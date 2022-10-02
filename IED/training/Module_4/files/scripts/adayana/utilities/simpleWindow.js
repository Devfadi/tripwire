define(function(require){    
    
    var $ = require('jquery');
    
    // false - do not add to configuration
    // 'yes' - enable
    // 'no'  - disable
    // 9999  - value
    // inspiration: https://developer.mozilla.org/en-US/docs/Web/API/window.open?redirectlocale=en-US&redirectslug=DOM%2Fwindow.open
    var defaults = {
        left         : false,
        top          : false,
        width        : 995,
        height       : 530,
        centerscreen : false,   // requires chrome=yes
        outerHeight  : false,
        outerWidth   : false,
        innerHeight  : false,
        innerWidth   : false,
        chrome       : false,
        scrollbars   : 'yes',   // show scrollbars?
        menubar      : 'no',    // show menubar
        toolbar      : 'no',    // show toolbar
        location     : 'no',    // show location bar
        personalbar  : 'no',    // show personalbar
        status       : 'no',    // show status bar
        resizable    : 'no',
        dependent    : 'yes',   // If on, the new window is said to be dependent of its parent window.
        dialog       : 'no',    // The dialog feature removes all icons (restore, minimize, maximize) from the window's titlebar, leaving only the close button.
        minimizable  : 'no'     // requires dialog=yes.
    };
    
    /**
     * Simplified Window Constructor
     * @constructor
     */
    var SimpleWindow = function( url, name, options ){
        this.settings = $.extend({}, defaults, options);
        var popupConfig = '';
        for ( var key in this.settings ) {
            if ( this.settings[key] ) {
                popupConfig += key + '=' + this.settings[key] + ', ';
            }
        }
        popupConfig += 'chrome=yes';
        this.reference = window.open( url, name, popupConfig );
        this.reference.focus();
    };
    
    SimpleWindow.prototype.focus = function(){
        if ( this.reference ) {
            this.reference.focus();
        }
    };
    
    SimpleWindow.prototype.close = function(){
        if ( this.reference ) {
            this.reference.close();
        }
    };
    
    return SimpleWindow;
    
});
