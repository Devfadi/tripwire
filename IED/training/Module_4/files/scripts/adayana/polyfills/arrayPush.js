/**
 * @file Polyfill for ancient browsers which do not support the Array's push method
 * @history 2007.02.04 JEM - Initial Version
 * @history 2013.07.19 VRB - Transposed code into AMD format
 */
define(function () {
    /**
     * Push a new element onto the end of an array
     * @returns {Number} New length of the array
     */
    if (Array.prototype.push === null) {
        Array.prototype.push = function(item) {
            this[this.length] = item;
            return this.length;
        };
    }
});