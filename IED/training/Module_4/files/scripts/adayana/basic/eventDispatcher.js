/**
 * @file houses the EventDispatcher Class
 * @author Valerie Burzynski <vburzynski@adayana.com>
 * @version 0.1.0
 * @history 2012.XX.XX VRB - Initial Version
 * @history 2014.06.11 VRB - AMD Version
 */
define(function(require){
	
	var Class = require('./class');
	
	var EventDispatcher = Class.extend(
	/** @lends EventDispatcher.prototype */
	{
		/**
		 * Parent Object (which is also an EventDispatcher)
		 * @default null 
		 */
		parent: null,
		
		/**
		 * Event Dispatcher
		 * @class Creates a class of objects capable of firing events
		 * @augments Class
		 * @constructs
		 */
		init: function() {
			this._listeners = {};
		},
		
		/**
		 * Identifies object as event dispatcher
		 */
		isEventDispatcher: true,
		
		/**
		 * object containing all event listener callback functions
		 */
		_listeners: null,
		
		/**
		 * Destory object
		 */
		destroy: function() {
			delete this._listeners;
			delete this.parent;
		},
		
		/**
		 * Add new Event Listener
		 */
		addEventListener: function( eventType, listener ) {
			// Check to see if the eventType is registered on this object yet.
			if (typeof this._listeners[eventType] === "undefined") {
				this._listeners[eventType] = [];
			}
			// Add Listener
			if ( this._listeners[eventType].indexOf(listener) === -1 ) {
				this._listeners[eventType].push(listener);            
			}
		},
		
		on: function( eventType, listener ) {
			this.addEventListener( eventType, listener );
		},
		
		/**
		 * Remove event listener
		 */
		removeEventListener: function( eventType, listener ) {
			if ( eventType in this._listeners ) {
				var eventListeners = this._listeners[eventType];
				var index = eventListeners.indexOf(listener);
				
				if ( index === -1 ){
					return false;
				}
				eventListeners.splice(index,1);
				return true;
			} else {
				return false;
			}
		},
		
		off: function( eventType, listener ) {
			this.removeEventListener( eventType, listener );
		},
		
		trigger: function( event ) {
			this.fireEvent( event );
		},
		
		/**
		 * Fire an Event
		 */
		fireEvent: function( event ) {
			//TODO - implement stopPropagation.
			//TODO - add event.cancelable to prevent cancellation of certain events.
			
			// Exit when no listeners exist
			if ( !this._listeners ) {
				return;
			}
			
			// Run check on arguments
			try {
                if ( arguments.length < 1 ) {
                    throw "noEventDefined";
                } else if ( !_.isString(event) && !_.isObject(event) ) {
                    throw "invalidEvent";
                }
                if ( _.isObject(event) && !event.type ) {
                    throw "noEventType";
                }
			} catch(er) {
				switch ( er ) {
					case "noEventDefined" : 
						console.error('Object is unable to fire event. Event was not designated.');
						break;
					case "invalidEvent" :
						console.error('parameter "event" must be a string or event object');
						break;
					case "noEventType" :
						console.error('event does not have a type.');
						break;
					default :
						console.error(er);
				}
				return false;
			}
			
			// Create event object when string is passed as event
			if ( _.isString(event) ) {
				var str = event;
				event = {};
				event.type = str;
			}
			
			// set target
			if ( !event.currentTarget ) {
				event.target        = this;        // set the target which fired the original event
				event.currentTarget = this;        // set the last object to bubble the event
			}
			else {
				event.target        = event.currentTarget;
				event.currentTarget = this;
			}
			
			// Fire Event
			if ( event.type in this._listeners ) {
				var eventListeners = this._listeners[event.type];
				
				if ( eventListeners === undefined ) {
					return false;
				}
				// queue all the callbacks (in case of removal of event listeners during processing )
				var callbackList = [];
				for ( var i=0; i<eventListeners.length; i++) {
					if ( eventListeners[i] === undefined ) {
						continue;}
					callbackList.push( eventListeners[i] );
				}
				
				for ( i=0; i<callbackList.length; i++) {
					callbackList[i]( event );
				}
			}
			
			// Event Bubbling.
			// bubble when event.bubbling === true;
			if ( event.bubbles && this.parent !== null && this.parent.isEventDispatcher && this.parent && this.parent.fireEvent ) {
				this.parent.fireEvent(event);
			}
		}
	});
	
	return EventDispatcher;
});