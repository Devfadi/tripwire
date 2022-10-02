/**
 * Configuration file for scenario 00, which encompases the splash screens and menu items before you
 * start scenarios 01 through 09 
 */
define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');
        
    var scenario = {
        "id"      : "scenario00",
        "fsm"     : null,
        "scene"   : null,
        "target"  : null,
        "xmlPath" : null,
        "totalPoints"  : 0,
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.fsm.gameView.trigger('complete');
        },
        "onPanoLoad": function(){
        },
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
                "score":{
                    "service"   : 0,
                    "employee"  : 0,
                    "customer"  : 0,
                    "financial" : 0
                }
            },
            "plugins" : {},
        },      
        "objects" : [],
        "timedEvents" : [],
        "pano": {
            "areaData": [],
            "scenes": []
        }
    };
    
    return scenario;
});
