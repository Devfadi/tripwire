define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        MathUtil = require('adayana/utilities/math'),
        debug    = require('adayana/debug/debug');
        
    var _points   = [];   // collection of every point and hotspot
    var _hotspots = [];   // names of every hotspot
    var _visible  = [];   // visible hotspots
    var _hidden   = [];   // hidden hotspots
    
    //TODO - track hotspots to enable/disable in every scene
    //TODO - track hotspots to show/hide in every scene
    
    var hotspots = {
        
        /**
         * initialize hotspots module 
         */
        init: function( parent ) {
            this.pano = parent;
        },
        
        /**
         * When new pano loads, grab the new set of nav points and grab
         * the list of hotspots 
         */
        onPanoLoad: function() {
            _points    = [];
            _hotspots  = [];
            _visible   = [];
            this._getHotspots();
        },
        
        /**
         * Generates a collection of all hotspots in the scene 
         */
        _getHotspots: function() {
            var h,v,point,name,visible,
                count = this.pano.krpano.get('hotspot.count');
            
            for ( var i = 0; i < count; i++ ) {
                name    = this.pano.krpano.get('hotspot['+i+'].name');
                h       = this.pano.krpano.get('hotspot['+i+'].ath');
                v       = this.pano.krpano.get('hotspot['+i+'].atv');
                visible = this.pano.krpano.get('hotspot['+i+'].visible');
                
                point = {
                    type : 'hotspot',
                    name : name,
                    h    : h,
                    v    : v
                };
                
                _hotspots.push( point );
                _points.push( point );
                if ( visible ) {
                    _visible.push(point);
                } else {
                    _hidden.push(point);
                }
            }
        },
        
        getNames: function() {
            return _.pluck(_hotspots,'name');
        },
        
        /**
         * Grab a point by name 
         */
        getPoint: function( name ) {
            var result;
            _.forEach( _points, function( point ) {
                if ( point.name && point.name === name ) {
                    result = point;
                    return false;
                }
            });
            return result;
        },
        
        /**
         * Enable a hotspot 
         * @param {String} id
         */
        enable: function ( id, always ) {
            if ( this.pano.krpano.get("hotspot[" + id + "].index") !== null ) {
                this.pano.krpano.call("hotspot[" + id + "].enabled", true);
            }
            //TODO - track hotspots to always enable on each pano load
        },
        
        enableAll: function() {
            _.forEach(_hotspots,function(hotspot){
                this.enable( hotspot.name );
            },this);
        },
        
        /**
         * Disable a hotspot
         * @param {String} id
         */
        disable: function ( id, always ) {
            if (this.pano.krpano.get("hotspot[" + id + "].index") !== null) {
                this.pano.krpano.call("hotspot[" + id + "].enabled", false);
            }
            //TODO - track hotspots to always disable on each pano load
        },
        
        disableAll: function() {
            _.forEach(_hotspots,function(hotspot){
                this.disable( hotspot.name );
            },this);
        },
        
        /**
         * Removes a specific hotspot
         * @param {String} id
         */
        remove: function( id ) {
            var visible = false;
            // remove from environment
            if (this.pano.krpano.get("hotspot[" + id + "].index") !== null) {
                visible = this.pano.krpano.get('hotspot["'+id+'"].visible');
                this.pano.krpano.call("removehotspot(" + id + ")");
                
            }
            // stop tracking
            removePointFrom( _points, id );
            removePointFrom( _hotspots, id );
            if ( visible ) {
                removePointFrom( _visible, id );
            } else {
                removePointFrom( _hidden, id );
            }
        },
        
        removeAll: function() {
            _.forEach(_hotspots,function(hotspot){
                this.remove( hotspot.name );
            },this);
        },
        
        /**
         * Show a hotspot 
         */
        show: function( id ) {
            var point = this.getPoint(id);
            if ( point ) {
                if (this.pano.krpano.get("hotspot[" + id + "].index") !== null) {
                    this.pano.krpano.set("hotspot[" + id + "].visible", true);
                }
                removePointFrom( _hidden, id );
                _visible.push(point);
            }
        },
        
        showAll: function() {
            _.forEach(_hotspots,function(hotspot){
                this.show( hotspot.name );
            },this);
        },
        
        /**
         * Hide a hotspot 
         */
        hide: function( id ) {
            var point = this.getPoint(id);
            if ( point ) {
                if (this.pano.krpano.get("hotspot[" + id + "].index") !== null) {
                    this.pano.krpano.set("hotspot[" + id + "].visible", false);
                }
                removePointFrom(_visible,id);
                _hidden.push(point);
            }
        },
        
        hideAll: function() {
            _.forEach(_hotspots,function(hotspot){
                this.hide( hotspot.name );
            },this);
        },
        
        /**
         * Dynamically add a Video Hotspot to the current pano
         * @param {String} src      video source
         * @param {Number} ath      horizontal angle
         * @param {Number} scale    hotspot scale
         * @param {Number} oy       y-offset
         * @param {Number} depth    hotspot depth
         */
        addVideo: function (id, src, ath, scale, height, width, oy, depth, clickable, navigatable, onClick, loop, onComplete) {
            debug.log('adding video hotspot: ' + src);
            
            if (onClick === undefined || onClick === null) {
                onClick = "";
            }
            
            if (loop === undefined || loop === null) {
                loop = true;
            }
            
            if (onComplete === undefined || onComplete === null) {
                onComplete = "";
            }
            
            navigatable = navigatable || false;
            
            debug.log('adding video using file: files/assets/graphics/video/' + src);
    
            // when the hotspot does not exist
            if ( this.pano.krpano.get("hotspot[" + id + "].index") === null) {
                // when hotspot does not exist, create it:
                // create hotspot entry
                var hotspot = {
                    id: id,
                    node: "none",
                    nav: false,
                    h: ath,
                    v: 0
                };
    
                this.hotspots.push(hotspot);
    
                if (navigatable) {
                    this.navHotspots.push(hotspot);
                }
    
                // add hotspot, set video plugin, set video url
                this.pano.krpano.call("addhotspot(" + id + ")");
                this.pano.krpano.set("hotspot[" + id + "].videourl", "%HTMLPATH%/files/assets/graphics/video/" + src);
                this.pano.krpano.set("hotspot[" + id + "].url", "plugins/videoplayer.swf");
            }
            // when the hotspot exists
            else {
                // change video source if hotspot exists
                this.pano.krpano.set("hotspot[" + id + "].url", "plugins/videoplayer.swf");
                this.pano.krpano.call("hotspot[" + id + "].playVideo(" + "%HTMLPATH%/files/assets/graphics/video/" + src + ")");
            }
    
            // set/update hotspot parameters
            this.pano.krpano.set("hotspot[" + id + "].name", id);
            this.pano.krpano.set("hotspot[" + id + "].distorted", "true");
            this.pano.krpano.set("hotspot[" + id + "].onhover", "showtext('Interact')");
            this.pano.krpano.set("hotspot[" + id + "].zorder", depth);
            this.pano.krpano.set("hotspot[" + id + "].height", height);
            this.pano.krpano.set("hotspot[" + id + "].width", width);
            //this.pano.krpano.set("hotspot[" + id + "].width", "prop");
            this.pano.krpano.set("hotspot[" + id + "].oy", oy);
            this.pano.krpano.set("hotspot[" + id + "].ath", ath);
            this.pano.krpano.set("hotspot[" + id + "].loop", loop);
            this.pano.krpano.set("hotspot[" + id + "].align", "center");
            this.pano.krpano.set("hotspot[" + id + "].edge", "center");
    
            // disable hotspot if it shouldn't be clickable
            if (!clickable) {
                this.pano.krpano.set("hotspot[" + id + "].enabled", "false");
                this.pano.krpano.set("hotspot[" + id + "].handcursor", "false");
            }
            else {
                // Set onClick action
                //this.pano.krpano.set("hotspot["+id+"].onclick", "lookto(get(ath),get(atv),55,tween(easeInOutQuad,2));js(aden.pano.entities.interact("+id+"));" + onClick );
                this.pano.krpano.set("hotspot[" + id + "].onclick", "lookto(get(ath),get(atv),55,smooth(720,-720,720));js(aden.pano.entities.interact(" + id + "));" + onClick);
            }
    
            // Set onComplete action
            if (onComplete !== "") {
                this.pano.krpano.set("hotspot[" + id + "].onvideocomplete", onComplete);
            }
    
            this.pano.krpano.call('updatescreen()');
        },
        
        /**
         * Dynamically add an image hotspot to the current pano
         */
        addImage: function (id, src, ath, scale, height, width, oy, depth, clickable, navigatable) {
            navigatable = navigatable || false;
    
            // when hotspot does not exist.
            if (this.pano.krpano.get("hotspot[" + id + "].index") === null) {
                var hotspot = {
                    "id": id,
                    "node": "none",
                    "nav": navigatable,
                    "h": ath,
                    "v": 0
                };
                this.hotspots.push(hotspot);
    
                if (navigatable) {
                    this.navHotspots.push(hotspot);
                }
    
                this.pano.krpano.call("addhotspot(" + id + ")");
            }
    
            debug.log('adding image using file: files/assets/graphics/images/' + src);
    
            // Set/Update properties
            this.pano.krpano.set("hotspot[" + id + "].name", id);
            this.pano.krpano.set("hotspot[" + id + "].url", "%HTMLPATH%/files/assets/graphics/images/" + src);
            this.pano.krpano.set("hotspot[" + id + "].ath", ath);
            this.pano.krpano.set("hotspot[" + id + "].atv", 0);
            this.pano.krpano.set("hotspot[" + id + "].height", height);
            this.pano.krpano.set("hotspot[" + id + "].width", width);
            this.pano.krpano.set("hotspot[" + id + "].distorted", "true");
            this.pano.krpano.set("hotspot[" + id + "].align", "center");
            this.pano.krpano.set("hotspot[" + id + "].edge", "center");
            this.pano.krpano.set("hotspot[" + id + "].onhover", "showtext('Interact')");
            this.pano.krpano.set("hotspot[" + id + "].zorder", depth);
            this.pano.krpano.set("hotspot[" + id + "].oy", oy);
            this.pano.krpano.set("hotspot[" + id + "].videourl", "");
            
            // when hotspot shouldn't be clickable
            if (!clickable) {
                this.pano.krpano.set("hotspot[" + id + "].enabled", "false");
                this.pano.krpano.set("hotspot[" + id + "].handcursor", "false");
            } else {
                // set onclick event
                this.pano.krpano.set("hotspot[" + id + "].enabled", "true");
                this.pano.krpano.set("hotspot[" + id + "].handcursor", "true");
                this.pano.krpano.set("hotspot[" + id + "].onclick", "lookto(get(ath),get(atv),55,smooth(720,-720,720));js(aden.pano.entities.interact(" + id + "));");
            }
    
            this.pano.krpano.call('updatescreen()');
    
            debug.log('image added');
        },
        
        /**
         * creates an image hotspot
         */
        addChildImage: function (id, src, parent, scale, ath, oy, depth, clickable, name ) {
            // when hotspot does not exist.
            if ( this.pano.krpano.get( "hotspot[" + id + "].index") === null ) {
                this.pano.krpano.call("addhotspot(" + id + ")");
            }
            this.pano.krpano.set("hotspot[" + id + "].url", "%HTMLPATH%/files/assets/graphics/images/" + src);
            this.pano.krpano.set("hotspot[" + id + "].ath", ath);
            this.pano.krpano.set("hotspot[" + id + "].atv", 0);
            this.pano.krpano.set("hotspot[" + id + "].oy", oy);
            this.pano.krpano.set("hotspot[" + id + "].scale", scale);
            this.pano.krpano.set("hotspot[" + id + "].zorder", depth);
            
            if ( clickable ) {
                this.pano.krpano.set("hotspot[" + id + "].enabled", "true");
                this.pano.krpano.set("hotspot[" + id + "].handcursor", "true");
                this.pano.krpano.set("hotspot[" + id + "].onclick", "lookto(get(ath),get(atv),55,smooth(720,-720,720));js(aden.pano.entities.interact(" + name + "));");
            } else {
                this.pano.krpano.set("hotspot[" + id + "].enabled", "false");
                this.pano.krpano.set("hotspot[" + id + "].handcursor", "false");
            }
        }
    };
    
    function removePointFrom( arr, name ) {
        for ( var i = 0, len = arr.length; i < len; i++ ) {
            if ( arr[i].name === name ) {
                arr.splice(i,1);
                break;
            }
        }
    }
    
    return hotspots;
});
