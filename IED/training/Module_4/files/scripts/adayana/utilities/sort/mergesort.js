define(['lodash'],function(_) {
    var self = {};
    
    /**
     * Performs an in-place merge sort on an array
     *  Source : http://rosettacode.org/wiki/Sorting_algorithms/Merge_sort
     */
    self.mergeSort = function(arr) {
        mSort(arr, arr.slice(), arr.length);
    };
    
    /**
     * Peforms an in-place Merge Sort on an array of objects.
     * Uses the key parameter as the value to sort by.
     * @param arr  array to sort
     * @param key  parameter to use as the value to sort by
     */
    self.mergeSortObjArray = function( arr, key, fn ) {
        mSortObj(arr, arr.slice(), arr.length, key, fn );
    };
    
    //============================================================================================//
    // MERGE SORT PRIVATE FUNCTIONS:
    //============================================================================================//    
    
    /**
     * Recursive portion of object array merge sort.
     * Recursively splits object array into smaller arrays.
     * @param arr  array to sort
     * @param tmp  temporary array
     * @param len  length of arr
     * @param key  parameter to use to sort by
     * @Change 2012.08.24; VRB; modified length check to also check for lengths less than 1 (i.e. 0)
     */
    function mSortObj( arr, tmp, len, key, fn ) {
        // do not sort 0 or 1 objects
        if (len <= 1) {
            return;
        }
        // calculate midpoint and left & right sections
        var mid   = Math.floor(len / 2);
        var left  = tmp.slice(0, mid);
        var right = tmp.slice(mid);
        // sort left
        mSortObj(left, arr.slice(0, mid), mid, key, fn );
        // sort right
        mSortObj(right, arr.slice(mid), len - mid, key, fn );
        // merge
        mergeObj(left, right, arr, key, fn );
    }
    
    /**
     * Merge portion of object array merge sort.
     * @param left   left array
     * @param right  right array
     * @param arr    target array
     * @param key    value to sort by
     */
    function mergeObj( left, right, arr, key, fn ) {
        var a=0;
        var rValue,lValue;
        if ( fn !== undefined && fn !== null && _.isString(fn) ) {
            rValue = right[0][fn](key);
            lValue = left[0][fn](key);
        } else {
            rValue = right[0][key];
            lValue = left[0][key];
        }
        
        while( left.length && right.length ) {
            arr[a++] = ( rValue < lValue ) ? right.shift() : left.shift();            
        }
        while( left.length ) {
            arr[a++] = left.shift();            
        }
        while( right.length ) {
            arr[a++] = right.shift();            
        }
    }
    
    /**
     * performs merge sort
     * @param {Array} arr
     * @param {Array} tmp
     * @param {Number} l
     * @Change 2012.08.24; VRB; Modified length check to also check for length of 0
     */
    function mSort(arr, tmp, l) {
        if (l <= 1) {
            return;
        }
        
        var m = Math.floor(l / 2), 
            tmp_l = tmp.slice(0, m), 
            tmp_r = tmp.slice(m);
            
        mSort(tmp_l, arr.slice(0, m), m);
        mSort(tmp_r, arr.slice(m), l - m);
        
        merge(tmp_l, tmp_r, arr);
    }
    
    /**
     * merges left and right arrays
     */
    function merge(left, right, arr) {
        var a = 0;
        while (left.length && right.length){
            arr[a++] = right[0] < left[0] ? right.shift() : left.shift();}
        while (left.length){
            arr[a++] = left.shift();}
        while (right.length){
            arr[a++] = right.shift();}
    }
    
    return self;
});