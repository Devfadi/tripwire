/**
 * A simple script intended to store data shared across multiple modules. 
 * @param {Object} root
 * @param {Object} factory
 */
( function(root, factory) {
    if ( typeof define === 'function' && define.amd) {
        // Register as an anonymous module (AMD).
        define([], function() {
            // Also create a global, just in case
            return (root.registry = factory());
        });
    } else {
        // Browser globals
        root.registry = factory();
    }
}(this, function() {
    registry = {};
    return registry;
})); 