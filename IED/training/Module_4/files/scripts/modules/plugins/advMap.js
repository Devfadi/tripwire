define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvPlugin = require('adayana/aden/plugins/advPlugin');
    
    var events = [];
    var blast = 'blast1';
    
    var AdvRadio = AdvPlugin.extend(
    /** @lends AdvRadio.prototype */        
    {
        currTime: 0,
        isOpen: false,
        
        init: function( name, mediator, data ) {
            this._super(name, mediator,data);
            this.mapTemplate = Templates.getTemplate(data.mapSource);
            this.iconTemplate = Templates.getTemplate(data.iconSource);
            this.onMapToggle = $.proxy(this.onMapToggle, this);
            this.onBlastClick = $.proxy(this.onBlastClick, this);
        },
        
        onInit: function( instance ) {     
            this.mapEl = $('<div id="map-view" class="map-view layer"></div>');
            this.mapEl.appendTo( aden.el );
            this.mapEl.hide();
            
            this.iconEl = $('<div id="map-icon" class="map-icon layer"><div style="color: rgb(0, 0, 0); position: absolute; font-size: 50px; font-weight: bold; bottom: 50px; right: 34px;">MAP</div></div>');
            this.iconEl.appendTo( aden.el );
            //this.iconEl.html(this.iconTemplate(null));
            this.iconEl.on('click',this.onMapToggle);
            
            debug.info('Radio module is ready');
        },
        
        /**
         * initialize trackers when level data loads 
         * @param {Object} levelData
         */
        onLoad: function( levelData ) {
            if ( 'plugin' in levelData && this.name in levelData.plugin ) {
                var pluginData = levelData.plugin[this.name];
                
                // empty the previous map contents
                this.mapEl.empty();
                
                // generate map and zones
                var data = $.extend(true,{},pluginData);
                _.each(data.zone,function(zone){
                    zone.tag_inner = zone.inner + " ft.";
                    zone.tag_outer = zone.outer + " ft.";                    
                    zone.zone_dead_r = ( zone.inner / data.scale );
                    zone.zone_warn_r = ( zone.outer / data.scale );
                    zone.zone_safe_r = zone.zone_warn_r * 1.2;                    
                    zone.zone_dead_d = zone.zone_dead_r * 2;
                    zone.zone_warn_d = zone.zone_warn_r * 2;
                    zone.zone_safe_d = zone.zone_safe_r * 2;
                });
                this.mapEl.html(this.mapTemplate(data));
                
                // configure close button
                this.mapEl.find('.map-close').on('click',this.onMapToggle);
                
                // configure blast button to select viewabel zones
                this.blastButtons = this.mapEl.find('.blast-btn');
                this.blastButtons.click(this.onBlastClick);
                
                // display the appropriate zone
                this.mapEl.find('.blast').hide();
                this.mapEl.find('[data-blast-id="' + blast + '"]').addClass('active');
                this.mapEl.find('#'+blast).show();
            }
        },
        
        setFSM: function( fsm ) {
            this.fsm = fsm;
        },
        
        setEventName: function( eventName ) {
            this.eventName = eventName;
        },
        
        onBlastClick: function(e){
            var id = $(e.target).attr('data-blast-id');
            
            // hide old blast image
            $('#' + blast).hide();
            this.mapEl.find('[data-blast-id="' + blast + '"]').removeClass('active');
            
            // show new blast iamge
            $('#' + id).show();
            $(e.target).addClass('active');
            blast = id;
            
            e.stopPropagation();
            return false;
        },
        
        onMapToggle: function(){
            if ( this.isActive ){
                this.mapEl.toggle();
                if ( this.isOpen ) {
                    this.isOpen = false;
                    aden.mediator.publish('msg:engine:resume');
                } else {
                    this.isOpen = true;
                    aden.mediator.publish('msg:engine:pause');
                }
            } else {
                debug.log('map inactive');
            }
        },
        
        open: function(){
            if( !this.isOpen ) {
                this.mapEl.toggle();
                this.isOpen = true;
                aden.mediator.publish('msg:engine:pause');
            }
        },
        
        close: function(){
            if ( this.isOpen ) {
                this.mapEl.toggle();
                this.isOpen = false;
                aden.mediator.publish('msg:engine:resume');
            }            
        }
    });
    
    return AdvRadio;
});