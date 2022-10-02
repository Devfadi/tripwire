define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        
        AdvPlugin = require('./advPlugin');
        
    var AdvScoreDisplay = AdvPlugin.extend(
    /** @lends AdvScoreDisplay.prototype */        
    {
        totalScore : null,
        
        /**
         * Initializes the Clock Plugin. Called during the Plugin.extend setup
         * @constructs
         * @augments AdvPlugin
         */
        init: function( name, mediator, data ) 
        {
            this._super(name,mediator,data);
            this.updateScore( aden.score.getTotal() );
        },
        
        /**
         * Updates this plugin.
         */
        onUpdate: function() {
            this._super();
            
            // update total score
            var newScore = aden.score.getTotal();
            
            // when the score changes, update
            if ( newScore !== this.totalScore ) {
                this.updateScore(newScore);
            }
            this.totalScore = newScore;
            this.oldScore = this.totalScore;
        },
        
        /**
         * Update the score 
         * @param {Object} newScore
         */
        updateScore: function( newScore ) {
            var score, percent;
            
            // update employee score
            score = aden.score.get('employee');
            percent = Math.round((score/5225)*100);
            $(".employee_score").html( score );
            $(".employee_percent").html( percent + "%" );
            
            // update customer score
            score = aden.score.get('customer');
            percent = Math.round((score/4575)*100);
            $(".customer_score").html( score );
            $(".customer_percent").html( percent + "%" );
            
            // update financial score
            score = aden.score.get('financial');
            percent = Math.round((score/625)*100);
            $(".financial_score").html( score );
            $(".financial_percent").html( percent + "%" );
            
            // update service score
            score = aden.score.get('service');
            percent = Math.round((score/3350)*100);
            $(".service_score").html( score );
            $(".service_percent").html( percent + "%" );
            
            // update total score
            percent = Math.round((newScore/13775)*100);
            $("#score").html(newScore);
            $(".total_score").html( newScore );
            $(".total_percent").html( percent + "%" );
        }
    });
    
    return AdvScoreDisplay;
});
