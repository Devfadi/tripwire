define(function(require){
    var _S = {};
    
    /**
     * Pads a numerical value with a given number of digits.
     */
    _S.padDigits = function(n, totalDigits) {
        n = n.toString(); 
        var pd = ''; 
        if (totalDigits > n.length) { 
            for (i=0; i < (totalDigits-n.length); i++) { 
                pd += '0'; 
            } 
        } 
        return pd + n.toString(); 
    };
    
    /**
     * Parses a string for the number of seconds
     * Modified From .\Adobe Flash CS5.5\Common\Configuration\Component Source\ActionScript 3.0\FLVPlaybackCaptioning\fl\video\TimedTextManager.as
     * parse time in hh:mm:ss.s or mm:ss.s format.
     * Also accepts a bare number of seconds with
     * no colons.  Returns a number of seconds.
     * @name parseTime
     * @memberOf _S.prototype
     * @function
     */
    _S.parseTime = function( timeStr ) {
        var theTime, multiplier;
        
        // check for clock format or partial click format
        // HH:MM:SS.SS
        // MM:SS.SS
        var pattern = /^((\d+):)?(\d+):((\d+)(.\d+)?)$/;
        var results = pattern.exec(timeStr);
        if ( results !== undefined )
        {
            theTime = 0;
            theTime += ( parseFloat(results[2]) * 60 * 60 );
            theTime += ( parseFloat(results[3]) * 60 );
            theTime += ( parseFloat(results[4]));
            return theTime;
        }
        
        // check for offset time
        // 0h
        // 1000ms
        pattern = /^(\d+(.\d+)?)(h|m|s|ms)?$/;
        results = pattern.exec(timeStr);
        if ( results !== null )
        {
            switch ( results[3] ) {
                case "h"  : multiplier = 3600; break;
                case "m"  : multiplier = 60;   break;
                case "ms" : multiplier = 0.001; break;
                default   : multiplier = 1;
            }
            theTime = parseFloat(results[1]) * multiplier;
            return theTime;
        }
        
        theTime = parseFloat(timeStr);
        if ( isNaN(theTime) || theTime < 0 ){
            return NaN;
        }
        return theTime;
    };
    
    /**
     * convert milliseconds into a time string 
     */
    _S.convertTimeString = function( time ) {
        var h, m, s, ms;
        
        h = Math.floor( time / 3600000 );
        time = time % 3600000;
        
        
        m = Math.floor( time / 60000 );
        time = time % 60000;
        m = _S.padDigits(m,2);
        
        s = Math.floor( time / 1000 );
        time = time % 1000;
        s = _S.padDigits(s,2);
        
        ms = _S.padDigits(time, 3);
        
        return h + ":" + m + ":" + s + "." + ms;
    };
    
    /**
     * remove comments from JSON String
     * Source : http://james.padolsey.com/javascript/removing-comments-in-javascript/
     * This function is loosely based on the one found here:
     * http://www.weanswer.it/blog/optimize-css-javascript-remove-comments-php/
     */
    _S.removeComments = function(str) {
        str = ('__' + str + '__').split('');
        var mode = {
            singleQuote: false,
            doubleQuote: false,
            regex: false,
            blockComment: false,
            lineComment: false,
            condComp: false 
        };
        for (var i = 0, l = str.length; i < l; i++) {
     
            if (mode.regex) {
                if (str[i] === '/' && str[i-1] !== '\\') {
                    mode.regex = false;
                }
                continue;
            }
     
            if (mode.singleQuote) {
                if (str[i] === "'" && str[i-1] !== '\\') {
                    mode.singleQuote = false;
                }
                continue;
            }
     
            if (mode.doubleQuote) {
                if (str[i] === '"' && str[i-1] !== '\\') {
                    mode.doubleQuote = false;
                }
                continue;
            }
     
            if (mode.blockComment) {
                if (str[i] === '*' && str[i+1] === '/') {
                    str[i+1] = '';
                    mode.blockComment = false;
                }
                str[i] = '';
                continue;
            }
     
            if (mode.lineComment) {
                if (str[i+1] === '\n' || str[i+1] === '\r') {
                    mode.lineComment = false;
                }
                str[i] = '';
                continue;
            }
     
            if (mode.condComp) {
                if (str[i-2] === '@' && str[i-1] === '*' && str[i] === '/') {
                    mode.condComp = false;
                }
                continue;
            }
     
            mode.doubleQuote = str[i] === '"';
            mode.singleQuote = str[i] === "'";
     
            if (str[i] === '/') {
     
                if (str[i+1] === '*' && str[i+2] === '@') {
                    mode.condComp = true;
                    continue;
                }
                if (str[i+1] === '*') {
                    str[i] = '';
                    mode.blockComment = true;
                    continue;
                }
                if (str[i+1] === '/') {
                    str[i] = '';
                    mode.lineComment = true;
                    continue;
                }
                mode.regex = true;
     
            }
     
        }
        return str.join('').slice(2, -2);
    };
    
    /**
     * Returns a time string (HH:MM:SS) from a date object 
     * @param {Object} date
     * @param {Object} useMilitaryTime
     */
    _S.getTimeString = function( date, useMilitaryTime ) {
        if ( _.isDate(date) ) {
            if ( !_.isBoolean(useMilitaryTime) ) {
                useMilitaryTime = true;
            }
            var suffix;
            var hours = date.getHours();      
            if ( !useMilitaryTime ) 
            {
                suffix = ( Math.floor(hours/12) % 2 === 1 ) ? "pm" : "am";
                hours  = ( hours % 12 );
                if ( hours === 0 ) {hours = 12;}
            } 
            else 
            {
                suffix = "";
                hours = _S.padDigits(hours,2);
            }
            
            var minutes  = _S.padDigits(date.getMinutes(),2);
            var seconds  = _S.padDigits(date.getSeconds(),2);
            
            return hours + ":" + minutes + ":" + seconds;
        } 
        else {
            return 'XX:XX:XX';
        }
    };
    
    return _S;
});