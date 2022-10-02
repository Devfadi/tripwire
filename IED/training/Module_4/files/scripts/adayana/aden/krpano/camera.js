define(function(require) {
    
    var $        = require('jquery'),
        _        = require('lodash'),
        MathUtil = require('adayana/utilities/math'),
        debug    = require('adayana/debug/debug');
        
    var _navPoints = [];

    var camera = {
        h : 0,
        v : 0,
        target : null,
        includeHotspots : false,
        
        init : function(parent) {
            this.pano = parent;
        },

        onPanoLoad : function() {
            _navPoints = [];
            this._getNavPoints();
            this.updateView();
            this.updateTarget();
        },

        /**
         * Pre-processes all of the nav points
         */
        _getNavPoints : function() {
            var h, v, point, 
                points = $.extend(true, [], this.pano.scene.navpoints);

            _.forEach(points, function(navPoint) {
                // when point is a string, nav point references a scene name
                if (_.isString(navPoint)) {
                    _.forEach(this.pano.sceneData, function(scene) {
                        if (scene.name.toLowerCase() === navPoint) {
                            var z1 = this.pano.scene.position.z;
                            var x1 = this.pano.scene.position.x;
                            var z2 = scene.position.z;
                            var x2 = scene.position.x;
                            h = MathUtil.angle(z1, x1, z2, x2);
                            v = 0;

                            point = {
                                type : 'nav',
                                name : navPoint,
                                h : h,
                                v : v
                            };
                            return false;
                        }
                    }, this);
                }
                // othewise this nav point provides ath and atv values
                else {
                    point = {
                        type : 'point',
                        h : navPoint.h,
                        v : navPoint.v
                    };
                }
                // when point exists, push
                if (point) {
                    _points.push(point);
                    _navPoints.push(point);
                }
            }, this);
        },
        
        /**
         * Update the view angles 
         */
        updateView : function() {
            this.h = Number(this.pano.krpano.get("view.hlookat"));
            this.v = Number(this.pano.krpano.get("view.vlookat"));
        },

        /**
         * Find the closest nav point
         */
        updateTarget : function() {
            var h, v, angle, 
                targetAngle = 360;

            // go through every nav point
            _.forEach(_navPoints, function(navPoint) {
                h = navPoint.h;
                v = navPoint.v;
                angle = MathUtil.diffAngle(this.pano.camera.h, 0, h, 0);
                if (angle < targetAngle) {
                    this.target = navPoint;
                    targetAngle = angle;
                }
            }, this);
        },
        
        /**
         * Grab the next nav target that is at least 15 degrees away from the current target in the
         * given direction (left/right); 
         */
        getNextTarget: function( direction ) {
            var targetAngle,h,v,delta,target;
            this.pano.camera.updateView();
            this.updateTarget();
            
            // get current view angle
            var angle = MathUtil.absAngle( this.pano.camera.h );
            
            // get starting target angle
            if ( direction === 'left' ) {
                targetAngle = angle - 360; // look at everything between this angle and 360 degrees behind 
            } else {
                targetAngle = angle + 360; // look at everything between this angle and 360 degrees ahead
            }
            
            // grab the next nav point in the given direction that is at least 15 degrees away
            _.forEach( _navPoints, function( navPoint ){
                h = MathUtil.absAngle(navPoint.h);
                delta = MathUtil.absAngle(angle - h);
                // continue when the same point or same angle
                if ( this.navTarget === navPoint || navPoint.h === angle ) {
                    return;
                }
                if ( direction === 'left' ) {
                    if ( h > angle ) {
                        h -= 360;
                    }
                    if ( h > targetAngle && delta > 15 ) {
                        target = navPoint;
                        targetAngle = h;
                    }
                }
                else {
                    if ( h < angle ) {
                        h += 360;
                    }
                    if ( h < targetAngle && delta > 15 ) {
                        target = navPoint;
                        targetAngle = h;
                    }
                }
            },this);
            return target;
        },

        /**
         * Turn camera to face a hotspot
         * @param {Object} name
         */
        turnTo : function( name ) {
            if (_.isString(name)) {
                // when the hotspot exits
                if (this.pano.krpano.get("hotspot[" + name + "].index") !== null) {
                    var h = this.pano.krpano.get("hotspot[" + name + "].ath");
                    var v = this.pano.krpano.get("hotspot[" + name + "].atv");
                    this.lookTo(h, v);
                }
            }
        },
        
        /**
         * Turn to a nav point 
         */
        turnToNavPoint : function( index ) {
            // FUTURE - implement turning to a nav point
        },

        /**
         * Turn camera relative to current view
         */
        turn : function(dh, dv) {
            var h = Number(this.pano.krpano.get("view.hlookat"));
            var v = Number(this.pano.krpano.get("view.vlookat"));
            h += dh;
            v += dv;
            this.lookTo(h, v);
        },

        /**
         * Face towards the specified direction
         */
        face : function(angle) {
            this.lookTo(angle, 0);
        },

        /**
         * look to specific horizontal and vertical angles
         */
        lookTo : function(h, v) {
            this.pano.krpano.call("lookto(" + h + "," + v + ",55,smooth(720,-720,720),true,true,JS(aden.pano.camera.onLookComplete))");
        },
		
		getView: function(){
			var toH = Number(this.pano.krpano.get("view.hlookat"));
            var toV = Number(this.pano.krpano.get("view.vlookat"));
			alert('(' + toH + "," + toV + ")");
		},
		
        /**
         * executes actions when the krpano lookto call is complete
         */
        onLookComplete : function() {
            this.updateView();
        },

        /**
         * Start Pano sway
         */
        beginSway : function() {
            this.shouldStopSway = false;
            this.swayRight();
        },

        /**
         * Stop Pano Sway
         */
        stopSway : function() {
            this.shouldStopSway = true;
        },

        /**
         * Sway Pano to the right and then call swayLeft
         */
        swayRight : function() {
            if (shouldStopSway) {
                return;                
            }
            var toH = Number(this.pano.krpano.get("view.hlookat"));
            var tov = Number(this.pano.krpano.get("view.vlookat"));
            toH += 1.0;

            this.pano.krpano.call("oninterrupt(break);lookat(" + toH + "," + tov + ",55,tween(easeInOutQuad,4),true,true,js(aden.pano.camera.swayLeft()));");
        },

        /**
         * Sway Pano to the left and then call swayRight
         */
        swayLeft : function() {
            if (shouldStopSway) {
                return;                
            }
            var toH = Number(this.pano.krpano.get("view.hlookat"));
            var tov = Number(this.pano.krpano.get("view.vlookat"));
            toH -= 1.0;

            this.pano.krpano.call("oninterrupt(break);lookat(" + toH + "," + tov + ",55,tween(easeInOutQuad,4),true,true,js(aden.pano.camera.swayRight()));");
        }
        // turnToAngle: function( angle, direction ) {
        // // make sure angle are between 0 and 360
        // angle = MathUtil.absAngle( angle );
        // this.h = MathUtil.absAngle( this.h );
        // this.pano.krpano.set('view.hlookat', this.h );
        // if ( direction === 'right' ) {
        // if ( angle < this.h ) {
        // angle += 360;
        // }
        // } else {
        // if ( angle > this.h ) {
        // angle -= 360
        // }
        // }
        // this.lookTo(h,0);
        // }
    };

    return camera;
});
