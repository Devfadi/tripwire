define(function(require){
    var Screen = require('./screen'),
        mediator = require('adayana/modules/mediatorShim'),
        $ = require('jquery'),
        _ = require('lodash');
    
    var Splash = Screen.extend({
        init: function( id, template, data ){
            this._super(id, template, data);
            this.el.find('.next').click(function(){
                mediator.publish('trigger:fsm:gameView:event','next');
            });
            this.el.find('.back').click(function(){
                mediator.publish('trigger:fsm:gameView:event','back');
            });
        }        
    });
    
    return Splash;
});
