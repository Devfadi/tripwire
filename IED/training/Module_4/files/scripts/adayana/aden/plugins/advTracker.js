define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        AdvPlugin = require('./advPlugin');
        
    var AdvTracker = AdvPlugin.extend(
    /** @lends AdvTracker.prototype */        
    {
        /**
         * Initialize the tracker plugin 
         * @param {Object} mediator
         * @param {Object} data
         */
        init: function( name, mediator, data ) {
            this._super(name,mediator,data);
            this.id = data.id;
            this.states = data.states;
            // create a save state for this plugin
            this.trackers = {};
        },
        
        onSaveData: function( saveData ) {
            // if ( this.id in saveData ) {
                // throw('Error creating save data: advTracker.js');
            // }
            // saveData[this.id] = $.extend(true,{},this.trackers);
        },
        
        onLoadData: function( saveData ) {
            
        },
        
        /**
         * initialize trackers when level data loads 
         * @param {Object} levelData
         */
        onLoad: function( levelData ) {
            if ( 'plugin' in levelData && this.id in levelData.plugin ) {
                this.order = [];
                this.trackers[levelData.id] = $.extend( true, [], levelData.plugin[this.id].trackers );
                this.level = levelData.id;
                
                _.forEach( this.trackers[this.level], function( tracker ) {
                    if ( tracker.state in this.states ) {
                        tracker.status = this.states[tracker.state];
                    } else {
                        tracker.status = '';
                    }
                    this.order.push( tracker.id );
                },this);
            }
        },
        
        /**
         * Handle data passed in by an adventure object when the object starts. Responsible for
         * tracking state changes, points, and feedback from objects.
         * @param {Object} id
         * @param {Object} data
         */
        onObjectStart: function( id, data ) {
            var obj = aden.objects.getData( id );
            
            var tracker = _.find( this.trackers[this.level], function( tracker ) {
                return tracker.id === data.id;
            });
            
            if ( tracker ) {
                if ( 'state' in data ) {
                    tracker.state = data.state;
                    if ( data.state in this.states ) {
                        tracker.status = this.states[data.state];
                    } else {
                        tracker.status = '';
                    }
                }
                if ( 'points' in data ) {
                    tracker.points = data.points;
                    aden.score.add( this.data.scoreId, tracker.points );
                }
                if ( obj ) {
                    switch( obj.type ) {
                        case "dp":
                        case "dp-multi":
                            tracker.stem = obj.stem;
                            break;
                        case "narration":
                        case "popup":
                            tracker.feedback = obj.text;
                            break;
                        
                    }
                }
            }
        },
        
        /**
         * Handle data passed in by an Adventure Object when it destroys. Mostly responsible for
         * parsing through the report of an object when its finished.
         */
        onObjectDestroy: function( id, data ) {
            var tracker = _.find( this.trackers[this.level], function( tracker ) {
                return tracker.id === data.id;
            });
            var obj = aden.objects.get( id );
            if ( tracker && obj ) { 
                switch( obj.type ) {
                    case "dp":
                        // grab the text for the option the user selected
                        tracker.selection = obj.data.options[obj.report.selection];
                        break;
                    case "dp-multi":
                        tracker.selections = [];
                        tracker.expected = obj.data.expected;
                        _.forEach( obj.report.selections, function( value, index ) {
                            if ( value === 1 ) {
                                tracker.selections.push({
                                    text      : obj.data.options[index],
                                    isCorrect : ( obj.data.answers[index] === 1 || obj.data.answers[index] === true )
                                });
                            }
                        });
                        break;
                    default:
                        // do nothing on destruction of other objects...
                }
                tracker.obj  = id;    
            }
        },
        
        set: function( data ) {
            var tracker = _.find( this.trackers[this.level], function( tracker ) {
                return tracker.id === data.id;
            });
            _.forEach( data, function( value, key ) {
                if ( key === "id" ) {
                    return;
                } else if ( key === "state" ) {
                    tracker.state = value;
                    if ( value in this.states ) {
                        tracker.status = this.states[value];
                    } else {
                        tracker.status = '';
                    }
                } else {
                    tracker[key] = data[key];
                }
            },this);
        },
        
        /**
         * Clear tracker states back to incomplete and clear reference to adventure object that
         * set the state 
         */
        clear: function() {
            _.forEach( this.trackers[this.level], function(tracker){
                tracker.state = "incomplete",
                tracker.obj = null;
            });
        },
        
        /**
         * clear all tracker states for all keys 
         */
        clearAll: function(){
            _.forEach( this.trackers, function( value, key ) {
                _.forEach( value, function(tracker){
                    tracker.state = "incomplete",
                    tracker.obj = null;
                });
            });
        }
    });
    
    return AdvTracker;
});
