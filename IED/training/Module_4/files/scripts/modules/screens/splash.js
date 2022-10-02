define(function(require){
    var Screen = require('./screen'),
        mediator = require('adayana/modules/mediatorShim'),
        $ = require('jquery'),
        _ = require('lodash');
    
    var Splash = Screen.extend({
        init: function( id, template, data ){
            this._super(id, template, data);
            $('#start-game').click(function(){
                mediator.publish('trigger:fsm:gameView:event','start');
            });
            $('#skip-intro').click(function(){
                mediator.publish('trigger:fsm:gameView:event','skip');
            });
        }        
    });
    
    return Splash;
});
