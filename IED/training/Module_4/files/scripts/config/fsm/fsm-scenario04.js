define(function (require) {
    'use strict';
    
    var $               = require('jquery'),
        _               = require('lodash'),
        aden            = require('adayana/aden/engine'),
        debug           = require('adayana/debug/debug'),
        Splash          = require('modules/screens/splash'),
        NavScreen       = require('modules/screens/navScreen'),
        SelectionScreen = require('modules/screens/selectionScreen'),
        ScenarioScreen  = require('modules/screens/scenarioScreen'),
        mediator        = require('adayana/modules/mediatorShim');
    
    var currAudio, currVideo, currPopup, currDP, currScreen;
        
    var WAIT_TIME      = 60000,// 30000,
		TIME_SHORT_YEL = 30000,// 3000,
        TIME_SHORT_RED = 50000,// 6000,
        TIME_SHORT_END = 60000,// 10000,
        TIME_SPLIT_1   = 20000,// 8000,
        TIME_SPLIT_2   = 30000,// 10000,
        TIME_SPLIT_3   = 20000,// 8000,
        TIME_SPLIT_4   = 30000,// 10000,
        TIME_LONG_YEL  = 30000,// 10000,
        TIME_LONG_RED  = 50000,// 15000,
        TIME_LONG_END  = 60000;// 20000;
    
    // === helper functions === 
    
    function setupRadioCall(image, audio, popup) {
        aden.plugin.radio.addGlow();
        if (image) {
            currScreen = aden.objects.load(image);
        }
        if (audio) {
            currAudio = aden.objects.load(audio);
        }
        if (popup) {
            currPopup = aden.objects.load(popup);
        }
    }
    
    function clearRadioCall() {
        if (currPopup) {
            currPopup.destroy();
        }
        aden.plugin.radio.removeGlow();
    }
    
    function setupRadioReply(time1, time2, time3) {
        aden.plugin.radio.addGlow();
        aden.plugin.radio.activate();
        aden.plugin.status.add(time1, function () { aden.plugin.status.set('yellow'); });
        aden.plugin.status.add(time2, function () { aden.plugin.status.set('red'); });
        aden.plugin.status.add(time3, function () { aden.fsm.scenario04.trigger('ignore'); });
        aden.plugin.status.setTime(time3);
    }
    
    function clearRadioReply() {
        aden.plugin.status.clear();
        aden.plugin.radio.deactivate();
        aden.plugin.radio.removeGlow();
    }
    
    function setupDP(dp) {
        aden.objects.load(dp);
    }
    
    function setupTimedObj(dp, warning) {
        aden.objects.load(dp);
        aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
        aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
        aden.plugin.status.add(TIME_LONG_END, function () {
            aden.objects.load(warning);
            aden.plugin.status.clearTime();
        });
        aden.plugin.status.setTime(TIME_LONG_END);
    }
    
    function setupSplitDP1(dp) {
        currDP = aden.objects.load(dp);
        aden.plugin.status.set('green');
        aden.plugin.status.add(TIME_SPLIT_1, function () { aden.plugin.status.set('yellow'); });
        aden.plugin.status.add(TIME_SPLIT_2, function () { aden.fsm.scenario04.trigger('ignored'); });
        aden.plugin.status.setTime(TIME_SPLIT_2);
    }
      
    function setupSplitDP2(dp, warning) {
        aden.objects.load(dp);
        aden.plugin.status.add(TIME_SPLIT_3, function () { aden.plugin.status.set('red'); });
        aden.plugin.status.add(TIME_SPLIT_4, function () {
            aden.objects.load(warning);
            aden.plugin.status.clearTime();
        });
        aden.plugin.status.setTime(TIME_SPLIT_4);
    }
    
    // Scenario 02 FSM
    
    var fsm = {
        id      : 'scenario04',
        type    : 'graph',
        initial : 'idle',
        inactive: 'idle',
        debug   : '#fsm-game-state',
        
        states  : [
            {
                id: "idle",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                },
                branches : [
                    { id: "start", target: "start" }
                ]
            },
            
            /*
             * First-person view (FPV) panorama of the mobile homes from the lane entrance looking 
             * toward the suspect trailer. This view should be far enough back to see both mobile 
             * homes, but not reveal significant details of the scene.
             */
            
            {
                id: "start",
                object: "s04-intro",
                onEnter: function () {
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('static');
                    currScreen = aden.objects.load('s04-start-screen');
                    aden.pano.hotspots.hideAll();
                },
                onExit: function () {},
                branches: [
                    { id: "popup-destroy", target: "dispatch01" }
                ]
            },
            {
                id: "dispatch01",
                onEnter: function () {
                    setupRadioCall(null, 's04-dispatch-call-audio', 's04-dispatch-call-text');
                },
                onExit: clearRadioCall,
                branches: [
                    { id: "audio-end", target: "dispatch01-reply" }
                ]
            },
            {
                id: "dispatch01-reply",
                onEnter: function () {
                    currPopup = aden.objects.load('s04-dispatch-response');
                    setupRadioReply(TIME_SHORT_YEL, TIME_SHORT_RED, TIME_SHORT_END);
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    clearRadioReply();
                },
                branches: [
                    { id: "ignore",      target: "dispatch01-warning" },
                    { id: "radio-click", target: "dispatch01-response" }
                ]
            },
            {
                id: "dispatch01-warning",
                onEnter: function () {
                    currPopup = aden.objects.load('s04-dispatch-warning');
                    aden.plugin.radio.addGlow();
                    aden.plugin.radio.activate();
                },
                onExit: function () {
                    clearRadioReply();
                    if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "radio-click", target: "dispatch01-response" }
                ]
            },
            {
                id: "dispatch01-response",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('s04-dispatch-reply-text');
                    currAudio = aden.objects.load('s04-dispatch-reply-audio');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "dp01" }
                ]
            },
            
             /*
             * FPV panorama from the lane looking at the front door to the suspect trailer. 
             * The trailer door is open and the body of a male subject is lying, face down, 
             * half in and half out of the door. 
             */
            
            {
                id: "dp01",
                onEnter: function () {
                    if (currScreen) {
                        currScreen.destroy();
                    }
                    aden.plugin.mode.setMode('pano');
					aden.pano.camera.face(130);
                    setupTimedObj('s04-dp01', 's04-dp01-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp01-r1" },
                    { id: "option1", target: "dp01-r2" },
                    { id: "option2", target: "dp01-r3" }
                ]
            },
            {
                id: 'dp01-r1',
                object: 's04-dp01-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic01" }
                ]
            },
            {
                id: 'dp01-r2',
                object: 's04-dp01-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic01" }
                ]
            },
            {
                id: 'dp01-r3',
                object: 's04-dp01-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic01" }
                ]
            },
            
            /*
             * (S04_Cin01) of moving to the front door of the trailer to assist the man. 
             * Transition to a panorama from the vantage point of just inside the front door. 
             * From this vantage point you can clearly see into the living room of the trailer 
             * and observe the “laboratory.”
             */
            {
                id: "cinematic01",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    aden.pano.load('trailerdoor');
                    currVideo = aden.objects.load('s04-cin01');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                branches: [
                    // if pano finishes loading during video, wait for end of video
                    { id: "move-trailerdoor", target: "cinematic-01-video-wait" },
                    // if video finishes before panorama, wait for pano to load
                    { id: "video-end", target: "cinematic-01-pano-wait" }
                ]
            },
            {
                // wait for pano to load
                // when pano loads, cleanup cinematic and go to dp 02 intro
                id: 'cinematic-01-pano-wait',
                onEnter: function () {},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "move-trailerdoor", target: "dp02-intro" }
                ]
            },
            {
                // wait for video to end
                id: 'cinematic-01-video-wait',
                onEnter: function(){},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp02-intro" }
                ]
            },

            // -- dp 02 -- 
            
            /*
             * Panorama from the entrance to the mobile home looking into the living room, 
             * which has been converted to a lab. Items in clear view should include: small 
             * propane burner, propane tank, bowls of ice, beakers, bottles of chemicals, 
             * weight scales, pseudoephedrine, articles of trash, pipe end caps, various 
             * lengths of threaded pipe sections, wires, light bulbs, batteries, trip wire, 
             * and contact switches.
             */
            
            {
                id: "dp02-intro",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s04-dp02-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario04.trigger('timeup');
                    });
                    aden.plugin.status.setTime(WAIT_TIME);
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: 'skip',   target: 'dp02' },
                    { id: 'timeup', target: 'dp02' }
                ]
            },
            {
                id: "dp02",
                onEnter: function () {
					aden.pano.camera.lookTo(96.12,66.75);
                    setupTimedObj('s04-dp02', 's04-dp02-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp02-r1" },
                    { id: "dp-wrong",   target: "dp02-r2" }
                ]
            },
            {
                id: 'dp02-r1',
                object: 's04-dp02-r01',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r2',
                object: 's04-dp02-r02',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            
            // -- dp 03 --
            
            {
                id: "dp03",
                onEnter: function () {

                    setupTimedObj('s04-dp03', 's04-dp03-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp03-r1" },
                    { id: "option1", target: "dp03-r2" },
                    { id: "option2", target: "dp03-r3" },
                    { id: "option3", target: "dp03-r4" }
                ]
            },
            {
                id: 'dp03-r1',
                object: 's04-dp03-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r2',
                object: 's04-dp03-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r3',
                object: 's04-dp03-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r4',
                object: 's04-dp03-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            
            /*
             * Cinematic (S04_Cin02) from the lane in between the two mobile homes. 
             * The unconscious man is now lying on the ground. Occupants of the neighboring mobile 
             * home exit and walk past and out of view. Jump to panorama.
             * 
             * Panorama from further up the lane toward the county road. 
             * Location is behind the emergency vehicle, which is parked facing the location of 
             * the two mobile homes. Neighbors are standing off to one side and farther back. 
             * The unconscious man is on the ground at the rear of the vehicle. See Decision 4.
             */
            {
                id: "cinematic02",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s04-cin02');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                    aden.pano.load('road');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "move-road", target: "cinematic-02-video-wait" },
                    { id: "video-end", target: "cinematic-02-pano-wait" }
                ]
            },
            {
                id: 'cinematic-02-pano-wait',
                onEnter: function () {},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "move-road", target: "dp04" }
                ]
            },
            {
                id: 'cinematic-02-video-wait',
                onEnter: function(){},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp04" }
                ]
            },
       
            // -- dp 04 -- 
            
            {
                id: "dp04",
                onEnter: function () {
					aden.pano.camera.lookTo(225.98277750163538,24.8226919253317);
                    setupTimedObj('s04-dp04', 's04-dp04-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp04-r1" },
                    { id: "option1", target: "dp04-r2" },
                    { id: "option2", target: "dp04-r3" }
                ]
            },
            {
                id: 'dp04-r1',
                object: 's04-dp04-r01',
                branches: [
                    { id: "popup-destroy", target: "dp05" }
                ]
            },
            {
                id: 'dp04-r2',
                object: 's04-dp04-r02',
                branches: [
                    { id: "popup-destroy", target: "dp05" }
                ]
            },
            {
                id: 'dp04-r3',
                object: 's04-dp04-r02',
                branches: [
                    { id: "popup-destroy", target: "dp05" }
                ]
            },
            
            // -- dp 05 --
                        
            {
                id: "dp05",
                onEnter: function () {

                    setupTimedObj('s04-dp05', 's04-dp05-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp05-r1" },
                    { id: "dp-wrong",   target: "dp05-r2" }
                ]
            },
            {
                id: 'dp05-r1',
                object: 's04-dp05-r01',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },
            {
                id: 'dp05-r2',
                object: 's04-dp05-r02',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },
            
            // -- dp 06 -- 
            
            {
                id: "dp06-intro",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s04-dp06-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario04.trigger('timeup');
                    });
                    aden.plugin.status.setTime(WAIT_TIME);
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: 'skip',   target: 'dp06' },
                    { id: 'timeup', target: 'dp06' }
                ]
            },
            {
                id: "dp06",
                onEnter: function () {

                    setupTimedObj('s04-dp06', 's04-dp06-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp06-r1" },
                    { id: "dp-wrong",   target: "dp06-r2" }
                ]
            },
            {
                id: 'dp06-r1',
                object: 's04-dp06-r01',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            {
                id: 'dp06-r2',
                object: 's04-dp06-r02',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            
            // -- dp 07 -- 
            
            {
                id: "dp07-intro",
                onEnter: function () {
                    aden.objects.load('s04-dp07-intro');
                },
                branches: [
                    { id: "popup-destroy", target: "dp07" }
                ]
            },
            {
                id: "dp07",
                onEnter: function () {

                    setupTimedObj('s04-dp07', 's04-dp07-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp07-r1" },
                    { id: "option1", target: "dp07-r2" },
                    { id: "option2", target: "dp07-r3" },
                    { id: "option3", target: "dp07-r4" }
                ]
            },
            {
                id: 'dp07-r1',
                object: 's04-dp07-r01',
                branches: [
                    { id: "popup-destroy", target: "dp08-intro" }
                ]
            },
            {
                id: 'dp07-r2',
                object: 's04-dp07-r02',
                branches: [
                    { id: "popup-destroy", target: "dp08-intro" }
                ]
            },
            {
                id: 'dp07-r3',
                object: 's04-dp07-r03',
                branches: [
                    { id: "popup-destroy", target: "dp08-intro" }
                ]
            },
            {
                id: 'dp07-r4',
                object: 's04-dp07-r04',
                branches: [
                    { id: "popup-destroy", target: "dp08-intro" }
                ]
            },
            
            // -- dp 08 -- 
            {
                id: "dp08-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s04-dp08-intro-audio');
                    currPopup = aden.objects.load('s04-dp08-intro-text');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                    if (currAudio) {
                        currAudio.destroy();
                    }
                },
                branches: [
                    { id: "audio-end", target: "dp08" }
                ]
            },
            {
                id: "dp08",
                onEnter: function () {

                    setupTimedObj('s04-dp08', 's04-dp08-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp08-r1" },
                    { id: "option1", target: "dp08-r2" },
                    { id: "option2", target: "dp08-r3" },
                    { id: "option3", target: "dp08-r4" },
                    { id: "option4", target: "dp08-r5" }
                ]
            },
            {
                id: 'dp08-r1',
                object: 's04-dp08-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r2',
                object: 's04-dp08-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r3',
                object: 's04-dp08-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r4',
                object: 's04-dp08-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r5',
                object: 's04-dp08-r05',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            
            // Cinematic (S04_Cin03) of the ambulance pulling out of the lane. See Decision 9.
            {
                id: "cinematic03",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s04-cin03');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                onExit: function () {
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "cinematic04" }
                ]
            },
            
            // Cinematic (S04_Cin04) of the ambulance pulling up to a police car.
            {
                id: "cinematic04",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s04-cin04');
                    aden.pano.load('ambulance');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                branches: [
                    { id: "move-ambulance", target: "cinematic-04-video-wait" },
                    { id: "video-end", target: "cinematic-04-pano-wait" }
                ]
            },
            {
                id: 'cinematic-04-pano-wait',
                onEnter: function () {},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "move-ambulance", target: "dp09" }
                ]
            },
            {
                id: 'cinematic-04-video-wait',
                onEnter: function(){},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp09" }
                ]
            },
            
            // -- DP 09 -- 
            
            {
                id: "dp09",
                onEnter: function () {
					aden.pano.camera.lookTo(225.4726122109009,7.3146869141900694);
                    setupTimedObj('s04-dp09', 's04-dp09-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp09-r1" },
                    { id: "option1", target: "dp09-r2" },
                    { id: "option2", target: "dp09-r3" },
                    { id: "option3", target: "dp09-r4" },
                    { id: "option4", target: "dp09-r5" }
                ]
            },
            {
                id: 'dp09-r1',
                object: 's04-dp09-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp09-r2',
                object: 's04-dp09-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp09-r3',
                object: 's04-dp09-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp09-r4',
                object: 's04-dp09-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp09-r5',
                object: 's04-dp09-r05',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            
            // -- dp 10 --
            
            /*
             * Cinematic (S04_Cin05) 
             * looking out the driver’s side window of the ambulance toward 
             * the police car and the Bomb Tech Lead walks up to the window. 
             */
            {
                id: "cinematic05",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.pano.load('ambulance');
                    aden.plugin.mode.setMode('vid');
                    currScreen = aden.objects.load('s04-bomb-tech');
                    currVideo = aden.objects.load('s04-cin05');
					currPopup = aden.objects.load('s04-dp10-intro');
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                    aden.plugin.mode.setMode('static');
                },
                branches: [
                    { id: "video-end", target: "dp10" }
                ]
            },
            
            {
                id: "dp10",
                onEnter: function () {

                    setupTimedObj('s04-dp10', 's04-dp10-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp10-r1" },
                    { id: "dp-wrong",   target: "dp10-r2" }
                ]
            },
            {
                id: 'dp10-r1',
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s04-tech-positive');
					currPopup = aden.objects.load('s04-dp10-r01');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "end" }
                ]
            },
            {
                id: 'dp10-r2',
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s04-tech-negative');
					currPopup = aden.objects.load('s04-dp10-r02');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "end" }
                ]
            },
            
            // --
            
            {
                id: 'end',
                onEnter: function () {
                    aden.plugin.map.close();
                    aden.fsm.gameView.trigger('end');
                    aden.plugin.mode.el.hide();
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    if (currScreen) {
                        currScreen.destroy();
                    }
                }
            }
        ]
    };
    
    return fsm;
});


