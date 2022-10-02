/**
 * @fileOverview Contains a Module which defines an array search
 * @history 2012.10.03 ALP - Initial version.
 * @history 2013.08.09 VRB - Refactored search out of old shell code
 * @history 2013.09.10 VRB - Added isDOM Boolean to allow searching through DOM Elements
 */
define(['../sort/bubble','lodash'], function(bubbleSort,_) {

    /**
     * Search through a sorted array using divide and conquer. If the array is
     * not already sorted, the function can be triggered to sort it first.
     * @param {Array}   array    - array to seach
     * @param {String}  property - the property to search for within the array objects
     * @param {type}    value    - the value to match
     * @param {Boolean} sort     - Whether to first sort the array on the property being searched for.
     * @param {Boolean} isDOM    - Indicates the array holds DOM Elements and the property parameter indicates which attribute to check
     */
    function searchArray(array, property, value, sort, isDOM) {
        sort  = (_.isBoolean(sort)) ? sort : false;
        isDOM = (_.isBoolean(isDOM)) ? isDOM : false;
        if (sort) {
            bubbleSort(array, property, isDOM);
        }
        return searchHelper(array, property, value, 0, array.length - 1, isDOM);
    }

    /**
     * Divide & Conquer Search Helper Function
     * @param {type} array
     * @param {type} prop
     * @param {type} val
     * @param {type} start
     * @param {type} end
     * @param {Boolean} isDOM
     * @returns {unresolved}
     */
    function searchHelper(array, prop, targetValue, start, end, isDOM) {
        myLocation = Math.round((end + start) / 2);
        if (end < start) {
            return null;
        } else {
            var value;
            if (isDOM) {
                value = array[myLocation].getAttribute(prop);
            } else {
                value = array[myLocation][prop];
            }

            if (targetValue === value) {
                return myLocation;
            } else if (start === end) {
                return null;
            } else if (targetValue < value) {
                return searchHelper(array, prop, targetValue, start, myLocation - 1, isDOM);
            } else {
                return searchHelper(array, prop, targetValue, myLocation + 1, end, isDOM);
            }
        }
    }

    return searchArray;
});
