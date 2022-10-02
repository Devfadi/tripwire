define(function(require){
    var plugins = {
        "clock": {
            "el"     : "#clock-view",
            "source" : "files/templates/plugins/clock.html"
        },
        "entities" : {},
        "entityManager" : {},
        "messages" : [],
        "feedback" : [],
        "overlay" : {
            "color"   : "#000000",
            "alpha"   : 0,
            "visible" : false
        },
        "avatars" : [
            {
                "node"     : 14,
                "type"     : "customer",
                "model"    : "",
                "behavior" : "Idle",
                "heading"  : 0,
                "velocity" : 0,
                "position" : [0.0, 0.0, 0.0],
                "offset"   : [0.0 ,0.0 ,0.0],
                "dOffset"  : 0,
                "mood"     : "Neutral",
                "depth"    : 1,
                "state"    : "Idle",
                "file"     : ""
            }
        ]
    };
    
    return plugins;
});
