define(['lodash'],function(_) {
    // http://www.nczonline.net/blog/2012/11/27/computer-science-in-javascript-quicksort
    
    var self = {};
    
    /**
     * In Place QuickSort Method for an Array 
     * @param {Object} arr
     */
    self.quickSort = function( arr ) {
        arr = quickSort( arr, 0, arr.length - 1 );
    };
    
    /**
     * In Place QuickSort Method for an array of Objects 
     * @param {Object} arr
     * @param {Object} key
     */
    self.quickSortObjArray = function( arr, key ) {
        arr = quickSortObj( arr, 0, arr.length - 1, key );
    };
    
    /**
     * Swaps two values in an array 
     * @param {Object} arr
     * @param {Object} first
     * @param {Object} second
     */
    function swap( arr, first, second ) {
        var temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
    
    /**
     * Partition method for use in quick sort algorithm 
     * @param {Object} items
     * @param {Object} left
     * @param {Object} right
     */
    function partition(items, left, right) {
        var pivot = items[Math.floor((right + left) / 2)],
            i     = left,
            j     = right;
        while (i <= j) {
            while (items[i] < pivot) {
                i++;
            }
            while (items[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(items, i, j);
                i++;
                j--;
            }
        }
        return i;
    }
    
    /**
     * Partition method used to quicksort an array of objects 
     * @param {Object} items
     * @param {Object} left
     * @param {Object} right
     * @param {Object} key
     */
    function partitionObj( items, left, right, key ) {
        var pivot = items[Math.floor((right + left) / 2)][key],
            i     = left,
            j     = right;
            
        while (i <= j) {
            // while items on left are less than pivot value
            while (items[i][key] < pivot) {
                i++;
            }
            // while items on right are greater than pivot value
            while (items[j][key] > pivot) {
                j--;
            }
            // perform swaps
            if (i <= j) {
                swap(items, i, j);
                i++;
                j--;
            }
        }
        return i;
    }
    
    /**
     * QuickSort an Array 
     * @param {Object} items
     * @param {Object} left
     * @param {Object} right
     */
    function quickSort(items, left, right) {
        var index;
        if (items.length > 1) {
            index = partition(items, left, right);
            if (left < index - 1) {
                quickSort(items, left, index - 1);
            }
            if (index < right) {
                quickSort(items, index, right);
            }
        }
        return items;
    }
    
    /**
     * Quick Sort an array of objects 
     * @param {Object} items
     * @param {Object} left
     * @param {Object} right
     * @param {Object} key
     */
    function quickSortObj( items, left, right, key ) {
        var index;
        if (items.length > 1) {
            index = partitionObj(items, left, right, key);
            if (left < index - 1) {
                quickSortObj(items, left, index - 1, key);
            }
            if (index < right) {
                quickSortObj(items, index, right, key);
            }
        }
        return items;
    }
    
    return self;
});