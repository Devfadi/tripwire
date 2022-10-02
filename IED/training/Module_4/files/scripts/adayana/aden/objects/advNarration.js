
/**
 * @file Contains the definition of a basic Adventure Engine Decision Point Object.
 */
define(function(require){
    
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvObject = require('./advObject');
    
	require('adayana/aden/modules/objectFactory');
	
    var defaults = {
        "prefix" : "branch",
        "modal"  : true,
        "styles" : {
            "option"    : "adv-dp-option",
            "disabled"  : "option-disabled"
        },
        "onShow"       : "narration-show",
        "onHide"       : "narration-hide",
        "onStart"      : "narration-start",
        "onDestroy"    : "narration-destroy",
        "onActivate"   : "narration-activate",
        "onDeactivate" : "narration-deactivate"
    };
    
    var AdvNarration = AdvObject.extend(
    /** @lends AdvNarration */        
    {            
        /**
         * Initializes a the Node
         * @class
         * @augments Class
         * @constructs
         */
        init: function( mediator, data, options ) {
            debug.info('creating an instance of AdvNarration');
            this._super(mediator,data,options);
            this.settings = $.extend(true,{},defaults,options);
            this.template = Templates.getTemplate(this.settings.source);
            this.mediator.publish('msg:object:init');
        },
        
        /**
         * Destroys the Adventure Object 
         */
        destroy: function() {
            if ( this.isDestroyed ) {return;}
			aden.layers.remove(this.id);
            this.mediator.publish('msg:object:destroy');
            // remove DOM Object if it exists
            if ( this.el ) {
                this.el.remove();
                delete this.el;
            }
            this._super();
            this.settings = null;
            this.template = null;
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:resize', this.onResize);
        },
        
        /**
         * Resizes stuff when display area size changes.
         */
        onResize : function() {
            if (this.isActive || this.isVisible) {
                this.resize();
            }
        },
        
        /**
         * Reloads Object
         */
        reload : function() {
            
        },

        /**
         * Starts Object
         */
        start : function() {
            this._super();
            this.el = $(this.template(this.data));
            this.el.attr('id', this.id).appendTo(aden.el);
			aden.layers.add(this.id);
			aden.layers.sendBelow(this.id, 'menu-bg');
            this.resize();
        },
        
        /**
         * Resizes the Decision Point 
         */
        resize: function(){
            var viewHeight = aden.height;
            this.el.find('.adv-dp-content').css({ 'max-height': (viewHeight - 20) + "px" });
            this.position();
        },

        /**
         * Positions node
         */
        position : function() {
            // re-center DP on bottom of screen;
            this.el.position({
                my: 'center bottom',
                at: 'center bottom',
                of: '#' + aden.el.attr('id')
            });
        },
        
        close: function() {
            this.destroy();
        }
    });
    
    AdvNarration.prototype.type = 'narration';
    aden.factory.addType(AdvNarration);
    
    return AdvNarration;
    
});
