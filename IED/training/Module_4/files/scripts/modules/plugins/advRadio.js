define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvPlugin = require('adayana/aden/plugins/advPlugin');
    
    var events = [];
    
    var AdvRadio = AdvPlugin.extend(
    /** @lends AdvRadio.prototype */        
    {
        currTime: 0,
        
        init: function( name, mediator, data ) {
            this._super(name,mediator,data);
            this.template = Templates.getTemplate(data.source);
            this.fsm = null;
            this.eventName = null;
            this.onRadioClick = $.proxy(this.onRadioClick, this);
        },
        
        onInit: function( instance ){            
            this.el = $('<div id="radio-view" class="radio-view layer"></div>');
            this.el.appendTo( aden.el );
            this.el.html(this.template(null));
            this.el.on('click',this.onRadioClick);
            debug.info('Radio module is ready');
        },
        
        setFSM: function( fsm ) {
            this.fsm = fsm;
        },
        
        setEventName: function( eventName ) {
            this.eventName = eventName;
        },
        
        onRadioClick: function(){
            if ( this.isActive ){
                if ( this.fsm && this.eventName ) {
                    this.fsm.trigger(this.eventName);
                } else {
                    debug.warn('radio is not configured to fire an fsm event');
                }
            } else {
                debug.log('radio inactive');
            }
        },
        
        addGlow: function(){
            this.el.addClass('glow');
        },
        
        removeGlow: function(){
            this.el.removeClass('glow');
        }
    });
    
    return AdvRadio;
});