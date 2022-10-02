define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        _S        = require('adayana/utilities/string'),
        debug     = require('adayana/debug/debug'),
        Templates = require('adayana/modules/templates'),
        AdvPlugin = require('./advPlugin');
    
    /**
     * Array of Month Strings
     * @private
     */
    var month = ["January","February","March","April","May","June","July","August","September","October","November","December"];
    
    /**
     * Array of Weekday Strings
     * @private
     */
    var weekday = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"];
    
    
    var AdvClock = AdvPlugin.extend(
    /** @lends AdvClock.prototype */        
    {
        /**
         * Indicates if the time should be displayed in military (24 hour) time
         */
        isMilitaryTime : false,
        
        /**
         * Date Object
         */
        date : new Date(),
        
        /**
         * Initializes the Clock Plugin. Called during the Plugin.extend setup
         * @constructs
         * @augments AdvPlugin
         */
        init: function( name, mediator, data ) {
            this._super( name, mediator, data );
            this.date = new Date();
            this.template = Templates.getTemplate(data.source);
            this.el = $(data.selector);
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            this.mediator.subscribe('msg:engine:init',   this.onInit, null, this );
            this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:init',   this.onInit);
            this.mediator.remove('msg:engine:update', this.onUpdate);
        },
        
        onInit: function( instance ){
            debug.info('Clock module is ready');
        },
        
        /**
         * Updates this plugin.
         */
        onUpdate: function( aden ) {
            this.date = aden.clock.date;
            var hours = this.date.getHours();        
            var suffix;
            if ( !this.isMilitaryTime ) {
                suffix = ( Math.floor(hours/12) % 2 === 1 ) ? "pm" : "am";
                hours  = ( hours % 12 );
                if ( hours === 0 ) {
                    hours = 12;
                }            
            } else {
                suffix = "";
                hours = _S.padDigits(hours, 2);
            }
            
            this.data = {};
            this.data.suffix   = suffix;
            this.data.hours    = hours;
            this.data.minutes  = _S.padDigits(this.date.getMinutes(),2);
            this.data.seconds  = _S.padDigits(this.date.getSeconds(),2);
            this.data.weekday  = weekday[this.date.getDay()];
            this.data.weekAbr  = this.data.weekday.substr(0,3);
            this.data.month    = month[this.date.getMonth()];
            this.data.monthAbr = this.data.month.substr(0,3);
            this.data.date     = this.date.getDate();
            this.data.year     = this.date.getFullYear();
            this.data.monthNum = this.date.getMonth();
            
            // change html only if content changes
            var archive = this.html;
            this.html = this.template(this.data);
            if ( archive !== this.html ) {
                this.el.html( this.html );
            }
        },
        
        /**
         * This method removes the Clock Plugin
         */
        destroy: function() {
            delete this.template;
            if ( this.el ) {
                this.el.remove();
                delete this.el;
            }
            delete this.data;
        }
    });
    
    return AdvClock;
});
