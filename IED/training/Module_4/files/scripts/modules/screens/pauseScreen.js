define(function(require){
    var Screen = require('./screen'),
        mediator = require('adayana/modules/mediatorShim'),
        aden = require('adayana/aden/engine'),
        $ = require('jquery'),
        _ = require('lodash');
    
    var view;
    
    var defaults = {
        shouldTogglePosition: true,
        shouldToggleVisibility: false,
        collapseDirection: 'left',
        collapseDimension: 75,
        clickElToggle: true,
        openOnInit: false,
        shouldOpenOnEvent: true
    };
    
    var Pause = Screen.extend({
        isOpen: false,
        
        /**
         * Initializes the Pause Screen
         */
        init: function( id, template, data, options ){
            this._super(id, template, data);
            this.settings = $.extend(true,{},defaults,options);
            
            if (this.settings.shouldOpenOnEvent) {
                aden.mediator.subscribe('msg:resources:toggle', this.toggle, null, this);
            }
            
            view = 'scenarios';
            
            this.buttons = this.el.find('.menu-tabs button');
            this.buttons.click($.proxy(function(e){
                switch ( view ) {
                    case 'scenarios':
                        this.el.find('.scenarios').hide();
                        this.el.find('.resources').show();
                        $(this.buttons.get(0)).addClass('state-active');
                        $(this.buttons.get(1)).removeClass('state-active');
                        view = 'resources';
                        break;
                    default:
                        this.el.find('.scenarios').show();
                        this.el.find('.resources').hide();
                        $(this.buttons.get(0)).removeClass('state-active');
                        $(this.buttons.get(1)).addClass('state-active');
                        view = 'scenarios';
               }
               e.stopPropagation();
               return false;
            },this));
            
            this.isOpen = this.settings.openOnInit;
            if ( this.isOpen ) {
                if ( this.settings.shouldTogglePosition ) {
                    this.el.css({left:0});
                }
                if ( this.settings.shouldToggleVisibility ) {
                    this.el.show();
                }
                aden.mediator.publish('msg:engine:pause');
            } else {
                if ( this.settings.shouldTogglePosition ) {
                    this.el.css({left:-$('body').width()});
                    //this.el.css({left:75 - $('body').width()});
                }
                if ( this.settings.shouldToggleVisibility ) {
                    this.el.hide();
                }
            }
            
            /*
            if ( this.settings.clickElToggle ) {
                this.el.click($.proxy(function(){
                    this.toggle();
                },this));
            }
            */
            
            this.el.find('.resume').click($.proxy(function(e){
                //aden.fsm.gameState.trigger('toggle-pause');
                this.toggle();
				aden.fsm.gameState.trigger('toggle-pause');
                e.stopPropagation();
                return false;
            },this));
            
            this.el.find('.stop').click(function(){
                mediator.publish('trigger:fsm:gameView:event','end');
            });
        },
        
        toggle: function(){
            var width = $('body').width();
            
            if ( this.isOpen ) {
                if ( this.settings.shouldTogglePosition ) {
                    this.el.animate({
                        left: -width
                        //left: 75 - width
                    }, 1000);
                }
                if ( this.settings.shouldToggleVisibility ) {
                    this.el.hide();
                }
                this.isOpen = false;
                aden.mediator.publish('msg:engine:resume');
            } else {
                if ( this.settings.shouldTogglePosition ) {
                    this.el.animate({
                        left: 0
                    }, 1000);
                }
                if ( this.settings.shouldToggleVisibility ) {
                    this.el.show();
                }
                this.isOpen = true;
                aden.mediator.publish('msg:engine:pause');
            }
			
        },
        
        destroy: function(){
            if (this.settings.shouldOpenOnEvent) {
                aden.mediator.remove('msg:resources:toggle', this.toggle, null, this);
            }
            
            if ( this.isOpen ) {
                aden.mediator.publish('msg:engine:resume');
            }
            
            this._super();
        },
        
        onResize: function(){
            if ( this.settings ) {
                if ( this.isOpen ) {
                    if ( this.settings.shouldTogglePosition ) {
                        this.el.css({left:0});
                    }
                    if ( this.settings.shouldToggleVisibility ) {
                        this.el.show();
                    }
                } else {
                    if ( this.settings.shouldTogglePosition ) {
                        this.el.css({left:-$('body').width()});
                    }
                    if ( this.settings.shouldToggleVisibility ) {
                        this.el.hide();
                    }
                }
            }
            this._super();
        }
    });
    
    return Pause;
});
