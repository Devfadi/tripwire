define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');
        
    var scenario = {
        "id" : "scenario06",
        
        // -- SETTINGS --
        "fsm"          : 'scenario06',
        "scene"        : 'accident',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/Scenario06/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 80,
        
        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM( aden.fsm.scenario06 );
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
            {
                id   : 's06-start-screen',
                type : 'image',
                src  : "files/assets/images/screens/scenario_06/intro.jpg"
            },
            {
                id   : 's06-bomb-tech',
                type : 'image',
                src  : "files/assets/images/screens/scenario_06/bomb-tech.jpg"
            },
            
            
            {
                id    : "s06-cin01",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_06/S06_Cin01.mp4'
                }
            },
            {
                id    : "s06-cin02",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_06/S06_Cin02.mp4'
                }
            },
            {
                id    : "s06-cin03",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_06/S06_Cin03.mp4'
                }
            },
            {
                id    : "s06-cin04",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_06/S06_Cin04.mp4'
                }
            },
            {
                id    : "s06-cin05",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_06/S06_Cin05.mp4'
                }
            },
            {
                id    : "s06-tech-positive",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_06/S06_Cin03a.mp4'
                }
            },
            {
                id    : "s06-tech-negative",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_06/S06_Cin03b.mp4'
                }
            },
            
            // FPV panorama of the intersection/accident scene from a few feet away.
            
            {
                id  : "s06-intro",
                type: "popup",
                text: "Your role in this scenario is that of an emergency medical technician responding to a dispatcher’s call about a traffic accident with injuries."
            },
            
            {
                id   : 's06-dispatch-call-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S06_start.mp3'
            },
            {
                id    : 's06-dispatch-call-text',
                type  : 'narration',
                text  : 'Units respond to a two-car accident with injuries at the intersection of Adams and Jefferson. Reportee states gasoline is leaking from one or both of the vehicles. Request immediate fire and medical response.'
            },
            {
                id    : 's06-dispatch-response',
                type  : 'narration',
                text  : 'Click the microphone to respond.'
            },
            {
                id    : "s06-dispatch-warning",
                type  : "narration",
                text  : "You did not respond to the dispatch call immediately. Click the microphone to respond."
            },
            {
                id   : 's06-dispatch-reply-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/Response_Acknowledged.mp3'
            },
            {
                id    : 's06-dispatch-reply-text',
                type  : 'narration',
                text  : 'Response acknowledged.',
                plugin: {
                    tracker: { id: "s06-respond", state: "success", points: 0 },
                }
            },
            
            {
                id: "s06-first-responder",
                type: "narration",
                text: "You are the first responder on the scene. Click on the arrow to check on the driver of the red car."
            },
            {
                id: "s06-first-responder-move",
                type: "popup",
                title: "Notice",
                text: "Click on the arrow to check on the driver of the red car."
            },
            
            
            {
                id: "s06-dp01-intro",
                type: "narration",
                text: "Take 30 seconds to view the inside of the vehicle."
            },
            
            {
                id   : 's06-dp01',
                type : 'dp-multi',
                stem : '1. You are the first responder on the scene of the accident. A driver is trapped inside the vehicle. It also appears there is an IED inside the vehicle. Identify the IED components and select each component you recognize. (Answer requires more than one selection.)',
                answers: [1,0,1,0,1],
                options: [
                    'Container',
                    'Main charge',
                    'Switch',
                    'Initiator',
                    'Power source'
                ],
                plugin: {
                    tracker: { id: "s06-identify" },
                }
            },
            {
                id    : 's06-dp01-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The container, switch, and power source are the visible IED components. You have completed the first of the Five Cs, which is to CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s06-identify", state: "success", points: 10 },
                }
            },
            {
                id    : 's06-dp01-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The container, switch, and power source are the visible IED components. ',
                plugin: {
                    tracker: { id: "s06-identify", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp01-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s06-identify", state: "failure", points: 0 },
                }
            },
                        
            {
                id   : 's06-dp02',
                type : 'dp',
                stem : '2. Now that you’ve CONFIRMED this IED threat, which of the Five Cs should you perform next?',
                options: [
                    'CLEAR people away from the immediate area around the IED.',
                    'CALL higher command to report the IED threat.',
                    'CONTROL traffic in the intersection until help arrives.',
                    'REMOVE the IED from the vehicle so it can be moved to a safe place for disposal.'
                ],
                plugin: {
                    tracker: { id: "s06-clear" },
                }
            },
            {
                id    : 's06-dp02-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Once you have confirmed the IED threat, the next of the Five Cs is to CLEAR the immediate area. You should stay close enough to maintain a line of sight and talk to the injured driver, but shelter in place if possible.',
                plugin: {
                    tracker: { id: "s06-clear", state: "success", points: 10 },
                }
            },
            {
                id    : 's06-dp02-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. If an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp02-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. If an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp02-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. If an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp02-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s06-clear", state: "failure", points: 0 },
                }
            },
            
            {
                id   : 's06-dp03',
                type : 'dp',
                stem : '3. You have cleared the pedestrians from the immediate area and sheltered in place behind your vehicle. What do you need to do next?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s06-call" },
                }
            },
            {
                id    : 's06-dp03-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp03-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp03-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command.',
                plugin: {
                    tracker: { id: "s06-call", state: "success", points: 10 },
                }
            },
            {
                id    : 's06-dp03-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp03-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp03-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s06-call", state: "failure", points: 0 },
                }
            },
            
            {
                id   : 's06-dp04',
                type : 'dp-multi',
                stem : '4. Your next action is to CALL higher command. What information do you need to report? (Answer requires more than one selection.)',
                answers: [1,1,1,1,0],
                options: [
                    'Confirmed IED threat.',
                    'IED components identified.',
                    'Threats and hazards in the environment.',
                    'Safe stand-off distance.',
                    'Distance to nearest occupied building.'
                ],
                plugin: {
                    tracker: { id: "s06-report" },
                }
            },
            {
                id    : 's06-dp04-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You have provided a complete report of the IED threat and other key facts accurately and concisely.',
                plugin: {
                    tracker: { id: "s06-report", state: "success", points: 10 },
                }
            },
            {
                id    : 's06-dp04-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have not provided a complete report of the IED threat and other key facts accurately and concisely.',
                plugin: {
                    tracker: { id: "s06-report", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp04-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s06-report", state: "failure", points: 0 },
                }
            },
            
            {
                id  : "s06-dp05-intro",
                type: "narration",
                text: "You need to report the threats and hazards in the environment. Use the controls to look around and conduct a more thorough assessment of the threats and hazards. You have 60 seconds to complete this assessment."
            },
                        
            {
                id   : 's06-dp05',
                type : 'dp-multi',
                stem : '5. Time is up. Select the threats and hazards in the environment by clicking the options below to make your selections. (Answer requires more than one selection.)',
                answers: [1,1,1],
                options: [
                    'Fragmentation of nearby structural elements, such as windows in buildings.',
                    'Fragmentation of infrastructure elements, such as traffic signals and electrical wires.',
                    'Blast effects on humans remaining in the danger zone.'
                ],
                plugin: {
                    tracker: { id: "s06-hazards" },
                }
            },
            {
                id    : 's06-dp05-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s06-hazards", state: "success", points: 10 },
                }
            },
            {
                id    : 's06-dp05-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s06-hazards", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp05-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s06-hazards", state: "failure", points: 0 },
                }
            },
            
            {
                id   : 's06-dp06',
                type : 'dp',
                stem : '6. You need to identify the safe stand-off distance for the type of IED you have identified. Use the Mapview tool or the Bomb Threat Stand-Off Card job aid to identify the safe stand-off distance, then select the safe stand-off distance from the list on the screen.',
                options: [
                    '70 ft.',
                    '110 ft.',
                    '1200 ft.',
                    '1850 ft.'
                ],
                plugin: {
                    tracker: { id: "s06-distance" },
                }
            },
            {
                id    : 's06-dp06-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1850 ft. is the preferred evacuation distance for this type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s06-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp06-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1850 ft. is the preferred evacuation distance for this type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s06-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp06-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1850 ft. is the preferred evacuation distance for this type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s06-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp06-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! 1850 ft. is the preferred evacuation distance for this type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s06-distance", state: "success", points: 10 },
                }
            },
            
            {
                id   : 's06-dp07',
                type : 'dp',
                stem : '7. You have identified the safe stand-off distance for the type of IED. Which answer best describes the purpose of this information?',
                options: [
                    'Establish the cordon perimeter.',
                    'All buildings within this distance of the IED will be evacuated.',
                    'Traffic will be stopped at this distance in all directions.',
                    'All electrical power will be turned off within this distance.'
                ],
                plugin: {
                    tracker: { id: "s06-cordon" },
                }
            },
            {
                id    : 's06-dp07-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The safe stand-off distance is used to establish the cordon perimeter.',
                plugin: {
                    tracker: { id: "s06-cordon", state: "success", points: 10 },
                }
            },
            {
                id    : 's06-dp07-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The safe stand-off distance is used to establish the cordon perimeter. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp07-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The safe stand-off distance is used to establish the cordon perimeter. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp07-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The safe stand-off distance is used to establish the cordon perimeter. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s06-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp07-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s06-cordon", state: "failure", points: 0 },
                }
            },
            
            {
                id   : 's06-dp08',
                type : 'dp',
                stem : '8. Additional units are arriving on-scene and using the safe stand-off distance you provided as a cordon perimeter and staging area. What is the next step in this IED response?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s06-control" },
                }
            },
            {
                id    : 's06-dp08-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s06-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp08-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s06-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp08-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s06-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp08-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s06-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp08-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The next step is to CONTROL the area around the cordon perimeter.',
                plugin: {
                    tracker: { id: "s06-control", state: "success", points: 10 },
                }
            },
            {
                id    : 's06-dp08-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s06-control", state: "failure", points: 0 },
                }
            },
            
            {
                id   : 's06-dp09-intro-audio',
                type : 'audio',
                file : 'files/assets/audio/bombtech/TSWG_IED_S01_BombTech01.mp3'
            },
            {
                id   : 's06-dp09-intro-text',
                type : 'narration',
                text : 'Officer, I am the lead bomb tech. I need you to brief me on the IED threat situation.'
            },
            
            {
                id   : 's06-dp09',
                type : 'dp-multi',
                stem : '9. What confirmed information goes into your brief for the Bomb Tech Lead? (Answer requires more than one selection.)',
                answers: [1,0,1,0,1,1,1,0,0],
                options: [
                    'Confirmed IED components inside the vehicle.',
                    'Main charge.',
                    'Switch.',
                    'Initiators.',
                    'Power source.',
                    'Driver of the vehicle may need medical attention.',
                    'Fuel is leaking from one of the vehicles.',
                    'The other driver has cleared the scene as directed.',
                    'Electrical power for the area is still active.'
                ],
                plugin: {
                    tracker: { id: "s06-brief" },
                }
            },
            {
                id    : 's06-dp09-r01',
                type  : 'narration',
                title : 'Feedback',
                text  : 'That’s good awareness and a complete briefing on your part, Officer.',
                plugin: {
                    tracker: { id: "s06-brief", state: "success", points: 20 },
                }
            },
            {
                id    : 's06-dp09-r02',
                type  : 'narration',
                title : 'Feedback',
                text  : 'Your information is incomplete. I’ll have to send someone in to take a closer look.',
                plugin: {
                    tracker: { id: "s06-brief", state: "failure", points: 0 },
                }
            },
            {
                id    : 's06-dp09-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s06-brief", state: "failure", points: 0 },
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
                        id    : "s06-respond",
                        title : "Respond to dispatch call",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-identify",
                        title : "Identify the IED components",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-call",
                        title : "Report the IED threat to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-report",
                        title : "Provide a complete report of the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-hazards",
                        title : "Conduct a threat/hazard assessment to identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-distance",
                        title : "Identify safe stand-off distance and recommend cordon perimeter.",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-cordon",
                        title : "Cordon",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-control",
                        title : "Control",
                        state : "incomplete"
                    },
                    {
                        id    : "s06-brief",
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
                    "name"      : "intersection",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario06.trigger('move-intersection');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "car",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario06.trigger('move-car');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "ambulance",
                    "position"  : { x: 0.0, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario06.trigger('move-ambulance');
                    }
                }
            ]
        }
    };
    
    return scenario;
});
