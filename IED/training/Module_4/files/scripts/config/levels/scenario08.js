define(function (require) {
    'use strict';

    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');

    var scenario = {
        "id" : "scenario08",

        // -- SETTINGS --
        "fsm"          : 'scenario08',
        "scene"        : 'Road',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/Scenario08/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 90, // removed question 4
		"passingScore" : 80,

        // -- EVENT HANDLERS --
        "onLoad": function () {
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM(aden.fsm.scenario08);
            aden.plugin.radio.setEventName('radio-click');
        },

        "onPanoLoad": function () {
            aden.fsm.gameView.trigger('complete');
        },

        // -- GAME STATE --
        "state": {
            "modules" : {
                "clock" : {
                    "initTime"  : "08:25:00.00",
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
                id   : 's08-start-screen',
                type : 'image',
                src  : "files/assets/images/screens/scenario_08/intro.jpg"
            },
            {
                id   : 's08-bomb-tech',
                type : 'image',
                src  : "files/assets/images/screens/scenario_08/bomb-tech.jpg"
            },
			{
				id    : "s08-cin00",
				type  : "video",
				media : {
					'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin00.mp4'
				}
			},
            {
                id    : "s08-cin01",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin01.mp4'
                }
            },
            {
                id    : "s08-cin02",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin02.mp4'
                }
            },
            {
                id    : "s08-cin03",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin03.mp4'
                }
            },
            {
                id    : "s08-cin04",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin04.mp4'
                }
            },
			{
				id: "s08-cin04a",
				type: "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin04a.mp4'
                }
			},
            {
                id    : "s08-cin05",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin05.mp4'
                }
            },
            {
                id    : "s08-tech-positive",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin05a.mp4'
                }
            },
            {
                id    : "s08-tech-negative",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_08/S08_Cin05b.mp4'
                }
            },
            
            {
                id: "s08-intro-pop",
                type: "popup",
                title: "Welcome",
                text: "Your role in this scenario is that of a volunteer fire crew member responding to a report of a brush fire near the parking lot of a rest area that is in the vicinity of an outdoor amphitheater."
            },
            
            {
                id   : "s08-dispatch-call-audio",
                type : "audio",
                file : "files/assets/audio/dispatcher/S08_SS01.mp3"
            },
            {
                id    : "s08-dispatch-call-text",
                type  : "narration",
                text  : "Require fire response. Report of a small brush fire at the rest area near the amphitheater."
            },
            {
                id    : "s08-dispatch-response",
                type  : "narration",
                text  : "Click the microphone to respond."
            },
            {
                id   : "s08-dispatch-reply-audio",
                type : "audio",
                file : "files/assets/audio/dispatcher/S08_SS02.mp3"
            },
            {
                id    : "s08-dispatch-reply-text",
                type  : "narration",
                text  : "Response acknowledged."
            },
            {
                id    : "s08-dispatch-warning",
                type  : "narration",
                text  : "You did not respond to the dispatch call immediately. Click the microphone to respond."
            },
            
            {
                id: "s08-move-popup",
                type: "narration",
                text: "You are the first responder on the scene. Click on the arrow to move closer to the fire to investigate the cause and size of the fire."
            },
            {
                id: "s08-move-warning",
                type: "popup",
                text: "Click on the arrow to move closer to the fire to investigate the cause and size of the fire."
            },
            
            {
                id   : "s08-dp01",
                type : "dp",
                stem : "1. According to the Five Cs, what is the first thing you need to do if you suspect an IED?",
                options: [
                    "Confirm",
                    "Clear",
                    "Call",
                    "Cordon",
                    "Control"
                ],
                plugin: {
                    tracker: { id: "s08-confirm" }
                }
            },
            {
                id    : "s08-dp01-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The first of the Five Cs is to CONFIRM the IED threat.",
                plugin: {
                    tracker: { id: "s08-confirm", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp01-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp01-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp01-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp01-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp01-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-confirm", state: "failure", points: 0 }
                }
            },
            
            {
                id    : "s08-dp02-intro",
                type  : "narration",
                text  : "You have 60 seconds to perform a 360-degree assessment of this situation and confirm an IED threat."
            },

            {
                id   : "s08-dp02",
                type : "dp",
                stem : "2. What is the IED threat in this situation?",
                options: [
                    'Stand-off weapon and improvised launch vehicle.',
                    'Vehicle-borne IED.',
                    'Remote-control IED.',
                    'No threat exists.'
                ],
                plugin: {
                    tracker: { id: "s08-identify" }
                }
            },
            {
                id    : "s08-dp02-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The IED threat is a stand-off weapon and improvised launch vehicle. ",
                plugin: {
                    tracker: { id: "s08-identify", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp02-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The IED threat is a stand-off weapon and improvised launch vehicle.",
                plugin: {
                    tracker: { id: "s08-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp02-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The IED threat is a stand-off weapon and improvised launch vehicle.",
                plugin: {
                    tracker: { id: "s08-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp02-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The IED threat is a stand-off weapon and improvised launch vehicle.",
                plugin: {
                    tracker: { id: "s08-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp02-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-identify", state: "failure", points: 0 }
                }
            },

            {
                id   : "s08-dp03",
                type : "dp",
                stem : "3. You have confirmed there is a suspected IED: a round from a stand-off weapon. What is the next Five Cs action you should take?",
                options: [
                    'CONTROL the area.',
                    'CORDON the area to the recommended evacuation distance.',
                    'CALL in your IED confirmation and request assistance.',
                    'CLEAR the immediate area.'
                ],
                plugin: {
                    tracker: { id: "s08-clear" }
                }
            },
            {
                id    : "s08-dp03-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp03-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp03-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp03-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Your next action is to CLEAR the immediate area.",
                plugin: {
                    tracker: { id: "s08-clear", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp03-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-clear", state: "failure", points: 0 }
                }
            },
            
			/*
            {
                id   : "s08-dp04",
                type : "dp",
                stem : "You have confirmed a suspected IED. What is the next thing to do according to the Five Cs?",
                options: [
                    'CLEAR the area.',
                    'CALL in to higher command.',
                    'CONTROL the area.',
                    'CONFIRM all pedestrians are out of the area.'
                ],
                plugin: {
                    tracker: { id: "s08-call" }
                }
            },
            {
                id    : "s08-dp04-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once you have confirmed the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp04-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Once you have confirmed the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command.",
                plugin: {
                    tracker: { id: "s08-call", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp04-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once you have confirmed the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp04-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once you have confirmed the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s08-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp04-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-call", state: "failure", points: 0 }
                }
            },
			*/
			
            {
                id   : "s08-dp05-intro",
                type : "popup",
                text : "Your next step is to call in the IED threat. You need to suggest a recommended evacuation distance. Check the Bomb Threat Stand-Off Card or the Mapview to determine a recommended evacuation distance."
            },
            {
                id   : "s08-dp05",
                type : "dp",
                stem : "4. What is the recommended evacuation distance for this type of IED?",
                options: [
                    '2400 ft.',
                    '1200 ft.',
                    '640 ft.',
                    '150 ft.'
                ],
                plugin: {
                    tracker: { id: "s08-distance" }
                }
            },
            {
                id    : "s08-dp05-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s08-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp05-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s08-distance", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp05-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s08-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp05-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s08-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp05-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-distance", state: "failure", points: 0 }
                }
            },

            {
                id: "s08-dp06-intro",
                type: "narration",
                text: "You need to call in a report. First, take 60 seconds to make a secondary sweep of the area."
            },

            {
                id   : "s08-dp06",
                type : "dp-multi",
                stem : "5. What information do you need to report to higher command at this time? (Answer requires more than one selection.)",
                answers: [1, 1, 1, 0, 0],
                options: [
                    'Confirmed IED threat.',
                    'IED is a stand-off weapon.',
                    'Recommended evacuation distance is 1200 ft.',
                    'Recommended evacuation distance is 70 ft.',
                    'IED type is vehicle-borne.'
                ],
                plugin: {
                    tracker: { id: "s08-report" }
                }
            },
            {
                id    : "s08-dp06-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! You have provided a complete report of the IED threat and other key facts accurately and concisely.",
                plugin: {
                    tracker: { id: "s08-report", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp06-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. You have not provided a complete report of the IED threat and other key facts accurately and concisely.",
                plugin: {
                    tracker: { id: "s08-report", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp06-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-report", state: "failure", points: 0 }
                }
            },
            
            {
                id   : "s08-dp07",
                type : "dp",
                stem : "6. You have called in a report. What is the next action according to the Five Cs?",
                options: [
                    'CONTROL the area.',
                    'CORDON the area.',
                    'CALL in additional information.',
                    'CLEAR other pedestrians from the area.',
                    'ASSIST the search for the suspects.'
                ],
                plugin: {
                    tracker: { id: "s08-cordon" }
                }
            },
            {
                id    : "s08-dp07-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s08-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp07-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The next Five Cs action to be performed is to CORDON the area.",
                plugin: {
                    tracker: { id: "s08-cordon", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp07-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s08-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp07-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s08-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp07-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s08-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp07-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-cordon", state: "failure", points: 0 }
                }
            },
            {
                id   : "s08-dp07-response-audio",
                type : "audio",
                file : "files/assets/audio/dispatcher/S08_D07.mp3"
            },
            {
                id: "s08-dp07-response-text",
                type: "narration",
                text: "Clear your current position and assist with the cordon operation in the parking lot."
            },

            

            {
                id   : "s08-dp08",
                type : "dp",
                stem : "7. You have assisted with the cordoning of the parking lot area and are now at the police assembly point. What is the next action to be taken according to the Five Cs?",
                options: [
                    'CLEAR the scene and go home.',
                    'CLEAR pedestrians from around the assembly point.',
                    'RETURN to the location of the brush fire to help put it out.',
                    'CONTROL the area.'
                ],
                plugin: {
                    tracker: { id: "s08-control" }
                }
            },
            {
                id    : "s08-dp08-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s08-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp08-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s08-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp08-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s08-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s08-dp08-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. ",
                plugin: {
                    tracker: { id: "s08-control", state: "success", points: 10 }
                }
            },
            {
                id    : "s08-dp08-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-control", state: "failure", points: 0 }
                }
            },

            {
                id: "s08-dp09-intro",
                type: "narration",
                text: "Officer, I am the lead bomb tech. I need you to brief me on the IED threat situation."
            },

            {
                id   : "s08-dp09",
                type : "dp-multi",
                stem : "8. The Bomb Tech Lead asks you for a briefing on the threat situation. Select the information that should be included in your briefing. (Answer requires more than one selection.)",
                answers: [1, 1, 0],
                options: [
                    'Confirmed IED threat.',
                    'IED is a stand-off weapon located at the scenic rest stop and misfired round located nearby.',
                    'The brush fire damaged about a half acre of property.'
                ],
                plugin: {
                    tracker: { id: "s08-brief" }
                }
            },
            {
                id    : "s08-dp09-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct. Your brief should include confirmation of the threat and details of the IED type and location.",
                plugin: {
                    tracker: { id: "s08-brief", state: "success", points: 20 }
                }
            },
            {
                id    : "s08-dp09-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your brief should include confirmation of the threat and details of the IED type and location.",
                plugin: {
                    tracker: { id: "s08-brief", state: "failure", points: 0 }
                }
            },
            {
                id: "s08-dp09-success",
                type  : 'narration',
                text: "That’s good awareness and a complete briefing on your part, Officer."
            },
            {
                id: "s08-dp09-failure",
                type  : 'narration',
                text: "Your information is incomplete. I’ll have to send someone in to take a closer look."
            },
            {
                id    : "s08-dp09-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s08-brief", state: "failure", points: 0 }
                }
            }
        ],

        // LEVEL DATA FOR PLUGINS
        "plugin" : {
            "map" : {
                "image" : "files/assets/images/screens/scenario_01/OverheadMapCC.png",
                "scale" : 10, // feet per pixel
                "position" : {
                    top  : 186,
                    left : 419
                },
                "zone" : [
                    {
                        id        : "blast1",
                        name      : "Pipe Bomb",
                        inner     : 70,
                        outer     : 1200,
                        pos_inner : -29,
                        pos_outer : 105
                    },
                    {
                        id        : "blast2",
                        name      : "Suicide Bomber",
                        inner     : 110,
                        outer     : 1700,
                        pos_inner : -10,
                        pos_outer : 156
                    },
                    {
                        id        : "blast3",
                        name      : "Briefcase/Suitcase",
                        inner     : 150,
                        outer     : 1850,
                        pos_inner : -7,
                        pos_outer : 175
                    },
                    {
                        id        : "blast4",
                        name      : "Car",
                        inner     : 320,
                        outer     : 1900,
                        pos_inner : 9,
                        pos_outer : 180
                    },
                    {
                        id        : "blast5",
                        name      : "SUV/Van",
                        inner     : 400,
                        outer     : 2400,
                        pos_inner : 20,
                        pos_outer : 230
                    }
                ]
            },
            // -- REQUIREMENT TRACKING DATA --
            "tracker" : {
                "trackers": [
                    {
                        id    : "s08-respond",
                        title : "Respond to dispatch call",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-confirm",
                        title : "Confirm the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-identify",
                        title : "Identify the IED threat.",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-call",
                        title : "Call in to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-hazards",
                        title : "Conduct a threat/hazard assessment to identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-distance",
                        title : "Identify the recommended evacuation distance",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-report",
                        title : "Report to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-cordon",
                        title : "Cordon the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-control",
                        title : "Control the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s08-brief",
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
                    "name"      : "bathrooms",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function () {
                        aden.fsm.scenario08.trigger('move-bathrooms');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "charred",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function () {
                        aden.fsm.scenario08.trigger('move-charred');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "road",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function () {
                        aden.fsm.scenario08.trigger('move-road');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "barricades",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function () {
                        aden.fsm.scenario08.trigger('move-barricades');
                    }
                }
            ]
        }
    };

    return scenario;
});
