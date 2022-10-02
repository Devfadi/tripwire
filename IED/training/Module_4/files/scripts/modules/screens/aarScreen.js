define(function(require){
    var Screen = require('./screen'),
        mediator = require('adayana/modules/mediatorShim'),
        aden = require('adayana/aden/engine'),
        $ = require('jquery'),
        _ = require('lodash');
    
    var Pause = Screen.extend({
        init: function( id, template, data ){
            this._super(id, template, data);
            aden.plugin.mode.el.hide();
            this.el.find('.restart').click(function(){
                mediator.publish('trigger:fsm:gameView:event','restart');
            });
            this.el.find('.menu').click(function(){
                mediator.publish('trigger:fsm:gameView:event','menu');
            });
            
            $('#menu-bg .title').hide();
        },
        destroy: function(){
            this._super();
            $('#menu-bg .title').show();
        },
    });
    
    return Pause;
});
