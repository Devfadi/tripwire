define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvObject = require('./advObject');
    
	require('adayana/aden/modules/objectFactory');
	
    var defaults = {};
    
    var AdvPopup = AdvObject.extend(
    /** @lends AdvPopup */        
    {    
        /**
         * Initializes a the Node
         * @class
         * @augments Class
         * @constructs
         */
        init: function( mediator, data, options ) {
            debug.info('creating an instance of AdvPopup');
            this._super(mediator,data,options);
            this.settings = $.extend(true,{},defaults,options);
            this.template = Templates.getTemplate(this.settings.source);
            this.mediator.publish('msg:object:init');
        },
        
        destroy: function() {
            this.mediator.publish('msg:object:destroy');
            // remove DOM Object if it exists
            if ( this.el ) {
                this.el.dialog('destroy');
                this.el.remove();
                delete this.el;
            }
            this._super();
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
            this.mediator.subscribe('msg:engine:pause',  this.onPause,  null, this);
            this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:update', this.onUpdate);
            this.mediator.remove('msg:engine:resize', this.onResize);
            this.mediator.remove('msg:engine:pause',  this.onPause);
            this.mediator.remove('msg:engine:resume', this.onResume);
        },

        /**
         * Updates Node
         */
        onUpdate : function() {
            if (this.isActive) {
                
            }
        },

        /**
         * Resizes stuff when display area size changes.
         */
        onResize : function() {
            if (this.isActive || this.isVisible) {
                // resize stuff
            }
        },

        /**
         * Pauses stuff
         */
        onPause : function() {
            if (this.isActive) {
                // pause stuff
            }
        },

        /**
         * Resumes stuff
         */
        onResume : function() {
            if (this.isActive) {
                // resume stuff
            }
        },
        
        /**
         * Reloads Object
         */
        reload : function() {},

        /**
         * Starts Object
         */
        start : function() {
            this._super();
            this.el = $(this.template(this.data));
            this.el.attr('id', this.id).appendTo(aden.el);
        },

        /**
         * Activate the object
         */
        activate : function() {
            this._super();
        },

        /**
         * Deactivate the object
         */
        deactivate : function() {
            this._super();
        },

        /**
         * Skips stuff
         */
        skip : function() {
            if (this.isActive) {
                
            }
        },

        /**
         * Positions node
         */
        position : function() {},

        /**
         * Show the visual items
         */
        show : function() {
            this._super();
        },

        /**
         * Hide the visual items
         */
        hide : function() {
            this._super();
        },
        
        close: function() {
            this.destroy();
        },
        
        triggerTimedAction : function() {},

        triggerEvent : function() {}
    });
    
    AdvPopup.prototype.type = 'popup';
    aden.factory.addType(AdvPopup);
    
    return AdvPopup;
    
});
