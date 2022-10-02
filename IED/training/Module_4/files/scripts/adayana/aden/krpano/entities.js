define(function(require){
    
    var $         = require('jquery'),
        _         = require('lodash'),
        Entity    = require('./entity'),
        _S        = require('adayana/utilities/string'),
        mergesort = require('adayana/utilities/sort/mergesort');
    
    /**
     * @private 
     */
    var _entities = {};
    
    
    var entities = {
        
        count: 0,
        
        time: null,
        
        /**
         * when initialized 
         */
        init: function( aden, pano, data ){
            this.aden = aden;
            this.pano = pano;
            this.models = data.entityModels;
        },
        
        /**
         * When new level loads 
         */
        onLoad: function( levelData ) {
            
        },
        
        /**
         * When engine updates 
         */
        onUpdate: function(){
            var time = aden.clock.getTime();
            this.checkAll(time);
        },
        
        /**
         * When new pano loads 
         */
        onPanoLoad: function(){
            
        },
        
        /**
         * Destroys all entities 
         */
        destroy: function(){
            this.removeAll();
        },
        
        /**
         * Force entities to be redrawn 
         */
        forceRedraw: function(){
            this.updateEntities();
            this.drawAll();
        },
        
        /**
         * Update every entity currently being managed
         * @history 2013.03.04; VRB; fixed for-loop which adjusts depth values
         */
        updateEntities: function(){
            var layer, 
                depth,
                entity,
                sortArray = [],
                layers = {},
                playerNode = this.pano.scene,
                playerIndex = this.pano.sceneIndex,
                visibles = this.getAreaList(this.pano.sceneIndex);
            
            // update each entity
            _.forEach(_entities,function(entity){
                entity.update(this.pano.scene,this.pano.sceneIndex,visibles);
                sortArray.push(entity);
            },this);
            
            // sort entities by distance from player ( increasing order of magnitude ) ===> closest-to-furthest
            mergesort.mergeSortObjArray(sortArray, 'distance', 'option');
            
            // every entity will now have a depth value that places it behind the
            // appropriate overlay layers in the cubemap.  We now need to adjust
            // those depths so than an entity closer to the player will appear in
            // front of other entities that started at the same depth.
            
            // for each entity in the sorted array.
            // go through the array in reverse order: furthest-away to closest
            for ( var i = sortArray.length - 1; i >= 0; i-- ) {
                entity = sortArray[i];
                // use initial depth setting to assign to a 'layer'
                layer = 'layer' + entity.settings.depth;
                // when another entity had the same starting depth, place this new
                // entity 1 step closer
                if (layer in layers) {
                    layers[layer] = layers[layer] + 1;
                } 
                // otherwise no previous entity had this starting depth. record depth.
                else {
                    layers[layer] = entity.settings.depth;
                }            
                // assign current entity the corrected depth;
                entity.settings.depth = layers[layer];
            }
        },
        
        /**
         * Runs checks on all entities 
         */
        checkAll: function(time){
            this.time = time;
            _.forEach(_entities,function(entity){
                this.check( entity, time );
            },this);
        },
        
        /**
         * Run checks on the specified entity.
         * Checks to see if the entity's time has expired
         * @param {String|Object} value - entity or identifier
         * @param {Object} time - time string
         */
        check: function( value, time ) {
            var entity;
            if ( _.isString(value) ) {
                if ( value in _entities ) {
                    entity = _entities[value];
                } else {
                    return;
                }
            } else {
                entity = value;
            }
            var isExpired = entity.checkExpiration(time);
            if ( isExpired ) {
                this.remove( entity );
            }
        },
        
        /**
         * remove all entities 
         */
        removeAll: function(){
            _.forEach(_entities,function(entity){
                entity.destroy();
            });
            _entities = {};
            this.count = 0;
        },
        
        /**
         * Remove an entity 
         * @param {Object} value
         */
        remove: function( value ) {
            var entity;
            if ( _.isString(value) ) {
                if ( value in _entities ) {
                    entity = _entities[value];
                } else {
                    return;
                }
            } else {
                entity = value;
            }
            delete _entities[entity.name];
            entity.destroy();
            this.count--;
        },
        
        /**
         * Draw every entity 
         */
        drawAll: function(){
            _.forEach(_entities,function(entity){
                this.draw( entity );
            },this);
        },
        
        /**
         * draw the specified entity; 
         */
        draw: function( value, checkReload ) {
            checkReload = !!checkReload;
            var entity;
            if ( _.isString(value) ) {
                if ( value in _entities ) {
                    entity = _entities[value];
                } else {
                    return;
                }
            } else {
                entity = value;
            }
            if ( checkReload ) {
                if ( entity.settings.reload === false ) {
                    this.remove( entity );
                    return;
                }
            }
            entity.draw();
        },
        
        /**
         * Determine if an entity name exists 
         * @param {Object} name
         */
        has: function( name ) {
            return ( name in _entities );
        },
        
        /**
         * Get an entity 
         */
        get: function( name ) {
            if ( name in _entities ) {
                return _entities[name];
            } else {
                return null;
            }
        },
        
        /**
         * Add an entity 
         */
        add: function( entity ) {
            _entities[entity.name] = entity;
            this.count++;
            this.updateEntities();
            this.drawAll();
        },
        
        /**
         * Create a new entity 
         */
        create: function( name, modelName, options ){
            var model = this.getModel(modelName);
            options = $.extend(true,{},model,options);
            options.name = name;
            var entity = new Entity( this.pano, name, options );
            this.add(entity);
        },
        
        /**
         * Interact with an entity ( click ) 
         * @param {Object} name
         */
        interact: function( name ) {
            if ( name in _entities ) {
                _entities[name].interact();
            }
        },
        
        /**
         * retrieve the array of visible nodes associated with a given node number
         * @param {type} nodeNum
         * @returns {@exp;area@pro;nodes}
         */
        getAreaList: function(nodeNum) {
            var area;
            for (var i = 0; i < this.panoe.areaData.length; i++) {
                area = this.pano.areaData[i];
                if ( area.nodes.indexOf(nodeNum) > -1 ) {
                    return area.visible;
                }
            }
            return [];
        },
        
        /**
         * Get the settings for a model 
         */
        getModel: function( name ) {
            var model = _.find(this.models,function(model) {
                return model.name === name;
            });
            return model;
        },
        
        /**
         * Get the Number of Entities that match the given type 
         * @param {Object} type
         */
        getNumberOf: function( type ) {
            var count = 0;
            _.forEach(_entities,function(entity){
                if ( entity.settings.type === type ) {
                    count++;
                }
            });
            return count;
        }
        
    };
    
    return entities;
});
