define(function(require){
    var Screen = require('./screen'),
        mediator = require('adayana/modules/mediatorShim'),
        $ = require('jquery'),
        _ = require('lodash');
    
    var ScenarioScreen = Screen.extend({
        init: function( id, template, data ){
            this._super(id, template, data);
            this.el.find('.start').click(function(){
                mediator.publish('trigger:fsm:gameView:event','start');
            });
            this.el.find('.back').click(function(){
                mediator.publish('trigger:fsm:gameView:event','back');
            });
        }        
    });
    
    return ScenarioScreen;
});
