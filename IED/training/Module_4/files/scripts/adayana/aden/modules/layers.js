define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        debug = require('adayana/debug/debug');
        
    var layers = aden.layers = aden.layers || {};
    
    var _layers;
    var _order;
    
    /**
     * Configure layers Module to its initial state
     * @constructs
     */
    layers.initialize = function(mediator) {
        _layers = {};
        _order = [];
        this.mediator = mediator;
        this.mediator.subscribe('msg:engine:init',   this.onInit, null, this );
        this.mediator.subscribe('msg:engine:load',   this.onLoad, null, this );
        this.mediator.subscribe('msg:engine:reset',  this.onReset, null, this );
        this.mediator.subscribe('trigger:engine:layer:add', this.add, null, this );
        this.mediator.subscribe('trigger:engine:layer:remove', this.remove, null, this);
        this.mediator.subscribe('trigger:engine:layer:sendToTop', this.sendToTop, null, this);
        this.mediator.subscribe('trigger:engine:layer:sendToBottom', this.sendToBottom, null, this);
        this.mediator.subscribe('trigger:engine:layer:sendAbove', this.sendAbove, null, this);
        this.mediator.subscribe('trigger:engine:layer:sendBelow', this.sendBelow, null, this);
        this.mediator.subscribe('trigger:engine:layer:update', this.update, null, this);        
    };
    
    /**
     * when engine initialized 
     */
    layers.onInit = function( data ) {
        _.forEach( data.settings.modules.layers.initial, function( id ){
            this.add(id);
        },this);
        debug.info('Layer Module is ready');
        this.update();
    };
    
    layers.onLoad = function( levelData ) {
        this.update();
    };
    
    layers.onReset = function() {
        
    };
    /**
     * Track a dom element as a layer 
     * @param {Object} id
     * @param {Object} template
     * @param {Object} data
     */
    layers.add = function( id, template, data ){
        // grab or create element
        var el = $('#' + id);
        // create layer data
        _layers[id] = {
            template: template,
            el: el
        };
        // set order, render, and update z-index
        _order.push(id);
        if ( template && data ) {
            this.render( id, data );
        }
        this.update();
    };
    /**
     * compile the template of a given layer 
     * @param {Object} id
     * @param {Object} data
     */
    layers.render = function( id, data ){
        var layer = _layers[id];
        if ( layer && layer.template ) {
            layer.el.html(layer.template(data));
        }
        this.update();
    };
    /**
     * Remove the identified layer
     * @param {Object} id
     * @param {Object} removeEl
     */
    layers.remove = function( id ){
        var layer = _layers[id];
        if ( layer ) {
            delete _layers[id];
            var index = _order.indexOf(id);
            _order.splice(index,1);
        }
        this.update();
    };
    /**
     * send layer to top of stack 
     */
    layers.sendToTop = function( id ) {
        var layer = _layers[id];
        if ( layer ) {
            var index = _order.indexOf(id);
            _order.splice(index,1);
            _order.push(id);
        }
        this.update();
    };
    /**
     * send layer to bottom of stack 
     */
    layers.sendToBottom = function( id ) {
        var layer = _layers[id];
        if ( layer ) {
            var index = _order.indexOf(id);
            _order.splice(index,1);
            _order.splice(0,0,id);
        }
        this.update();
    };
    /**
     * send layer above another. 
     */
    layers.sendAbove = function( layerId, targetId ) {
        var layer = _layers[layerId];
        if ( layer ) {
            var layerIndex  = _order.indexOf(layerId);
            if ( layerIndex !== -1 ) {
                _order.splice(layerIndex,1);
                var targetIndex = _order.indexOf(targetId);
                if ( targetIndex !== -1 ) {
                    _order.splice(targetIndex+1,0,layerId);
                }
            }
        }
        this.update();
    };
    /**
     * send layer below another 
     */
    layers.sendBelow = function( layerId, targetId ) {
        var layer = _layers[layerId];
        if ( layer ) {
            var layerIndex  = _order.indexOf(layerId);
            if ( layerIndex !== -1 ) {
                _order.splice(layerIndex,1);
                var targetIndex = _order.indexOf(targetId);
                if ( targetIndex !== -1 ) {
                    _order.splice(targetIndex,0,layerId);
                }
            }
        }
        this.update();
    };
    /**
     * update z-index on all layers 
     */
    layers.update = function(){
        _.forEach(_order, function( id, index, _order ) {
            var layer = _layers[id];
            // when jQuery collection is empty, try to find the element again
            if ( layer.el.length === 0 ) {
                layer.el = $('#' + id);
            }
            layer.el.css('zIndex',index + 1);
        });
    };
    
    return layers;
});
