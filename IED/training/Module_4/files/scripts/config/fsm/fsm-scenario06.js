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
        aden.plugin.status.add(time3, function () { aden.fsm.scenario06.trigger('ignore'); });
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
        aden.plugin.status.set('green');
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
        aden.plugin.status.add(TIME_SPLIT_2, function () { aden.fsm.scenario06.trigger('ignored'); });
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

    var fsm = {
        id      : 'scenario06',
        type    : 'graph',
        initial : 'idle',
        inactive: 'idle',
        debug   : '#fsm-game-state',

        states  : [
            {
                id: "idle",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                },
                branches : [
                    { id: "start", target: "start" }
                ]
            },

            // -- starting point --
            {
                id: "start",
                object: "s06-intro",
                onEnter: function () {
                    currScreen = aden.objects.load('s06-start-screen');
                    aden.pano.hotspots.hideAll();
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('static');
                },
                onExit: function () {},
                branches: [
                    { id: "popup-destroy", target: "dispatch" }
                ]
            },

            // -- dispatcher --
            
            {
                id: "dispatch",
                onEnter: function () {
                    setupRadioCall(null, 's06-dispatch-call-audio', 's06-dispatch-call-text');
                },
                onExit: clearRadioCall,
                branches: [
                    { id: "audio-end", target: "dispatch-reply" }
                ]
            },
            {
                id: "dispatch-reply",
                onEnter: function () {
                    currPopup = aden.objects.load('s06-dispatch-response');
                    setupRadioReply(TIME_SHORT_YEL, TIME_SHORT_RED, TIME_SHORT_END);
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    clearRadioReply();
                },
                branches: [
                    { id: "ignore",      target: "dispatch-warning" },
                    { id: "radio-click", target: "dispatch-response" }
                ]
            },
            {
                id: "dispatch-warning",
                onEnter: function () {
                    currPopup = aden.objects.load('s06-dispatch-warning');
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
                    { id: "radio-click", target: "dispatch-response" }
                ]
            },
            {
                id: "dispatch-response",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('s06-dispatch-reply-text');
                    currAudio = aden.objects.load('s06-dispatch-reply-audio');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "cinematic01" }
                ]
            },
            
            /*
             * Cinematic (S06_Cin01): Ambulance arrives at the intersection. 
             */
            {
                id: "cinematic01",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    if (currScreen) { currScreen.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s06-cin01');
                    aden.plugin.mode.setMode('vid');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "move" }
                ]
            },
            
            /*
             * FPV panorama of the accident scene in the intersection. 
             * One driver is standing outside the vehicles, and the other driver is still inside 
             * his vehicle. Show teleport arrow leading to the driver’s side of the “suspect” 
             * vehicle where the driver is trapped.
             */
            
            {
                id: "move",
                onEnter: function () {
                    aden.pano.hotspots.showAll();
					aden.pano.camera.lookTo(284,0);
                    currPopup = aden.objects.load('s06-first-responder');
                },
                onExit: function () {
                    if ( currPopup ) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "move-car", target: "dp01-intro" }
                ]
            },
            
            // -- dp 01 --
            
            /*
             * FPV panorama standing next to the driver’s side door of the vehicle containing the 
             * injured driver. The complete interior of the vehicle is visible. On the passenger’s 
             * seat next to the driver is the backpack IED. The backpack is partially open and the 
             * contents are visible, these include multiple pipe bombs wired together and 
             * surrounding a 20 lb. propane tank, a kitchen timer, which has not been set or 
             * initiated, 6 volt lantern battery, and wires from the pipe bombs to the battery.
             */
            
            {
                id: "dp01-intro",
                onEnter: function () {
                    aden.plugin.status.clearTime();
                    aden.plugin.status.set('green');
                    aden.pano.camera.lookTo(-160,21);
                    currPopup = aden.objects.load('s06-dp01-intro');
                    aden.plugin.status.add(30000, function () {
                        aden.fsm.scenario06.trigger('timeup');
                    });
                    aden.plugin.status.setTime(30000);
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: 'skip',   target: 'dp01' },
                    { id: 'timeup', target: 'dp01' }
                ]
            },
            
            {
                id: "dp01",
                onEnter: function () {
					aden.pano.camera.lookTo(-160,21);
                    setupTimedObj('s06-dp01', 's06-dp01-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp01-r1" },
                    { id: "dp-wrong",   target: "dp01-r2" }
                ]
            },
            {
                id: 'dp01-r1',
                object: 's06-dp01-r01',
                branches: [
                    { id: "popup-destroy", target: "dp02" }
                ]
            },
            {
                id: 'dp01-r2',
                object: 's06-dp01-r02',
                branches: [
                    { id: "popup-destroy", target: "dp02" }
                ]
            },

            // -- DP 02 --

            {
                id: "dp02",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }
                    setupTimedObj('s06-dp02', 's06-dp02-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp02-r1" },
                    { id: "option1", target: "dp02-r2" },
                    { id: "option2", target: "dp02-r3" },
                    { id: "option3", target: "dp02-r4" }
                ]
            },
            {
                id: 'dp02-r1',
                object: 's06-dp02-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp02-r2',
                object: 's06-dp02-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp02-r3',
                object: 's06-dp02-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp02-r4',
                object: 's06-dp02-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },

            /*
             * Cinematic (S06_Cin02) shows pedestrians walking quickly away from the intersection.
             */
            {
                id: "cinematic02",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s06-cin02');
                    if (currScreen) { currScreen.destroy(); }
                    aden.pano.load('ambulance');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp03" }
                ]
            },
                        
            // -- DP 03 --
            
            /*
             * Continued from Decision 2. FPV panorama from behind the ambulance but with a 
             * clear view of the wreckage and injured driver and still within voice distance.
             */
            
            {
                id: "dp03",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }
					aden.pano.camera.lookTo(260,18);
                    setupTimedObj('s06-dp03', 's06-dp03-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp03-r1" },
                    { id: "option1", target: "dp03-r2" },
                    { id: "option2", target: "dp03-r3" },
                    { id: "option3", target: "dp03-r4" },
                    { id: "option4", target: "dp03-r5" }
                ]
            },
            {
                id: 'dp03-r1',
                object: 's06-dp03-r01',
                branches: [
                    { id: "popup-destroy", target: "dp04" }
                ]
            },
            {
                id: 'dp03-r2',
                object: 's06-dp03-r02',
                branches: [
                    { id: "popup-destroy", target: "dp04" }
                ]
            },
            {
                id: 'dp03-r3',
                object: 's06-dp03-r03',
                branches: [
                    { id: "popup-destroy", target: "dp04" }
                ]
            },
            {
                id: 'dp03-r4',
                object: 's06-dp03-r04',
                branches: [
                    { id: "popup-destroy", target: "dp04" }
                ]
            },
            {
                id: 'dp03-r5',
                object: 's06-dp03-r05',
                branches: [
                    { id: "popup-destroy", target: "dp04" }
                ]
            },

            // -- DP 04 --

            {
                id: "dp04",
                onEnter: function () {

                    setupTimedObj('s06-dp04', 's06-dp04-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp04-r1" },
                    { id: "dp-wrong",   target: "dp04-r2" }
                ]
            },
            {
                id: 'dp04-r1',
                object: 's06-dp04-r01',
                branches: [
                    { id: "popup-destroy", target: "dp05-intro" }
                ]
            },
            {
                id: 'dp04-r2',
                object: 's06-dp04-r02',
                branches: [
                    { id: "popup-destroy", target: "dp05-intro" }
                ]
            },

            // -- DP 05 --

            {
                id: "dp05-intro",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s06-dp05-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario06.trigger('timeup');
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
                    { id: 'skip',   target: 'dp05' },
                    { id: 'timeup', target: 'dp05' }
                ]
            },
            {
                id: "dp05",
                onEnter: function () {

                    setupTimedObj('s06-dp05', 's06-dp05-warning');
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
                object: 's06-dp05-r01',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r2',
                object: 's06-dp05-r02',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },

            // -- DP 06 --

            {
                id: "dp06",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    aden.plugin.status.set('green');
                    aden.objects.load('s06-dp06');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp06-r1" },
                    { id: "option1", target: "dp06-r2" },
                    { id: "option2", target: "dp06-r3" },
                    { id: "option3", target: "dp06-r4" }
                ]
            },
            {
                id: 'dp06-r1',
                object: 's06-dp06-r01',
                branches: [
                    { id: "popup-destroy", target: "dp07" }
                ]
            },
            {
                id: 'dp06-r2',
                object: 's06-dp06-r02',
                branches: [
                    { id: "popup-destroy", target: "dp07" }
                ]
            },
            {
                id: 'dp06-r3',
                object: 's06-dp06-r03',
                branches: [
                    { id: "popup-destroy", target: "dp07" }
                ]
            },
            {
                id: 'dp06-r4',
                object: 's06-dp06-r04',
                branches: [
                    { id: "popup-destroy", target: "dp07" }
                ]
            },

            // -- DP 07 --

            {
                id: "dp07",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s06-dp07', 's06-dp07-warning');
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
                object: 's06-dp07-r01',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r2',
                object: 's06-dp07-r02',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r3',
                object: 's06-dp07-r03',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r4',
                object: 's06-dp07-r04',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },

            // -- DP 08 --

            {
                id: "dp08",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s06-dp08', 's06-dp08-warning');
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
                object: 's06-dp08-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r2',
                object: 's06-dp08-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r3',
                object: 's06-dp08-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r4',
                object: 's06-dp08-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp08-r5',
                object: 's06-dp08-r05',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },

            // -- DP 09 --
            
            {
                id: "cinematic03",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currScreen = aden.objects.load('s06-bomb-tech');
                    currVideo = aden.objects.load('s06-cin03');
					currPopup = aden.objects.load('s06-dp09-intro-text');
                    aden.plugin.mode.setMode('vid');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('static');
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp09" }
                ]
            },
            
            {
                id: "dp09",
                onEnter: function () {
                    setupTimedObj('s06-dp09', 's06-dp09-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp09-r1" },
                    { id: "dp-wrong",   target: "dp09-r2" }
                ]
            },
            {
                id: 'dp09-r1',
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s06-tech-positive');
					currPopup = aden.objects.load('s06-dp09-r01');
                    aden.plugin.mode.setMode('vid');
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
                id: 'dp09-r2',
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s06-tech-negative');
					currPopup = aden.objects.load('s06-dp09-r02');
                    aden.plugin.mode.setMode('vid');
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

            // ---

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


