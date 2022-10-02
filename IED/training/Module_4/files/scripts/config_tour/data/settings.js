define(function(){
    
    /*
     * Houses the settings for the engine and the main modules
     */
    var settings = {
        
        // ENGINE SETTINGS
        "engine" : {
            "el"         : "#viewport",
            "firstLevel" : 0,
            "isLocal"    : false,
            "isMobile"   : false
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
                    "clock-view",
                    "status-view",
                    "radio-view",
                    "playlist",
                    "map-view",
                    "map-icon",
                    "menu-bg",
                    "preload-display",
                    "god-view",
                    "debug",
                ]
            } 
        },
        
        // ADVENTURE OBJECT SETTINGS
        "objects" : {
           "popup": { 
               "source"       : "files/templates/objects/popup.html",
               "modal"        : true,
               "onShow"       : "obj-show",
               "onHide"       : "obj-hide",
               "onStart"      : "obj-start",
               "onDestroy"    : "obj-destroy",
               "onActivate"   : "obj-activate",
               "onDeactivate" : "obj-deactivate"
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
               "onShow"       : "obj-show",
               "onHide"       : "obj-hide",
               "onStart"      : "obj-start",
               "onDestroy"    : "obj-destroy",
               "onActivate"   : "obj-activate",
               "onDeactivate" : "obj-deactivate"
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
        "variables" : {}
    };
    
    return settings;
});