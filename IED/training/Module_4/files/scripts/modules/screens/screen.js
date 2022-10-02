define(function(require){
    
    var Class = require('adayana/basic/class'),
        Templates = require('adayana/modules/templates'),
        mediator = require('adayana/modules/mediatorShim'),
        aden = require('adayana/aden/engine'),
        $ = require('jquery'),
        _ = require('lodash');
    
    var Screen = Class.extend({
        init: function( id, template, data ){
            this.mediator = mediator;
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
            this.id = id;
            this.el = $(Templates.getTemplate(template)(data));
            this.el.attr("id",id);
            this.el.appendTo('#viewport');
            this.data = data;
            this.isDestroyed = false;
            aden.layers.add(this.id);
            aden.layers.sendBelow(this.id,'god-view');
            this.onResize();
        },
        destroy: function(){
            this.mediator.remove('msg:engine:resize', this.onResize, null, this);
            aden.layers.remove(this.id);
            this.el.remove();
            this.isDestroyed = true;
        },
        onResize: function(){
            var self = this;
            this.el.find('.square-fit-height').each(function(index, el){
                el = $(el);
                var height = el.parent().height();
                var width = el.parent().width();
                el.width(height);
                el.height(height);
                self.el.find('.fit-text').css({
                    right: height + 20
                });
            });
        } 
    });
    
    return Screen;
});
