define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvObject = require('./advObject');
    
	require('adayana/aden/modules/objectFactory');
	
    require('elevateZoom');
    
    var defaults = {
        "source"       : "",
        "modal"        : true,
        "onShow"       : "image-show",
        "onHide"       : "image-hide",
        "onStart"      : "image-start",
        "onDestroy"    : "image-destroy",
        "onActivate"   : "image-activate",
        "onDeactivate" : "image-deactivate"
    };
    
    var AdvImage = AdvObject.extend(
    /** @lends AdvImage */        
    {    
        /**
         * Initializes a the Node
         * @class
         * @augments Class
         * @constructs
         */
        init: function( mediator, data, options ) {
            debug.info('creating an instance of AdvImage');
            this._super(mediator,data,options);
            this.settings = $.extend(true,{},defaults,options);
            this.template = Templates.getTemplate(this.settings.source);
            this.mediator.publish('msg:object:init');
        },
        
        /**
         * Destroys the object 
         */
        destroy: function() {
            if ( this.isDestroyed ) {return;}
            aden.layers.remove(this.id);
            this.mediator.publish('msg:object:destroy');
            // remove DOM Object if it exists
            if ( this.el ) {
                this.el.remove();
                delete this.el;
            }
            this._super();
            this.image = null;
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
            this.mediator.subscribe('msg:engine:pause',  this.onPause,  null, this);
            this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:update', this.onUpdate);
            this.mediator.remove('msg:engine:resize', this.onResize);
            this.mediator.remove('msg:engine:pause',  this.onPause);
            this.mediator.remove('msg:engine:resume', this.onResume);
        },

        /**
         * Updates Node
         */
        onUpdate : function() {
            if (this.isActive) {
                
            }
        },

        /**
         * Resizes stuff when display area size changes.
         */
        onResize : function() {
            if (this.isActive || this.isVisible) {
                this.resize();
            }
        },

        /**
         * Pauses stuff
         */
        onPause : function() {
            if (this.isActive) {
                // pause stuff
            }
        },

        /**
         * Resumes stuff
         */
        onResume : function() {
            if (this.isActive) {
                // resume stuff
            }
        },
        
        /**
         * Reloads Object
         */
        reload : function() {},

        /**
         * Starts Object
         */
        start : function() {
            this._super();
            this.el = $(this.template(this.data));
            this.el.attr('id', this.id).appendTo(aden.el);
            this.image = this.el.find('img');
            this.image.attr('id','image-' + this.data.id);
            
            //if ( 'css' in this.data ) {
            //    this.el.css(this.data.css);
            //} else {
                
                /*this.image.css({
                    position: 'absolute',
                    left: '50%',
                    top: '50%',
                    marginLeft: '-50%',
                    marginTop: '-50%'
                });*/
            //}
            aden.layers.add(this.id);
            aden.layers.sendBelow(this.id,'clock-view');
            this.resize();
        },
        
        zoom: function(){
            this.image.elevateZoom({
                zoomType: "lens",
                lensShape: "round",
                lensSize: "250",
                scrollZoom: true,
                zoomWindowFadeIn: 500,
                zoomWindowFadeOut: 750,
                containLensZoom: true,
                parent: this.el
            });
        },
        
        resize: function() {
            var ratio1 = 1024 / 768;
            var ratio2 = aden.width / aden.height;
            
            // when image aspect ratio is wider 
            if ( ratio1 > ratio2 ) {
                this.image.height( aden.width / ratio1 );
                this.image.width( aden.width );
            } else {
                this.image.height( aden.height );
                this.image.width( aden.height * ratio1 );
            }
            
            this.el.addClass('screen').css({
                background: "#000000",
                height: aden.height + 'px',
                width: aden.width + 'px'
            });
            
            this.position();
        },
        
        position: function(){
            //if ( this.data.shouldScale ) {
                this.image.position({
                    "my" : "center",
                    "at" : "center",
                    "of" : this.el
                });
            //}
        },
        
        /**
         * Show the visual items
         */
        show : function() {
            this._super();
        },

        /**
         * Hide the visual items
         */
        hide : function() {
            this._super();
        },
        
        close: function() {
            this.destroy();
        },
        
        triggerTimedAction : function() {},

        triggerEvent : function() {}
    });
    
    AdvImage.prototype.type = 'image';
    aden.factory.addType(AdvImage);
    return AdvImage;
});
