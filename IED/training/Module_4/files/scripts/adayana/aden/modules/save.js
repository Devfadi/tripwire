define(function (require) {
    'use strict';

    var $ = require('jquery'),
        _ = require('lodash'),
        SCORM = require('scorm'),
        Cookie = require('adayana/utilities/data/cookie'),
        debug = require('adayana/debug/debug'),
        aden = require('adayana/aden/engine'),
        user = require('adayana/aden/internal/user'),
        detect = require('adayana/utilities/detect');
    
    /*
    Notes on Storage Limitations...
    
    COOKIE LIMITS
    http://browsercookielimits.x64.me/
    we can approximate/assume 1 byte per character ( not always the case though )
    4096 byte limit ( some down to 4093 in practice )
    IE 6 + 7 (unpatched)   20 cookies
    IE 8+                  50 cookies
    Chrome 5-7             70 cookies
    Chrome 8+             180 cookies
    FF 3.6.13+            150 cookies
    
    20 * 4093 = 81,860 bytes
    
    Character Limits for LMS Suspend_Data:
    SCORM 1.2                4,096
    SCORM 2004 2nd Edition   4,000
    SCORM 2004 3rd Edition  64,000
    SCORM 2004 4th Edition  64,000
    
    Local Storage
    IE7 + IE6       128 kB
    FF & Chrome       5 MB
    IE8              10 MB
    
    WARNING: in some versions of IE, LocalStorage and UserData do not 
    persist between sessions if created by a local file
    
    */
    
    var save = aden.save = aden.save || {};

    var AUTOSAVE = "auto";

    var defaults = {
        autoSave: "auto",
        enableLMSStorage: true, // When enabled (true), Shell attempts to store save data into the LMS's suspend_data. default = true
        enableLocalStorage: true, // When enabled (true), LocalStorage API or Cookies will be available to store course progress data. default = true
        enableCookieStorage: true, // When enabled (true), cookies are used as a fallback solution when suspend_data and local storage are unavailable. default = false
        priority: [
            'scorm',
            'local',
            'cookies'
        ]
    };

    var scormObj;

    /**
     * Indicates the number of times the save module has attempted to load data
     */
    save.loadAttempt = -1;

    /**
     * Boolean indicating whether save data has been loaded
     */
    save.isLoaded = false;

    /**
     * Integer representing the maximum number of keys we can store.
     * This limit is imposed by browser cookies. For more information
     * see http://browsercookielimits.x64.me/
     */
    save.keyLimit = 20;

    /**
     * The current Number of keys stored
     */
    save.keyCount = 0;

    /**
     * Initialize the Save Module (when loaded)
     * @param {Mediator} mediator mediator object
     * @param {Object}   options  settings
     */
    save.initialize = function (mediator, options) {
        this.mediator = mediator;
        this.mediator.subscribe('msg:engine:init', this.onInit, null, this);
        this.settings = $.extend({}, defaults, options);
        this.loadAttempt = -1;
        this.isLoaded = false;
    };

    /**
     * Further initializes save module after engine is initialized and detect module checks have run.
     */
    save.onInit = function () {
        /* When running standalone/local on IE9 and IE10, fallback to 
           cookie storage. This is due to UserData and LocalStorage not 
           persisting between refreshes without a complicated change of 
           browser settings. */
        var ie = detect.getInternetExplorerVersion();
        if (ie >= 9 && detect.isStandalone && this.settings.enableLocalStorage) {
            this.settings.enableLocalStorage = false;
            this.settings.enableCookieStorage = true;
        }

        // Do not use LMS suspend data when running standalone or on a local server
        if (detect.isStandalone || detect.isLocalServer) {
            debug.log('not running on server - disabling LMS save feature');
            this.settings.enableLMSStorage = false;
        }

        // start the SCORM module
        if (this.settings.enableLMSStorage) {
            debug.log('creating SCORM Object');
            scormObj = new SCORM({
                version: '1.2',
                isPPS: false
            });
            scormObj.start();
            
            debug.log('scorm connected: ' + scormObj.isConnected);
        }

        // retrieve the user's name
        if (scormObj && scormObj.isConnected) {
            user.name = scormObj.user;
        } else {
            user.name = prompt('Enter your name:', "First Last");
        }
        
        // load saved data
        this.load();
    };

    /**
     * Retrieve all data stored in cookies
     * @returns {Object} Saved Data
     */
    function getAllCookiesHelper() {
        var data = {},
            arr = Cookie.index(),
            len = arr.length,
            i,
            key,
            str;

        for (i = 0; i < len; i++) {
            key = arr[i];
            str = Cookie.get(key);
            data[key] = JSON.parse(str);
        }

        return data;
    }

    /**
     * Save all data into cookies
     * @param {Object} data Save Data
     */
    function setAllCookiesHelper(data) {
        _.each(data, function (value, key, data) {
            Cookie.set(key, JSON.stringify(value));
        });
    }

    /**
     * Save all data into jStorage which uses LocalStorage and UserData.
     * @param {Object} data Save Data
     */
    function setAllLocalStorageHelper(data) {
        _.each(data, function (value, key, data) {
            $.jStorage.set(key, JSON.stringify(value));
        });
    }

    /**
     * Retrieve data stored in jStorage
     * @returns {Object} Saved Data
     */
    function getAllLocalStorageHelper() {
        var data = {},
            arr = $.jStorage.index(),
            len = arr.length,
            i,
            key,
            str;
        for (i = 0; i < len; i++) {
            key = arr[i];
            str = $.jStorage.get(key);
            data[key] = JSON.parse(str);
        }
        return data;
    }

    var loadNext;

    /**
     * Signal that the module is done loading saved data
     */
    function loadComplete() {
        save.data.version = aden.version;
        save.keyCount = _.keys(save.data).length;
        save.save();
        save.isLoaded = true;
        save.mediator.publish('msg:save:ready');
    }

    /**
     * Check if the loaded data contains data and matches the current version of the game
     */
    function loadCheck(str) {
        debug.log('received data string: ' + str);
        // if not empty and version matches, load data
        if (str !== null && typeof str !== 'undefined' && str !== "" && str !== "undefined" && str !== "null") {
            if (save.solution === "scorm") {
                save.data = JSON.parse(str);
                if (_.has(save.data, 'version') && save.data.version === aden.version) {
                    loadComplete();
                    return;
                }
            } else if (JSON.parse(str) === aden.version) {
                if (save.solution === 'local') {
                    save.data = getAllLocalStorageHelper();
                } else if (save.solution === 'cookie') {
                    save.data = getAllCookiesHelper();
                }
                loadComplete();
                return;
            }
            save.data = {};
        }
        
        // since the solution is empty or invalid (missing version information or version doesn't match)
        // clear it before trying the next
        switch (save.solution) {
        case 'scorm':
            if (save.settings.enableLMSStorage) {
                scormObj.setSuspendData('');
            }
            break;
        case 'local':
            if (save.settings.enableLocalStorage) {
                $.jStorage.flush();
            }
            break;
        case 'cookie':
            if (save.settings.enableCookieStorage) {
                Cookie.flush();
            }
            break;
        }
        
        // try next storage solution
        loadNext();
    }

    /**
     * Load data from the specified storage solution
     */
    function loadData() {
        var defer = $.Deferred();
        switch (save.solution) {
        case 'scorm':
            if (save.settings.enableLMSStorage) {
                scormObj.getSuspendData(function (str) {
                    defer.resolve(str);
                });
            } else {
                defer.resolve("");
            }
            break;
        case 'local':
            if (save.settings.enableLocalStorage) {
                defer.resolve($.jStorage.get('version', ''));
            } else {
                defer.resolve("");
            }
            break;
        case 'cookie':
            if (save.settings.enableCookieStorage) {
                defer.resolve(Cookie.get('version'));
            } else {
                defer.resolve("");
            }
            break;
        }
        defer.promise().done(loadCheck);
    }

    /**
     * Check the next available storage solution for saved data
     * @private
     */
    loadNext = function () {
        save.loadAttempt++;
        if (save.loadAttempt < save.settings.priority.length) {
            save.solution = save.settings.priority[save.loadAttempt].toLowerCase();
            debug.log('load attempt ' + save.loadAttempt + ' using solution: ' + save.solution);
            loadData();
        } else {
            save.solution = null;
            save.data = {};
            debug.log('load attempt ' + save.loadAttempt + ' - no save data found');
            loadComplete();
        }
    };

    /**
     * Loads all Saved Data from the first available and valid storage solution
     */
    save.load = function () {
        debug.log('starting data load');
        loadNext();
    };

    /**
     * Generate an array of keys in the saved data
     * @returns {Array} keys
     */
    save.keys = function () {
        return _.keys(this.data);
    };
    
    /**
     * Save all saved states into all available storage locations
     */
    save.save = function () {
        if (this.settings.enableLMSStorage) {
            scormObj.setSuspendData(JSON.stringify(this.data));
        }
        if (this.settings.enableLocalStorage) {
            setAllLocalStorageHelper(save.data);
        }
        if (this.settings.enableCookieStorage) {
            setAllCookiesHelper(save.data);
        }
    };

    /**
     * Save the engine's save state
     */
    save.setState = function (name) {
        // if name is not provided, create auto save
        name = name || AUTOSAVE;

        // when cookies are not enabled or the key count is below the limit
        if (!this.settings.enableCookieStorage || this.keyCount < this.keyLimit) {
            // retrieve save data from all components
            var saveData = {};
            this.mediator.publish('msg:state:save', saveData);

            // cache data
            this.data[name] = saveData;
            this.keyCount = _.keys(this.data).length;
            
            // store the save data
            if (this.settings.enableLMSStorage) {
                debug.log('saving suspend data');
                scormObj.setSuspendData(JSON.stringify(this.data));
                scormObj.save();
            }
            if (this.settings.enableLocalStorage) {
                $.jStorage.set(name, JSON.stringify(saveData));
            }
            if (this.settings.enableCookieStorage) {
                Cookie.set(name, JSON.stringify(saveData));
            }
        } else {
            alert('Warning! The save module has exceeded the key limit');
        }
    };

    /**
     * Retrieve a saved state
     */
    save.getState = function (name) {
        name = name || AUTOSAVE;
        if (_.has(this.data, name)) {
            this.mediator.publish('msg:state:load', this.data[name]);
        } else {
            this.mediator.publish('msg:state:load', null);
        }
    };

    /**
     * Determines if the given save state is recorded
     * @param   {String}  name save state name
     * @returns {Boolean} True when save state exists
     */
    save.hasState = function (name) {
        return _.has(this.data, name);
    };

    /**
     * Clear a specified save state
     * @param {String|Array} name optional save state name
     */
    save.clear = function (name) {
        if (name === null || typeof name === "undefined") {
            save.data = {};
            save.keyCount = 0;
            if (this.settings.enableLMSStorage) {
                scormObj.setSuspendData('');
            }
            if (this.settings.enableLocalStorage) {
                $.jStorage.flush();
            }
            if (this.settings.enableCookieStorage) {
                Cookie.flush();
            }
        } else if (_.isArray(name)) {
            _.each(name, save.flush);
        } else if (_.isString(name) && name !== "" && _.has(save.data, name)) {
            delete save.data[name];
            this.keyCount = _.keys(this.data).length;
            if (this.settings.enableLMSStorage) {
                scormObj.setSuspendData(JSON.stringify(save.data));
            }
            if (this.settings.enableLocalStorage) {
                $.jStorage.deleteKey(name);
            }
            if (this.settings.enableCookieStorage) {
                Cookie.remove(name);
            }
        }
    };
    
    save.recordCompletion = function () {
        if (scormObj && scormObj.isConnected) {
            scormObj.recordCompletion();
        }
    };
    
    return save;
});