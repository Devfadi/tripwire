/**
 * @file contains the definition for an Adventure Engine Popup Object.  
 * Displays inside of a jQuery UI Dialog widget, and can trigger an fsm 
 * event when closed.
 */
define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvObject = require('./advObject');
    
	require('adayana/aden/modules/objectFactory');
	
    /**
     * Default Settings 
     */
    var defaults = {
        "source"       : "",
        "modal"        : true,
        "onShow"       : "popup-show",
        "onHide"       : "popup-hide",
        "onStart"      : "popup-start",
        "onDestroy"    : "popup-destroy",
        "onActivate"   : "popup-activate",
        "onDeactivate" : "popup-deactivate"
    };
    
    var AdvPopup = AdvObject.extend({    
        
        /**
         * Initializes a Popup Adventure Node
         * @class
         * @augments Class
         * @constructs
         */
        init: function( mediator, data, options ) {
            debug.info('creating an instance of AdvPopup');
            this._super(mediator,data);
            this.settings = $.extend(true,{},defaults,options);
            this.template = Templates.getTemplate(this.settings.source);
            this.mediator.publish('msg:object:init');
        },
        
        /**
         * Destroys popup node
         */
        destroy: function() {
            if ( this.isDestroyed ) {return;}
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
            this.mediator.subscribe('msg:engine:resize', this.resize, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:resize', this.resize);
        },
        
        start: function(){
            //TODO preload necessary graphics for popup
            //TODO Add another button to generate a child node without setting this one to complete
            this._super();
            this.el = $(this.template(this.data));
            this.el.attr('id', this.id).appendTo(aden.el);
            var width = 3 * aden.el.width() / 4;
            var proxyFn = jQuery.proxy(this.close, this);
            this.el.dialog({
                closeOnEscape: false,
                title : this.data.title,
                width : width,
                modal : this.settings.modal,
                open  : function(event,ui) {
                    if ( $(this).height() > aden.height ) {
                        $(this).dialog( "option", "height", aden.height - 10 );
                    }
                    $(this).dialog("widget").position({
                        my: 'center',
                        at: 'center',
                        of: aden.el
                    });
                },
                buttons: {
                    "Close": function() {
                        $( this ).dialog( "close" );
                    }
                },
                close : proxyFn
            });
            this.resize();
        },
        
        /**
         * Re-center the popup when engine resizes
         */
        resize: function() {
            if( this.isActive ) {
                var width = 450; // (3/4) * aden.el.width();
                this.el.dialog('option','width',width);
                this.el.dialog("widget").position({
                    my: 'center',
                    at: 'center',
                    of: aden.el
                });
            }
        },
        
        close: function() {
            this.destroy();
        }
    });
    
    AdvPopup.prototype.type = 'popup';
    aden.factory.addType(AdvPopup);
    
    return AdvPopup;
    
});
