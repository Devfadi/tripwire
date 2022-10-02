/**
 * @fileOverview Cookie Module
 * Reference: http://www.quirksmode.org/js/cookies.html
 * @history 2013.04.12 VRB - Added functions: index and flush. Also renamed other functions
 * @history 2013.08.09 VRB - AMD Shim
 */
define(function(){
    
    var cookie = {};
    
    /**
     * Creates or modifies a Cookie
     * @param {String} name - Name of the cookie to create
     * @param {String} value - String value to store in cookie
     * @param {Number} [days=365] - Number of days in which the cookie should expire. Defaults to 365 days.
     */
    cookie.set = function( name, value, days ) {
        // default value of 365 days or 1 year
        days = ( typeof(days) === "number" ) ? days : 365; 
        
        // construct expiration string
        var expires = "";
        if (days) {
            var date = new Date();
            date.setTime(date.getTime()+(days*24*60*60*1000));
            expires = "; expires="+date.toGMTString();
        }
        
        // set cookie
        document.cookie = name+"="+value+expires+"; path=/";
    };
    
    /**
     * Retrieves the value stored in a Cookie.
     * @param {String} name - the name of the cookie to grab
     * @returns {String} the string value saved inside the cookie
     */
    cookie.get = function(name) {
        var nameEQ = name + "=";
        var ca = document.cookie.split(';');
        for(var i=0;i < ca.length;i++) {
            var c = ca[i];
            while (c.charAt(0)===' ') {
                c = c.substring(1,c.length);
            }
            if (c.indexOf(nameEQ) === 0) {
                return c.substring(nameEQ.length,c.length);
            }
        }
        return null;
    };
    
    /**
     * Deletes a Cookie.
     * @param {String} name - the name of the cookie
     */
    cookie.remove = function(name) {
        this.set(name,"",-1);
    };
    
    /**
     * Deletes all cookies. 
     */
    cookie.flush = function() {
        var cookies = this.index();
        for ( var key in cookies ) {
            if ( cookies.hasOwnProperty(key) ) {
                this.remove(key);
            }
        }
    };
    
    /**
     * Retrieve an index of all available cookies
     * Reference: http://stackoverflow.com/questions/252665/i-need-to-get-all-the-cookies-from-the-browser
     * @returns {Array} An array of keys used for all cookies set on this domain
     */
    cookie.index = function() {
        var pairs = document.cookie.split(";");
        var cookies = {};
        for (var i = 0; i < pairs.length; i++) {
            var pair = pairs[i].split("=");
            cookies[pair[0]] = unescape(pair[1]);
        }
        return cookies;
    };

    return cookie;
});