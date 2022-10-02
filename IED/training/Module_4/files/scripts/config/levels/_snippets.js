define(function(require){ 
    var scenario = {
        "objects" : [
            {
                id    : "s09-cin01",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/s09_Cin01.mp4"
                }
            },
            
            {
                id  : "s09-intro",
                type: "popup",
                text: ""
            },
            
            {
                id   : "s09-start-screen",
                type : "image",
                src  : "files/assets/images/screens/placeholder.png"
            },
            

            {
                id   : "s09-dispatch-control-audio",
                type : "audio",
                file : "files/assets/audio/placeholder.mp3"
            },
            {
                id    : "s09-dispatch-control-text",
                type  : "narration",
                text  : ""
            },
            
            {
                id    : "s09-dispatch-response",
                type  : "narration",
                text  : ""
            },
            
            
            
            {
                id   : "s09-dp10",
                type : "dp",
                stem : "",
                options: [
                    "Confirm",
                    "Clear",
                    "Call",
                    "Cordon",
                    "Control"
                ],
                plugin: {
                    tracker: { id: "s09-control" },
                }
            },
            {
                id    : "s09-dp10-r01",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            },
            {
                id    : "s09-dp10-r02",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            },
            {
                id    : "s09-dp10-r03",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            },
            {
                id    : "s09-dp10-r04",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            },
            {
                id    : "s09-dp10-r05",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            },
            {
                id    : "s09-dp10-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            },
            
            
            
            {
                id   : "s09-dp10",
                type : "dp-multi",
                stem : "",
                answers: [],
                options: [],
                plugin: {
                    tracker: { id: "s09-control" }
                }
            },
            {
                id    : "s09-dp10-r01",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s09-control", state: "success", points: 10 },
                }
            },
            {
                id    : "s09-dp10-r02",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            },
            {
                id    : "s09-dp10-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 },
                }
            }
        ]
    };
    return scenario;
});
