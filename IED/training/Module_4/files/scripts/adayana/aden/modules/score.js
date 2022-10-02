define(function(require){
    // dependencies
    var $     = require('jquery'),
        _     = require('lodash'),
        debug = require('adayana/debug/debug'),
        aden  = require('adayana/aden/engine');

    var score = aden.score = aden.score || {};
        
    /**
     * Tracks whether score should be reset between levels.
     * @private 
     */
    var _resetBetweenLevels = true;
    
    var scoreObj = {};
    
    /**
     * Initializes the Score module
     */
    score.initialize = function(mediator) {
        this.mediator = mediator;
        this.mediator.subscribe('msg:engine:init',   this.onInit,     null, this );
        this.mediator.subscribe('msg:engine:load',   this.onLoad,     null, this );
        this.mediator.subscribe('msg:engine:reset',  this.onReset,    null, this );
        this.mediator.subscribe('msg:state:save',    this.onSaveData, null, this );
        this.mediator.subscribe('msg:state:load',    this.onLoadData, null, this );
    },
    
    score.onSaveData = function( saveData ) {
        // if ( 'score' in saveData ) {
            // throw('Error creating save data: score.js');
        // }
        // saveData['score'] = $.extend(true,{},scoreObj);
    };
    
    score.onLoadData = function( saveData ) {
        // if ( 'score' in saveData ) {
            // scoreObj = $.extend(true,{},saveData['score']);
        // }
    };
    
    /**
     * Handles the engine initialization event. 
     */
    score.onInit = function( data ) {
        // get settings
        var settings = data.settings.modules.score;
        _resetBetweenLevels = settings.resetBetweenLevels;
        // set initial shared parameters
        scoreObj = {
            params: {},
            total: 0
        };
        debug.info('Score Module is ready');
    };
    
    /**
     * Handles the engine level load event. 
     */
    score.onLoad = function( levelData ) {
        if ( _resetBetweenLevels ) {
            scoreObj.params = {};
            scoreObj.total  = 0;
        }
        
        // FUTURE - when not resetting between levels, need to check for when level data had a duplicate parameter definition
        
        // for every parameter in the settings
        var settings = levelData.state.modules.score;
        for ( var key in settings ) {
            if ( settings.hasOwnProperty(key) ) {
                scoreObj.params[key] = settings[key];
                scoreObj.total += settings[key];
            }
        }
    };
    
    /**
     * Handles the engine reload event. Reloads the Score data.
     */
    score.onReset = function() {
        //TODO
    };
    
    /**
     * Adds a value to a scoring parameter
     */
    score.add = function(key, value) {
        if ( key in scoreObj.params ) {
            scoreObj.params[key] += value;
            scoreObj.total += value;
        }
    };
    
    /**
     * retrieves a score parameter by name
     */
    score.get = function(key) {
        return scoreObj.params[key];
    };
    
    /**
     * returns the total score
     */
    score.getTotal = function() {
        return scoreObj.total;
    };
    
    /**
     * returns an array of all the keys in the score object
     */
    score.getKeys = function() {
        var keys = [];
        for ( var key in scoreObj.params ) {
            if(scoreObj.params.hasOwnProperty(key)){
                keys[keys.length] = key;
            }
        }
        return keys;
    };
    
});
