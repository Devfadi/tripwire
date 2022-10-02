define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        debug = require('adayana/debug/debug'),
        detect = require('adayana/utilities/detect');
           
    //TODO - re-implement save states
    //TODO - fix nodes to allow for creating a save state at any point in the game.
    //TODO - Add rotate event detection for mobile device    
    //TODO - Perhaps more of the engine could become event driven rather than driven by the update cycle.
    //TODO - implement a system that would allow additional JSON files to be loaded
    
    var AdvEngine = {
        /**
         * jQuery Object containing the AdvEngine Container DOM Element
         */
        el : null,
        /**
         * The engine data object
         */
        data: null,
        /**
         * Boolean indicating if debug output should be generated.
         */
        debug: true,
        /**
         * Time elapsed while the engine is in a running state. 
         */
        elapsedTime: 0,
        /**
         * Time elapsed since the engine first started. 
         */
        runTime: 0,
        /**
         * reference to the mediator instance 
         */
        mediator: null,
        /**
         * collection of engine plugins 
         */
        plugin: {},
        /**
         * collection of finite state machines 
         */
        fsm: {}
    };
    
    // --- Private Variables -----------------------------------------------------------------------
    
    /**
     * id of the requested animation frame or timer interval
     */
    var _requestId = null;
    
    /**
     * Boolean indicating if the game is running. When false, the game will stop on the next update cycle
     */
    var _isRunning = false;
    
    /**
     * Indicates if AdvEngine is ready
     * @type Booean
     */
    var _isReady = false;
    
    /**
     * Indicates whether the engine is paused 
     */
    var _isPaused = false;
    
    /**
     * Time at initialization 
     */
    var initTimeFrame;
    
    /**
     * Time when the current frame started 
     */
    var currTimeFrame;
    
    /**
     * Time when the previous frame started 
     */
    var prevTimeFrame;
    
    /**
     * Executes the engine reload sequence 
     */
    function reload(){
        alert('engine reload not implemented');
        AdvEngine.mediator.publish('msg:engine:reload');
    }
    
    /**
     * Starts the Adventure Engine by initializing the initial state of the engine and all 
     * components. Following this, the game engine cycle/loop is triggered. Finally, the method 
     * communicates to other components that the engine has started.
     */
    AdvEngine.start = function( mediator, data, saveName ) {
        debug.info('engine starting');
        
        this.data = data;
        
        // configure channels
        this.mediator = mediator;
        this.mediator.subscribe('trigger:engine:pause',  this.pause,     null, this );
        this.mediator.subscribe('trigger:engine:resume', this.resume,    null, this );
        this.mediator.subscribe('trigger:engine:stop',   this.stop,      null, this );
        this.mediator.subscribe('trigger:engine:level',  this.loadLevel, null, this );
        
        // setup
        this.version = data.version;
        this.levelData = data.levels;
        this.setupViewport();
        
        // run engine initialization
        initialize(mediator,data);
        
        // attempt to load saved state
        // FUTURE - m-learning suspend data is asynchronous. would have to change this.
        if ( this.save && data.settings.engine.loadSaveOnStart ) {
            this.save.getState(saveName);
        }
        
        // always load the first level, this is the "level loader"
        this.loadLevel(data.settings.engine.firstLevel);
        
        // start engine cycle
        _isRunning = true;
        _requestId = window.requestAnimationFrame( step );
        this.mediator.publish('msg:engine:start');
        _isReady = true;
        
        debug.info('engine started');
    };
    
	var firstSetup = true;
    AdvEngine.setupViewport = function() {
        this.el = $( this.data.settings.engine.el );
        this.height = this.el.height();
        this.width  = this.el.width();
		
		$('.aden-viewport').html(this.width + "px by " + this.height + "px");
		$('.aden-document').html(window.innerWidth + "px by " + window.innerHeight + "px");
		$('.aden-window').html(document.documentElement.clientWidth + "px by " + document.documentElement.clientHeight + "px");
		
		
//		$("body").css({
//			"width": Math.round(document.documentElement.clientWidth),
//			"height": Math.round(document.documentElement.clientHeight)
//		});
			
		// Locks dimensions to initial size
//		if(firstSetup){
//			$("body").css({
//				"max-width": this.width,
//				"min-width": this.width,
//				"max-height": this.height,
//				"min-height": this.height
//			});
//			firstSetup=false;
//		}
        
		this._resizeViewport();
    };
    
    AdvEngine._resizeViewport = function() {
        if ( this.data.settings.engine.constrainDimensions ) {
            //TODO - constrain dimensions of viewport
        }
        if ( this.data.settings.engine.constrainToRatio ) {
            var ratio = this.width / this.height;
            var targetRatio = this.data.settings.engine.ratio;
            var h, w, t, l;
            if ( ratio > targetRatio ) {
                w = (targetRatio * this.height);
                h = winHeight;
            } else {
                w = this.width;
                h = ( this.width / targetRatio );
            }
            l = (this.width - w ) / 2;
            t = (this.height - h ) / 2;
            this.el.css({
                'width'    : w,
                'height'   : h,
                'top'      : t,
                'left'     : l,
                'position' : 'absolute'
            });
        }
    };
    
    /**
     * Stops the engine cycle/loop
     */
    AdvEngine.stop = function() {
        _isRunning = false;
        // cancel animation frame
        window.cancelAnimationFrame(requestId);
        this.mediator.publish('msg:engine:stop');
    };
    
    /**
     * Handles the resizing of the engine and all components.
     */
    AdvEngine.onResize = function() {
        // update dimensions
        AdvEngine.setupViewport();
        // call resize methods
        this.mediator.publish('msg:engine:resize');
    };
    
    /**
     * Pauses the engine by canceling the animation frame and notifies all components
     */
    //FIXME - after unpausing engine, engine clock jumps ahead the amount of time paused.
    AdvEngine.pause = function() {
        //TODO - don't actually stop the entire update cycle. just put the engine into idle. Modules and Plugins will need to detect the mode
        if ( _isReady && !_isPaused ) {
            window.cancelAnimationFrame(_requestId);
            this.mediator.publish('msg:engine:pause');
            _isPaused = true;
        }
    };
    
    /**
     * Resumes engine cycle after a pause has been executed. The animation frame cycle is 
     * resumed and all components are notified.
     */
    AdvEngine.resume = function() {        
        if ( _isReady && _isPaused ) {
            _requestId = window.requestAnimationFrame(step);            
            this.mediator.publish('msg:engine:resume');
            _isPaused = false;
        }
    };
    
    /**
     * Resets the engine back to its initial state 
     */
    AdvEngine.reset = function() {
        window.cancelAnimationFrame(_requestId);
        
        this.mediator.publish('msg:engine:reset');
        
        _.forEach( aden.fsm, function( fsm ) {
            fsm.reset();
        });
        
        //TODO - need to implement a onReset event for most modules/plugins
        // engine is running
        // _isRunning = true;
        // initialize(mediator,this.data);
        // this.loadLevel(this.data.settings.engine.firstLevel);
        // _requestId = window.requestAnimationFrame( step );
        // this.mediator.publish('msg:engine:start');
        // _isReady = true;
        // debug.info('engine started');
    };
    
    /**
     * Load a level 
     */
    AdvEngine.loadLevel = function( index ) {
        if ( index > -1 && index < this.levelData.length ) {
            this.level = this.levelData[index];
            this.mediator.publish('msg:engine:load', this.level );
            if ( 'onLoad' in this.level ) {
                this.level.onLoad();
            }
        }
    };
    
    //TODO - implement a resumeLevel method
    
    /**
     * Executes the engine initialization sequence 
     */
    function initialize( mediator, data ){
        var subId,
            priority = 0;
        
        // initialize frame time parameters
        currFrameTime = new Date().getTime();
        prevFrameTime = currFrameTime;
        initFrameTime = currFrameTime;
        
        // set initial values
        AdvEngine.elapsedTime = 0; // reset total time to zero
        
        // Prioritize the initialization of certain modules/plugins:
        
        // When the Clock Module is loaded, ensure it has first priority on engine msg channels
        if ( 'clock' in AdvEngine ) {    
            AdvEngine.clock._subUpdate.channel.setPriority( AdvEngine.clock._subUpdate.id, priority );
            AdvEngine.clock._subReset.channel.setPriority( AdvEngine.clock._subReset.id, priority );
            AdvEngine.clock._subPause.channel.setPriority( AdvEngine.clock._subPause.id, priority );
            AdvEngine.clock._subResume.channel.setPriority( AdvEngine.clock._subResume.id, priority );
            priority++;
        }
        
        // When variables module is loaded, ensure it is updated last
        if ( 'variables' in AdvEngine ) {
            var module = AdvEngine.variables;
            module._subInit.channel.setPriority( module._subInit.id, module._subInit.channel._subscribers.length-1 );
            module._subLoad.channel.setPriority( module._subLoad.id, module._subLoad.channel._subscribers.length-1 );
            module._subReset.channel.setPriority( module._subReset.id, module._subReset.channel._subscribers.length-1 );
            module._subUpdate.channel.setPriority( module._subUpdate.id, module._subUpdate.channel._subscribers.length-1 );
        }
        
        // initialize any add-ons           
        AdvEngine.mediator.publish('msg:engine:init', data );
    }
    
    /**
     * Executes the next step or iteration of the game
     * @private 
     */
    function step() {
        currFrameTime = new Date().getTime();
        var deltaTime = currFrameTime - prevFrameTime;
        AdvEngine.runTime = currFrameTime - initFrameTime;
        AdvEngine.elapsedTime += deltaTime;
        prevFrameTime = currFrameTime;
        
        //this.nextEventTime = AdvEngine.timedEvents.getNextEventTime();
        AdvEngine.mediator.publish('msg:engine:update', AdvEngine );
        AdvEngine.mediator.publish('msg:engine:lateUpdate', AdvEngine );
        AdvEngine.mediator.publish('msg:engine:draw', AdvEngine );
        
        if ( _isRunning ) {
            _requestId = window.requestAnimationFrame( step );            
        }
    }
    
    // for debugging purposes...
    window.aden = AdvEngine;
    
    return AdvEngine;
});
