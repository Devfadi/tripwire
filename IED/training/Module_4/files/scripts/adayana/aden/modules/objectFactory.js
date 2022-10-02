define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        AdvObject = require('adayana/aden/objects/advObject');
        
    var factory = aden.factory = aden.factory || {};
    
    // PRIVATE Params-------------------------------------------------------------------------------
    
    /**
     * Contains constructors for nodes that this factory can produce
     * @name products
     * @inner
     */
    var products = {};
    
    // PUBLIC Methods ------------------------------------------------------------------------------
    
    factory.initialize = function(mediator) {
        // object event handler proxy
        onObjectEvent = $.proxy(this.objectEventHandler, this);
        
        // subscribe to channels
        this.mediator = mediator;
        this.mediator.subscribe('msg:engine:init', this.onInit, null, this);
    };
    
    factory.onInit = function( data ) {
        this.settings = data.settings.objects;
    };
    
    /**
     * Adds a new type of object to the factory
     */
    factory.addType = function( constructor ) {
        var type = constructor.prototype.type.toLowerCase();
        if ( type in products ) {
            throw ('Error: node type is already in use.');            
        } else { 
            products[type] = constructor;
        }
    };
    
    /**
     * Returns the settings object for a node type
     */
    factory.getSettings = function( type ) {
        return this.settings[type];
    };
    
    /**
     * Changes the settings for a node
     */
    factory.changeSetting = function( type, param, value ) {
        this.settings[type][param] = value;
    };
    
    /**
     * Creates a new adventure object
     */
    factory.create = function( data ) {
        // when object type exists
        if ( 'type' in data ) {
            // get constructor
            var type = data.type.toLowerCase();
            if ( type in products ) {
                return new products[type]( this.mediator, data, this.settings[type] );                
            }
            // Handle Unrecognized and Invalid Node Types:
            else {
                throw "Factory was unable to recognize the type of object requested";                
            }
        }
        else {
            // otherwise return an default object
            return new AdvObject(data);
        }
    };
    
});
