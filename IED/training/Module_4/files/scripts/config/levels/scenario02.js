define(function(require){

    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');

    var scenario = {
        "id" : "scenario02",

        // -- SETTINGS --
        "fsm"          : 'scenario02',
        "scene"        : 'start',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/scenario02/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 80,

        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM( aden.fsm.scenario02 );
            aden.plugin.radio.setEventName( 'radio-click' );
        },

        "onPanoLoad": function(){
            aden.fsm.gameView.trigger('complete');
        },

        // -- GAME STATE --
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
                "score": {
                    "points" : 0
                }
            }
        },

        // -- LEVEL VARIABLES --
        "variables" : [],

        // -- GAME OBJECTS --
        "objects" : [
            
            // -- video clips --

            {
                id    : "s02-cin01",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_02/S02_Cin01.mp4'
                }
            },
            {
                id    : "s02-cin02",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_02/S02_Cin02.mp4'
                }
            },
            {
                id    : "s02-cin03",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_02/S02_Cin03.mp4'
                }
            },
            {
                id    : "s02-cin04",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_02/S02_Cin04.mp4'
                }
            },
            {
                id    : "s02-cin05",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_02/S02_Cin05.mp4'
                }
            },

            // -- intro --
            {
                id  : "s02-intro",
                type: "popup",
                text: "Your role in this scenario is that of a municipal/mass transit police officer."
            },

            // -- dispatch segment --
            {
                id   : 's02-dispatch01',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S02_Dispatch_startup.mp3'
            },
            {
                id    : 's02-dispatch01-narration',
                type  : 'narration',
                title : '',
                text  : 'All units in the vicinity of the regional train station, respond to a male creating a disturbance in the concourse near the boarding area. Witnesses say the man is hysterical and screaming at people for help.'
            },
            {
                id    : 's02-dispatch01-instructions',
                type  : 'narration',
                title : '',
                text  : 'Click the microphone to respond to the dispatch call.'
            },
            {
                id    : 's02-dispatch01-warning',
                type  : 'narration',
                title : 'Warning',
                text  : 'You need to respond to the dispatch call immediately.'
            },
            {
                id   : 's02-dispatch01-reply-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/Response_Acknowledged.mp3'
            },
            {
                id    : "s02-dispatch01-reply-text",
                type  : "narration",
                text  : "Response acknowledged."
            },

            // -- DP 01 --

            {
                id   : 's02-dp01',
                type : 'dp',
                stem : '1. This appears to be the man the dispatch call referred to. You are the first responder on the scene. How should you react?',
                options: [
                    'Tell the man to stay where he is and move in closer for a better look.',
                    'Tell the man to stay where he is, but do not approach him. Maintain your current distance and assess the situation.',
                    'Tell the man to lie down on the floor, then move in closer and place the man in handcuffs.'
                ],
                plugin: {
                    tracker: { id: "s02-confirm" }
                }
            },
            {
                id    : 's02-dp01-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The man says he has a bomb. You should not move any closer.',
                plugin: {
                    tracker: { id: "s02-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp01-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The man says he has a bomb. You need him to stay where he is, and you need to maintain a line of sight on him for the moment.',
                plugin: {
                    tracker: { id: "s02-confirm", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp01-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You are probably putting yourself in great danger. The man says he has a bomb, so you don’t want to assume that’s not true.',
                plugin: {
                    tracker: { id: "s02-confirm", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp01-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You must answer the question.'
            },

            // -- DP 02 --

            {
                id   : 's02-dp02',
                type : 'dp',
                stem : '2. Now that you’ve had time to assess the situation, do you recognize an IED?',
                answers: [1,0],
                options: [
                    'Yes',
                    'No'
                ],
                plugin: {
                    tracker: { id: "s02-components" }
                }
            },
            {
                id    : 's02-dp02-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! IED components are visible. You have completed the first of the Five Cs, which is to CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s02-components", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp02-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. IED components are visible. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s02-components", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp02-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond within the time allowed. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.'
            },

            // -- DP 03 --

            {
                id   : 's02-dp03',
                type : 'dp',
                stem : '3. Now that you’ve CONFIRMED this IED threat, which of the Five Cs should you perform next?',
                options: [
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s02-clear" }
                }
            },
            {
                id    : 's02-dp03-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Once you have confirmed the IED threat, the next of the Five Cs is to CLEAR the area. You should stay close enough to talk to the subject, but get behind cover.',
                plugin: {
                    tracker: { id: "s02-clear", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp03-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. If an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s02-clear", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp03-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. If an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s02-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's02-dp03-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. If an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s02-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's02-dp03-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.'
            },

            // -- DP 04 --

            {
                id: "s02-dp04-intro",
                type: "narration",
                text: "Before you call in to headquarters, take 60 seconds to perform a secondary sweep of the area. Use the arrow keys on your keyboard to conduct the secondary sweep."
            },
            {
                id   : 's02-dp04',
                type : 'dp-multi',
                stem : '4. You have cleared people from the immediate area and taken cover. Your next Five Cs task is to CALL a situation report to higher command. What will you tell them? (Answer requires more than one selection.)',
                answers: [1,1,1,1,0],
                options: [
                    'Subject is a male wearing an explosive vest.',
                    'Location is the concourse level of the train station.',
                    'IED confirmed. Visible components are the charge and switch.',
                    'Subject may be communicating with an unknown person via walkie talkie.',
                    'Subject is threatening to detonate the device.'
                ],
                plugin: {
                    tracker: { id: "s02-report" }
                }
            },
            {
                id    : 's02-dp04-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You have provided a complete report of the IED threat and other key facts accurately and concisely.',
                plugin: {
                    tracker: { id: "s02-report", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp04-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have not provided a complete report of the IED threat and other key facts accurately and concisely.',
                plugin: {
                    tracker: { id: "s02-report", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp04-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.'
            },

            // -- Assessment Segment --

            {
                id    : 's02-assessment',
                type  : 'narration',
                title : '',
                text  : 'Use the game controls to look around and conduct a more thorough assessment of the threats and hazards in the environment. You have 60 seconds to complete this assessment.'
            },

            // -- DP 05 --

            {
                id   : 's02-dp05',
                type : 'dp-multi',
                stem : '5. Time is up. Select the threats and hazards in the environment from the list you see here. (Answer requires more than one selection.)',
                answers: [1,1,1,0],
                options: [
                    'Explosive vest IED.',
                    'Blast effects on humans.',
                    'Blast concentration in the enclosed concourse area.',
					"Blast effects on underground electrical cables."
                ],
                plugin: {
                    tracker: { id: "s02-hazards" }
                }
            },
            {
                id    : 's02-dp05-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s02-hazards", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp05-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s02-hazards", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp05-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.'
            },

            // -- DP 06 --

            {
                id   : 's02-dp06-intro',
                type : 'popup',
                text : 'There are still too many people too close to this bomb. You need to identify a preferred evacuation distance for the evacuation of civilians, and so additional responders will have a safe assembly area.'
            },
            {
                id   : 's02-dp06',
                type : 'dp',
                stem : '6. Use the Mapview tool or the Bomb Threat Stand-Off Card job aid to identify the preferred evacuation distance, then select the preferred evacuation distance from the list on the screen.',
                options: [
                    '150 ft.',
                    '400 ft.',
                    '1200 ft.',
                    '1700 ft.'
                ],
                plugin: {
                    tracker: { id: "s02-distance" }
                }
            },
            {
                id    : 's02-dp06-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 150 ft. is the Mandatory Evacuation Distance for a pipe bomb. For more information on preferred evacuation distances, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s02-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp06-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 400 ft. is the Mandatory Evacuation Distance for an SUV/Van loaded with explosives. For more information on preferred evacuation distances, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s02-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp06-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1200 ft. is the preferred evacuation distance for a pipe bomb. For more information on preferred evacuation, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s02-distance", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp06-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! 1700 ft. is the preferred evacuation distance for a person-borne IED. When you have identified the preferred evacuation distance, call that in to higher command.',
                plugin: {
                    tracker: { id: "s02-distance", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp06-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1900 ft. is the preferred evacuation distance for a car bomb. For more information on preferred evacuation distances, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s02-distance", state: "failure", points: 0 }
                }
            },

            // -- DP 07 --
            {
                id   : 's02-dp07-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S02_Dispatch_D07.mp3'
            },
            {
                id   : 's02-dp07-intro',
                type : 'narration',
                text : 'Units are arriving at the metro train station in response to a person-borne IED in the concourse area.'
            },
            {
                id   : 's02-dp07',
                type : 'dp',
                stem : '7. You have identified the preferred evacuation distance, and additional emergency personnel are arriving on scene. Which of the Five Cs must be performed next? Select one response from the list.',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s02-cordon" }
                }
            },
            {
                id    : 's02-dp07-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s02-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp07-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s02-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp07-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s02-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp07-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The next Five Cs action to be performed is to CORDON the area.',
                plugin: {
                    tracker: { id: "s02-cordon", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp07-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s02-cordon", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp07-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.'
            },

            // -- DP 08 --

            {
                id   : 's02-dp08',
                type : 'dp',
                stem : '8. A pedestrian is unknowingly walking through the blast zone near you. Which of the Five Cs do you need to perform in response? Select one response from the list.',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s02-control" }
                }
            },
            {
                id    : 's02-dp08-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CONTROL the area around the IED threat. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s02-control", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp08-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CONTROL the area around the IED threat. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s02-control", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp08-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CONTROL the area around the IED threat. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s02-control", state: "failure", points: 0 }
                }
            },
            {
                id    : 's02-dp08-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CONTROL the area around the IED threat. You should review the Five Cs job aid in the Resources section for more information on controlling the area.'
            },
            {
                id    : 's02-dp08-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You need to CONTROL the area around the IED threat and prevent this civilian from walking into harm’s way.',
                plugin: {
                    tracker: { id: "s02-control", state: "success", points: 10 }
                }
            },
            {
                id    : 's02-dp08-warning01',
                type  : 'popup',
                title : 'Warning',
                text  : 'In order to protect this civilian, you need to respond to this situation quickly. Try again.'
            },
            {
                id    : 's02-dp08-warning02',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.'
            },

            // -- DP 09 --

            {
                id   : 's02-dp09-audio',
                type : 'audio',
                file : 'files/assets/audio/bombtech/TSWG_IED_S01_BombTech01_Radio.mp3'
            },
            {
                id   : 's02-dp09-intro',
                type : 'narration',
                text : 'Officer, I am the lead bomb tech. I need you to brief me on the IED threat situation.'
            },

            {
                id   : 's02-dp09',
                type : 'dp-multi',
                stem : '9. Keep your brief back to the Lead Bomb Tech focused. What information do you need to provide? (Answer requires more than one selection.)',
                answers: [0,1,1],
                options: [
					'Switch is a digital timer.',
					'Subject has a walkie talkie and may be communicating with another subject.',
					'Subject may be a PBIED (Person-born IED).'
                ],
                plugin: {
                    tracker: { id: "s02-brief" }
                }
            },
            {
                id   : 's02-dp09-r01-audio',
                type : 'audio',
                file : 'files/assets/audio/bombtech/TSWG_IED_S01_BombTech02_Radio.mp3'
            },
            {
                id    : 's02-dp09-r01-text',
                type  : 'narration',
                title : 'Feedback',
                text  : 'That’s good awareness and a complete briefing on your part, Officer.',
                plugin: {
                    tracker: { id: "s02-brief", state: "success", points: 20 }
                }
            },
            {
                id   : 's02-dp09-r02-audio',
                type : 'audio',
                file : 'files/assets/audio/bombtech/TSWG_IED_S01_BombTech03_Radio.mp3'
            },
            {
                id    : 's02-dp09-r02-text',
                type  : 'narration',
                title : 'Feedback',
                text  : 'Your information is incomplete. I’ll have to send someone in to take a closer look.',
                plugin: {
                    tracker: { id: "s02-brief", state: "failure", points: 0 }
                }
            },
			
            {
                id    : 's02-cinematic04-text',
                type  : 'narration',
                text  : "Get back! There's a bomb."
            },
            {
                id    : 's02-dp09-warning',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to respond.'
            }
        ],

        // LEVEL DATA FOR PLUGINS
        "plugin" : {
            "map" : {
                "image" : "files/assets/images/screens/scenario_01/OverheadMapCC.png",
                "scale" : 10, // feet per pixel
                "position" : {
                    top  : 370,
                    left : 809
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
                        id    : "s02-confirm",
                        title : "Identify the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-components",
                        title : "Identify IED components",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-report",
                        title : "Report the IED threat to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-hazards",
                        title : "Identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-distance",
                        title : "Identify preferred evacuation distance.",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-cordon",
                        title : "Cordon",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-control",
                        title : "Control",
                        state : "incomplete"
                    },
                    {
                        id    : "s02-brief",
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
                    "name"      : "start",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario02.trigger('move-start');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "behindcolumn",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario02.trigger('move-column');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "concourse",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario02.trigger('move-concourse');
                    }
                }
            ]
        }
    };

    return scenario;
});
