define(function (require) {
    'use strict';
    
    // dependencies:
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        debug = require('adayana/debug/debug'),
        AdvVariable = require('adayana/aden/internal/advVariable');

    var variables = aden.variables = aden.variables || {};

    var _variables;

    variables.initialize = function (mediator) {
        this.mediator = mediator;
        this._subInit = this.mediator.subscribe('msg:engine:init', this.onInit, null, this);
        this._subLoad = this.mediator.subscribe('msg:engine:load', this.onLoad, null, this);
        this._subReset = this.mediator.subscribe('msg:engine:reset', this.onReset, null, this);
        this._subUpdate = this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);

        this.mediator.subscribe('msg:state:save', this.onSaveData, null, this);
        this.mediator.subscribe('msg:state:load', this.onLoadData, null, this);
        _variables = {};
    };

    variables.onSaveData = function (saveData) {
        saveData.variables = {};
        _.forEach(_variables, function (varObj, key) {
            saveData.variables[key] = varObj.get();
        });
    };

    variables.onLoadData = function (saveData) {
        if (saveData && typeof (saveData.variables) !== 'undefined') {
            _.forEach(saveData.variables, function (value, key) {
                _variables[key].set(value);
            }, this);
        }
    };

    variables.onInit = function (data) {
        // get module settings:
        this.settings = data.settings.modules.variables;
        // get module data:
        _.forEach(data.settings.variables, this.create, this);
    };

    variables.onLoad = function (levelData) {
        var data = levelData.variables;
        _.forEach(data, this.create, this);
    };

    variables.onUpdate = function () {
        _.forEach(_variables, function (variable) {
            variable.update();
        });
    };

    variables.onReset = function () {
        //TODO
    };

    /**
     * Retrieve variable by name
     * @param {Object} key
     */
    variables.get = function (key) {
        return _variables[key];
    };

    /**
     * Create a new variable
     * @param {Object} data
     */
    variables.create = function (data) {
        // when the data has not been set
        if (_variables && data && typeof _variables[data.name] === 'undefined') {
            _variables[data.name] = new AdvVariable(data);
            return _variables[data.name];
        }
        return null;
    };

    /**
     * Remove a variable
     */
    variables.remove = function (key) {
        // when the key is in use
        if (_variables && typeof _variables[key] !== "undefined") {
            delete _variables[key];
        }
    };

    return variables;
});