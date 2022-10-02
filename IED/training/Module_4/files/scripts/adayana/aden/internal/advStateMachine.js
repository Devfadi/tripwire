define(function(require){
    
    var $     = require('jquery'),
        _     = require('lodash'),
        aden  = require('adayana/aden/engine'),
        debug = require('adayana/debug/debug');
        
    var AdvStateMachine = function( mediator, data ) {
        if ( data.id in aden.fsm ) {
            throw "ERROR! Another Finite State Machine has already taken the name " + name;
        }
        
        this.id       = data.id;
        this.states   = data.states.slice();
        this.debug    = data.debug;
        this.initial  = data.initial;
        this.inactive = data.inactive;
        this.mediator = mediator;
        
        _.forEach( this.states, function(state) {
            state.visits = 0;
        });
        
        /**
         * When true, indicates that the state machine is active
         * @private 
         */
        var active = true;
        
        /**
         * Retrive or Set the value of the active boolean 
         */
        this.active = function( value, triggerEvent ){
            if ( value !== null && typeof value !== 'undefined' ) {
                active = !!value;
                if ( triggerEvent !== false ) {
                    if ( active ) {
                        if ( this.state && 'onActivate' in this.state ) {
                            this.state.onActivate();
                        }
                    } else {
                        if ( this.state && 'onDeactivate' in this.state ) {
                            this.state.onDeactivate();
                        }
                    }
                }
            }
            return active;
        };
        
        // subscribe to engine updates?
        if ( data.useUpdate ) {
            this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
        }
        // subscribe to channel that triggers global fsm events
        this.mediator.subscribe('trigger:fsm:event', this.trigger, null, this );
        // subscribe to channel that triggers events on this fsm
        this.mediator.subscribe('trigger:fsm:' + this.id + ":event", this.trigger, null, this );
        
        // set initial state
        this.setState( data.initial );
        
        aden.fsm[data.id] = this;
    };
    
    AdvStateMachine.prototype = {
        /**
         * State Machine Identifier 
         */
        id: "undefined",
        
        /**
         * Array of states 
         */
        states: null,
        
        /**
         * debug DOM Element 
         */
        debug: null,
        
        /**
         * Resets the state machine back to its initial state. 
         */
        reset: function(){
            this.active(true,false);
            this.setState( this.initial );
        },
        
        /**
         * Executes the current state node's onUpdate action, if it contains one 
         */
        onUpdate: function() {
            if ( this.active() && this.state && this.state.hasOwnProperty( 'onUpdate' ) ) {
                this.state.onUpdate();
            }
        },
        
        /**
         * Locate a state by name
         * @param {Object} name
         */
        findState: function( name ) {
            var i = 0;
            var len = this.states.length;
            var state;
            for( i; i < len; i++ ) {
                state = this.states[i];
                if ( state.id === name ) {
                    return state;
                }
            }
            return null;
        },
        
        /**
         * Set the state machine to a new state 
         * @param {Object} state
         */
        setState: function( stateName ) {
            if ( !this.active() ) { return; }
            debug.log('fsm ' + this.id + " entering state " + stateName );
            
            var state = this.findState( stateName );
            // when state is defined
            if ( state ) {
                // execute previous event's onExit event
                if ( this.state ) {
                    if ( this.state.hasOwnProperty( 'onExit' ) && this.state.onExit !== null ) {
                        this.state.onExit();
                    }
                    // notify listeners that we're leaving the previous state
                    this.mediator.publish('msg:fsm:state:exit', this.id, state.id );
                    this.mediator.publish('msg:fsm:' + this.id + ":state:exit", state.id);
                } 
                
                // set state data
                this.previous = state;
                this.state = state;
                this.state.visits++;                
                
                if ( this.debug && stateName != this.inactive ) {
                    $( this.debug ).html( stateName );
                }
                
                if ( 'object' in this.state && _.isString(this.state.object)) {
                    aden.objects.load(this.state.object);
                }
                
                if ( this.state.visits === 1 && 'onInit' in this.state ) {
                    this.state.onInit();
                } else if ( this.state.visits > 1 && 'onReturn' in this.state ){
                    this.state.onReturn();
                }
                
                // execute new state's onEnter Action
                if ( this.state.hasOwnProperty( 'onEnter' ) ) {
                    this.state.onEnter();
                }
                
                // notify listeners of state change
                this.mediator.publish('msg:fsm:state:enter', this.id, state.id );
                this.mediator.publish('msg:fsm:' + this.id + ":state:enter", state.id);
            } 
            else {
                alert('error - state does not exist: ' + stateName );
            }
        },
        
        /**
         * Trigger a state machine event in order to change states 
         * @param {Object} eventName
         */
        trigger: function( eventName ) {
            if ( !this.active() ) { return; }
            debug.log('triggering ' + eventName + ' on ' + this.id );
            
            if ( eventName ) {
                var branch = this.getBranch(eventName);
                if ( branch ) {
                    if ( branch.hasOwnProperty('onBeforeTrigger') ) {
                        branch.onBeforeTrigger();
                    }
                    this.mediator.publish('msg:fsm:event:before', this.id, eventName );
                    this.mediator.publish('msg:fsm:' + this.id + ":event:before", eventName);
                    // when target defined, go there
                    if ( branch.target ) {
                        this.setState( branch.target );
                    } 
                    // when back is truthy, go to previous state
                    else if ( branch.back ) {
                        this.setState( this.previous.id );
                    } 
                    // otherwise trigger current state again
                    else {
                        this.setState( this.state.id );
                    }
                    if ( branch.hasOwnProperty('onAfterTrigger') ) {
                        branch.onAfterTrigger();
                    }
                    this.mediator.publish('msg:fsm:' + this.id + ":event:after:" + eventName);        
                } 
                else {
                    debug.warn('branch does not exist: ' + eventName );
                    this.mediator.publish('msg:fsm:event:error', this.id );
                    this.mediator.publish('msg:fsm:' + this.id + "event:error");
                }
            }
        },
        
        /**
         * Locate a branch in the current state which matches the given event name 
         * @param {Object} eventName
         */
        getBranch: function( eventName ) {
            if ( !this.active() ) { return; }
            if ( 'branches' in this.state ) {
                var i = 0, len = this.state.branches.length, branch;
                for ( i; i < len; i++ ) {
                    branch = this.state.branches[i];
                    if ( branch.id === eventName ) {
                        return branch;
                    }
                }
            }
            return null;
        }
    };
    
    return AdvStateMachine;
});
