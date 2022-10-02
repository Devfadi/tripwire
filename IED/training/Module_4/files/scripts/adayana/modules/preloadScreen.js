define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash');
    
    var preload = {
        el: null,
        initialize: function( selector, mediator ){
            this.el = $(selector);
            this.mediator = mediator;
            mediator.subscribe('trigger:preload:hide',   this.hide,               null, this );
            mediator.subscribe('trigger:preload:show',   this.show,               null, this );
            mediator.subscribe('trigger:preload:update', this.update,             null, this );
            mediator.subscribe('set:preload:message',    this.setMessage,         null, this );
            mediator.subscribe('set:preload:template',   this.setMessageTemplate, null, this );            
        },
        show: function(){
            this.el.show();
        },
        hide: function(){
            this.el.hide();
        },
        setMessage: function( str ){
            $('.preload-progress-text').html(str);
        },
        setMessageTemplate: function( template ){
            this.template = template;
        },
        update: function( num, total ) {
            var percent = Math.round( ( num / total ) * 100 );
            $('.preload-progress-bar').css('width', percent + "%");
            var source = this.template({
                percent: percent,
                num: num,
                total: total
            });
            $('.preload-progress-text').html(source);
        }
    };
    
    return preload;
});
