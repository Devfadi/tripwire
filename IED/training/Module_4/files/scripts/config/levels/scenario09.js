define(function (require) {
    'use strict';

    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');

    var scenario = {
        // -- ID --
        "id" : "scenario09",

        // -- SETTINGS --
        "fsm"          : 'scenario09',
        "scene"        : 'rural',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/Scenario09/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 80,

        // -- EVENT HANDLERS --
        "onLoad": function () {
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM(aden.fsm.scenario09);
            aden.plugin.radio.setEventName('radio-click');
        },
        "onPanoLoad": function () {
            aden.fsm.gameView.trigger('complete');
        },

        // -- GAME STATE --
        
        "state": {
            "modules" : {
                "clock" : {
                    "initTime"  : "09:25:00.00",
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
            // Still Images
            {
                id   : 's09-bomb-tech',
                type : 'image',
                src  : "files/assets/images/screens/scenario_09/bomb-tech.jpg"
            },
            
            // Cinematics
            {
                id    : "s09-cin01",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin01.mp4'
                }
            },
            {
                id    : "s09-cin02",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin02.mp4'
                }
            },
            {
                id    : "s09-cin03",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin03.mp4'
                }
            },
            {
                id    : "s09-cin04",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin04.mp4'
                }
            },
            {
                id    : "s09-cin05",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin05.mp4'
                }
            },
            {
                id    : "s09-cin06",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin06.mp4'
                }
            },
            {
                id    : "s09-tech-positive",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin05a.mp4'
                }
            },
            {
                id    : "s09-tech-negative",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_09/S09_Cin05b.mp4'
                }
            },

            {
                id: "s09-intro-popup",
                type: "popup",
                text: "Your role in this scenario is that of a police officer dispatched to investigate a report of an unknown disturbance in the parking lot at the outdoor amphitheater."
            },

            {
                id   : "s09-dispatch-call-audio",
                type : "audio",
                file : "files/assets/audio/dispatcher/S09_SS01.mp3"
            },
            {
                id    : "s09-dispatch-call-text",
                type  : "narration",
                text  : "Any unit in the vicinity of the outdoor amphitheater, respond to a report of an unknown disturbance in the amphitheater parking lot. Reportee reports multiple vehicles have been damaged and one may be on fire."
            },
            {
                id    : "s09-dispatch-response",
                type  : "narration",
                text  : "Click the microphone to respond."
            },
            {
                id   : "s09-dispatch-reply-audio",
                type : "audio",
                file : "files/assets/audio/dispatcher/S09_SS02.mp3"
            },
            {
                id    : "s09-dispatch-reply-text",
                type  : "narration",
                text  : "Response acknowledged."
            },
            {
                id    : "s09-dispatch-warning",
                type  : "narration",
                text  : "You did not respond to the dispatch call immediately. Click the microphone to respond."
            },

            {
                id: 's09-arrival',
                type: 'narration',
                text: 'You are the first responder on the scene. Click on the arrow to move closer and investigate this disturbance.'
            },
            {
                id: 's09-arrival-warning',
                type: 'popup',
                text: 'Click on the arrow to move closer and investigate this disturbance.'
            },
			
			{
				id: 's09-dp01-intro-text',
				type: 'narration',
				text: "I'm glad you're here. It looks like someone must have thrown some type of bomb through the back window of my car."
			},
            {
                id   : "s09-dp01",
                type : "dp",
                stem : "1. This car has been hit by a projectile. According to the Five Cs protocol, what is the first thing you need to do if you suspect an IED?",
                options: [
                    "Confirm",
                    "Clear",
                    "Call",
                    "Cordon",
                    "Control"
                ],
                plugin: {
                    tracker: { id: "s09-confirm" }
                }
            },
            {
                id    : "s09-dp01-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The first of the Five Cs is to CONFIRM the IED threat.",
                plugin: {
                    tracker: { id: "s09-confirm", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp01-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp01-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp01-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp01-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The first of the Five Cs is to CONFIRM the IED threat. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp01-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-confirm", state: "failure", points: 0 }
                }
            },

            {
                id: "s09-dp02-intro",
                type: 'narration',
                text: 'You have 60 seconds to perform a 360-degree assessment of this situation and confirm an IED threat.'
            },
            {
                id   : "s09-dp02",
                type : "dp",
                stem : "2. What is the IED threat in this situation?",
                options: [
                    'Unexploded round from a stand-off weapon.',
                    'Pipe bomb.',
                    'Remote-control IED.',
                    'No threat exists.'
                ],
                plugin: {
                    tracker: { id: "s09-identify" }
                }
            },
            {
                id    : "s09-dp02-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The IED threat is an unexploded round from a stand-off weapon.",
                plugin: {
                    tracker: { id: "s09-identify", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp02-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The IED threat is an unexploded round from a stand-off weapon.",
                plugin: {
                    tracker: { id: "s09-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp02-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The IED threat is an unexploded round from a stand-off weapon.",
                plugin: {
                    tracker: { id: "s09-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp02-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The IED threat is an unexploded round from a stand-off weapon.",
                plugin: {
                    tracker: { id: "s09-identify", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp02-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-identify", state: "failure", points: 0 }
                }
            },

            {
                id   : "s09-dp03",
                type : "dp",
                stem : "3. You have confirmed a threat from a stand-off weapon. What is the next action prescribed by the Five Cs protocol?",
                options: [
                    'CONTROL the area.',
                    'CORDON the area to the recommended evacuation distance.',
                    'CALL in your IED confirmation and request assistance.',
                    'CLEAR the immediate area around the car.'
                ],
                plugin: {
                    tracker: { id: "s09-clear" }
                }
            },
            {
                id    : "s09-dp03-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp03-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp03-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your next action is to CLEAR the immediate area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp03-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Your next action is to CLEAR the immediate area.",
                plugin: {
                    tracker: { id: "s09-clear", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp03-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-clear", state: "failure", points: 0 }
                }
            },

            

            {
                id   : "s09-dp04",
                type : "dp",
                stem : "4. You have confirmed the IED threat and cleared people from the immediate area. What is the next step to be performed according to the Five Cs?",
                options: [
                    "Call",
                    "Confirm",
                    "Clear",
                    "Cordon",
                    "Control"
                ],
                plugin: {
                    tracker: { id: "s09-call" }
                }
            },
            {
                id    : "s09-dp04-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Once you have confirmed the IED threat and cleared people from the immediate area, the next of the Five Cs is to CALL in the threat to higher command.",
                plugin: {
                    tracker: { id: "s09-call", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp04-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once you have confirmed the IED threat and cleared people from the immediate area, the next of the Five Cs is to CALL in the threat to higher command.  You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp04-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once you have confirmed the IED threat and cleared people from the immediate area, the next of the Five Cs is to CALL in the threat to higher command.  You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp04-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once you have confirmed the IED threat and cleared people from the immediate area, the next of the Five Cs is to CALL in the threat to higher command.  You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp04-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once you have confirmed the IED threat and cleared people from the immediate area, the next of the Five Cs is to CALL in the threat to higher command.  You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.",
                plugin: {
                    tracker: { id: "s09-call", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp04-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-call", state: "failure", points: 0 }
                }
            },

            {
                id: "s09-dp05-intro",
                type: 'popup',
                text: 'Your next step is to call in the IED threat to higher command. You need to suggest a recommended evacuation distance. Check the Bomb Threat Stand-Off Card or the Mapview to determine a recommended evacuation distance.'
            },
            {
                id   : "s09-dp05",
                type : "dp",
                stem : "5. What is the recommended evacuation distance for this type of IED?",
                options: [
                    '400 ft.',
                    '640 ft.',
                    '1200 ft.',
                    '3800 ft.'
                ],
                plugin: {
                    tracker: { id: "s09-distance" }
                }
            },
            {
                id    : "s09-dp05-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect! The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s09-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp05-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect! The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s09-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp05-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s09-distance", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp05-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect! The recommended evacuation distance for this type of IED is at least 1200 ft.",
                plugin: {
                    tracker: { id: "s09-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp05-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-distance", state: "failure", points: 0 }
                }
            },

            {
                id: "s09-dp06-intro",
                type: "narration",
                text: "You need to call in a report. First, take 60 seconds to make a secondary sweep of the area."
            },
            {
                id   : "s09-dp06",
                type : "dp-multi",
                stem : "6. You need to call in to report the IED threat situation to higher command. Which information will you call in? (Answer requires more than one selection.)",
                answers: [1, 1, 1, 1, 0],
                options: [
                    'Confirmed IED threat is a stand-off weapon.',
                    'Location is the parking lot at the outdoor amphitheater.',
                    'An unexploded round is lodged in the rear window of a car.',
                    'Recommended evacuation distance is 1200 ft.',
                    'The distance from the parking lot to police headquarters is 12 miles.'
                ],
                plugin: {
                    tracker: { id: "s09-report" }
                }
            },
            {
                id    : "s09-dp06-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Your report should confirm the IED threat, describe the IED, provide the location of the IED, and recommend the recommended evacuation distance.",
                plugin: {
                    tracker: { id: "s09-report", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp06-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your report should confirm the IED threat, describe the IED, provide the location of the IED, and recommend the recommended evacuation distance.",
                plugin: {
                    tracker: { id: "s09-report", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp06-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-report", state: "failure", points: 0 }
                }
            },

            {
                id   : "s09-dp07",
                type : "dp",
                stem : "7. You have called in a report. What is the next action according to the Five Cs?",
                options: [
                    'CONTROL the area.',
                    'CORDON the area.',
                    'CALL in additional information.',
                    'CLEAR other pedestrians from the area.',
                    'ASSIST the search for the suspects.'
                ],
                plugin: {
                    tracker: { id: "s09-cordon" }
                }
            },
            {
                id    : "s09-dp07-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s09-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp07-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! The next Five Cs action to be performed is to CORDON the area. ",
                plugin: {
                    tracker: { id: "s09-cordon", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp07-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s09-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp07-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s09-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp07-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.",
                plugin: {
                    tracker: { id: "s09-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp07-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-cordon", state: "failure", points: 0 }
                }
            },
            
            {
                id: "s09-dp07-response-audio",
                type: "audio",
                file: "files/assets/audio/dispatcher/S09_D07.mp3"
            },
            {
                id: "s09-dp07-response-text",
                type: "narration",
                text: "Clear your current position and assist with the cordon operation."
            },

            

            {
                id   : "s09-dp08",
                type : "dp",
                stem : "8. You have assisted with the cordoning of the area to the recommended evacuation distance and are now at the police assembly point. What is the next action to be taken according to the Five Cs?",
                options: [
                    "Confirm",
                    "Clear",
                    "Call",
                    "Cordon",
                    "Control"
                ],
                plugin: {
                    tracker: { id: "s09-control" }
                }
            },
            {
                id    : "s09-dp08-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp08-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp08-r03",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp08-r04",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. You should review the Five Cs job aid in the Resources section for more information on controlling the area.",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 }
                }
            },
            {
                id    : "s09-dp08-r05",
                type  : "popup",
                title : "Feedback",
                text  : "Correct! Once the area is cordoned at the recommended evacuation distance, the next step in the Five Cs is to CONTROL the area. ",
                plugin: {
                    tracker: { id: "s09-control", state: "success", points: 10 }
                }
            },
            {
                id    : "s09-dp08-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-control", state: "failure", points: 0 }
                }
            },
			
			{
                id: "s09-dp09-intro",
                type: "narration",
                text: "Officer, I am the lead bomb tech. I need you to brief me on the IED threat situation."
            },

            {
                id   : "s09-dp09",
                type : "dp-multi",
                stem : "9. The Bomb Tech Lead asks you for a briefing on the threat situation. Select the information that should be included in your briefing. (Answer requires more than one selection.)",
                answers: [1, 1, 0, 0],
                options: [
                    'Confirmed IED threat.',
                    'IED is an unexploded round from a stand-off weapon that is lodged in the rear window of a car in the parking lot.',
                    'The IED is no longer a threat.',
                    'Pedestrians would like to return to the parking lot and retrieve their cars.'
                ],
                plugin: {
                    tracker: { id: "s09-brief" }
                }
            },
            {
                id    : "s09-dp09-r01",
                type  : "popup",
                title : "Feedback",
                text  : "Correct. Your brief should include confirmation of the threat and details of the IED type and location.",
                plugin: {
                    tracker: { id: "s09-brief", state: "success", points: 20 }
                }
            },
            {
                id    : "s09-dp09-r02",
                type  : "popup",
                title : "Feedback",
                text  : "Incorrect. Your brief should include confirmation of the threat and details of the IED type and location.",
                plugin: {
                    tracker: { id: "s09-brief", state: "failure", points: 0 }
                }
            },
            {
                id: "s09-dp09-success",
                type  : 'narration',
                text: "That’s good awareness and a complete briefing on your part, Officer."
            },
            {
                id: "s09-dp09-failure",
                type  : 'narration',
                text: "Your information is incomplete. I’ll have to send someone in to take a closer look."
            },
            {
                id    : "s09-dp09-warning",
                type  : "popup",
                title : "Warning",
                text  : "You need to make a decision.",
                plugin: {
                    tracker: { id: "s09-brief", state: "failure", points: 0 }
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
                        id    : "s09-respond",
                        title : "Respond to dispatch call",
                        state : "incomplete"
                    },
                    {
                        id    : 's09-confirm',
                        title : 'Confirm the IED threat',
                        state : 'incomplete'
                    },
                    {
                        id    : "s09-identify",
                        title : "Identify the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-call",
                        title : "Report the IED threat to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-hazards",
                        title : "Conduct a threat/hazard assessment to identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-distance",
                        title : "Identify recommended evacuation distance.",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-report",
                        title : "Determine the critical information to report.",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-cordon",
                        title : "Cordon the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-control",
                        title : "Control the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s09-brief",
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
                    "name"      : "rural",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function () {
                        aden.fsm.scenario09.trigger('move-rural');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "car",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function () {
                        aden.fsm.scenario09.trigger('move-car');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "parked",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function () {
                        aden.fsm.scenario09.trigger('move-parked');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "patrol",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function () {
                        aden.fsm.scenario09.trigger('move-patrol');
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
                        aden.fsm.scenario09.trigger('move-barricades');
                    }
                }
            ]
        }
    };

    return scenario;
});
