define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');
        
    var scenario = {
        "id" : "scenario04",
        
        // -- SETTINGS --
        "fsm"          : 'scenario04',
        "scene"        : 'van',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/Scenario04/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 80,
        
        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM( aden.fsm.scenario04 );
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
                id    : "s04-cin01",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_04/S04_Cin01.mp4'
                }
            },
            {
                id    : "s04-cin02",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_04/S04_Cin02.mp4'
                }
            },
            {
                id    : "s04-cin03",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_04/S04_Cin03.mp4'
                }
            },
            {
                id    : "s04-cin04",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_04/S04_Cin04.mp4'
                }
            },
            {
                id    : "s04-cin05",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_04/S04_Cin05.mp4'
                }
            },
            {
                id    : "s04-tech-positive",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_04/S04_Cin05a.mp4'
                }
            },
            {
                id    : "s04-tech-negative",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_04/S04_Cin05b.mp4'
                }
            },
            {
                id   : 's04-bomb-tech',
                type : 'image',
                src  : "files/assets/images/screens/scenario_04/bomb-tech.jpg"
            },  
            
            // -- intro --
            {
                id  : "s04-intro",
                type: "popup",
                text: "Your role in this scenario is that of an emergency medical technician responding to a call for medical assistance."
            },
            {
                id   : 's04-start-screen',
                type : 'image',
                src  : "files/assets/images/screens/scenario_04/intro.jpg"
            },            
            {
                id   : 's04-dispatch-call-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S04_start.mp3'
            },
            {
                id    : 's04-dispatch-call-text',
                type  : 'narration',
                text  : 'Request emergency medical response to 24-hundred North County Road 21-hundred. Reportee says she heard a very loud "pop" coming from a neighbor\'s mobile home.'
            },
            {
                id    : 's04-dispatch-response',
                type  : 'narration',
                text  : 'Click the microphone to respond to the dispatch call.'
            },
            {
                id    : 's04-dispatch-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You did not respond to the dispatch call immediately. Click the microphone to respond.'
            },
            {
                id  : 's04-dispatch-reply-audio',
                type: 'audio',
                file: 'files/assets/audio/dispatcher/Response_Acknowledged.mp3'
            },
            {
                id    : "s04-dispatch-reply-text",
                type  : "narration",
                text  : "Response acknowledged."
            },
            
            
            // -- DP 01 --
            
            {
                id   : 's04-dp01',
                type : 'dp',
                stem : '1. You are the first responder on scene. You have been called to this location and you find a man lying in the doorway of one of the residences. What immediate action should you take?',
                options: [
                    'Leave the man where he is, stay back from the trailer, and wait for additional assistance to arrive.', 
                    'Render assistance to the man and try to determine his current medical status.',
                    'Go inside the trailer to try to determine what caused the loud sound and the man’s injuries.'
                ],
                plugin: {
                    tracker: { id: "s04-action" },
                }
            },
            {
                id    : 's04-dp01-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The man’s life may be in danger. You need to render assistance.',
                plugin: {
                    tracker: { id: "s04-action", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp01-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! This man’s life may be in danger, and you need to render assistance.',
                plugin: {
                    tracker: { id: "s04-action", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp01-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The man’s life may be in danger. You need to render assistance.',
                plugin: {
                    tracker: { id: "s04-action", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp01-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s04-action", state: "failure", points: 0 },
                }
            },
            
            // -- DP 02 --
            
            {
                id    : 's04-dp02-intro',
                type  : 'narration',
                text  : 'You are assisting the unconscious man at the doorway to a mobile home. From this vantage point, what IED components can you confirm inside the mobile home? Take 60 seconds to assess the situation.'
            },

            {
                id   : 's04-dp02',
                type : 'dp-multi',
                stem : '2. You had 60 seconds to scan the inside of the mobile home. What IED components did you see? (Answer requires more than one selection.)',
                answers: [1,1,1,1,0],
                options: [
                    'Threaded pipe sections and pipe end caps.',
                    'Wires and light bulbs.',
                    'Batteries.',
                    'Chemicals.',
                    'No recognizable IED components in view.'
                ],
                plugin: {
                    tracker: { id: "s04-components" },
                }
            },
            {
                id    : 's04-dp02-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You have identified all of the necessary components for an IED: the container, main charge, initiator, power source, and switch. You have completed the first of the Five Cs, which is to CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s04-components", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp02-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. All of the components needed to build an IED are in view inside the mobile home. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s04-components", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp02-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s04-components", state: "failure", points: 0 },
                }
            },

            // -- DP 03 --
            
            
            {
                id   : 's04-dp03',
                type : 'dp',
                stem : '3. Now that you’ve CONFIRMED an IED threat is present in this mobile home, what is the next action you should take?',
                options: [
                    'Clear the unconscious man, any occupants in the other mobile homes, and yourself from the immediate area of the mobile home.',
                    'Leave the unconscious man in the doorway and move away from the IED threat in the mobile home.',
                    'Enter the mobile home to get a closer look at the materials on the tables.',
                    'Determine the safe stand-off distance for the type of IED you confirmed inside the mobile home.'
                ],
                plugin: {
                    tracker: { id: "s04-clear" },
                }
            },
            {
                id    : 's04-dp03-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Once you have confirmed the IED threat, the next of the Five Cs is to CLEAR the area. You need to move the unconscious man, any neighbors, and yourself away from the laboratory site.',
                plugin: {
                    tracker: { id: "s04-clear", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp03-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have confirmed the IED threat, the next of the Five Cs is to CLEAR the area. You need to move the unconscious man, any neighbors, and yourself away from the laboratory site.',
                plugin: {
                    tracker: { id: "s04-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp03-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have confirmed the IED threat, the next of the Five Cs is to CLEAR the area. You need to move the unconscious man, any neighbors, and yourself away from the laboratory site.',
                plugin: {
                    tracker: { id: "s04-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp03-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have confirmed the IED threat, the next of the Five Cs is to CLEAR the area. You need to move the unconscious man, any neighbors, and yourself away from the laboratory site.',
                plugin: {
                    tracker: { id: "s04-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp03-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s04-clear", state: "failure", points: 0 },
                }
            },
            
            // -- DP 04 --
            
            {
                id   : 's04-dp04',
                type : 'dp',
                stem : '4. You have cleared the unconscious man, the occupants of the neighboring mobile homes, and yourself from the immediate area of the IED threat. According to the Five Cs protocol, what should you do next?',
                options: [
                    'Call in the IED threat.',
                    'Cordon the area.',
                    'Control the area.'
                ],
                plugin: {
                    tracker: { id: "s04-call" },
                }
            },
            {
                id    : 's04-dp04-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command.',
                plugin: {
                    tracker: { id: "s04-call", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp04-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s04-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp04-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once you have cleared the immediate area of the IED threat, the next step in the Five Cs protocol is to CALL the threat in to higher command. You should review the Five Cs job aid in the Resources section for a better understanding of how to respond to an IED threat.',
                plugin: {
                    tracker: { id: "s04-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp04-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s04-call", state: "failure", points: 0 },
                }
            },
            
            // -- DP 05 --
            
            {
                id   : 's04-dp05',
                type : 'dp-multi',
                stem : '5. You need to call in the IED threat. What information will you report? (Answer requires more than one selection.)',
                answers: [1,1,1,1,0],
                options: [
                    'Confirmed IED threat.',
                    'Individual in need of medical assistance.',
                    'Verify your location.',
                    'Have cleared the immediate area around the IED threat.',
                    'Confirmed an IED threat does not exist.'
                ],
                plugin: {
                    tracker: { id: "s04-report" },
                }
            },
            {
                id    : 's04-dp05-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You have provided a complete report of the IED threat and other key facts accurately and concisely.',
                plugin: {
                    tracker: { id: "s04-report", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp05-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have not provided a complete report of the IED threat and other key facts accurately and concisely.',
                plugin: {
                    tracker: { id: "s04-report", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp05-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to respond.',
                plugin: {
                    tracker: { id: "s04-report", state: "failure", points: 0 },
                }
            },
            
            // -- DP 06 --
            
            {
                id   : 's04-dp06-intro',
                type : 'narration',
                text : 'Use the controls to look around and assess the threats and hazards in the environment. You have 60 seconds to complete this assessment.'
            },
            {
                id   : 's04-dp06',
                type : 'dp-multi',
                stem : '6. Time is up. Select the threats and hazards in the environment from the list you see here. (Answer requires more than one selection.)',
                answers: [1,1,1,1],
                options: [
                    'IED components inside the mobile home.',
                    'External propane tank.',
                    'High-voltage electrical tower.',
                    'Electrical and propane connections to the mobile homes.'
                ],
                plugin: {
                    tracker: { id: "s04-hazards" },
                }
            },
            {
                id    : 's04-dp06-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s04-hazards", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp06-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s04-hazards", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp06-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s04-hazards", state: "failure", points: 0 },
                }
            },
            
            // -- DP 07 --
            {
                id: "s04-dp07-intro",
                type: "popup",
                title: "Notice",
                text: "Other responders will be arriving on scene soon. You need to identify a safe stand-off distance for an assembly area, and to help determine whether there are other neighbors who need to be evacuated."
            },
            {
                id   : 's04-dp07',
                type : 'dp',
                stem : '7. Use the Mapview tool or the Bomb Threat Stand-Off Card job aid to identify the recommended safe stand-off distance, and then select the safe stand-off distance from the list on the screen.',
                options: [
                    '110 ft.',
                    '150 ft.',
                    '1200 ft.',
                    '1900 ft.'
                ],
                plugin: {
                    tracker: { id: "s04-distance" },
                }
            },
            {
                id    : 's04-dp07-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 110 ft. is the Mandatory Evacuation Distance for a suicide bomber. For more information on stand-off distances, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s04-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp07-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 150 ft. is the Mandatory Evacuation Distance for briefcase/suitcase bomb. For more information on stand-off distances, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s04-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp07-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! 1200 ft. is the recommended safe stand-off distance for a pipe bomb. Once you have identified the safe stand-off distance, call that in to higher command.',
                plugin: {
                    tracker: { id: "s04-distance", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp07-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1900 ft. is the safe stand-off distance for a car bomb. For more information on stand-off distances, review the Bomb Threat Stand-Off Card job aid in the Resources section.',
                plugin: {
                    tracker: { id: "s04-distance", state: "failure", points: 0 },
                }
            },
                        
            // -- DP 08 --
                        
            {
                id   : 's04-dp08-intro-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S04_D8.mp3'
            },
            {
                id    : 's04-dp08-intro-text',
                type  : 'narration',
                text  : 'Additional units arriving on scene of confirmed pipe bomb IED.'
            },
            {
                id   : 's04-dp08',
                type : 'dp',
                stem : '8. You have identified the safe stand-off distance, and additional emergency personnel are arriving on scene. Which of the Five Cs must be performed next? Select one response from the list.',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s04-cordon" },
                }
            },
            {
                id    : 's04-dp08-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s04-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp08-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s04-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp08-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s04-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp08-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The next Five Cs action to be performed is to CORDON the area. At this time you will move your emergency vehicle with the unconscious man to the nearby staging area.',
                plugin: {
                    tracker: { id: "s04-cordon", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp08-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next Five Cs action to be performed is to CORDON the area. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s04-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp08-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s04-cordon", state: "failure", points: 0 },
                }
            },
            
            // -- DP 09 --
            
            {
                id   : 's04-dp09-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S04_D8.mp3'
            },
            {
                id    : 's04-dp09-intro',
                type  : 'narration',
                text  : 'Additional units arriving on scene of confirmed pipe bomb IED.'
            },
            {
                id   : 's04-dp09',
                type : 'dp',
                stem : '9. Other emergency personnel have cordoned the area at the safe stand-off distance you identified. Which of the Five Cs still must be performed for this response? Select one response from the list.',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s04-control" },
                }
            },
            {
                id    : 's04-dp09-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once the area is cordoned at the safe stand-off distance, the area must be CONTROLLED to maintain public safety. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s04-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp09-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once the area is cordoned at the safe stand-off distance, the area must be CONTROLLED to maintain public safety. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s04-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp09-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once the area is cordoned at the safe stand-off distance, the area must be CONTROLLED to maintain public safety. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s04-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp09-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Once the area is cordoned at the safe stand-off distance, the area must be CONTROLLED to maintain public safety. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s04-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp09-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Once the area is cordoned at the safe stand-off distance, the area must be CONTROLLED to maintain public safety.',
                plugin: {
                    tracker: { id: "s04-control", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp09-warning',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s04-control", state: "failure", points: 0 },
                }
            },
            
            // Panorama view looking out the driver’s side window of the ambulance toward the police car. 
                        
            {
                id   : 's04-dp10-audio',
                type : 'audio',
                file : 'files/assets/audio/placeholder.mp3'
            },
            {
                id    : 's04-dp10-intro',
                type  : 'narration',
                text  : 'Officer, I am the lead bomb tech. I need you to brief me on the IED threat situation.'
            },
            {
                id   : 's04-dp10',
                type : 'dp-multi',
                stem : '10. Keep your brief back to the Bomb Tech Lead focused. What information do you need to provide? (Answer requires more than one selection.)',
                answers: [1,1,1,0,1,0],
                options: [
                    'Visible IED components in the front room of the mobile home are pipe bomb type.',
                    'Bottles of chemicals.',
                    'Light bulbs and wires.',
                    'Contact switches.',
                    'Batteries.',
                    'Black powder.'
                ],
                plugin: {
                    tracker: { id: "s04-brief" },
                }
            },
            {
                id    : 's04-dp10-r01',
                type  : 'narration',
                title : 'Feedback',
                text  : 'That’s good awareness and a complete briefing on your part, Officer.',
                plugin: {
                    tracker: { id: "s04-brief", state: "success", points: 10 },
                }
            },
            {
                id    : 's04-dp10-r02',
                type  : 'narration',
                title : 'Feedback',
                text  : 'Your information is incomplete. I’ll have to send someone in to take a closer look.',
                plugin: {
                    tracker: { id: "s04-brief", state: "failure", points: 0 },
                }
            },
            {
                id    : 's04-dp10-warning',
                type  : 'popup',
                title : 'Feedback',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s04-brief", state: "failure", points: 0 },
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
                        pos_inner : -107,
                        pos_outer : -220
                    },
                    {
                        id        : "blast3",
                        name      : "Briefcase/Suitcase",
                        inner     : 150,
                        outer     : 1850,
                        pos_inner : -107,
                        pos_outer : -220
                    },
                    {
                        id        : "blast4",
                        name      : "Car",
                        inner     : 320,
                        outer     : 1900,
                        pos_inner : -107,
                        pos_outer : -220
                    },
                    {
                        id        : "blast5",
                        name      : "SUV/Van",
                        inner     : 400,
                        outer     : 2400,
                        pos_inner : -107,
                        pos_outer : -220
                    },
                ]
            },
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
                        id    : "s04-action",
                        title : "Take immediate action",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-components",
                        title : "Identify IED components",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-call",
                        title : "Report the IED threat to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-report",
                        title : "Report the IED threat to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-hazards",
                        title : "Identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-distance",
                        title : "Identify preferred evacuation distance.",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-cordon",
                        title : "Cordon",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-control",
                        title : "Control",
                        state : "incomplete"
                    },
                    {
                        id    : "s04-brief",
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
                    "name"      : "van",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario04.trigger('move-van');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "trailerdoor",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario04.trigger('move-trailerdoor');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "road",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario04.trigger('move-road');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "ambulance",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario04.trigger('move-ambulance');
                    }
                }
            ]
        }
    };
    
    return scenario;
});
