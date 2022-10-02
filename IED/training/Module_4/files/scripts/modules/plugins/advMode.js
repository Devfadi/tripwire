define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvPlugin = require('adayana/aden/plugins/advPlugin');
    
    
    var AdvMode = AdvPlugin.extend(
    /** @lends AdvMode.prototype */        
    {
        mode: '',
        
        init: function( name, mediator, data ) {
            this._super(name,mediator,data);
            this.fsm = null;
            this.eventName = null;
            this.onRadioClick = $.proxy(this.onRadioClick, this);
        },
        
        onInit: function( instance ){            
            this.el = $('<div id="mode-view" class="mode-view layer"></div>');
            this.el.appendTo( aden.el );
            this.el.html('loading');
            debug.info('Radio module is ready');
        },
        
        setMode: function( mode ){
            this.el.show();
            this.el.removeClass(this.mode);
            this.el.addClass(mode);
            this.mode = mode;
            
            switch( mode ) {
                case 'static':
                    this.el.html('Static View');
                    break;
                case 'pano':
                    this.el.html('You can look around.');
                    break;
                case 'vid':
                    this.el.html('Cinematic');
            }
        }
    });
    
    return AdvMode;
});