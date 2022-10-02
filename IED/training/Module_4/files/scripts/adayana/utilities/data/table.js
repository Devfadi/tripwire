/**
 * Defines a Table Object which houses data and provides functionality for access.
 */
define(function (require) {
    'use strict';
    
    var $ = require('jquery'),
        _ = require('lodash');
    
    var table = function(){
        this._data = {};
        this._order = {};
        this._order.default = [];
        this.currOrder = 'default';
    }
    
    table.prototype = {
        update: function( data ){
        
        },
        
        at: function( index, order ){
            order = (order) ? order : this.currOrder;
            return _.at(this._order[order], index);
        },
        
        get: function( key ) {
            if ( key && key in this._data ) {
                return this._data[key];
            }
            return null;
        },
        
        set: function( key, value ) {
            if ( key ) {
                this._data[key] = value;
            }
            return this;
        },
        
        has: function( key ) {
            return _.has(this._data,key);
        },
        
        contains: function( value ) {
            return _.contains(this._data,value);
        },
        
        keys: function(){
            return _.keys(this._data);
        },
        
        filter: function(){},
        reject: function(){},
        find: function(){},
        each: function(){},
        map: function(){},
        max: function(){},
        min: function(){},
        pluck: function(){},
        sample: function(){},
        shuffle: function(){},
        size: function(){},
        remove: function(){},
        insert: function(){},
        add: function(){},
        put: function( value ) {},
        order: function(){},
        each: function(){},
        first: function(){},
        last: function(){},
        indexOf: function(){},
        lastIndexOf: function(){},
        pull: function(){},
        range: function(){},
        reindex: function(){},
        getOrder: function( name ){},
        addOrder: function( name, updateFn ){},
        setOrder: function( name ){},
        dropOrder: function( name ) {}
    };
});