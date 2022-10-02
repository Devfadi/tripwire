define(['lodash'],function(_) {
    /**
     * Use the Bubble Sorting Algorithm to sort through an array of elements
     * @param {Object} arrayToSort  - array to sort through
     * @param {Object} propToSortOn - property or attribute to use for sorting
     * @param {Object} isDOMElement - indicates whether array holds DOM Elements
     */
    function bubbleSort(arrayToSort, propToSortOn, isDOMElement ) {
        var dummy1, 
            dummy2, 
            myLength = arrayToSort.length;
            
        for (var i = 0; i < (myLength - 1); i++) {
            for (var j = i + 1; j < myLength; j++) {
                if ( isDOMElement ) {
                    dummy1 = arrayToSort[j].getAttribute( propToSortOn );
                    dummy2 = arrayToSort[i].getAttribute( propToSortOn );
                } else {
                    dummy1 = arrayToSort[j][propToSortOn];
                    dummy2 = arrayToSort[i][propToSortOn];
                }
                // Swap when dummy1 is less than dummy2
                if ( dummy1 < dummy2 ) {
                    dummy1 = arrayToSort[i];
                    arrayToSort[i] = arrayToSort[j];
                    arrayToSort[j] = dummy1;
                }
            }
        }
    }
    return bubbleSort;
});