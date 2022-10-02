define(function(require){

    var $        = require('jquery'),
        _        = require('lodash'),
        aden     = require('adayana/aden/engine'),
        debug    = require('adayana/debug/debug'),
        preload  = require('adayana/modules/preloadScreen'),
        mediator = require('adayana/modules/mediatorShim');

    var scenario = {
        "id" : "scenario05",

        // -- SETTINGS --
        "fsm"          : 'scenario05',
        "scene"        : 'exitview',
        "target"       : null,
        "xmlPath"      : '%HTMLPATH%/files/assets/panos/Scenario05/level.xml',
        "resetObjects" : true,
        "totalPoints"  : 100,
		"passingScore" : 80,

        // -- EVENT HANDLERS --
        "onLoad": function(){
            preload.setMessage('Loading Panorama Environment');
            aden.plugin.radio.setFSM( aden.fsm.scenario05 );
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
                id    : "s05-cin01",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_05/S05_Cin01.mp4'
                }
            },
            {
                id    : "s05-cin02",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_05/S05_Cin02.mp4'
                }
            },
            {
                id    : "s05-cin03",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_05/S05_Cin03.mp4'
                }
            },
            {
                id    : "s05-cin04",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_05/S05_Cin04.mp4'
                }
            },
            {
                id    : "s05-cin05",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_05/S05_Cin05.mp4'
                }
            },
            {
                id    : "s05-tech-positive",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_05/S05_Cin04a.mp4'
                }
            },
            {
                id    : "s05-tech-negative",
                type  : "video",
                media : {
                    'm4v': 'files/assets/video/cinematics/scenario_05/S05_Cin04b.mp4'
                }
            },
            {
                id: "s05-bomb-tech",
                type: "image",
                src  : "files/assets/images/screens/scenario_05/bomb-tech.jpg"
            },
            {
                id: "s05-still-cin02",
                type: "image",
                src  : "files/assets/images/screens/scenario_05/cinematic02.jpg"
            },
            
            
            
            {
                id: "s05-intro-screen",
                type: "image",
                src  : "files/assets/images/screens/scenario_05/intro.jpg"
            },
            {
                id  : "s05-intro",
                type: "popup",
                text: 'Your role in this scenario is that of a first responder dispatched to an emergency situation at the local high school.'
            },

            // Dispatch

            {
                id   : 's05-dispatch-call-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S05_start_a.mp3'
            },
            {
                id    : 's05-dispatch-call-text',
                type  : 'narration',
                text  : 'All units respond to Central High School. The principal of the school reports a student has killed himself with a gun in the library. Situation may involve hostages.'
            },
            {
                id    : 's05-dispatch-response',
                type  : 'narration',
                text  : 'Click the microphone to respond.'
            },
            {
                id    : "s05-dispatch-warning",
                type  : "narration",
                title : "Warning",
                text  : "You did not respond to the dispatch call immediately. Click the microphone to respond."
            },
            {
                id   : 's05-dispatch-reply-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/Response_Acknowledged.mp3'
            },
            {
                id    : 's05-dispatch-reply-text',
                type  : 'narration',
                text  : 'Response acknowledged.',
                plugin: {
                    tracker: { id: "s05-respond", state: "success", points: 0 },
                }
            },

            // Action
            /*
             * Panorama from the hallway. Arrow on floor pointing in the direction of the library.
             */

            {
                id    : 's05-move-prompt',
                type  : 'narration',
                text  : 'Click the arrow to approach the library.'
            },

            // when user does not move forward after 10 seconds...

            {
                id   : 's05-dispatch02-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S05_start_b.mp3'
            },
            {
                id    : 's05-dispatch02-text',
                type  : 'narration',
                text  : 'All units, we need confirmation of the situation inside the library at the high school. Approach with caution.'
            },

            /*
             * Cinematic (S05_Cin01) of moving through the hallway to a vantage point where the
             * interior of the library is visible.
             */

            /*
             * Panorama view from just outside the library.
             * From this point of view, the learner is able to see inside the library.
             * The suspect is face down on the floor. A handgun is on the floor a few feet away.
             * The librarian and students are huddled next to the tables near the entrance.
             * There are devices visible that have been attached to the entrance door, and
             * another exit door located across the room from the entrance. These devices
             * are made from pipes with end caps, wires, batteries, and switches taped to
             * the doors.
             */

            // Continue panorama view from Scenario Startup.

            {
                id   : 's05-dp01',
                type : 'dp',
                stem : '1. You are the first responder on the scene. What action do you need to take?',
                options: [
                    'Identify yourself and ask the librarian what is happening inside the library.',
                    'Retreat back down the hall from the library and wait for assistance.',
                    'Open the entrance door and enter the library.'
                ],
                plugin: {
                    tracker: { id: "s05-action" },
                }
            },
            {
                id    : 's05-dp01-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You should take immediate action to determine what is happening. ',
                plugin: {
                    tracker: { id: "s05-action", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp01-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You should take immediate action to determine what is happening.',
                plugin: {
                    tracker: { id: "s05-action", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp01-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You should take immediate action to determine what is happening.',
                plugin: {
                    tracker: { id: "s05-action", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp01-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s05-action", state: "failure", points: 0 },
                }
            },

            /*
             * Initiate a cinematic (S05_Cin02) with the librarian looking up and responding,
             * “He shot himself. I think he’s dead. He said he was putting bombs on the doors
             * so that if anyone tried to get in the bombs would explode.”
             */

            {
                id   : 's05-dp02',
                type : 'dp',
                stem : '2. The librarian says there are bombs on the doors. What should you do next?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s05-confirm" },
                }
            },
            {
                id    : 's05-dp02-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! First you should CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s05-confirm", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp02-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. First you should CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s05-confirm", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp02-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. First you should CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s05-confirm", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp02-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. First you should CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s05-confirm", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp02-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. First you should CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s05-confirm", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp02-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s05-confirm", state: "failure", points: 0 },
                }
            },

            // Return to panorama FPV at the library entrance.

            {
                id   : 's05-dp03',
                type : 'dp-multi',
                stem : '3. You need to CONFIRM the IED threat. What IED components can you positively identify? (Answer requires more than one selection.)',
                answers: [1,0,0,1,0],
                options: [
                    'Container.',
                    'Switch.',
                    'Initiator.',
                    'Power source.',
                    'No recognizable IED components.'
                ],
                plugin: {
                    tracker: { id: "s05-identify" },
                }
            },
            {
                id    : 's05-dp03-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You can positively identify the container and power source. You cannot positively identify the switch, initiator, or charge inside the pipe. You have completed the first of the Five Cs, which is to CONFIRM the IED threat.',
                plugin: {
                    tracker: { id: "s05-identify", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp03-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You can positively identify the container and power source. You cannot positively identify the switch, initiator, or charge inside the pipe.',
                plugin: {
                    tracker: { id: "s05-identify", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp03-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s05-identify", state: "failure", points: 0 },
                }
            },

            // Remain on FPV panorama from outside the entrance to the library. See Decision 4.
            // Continued from Decision 3. FPV panorama from outside the library entrance.

            {
                id   : 's05-dp04',
                type : 'dp',
                stem : '4. You have identified the IED components attached to the entrance and exit doors to the library. Which of the Five Cs should you perform next?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s05-clear" },
                }
            },
            {
                id    : 's05-dp04-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have confirmed the IED threat and need to CLEAR the immediate area. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp04-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You have confirmed the IED threat and need to CLEAR the immediate area. Tell the librarian to take the students away from the doors and take cover away from any windows. You would also look to shelter in place.',
                plugin: {
                    tracker: { id: "s05-clear", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp04-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have confirmed the IED threat and need to CLEAR the immediate area. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp04-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have confirmed the IED threat and need to CLEAR the immediate area. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp04-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You have confirmed the IED threat and need to CLEAR the immediate area. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-clear", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp04-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s05-clear", state: "failure", points: 0 },
                }
            },

            /*
             * Cinematic (S05_Cin03) of the librarian and students walking to another portion of
             * the room and taking cover behind a large table against the wall. Cut to FPV moving
             * back away from the entrance to the library and into a doorway across the hall to
             * take cover. Should still be in a position to see into the library through the
             * windows. See Decision 5.
             */

            // Continued from Decision 4. Panorama with FPV of the library entrance from the doorway across the hall.

            {
                id   : 's05-dp05',
                type : 'dp',
                stem : '5. Now that you have helped the librarian and students shelter in place and have taken steps to protect yourself, what is your next priority?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s05-call" },
                }
            },
            {
                id    : 's05-dp05-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CALL and report the IED threat to higher command. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp05-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CALL and report the IED threat to higher command. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp05-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! You need to CALL and report the IED threat to higher command. Your report should include a recommendation for a safe stand-off distance and identification of critical hazards in the environment.',
                plugin: {
                    tracker: { id: "s05-call", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp05-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CALL and report the IED threat to higher command. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp05-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. You need to CALL and report the IED threat to higher command. Review the Five Cs job aid in the Resources section for a better understanding of the correct response to a suspected IED.',
                plugin: {
                    tracker: { id: "s05-call", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp05-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s05-call", state: "failure", points: 0 },
                }
            },

            // Continue panorama with FPV of the library entrance from the doorway across the hall. See Decision 6.
            // Continue panorama from Decision 5 with FPV of the library entrance from the doorway across the hall.

            {
                id   : 's05-dp06',
                type : 'dp-multi',
                stem : '6. You need to report any critical hazards in the environment to higher command. What critical hazards have you observed? (Answer requires more than one selection.)',
                answers: [1,1],
                options: [
                    'Blast effects from pipe bombs on entrance and exit doors.',
                    'Fragmentation of structural and infrastructure components in the library, including glass from windows and light fixtures and splintered wood from desks, chairs, and bookshelves.'
                ],
                plugin: {
                    tracker: { id: "s05-hazards" },
                }
            },
            {
                id    : 's05-dp06-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s05-hazards", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp06-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. Threats/hazards from IEDs include blast and fragmentation effects to humans, structures, and infrastructure.',
                plugin: {
                    tracker: { id: "s05-hazards", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp06-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s05-hazards", state: "failure", points: 0 },
                }
            },

            // Continue panorama with FPV of the library entrance from the doorway across the hall.

            {
                id   : 's05-dp07',
                type : 'dp',
                stem : '7. You need to identify the recommended safe stand-off distance for the type of IED you have confirmed in the high school library. Use the Mapview tool or the Bomb Threat Stand-Off Card job aid to identify the safe stand-off distance, then select the safe stand-off distance from the list on the screen.',
                options: [
                    '640 ft.',
                    '860 ft.',
                    '1200 ft.',
                    '1850 ft.'
                ],
                plugin: {
                    tracker: { id: "s05-distance" },
                }
            },
            {
                id    : 's05-dp07-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1200 ft. is the recommended evacuation distance for a pipe bomb type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s05-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp07-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1200 ft. is the recommended evacuation distance for a pipe bomb type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s05-distance", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp07-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! 1200 ft. is the recommended evacuation distance for a pipe bomb type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s05-distance", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp07-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. 1200 ft. is the recommended evacuation distance for a pipe bomb type of IED. You should recommend this stand-off distance to higher command when you call in.',
                plugin: {
                    tracker: { id: "s05-distance", state: "failure", points: 0 },
                }
            },

            // Continue panorama with FPV of the library entrance from the doorway across the hall.

            {
                id   : 's05-dp08',
                type : 'dp',
                stem : '8. You have determined the critical hazards in the environment and safe stand-off distance for the IED type you are dealing with. What is the next step for responding to this IED threat?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s05-cordon" },
                }
            },
            {
                id    : 's05-dp08-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is for other responders to begin to CORDON the area around the school at the safe stand-off distance you recommended. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s05-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp08-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is for other responders to begin to CORDON the area around the school at the safe stand-off distance you recommended. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s05-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp08-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is for other responders to begin to CORDON the area around the school at the safe stand-off distance you recommended. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s05-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp08-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct! The next step is for other responders to begin to CORDON the area around the school at the safe stand-off distance you recommended.',
                plugin: {
                    tracker: { id: "s05-cordon", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp08-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The next step is for other responders to begin to CORDON the area around the school at the safe stand-off distance you recommended. You should review the Five Cs job aid in the Resources section for more information on cordoning the area.',
                plugin: {
                    tracker: { id: "s05-cordon", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp08-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s05-cordon", state: "failure", points: 0 },
                }
            },

            /*
             * Continue panorama with FPV of the library entrance from the doorway across the hall.
             */

            {
                id   : 's05-dp09-intro-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S05_D8.mp3'
            },
            {
                id    : 's05-dp09-intro-text',
                type  : 'narration',
                text  : 'All units assist with cordoning of the area around the high school if possible. Recommended cordon perimeter is 1200 ft. from the school.'
            },

            {
                id   : 's05-dp09',
                type : 'dp',
                stem : '9. You are maintaining your watch on the library from behind a position of cover while other first responders are establishing the cordon perimeter. There is one more key task in the Five Cs to accomplish. What is it?',
                options: [
                    'Confirm',
                    'Clear',
                    'Call',
                    'Cordon',
                    'Control'
                ],
                plugin: {
                    tracker: { id: "s05-control" },
                }
            },
            {
                id    : 's05-dp09-r01',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The last step in the Five Cs is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s05-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp09-r02',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The last step in the Five Cs is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s05-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp09-r03',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The last step in the Five Cs is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s05-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp09-r04',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Incorrect. The last step in the Five Cs is to CONTROL the area around the cordon perimeter. You should review the Five Cs job aid in the Resources section for more information on controlling the area.',
                plugin: {
                    tracker: { id: "s05-control", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp09-r05',
                type  : 'popup',
                title : 'Feedback',
                text  : 'Correct. The last step in the Five Cs is to CONTROL the area around the cordon perimeter.',
                plugin: {
                    tracker: { id: "s05-control", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp09-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision. If you’re having trouble getting started, review the Five Cs job aid in the Resources section for some hints.',
                plugin: {
                    tracker: { id: "s05-control", state: "failure", points: 0 },
                }
            },

            /*
             * Continue panorama with FPV of the library entrance from the doorway across the hall.
             */

            {
                id   : 's05-dp10-intro-audio',
                type : 'audio',
                file : 'files/assets/audio/dispatcher/S05_D9.mp3'
            },
            {
                id    : 's05-dp10-intro-text',
                type  : 'narration',
                text  : 'Unit at the library entrance, the bomb unit is on scene. The Bomb Tech Lead will meet you in the hallway leading to the library entrance.'
            },
			{
				id: 's05-dp10-bomb-tech',
				type: 'narration',
				text: 'Officer, I am the lead bomb tech. I need you to brief me on the IED threat situation.'
			},

            {
                id   : 's05-dp10',
                type : 'dp-multi',
                stem : '10. What confirmed information goes into your brief for the Bomb Tech Lead? Click on each item you want to include in your brief, and then click Submit. (Answer requires more than one selection.)',
                answers: [1,1,0,0,0,1,0],
                options: [
                    'Confirmed IED components on entrance and exit doors.',
                    'Containers.',
                    'Main charges.',
                    'Switches.',
                    'Initiators.',
                    'Power source.',
                    'Five people sheltering in place in the library.'
                ],
                plugin: {
                    tracker: { id: "s05-brief" },
                }
            },
            {
                id    : 's05-dp10-r01',
                type  : 'narration',
                title : 'Feedback',
                text  : 'That’s good awareness and a complete briefing on your part, Officer.',
                plugin: {
                    tracker: { id: "s05-brief", state: "success", points: 10 },
                }
            },
            {
                id    : 's05-dp10-r02',
                type  : 'narration',
                title : 'Feedback',
                text  : 'Your information is incomplete. I’ll have to send someone in to take a closer look.',
                plugin: {
                    tracker: { id: "s05-brief", state: "failure", points: 0 },
                }
            },
            {
                id    : 's05-dp10-warning',
                type  : 'popup',
                title : 'Warning',
                text  : 'You need to make a decision.',
                plugin: {
                    tracker: { id: "s05-brief", state: "failure", points: 0 },
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
                        id    : "s05-respond",
                        title : "Respond to dispatch call",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-action",
                        title : "Take immediate action",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-confirm",
                        title : "Confirm the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-identify",
                        title : "Identify the IED threat",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-clear",
                        title : "Clear the immediate area",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-call",
                        title : "Report the IED threat to higher command",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-hazards",
                        title : "Conduct a threat/hazard assessment to identify threats and hazards in the environment",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-distance",
                        title : "Identify safe stand-off distance and recommend cordon perimeter.",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-cordon",
                        title : "Cordon",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-control",
                        title : "Control",
                        state : "incomplete"
                    },
                    {
                        id    : "s05-brief",
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
                    "name"      : "entrance",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"   : function() {
                        aden.fsm.scenario05.trigger('move-entrance');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "exitview",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario05.trigger('move-exitview');
                    }
                },
                {
                    "num"       : 1,
                    "name"      : "acrosshallway",
                    "position"  : { x: -9.5, y: 0.0, z: 0.3 },
                    "visited"   : false,
                    "navpoints" : [],
                    "layers"    : [],
                    "onVisit"    : function(){
                        aden.fsm.scenario05.trigger('move-acrosshallway');
                    }
                }
            ]
        }
    };

    return scenario;
});
