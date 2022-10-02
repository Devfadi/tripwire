define(function(require){
    
    var $     = require('jquery'),
        _     = require('lodash'),
        debug = require('adayana/debug/debug'),
        aden  = require('adayana/aden/engine');
        
    var save = aden.save = aden.save || {};
    
    var AUTOSAVE = "auto";
    
    save.initialize = function(mediator) {
        this.mediator = mediator;
    };
    
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
        $.jStorage.set( name + aden.version, saveData);
    };
    
    /**
     * Reload the engine's save state
     */
    save.getState = function( name ) {
        name = (name) ? name : AUTOSAVE;
        var saveData = $.jStorage.get(name + aden.version, "undefined");
        if ( saveData && saveData !== "undefined" ) {
            this.mediator.publish('msg:state:load', saveData);        
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
    
    return save;
});
