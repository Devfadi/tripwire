define(function(require){
    var Screen = require('./screen'),
        mediator = require('adayana/modules/mediatorShim'),
        $ = require('jquery'),
        _ = require('lodash'),
        SimpleWindow = require('adayana/utilities/simpleWindow');
    
    var NavScreen = Screen.extend({
        init: function( id, template, data ){
            this._super(id, template, data);
            
            var children = this.el.find('.menu-selections').children();
            _.forEach( data.selections, function(selection,index){
                var child = children.eq(index);
                child.on('click',function(){
                    mediator.publish('trigger:fsm:gameView:event',selection.event);
                });
            });
            
            this.el.find('.help').click(function(){
                mediator.publish('trigger:fsm:gameView:event','help');
            });
            
            this.el.find('.clear').click(function(){
                $.jStorage.flush();
                window.location.reload();
            });
			
			this.el.find('.back').click(function(){
				mediator.publish('trigger:fsm:gameView:event','back');
			});
            
            this.el.find('#certificate').click(function(){
                var popup = new SimpleWindow('files/certificate/certificate.html', 'Certificate', {
					width        : 400,
					height       : 150,
					chrome       : "yes",
					centerscreen : true,
					scrollbars   : 'no'
				});
            });
        }        
    });
    
    return NavScreen;
});
