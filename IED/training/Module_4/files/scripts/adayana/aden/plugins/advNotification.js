define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        _S        = require('adayana/utilities/string'),
        AdvPlugin = require('./advPlugin');
    
    var defaults = {
        selector : '#notification',
        speed: 1000,
        duration: 15000,
        open: {
            left : '859px',
            top  : '20px'
        },
        closed: {
            left : '1030px',
            top  : '20px'
        }
        
    };

    var AdvNotification = AdvPlugin.extend(
    /** @lends AdvNotification.prototype */        
    {
        time : 0,
        timeString : "",
        timeoutId: null,
        isOpen: false,
        options: null,
          
        /**
         * @class
         * @augments AdvPlugin
         * @constructs
         */
        init: function( name, mediator, data ){
            this._super(name,mediator,data);
            this.el = $(data.selector);
            this.options = $.extend({}, defaults, data );
            
            // Close the notification when clicked
            this.el.click( $.proxy(function() {
                this.animateClosed();
            },this));
        },
        
        /**
         * Runs update on the plugin
         */
        update : function(){ 
            // update time
            var newTime = aden.clock.getTime();
            this.time = newTime;
            this.timeString = _S.getTimeString(aden.clock.date,true);
        },
        
        /**
         * Animate Notification to target area
         */ 
        animateOpen: function() {    
            if ( this.isOpen ) {
                this.el.css('left','1030px');
            }  
            window.clearTimeout( this.timeoutId );
            this.el.animate(
                this.options.open, 
                this.options.speed, 
                $.proxy(function() {
                    this.timeoutId = window.setTimeout($.proxy(function() { 
                        this.animateClosed(); 
                    },this), this.options.duration );
                },this)
            );
            this.isOpen = true;
        },
        
        /**
         * Animate Notification to closed state 
         */
        animateClosed: function() {
            this.el.animate(
                this.options.closed, 
                this.options.speed, 
                $.proxy(function() {
                    window.clearTimeout( this.timeoutId );
                    this.isOpen = false;
                },this)
            );
        },
        
        /**
         * Trigger a new notification 
         * @param {Object} text
         * @param {Object} status
         */
        notify : function( text, status ) {
            status = status || 'neutral';
            this.el
               .removeClass('positive negative neutral')
               .addClass( status )
               .html( text );
            this.animateOpen();
        }
    });
    
    return AdvNotification;
});
