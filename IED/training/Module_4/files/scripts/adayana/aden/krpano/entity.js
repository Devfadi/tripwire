define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        _S = require('adayana/utilities/string'),
        MathUtil = require('adayana/utilities/math');
    
    var defaults = {
        model          : "",                         // entity model name
        baseUrl        : "",                         // where images are stored
        type           : "customer",                 // entity type
        state          : "Idle",                     // state (action)
        mood           : "Neutral",                  // mood (visual appearance)
        behavior       : "idle",                     // which behavior algorithm to use
        dOffset        : 0,                          // distance offset ( used with behavior )
        position       : { x: 0.0, y: 0.0, z: 0.0 }, // current position
        offset         : { x: 0.0, y: 0.0, z: 0.0 }, // where to place player relative to camera
        modifiers      : [
            {
                isActive : false,
                name     : 'glasses',
                active   : 'glasses',
                inactive : ''
            }
        ],        
        heading        : 0,             // angle entity is facing
        velocity       : 0,             // velocity / speed of movement
        hasDisplayName : false,
        displayName    : '',
        node           : 0,             // closest pano node
        isVideo        : false,
        onInteract     : null,          // function to execute when interacted with
        onExpire       : null,          // function to execute when expiration time reached
        expires        : ""             // Time String indicating when player expires
    };
    
    /**
     * Scale Factor
     */
    var scaleFactor = 1.953125;
    
    /**
     * OY Factor. used to visually keep entities the same distance from the floor
     */
    var oyFactor = 0.0048;
    
    /**
     * Create a new Entity instance
     * @constructor
     * @param {type} name
     * @param {type} options
     */
    var entity = function ( pano, name, options ) {
        this.pano = pano;
        this.name = name;
        this.settings = $.extend({}, defaults, options);
        this.position = $.extend(true, {}, this.settings.position);
        this.relative = $.extend(true, {}, this.settings.relative);
        this.distance = 0;
        this.angle    = 0;
        this.scale    = 0;
        this.yoffset  = 0;
        this.src      = "";
        this.inArea   = false;
        // make sure baseUrl ends with a slash
        var lastChar = this.settings.baseUrl.charAt(this.settings.baseUrl.length-1);
        var hasForward = this.settings.baseUrl.indexOf('/');        
        if ( lastChar !== "/" && lastChar !== "\\" ) {
            if ( hasForward ) {
                this.settings.baseUrl += "/";
            } else {
                this.settings.baseUrl += "\\";  
            }
        }
    };
    
    entity.prototype = {
        /**
         * Entity's name 
         */
        name: 'undefined',
        
        /**
         * Recalculates entity's status
         * @returns {undefined}
         */
        update: function ( scene, areaNodeList ) {
            this.updatePosition(scene);
            this.updateDistance(scene);
            this.updateAngle(scene);
            this.updateScale();
            this.updateDepth( scene, areaNodeList );
            this.updateClickable();
            this.calculateFile( scene );
        },
        
        /**
         * Destroy this instance
         * @returns {undefined}
         */
        destroy: function(){
            this.pano.hotspots.remove(this.name);
            if ( this.settings.hasDisplayName ) {
                this.pano.hotspots.remove('nametag_' + this.name );
            }
            if ( this.settings.showAlertIcon ) {
                this.pano.hotspots.remove('alert_' + this.name );
            }
        },
        
        draw: function(){
            var name      = this.name,
                angle     = this.settings.angle,
                file      = this.settings.file,
                scale     = this.settings.scale,
                yoffset   = this.settings.yoffset,
                depth     = this.settings.depth,
                clickable = this.settings.isClickable,
                height    = this.settings.height,
                width     = this.settings.width,
                displayName,childName,fileName,newOY;
            
            // add main hotspot
            if ( this.settings.isVideo ) {
                aden.pano.hotspots.addVideo(name, file, angle, scale, height, width, yoffset, depth, clickable, clickable);
            } else {
                aden.pano.hotspots.addImage(name, file, angle, scale, height, width, yoffset, depth, clickable, clickable);
            }
            
            // add name tag
            if ( this.settings.hasDisplayName ) {
                displayName = this.settings.displayName;
                childName = 'nametag_' + displayName;
                fileName = 'Nametags/' + displayName + '.png';
                newOY = yoffset - (375 * scale);
                aden.pano.hotspots.addChildImage(childName, fileName, name, scale, angle, newOY, depth, clickable, name);
            }
            
            // add alert icon
            if ( this.settings.showAlertIcon ) {
                childName = 'alert_' + this.name;
                fileName = 'alertIcon.png';
                newOY = yoffset - (400 * scale);
                newScale = 0.25 * scale;
                aden.pano.hotspots.addChildImage(childName, fileName, name, newScale, angle, newOY, depth + 1, clickable, name);
            }
        },
        
        /**
         * Calculates where to place the character when they're updated 
         * @param {Object} scene
         * @param {Object} index
         */
        updatePosition: function( scene ) {
            var playerAngle = this.pano.camera.h;
            switch (this.settings.behavior) {
                case "follow":
                    this.position.x = scene.position.x - this.settings.dOffset * Math.sin(playerAngle * MathUtil.pi / 180) + this.settings.offset.x;
                    this.position.z = scene.position.z - this.settings.dOffset * Math.cos(playerAngle * MathUtil.pi / 180) + this.settings.offset.z;
                    break;
                case "lead":
                    this.position.x = scene.position.x + this.settings.dOffset * Math.sin(playerAngle * MathUtil.pi / 180) + this.settings.offset.x;
                    this.position.z = scene.position.z + this.settings.dOffset * Math.cos(playerAngle * MathUtil.pi / 180) + this.settings.offset.z;
                    break;
                case "stalk":   // entity 'stalks' player. Stays at a static position on every node
                    this.position.x = scene.position.x + this.settings.offset.x;
                    this.position.z = scene.position.z + this.settings.offset.z;
                    break;
                // idle
                default:
                    return;
            }
        },
        
        /**
         * Calculates the distance of the entity from the camera
         * @param {type} scene
         */
        updateDistance: function (scene) {
            this.relative.x = MathUtil.diff(scene.position.x, this.position.x);
            this.relative.y = MathUtil.diff(scene.position.y, this.position.y);
            this.relative.z = MathUtil.diff(scene.position.z, this.position.z);
            this.distance = MathUtil.distance(this.relative.z, this.relative.x);
        },
        
        /**
         * calculates the angle between the player's node and entity's node
         * @param {type} scene
         */
        updateAngle: function (scene) {
            this.angle = MathUtil.angle(scene.position.z, scene.position.x, this.position.z, this.position.x);
        },
        
        /**
         * Calculates the scale to use when displaying the entity in the cubemap panorama
         */
        updateScale: function () {
            this.scale   = scaleFactor / (2 * (this.distance * 0.507965897));
            this.yoffset = this.scale / oyFactor;
        },
        
        /**
         * Calculates the entity's initial depth amongst the node's layers
         * @param {type} scene
         * @returns {undefined}
         */
        updateDepth: function (scene, areaNodeList) {
            // depth:  {0,N} -- 0 is furthest away.  N is closest
            var depth = 0;
            var layers = scene.layers;
            var layer, i;
            
            // for each layer within this node location
            for (i = 0; i < layers.length; i++) {
                // get layer
                layer = layers[i];
                // if the entity's node index is in this layer's array
                // Then the entity appears behind this layer.
                if ( layer.scenes.indexOf(this.settings.node) > -1 ) {
                    // use the last valid depth. entity will not appear in front of subsequent layers.
                    break;
                } 
                // this node is in front of this layer
                else {
                    // use a depth that is 1 step closer to the screen.
                    depth = layer.depth + 1;
                }
            }
            // set this entity's depth
            this.depth = depth;
            
            // determin if the entity is in the same area as the player.
            this.inArea = ( areaNodeList.indexOf( this.settings.node ) > -1 );
        },
        
        /**
         * Update Clickable status
         */
        updateClickable: function(){
            this.isClickable = ( 
                this.inArea && 
                this.settings.onInteract !== '' && 
                this.settings.onInteract !== null && 
                this.settings.onInteract !== undefined 
            );
        },
        
        /**
         * Update Generated File Name
         * @param {type} scene
         */
        calculateFile: function( scene ) {
            // Model_State_Mood{{_modifier}}_Distance.png
            // Model_State_Mood{{_modifier}}_Distance_Heading.png
            
            // calculate distance
            var isClose = false;
            this.settings.isVideo = false;
            if ( scene.position.x === this.settings.position.x && 
                 scene.position.y === this.settings.position.y && 
                 scene.position.y === this.settings.position.z 
            ) {
                isClose = true;
                this.settings.isVideo = true;
            }
            
            var src = this.settings.baseUrl + this.settings.model + "_" + this.settings.state;
            
            // When close, add mood, otherwise show neutral
            if ( isClose ) {
                src += '_' + this.settings.mood;
            } else {
                src += '_Neutral';
            }
            
            //TODO - process modifiers
            _.forEach( this.settings.modifiers, function(modifier) {
                // src += "_" + modifier.active
            });
            
            if ( isClose ) {
                src += "_Close";
                // change angle to directly face the player
                this.settings.angle = krpano.get("view.hlookat");
                var heading = this.settings.angle - 180;
                if ( heading < 0 ) {
                    heading += 360;
                }
                this.settings.heading = heading;
                this.settings.scale   = 1;
                this.settings.oy      = 80;
                this.depth   = 150;
            } 
            else {
                src += "_Mid";
                // Calculate and add the viewing angle
                var diff = MathUtil.absAngle(this.settings.heading - this.settings.angle);
                var viewAngle = Math.round( diff / 45 ) * 45;   // round to closest factor of 45
                viewAngle = MathUtil.absAngle(viewAngle);       // ensure its between 0 and 360 degrees
                viewAngle = _S.padDigits(viewAngle, 3);         // pad to three digits
                src += "_" + viewAngle;
            }
            
            if ( this.settings.isVideo ) {
                src += ".flv";
            } else {
                src += ".png";
            }
            this.file = src;
            
            // set dimensions to display file at
            var height = 576, 
                width;
            if ( isClose ) {
                width = 1024;
            } else {
                if ( this.settings.isVideo ) {
                    width = 288;
                } else {
                    width = 280;
                }
            }
            this.height = height * this.settings.scale;
            this.width  = width  * this.settings.scale;
        },
        
        /**
         * Get or Set an entity's setting/option
         * @param {type} key
         * @param {type} value
         */
        option: function( key, value ) {
            if ( value === undefined ) {
                return this.settings[key];
            } else {
                switch( key ) {
                    case "depth":
                        this._setDepth( value );
                        break;
                    case "displayName":
                        this._setDisplayName( value );
                        break;
                    case "expires":
                        this._setExpiration( value );
                        break;
                    case "node":
                        this._setNodeIndex( value );
                        break;
                    case "onInteract":
                        this.settings[key] = value;
                        this.updateClickable();
                        break;
                    default:
                        this.settings[key] = value;
                }
            }
        },
        
        /**
         * Set a new depth for this entity
         * @param {type} depth
         */
        _setDepth: function( depth ) {
            this.depth = depth;
            krpano.set("hotspot["+ this.name +"].zorder", this.depth );
        },
        
        /**
         * Set Display Name of entity
         * @param {type} name
         * @returns {undefined}
         */
        _setDisplayName: function( name ) {
            // FUTURE - remove old display name hotspot if allowing this to change...
            this.settings.displayName = name;
            if ( name && name !== '' ) {
                this.settings.hasDisplayname = true;                
            } else {
                this.settings.hasDisplayName = false;                
            }
        },
        
        /**
         * Set time when the entity expires
         * @param {type} timeStr
         * @returns {undefined}
         */
        _setExpiration: function( timeStr ) {
            if ( _.isString(timeStr) ) {
                this.settings.expires    = timeStr;
                this.settings.expires_ms = _S.parseTime( this.settings.expires ) * 1000;
            } else {
                this.settings.expires_ms = null;
                this.settings.expires    = null;
            }
        },
        
        /**
         * Move entity to a new node index
         * @param {type} nodeIndex
         * @returns {undefined}
         */
        _setNodeIndex: function( nodeIndex ) {
            this.settings.node = nodeIndex;
        },
        
        /**
         * move a relative amount 
         */
        move: function( x, y, z ) {
            this.position.x += x;
            this.position.y += y;
            this.position.z += z;
        },
        
        /**
         * move character to a given world position 
         */
        moveTo: function( x, y, z ) {
            this.position.x = x;
            this.position.y = y;
            this.position.z = z;
        },
        
        /**
         * Move to the position of a specific scene 
         */
        moveToScene: function( scene ) {
            this.position = $.extend(true,{},scene.position);
        },
        
        interact: function(){
            if ( _.isFunction( this.settings.onInteract ) ) {
                this.settings.onInteract();
            }
        },
        
        /**
         * Check if the entity has expired
         * @param {type} time
         * @returns {Boolean}
         */
        checkExpiration: function( time ) {
            if ( 'expires' in this.settings && this.settings.expires !== '' && this.settings.expires !== null && this.settings.expires !== undefined ) {
                if ( !( 'expires_ms' in this.settings ) ) {
                    this.settings.expires_ms = _S.parseTime( this.settings.expires ) * 1000;
                }
                // when expires time has been surpassed
                if ( this.settings.expires_ms < time ) {
                    // execute the onExpire script
                    if ( this.settings.onExpire && _.isFunction(this.settings.onExpire)) {
                        this.settings.onExpire( this );                            
                    }
                    // entity has expired
                    return true;
                }
            }
            return false;
        }
    };
    
    return entity;
    
});
