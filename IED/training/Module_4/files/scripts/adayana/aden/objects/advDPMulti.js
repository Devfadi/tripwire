define(function(require){
    
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvObject = require('./advObject'),
        AdvDP     = require('./advDP');
    
	require('adayana/aden/modules/objectFactory');
	
    var defaults = {
        "prefix"   : "branch",
        "modal"    : true,
        "attempts" : -1,
        "response" : "pass-fail",
        "styles"   : {
            "option"    : "adv-dp-option",
            "disabled"  : "option-disabled",
            "selected"  : "adv-state-selected"
        },
        "selectors": {
            "submit" : ".adv-dp-button"
        },
        "onCorrect"     : "dp-correct",
        "onWrong"       : "dp-wrong",
        "onPartial"     : "dp-partial",
        "onMaxAttempts" : "dp-max-attempts",
        "onShow"        : "dp-show",
        "onHide"        : "dp-hide",
        "onStart"       : "dp-start",
        "onDestroy"     : "dp-destroy",
        "onActivate"    : "dp-activate",
        "onDeactivate"  : "dp-deactivate"
    };
    
    // Keys for which the node data overwrite defaults in the global settings
    var dataOverwrite = [
        "attempts",
        "response"
    ];
    
    //TODO - implement method of disabling options
    //TODO - implement method of hiding options
    //TODO - disable previously visited options
    
    var AdvDPMulti = AdvDP.extend(
    /** @lends AdvDPMulti */        
    {    
        /**
         * Initializes a the Node
         * @class
         * @augments Class
         * @constructs
         */
        init: function( mediator, data, options ) {
            debug.info('creating an instance of AdvDPMulti');
            this._super(mediator,data,options);
            this.settings = $.extend(true,{},defaults,options);
            _.forEach( dataOverwrite, function( key ) {
                if ( key in this.data ) {
                    this.settings[key] = this.data[key];
                }
            },this);
            this.mediator.publish('msg:object:init');
            this.report.selections = [];
            this.attempts = 0;
            this.onSubmitClick = $.proxy(this.onSubmitClick,this);
            
            this.data.expected = 0;
            _.forEach( this.data.answers, function(value){
                if (value === 1) {
                    this.data.expected += 1;
                }
            },this);
            if(this.data.min == undefined || this.data.min == null) {
                this.data.min = 1;
            }
            if(this.data.max == undefined || this.data.max == null) {
                this.data.max = this.data.answers.length;
            }
        },
        
        /**
         * Destroys the node
         */
        destroy: function() {
            if ( this.isDestroyed ) {return;}
            this.mediator.publish('msg:object:destroy');
            // remove DOM Object if it exists
            if ( this.el ) {
                this.el.remove();
                delete this.el;
            }
            this._super();
            // remove refrences to these after super call in case anything listening to the destroy
            // event needs to reference them.
            this.settings = null;
            this.template = null;
            this.report   = null;
        },
        
        /**
         * Start the node 
         */
        start: function(){
            this._super();
            
            this.submit = this.el.find( this.settings.selectors.submit );
            this.submit.button().on('click', this.onSubmitClick );
            this.resize();
            
            _.forEach( this.data.options, function( option, i ) {
                this.report.selections.push(0);
            },this);
        },
        
        /**
         * Handle a click event on an option 
         * @param {Object} e
         */
        onOptionClick: function( e ) {
            var el       = $(e.target);
            var index    = el.attr('data-adv-option');
            var id       = el.attr('id');
            var option   = this.data.options[index];
            var selected = el.hasClass( this.settings.styles.selected );
            
            if ( selected ) {
                el.removeClass( this.settings.styles.selected );
                this.report.selections[index] = 0;
            } else {
                el.addClass( this.settings.styles.selected );
                this.report.selections[index] = 1;
            }
            e.preventDefault();
            e.stopPropagation();
        },
        
        /**
         * Handles a click event on the submit button 
         * @param {Object} e
         */
        onSubmitClick: function( e ) {
            var count = this.data.options.length;   // total number of items
            var selected = 0;   // number of selected items
            var matches = 0;    // number of items that match their answer
            var correct = 0;    // number of items that are correctly selected
            var answers = 0;
			
            // evaluate selections
            _.forEach(this.report.selections, function( selection, i ) {
                var answer = this.data.answers[i];
                if ( answer === 1 ) {
                    answers++;
                }
                // find which options match their given answer
                if ( selection === answer ) {
                    matches++;
                }
                // when selected
                if ( selection === 1 ) {
                    selected++;
                    if ( answer === 1 ) {
                        correct++;
                    }
                }
            }, this);
            
            // when min and max conditions are met
            if ( ( !this.data.min || this.data.min === -1 || selected >= this.data.min ) && 
                 ( !this.data.max || this.data.max === -1 || selected <= this.data.max ) 
            ) {
                this.hide();
                this.attempts++;
                // when max number of attempts reached
                if ( this.settings.attempts !== -1 && this.attempts >= this.settings.attempts ) {
                    if ( matches === count ) {
                        this.handleEvent('onCorrect');
                    } else {
                        this.handleEvent('onMaxAttempts');
                    }
                } else {
                    // when using pass-fail responses
                    if ( this.settings.response === "pass-fail" ) {
                        if ( matches === count ) {
                            this.handleEvent('onCorrect');
                        } else {
                            this.handleEvent('onWrong');
                        }
                    } 
                    // otherwise use pass/fail/partial
                    else {
                        // when there are correct selections.
                        if ( correct > 0 ) {
                            // when all selections are correct, and all correct options are selected
                            if ( correct === selected && correct === answers ) {
                                this.handleEvent('onCorrect');
                            } else {
                                this.handleEvent('onPartial');
                            }
                        } 
                        // otherwise all selections are incorrect
                        else {
                            this.handleEvent('onWrong');
                        }
                    }
                }
                this.destroy();
            }
            e.preventDefault();
            e.stopPropagation();
        }
    });
    
    AdvDPMulti.prototype.type = 'dp-multi';
    aden.factory.addType(AdvDPMulti);
    return AdvDPMulti;
    
});
