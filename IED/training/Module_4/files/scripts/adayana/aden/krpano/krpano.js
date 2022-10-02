define(function( require ){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        MathUtil = require('adayana/utilities/math'),
        debug    = require('adayana/debug/debug'),
        aden     = require('adayana/aden/engine');
        
    var pano = aden.pano = aden.pano || {};
    
    var isFirstPano = true;
    var _delayedScripts = [];
    
    pano.krpano   = null;
    pano.camera   = require('./camera');
    pano.hotspots = require('./hotspots');
    pano.input    = require('./input');
    pano.player   = require('./player');
    pano.entities = require('./entities');
    
    pano.initialize = function( mediator ) {
        this.mediator = mediator;
        mediator.subscribe('msg:engine:init', this.onInit, null, this);
        mediator.subscribe('msg:engine:load', this.onLoad, null, this);
        mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
		mediator.subscribe('msg:engine:resize', this.onResize, null, this);
    };
    
    // -- EVENT HANDLERS --
    
    /**
     * Initializes the pano module after the Adventure Engine has initialized 
     * @param {Object} aden
     */
    pano.onInit = function( data ) {
        this.el = $('<div id="krpanoDIV" class="layer">');
        aden.el.append(this.el);
        
		this.spinner = $('<div id="spinner" style="display:none;"><div id="spinner-content"><p>Loading...</p><img src="files/assets/images/animated/waiting.gif" /></div></div>');
		aden.el.append(this.spinner);
		$("#spinner-content").position({
            "my": "center",
            "at": "center",
            "of": "#spinner"
        });
		
        this.hotspots.init( this );
        this.camera.init( this );
        this.player.init( this );
        this.input.init( this );
        this.entities.init( this, aden, data );
    };
    
	pano.onResize = function () {
		$("#spinner-content").position({
            "my": "center",
            "at": "center",
            "of": "#spinner"
        });
	};
	
    /**
     * Sets the scene data when the level has loaded 
     * @param {Object} levelData
     */
    pano.onLoad = function( levelData ) {
        if ( levelData.xmlPath ) {
            this.loadFn    = levelData.onPanoLoad; 
            this.areaData  = levelData.pano.areaData;
            this.sceneData = levelData.pano.scenes;
            this.sceneName = levelData.scene;
            this.entities.onLoad( levelData );
            this.loadPano( levelData.xmlPath );
        }
    };
    
    pano.onUpdate = function(){
        
    },
    
    /**
     * When krpano has started 
     */
    pano.onPanoStart = function() {
        debug.log('krpano event onStart');
        // grab the embeded object
        this.krpano = window.krpano = document.getElementById("krpanoSWFObject");
        // this.sceneName = this.krpano.call('get(scene[get(xml.scene)].title');
        this.load( this.sceneName );
        
        if ( this.loadFn && _.isFunction(this.loadFn) ) {
            _delayedScripts.push(this.loadFn);
        }
        
    };
    pano.onPanoXMLComplete = function(){
        debug.log('krpano event onxmlcomplete');
    };
    pano.onPanoRemove = function(){
        debug.log('krpano event onremovepano');
    };
    pano.onPanoPreviewComplete = function(){
        debug.log('krpano event onpreviewcomplete');
    };
    pano.onPanoLoadStart = function(){
        debug.log('krpano event onNewPano');
    };
    pano.onPanoLoadError = function(){
        debug.log('krpano event onloaderror');
    };
    pano.onPanoNewScene = function(){
        debug.log('krpano event onnewscene');
    };
    /**
     * When a pano has finished loading 
     */
    pano.onPanoLoadComplete = function(){
        debug.log('krpano event onLoadComplete');
        debug.log(this.krpano.get('xml.scene'));
        
        $('#spinner').hide();
        
        // find which pano scene loaded
        this.sceneName  = this.krpano.get('xml.scene').toLowerCase();
        this.sceneIndex = this.getSceneIndex( this.sceneName );
        this.scene      = this.sceneData[ this.sceneIndex ];
        
        // run through modules
        this.hotspots.onPanoLoad();
        this.camera.onPanoLoad();
        //this.entities.onPanoLoad(); // forceRedraw
        this.player.onPanoLoad();
                
        // determine return state
        var isReturning = this.scene.visited;
        this.scene.visited = true;
        
        // publish events
        this.mediator.publish('msg:pano:loaded');
        this.mediator.publish('trigger:engine:resume');
        this.isLoaded = true;
        
        // turn to target hotspot
        if ( this.target ) {
            this.camera.turnTo( this.target );
        }
        this.target = null;
        
        // run through actions
        processScriptQueue();
        
        if ( isReturning ) {
            if ( 'onReturn' in this.scene ) {
                this.scene.onReturn();
            }
        } else {
            if ( 'onInit' in this.scene ) {
                this.scene.onInit();
            }
        }
        if ( 'onVisit' in this.scene ) {
            this.scene.onVisit();
        }
    };
    
    pano.onSceneStart = function(){
        debug.log('krpano scene onstart');
    };
    
    function processScriptQueue(){
        var script;
        while( _delayedScripts.length > 0 ) {
            script = _delayedScripts.pop();
            if ( _.isFunction( script )) {
                script();
            }
        }
    }
    
    pano.addDelayedScript = function( script ) {
        _delayedScripts.push(script);
    },
    
    /**
     * load a new krpano xml file  
     * @param {Object} xmlPath
     */
    pano.loadPano = function( xmlPath ) {
        if ( this.krpano ) {
            this.krpano.call('loadpano(' + xmlPath + ')');
        } else {
            embedpano({
                swf    : "files/krpano/krpano.swf",
                html5  : "fallback",
                xml    : xmlPath,
                wmode  : "transparent",
                target : "krpanoDIV",
                height : "100%",
                width  : "100%"
            });
        }
    };
    
	function krpanoReady() {
		alert('ready');
	}
	
	function krpanoError() {
		alert('error');
	}
    /**
     * Reload the current scene 
     */
    pano.reload = function(){
        this.load( this.sceneName, false, null);
    };
    
    /**
     * Load a pano scene 
     * @param {Object} sceneName
     * @param {Object} shouldTurn
     * @param {Object} target
     */
    pano.load = function( sceneName, shouldTurn, target ){
        var h,v;
        shouldTurn = !!shouldTurn;
        sceneName = sceneName.toLowerCase();
        
        // execute the onExit action if it exists
        if ( this.scene && 'onExit' in this.scene ) {
            this.scene.onExit();
        }
        // when turning to face new scene, calculate angles
        if ( shouldTurn ) {
            var newScene = this.getSceneData( sceneName );
            h = MathUtil.angle( this.scene.position.z, this.scene.position.y, newScene.position.z, newScene.position.y );
            v = 0;
        }
        // pause the engine
        //this.mediator.publish('trigger:engine:pause');
        $('#spinner').show();
        
        // set parameters
        this.isLoaded   = false;
        this.target     = target;
        // this.sceneName  = sceneName;
        
        // initiate the load
        if ( shouldTurn ) {
            this.krpano.call("lookto(" + h + "," + v + ",55,smooth(720,-720,720),true,true,js(aden.pano.load(" + name + ")));");
        } else {
            this.krpano.call("loadscene('" + sceneName  + "',null,MERGE,BLEND(.5));");
        }
    };
    
    /**
     * Grab the data for a scene 
     * @param {Object} name
     */
    pano.getSceneData = function( name ) {
        name = name.toLowerCase();
        _.forEach( this.sceneData, function( location ) {
            if ( location.name.toLowerCase() === name ) {
                return location;
            }
        },this);
        return null;
    };
    
    /**
     * Find the index for the given scene name 
     * @param {Object} name
     */
    pano.getSceneIndex = function( name ) {
        name = name.toLowerCase();
        var index = 0;
        _.forEach( this.sceneData, function( location, i ) {
            if ( location.name.toLowerCase() === name ) {
                index = i;
                return false;
            }
        },this);
        return index;
    };
});
