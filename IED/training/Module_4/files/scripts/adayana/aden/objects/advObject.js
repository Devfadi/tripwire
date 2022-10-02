define(function(require) {
    // dependencies:
    var $               = require('jquery'),
        EventDispatcher = require('adayana/basic/eventDispatcher'),
        AdvEvent        = require('adayana/aden/internal/advEvent');
    
    /**
     * Constructs an Adventure Object
     * @constructor 
     */
    var AdvObject = EventDispatcher.extend({
        /**
         * reference to the mediator object 
         */
        mediator: null,
        /**
         * Indicates if the node is ready
         */
        isReady : false,

        /**
         * Indicates if the node is active
         */
        isActive : false,

        /**
         * Indicates visibility
         */
        isVisible : true,

        /**
         * Indicates that this node was destroyed
         */
        isDestroyed : false,

        /**
         * jQuery/DOM Object
         */
        el : null,

        /**
         * id of this object
         */
        id : "",

        /**
         * Node Data
         */
        data : null,

        /**
         * creates an instance of an Adventure Object Entity
         * @constructs
         * @augments EventDispatcher
         * @augments Class
         * @param {Object} data Object's configuration data
         */
        init : function( mediator, data, options ) {
            debug.log('creating a new Adventure Object: ' + data.id);
            
            this._super();
            
            this.id = data.id;
            this.data = data;
            this.parent = null;
            this.isActive = false;
            this.isVisible = true;
            this.isDestroyed = false;
            this.mediator = mediator;
            this.subscribe();
            this.triggerEvent = $.proxy(this.triggerEvent,this);
            this.fireEvent(new AdvEvent(AdvEvent.OBJECT_LOAD, true, true));
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {},
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {},

        /**
         * Updates Node
         */
        onUpdate : function() {
            if (this.isActive) {
                // update stuff
            }
        },

        /**
         * Resizes stuff when display area size changes.
         */
        onResize : function() {
            if (this.isActive || this.isVisible) {
                // resize stuff
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
        reload : function() {
            //TODO - reset data
            //TODO - add time parameter to reset prevTime and startTime
        },

        /**
         * Destroy the Object
         */
        destroy : function() {
            if ( this.isDestroyed ) {return;}
            
            // when there is DOM object, destroy it
            if (this.el) {
                this.el.remove();
                delete this.el;
            }
            this.unsubscribe();
            // check for Object's onDestroy attribute
            this.isDestroyed = true;
            this.handleEvent('onDestroy');
            // notify listeners
            this.fireEvent(new AdvEvent(AdvEvent.OBJECT_DESTROY, true, true));
            // finish destruction by calling eventDispatcher's Destroy function
            this._super();
            this.id       = null;
            this.data     = null;
            this.parent   = null;
            this.mediator = null;
        },

        /**
         * Starts Object
         */
        start : function() {
            debug.log('starting object: ' + this.id);
            this.activate();
            this.handleEvent('onStart');
            this.isReady = true;
            this.fireEvent(new AdvEvent(AdvEvent.OBJECT_START, true, true));
        },

        /**
         * Activate the object
         */
        activate : function() {
            debug.log('activating object: ' + this.id);
            
            this.isActive = true;
            if ( this.data ) {this.data.isActive = true;}
            this.handleEvent('onActivate');
            this.fireEvent(new AdvEvent(AdvEvent.OBJECT_ACTIVATE, true, true));
        },

        /**
         * Deactivate the object
         */
        deactivate : function() {
            debug.log('deactivating object: ' + this.id);
            
            this.isActive = false;
            if ( this.data ) {this.data.isActive = false;}
            this.handleEvent('onDeactivate');
            this.fireEvent(new AdvEvent(AdvEvent.OBJECT_DEACTIVATE, true, true));
        },

        /**
         * Skips stuff
         */
        skip : function() {
            // when the node is running (started and not set to complete)
            if (this.isActive) {
                //TODO - run checks to see if this node should skip.
                // no reason to make generic nodes skippable right now...
            }
        },

        /**
         * Positions node
         */
        position : function() {
            //TODO - create positioning method
        },

        /**
         * Event Handler
         */
        eventHandler : function(e) {
            //TODO - make event handler for DOM Events and Custom Events fired from our domObj and other components
            //TODO - for components that fire time events, listen for those and trigger appropriate actions
        },

        /**
         * Show the visual items
         */
        show : function() {
            if (this.el) {
                this.el.show();
            }
            this.isVisible = true;
            if ( this.data ) {this.data.isVisible = true;}
            this.handleEvent('onShow');
            this.fireEvent(new AdvEvent(AdvEvent.OBJECT_SHOW, true, true));
        },

        /**
         * Hide the visual items
         */
        hide : function() {
            if (this.el) {
                this.el.hide();
            }
            this.isVisible = false;
            if ( this.data ) {this.data.isVisible = false;}
            this.handleEvent('onHide');
            this.fireEvent(new AdvEvent(AdvEvent.OBJECT_HIDE, true, true));
        },
        
        /**
         * Checks the object data to see if it has a handler for the given event name 
         * @param {Object} eventName
         */
        handleEvent : function( eventName ) {
            // when object data defines an event handler...
            if ( this.data && eventName in this.data ) {
                var action = this.data[eventName];
                if ( _.isFunction(action) ) {
                    action();
                } else if ( _.isString(action) ) {
                    // when data defines an fsm name
                    if ( 'fsm' in this.data ) {
                        aden.fsm[this.data.fsm].trigger(action);
                    }
                    else if ( aden.objects.fsm ) {
                        aden.fsm[aden.objects.fsm].trigger(action);
                    }
                    else {
                        _.forEach( aden.fsm, function( fsm ) {
                            fsm.trigger(action);
                        });
                    }
                } else if ( _.isObject(action) && 'fsm' in action && 'event' in action ) {
                    aden.fsm[action.fsm].trigger(action.event);
                }
            }
            
            if( this.settings ) {
                // when data specifies an fsm to trigger an event on
                if ( 'fsm' in this.data ) {
                    aden.fsm[this.data.fsm].trigger( this.settings[eventName] );
                }
                else if ( aden.objects.fsm ) {
                    aden.fsm[aden.objects.fsm].trigger( this.settings[eventName] );
                }
                // otherwise send to all FSMs
                else {
                    _.forEach( aden.fsm, function( fsm ) {
                        fsm.trigger( this.settings[eventName] );
                    }, this);                
                }
            }
        },
        
        triggerEvent: function( eventName ) {
            // when data specifies an fsm to trigger an event on
            if ( 'fsm' in this.data ) {
                aden.fsm[this.data.fsm].trigger( eventName );
            }
            else if ( aden.objects.fsm ) {
                aden.fsm[aden.objects.fsm].trigger( eventName );
            }
            // otherwise send to all FSMs
            else {
                _.forEach( aden.fsm, function( fsm ) {
                    fsm.trigger( eventName );
                }, this);                
            }
        }
    });
    
    return AdvObject;
});
