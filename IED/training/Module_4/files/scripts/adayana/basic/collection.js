/**
 * @module adayana/utilities/collection 
 */
define(['jquery'], function ($) {
    /**
     * @constructor
     * @alias module:adayana/utilities/collection 
     */
    var collection = function () {
        this._byKey = {};
        this._byIndex = [];
        this.length = 0;
    };

    collection.prototype = {
        /**
         * Object which houses the collection's stuff 
         */
        _byKey: null,
        /**
         * Array which houses the collection's stuff 
         */
        _byIndex: null,
        /**
         * Number of items within the collection 
         */
        length: 0,
        
        /**
         * Adds an item to the collection 
         * @param {Object} key
         * @param {Object} item
         */
        add: function (key, item) {
            this._byIndex.push(item);
            this._byKey[key] = item;
            this.length = this._byIndex.length;
        },
        
        /**
         * Adds an item at a particular index
         * @param {Object} key
         * @param {Object} item
         */
        addAt: function (key, item, index) {
            this._byKey[key] = item;

            this.length = this._byIndex.length;
        },
        
        /**
         * Retrieve an item by its key  
         * @param {Object} key
         */
        get: function (key) {
            if (key in this._byKey) {
                return this._byKey[key];
            } else {
                console.log('item with key of ' + key + ' is not housed within this collection');
                return undefined;
            }
        },
        
        /**
         * Retrieve an item by its index
         * @param {Object} index
         */
        getByIndex: function (index) {
            if (index >= 0 && index < this._byIndex.length) {
                return this._byIndex[index];
            } else {
                console.log('invalid index');
                return undefined;
            }
        },
        
        /**
         * Remove the item with the matching key 
         * @param {Object} key
         */
        remove: function (key) {
            if (key in this._byKey) {
                var item = this._byKey[key];
                var i = this._byIndex.indexOf(item);
                this._byIndex.splice(i, 1);
                delete this._byKey[key];
                this.length = this._byIndex.length;
            }
        },
        
        /**
         * Iterate over all the items in the collection 
         * @param {Object} callback
         */
        each: function (callback) {
            for (var i = 0; i < this.length; i++) {
                callback(this._byIndex[i]);
            }
        },
        
        /**
         * Determine if a key is in use
         */
        has: function( key ) {
            return ( this.getIndex(key) > -1 );
        },
        
        /**
         * retrieve the index of a key value 
         */
        getIndex: function (key) {
            return this.indexOf(key);
        },
        
        /**
         * retrieve the index of a key value 
         */
        indexOf: function (key) {
            return this._byIndex.indexOf(this._byKey[key]);
        },
        
        /**
         * set the index of the item with the following key 
         * @param {Object} key
         * @param {Object} index
         */
        setIndex: function (key, index) {
            var i = this.indexOf(key);
            if (i > -1) {
                var items = this._byIndex.splice(i, 1);
                this._byIndex.splice(index, 0, items[0]);
            }
        },
        
        /**
         * find all objects that match
         * @param {Object} property
         * @param {Object} value
         */
        find: function( property, value ) {
            //TODO : Implement this
        }
    };

    return collection;
});
