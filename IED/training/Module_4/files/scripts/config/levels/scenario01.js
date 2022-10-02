define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');
        
    var scenario = {
        "id" : "scenario01",
        
        // -- SETTINGS --
        "fsm"          : 'scenario01',
        "scene"        : 'start',
        "target"       : null,
        "xmlPath"      : 'files/assets/panos/scenario01/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 60,
        
        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.fsm.scenario01.trigger('load');
            aden.plugin.radio.setFSM( aden.fsm.scenario01 );
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
        
        // -- GAME OBJECTS --
        "objects" : [
            {
                id: 's01-warning-popup',
                type: 'popup',
                title: 'Warning',
                text: 'You have to make a decision.'
            },
            {
                id: 'audio-01',
                type: 'audio',
                file: 'files/assets/audio/dispatcher/S01_Dispatch01.mp3'
            },
            {
                id: 'audio-02',
                type: 'audio',
                file: 'files/assets/audio/dispatcher/S01_Dispatch02.mp3'
            },
            {
                id: 'audio-03',
                type: 'audio',
                file: 'files/assets/audio/dispatcher/S01_Dispatch03.mp3'
            },
            {
                id: 'audio-04',
                type: 'audio',
                file: 'files/assets/audio/dispatcher/S01_Dispatch04.mp3'
            },
            {
                id: 'audio-05',
                type: 'audio',
                file: 'files/assets/audio/dispatcher/Response_Acknowledged.mp3'
            },
            {
                id    : "narration-05",
                type  : "narration",
                text  : "Response acknowledged."
            },
            {
                id  : 'audio-06',
                type: 'audio',
                file: 'files/assets/audio/dispatcher/S01_Dispatch06.mp3'
            },
            {
                id    : "narration-06",
                type  : "narration",
                text  : "Seventy-One. Clear your current position and cordon west to the assembly point."
            },
            {
                id   : 's01-start-screen',
                type : 'image',
                src  : "files/assets/images/screens/scenario_01/S01_StartScreen.png"
            },
            {
                id   : 's01-screen04',
                type : 'image',
                src  : "files/assets/images/screens/scenario_01/S01_Cin04.jpg"
            },
            {
                id   : 's01-screen05',
                type : 'image',
                src  : "files/assets/images/screens/scenario_01/S01_Cin05.jpg"
            },
            {
                id    : "s01-pop1",
                type  : "popup",
                title : "",
                text  : "Your role in this scenario is that of a municipal police patrol officer."
            },
            {
                id    : "s01-pop2",
                type  : "narration",
                title : "",
                text  : "Seventy-One. Respond to a report of an unoccupied vehicle in the no parking zone in front of the Federal Courthouse."
            },
            {
                id    : "s01-pop4",
                type  : "narration",
                title : "",
                text  : "Seventy-One. Other units arriving on-scene. Vicinity Federal Courthouse."
            },
            {
                id: "s01-dispatch-prompt",
                type: "narration",
                text: "Click the microphone to respond."
            },
            {
                id    : "s01-cin01",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin01.mp4'
                },
                plugin: {
                    tracker: { id: "s01-respond", state: "success", points: 0 },
                }
            },
            {
                id    : "s01-30sec",
                type  : "narration",
                title : "",
                text  : "You have 60 seconds to look around and investigate the vehicle."
            },
            {
                id    : "s01-cin02",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin02.mp4'
                }
            },
            {
                id    : "s01-cin03",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin03.mp4'
                }
            },
            {
                id    : "s01-cin04",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin04.mp4'
                }
            },
            {
                id    : "s01-cin05",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin05.mp4'
                }
            },
            {
                id    : "s01-cin05a",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin05a.mp4'
                }
            },
            {
                id    : "s01-cin05b",
                type  : "video",
                media : {
                    'm4v' : 'files/assets/video/cinematics/scenario_01/S01_Cin05b.mp4'
                }
            },
            {
                id    : "s01-fail01",
                type  : "popup",
                title : "Feedback",
                text  : "You need to respond to the dispatch call. Click the microphone to respond.",
                plugin: {
                    tracker: { id: "s01-respond", state: "failure", points: 0 },
                }
            },
            {
                id    : 's01-fail02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You did not investigate the illegally parked vehicle.',
                plugin: {
                    tracker: { id: "s01-investigate", state: "failure", points: 0 },
                }
            },
            {
                id    : 's01-instructions',
                type  : 'narration',
                title : '',
                text  : 'Click the arrow to investigate this vehicle.'
            },
            
            // -- DP 01 --
            
            {
                id   : 's01-dp01',
                type : 'dp',
                stem : '1. What have you observed about this vehicle that is most critical to public safety?',
                options: [
                    'It is parked illegally',
                    'It contains heavy cargo',
                    'It contains a suspected IED'
                ],
                plugin: {
                    tracker: { id: "s01-threat" }
                }
            },
            {
                id    : 's01-dp01-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'While the van is clearly parked illegally, that is not the key observation you need to make.',
                plugin: {
                    tracker: { id: "s01-threat", state: "failure", points: 0 },
                }
            },
            {
                id    : 's01-dp01-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'While the cargo load is obviously heavy, that is not the key observation you need to make.',
                plugin: {
                    tracker: { id: "s01-threat", state: "failure", points: 0 }
                }
            },
            {
                id    : 's01-dp01-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You have identified a suspected IED.',
                plugin: {
                    tracker: { id: "s01-threat", state: "success", points: 8 }
                }
            },
            {
                id    : 's01-dp01-ignore',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s01-threat", state: "ignored", points: 0 }
                }
            },
            
            // -- DP 02 --
            
            {
                id: 's01-dp02',
                type: 'dp-multi',
                stem: '2. What IED components did you see? (Answer requires more than one selection.)',
                answers: [0,0,0,0,1],
                options: [
                    'Initiator',
                    'Main charge',
                    'Power source',
                    'Switch',
                    'Container and wires'
                ],
                plugin: {
                    tracker: { id: "s01-components" }
                }
            },
            {
                id: 's01-dp02-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! The container and wires are the IED components that are visible. You have completed the first of the Five Cs, which is to CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s01-components", state: "success", points: 9 },
                }
            },
            {
                id: 's01-dp02-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. The main container and wires are the IED components that are visible. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s01-components", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp02-ignore',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s01-components", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 03 -- 
            
            {
                id: 's01-dp03',
                type: 'dp',
                stem: '3. Now that you have identified an IED threat and the components of the IED, what should you do next?',
                options: [
                    'Clear the area around the IED threat and find a position of cover.',
                    'Call in the IED threat to higher command'
                ],
                plugin: {
                    tracker: { id: "s01-clear" }
                }
            },
            {
                id: 's01-dp03-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! If an IED is confirmed, the next of the Five Cs is to CLEAR the area and take a position of cover.',
                plugin: {
                    tracker: { id: "s01-clear", state: "success", points: 8 },
                }
            },
            {
                id: 's01-dp03-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. If an IED is confirmed, the next step is to clear the area and take a position of cover. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s01-clear", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp03-ignore',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision. If you’re having trouble, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s01-clear", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 04 -- 
            
            {
                id: 's01-dp04',
                type: 'dp',
                stem: '4. You have cleared the immediate area around the IED, what is the next action you need to take?',
                options: [
                    'Call in the IED threat to higher command',
                    'Control the area around the suspected IED'
                ],
                plugin: {
                    tracker: { id: "s01-call" }
                }
            },
            {
                id: 's01-dp04-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! While the area around the IED is being cleared, a report should be called in. Review the Five Cs job aid for more information about the correct response to an IED threat.',
                plugin: {
                    tracker: { id: "s01-call", state: "success", points: 8 },
                }
            },
            {
                id: 's01-dp04-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. While the area around the IED is being cleared, a report should be called in. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s01-call", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp04-ignore01',
                type: 'narration',
                title: '',
                text: 'Seventy-One. Report your status.'
            },
            {
                id: 's01-dp04-ignore02',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision. If you’re having trouble, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s01-call", state: "ignored", points: 0 },
                }
            },
            
            
            // -- DP 05 -- 
            
            {
                id: 's01-dp05',
                type: 'dp-multi',
                stem: '5. You need to call in the IED threat. What information should you report? (Answer requires more than one selection.)',
                answers: [1,1,1,1,0],
                options: [
                    'Suspected Vehicle-borne IED in a white cargo van',
                    'Outside the entrance to the Federal Courthouse',
                    'Report threats and hazards in the environment',
                    'Recommend a stand-off distance.',
                    'Suspects are located at the outdoor café across the street'
                ],
                plugin: {
                    tracker: { id: "s01-info" }
                }
            },
            {
                id: 's01-dp05-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! You need to report the IED threat and location, the threats and hazards in the environment, and recommend a stand-off distance.',
                plugin: {
                    tracker: { id: "s01-info", state: "success", points: 9 },
                }
            },
            {
                id: 's01-dp05-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. You need to report the IED threat and location, the threats and hazards in the environment, and recommend a stand-off distance.',
                plugin: {
                    tracker: { id: "s01-info", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp05-ignore',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision.',
                plugin: {
                    tracker: { id: "s01-info", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 06 --
            
            {
                id: 's01-dp06',
                type: 'dp',
                stem: '6. You need to gather information for your call in to headquarters. What should you do next?',
                options: [
                    'Conduct a threat assessment',
                    'Cordon the area'
                ],
                plugin: {
                    tracker: { id: "s01-assess" }
                }
            },
            {
                id: 's01-dp06-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! Assess the area for threats and hazards.',
                plugin: {
                    tracker: { id: "s01-assess", state: "success", points: 8 },
                }
            },
            {
                id: 's01-dp06-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. You should assess the area for threats and hazards.',
                plugin: {
                    tracker: { id: "s01-assess", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp06-ignore',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision.',
                plugin: {
                    tracker: { id: "s01-assess", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 07 --
            
            {
                id   : "s01-assess-threats",
                type : "narration",
                text : "Take 60 seconds to perform a threat/hazard assessment. You can use the arrow keys on your keyboard to scan the area around you."
            },
            {
                id: 's01-dp07',
                type: 'dp-multi',
                stem: '7. Which of these are threats and hazards in the vicinity of the suspected IED? (Answer requires more than one selection.)',
                answers: [1,1,1,0,0],
                options: [
                    'Gas main',
                    'The courthouse portico',
                    'Windows in the buildings',
                    'Overhead power lines',
                    'Plants and trees'
                ],
                plugin: {
                    tracker: { id: "s01-hazards" }
                }
            },
            {
                id: 's01-dp07-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s01-hazards", state: "success", points: 9 },
                }
            },
            {
                id: 's01-dp07-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s01-hazards", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp07-ignore',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision.',
                plugin: {
                    tracker: { id: "s01-hazards", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 08 -- 
            {
                id  : 's01-stand-off',
                type: 'narration',
                text: 'Review the Bomb Threat Stand-Off Card and/or the Mapview tool to identify a preferred evacuation distance.'
            },
            {
                id: 's01-dp08',
                type: 'dp',
                stem: '8. Your call in to headquarters also needs to include a recommended evacuation distance. Use the Mapview tool or the Bomb Threat Stand-Off Card in the Resources to identify the recommended evacuation distance for the type of IED.',
                options: [
                    '1200 ft.',
                    '1850 ft.',
                    '2400 ft.'
                ],
                plugin: {
                    tracker: { id: "s01-safety" }
                }
            },
            {
                id: 's01-dp08-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. The recommended stand-off distance for a van loaded with explosives is 2400 ft. Review the Bomb Threat Stand-Off Card job aid in the Resources section to determine the recommended stand-off distance for the type of IED you have identified.',
                plugin: {
                    tracker: { id: "s01-safety", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp08-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. The recommended stand-off distance for a van loaded with explosives is 2400 ft. Review the Bomb Threat Stand-Off Card job aid in the Resources section to determine the recommended stand-off distance for the type of IED you have identified.',
                plugin: {
                    tracker: { id: "s01-safety", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp08-r03',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! The recommended stand-off distance for a van loaded with explosives is 2400 ft. For more information on stand-off distances, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s01-safety", state: "success", points: 8 },
                }
            },
            {
                id: 's01-dp08-ignore',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision. If you are having trouble, review the Bomb Threat Stand-Off Card in the Resources section for some tips.',
                plugin: {
                    tracker: { id: "s01-safety", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 09 --
            
            {
                id: "s01-dp09-intro",
                type: "narration",
                text: "Before you call in to headquarters, take 60 seconds to perform a secondary sweep of the area. Use the arrow keys on your keyboard to conduct the secondary sweep."
            },
            {
                id: 's01-dp09',
                type: 'dp-multi',
                stem: '9. What information do you need to include in your report to headquarters? (Answer requires more than one selection.)',
                answers: [1,1,1,0,0],
                options: [
                    'Vehicle-borne IED in front of the Federal Courthouse.',
                    'Threats and hazards include glass and debris, courthouse portico, and various infrastructure elements including a gas main.',
                    'Recommended evacuation distance is 2400 ft.',
                    'There are no immediate threats or hazards in the environment.',
                    'Recommended evacuation distance is 150 ft.'
                ],
                plugin: {
                    tracker: { id: "s01-report" }
                }
            },
            {
                id: 's01-dp09-r01',
                type: 'popup',
                title: 'Feedback',
                text: 'Correct! You should call in a Vehicle-borne IED in front of the courthouse, threats and hazards including building glass and debris and the courthouse portico, and a recommended evacuation distance of 2400 ft. ',
                plugin: {
                    tracker: { id: "s01-report", state: "success", points: 8 },
                }
            },
            {
                id: 's01-dp09-r02',
                type: 'popup',
                title: 'Feedback',
                text: 'Incorrect. You should call in a Vehicle-borne IED in front of the courthouse, threats and hazards including building glass and debris and the courthouse portico, and a recommended evacuation distance of 2400 ft.',
                plugin: {
                    tracker: { id: "s01-report", state: "failure", points: 0 },
                }
            },
            {
                id: 's01-dp09-ignore',
                type: 'popup',
                title: 'Feedback',
                text: 'You did not respond within the time allowed. You need to make a decision.'
            },
            
            // -- DP 10 --
            
            {
                id      : 's01-dp10',
                type    : 'dp',
                stem    : 'You\'ve called in a situation report to higher command, and additional responders are beginning to arrive on scene. What should you do next?',
                options : [
                    'Conduct a threat assessment',
                    'Cordon the area'
                ],
                plugin: {
                    tracker: { id: "s01-cordon" }
                }
            },
            {
                id    : 's01-dp10-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Your next action is to assist other units with cordoning the area at the recommended evacuation distance. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s01-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's01-dp10-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Your next action is to assist other units with cordoning the area at the recommended evacuation distance. For more information on cordoning the area, review the Five Cs job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s01-cordon", state: "success", points: 8 },
                }
            },
            {
                id    : 's01-dp10-ignore',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to make a decision. You should review the Five Cs job aid to develop a better understanding of the actions you should take in an IED threat situation.',
                plugin: {
                    tracker: { id: "s01-cordon", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 11 --
            
            {
                id      : 's01-dp11',
                type    : 'dp',
                stem    : 'Once you have cordoned off the area around the IED to the recommended stand-off distance, what is your responsibility?',
                options : [
                    'Control the area at the appropriate stand-off distance',
                    'Return to headquarters to brief higher command'
                ],
                plugin: {
                    tracker: { id: "s01-control" }
                }
            },
            {
                id    : 's01-dp11-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Your next action is to control the area at the recommended evacuation distance. For more information, review the Five Cs job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s01-control", state: "success", points: 8 },
                }
            },
            {
                id    : 's01-dp11-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Your next action is to control the area at the recommended evacuation distance. You should review the Five Cs job aid in the Resources section for a better understanding of how you should respond to an IED threat.',
                plugin: {
                    tracker: { id: "s01-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's01-dp11-ignore',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to make a decision. If you’re having trouble, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s01-control", state: "ignored", points: 0 },
                }
            },
            
            // -- DP 12 -- 
            
            {
                id      : 's01-dp12',
                type    : 'dp-multi',
                stem    : 'What information do you need to provide to the Lead Bomb Tech? (Answer requires more than one selection.)',
                answers : [1,1,1,0,0],
                options : [
                    'Vehicle-borne IED in a van',
                    '4 55-gallon drums of suspected explosive material',
                    'Wires are leading from the drums to the interior light in the ceiling',
                    'Stand-off distance is 70 ft',
                    'The van is a rental'
                ],
                plugin: {
                    tracker: { id: "s01-brief" }
                }
            },
            {
                id    : 's01-dp12-r01',
                type  : 'narration',
                title : 'Feedback',
                text  : 'That’s good awareness and a complete briefing on your part, Officer.',
                plugin: {
                    tracker: { id: "s01-brief", state: "success", points: 9 },
                }
            },
            {
                id    : 's01-dp12-r02',
                type  : 'narration',
                title : 'Feedback',
                text  : 'Your information is incomplete. I’ll have to send someone in to take a closer look.',
                plugin: {
                    tracker: { id: "s01-brief", state: "failure", points: 0 },
                }
            },
            {
                id    : 's01-dp12-ignore',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s01-brief", state: "ignored", points: 0 },
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
                        id    : "s01-respond",
                        title : "Respond to dispatch call",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-investigate",
                        title : "Investigate the unoccupied vehicle",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-threat",
                        title : "Identify the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-components",
                        title : "Identify the IED components",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-clear",
                        title : "Clear the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-call",
                        title : "Call in the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-info",
                        title : "Call in information",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-assess",
                        title : "Conduct the threat assessment",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-hazards",
                        title : "Identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-safety",
                        title : "Identify the recommended stand-off distance.",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-report",
                        title : "Report the recommended stand-off distance, threats and hazards, IED type.",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-cordon",
                        title : "Cordon the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-control",
                        title : "Control the area",
                        state : "incomplete"
                    },
                    {
                        id    : "s01-brief",
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
                        aden.fsm.acenario01.trigger('move-start');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "van",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario01.trigger('move-van');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "cafe",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario01.trigger('move-cafe');
                    }
                },
                {
                    "num"       : 0,
                    "name"      : "car",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario01.trigger('move-car');
                    }
                }
            ]
        }
    };
    
    return scenario;
});
