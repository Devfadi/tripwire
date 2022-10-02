define(function(){
    
    /*
     * Houses the settings for the engine and the main modules
     */
    var settings = {
        "version" : "0.2.0",
        
        // ENGINE SETTINGS
        "engine" : {
            "el"               : "#viewport",
            "firstLevel"       : 0,
            "isLocal"          : false,
            "isMobile"         : false,
            "loadSaveOnStart"  : true,
            "constrainToRatio" : false,
            "ratio"            : 16/9,
            
        },
        
        // ENGINE MODULE SETTINGS
        "modules" : {
            "clock" : {
                "resetsOnLevel" : true,
                "speed"         : 1,
                "maxSpeed"      : 960,
                "minSpeed"      : 1
            },
            "objects": {
                "resetsOnLevel" : true            
            },
            "score" : {
                "resetBetweenLevels" : true // When true, scores are reset between levels            
            },
            "layers" : {
                "el" : "#viewport",
                // bottom to top
                "initial": [
                    "krpanoDIV",
					"spinner",
                    "clock-view",
                    "status-view",
                    "radio-view",
                    "pause-icon",
                    "resources-icon",
                    "map-view",
                    "map-icon",
                    "menu-bg",
                    "mode-view",
                    "preload-display",
                    "god-view",
                    "debug",
                ]
            },
            "variables": {
                "trackLevelsIndependently" : true,
                "resetLevelsOnLoad"        : true
            },
        },
        
        // ADVENTURE OBJECT SETTINGS
        "objects" : {
           "popup": { 
               "source"       : "files/templates/objects/popup.html",
               "modal"        : true,
               "onShow"       : "popup-show",
               "onHide"       : "popup-hide",
               "onStart"      : "popup-start",
               "onDestroy"    : "popup-destroy",
               "onActivate"   : "popup-activate",
               "onDeactivate" : "popup-deactivate"
           },
           "narration" : { 
               "source" : "files/templates/objects/narration.html",
               "modal"  : true
           },
           "dp" : { 
               "source" : "files/templates/objects/dp.html",
               "prefix" : "option",
               "modal"  : true
           },
           "dp-multi" : {
               "source" : "files/templates/objects/dp-multi.html",
               "prefix" : "option",
               "modal"  : true
           },
           "image": { 
               "source"       : "files/templates/objects/image.html",
               "onShow"       : "image-show",
               "onHide"       : "image-hide",
               "onStart"      : "image-start",
               "onDestroy"    : "image-destroy",
               "onActivate"   : "image-activate",
               "onDeactivate" : "image-deactivate"
           },
           "video": {
               "path"          : "",
               "template"      : "files/templates/objects/video.html",
               "sourceParam"   : "source"
           },
           "audio": {
               "source" : 'files/templates/objects/audio.html',
               "playerSource"  : "files/templates/audio_player.html",
               "controlSource" : "files/templates/audio_control.html"
           },

           "dp_managed"      : { "source": "files/templates/objects/dpManaged.html"},
           "dp_multimanaged" : { "source": "files/templates/objects/dpMultiManaged.html"},
           "dp_popup"        : { "source": "files/templates/objects/popup.html"},
           "narrator"        : { "source": "files/templates/objects/narrator.html"},
           "scorePopup"      : { "source": "files/templates/objects/scorePopup.html"},
           "tabbed_popup"    : { "source": "files/templates/objects/tabbedPopup.html"}
        },
        
        // GLOBALLY TRACKED VARIABLES
        "variables" : [
            // track scenario completion
            { "name": "scenario01_complete",  "type": "boolean", "value" : false },
            { "name": "scenario02_complete",  "type": "boolean", "value" : false },
            { "name": "scenario03_complete",  "type": "boolean", "value" : false },
            { "name": "scenario04_complete",  "type": "boolean", "value" : false },
            { "name": "scenario05_complete",  "type": "boolean", "value" : false },
            { "name": "scenario06_complete",  "type": "boolean", "value" : false },
            { "name": "scenario07_complete",  "type": "boolean", "value" : false },
            { "name": "scenario08_complete",  "type": "boolean", "value" : false },
            { "name": "scenario09_complete",  "type": "boolean", "value" : false },
            // track scenario attempts
            { "name": "scenario01_attempted", "type": "boolean", "value" : false },
            { "name": "scenario02_attempted", "type": "boolean", "value" : false },
            { "name": "scenario03_attempted", "type": "boolean", "value" : false },
            { "name": "scenario04_attempted", "type": "boolean", "value" : false },
            { "name": "scenario05_attempted", "type": "boolean", "value" : false },
            { "name": "scenario06_attempted", "type": "boolean", "value" : false },
            { "name": "scenario07_attempted", "type": "boolean", "value" : false },
            { "name": "scenario08_attempted", "type": "boolean", "value" : false },
            { "name": "scenario09_attempted", "type": "boolean", "value" : false },
            // track scenario scores
            { "name": "scenario01_score", "type": "number", "value" : 0 },
            { "name": "scenario02_score", "type": "number", "value" : 0 },
            { "name": "scenario03_score", "type": "number", "value" : 0 },
            { "name": "scenario04_score", "type": "number", "value" : 0 },
            { "name": "scenario05_score", "type": "number", "value" : 0 },
            { "name": "scenario06_score", "type": "number", "value" : 0 },
            { "name": "scenario07_score", "type": "number", "value" : 0 },
            { "name": "scenario08_score", "type": "number", "value" : 0 },
            { "name": "scenario09_score", "type": "number", "value" : 0 }
        ]
    };
    
    return settings;
});