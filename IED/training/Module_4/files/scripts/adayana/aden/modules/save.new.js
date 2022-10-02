define(function(require){
    
    var $     = require('jquery'),
        _     = require('lodash'),
        debug = require('adayana/debug/debug'),
        aden  = require('adayana/aden/engine'),
        detect = require('adayana/utilities/detect');
    
    var save = aden.save = aden.save || {};
    
    var AUTOSAVE = "auto";
    
    var defaults = {
        autoSave : "auto",
        enableLMSStorage     : true,  // When enabled (true), Shell attempts to store save data into the LMS's suspend_data. default = true
        enableLocalStorage   : true,  // When enabled (true), LocalStorage API or Cookies will be available to store course progress data. default = true
        enableCookieStorage  : true,  // When enabled (true), cookies are used as a fallback solution when suspend_data and local storage are unavailable. default = false
        enableFlashFallback  : false, // When enabled (true), A Flash fallback solution is used to store data. default = false
        priority : [
            'scorm',
            'local',
            'cookies'
        ]
    };
    
    /**
     * Initialize the Save Module (when loaded)
     * @param {Mediator} mediator mediator object
     * @param {Object}   options  settings
     */
    save.initialize = function(mediator, options) {
        this.mediator = mediator;
        this.mediator.subscribe('msg:engine:init', this.onInit, null, this);
        this.settings = $.extend({},defaults,options);
    };
    
    /**
     * Further initializes save module after engine is initialized and detect module checks have run.
     */ 
    onInit: function () {
        // When running standalone/local on IE9 and IE10, fallback to cookie storage
        // This is due to UserData and LocalStorage not persisting between refreshes
        // without a complicated change of browser settings.
        // FUTURE Test local storage in IE 11 locally
        var ie = detect.getInternetExplorerVersion();
        if ( ie >= 9 && detect.isStandalone && this.settings.enableLocalStorage ) {
            this.settings.enableLocalStorage = false;
            this.settings.enableCookieStorage = true;
        }
        
        // Do not use LMS suspend data when running standalone or on a local server
        if ( detect.isStandalone || detect.isLocalServer ) {
            this.settings.enableLMSStorage = false;
        }
    };
    
    //TODO - use cookies if running local on IE.
    //TODO - plug into SCORM code
    
    /**
     * Save the engine's save state
     */
    save.setState = function( name ) {
        // if name is not provided, create auto save
        name = (name) ? name : AUTOSAVE;
        
        // retrieve save data from all components
        var saveData = {};
        this.mediator.publish('msg:state:save', saveData );
        
        // store the save data
        if ( this.settings.enableLocalStorage ) {
            $.jStorage.set( name + aden.version, saveData);
        }
        if ( this.settings.enableLMSStorage ) {
            var str = JSON.stringify(saveData);
            
        }
        
    };
    
    /**
     * Reload the engine's save state
     */
    save.getState = function( name ) {
        name = (name) ? name : AUTOSAVE;
        var saveData = $.jStorage.get(name + aden.version, "undefined");
        if ( saveData && saveData !== "undefined" ) {
            this.mediator.publish('msg:state:load',saveData);        
        }
    };
    
    save.hasState = function( name ) {
        return ( $.jStorage.get(name + aden.version,"undefined") !== "undefined" );
    };
    
    save.clear = function( name ) {
        name = (name) ? name : AUTOSAVE;
        $.jStorage.deleteKey( name + aden.version );
    };
    
    /**
     * Get a list of save states
     */
    save.getList = function() {
        return $.jStorage.index();
    };
    
    
    function _save( data ) {
        if ( save.settings.enableLMSStorage ) {
            
        }
    };
    
    function _load(  ) {
        
    };
    
    function _loadComplete() {
        
    };
    
    return save;
});
