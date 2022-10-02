define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');
        
    var scenario = {
        "id" : "scenario03",
        
        // -- SETTINGS --
        "fsm"          : 'scenario03',
        "scene"        : 'concourse',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/scenario03/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 80,
        
        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM( aden.fsm.scenario03 );
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
                id   : 's03-bomb-tech',
                type : 'image',
                src  : "files/assets/images/screens/scenario_03/bomb-tech.jpg"
            },
            {
                id: "s03-backpack",
                type: "image",
                src: "files/assets/images/screens/scenario_03/backpack.jpg"
            },
            {
                id: "s03-fan-pointing",
                type: "image",
                src: "files/assets/images/screens/scenario_03/fan-pointing.jpg"
            },
            
            {
                id    : "s03-cin01",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_03/S03_Cin01.mp4'
                }
            },
            {
                id    : "s03-cin02",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_03/S03_Cin02.mp4'
                }
            },
            {
                id    : "s03-cin03",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_03/S03_Cin03.mp4'
                }
            },
            {
                id    : "s03-cin04",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_03/S03_Cin04.mp4'
                }
            },
            {
                id    : "s03-cin05",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_03/S03_Cin05.mp4'
                }
            },
            {
                id    : "s03-tech-positive",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_03/S03_Cin05a.mp4'
                }
            },
            {
                id    : "s03-tech-negative",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_03/S03_Cin05b.mp4'
                }
            },
            
            
            // -- intro --
            {
                id  : "s03-intro",
                type: "popup",
                text: "Your role in this scenario is that of a first responder working as stadium security at a football game."
            },
            {
                id   : 's03-start-screen',
                type : 'image',
                src  : "files/assets/images/screens/placeholder.png"
            },
            
            {
                id    : 's03-cin01-narration',
                type  : 'narration',
                title : '',
                text  : 'Someone left a backpack at the hallway entrance just around the corner there.'
            },
            
            // -- DP 01 --
            
            {
                id   : 's03-dp01',
                type : 'dp',
                stem : '1. A person has just informed you that there is an unattended backpack nearby in the stadium concourse area. What action do you need to take?',
                options: [
                    'Go around the corner into the stadium concourse and investigate the report.',
                    'Use your radio to call for someone else to take a look.',
                    'Ignore it. It probably belongs to another football fan.'
                ],
                plugin: {
                    tracker: { id: "s03-confirm" },
                }
            },
            {
                id    : 's03-dp01-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You should take immediate action to check out this report.',
                plugin: {
                    tracker: { id: "s03-confirm", state: "success", points: 10 },
                }
            },
            {
                id    : 's03-dp01-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You should take immediate action to check out this report. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to this situation.',
                plugin: {
                    tracker: { id: "s03-confirm", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp01-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You should take immediate action to check out this report. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to this situation.',
                plugin: {
                    tracker: { id: "s03-confirm", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp01-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s03-confirm", state: "failure", points: 0 },
                }
            },
            
            // -- DP 02 --
            
            {
                id   : 's03-dp02-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S03_D01.mp3'
            },
            {
                id    : 's03-dp02-intro',
                type  : 'narration',
                text  : 'All units. We have an unattended package in the stadium locker room area. Suspect this may be an explosive device.'
            },
            {
                id   : 's03-dp02',
                type : 'dp-multi',
                stem : '2. What IED components do you recognize? (Answer requires more than one selection.)',
                answers: [1,1,0,0],
                options: [
                    'Container',
                    'Wires',
                    'Power source',
                    'No recognizable IED components'
                ],
                plugin: {
                    tracker: { id: "s03-components" },
                }
            },
            {
                id    : 's03-dp02-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The container (pressure cooker) and wires are the visible IED components. You have completed the first of the Five Cs, which is to CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s03-components", state: "success", points: 10 },
                }
            },
            {
                id    : 's03-dp02-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The container (pressure cooker) and wires are the visible IED components. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s03-components", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp02-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s03-components", state: "failure", points: 0 },
                }
            },
            
            // -- DP 03 --
            
            {
                id   : 's03-dp03-intro-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S03_D03.mp3'
            },
            {
                id    : 's03-dp03-intro-text',
                type  : 'narration',
                text  : 'All units. A second suspicious package is reported in the stadium parking lot area. Suspect multiple explosive device situation.'
            },
            {
                id   : 's03-dp03',
                type : 'dp',
                stem : '3. You can clearly see IED components in an unattended backpack, and similar packages are reported in other areas of the stadium. What is your next action?',
                options: [
                    'Move away from the backpack, and direct the other people in the area to move away.',
                    'Stay near the backpack, but direct other people to leave the area.',
                    'Use the radio to report you have a suspected IED.'
                ],
                plugin: {
                    tracker: { id: "s03-clear" },
                }
            },
            {
                id    : 's03-dp03-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Once you have confirmed the IED threat, the next of the Five Cs is to CLEAR the area. You should also move away from the threat to a safer location.',
                plugin: {
                    tracker: { id: "s03-clear", state: "success", points: 10 },
                }
            },
            {
                id    : 's03-dp03-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s03-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp03-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once an IED threat is confirmed, the next step in the Five Cs is to CLEAR the area. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s03-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp03-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s03-clear", state: "failure", points: 0 },
                }
            },
            
            // -- DP 04 --
            
            {
                id: "s03-dp04-intro",
                type: "narration",
                text: "Before you call in to headquarters, take 60 seconds to perform a secondary sweep of the area. Use the arrow keys on your keyboard to conduct the secondary sweep."
            },
            {
                id   : 's03-dp04',
                type : 'dp-multi',
                stem : '4. You need to report this IED threat to security coordinators. What information should you include in your call? (Answer requires more than one selection.)',
                answers: [1,0,1,0,1],
                options: [
                    'Confirmed IED threat.',
                    'Possible IED threat.',
                    'Visible IED components are container and initiator.',
                    'I have cleared the area and there is no danger to the public at this time.',
                    'Location is the stadium concourse near the concession area.'
                ],
                plugin: {
                    tracker: { id: "s03-report" },
                }
            },
            {
                id    : 's03-dp04-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You have provided an accurate report of what you currently know about this IED threat.',
                plugin: {
                    tracker: { id: "s03-report", state: "success", points: 10 },
                }
            },
            {
                id    : 's03-dp04-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have not provided an accurate report of what you currently know about this IED threat.',
                plugin: {
                    tracker: { id: "s03-report", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp04-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s03-report", state: "failure", points: 0 },
                }
            },
            
            // -- DP 05 --
            
            {
                id   : 's03-dp05',
                type : 'dp',
                stem : '5. You have reported what you know about the IED threat to security coordinators and can now proceed to a threat/hazard assessment. What is the objective of the threat/hazard assessment?',
                options: [
                    'To identify potential blast and fragmentation effects of the IED on humans, structures, and infrastructure.',
                    'To identify the person (or persons) responsible for building and placing the IED at its current location.',
                    'To identify the possible motive for the placement of the IED.'
                ],
                plugin: {
                    tracker: { id: "s03-hazards" },
                }
            },
            {
                id    : 's03-dp05-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The objective of the threat/hazard assessment is to identify potential blast and fragmentation effects of the IED on humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s03-hazards", state: "success", points: 20 },
                }
            },
            {
                id    : 's03-dp05-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The objective of the threat/hazard assessment is to identify potential blast and fragmentation effects of the IED on humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s03-hazards", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp05-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The objective of the threat/hazard assessment is to identify potential blast and fragmentation effects of the IED on humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s03-hazards", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp05-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond.',
                plugin: {
                    tracker: { id: "s03-hazards", state: "failure", points: 0 },
                }
            },
            
            // -- DP 06 --
            
            {
                id   : 's03-dp06-intro-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S03_D06.mp3'
            },
            {
                id   : 's03-dp06-intro-text',
                type : 'narration',
                text : 'All units. Multiple IED threats are confirmed at university stadium. Activate emergency evacuation plan.'
            },
            {
                id   : 's03-dp06',
                type : 'dp',
                stem : '6. You are going to be evacuating the public from the stadium. What is the preferred evacuation distance for this type of IED?',
                options: [
                    '640 ft.',
                    '860 ft.',
                    '1200 ft.',
                    '1850 ft.'
                ],
                plugin: {
                    tracker: { id: "s03-distance" },
                }
            },
            {
                id    : 's03-dp06-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1850 ft. is the preferred evacuation distance for this backpack IED, which is most similar to a briefcase/suitcase IED.',
                plugin: {
                    tracker: { id: "s03-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp06-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1850 ft. is the preferred evacuation distance for this backpack IED, which is most similar to a briefcase/suitcase IED.',
                plugin: {
                    tracker: { id: "s03-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp06-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1850 ft. is the preferred evacuation distance for this backpack IED, which is most similar to a briefcase/suitcase IED.',
                plugin: {
                    tracker: { id: "s03-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp06-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! 1850 ft. is the preferred evacuation distance for this backpack IED, which is most similar to a briefcase/suitcase IED.',
                plugin: {
                    tracker: { id: "s03-distance", state: "success", points: 10 },
                }
            },
            
            // -- DP 07 --
            
            {
                id   : 's03-dp07',
                type : 'dp',
                stem : '7. You are assisting with the evacuation of the public from the stadium. Which of the Five Cs are you performing?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s03-cordon" },
                }
            },
            {
                id    : 's03-dp07-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Evacuation of the stadium is part of the CORDONING task. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s03-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp07-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Evacuation of the stadium is part of the CORDONING task. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s03-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp07-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Evacuation of the stadium is part of the CORDONING task. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s03-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp07-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Evacuation of the stadium is part of the CORDONING task.',
                plugin: {
                    tracker: { id: "s03-cordon", state: "success", points: 10 },
                }
            },
            {
                id    : 's03-dp07-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Evacuation of the stadium is part of the CORDONING task. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s03-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp07-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s03-cordon", state: "failure", points: 0 },
                }
            },
            
            // -- DP 08 --
            
            {
                id   : 's03-dp08',
                type : 'dp',
                stem : '8. Once you have reached the preferred evacuation distance, what task can you expect to be responsible for?',
                options: [
                    'Control the area and ensure members of the public does not approach.',
                    'Return to the stadium to assist in neutralizing the IEDs.',
                    'Return to the stadium security office.'
                ],
                plugin: {
                    tracker: { id: "s03-control" },
                }
            },
            {
                id    : 's03-dp08-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You would most likely help to CONTROL the area and prevent the public from getting closer to the IED threat.',
                plugin: {
                    tracker: { id: "s03-control", state: "success", points: 10 },
                }
            },
            {
                id    : 's03-dp08-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You would most likely help to CONTROL the area and prevent the public from getting closer to the IED threat. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s03-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp08-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You would most likely help to CONTROL the area and prevent the public from getting closer to the IED threat. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s03-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp08-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s03-control", state: "failure", points: 0 },
                }
            },
            
            // -- DP 09 --

            {
                id    : 's03-dp09-intro',
                type  : 'popup',
                title : 'Warning',
                text  : 'I understand you reported the IED threat in the stadium concourse. I need you to brief me on that.'
            },
            {
                id   : 's03-dp09',
                type : 'dp-multi',
                stem : '9. What information goes into your brief for the Bomb Tech Lead? (Answer requires more than one selection.)',
                answers: [1,1,0,1],
                options: [
                    'The IED container is a pressure cooker inside a backpack.',
                    'The other visible IED component is wires taped to the top of the pressure cooker.',
                    'It is obvious someone intends to detonate this IED remotely.',
                    'I did not identify any subjects who might be in control of the device.'
                ],
                plugin: {
                    tracker: { id: "s03-brief" },
                }
            },
            {
                id    : 's03-dp09-r01',
                type  : 'narration',
                title : 'Feedback',
                text  : 'That’s good awareness and a complete briefing on your part, Officer.',
                plugin: {
                    tracker: { id: "s03-brief", state: "success", points: 10 },
                }
            },
            {
                id    : 's03-dp09-r02',
                type  : 'narration',
                title : 'Feedback',
                text  : 'Your information is incomplete. I’ll have to send someone in to take a closer look.',
                plugin: {
                    tracker: { id: "s03-brief", state: "failure", points: 0 },
                }
            },
            {
                id    : 's03-dp09-warning',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to respond.',
                plugin: {
                    tracker: { id: "s03-brief", state: "failure", points: 0 },
                }
            }
        ],
        
        // LEVEL DATA FOR PLUGINS
        "plugin" : {
            "map" : {
                "image" : "files/assets/images/screens/scenario_01/OverheadMapCC.png",
                "scale" : 10, // feet per pixel
                "position" : {
                    top  : 270,
                    left : 725
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
                        id    : "s03-confirm",
                        title : "Identify the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-components",
                        title : "Identify IED components",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-report",
                        title : "Report the IED threat to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-hazards",
                        title : "Identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-distance",
                        title : "Identify preferred evacuation distance.",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-cordon",
                        title : "Cordon",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-control",
                        title : "Control",
                        state : "incomplete"
                    },
                    {
                        id    : "s03-brief",
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
                    "name"      : "backpack",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario03.trigger('move-backpack');
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
                        aden.fsm.scenario03.trigger('move-column');
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
                        aden.fsm.scenario03.trigger('move-concourse');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "parkinglot",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario03.trigger('move-parkinglot');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "evacuate",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario03.trigger('move-evacuate');
                    }
                }
            ]
        }
    };
    
    return scenario;
});
