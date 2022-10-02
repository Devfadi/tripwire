define(function( require ) {
    var plugins = {
        "clock": {
            "selector": "#clock-view",
            "source": "files/templates/plugins/clock.html"
        },
        "status": {
            "id": "status-view",
            "source": "files/templates/plugins/status.html"
        },
        "radio": {
            "source": "files/templates/plugins/radio.html"
        },
        "tracker": {
            "id": 'tracker',
            "scoreId": 'points',
            // Display Text for each tracking state
            "states": {
                "incomplete" : "This task is incomplete",
                "started"    : "This task was started, but not completed",
                "ignored"    : "This task was ignored",
                "partial"    : "Partially completed",
                "success"    : "Completed Successfully",
                "failure"    : "Failed"
            }
        },
        "review": {
            "id": "review",
            'source': "files/templates/plugins/review.html"
        },
        "map": {
            'iconSource': "files/templates/plugins/map-icon.html",
            'mapSource': "files/templates/plugins/map-view.html"
        },
        
        
        "entities": {},
        "entityManager": {},
        "messages": [],
        "feedback": [],
        "overlay": {
            "color": "#000000",
            "alpha": 0,
            "visible": false
        },
        "avatars": [{
            "node"     : 14,
            "type"     : "customer",
            "model"    : "",
            "behavior" : "Idle",
            "heading"  : 0,
            "velocity" : 0,
            "position" : [0.0, 0.0, 0.0],
            "offset"   : [0.0, 0.0, 0.0],
            "dOffset"  : 0,
            "mood"     : "Neutral",
            "depth"    : 1,
            "state"    : "Idle",
            "file"     : ""
        }]
    };

    return plugins;
});
