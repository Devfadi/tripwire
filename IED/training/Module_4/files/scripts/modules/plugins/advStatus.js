define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvPlugin = require('adayana/aden/plugins/advPlugin');
    
    var events = [];
    
    var AdvStatus = AdvPlugin.extend(
    /** @lends AdvStatus.prototype */        
    {
        currTime: 0,
        
        showTime: false,
        timeLeft: 0,
        
        /**
         * Initializes the plugin 
         * @param {Object} mediator
         * @param {Object} data
         */
        init: function( name, mediator, data ) {
            this._super(name,mediator,data);
            this.template = Templates.getTemplate(data.source);
            this.state = {
                "status" : "green"
            };
        },
        
        /**
         * Performs initalizations after the engine is ready 
         * @param {Object} instance
         */
        onInit: function( instance ){            
            this.el = $('<div id="'+this.data.id+'" class="status-view layer"></div>');
            this.el.appendTo( aden.el );
            this.el.html(this.template(this.state));
            this.barEl = this.el.find('.bar');
            debug.info('Status module is ready');
            
            this.timeEl = this.el.find('.bar-time');
        },
        
        onLoad: function() {
            this.barEl.css({
                backgroundColor: "#00ff00"
            });
        },
        
        /**
         * Set the current status 
         */
        set: function( status ){
            switch( status ) {
                case "green":
                    this.barEl.css({
                        backgroundColor: "#00ff00"
                    });
                    break;
                case "yellow":
                    this.barEl.animate({
                        backgroundColor: "#ffcc00"
                    },1000);
                    break;
                case "red":
                    this.barEl.animate({
                        backgroundColor: "#e10019"
                    },1000);
                    break;
            }
        },
        
        /**
         * handle engine update event
         */
        onUpdate: function(){
            this.currTime = aden.clock.getTime();
            
            if ( this.showTime ) {
                var s = Math.round((this.timeLeft - this.currTime)/1000);
                this.timeEl.html( s + ' second(s)');
            } else {
                this.timeEl.empty();              
            }
            
            // trigger all events that need to fire
            _.forEach( events, function( event ){
                // when event time is in the past or matches the current time
                if ( event.time <= this.currTime ) {
                    if ( event.fn ) {
                        event.fn();
                    }
                    event.fired = true;
                } else {
                    // otherwise abort loop
                    return false;
                }
            },this);
            
            // remove fired events;
            events = _.reject( events, 'fired' );
        },
        
        /**
         * Add a timed event 
         * @param {Object} id
         * @param {Object} seconds
         * @param {Object} eventName
         * @param {Object} fsm
         */
        add: function( ms, fn ) {
            var timeEvent = {
                'time'     : this.currTime + ms,
                'fn'       : fn,
                'fired'    : false
            };
            var index = _.sortedIndex( events, timeEvent, 'time' );
            events.splice( index, 0, timeEvent );
        },
        
        setTime: function( ms ) {
            this.timeLeft = this.currTime + ms;
            this.showTime = true;
        },
        
        clearTime: function(){
            this.timeLeft = 0;
            this.showTime = false;
            this.timeEl.empty();
        },
        
        /***
         * clear all events 
         */
        clear: function(){
            this.timeLeft = 0;
            this.showTime = false;
            this.timeEl.empty();
            events = [];
        }
    });
    
    return AdvStatus;
});