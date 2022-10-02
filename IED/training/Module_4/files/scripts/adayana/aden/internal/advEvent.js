define(function(require){
    
    var $ = require('jquery'),
        Class = require('adayana/basic/class');
    
    var AdvEvent = Class.extend({
        /**
         * Initializes new AdvEvent().
         * @param {String}  eventType  type of event this is
         * @param {Boolean} bubbles    indicates if the event should bubble
         * @param {Boolean} cancelable indicates if the event can be canceled
         * @param {Object}  data       object containing event specific data to pass along to listeners
         */
        init: function(eventType, bubbles, cancelable, data) {
            this.type = eventType;
            this.bubbles = bubbles || false;
            this.cancelable = cancelable || false;
            this.data = data || {};
        },
        /**
         * Clone the AdvEvent 
         */
        clone: function() {
            var event = new AdvEvent(this.type, this.bubbles,this.cancelable, $.extend(true,{},data));
            return event;
        },
        /**
         * Destroy the AdvEvent 
         */
        destroy: function() {
            this.type = null;
            this.data = null;
        }
    });
    
    AdvEvent.OBJECT_LOAD       = 'objectLoaded';
    AdvEvent.OBJECT_START      = 'objectStart';
    AdvEvent.OBJECT_DESTROY    = 'objectDestroy';
    AdvEvent.OBJECT_ACTIVATE   = 'objectActivate';
    AdvEvent.OBJECT_DEACTIVATE = 'objectDeactivate';
    AdvEvent.OBJECT_INITIALIZE = 'objectInitialize';
    AdvEvent.OBJECT_DESTROY    = 'objectDestroy';
    AdvEvent.OBJECT_HIDE       = 'objectHide';
    AdvEvent.OBJECT_SHOW       = 'objectShow';
    
    return AdvEvent;
});
