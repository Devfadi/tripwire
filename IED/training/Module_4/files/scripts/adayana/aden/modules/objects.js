define(function (require) {
	'use strict';
	
    var $ = require('jquery'),
        _ = require('lodash'),
        debug = require('adayana/debug/debug'),
        aden = require('adayana/aden/engine'),
        AdvEvent = require('adayana/aden/internal/advEvent');

    require('adayana/aden/modules/objectFactory');

    var objects = aden.objects = aden.objects || {};

    var _resetsOnLoad = true;

    var _objects = {};

    /**
     * Configures the module to its initial state
     */
    objects.initialize = function (mediator) {
        // object event handler proxy
        this.onObjectEvent = $.proxy(this.onObjectEvent, this);

        // subscribe to channels
        this.mediator = mediator;
        this.mediator.subscribe('msg:engine:init', this.onInit, null, this);
        this.mediator.subscribe('msg:engine:load', this.onLoad, null, this);
        this.mediator.subscribe('msg:engine:reset', this.onReset, null, this);
        this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
        this.mediator.subscribe('msg:state:save', this.onSaveData, null, this);
        this.mediator.subscribe('msg:state:load', this.onLoadData, null, this);
        this.mediator.subscribe('trigger:object:load', this.load, null, this);
    };

    objects.onSaveData = function (saveData) {
        // if ( 'objects' in saveData ) {
        // throw ('Error creating save data: objects.js');
        // }
        // saveData['objects'] = [];
        // _.forEach( _objects, function( obj ){
        // saveData['objects'].push(obj.id);
        // });
        //TODO - create a save state for any objects that need it.
    };

    objects.onLoadData = function (saveData) {
        // if ( 'objects' in saveData ) {
        // _.forEach( saveData['objects'], function( key, index ) {
        // this.load(key);
        // },this);
        // }
        //TODO - reinstate each object's saved state
    };

    /**
     * Configures the module to a saved state
     */
    objects.onReset = function () {};

    objects.onResume = function () {};

    objects.onInit = function (data) {
        // init current objects object
        _objects = [];

        _resetsOnLoad = data.settings.modules.objects.resetsOnLoad;

        debug.info('Objects Module is ready');
    };

    objects.onLoad = function (levelData) {
        var reset = !!levelData.resetObjects;
        if (_resetsOnLoad || reset) {
            this.clear();
        }
        this.fsm = levelData.fsm;
        // grab new array of objects
        this.objects = levelData.objects;
    };

    objects.getData = function (id) {
        var objData = null;
        _.forEach(this.objects, function (data) {
            if (data.id === id) {
                objData = data;
            }
        });
        return objData;
    };

    /**
     * load the object with the specified id
     * @param {Object} id
     */
    objects.load = function (id, autoStart) {
		autoStart = autoStart !== false;
		
        // TODO - this is very very inefficient code. this sucks!

        var objData = this.getData(id);

        if (objData !== null) {
            // create obj
            var obj = aden.factory.create(objData);
            // listen for destroy
            obj.addEventListener(AdvEvent.OBJECT_DESTROY, this.onObjectEvent);
            obj.addEventListener(AdvEvent.OBJECT_START, this.onObjectEvent);
			if (autoStart) {
				// start object
				obj.start();
			}
            // track object 
            _objects.push(obj);
            return obj;
        } else {
            return null;
        }
    };

    /**
     * Remove the object with the specified id
     * @param {Object} id
     */
    objects.remove = function (id) {
        var index = this.getIndexById(id);
        this.removeObjectAt(index);
    };

    objects.removeObject = function (obj) {
        var index = this.getIndex(obj);
        this.removeObjectAt(index);
    };

    objects.removeObjectAt = function (index) {
        if (index > -1) {
            var objList = _objects.splice(index, 1);
            var obj = objList[0];
            obj.removeEventListener(AdvEvent.OBJECT_DESTROY, this.onObjectEvent);
            if (!obj.isDestroyed) {
                obj.destroy();
            }
        }
    };

    /**
     * Clear all objects
     */
    objects.clear = function () {
        _.forEach(_objects, function (obj) {
            obj.destroy();
        });
        _objects = [];
    };

    /***
     * Grab an object by id
     * @param {Object} id
     */
    objects.get = function (id) {
        var obj,
            i = 0,
            len = _objects.length;

        for (i; i < len; i++) {
            obj = _objects[i];
            if (obj.id === id) {
                return obj;
            }
        }
        return null;
    };

    /**
     * Grab an object by its index
     * @param {Object} obj
     */
    objects.getIndex = function (obj) {
        var i = 0,
            len = _objects.length;

        for (i; i < len; i++) {
            if (obj === _objects[i]) {
                return i;
            }
        }

        return -1;
    };

    /**
     * Grab the index of the object that matches the given id
     * @param {Object} id
     */
    objects.getIndexById = function (id) {
        var obj,
            i = 0,
            len = _objects.length;

        for (i; i < len; i++) {
            obj = _objects[i];
            if (obj.id === id) {
                return i;
            }
        }
        return -1;
    };

    objects.skip = function () {
        _.each(_objects, function (element) {
            if (element) {
                element.skip();
            }
        });
    };

    objects.onObjectEvent = function (e) {
        var obj = e.target;
        switch (e.type) {

            // When objects are destroyed
        case AdvEvent.OBJECT_DESTROY:
            // for every plugin, see if there's data to be passed
            _.forEach(obj.data.plugin, function (data, key) {
                if (key in aden.plugin && 'onObjectDestroy' in aden.plugin[key]) {
                    aden.plugin[key].onObjectDestroy(obj.id, data);
                }
            });
            this.removeObject(obj);
            break;

            // When objects are started
        case AdvEvent.OBJECT_START:
            // for every plugin, see if there's data to be passed
            _.forEach(obj.data.plugin, function (data, key) {
                if (key in aden.plugin && 'onObjectStart' in aden.plugin[key]) {
                    aden.plugin[key].onObjectStart(obj.id, data);
                }
            });
			break;
        }
    };

});