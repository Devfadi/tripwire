define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvPlugin = require('adayana/aden/plugins/advPlugin');
    
    var events = [];
    
    var AdvPlaylist = AdvPlugin.extend(
    {   
        fsm: null,
        isOpen: false,
        
        init: function( name, mediator, data ) {
            this._super(name,mediator,data);
            this.template = Templates.getTemplate(data.source);
        },
        
        onInit: function( instance ){            
            this.el = $('<div id="playlist"></div>'); 
            this.el.appendTo( aden.el );
            this.setTriggers(null);
            this.el.click($.proxy(function(){
                var height = this.el.height();
                if ( this.isOpen ) {
                    this.el.animate({
                        top: -(height-36)
                    }, 1000);
                    this.isOpen = false;
                } else {
                    this.el.animate({
                        top: 0
                    }, 1000);
                    this.isOpen = true;
                }
            },this));
        },
        
        onLoad: function() {
            
        },
        
        onUpdate: function(){
            
        },
        
        setFSM: function( fsm ) {
            this.fsm = fsm;
        },
        
        setTriggers: function( data ) {
            this.el.html(this.template(data));
            this.el.find('.playlist-trigger').click($.proxy(function(event){
                // alert( $(event.currentTarget).attr('data-trigger-event'));
                this.fsm.trigger($(event.currentTarget).attr('data-trigger-event'));
                event.stopPropagation();
                return false;
            },this));
            var list = this.el.find('.trigger-list');
            // reset height of container
            this.el.height( list.height() + 36 + 8 );
            // set position
            if ( this.isOpen ) {
                this.el.css({ top: 0 });
            } else {
                this.el.css({ top: -(this.el.height() - 36) });                
            }
        }
    });
    
    return AdvPlaylist;
});