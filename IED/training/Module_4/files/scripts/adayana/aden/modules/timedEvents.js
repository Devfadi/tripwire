define(function(require){
    // dependencies:
    var $     = require('jquery'),
        _     = require('lodash'),
        _S    = require('adayana/utilities/string'),
        debug = require('adayana/debug/debug'),
        aden  = require('adayana/aden/engine');
//         
    var TimedEvents = aden.TimedEvents = aden.TimedEvents || {};
    
    
    TimedEvents.isReady = false;
    TimedEvents.data = null;
    TimedEvents.initTime = null;
    TimedEvents.startIndex = 0;
    
    TimedEvents.initialize = function( mediator ) {
        this.isReady = true;
        this.mediator = mediator;
        this.startIndex = 0;
        this._subInit   = this.mediator.subscribe('msg:engine:init', this.onInit, null, this );
        this._subUpdate = this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this );
    };
    
    TimedEvents.onInit = function( data ) {
        debug.info('Timed Events Module is ready');
    };
    
    TimedEvents.onLoad = function( levelData ) {
        this.events = data.timedEvents;
    };
    
    /**
     * Update timed events on each engine cycle 
     */
    TimedEvents.onUpdate = function() {
        var time = aden.clock.getTime();
        
        // Store the initial time
        if ( this.initTime === null ) {
            this.initTime = time;
        }
        
        // cancel when there is no data or when inactive
        if ( this.events === null || this.isActive === false ) {
            return;
        }

        // Go through game events and determine if anything should fire.
        var timedEvent,
            i   = this.startIndex,
            len = this.events.length;
            
        for ( i; i < len; i++ ) {
            timedEvent = this.events[i];
            
            // when milliseconds are not available, parse time string
            if ( !('time_ms' in timedEvent) ) {
                timedEvent.time_ms = _S.parseTime( timedEvent.time ) * 1000;
            }
            
            // when the trigger time is equal to or before the current time
            if ( timedEvent.time_ms <= time ) {
                // when timedEvent is active
                if ( timedEvent.isActive ) {
                    // trigger the timed event
                    if ( 'event' in timedEvent ) {
                        if ( 'fsm' in timedEvent ) {
                            this.triggerEvent( timedEvent['event'], timedEvent['fsm'] );
                        } else {
                            this.triggerEvent( timedEvent['event']);
                        }
                    }
                    // trigger the timed action
                    if ( 'action' in timedEvent ) {
                        timedEvent['action']();
                    }
                    // deactivate event
                    timedEvent.isActive = false;
                    // set to visited state
                    timedEvent.visited = true;                    
                }                
                // start at next timedEvent on next update cycle
                this.startIndex = i + 1;
            } else {                
                // this and all subsequent timed events occur in the future, break loop
                break;
            }
        }
    };
    
    TimedEvents.triggerEvent = function( eventName, fsmName ) {
        if ( fsmName && fsmName in aden.fsm ) {
            aden.fsm[fsmName].trigger(eventName);
        } else {
            _.forEach( aden.fsm, function( fsm ) {
                fsm.trigger(eventName);
            });
        }
    };
    
    /**
     * Sets an event's state to active
     * @param {Object} eventName
     */
    TimedEvents.activateEvent = function(eventName) {
        this.findAndExecute( eventName, function(timedEvent) { timedEvent.isActive = true; } );
    };

    /**
     * Sets an event's state to inactive/deactivated
     * @param {Object} eventName
     */
    TimedEvents.deactivateEvent = function(eventName) {
        this.findAndExecute( eventName, function(timedEvent) { timedEvent.isActive = false; } );
    };
    
    /**
     * Create a new timed event, and place it in chronological order
     */
    TimedEvents.createEvent = function( eventData ){
        var time;
        if ( 'time_ms' in eventData ) {
            time = eventData.time_ms;
        } else {
            time = _S.parseTime( eventData.time ) * 1000; 
        }
        
        var timedEvent,
            i = 0,
            len = this.events.length;
        // go through all timed events...
        for ( i; i < len; i++ ) {
            timedEvent = this.events[i];
            
            // when milliseconds are not available, parse time string
            if ( !('time_ms' in timedEvent) ) {
                timedEvent.time_ms = _S.parseTime( timedEvent.time ) * 1000;
            }
            
            // if existing event occurs before or at the same time as new event, move to next index
            if ( timedEvent.time_ms <= time ) {
                continue;
            } else {
                break;
            }
        }
        // add new timed event at the index we found
        this.events.splice( i, 0, eventData );
    };

    /**
     * Deactivate all timed events between two points in time 
     */
    TimedEvents.deactivateTimeSpan = function( startTime, endTime ) {
        // when parameters are strings, get millisecond equivalent
        if ( _.isString(startTime) ) {
            startTime = _S.parseTime( startTime ) * 1000;
        }
        if ( _.isString(endTime) ) {
            endTime = _S.parseTime( endTime ) * 1000;
        }
        
        var timedEvent,
            i   = 0,
            len = this.events.length;
        // go through all timed events...
        for ( i; i < len; i++ ) {
            timedEvent = this.events[i];
            // when milliseconds are not available, parse time string
            if ( !('time_ms' in timedEvent) ) {
                timedEvent.time_ms = _S.parseTime( timedEvent.time ) * 1000;
            }
            // when timed event occurs after or at the startTime and also occurs before or at the endTime
            if ( timedEvent.time_ms >= startTime && timedEvent.time_ms <= endTime ) {
                if ( timedEvent.isActive ) {
                    // check for skip event
                    if ( timedEvent.hasOwnProperty('skipEvent') ) {
                        this.triggerEvent(timedEvent['skipEvent']);
                    }
                    // check for skip action
                    if ( timedEvent.hasOwnProperty('onSkip') ) {
                        timedEvent['onSkip']();
                    }
                }
                // deactivate event
                timedEvent.isActive = false;
                timedEvent.wasSkipped = true;
            }
        }
    };

    /**
     * Check for skip events and onSkip actions 
     */
    TimedEvents.checkSkippedEvents = function( startTime, endTime ) {
        // when parameters are strings, get millisecond equivalent
        if ( _.isString(startTime) ) {
            startTime = _S.parseTime( startTime ) * 1000;
        }
        if ( _.isString(endTime) ) {
            endTime = _S.parseTime( endTime ) * 1000;
        }
        
        var timedEvent,
            len = this.events.length,
            i   = (len - 1);
                        
        // go through all timed events backwards
        for ( i; i > 0; i-- ) {
            timedEvent = this.events[i];
            // when milliseconds are not available, parse time string
            if ( !('time_ms' in timedEvent) ) {
                timedEvent.time_ms = _S.parseTime( timedEvent.time ) * 1000;
            }
            // when timed event occurs after or at the startTime and also occurs before or at the endTime
            if ( timedEvent.time_ms >= startTime && timedEvent.time_ms <= endTime ) {
                if ( timedEvent.wasSkipped ) {
                    // check for skip event
                    if ( timedEvent.hasOwnProperty('skipEvent') ) {
                        this.triggerEvent(timedEvent['skipEvent']);
                    }
                    // check for skip action
                    if ( timedEvent.hasOwnProperty('onSkip') ) {
                        timedEvent['onSkip']();
                    }
                }
            }
        }
    };

    /**
     * Check if any of the conflicting events exist between two points in time 
     */
    TimedEvents.checkConflicts = function( conflicts, startTime, endTime ) {
        // when parameters are strings, get millisecond equivalent
        if ( _.isString(startTime) ) {
            startTime = _S.parseTime( startTime ) * 1000;
        }
        if ( _.isString(endTime) ) {
            endTime = _S.parseTime( endTime ) * 1000;
        }
        
        var timedEvent,
            i = 0,
            len = this.events.length;
        // go through all timed events...
        for ( i; i < len; i++ ) {
            timedEvent = this.events[i];
            // when milliseconds are not available, parse time string
            if ( !('time_ms' in timedEvent) ) {
                timedEvent.time_ms = _S.parseTime( timedEvent.time ) * 1000;
            }
            // when an active timed event occurs after or at the startTime 
            // and also occurs before or at the endTime
            // when the event id is listed in the conflict array
            if ( timedEvent.time_ms >= startTime && timedEvent.time_ms <= endTime && conflicts.indexOf( timedEvent.id ) > -1 && timedEvent.isActive) {
                return timedEvent;
            }
        }
        return null;
    };

    /**
     * If a timed event with the specified name exists, pass it into a callback function 
     */
    TimedEvents.findAndExecute = function( name, callback ) {
        var timedEvent = this.findEvent(name);
        if ( timedEvent ) {
            callback(timedEvent);
        }
    };

    /**
     * Find the Timed Event with the given name/id
     * @param {String} name id of the event to find
     */
    TimedEvents.findEvent = function( name ) {
        var timedEvent,
            i = this.startIndex,
            len = this.events.length;
            
        for ( i; i < len; i++ ) {
            timedEvent = this.events[i];
            if ( timedEvent.id === name ) {
                return timedEvent;
            }
        }
        
        return undefined;
    };

    /**
     * Skip ahead to next timed event 
     */
    TimedEvents.skipAhead = function() {
        // Go through game events and determine if anything should fire.
        var timedEvent,
            i = this.startIndex,
            len = this.events.length;
            
        for ( i; i < len; i++ ) {
            timedEvent = this.events[i];
            
            // when milliseconds are not available, parse time string
            if ( !('time_ms' in timedEvent) ) {
                timedEvent.time_ms = _S.parseTime( timedEvent.time ) * 1000;
            }
            
            if ( timedEvent.isActive ) {
                aden.clock.setClock( timedEvent.time );
                return;
            }
        }
    };

    /**
     * Grab the next event time 
     */
    TimedEvents.getNextEventTime = function(){
        // Go through game events and determine if anything should fire.
        var timedEvent,
            i = this.startIndex,
            len = this.events.length;
        if ( i < len ) {
            // grab data
            timedEvent = this.events[i];
            // when milliseconds are not available, parse time string
            if ( !('time_ms' in timedEvent) ) {
                timedEvent.time_ms = _S.parseTime( timedEvent.time ) * 1000;
            }
            return timedEvent.time_ms;
        }
        return -1;
    };
    
    return TimedEvents;
});
