// NOTE - RECOMMEND USING LODASH OR UNDERSCORE JS LIBRARIES
// Still this could have some use...

/**
 * @fileOverview A collection of function to identify the class and types of objects
 * @history 2013.06.13 VRB - Rewrote in AMD Format
 */
define(function() {
    /**
     * A Module for detecting an object's class-type
     * @module utilities/objectClass
     */
    var utility = {};

    /**
     * Determines if the Object is a member of the given Type. Way better than using the typeof operator,
     * which is completly broken. See: Http://bonsaiden.github.io/JavaScript-Garden/#types.typeof
     * Source: Javascript Garden
     */
    utility.is = function(type, obj) {
        var clas = Object.prototype.toString.call(obj).slice(8, -1);
        return obj !== undefined && obj !== null && clas === type;
    };

    // Below are a whole slew of shorthand methods for is();
    // As awesome as the function is, the syntax is strange.
    utility.isArray = function(obj) {
        return this.is('Array', obj);
    };
    utility.isBoolean = function(obj) {
        return this.is('Boolean', obj);
    };
    utility.isDate = function(obj) {
        return this.is('Date', obj);
    };
    utility.isError = function(obj) {
        return this.is('Error', obj);
    };
    utility.isFunction = function(obj) {
        return this.is('Function', obj);
    };
    utility.isNumber = function(obj) {
        return this.is('Number', obj);
    };
    utility.isObject = function(obj) {
        return this.is('Object', obj);
    };
    utility.isRegEx = function(obj) {
        return this.is('RegEx', obj);
    };
    utility.isString = function(obj) {
        return this.is('String', obj);
    };

    /**
     * Gets the class type of an object using toString
     */
    utility.getClass = function(obj) {
        return Object.prototype.toString.call(obj).slice(8, -1);
    };

    /**
     * Get Object Class
     * Source : http://blog.magnetiq.com/post/514962277/finding-out-class-names-of-javascript-objects
     */
    utility.getObjectClass = function(obj) {
        if (obj && obj.constructor && obj.constructor.toString) {
            var arr = obj.constructor.toString().match(
            /function\s*(\w+)/);

            if (arr && arr.length === 2) {
                return arr[1];
            }
        }
        return undefined;
    };

    return utility;
});
