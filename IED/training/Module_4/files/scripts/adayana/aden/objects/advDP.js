 
/**
 * @file Contains the definition of a basic Adventure Engine Decision Point Object.
 */
define(function(require){
    
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvObject = require('./advObject');
    
	require('adayana/aden/modules/objectFactory');
	
    var defaults = {
        "prefix" : "branch",
        "modal"  : true,
        "styles" : {
            "option"    : "adv-dp-option",
            "disabled"  : "option-disabled"
        },
        "onShow"       : "dp-show",
        "onHide"       : "dp-hide",
        "onStart"      : "dp-start",
        "onDestroy"    : "dp-destroy",
        "onActivate"   : "dp-activate",
        "onDeactivate" : "dp-deactivate",
        "randomize"    : false
    };
    
    //TODO - implement method of disabling options
    //TODO - implement method of hiding options
    //TODO - disable previously visited options
    
    var AdvDP = AdvObject.extend(
    /** @lends AdvDP */
    {    
        report: null,
        
        /**
         * Initializes a the Node
         * @class
         * @augments Class
         * @constructs
         */
        init: function( mediator, data, options ) {
            debug.info('creating an instance of AdvDP');
            this._super(mediator,data,options);
            this.settings = $.extend(true,{},defaults,options);
            this.template = Templates.getTemplate(this.settings.source);
            this.randomize = (data.randomize) ? data.randomize : this.settings.randomize;
            this.report = {
                id        : data.id,
                selection : 0,
                startTime : new Date().getTime(),
                stopTime  : -1
            };
            this.onOptionClick = $.proxy(this.onOptionClick, this);
            this.mediator.publish('msg:object:init');
        },
        
        /**
         * Destroys the Adventure Object 
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
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            this.mediator.remove('msg:engine:resize', this.onResize);
        },
        
        /**
         * Resizes stuff when display area size changes.
         */
        onResize : function() {
            if (this.isActive || this.isVisible) {
                this.resize();
            }
        },
        
        /**
         * Reloads Object
         */
        reload : function() {
            
        },

        /**
         * Starts Object
         */
        start : function() {
            this._super();
            
            // create a random order
            this.order = [];
            _.forEach( this.data.options, function( value, i ) {
                this.order.push(i);
            },this);
            
            // Shuffle Values
            if ( this.randomize ) {
                var len = this.order.length,
                    ran, temp;
                for ( var i = len-1; i > 0; i-- ) {
                    ran = Math.floor(Math.random() * (i+1));
                    temp = this.order[ran];
                    this.order[ran] = this.order[i];
                    this.order[i] = temp;
                }
            }
                   
            var data = {
                stem: this.data.stem,
                expected: this.data.expected || 1,
                options: []
            };
            _.forEach( this.order, function(i){
                data.options.push({
                    text: this.data.options[i],
                    index: i,
                    id: this.settings.prefix + i
                });
            },this);
            
            // generate element
            this.el = $(this.template(data));
            this.el.attr('id', this.id).appendTo(aden.el);
            // this.el.find('.' + this.settings.styles.option).each($.proxy(function( i, el ){
                // $(el).attr('data-adv-option',i);
                // $(el).attr('id', this.settings.prefix + i );
            // },this));
            this.resize();
            
            // for every option
            _.forEach( this.order, function( i ){
                var option = this.data.options[i];
                var optionEl = this.el.find( '#' + this.settings.prefix + i ); 
                if ( option.visited ) {
                    optionEl.addClass( this.settings.styles.disabled );
                } else {
                    optionEl.click(this.onOptionClick);
                }
            },this);
        },
        
        /**
         * Method runs whenever one of the decision point's options are clicked.
         * Triggers the appropriate option/branch and sets the object as complete.
         */
        onOptionClick: function( e ){
            // deactivate the dp
            this.isActive = false;
            var index = $(e.target).attr('data-adv-option');
            var id = $(e.target).attr('id');
            var option = this.data.options[index];
            // handle event
            if ( _.isString( option ) ) {
                this.triggerEvent( id );
            } else {
                this.triggerEvent( option['event'] );
            }
            // record items in the report
            this.report.stopTime = new Date().getTime();
            this.report.selection = index;
            // close & destroy the DP
            this.destroy();
            e.preventDefault();
            e.stopPropagation();
        },
        
        /**
         * Resizes the Decision Point 
         */
        resize: function(){
            var viewHeight = aden.height;
            this.el.find('.adv-dp-content').css({ 'max-height': (viewHeight - 20) + "px" });
            this.position();
        },

        /**
         * Positions node
         */
        position : function() {
            // re-center DP on bottom of screen;
            this.el.position({
                my: 'center bottom',
                at: 'center bottom',
                of: '#' + aden.el.attr('id')
            });
        },
        
        close: function() {
            this.destroy();
        }
    });
    
    AdvDP.prototype.type = 'dp';
    aden.factory.addType(AdvDP);
    
    return AdvDP;
    
});
