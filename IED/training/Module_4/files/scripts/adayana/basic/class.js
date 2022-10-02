/**
 * @file <p>Simple JavaScript Inheritance</p>
 * <p>By John Resig http://ejohn.org/</p>
 * @license MIT
 */

/**
 * A module representing a Class Object
 * @module basic/class
 */
(function (root, factory) {
    // when RequireJS or another AMD implementation is available
    if (typeof define === 'function' && define.amd) {
        // use AMD. Register as an anonymous module.
        define(factory);
    } else {
        // use Browser globals
        root.Class = factory();
    }
}(this, function() { // factory (below) is exposed by wrapper (above)
    
    var initializing = false, 
        fnTest = /xyz/.test(function() { xyz; }) ? /\b_super\b/ : /.*/;
        
    // fnTest -- utilizes a technique called function decompilation, also known 
    // as function serialization. if the serialization of the anonymous 
    // function contains xyz, we can easily test to see if class methods
    // contain references to their _super method. Otherwise .* pattern is used,
    // which always returns true, and every class method will require the
    // _super method handling below (older browsers).
    
    /**
     * @constructor
     * @alias module:utilities/class 
     */
    var Class = function() {};

    /**
     * Create a new Class that inherits from this class
     * @static 
     * @param {Object} prop
     */
    Class.extend = function(prop) {
        var _super = this.prototype;

        // Instantiate a base class (but only create the instance,
        // don't run the init constructor)
        initializing = true;
        var prototype = new this();
        initializing = false;

        // Copy the properties over onto the new prototype
        for (var name in prop) {
            // Check if we're overwriting an existing function
            // Also, in new browsers, check if the new method refers to _super
            // if it doesn't we can safely overwrite it.
            prototype[name] = typeof prop[name] === "function" && typeof _super[name] === "function" && fnTest.test(prop[name]) ? (function(name, fn) {
                return function() {
                    // create reference to 'prototype' super
                    var tmp = this._super;
                    // Add a new ._super() method that is the same method
                    // but on the super-class
                    this._super = _super[name];
                    // The method only need to be bound temporarily, so we
                    // remove it when we're done executing
                    var ret = fn.apply(this, arguments);
                    // restore 'prototype' super
                    this._super = tmp;
                    // return new function
                    return ret;
                };
            })(name, prop[name]) : prop[name];
        }

        // The dummy class constructor
        function Class() {
            // All construction is actually done in the init method
            if (!initializing && this.init){
                this.init.apply(this, arguments);
            }
        }

        // Populate our constructed prototype object
        Class.prototype = prototype;

        // Enforce the constructor to be what we expect
        Class.prototype.constructor = Class;

        // And make this class extendable
        Class.extend = arguments.callee;

        return Class;
    };
    
    return Class;
}));

