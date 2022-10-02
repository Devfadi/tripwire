define(function(require){
    // dependencies:
    var $               = require('jquery'),
        _               = require('lodash'),
        aden            = require('adayana/aden/engine'),
        EventDispatcher = require('adayana/basic/eventDispatcher');
        
    var AdvPlugin = EventDispatcher.extend(
    /** @lends AdvPlugin.prototype */        
    {
        /**
         * The name given to this instance of the plugin 
         */
        name: '',
        
        /**
         * Data object for this plugin
         */
        data: null,
        
        /**
         * Indicates if the plugin is ready
         */
        isReady: false,
        
        /**
         * Plugin id
         */
        id: 'undefined',
        
        /**
         * Indicates if plugin is active
         */
        isActive: true,
        
        /**
         * Adventure Engine Plugin Template
         * @constructs
         * @augments EventDispatcher
         */
        init: function( name, mediator, data ) {
            if ( name in aden.plugin ) {
                throw "ERROR! Another plugin instance has already taken the name '" + name + ".'";
            }
            aden.plugin[name] = this;
            this._super();
            this.name     = name;
            this.self     = this;
            this.isReady  = true;
            this.mediator = mediator;
            this.data     = data;
            this.subscribe();
        },
        
        /**
         * Destroys the plugin instance 
         */
        destroy: function() {
            this.unsubscribe();
            delete this.self;
            this.data = null;        
            this._super();
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            this.mediator.subscribe('msg:engine:init',   this.onInit,   null, this);
            this.mediator.subscribe('msg:engine:load',   this.onLoad,   null, this);
            this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
            this.mediator.subscribe('msg:engine:draw',   this.onDraw,   null, this);
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
            this.mediator.subscribe('msg:engine:pause',  this.onPause,  null, this);
            this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
            this.mediator.subscribe('msg:state:save',    this.onSaveData, null, this);
            this.mediator.subscribe('msg:state:load',    this.onLoadData, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:init',   this.onInit);
            this.mediator.remove('msg:engine:load',   this.onLoad);
            this.mediator.remove('msg:engine:update', this.onUpdate);
            this.mediator.remove('msg:engine:draw',   this.onDraw);
            this.mediator.remove('msg:engine:resize', this.onResize);
            this.mediator.remove('msg:engine:pause',  this.onPause);
            this.mediator.remove('msg:engine:resume', this.onResume);
            this.mediator.remove('msg:state:save',    this.onSaveData);
            this.mediator.remove('msg:state:load',    this.onLoadData);
        },
        
        /**
         * Runs when engine is creating a save state 
         */
        onSaveData: function( saveData ){},
        
        /**
         * Runs when engine is laoding a save state 
         */
        onLoadData: function( saveData ){},
        
        /**
         * Runs when engine initializes 
         */
        onInit: function(){},
        
        /**
         * Runs when level is loaded 
         */
        onLoad: function(){},
        
        /**
         * Runs update on the plugin
         */
        onUpdate: function() {},
        
        /**
         * Draws plugin
         */
        onDraw: function() {},
        
        /**
         * Resize plugin when display space changes
         */
        onResize: function() {},
        
        /**
         * Pauses the plugin 
         */
        onPause: function() {},
        
        /**
         * Resumes the plugin 
         */
        onResume: function() {},
        
        /**
         * Handles data passed in from adventure objects 
         */
        onObjectStart: function( id, data ) {},
        
        /**
         * Resets the Plugin
         */
        reset: function() {},
        
        /**
         * Activates the Plugin
         */
        activate: function() {
            this.isActive = true;
        },
        
        /**
         * Deactivates the Plugin
         */
        deactivate: function() {
            this.isActive = false;
        }
    });
    
    return AdvPlugin;
});
