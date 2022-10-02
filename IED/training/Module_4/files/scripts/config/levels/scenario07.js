define(function (require) {
    'use strict';

    var $        = require("jquery"),
        _        = require("lodash"),
        aden     = require("adayana/aden/engine"),
        debug    = require("adayana/debug/debug"),
        preload  = require("adayana/modules/preloadScreen"),
        mediator = require("adayana/modules/mediatorShim");

    var scenario = {
        "id" : "scenario07",

        // -- SETTINGS --
        "fsm"          : "scenario07",
        "scene"        : "outsidecar",
        "target"       : null,
        "xmlPath"      : "%HTMLPATH%/files/assets/panos/Scenario07/level.xml",
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 80,

        // -- EVENT HANDLERS --
        "onLoad": function () {
            preload.setMessage("Loading Panorama Environment");
            aden.plugin.radio.setFSM(aden.fsm.scenario07);
            aden.plugin.radio.setEventName("radio-click");
        },

        "onPanoLoad": function () {
            aden.fsm.gameView.trigger("complete");
        },

        // -- GAME STATE --
        "state": {
            "modules" : {
                "clock" : {
                    "initTime"  : "07:25:00.00",
                    "autoStart" : true,
                    "speed"     : 30,
                    "maxSpeed"  : 960,
                    "minSpeed"  : 1
                },
                "objects": {
                    "reset": true
                },
                "score": {
                    "points" : 0
                }
            }
        },

        // -- LEVEL VARIABLES --
        "variables" : [],

        // -- GAME OBJECTS --
        "objects" : [
            {
                id   : 's07-start-screen',
                type : 'image',
                src  : "files/assets/images/screens/scenario_07/intro.jpg"
            },
            {
                id   : 's07-bomb-tech',
                type : 'image',
                src  : "files/assets/images/screens/scenario_07/bomb-tech.jpg"
            },
            
            // video objects:
            {
                id    : "s07-cin01",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin01.mp4"
                }
            },
            {
                id    : "s07-cin02",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin02.mp4"
                }
            },
			{
				id: "s07-cin02-text",
				type: "narration",
				text: "The passengers got off the bus and away from the area as soon as I stopped and told them there’s a bomb on the bus. The bomb is on the floor, just inside the doors."
			},
            {
                id    : "s07-cin03",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin03.mp4"
                }
            },
            {
                id    : "s07-cin04",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin04.mp4"
                }
            },
            {
                id    : "s07-cin05",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin05.mp4"
                }
            },
            {
                id    : "s07-cin06",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin06.mp4"
                }
            },
            {
                id    : "s07-cin07",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin07.mp4"
                }
            },
            {
                id    : "s07-cin08",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin08.mp4"
                }
            },
            {
                id    : "s07-tech-positive",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin08a.mp4"
                }
            },
            {
                id    : "s07-tech-negative",
                type  : "video",
                media : {
                    "m4v": "files/assets/video/cinematics/scenario_07/S07_Cin08b.mp4"
                }
            },

            // intro:
            {
                id  : "s07-intro",
                type: "popup",
                text: "Your role in this scenario is that of a police officer on patrol in an urban downtown environment."
            },

            // dispatcher:
            {
                id   : "s07-dispatch-call-audio",
                type : "audio",
                file : "files/assets/audio/dispatcher/S07_SS.mp3"
            },
            {
                id    : "s07-dispatch-call-text",
                type  : "narration",
                text  : "All units in the area of downtown, respond to a suspicious package in a city bus. Reportee is the bus driver. Package is a computer bag with visible wires."
            },
            {
                id    : "s07-dispatch-response",
                type  : "narration",
                text  : "Click the microphone to respond to the dispatch call."
            },

            {
                id    : "s07-dispatch-warning",
                type  : "popup",
                title : "Warning",
                text  : "You did not respond to the dispatch call immediately. Click the microphone to respond."
            },
            {
                id  : "s07-dispatch-reply-audio",
                type: "audio",
                file: "files/assets/audio/dispatcher/Response_Acknowledged.mp3"
            },
            {
                id    : "s07-dispatch-reply-text",
                type  : "narration",
                text  : "Response acknowledged."
            },

            {
                id    : "s07-arrival-text",
                type  : "narration",
                text  : "You are the first responder on the scene. Click on the arrow to approach the bus driver and get information."
            },
            {
                id   : 's07-arrival-warning',
                type : 'popup',
                text : 'Click on the arrow to approach the bus driver and get information.'
            },

            {
                id   : "s07-dp01",
                type : "dp",
                stem : "1. The bus driver says there is a bomb aboard the bus. What do the Five Cs tell you is the first thing you should do?",
                options: [
                    "CONFIRM the IED threat.",
                    "CLEAR the immediate area around the IED.",
                    "CALL to report the IED threat to higher command.",
                    "CORDON the area to the recommended evacuation distance.",
                    "CONTROL the area."
                ],
                plugin: {
                    tracker: { id: "s07-confirm" }
                }
            },
            {
                id    : "s07-dp01-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The first step is to CONFIRM the presence of a suspected IED.",
                plugin: {
                    tracker: { id: "s07-confirm", state: "success", points: 10 }
                }
            },
            {
                id    : "s07-dp01-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first step is to CONFIRM the presence of a suspected IED. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp01-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first step is to CONFIRM the presence of a suspected IED. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp01-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first step is to CONFIRM the presence of a suspected IED. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp01-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first step is to CONFIRM the presence of a suspected IED. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp01-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.",
                plugin: {
                    tracker: { id: "s07-confirm", state: "failure", points: 0 }
                }
            },

            {
                id   : "s07-bus-door-nav",
                type : "narration",
                text : "Click the arrow to investigate further."
            },
            {
                id   : "s07-bus-door-warning",
                type : "popup",
                title: "warning",
                text : "Click on the arrow to investigate the suspicious package."
            },

            {
                id   : "bus-investigation",
                type : "narration",
                text : "You have 60 seconds to investigate."
            },
            
            {
                id   : "s07-dp02",
                type : "dp",
                stem : "2. Based on what you observed, what is the most likely type of IED you are dealing with?",
                options: [
                    'Remote-Control IED.',
                    'Vehicle-Borne IED.',
                    'Person-Borne IED.',
                    'Stand-off weapon.'
                ],
                plugin: {
                    tracker: { id: "s07-identify" }
                }
            },
            {
                id    : "s07-dp02-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The cell phone indicates that this is likely to be a remote-control IED.",
                plugin: {
                    tracker: { id: "s07-identify", state: "success", points: 10 }
                }
            },
            {
                id    : "s07-dp02-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The cell phone indicates that this is likely to be a remote-control IED.",
                plugin: {
                    tracker: { id: "s07-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp02-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The cell phone indicates that this is likely to be a remote-control IED.",
                plugin: {
                    tracker: { id: "s07-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp02-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The cell phone indicates that this is likely to be a remote-control IED.",
                plugin: {
                    tracker: { id: "s07-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp02-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-identify", state: "failure", points: 0 }
                }
            },

            {
                id   : "s07-dp03",
                type : "dp",
                stem : "3. You have confirmed there is a suspected remote-control IED aboard the bus. What is the next Five Cs action you should take?",
                options: [
                    'CONTROL the area.',
                    'CORDON the area to the recommended evacuation distance.',
                    'CALL in your IED confirmation and request assistance.',
                    'CLEAR the immediate area around the bus.'
                ],
                plugin: {
                    tracker: { id: "s07-clear" }
                }
            },
            {
                id    : "s07-dp03-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp03-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp03-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp03-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Your next action is to CLEAR the immediate area.",
                plugin: {
                    tracker: { id: "s07-clear", state: "success", points: 10 }
                }
            },
            {
                id    : "s07-dp03-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-clear", state: "failure", points: 0 }
                }
            },
            
            {
                id   : "s07-dp04",
                type : "dp",
                stem : "4. What should you do?",
                options: [
                    'Get back into the patrol car and drive to a safe zone.',
                    'Stay in position and maintain close contact with the bus and suspected IED.',
                    'Shelter-in-place while keeping visual contact with the bus and suspected IED.'
                ],
                plugin: {
                    tracker: { id: "s07-shelter" }
                }
            },
            {
                id    : "s07-dp04-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. You need to maintain visual contact, but shelter-in-place to protect yourself.",
                plugin: {
                    tracker: { id: "s07-shelter", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp04-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. You need to maintain visual contact, but shelter-in-place to protect yourself.",
                plugin: {
                    tracker: { id: "s07-shelter", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp04-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! You need to maintain visual contact, but shelter-in-place to protect yourself.",
                plugin: {
                    tracker: { id: "s07-shelter", state: "success", points: 5 }
                }
            },
            {
                id    : "s07-dp04-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-shelter", state: "failure", points: 0 }
                }
            },

            

            {
                id   : "s07-dp05",
                type : "dp",
                stem : "5. You have cleared the pedestrians from the immediate area around the suspected IED and sheltered-in-place. What is the next thing to do according to the Five Cs?",
                options: [
                    'Call in to higher command.',
                    'Control the area.',
                    'Confirm all pedestrians are out of the area.',
                    'Clear the surrounding buildings.'
                ],
                plugin: {
                    tracker: { id: "s07-call" }
                }
            },
            {
                id    : "s07-dp05-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The next step in the Five Cs protocol is to CALL the threat in to higher command.",
                plugin: {
                    tracker: { id: "s07-call", state: "success", points: 10 }
                }
            },
            {
                id    : "s07-dp05-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp05-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp05-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s07-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp05-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-call", state: "failure", points: 0 }
                }
            },
            
            {
                id   : "s07-dp06",
                type : "dp",
                stem : "6. You have recognized that the next step in the Five Cs is to call higher command with information about the situation. Now what should you do?",
                options: [
                    'CONTROL the area.',
                    'CORDON the area.',
                    'CONDUCT a detailed 360-degree threat/hazard assessment.'
                ],
                plugin: {
                    tracker: { id: "s07-assess" }
                }
            },
            {
                id    : "s07-dp06-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next step is to perform a threat/hazard assessment.",
                plugin: {
                    tracker: { id: "s07-assess", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp06-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next step is to perform a threat/hazard assessment.",
                plugin: {
                    tracker: { id: "s07-assess", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp06-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The next step is to perform a threat/hazard assessment.",
                plugin: {
                    tracker: { id: "s07-assess", state: "success", points: 5 }
                }
            },
            {
                id    : "s07-dp06-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-assess", state: "failure", points: 0 }
                }
            },


            {
                id : "s07-threat-assess",
                type: "narration",
                text: "Perform a 360-degree threat/hazard assessment. You have 60 seconds."
            },

            {
                id   : "s07-dp07",
                type : "dp-multi",
                stem : "7. You have performed a 360-degree threat/hazard assessment. Which items in the list are threats/hazards in this situation? (Answer requires more than one selection.)",
                answers: [1, 1, 0, 0],
                options: [
                    'Windows in buildings.',
                    'Shrapnel from the bus and IED.',
                    'Overhead power lines.',
                    'Storm sewers.'
                ],
                plugin: {
                    tracker: { id: "s07-hazards" }
                }
            },
            {
                id    : "s07-dp07-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The threats/hazards in the area include the windows in surrounding buildings, and shrapnel from the bus and IED.",
                plugin: {
                    tracker: { id: "s07-hazards", state: "success", points: 10 }
                }
            },
            {
                id    : "s07-dp07-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The threats/hazards in the area include the windows in surrounding buildings, and shrapnel from the bus and IED.",
                plugin: {
                    tracker: { id: "s07-hazards", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp07-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-hazards", state: "failure", points: 0 }
                }
            },
            
            {
                id   : "s07-dp08",
                type : "dp",
                stem : "8. You have identified threats and hazards in the area. What action should you take next?",
                options: [
                    'Identify the recommended evacuation distance.',
                    'Cordon the area.',
                    'Control the area.',
                    'Take the suspected IED handler into custody.'
                ],
                plugin: {
                    tracker: { id: "s07-recommend" }
                }
            },
            {
                id    : "s07-dp08-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The next action you should take is to identify the recommended evacuation distance.",
                plugin: {
                    tracker: { id: "s07-recommend", state: "success", points: 5 }
                }
            },
            {
                id    : "s07-dp08-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next action you should take is to identify the recommended evacuation distance.",
                plugin: {
                    tracker: { id: "s07-recommend", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp08-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next action you should take is to identify the recommended evacuation distance.",
                plugin: {
                    tracker: { id: "s07-recommend", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp08-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next action you should take is to identify the recommended evacuation distance.",
                plugin: {
                    tracker: { id: "s07-recommend", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp08-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-recommend", state: "failure", points: 0 }
                }
            },


            {
                id    : "s07-dp09-intro",
                type  : "popup",
                title : "Information",
                text  : "Use the Mapview tool or the Bomb Threat Stand-Off Card job aid to identify the recommended evacuation distance."
            },

            {
                id   : "s07-dp09",
                type : "dp",
                stem : "9. What is the recommended evacuation distance for this type of IED?",
                options: [
                    '320 ft.',
                    '1200 ft.',
                    '1850 ft.',
                    '3800 ft.'
                ],
                plugin: {
                    tracker: { id: "s07-distance" }
                }
            },
            {
                id    : "s07-dp09-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The recommended evacuation distance for this type of IED is 1850 ft.",
                plugin: {
                    tracker: { id: "s07-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp09-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The recommended evacuation distance for this type of IED is 1850 ft.",
                plugin: {
                    tracker: { id: "s07-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp09-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The recommended evacuation distance for this type of IED is 1850 ft.",
                plugin: {
                    tracker: { id: "s07-distance", state: "success", points: 5 }
                }
            },
            {
                id    : "s07-dp09-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The recommended evacuation distance for this type of IED is 1850 ft.",
                plugin: {
                    tracker: { id: "s07-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp09-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-distance", state: "failure", points: 0 }
                }
            },

            {
                id   : "s07-dp10-intro",
                type : "narration",
                text : "You are preparing to call a situation report to higher command. Take 60 seconds to make a secondary sweep of the area to ensure you have identified all of the threats, including any secondary devices."
            },
            
            {
                id   : "s07-dp10",
                type : "dp-multi",
                stem : "10. What information do you need to report to higher command at this time? (Answer requires more than one selection.)",
                answers: [1, 1, 1, 1, 0, 0],
                options: [
                    'Confirmed IED threat on a city bus.',
                    'IED is a remote-control type in a computer bag.',
                    'Threats and hazards include windows in surrounding buildings and shrapnel from the bus and IED.',
                    'Recommended evacuation distance is 1850 ft.',
                    'Recommended evacuation distance is 320 ft.',
                    'IED type is vehicle-borne.'
                ],
                plugin: {
                    tracker: { id: "s07-report" }
                }
            },
            {
                id    : "s07-dp10-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! You have provided a complete report of the IED threat and other key facts accurately and concisely.",
                plugin: {
                    tracker: { id: "s07-report", state: "success", points: 10 }
                }
            },
            {
                id    : "s07-dp10-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. You have not provided a complete report of the IED threat and other key facts accurately and concisely.",
                plugin: {
                    tracker: { id: "s07-report", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp10-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-report", state: "failure", points: 0 }
                }
            },

            {
                id   : "s07-dp11",
                type : "dp",
                stem : "11. You have called in a report. What is the next action according to the Five Cs?",
                options: [
                    'Control the area.',
                    'Cordon the area.',
                    'Call in additional information.',
                    'Clear other pedestrians from the area.',
                    'Confirm help is on the way.'
                ],
                plugin: {
                    tracker: { id: "s07-cordon" }
                }
            },
            {
                id    : "s07-dp11-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s07-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp11-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The next Five Cs action to be performed is to CORDON the area.",
                plugin: {
                    tracker: { id: "s07-cordon", state: "success", points: 5 }
                }
            },
            {
                id    : "s07-dp11-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s07-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp11-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s07-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp11-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s07-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp11-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-cordon", state: "failure", points: 0 }
                }
            },

            {
                id: "s07-dp11-response-audio",
                type: "audio",
                file: "files/assets/audio/dispatcher/S07_D09.mp3"
            },
            {
                id: "s07-dp11-response-text",
                type: "narration",
                text: "Suspect in custody. Clear your current position and assist with cordon operation."
            },

            {
                id   : "s07-dp12",
                type : "dp",
                stem : "12. You have assisted with the cordoning of the area and are now at the police assembly point. What is the next action to be taken according to the Five Cs?",
                options: [
                    'Confirm all pedestrians are out of the cordoned area.',
                    'Clear pedestrians from around the assembly point.',
                    'Call in to provide supplemental information.',
                    'Control the area.'
                ],
                plugin: {
                    tracker: { id: "s07-control" }
                }
            },
            {
                id    : "s07-dp12-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s07-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp12-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s07-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp12-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s07-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp12-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. ",
                plugin: {
                    tracker: { id: "s07-control", state: "success", points: 5 }
                }
            },
            {
                id    : "s07-dp12-r05",
                type  : "popup",
                title : "Feedback",
                text  : "",
                plugin: {
                    tracker: { id: "s07-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp12-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-control", state: "failure", points: 0 }
                }
            },
            {
                id   : 's07-dp13-intro-text',
                type : 'narration',
                text : 'Officer, I am the lead bomb tech. I need you to brief me on the IED threat situation.'
            },

            {
                id   : "s07-dp13",
                type : "dp-multi",
                stem : "13. The Bomb Tech Lead asks you for a briefing on the threat situation. Select the information that should be included in your briefing. (Answer requires more than one selection.)",
                answers: [1, 1, 1, 1, 1, 0],
                options: [
                    'Confirmed IED threat.',
                    'Location is on the floor just inside the door of a city bus.',
                    'IED is a remote-control type in a computer bag.',
                    'Visible components are the bag container and the cell phone switch.',
                    'Threats and hazards include glass from buildings and shrapnel from the bus and IED.',
                    'Main charge is C4 plastic explosive.'
                ],
                plugin: {
                    tracker: { id: "s07-brief" }
                }
            },
            {
                id    : "s07-dp13-r01",
                type  : 'narration',
                title : "Feedback",
                text  : "That’s good awareness and a complete briefing on your part, Officer.",
                plugin: {
                    tracker: { id: "s07-brief", state: "success", points: 10 }
                }
            },
            {
                id    : "s07-dp13-r02",
                type  : 'narration',
                title : "Feedback",
                text  : "Your information is incomplete. I’ll have to send someone in to take a closer look.",
                plugin: {
                    tracker: { id: "s07-brief", state: "failure", points: 0 }
                }
            },
            {
                id    : "s07-dp13-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s07-brief", state: "failure", points: 0 }
                }
            }
        ],

        // LEVEL DATA FOR PLUGINS
        "plugin" : {
            "map" : {
                "image" : "files/assets/images/screens/scenario_01/OverheadMapCC.png",
                "scale" : 10, // feet per pixel
                "position" : {
                    top  : 220,
                    left : 769
                },
                "zone" : [
                    {
                        id        : "blast1",
                        name      : "Pipe Bomb",
                        inner     : 70,
                        outer     : 1200,
                        pos_inner : -107,
                        pos_outer : -220
                    },
                    {
                        id        : "blast2",
                        name      : "Suicide Bomber",
                        inner     : 110,
                        outer     : 1700,
                        pos_inner : -110,
                        pos_outer : -270
                    },
                    {
                        id        : "blast3",
                        name      : "Briefcase/Suitcase",
                        inner     : 150,
                        outer     : 1850,
                        pos_inner : -115,
                        pos_outer : -285
                    },
                    {
                        id        : "blast4",
                        name      : "Car",
                        inner     : 320,
                        outer     : 1900,
                        pos_inner : -131,
                        pos_outer : -290
                    },
                    {
                        id        : "blast5",
                        name      : "SUV/Van",
                        inner     : 400,
                        outer     : 2400,
                        pos_inner : -140,
                        pos_outer : -339
                    }
                ]
            },
            // -- REQUIREMENT TRACKING DATA --
            "tracker" : {
                "trackers": [
                    {
                        id    : "s07-respond",
                        title : "Respond to dispatch call",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-confirm",
                        title : "Confirm the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-identify",
                        title : "Identify IED type",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-shelter",
                        title : "Shelter in Place",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-call",
                        title : "Call in to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-assess",
                        title : "Conduct a threat/hazard assessment.",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-hazards",
                        title : "Identify threats/hazards in the area.",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-recommend",
                        title : "Identify the recommended evacuation distance.",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-distance",
                        title : "Identify safe stand-off distance and recommend cordon perimeter.",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-report",
                        title : "Report to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-cordon",
                        title : "Cordon the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-control",
                        title : "Control the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s07-brief",
                        title : "Brief the Bomb Tech Lead",
                        state : "incomplete"
                    }
                ]
            },
            // GENERIC FEEDBACK STRINGS
            "feedback": {}
        },

        // DATA FOR TIMED EVENT MODULE
        "timedEvents" : [],

        // ENVIRONMENT DATA FOR KRPANO MODULE
        "pano": {
            "areaData": [],
            "scenes": [
                {
                    "num"       : 0,
                    "name"      : "patrolcar",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function () {
                        aden.fsm.scenario07.trigger("move-patrolcar");
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "outsidecar",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function () {
                        aden.fsm.scenario07.trigger("move-outsidecar");
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "sidewalk",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function () {
                        aden.fsm.scenario07.trigger("move-sidewalk");
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "busdoor",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function () {
                        aden.fsm.scenario07.trigger("move-busdoor");
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "barricades",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function () {
                        aden.fsm.scenario07.trigger("move-barricades");
                    }
                }
            ]
        }
    };

    return scenario;
});
