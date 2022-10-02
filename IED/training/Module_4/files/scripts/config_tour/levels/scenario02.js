define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');
        
    var scenario = {
        "id" : "scenario02",
        
        // -- SETTINGS --
        "fsm"          : 'scenario02',
        "scene"        : 'start',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/scenario02/tour.xml',
        "resetObjects" : true,
        
        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
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
        
        // -- GAME OBJECTS --
        "objects" : [
            {
                id    : 's02-tour-intro',
                type  : 'popup',
                title : 'Welcome',
                text  : 'Welcome to the virtual tour.'
            },
            {
                id    : "s02-cin01",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_02/S02_Cin01.mp4'
                }
            },
            {
                id    : "s02-cin02",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_02/S02_Cin02.mp4'
                }
            },
            {
                id    : "s02-cin03",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_02/S02_Cin03.mp4'
                }
            },
            {
                id    : "s02-cin04",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_02/S02_Cin04.mp4'
                }
            },
            {
                id    : "s02-cin05",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_02/S02_Cin05.mp4'
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
                        aden.fsm.scenario02.trigger('move-start');
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
                        aden.fsm.scenario02.trigger('move-van');
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
                        aden.fsm.scenario02.trigger('move-cafe');
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
                        aden.fsm.scenario02.trigger('move-car');
                    }
                }
            ]
        }
    };
    
    return scenario;
});
