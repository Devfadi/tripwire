define(function(require){
    var objects = [
        {
            id    : "",
            type  : "overlay"            
        },
        {
            id    : "",
            type  : "image",
            src   : "",
            css   : {
                'left'    : '320px',
                'z-index' : 50,
                'top'     : '0px'
            }
        },
        {
            id      : "",
            type    : "bubble",
            content : "",
            options : {
                "top"           : "93px",
                "left"          : "118px",
                "width"         : "500px",
                "arrowPosition" : "right-middle",
                "arrowOffset"   : 0,
                "arrowBase"     : 12,
                "arrowLength"   : 50
            }
        },
        {
            id   : "",
            type : "audio",
            file : ""
        },
        {
            id : "",
            type : "video",
            source : [
                {
                    "file" : "files/assets/video/video.mp4",
                    'type' : "video/mp4"
                }
            ],
            loop            : false,
            stopOnLastFrame : false,
            showControls    : false,
            keepVisible     : false,
            keepActive      : false,
            stopClock       : true
        },
        {
            id: "",
            type: "tab_pop",
            title: "",
            tabs  : [
                {
                    id    : "",
                    title : "",
                    text  : ""
                },
                {
                    id    : "",
                    title : "",
                    text  : ""
                },
                {
                    id    : "",
                    title : "",
                    text  : ""
                },
                {
                    id    : "",
                    title : "",
                    text  : ""
                }
            ]
        },
        {
            id    : "",
            type  : "popup",
            title : "",
            text  : ""
        },
        {
            id      : "",
            type    : "scorePopup",
            title   : "",
            stem    : "",
            options : [
                {
                    text  : "",
                    event : "branch1"
                }
            ]
        },
        {
            id      : "",
            type    : "dp",
            stem    : "",
            options : [
                "option01",
                "option02",
                "option03"
            ]
        },
        {
            id      : "",
            type    : "dp_popup",
            title   : "",
            stem    : "",
            options : [
                {
                    text  : "",
                    event : "branch1"
                },
                {
                    text  : "",
                    event : "branch2"
                }
            ]
        },
        {
            id      : "",
            type    : "dp_managed",
            stem    : "",
            getOptionArray : Actions.dailyMeeting.getOptionArray,
            setOptionState : Actions.dailyMeeting.setOption,
            options : [
                {
                    text  : "",
                    event : "branch1"
                },
                {
                    text  : "",
                    event : "branch2"
                }
            ]
        },
        {
            id             : "",
            type           : "dp_multimanaged",
            title          : "",
            stem           : "",
            min            : 1,
            max            : 2,
            action         : Actions.inventory.processSelectionA,
            getOptionArray : Actions.inventory.getOptionArray,
            setOptionState : Actions.inventory.setOption,
            options : [
                {
                    text  : "",
                    event : "mark"
                },
                {
                    text  : "",
                    event : "Chris"
                }
            ]
        },
        {
            id         : "",
            type       : "dp_timed",
            title      : "",
            stem       : "",
            targetTime : "18:00:00",
            options    : [
                {
                    text  : "",
                    event : "branch1"
                },
                {
                    text  : "",
                    event : "branch2"
                }
            ]
        },
    ];
    return objects;
});
