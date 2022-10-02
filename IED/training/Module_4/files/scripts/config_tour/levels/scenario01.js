define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        debug = require('adayana/debug/debug'),
        preload = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');
        
    var scenario = {
        "id" : "scenario01",
        
        // -- SETTINGS --
        "fsm"          : 'scenario01',
        "scene"        : 'start',
        "target"       : null,
        "xmlPath"      : 'files/assets/panos/scenario01/level.xml',
        "resetObjects" : true,
        
        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM( aden.fsm.scenario01 );
            aden.plugin.radio.setEventName( 'radio-click' );
        },
        "onPanoLoad": function(){
            aden.fsm.gameView.trigger('complete');
        },
        
        // -- GAME STATE --
        "state": {
            "modules" : {
                "clock" : {
                    "initTime"  : "06:25:00.00",
                    "autoStart" : true,
                    "speed"     : 30,
                    "maxSpeed"  : 960,
                    "minSpeed"  : 1
                },
                "objects":{
                    "reset": true
                },
                "score": {
                    "points" : 0
                }
            }
        },
        
        
        "variables" : [
            {
                "name"  : "scenario01_complete",
                "type"  : "boolean",
                "value" : false
            }
        ],
        
        // -- GAME OBJECTS --
        "objects" : [
            {
                id    : 's01-warning-popup',
                type  : 'popup',
                title : 'Warning',
                text  : 'You have to make a decision.'
            },
            {
                id    : "s01-cin01",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin01.mp4'
                }
            },
            {
                id    : "s01-cin04",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin04.mp4'
                }
            }
        ],
        
        // LEVEL DATA FOR PLUGINS
        "plugin" : {
            
        },
        
        // DATA FOR TIMED EVENT MODULE
        "timedEvents" : [],
        
        // ENVIRONMENT DATA FOR KRPANO MODULE
        "pano": {
            "areaData": [],
            "scenes": [
                {
                    "num"       : 0,
                    "name"      : "start",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.acenario01.trigger('move-start');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "van",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario01.trigger('move-van');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "cafe",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario01.trigger('move-cafe');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "car",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario01.trigger('move-car');
                    }
                }
            ]
        }
    };
    
    return scenario;
});
