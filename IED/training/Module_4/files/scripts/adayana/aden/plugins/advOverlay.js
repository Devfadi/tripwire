define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        AdvPlugin = require('./advPlugin');
        
    var AdvOverlay = AdvPlugin.extend(
    /** @lends AdvOverlay.prototype */        
    {
        // Plugin Parameters
        el : null,
        speed : 0,
        shouldDraw : false,
        isFadeIn   : false,
        isFadeOut  : false,
        
        /**
         * Adventure Engine Plugin Template
         * @constructs
         * @augments EventDispatcher
         */
        init: function( name, mediator, data ) {
            this._super( name, mediator, data );
            this.step = 0;
            this.el = $("<div class='overlay'></div>").attr('id', this.id).appendTo(aden.el);
            this.el.hide();
            this.time = 0;
            this.callback = null;
        },
        
        /**
         * Destroys the plugin instance 
         */
        destroy: function() {
            this.unsubscribe();
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
            this.mediator.subscribe('msg:engine:draw',   this.onDraw,   null, this);
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
            this.mediator.subscribe('msg:engine:pause',  this.onPause,  null, this);
            this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:update', this.onUpdate);
            this.mediator.remove('msg:engine:draw',   this.onDraw);
            this.mediator.remove('msg:engine:resize', this.onResize);
            this.mediator.remove('msg:engine:pause',  this.onPause);
            this.mediator.remove('msg:engine:resume', this.onResume);
        },
        
        /**
         * Runs update on the plugin
         */
        onUpdate: function() {
            var time = aden.elapsedTime; 
            this.step = time - this.time;
            this.time = time;
            
            // When tweening
            if ( this.isTweening ) {
                this.shouldDraw = true;
                
                // fade in has reached end point
                if ( this.data.alpha === 1 && this.speed > 0 ) {
                    this.speed = 0;
                    this.isTweening = false;
                    this.shouldDraw = false;
                    if ( this.callback ) {
                        this.callback();
                    }
                    this.callback = null;
                }
                // fade out has reached end point
                else if (  this.data.alpha === 0 && this.speed < 0 ) {
                    this.speed = 0;
                    this.el.hide();
                    this.isTweening = false;
                    this.shouldDraw = false;
                    if ( this.callback ) {
                        this.callback();
                    }
                    this.callback = null;
                }
                // tween
                else {
                    this.data.alpha += ( this.speed * this.step );
                    if ( this.data.alpha > 1 ) {
                        this.data.alpha = 1;
                    }
                    else if ( this.data.alpha < 0 ){
                        this.data.alpha = 0;
                    }
                }    
            } 
            else {
                this.shouldDraw = false;
            }
        },
        
        /**
         * Draws plugin
         */
        onDraw: function() {
            if ( this.shouldDraw ) {
                this.el.css({
                    "background-color" : this.data.color,
                    "opacity"          : this.data.alpha
                });
                if ( this.data.visible ) {
                    this.el.show();
                } else {
                    this.el.hide();
                }
            }
        },
        
        /**
         * Resize plugin when display space changes
         */
        onResize: function() {},
        
        /**
         * Pauses the plugin 
         */
        onPause: function() {},
        
        /**
         * Resumes the plugin 
         */
        onResume: function() {},
        
        fadeOut: function( time, callback ) {
            if ( _.isString(time) ) {
                time = parseInt(time,10);            
            }
            if ( callback ) {
                this.callback = callback;
            }
            this.data.visible = true;
            this.data.alpha   = 1;
            this.isTweening   = true;
            this.speed        = - 1/time;
        },
        
        fadeIn: function( time, callback ) {
            if ( _.isString(time) ) {
                time = parseInt(time,10);            
            }
            if ( callback ) {
                this.callback = callback;
            }
            this.el.css({
                "z-index"          : 45
            });
            this.data.visible = true;
            this.data.alpha   = 0;
            this.isTweening   = true;
            this.speed        = 1/time;
        },
        
        show: function( opacity ) {
            this.el.css({
                "background-color" : this.data.color,
                "background-image" : "url(\"files/assets/images/fills/blank.gif\")",
                "opacity"          : opacity,
                "z-index"          : 2
            });
            this.el.show();
            this.data.visible = true;
            this.data.alpha   = opacity;
            this.isTweening   = false;
            this.speed        = 0;
        },
        
        hide: function() {
            this.el.hide();
            this.el.css({
                "opacity" : 0
            });
            this.data.visible = false;
            this.data.alpha   = 0;
            this.isTweening   = false;
            this.speed        = 0;
        }
    });
    
    return AdvOverlay;
});
