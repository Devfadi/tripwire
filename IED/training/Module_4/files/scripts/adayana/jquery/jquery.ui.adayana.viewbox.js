/**
 * This module contains a jQuery UI Widget for a dynamically resizing Viewbox,
 * it keeps the outer dimensions of the target element sized within its parent
 * element or within the browser's viewport
 * @history 2013.09.11 VRB - Initial Version
 */
define(["jquery", "jqueryui"], function ($) {
    
    //TODO - add support for percentages
    //TODO - add support for em
    
    $.widget( "ada.viewbox", {

        /**
         * Options to be used as defaults 
         */
        options: {
            width        : 100,   // this is the initial width
            height       : 100,   // initial height 
            minWidth     : false, // minimum width
            maxWidth     : false, // maximum width
            minHeight    : false, // minimum height
            maxHeight    : false, // maximum height
            gutterTop    : 0,     // spacing above element, past any margin, padding, or border
            gutterLeft   : 0,     // spacing to left of element, past any margin, padding, or border
            gutterBottom : 0,     // spacing below element, past any margin, padding, or border
            gutterRight  : 0,     // spacing to right of element, past any margin, padding, or border
            parent       : false, // if set, fill innerHeight. otherwise fill browser viewport
            alsoResize   : false  // if set, contains an array of elements to resize after this element resizes.
        },
        
        /**
         * Elements current width 
         */
        _currWidth: 0,
        
        /**
         * Elements current height 
         */
        _currHeight: 0,
        
        // Set up widget (e.g. create element, apply theming,
        // bind events, etc.)
        _create: function () {
            // _create will automatically run the first time
            // this widget is called. Put the initial widget
            // set-up code here, then you can access the element
            // on which the widget was called via this.element.
            // The options defined above can be accessed via
            // this.options
            
            this.element.addClass( 'ui-adayana-viewbox' );
            
            if ( this.options.parent ) {
                // fill inner dimensions of parent element
                this.options.parent = $(this.options.parent);
            } else {
                // fill the browser viewport
                
            }
            
            this.resize();
        },

        // Destroy an instantiated plugin and clean up modifications
        // that the widget has made to the DOM
        destroy: function () {
            // this.element.removeStuff();
            // For UI 1.8, destroy must be invoked from the base
            // widget
            $.Widget.prototype.destroy.call( this );
            // For UI 1.9, define _destroy instead and don't worry
            // about calling the base widget
        },
        
        /**
         * Resize the viewbox 
         */
        resize: function(){
            // calculate available space
            var availableWidth;
            var availableHeight;
            // when there is a parent
            if ( this.options.parent !== false ) {
                availableHeight = this.options.parent.height();
                availableWidth  = this.options.parent.width();
            } 
            // otherwise use viewport
            else {
                // first method is a lot faster than using jQuery
                if (document.documentElement && document.documentElement.clientWidth) {
                    availableWidth = document.documentElement.clientWidth;
                } else {
                    availableWidth = $(window).innerWidth();
                }
                if ( document.documentElement && document.documentElement.clientHeight ) {
                    availableHeight = document.documentElement.clientHeight;
                } else {
                    availableHeight = $(window).innerHeight();
                }
            }
            
            
            this._resizeHeight( availableHeight );
            this._resizeWidth( availableWidth );
                        
            if ( this.options.alsoResize ) {
                //TODO - implement
            }
            this._trigger("resize");
        },
        
        /**
         * Resizes the width of the viewbox 
         */
        _resizeWidth: function( availableWidth ){
            // calculate how much the css padding, margin, and border properties add to the width
            var cssModifiers = this.element.outerWidth() - this.element.width();
            availableWidth = availableWidth - this.options.gutterRight - this.options.gutterLeft;
            // resize
            this._resize( 'width', this._currWidth, availableWidth, this.options.maxWidth, this.options.minWidth, cssModifiers );
            this._currWidth  = this.element.outerWidth();
            this._trigger("resizeWidth");
        },
        
        /**
         * Resizes the height of the viewbox 
         */
        _resizeHeight: function( availableHeight ){
            // calculate how much the css padding, margin, and border properties add to the height
            var cssModifiers = this.element.outerHeight() - this.element.height();
            // calculate the outerheight of all siblings of the viewbox element
            var siblingHeight = 0;
            if ( this.options.parent !== false ) {
                this.element.siblings().each(function(){
                    siblingHeight += $(this).outerHeight();
                });
            }
            var modifier = cssModifiers + siblingHeight;
            
            availableHeight = availableHeight - this.options.gutterTop - this.options.gutterBottom;
            // resize
            this._resize( 'height', this._currHeight, availableHeight, this.options.maxHeight, this.options.minHeight, modifier );
            this._currHeight = this.element.outerHeight();
            this._trigger("resizeHeight");
        },
        
        /**
         * resize the height/width of the viewbox 
         */
        _resize: function( prop, curr, avail, max, min, modifier ) {
            // by default, fill the available space
            var value = avail;
            // check limits
            // if there's a maximum value, and there's more available space than that value
            if ( max && avail > max ) {
                value = max;
            } 
            // if there's a minimum value, and there's less available space
            else if ( min && avail < min ) {
                value = min;
            } 
            // set property
            this.element[prop]( value - modifier );
        },
       
        //Respond to any changes the user makes to the option method
        _setOption: function ( key, value ) {
            switch (key) {
                case "height":
                case "width":
                case "maxHeight":
                case "minHeight":
                case "maxWidth":
                case "minWidth":
                    this.options[ key ] = value;
                    this.resize();
                    break;
                default:
                    this.options[ key ] = value;
                    break;
            }
            
            // For UI 1.8, _setOption must be manually invoked from
            // the base widget
            // $.Widget.prototype._setOption.apply( this, arguments );
            // For UI 1.9 the _super method can be used instead
            this._super( "_setOption", key, value );
        }
        
    });
    
    // extend the widget's prototype...
    // $.extend( $.ada.Viewbox.prototype, {} );
});