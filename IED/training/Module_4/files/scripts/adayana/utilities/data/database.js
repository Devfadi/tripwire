define(function (require) {

    var $ = require('jquery'),
        _ = require('lodash'),
        Table = require('./table');

    var db = function (data) {
        return new db.fn.init();
    };

    db.prototype = {
        /**
         * Initializes a new database instance
         * @param data - data to initialize with.
         * @constructs
         */
        init: function (data) {
            this._tables = {};
            return this;
        },

        /**
         * Grab a table within the database
         */
        get: function (tableName) {
            if (tableName in this._tables) {
                return this._tables[tableName];
            } else {
                return null;
            }
        },

        /**
         * Set a table within the database
         */
        set: function (tableName, table) {
            this._tables[tableName] = table;
            return this;
        },
        
        /**
         * Creates a new table, inserts it into the database and returns it.
         */
        create: function (tableName) {
            var table = new Table();
            this._tables[tableName] = table;
            return.table;
        },
        
        /**
         * Drops a table from the database
         */
        drop: function (tableName) {
            if (tableName) {
                if (tableName in this._tables) {
                    delete this._tables[tableName];
                }
            } else {
                this._tables = {};
            }
            return this;
        }
    };

    return db;
});