define(function(require){
    // dependencies:
    var $          = require('jquery'),
        _          = require('lodash'),
        Handlebars = require('handlebars'),
        aden       = require('adayana/aden/engine'),
        Templates  = require('adayana/modules/templates'),
        AdvPlugin  = require('./advPlugin');
    
    Handlebars.registerHelper("ifMatch", function( value, target, options ) {
        if ( value === target ) {
            return options.fn(this);
        } else {
            return options.inverse(this);
        }
    });
    
    var AdvOverlay = AdvPlugin.extend(
    /** @lends AdvOverlay.prototype */        
    {
        init: function( name, mediator, data ) {
            this._super(name,mediator,data);
            this.id = data.id;
            this.template = Templates.getTemplate(data.source);
        },
        
        onLoad: function( levelData ) {
            this.level = levelData.id;
            this.totalScore = levelData.totalPoints;
			this.passingScore = levelData.passingScore;
        },
        
        generate: function( element ) {
            var el      = $(element);
            var score   = aden.score.getTotal();
            var total   = this.totalScore;
            var percent = Math.round((score/total)*100);
            
            // set persistent data
            aden.variables.get(this.level+"_score").set(percent);
            if ( percent >= this.passingScore ) {
                aden.variables.get(this.level+"_complete").set(true);
            }
            
            // create a save state whenever a review is generated
            aden.save.setState();
            
            var isComplete = (aden.variables.get('scenario01_complete').value &&
                              aden.variables.get('scenario02_complete').value &&
                              aden.variables.get('scenario03_complete').value &&
                              aden.variables.get('scenario04_complete').value &&
                              aden.variables.get('scenario05_complete').value &&
                              aden.variables.get('scenario06_complete').value &&
                              aden.variables.get('scenario07_complete').value &&
                              aden.variables.get('scenario08_complete').value &&
                              aden.variables.get('scenario09_complete').value);

            if (isComplete) {
                aden.save.recordCompletion();
            }
            
            // generate after action review
            var data = {
                score   : score,
                total   : total,
                percent : percent,
                results : []
            };
            
            if ( 'tracker' in aden.plugin ) {
                var level = aden.plugin.tracker.level;
                _.forEach( aden.plugin.tracker.trackers[level], function( tracker ) {
                    var result = $.extend(true,{},tracker);
                    if ( tracker.state !== "incomplete") {
                        data.results.push(result);
                    }
                });
            }
            el.html( this.template(data) );
        }
    });
    
    return AdvOverlay;
});
