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
        aden.plugin.status.add(time3, function () { aden.fsm.scenario05.trigger('ignore'); });
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
        aden.plugin.status.add(TIME_SPLIT_2, function () { aden.fsm.scenario05.trigger('ignored'); });
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
        id      : 'scenario05',
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

            // -- start --
            
            {
                id: "start",
                object: "",
                onEnter: function () {
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('static');
                    currScreen = aden.objects.load('s05-intro-screen');
                    currPopup = aden.objects.load('s05-intro');
                    aden.pano.hotspots.hideAll();
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "popup-destroy", target: "dispatch" }
                ]
            },

            // -- dispatch --
            
            {
                id: "dispatch",
                onEnter: function () {

                    setupRadioCall(null, 's05-dispatch-call-audio', 's05-dispatch-call-text');
                },
                onExit: clearRadioCall,
                branches: [
                    { id: "audio-end", target: "dispatch-reply" }
                ]
            },
            {
                id: "dispatch-reply",
                onEnter: function () {
                    currPopup = aden.objects.load('s05-dispatch-response');
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
                    currPopup = aden.objects.load('s05-dispatch-warning');
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
                    currPopup = aden.objects.load('s05-dispatch-reply-text');
                    currAudio = aden.objects.load('s05-dispatch-reply-audio');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                    if (currScreen) { currScreen.destroy(); }
                    aden.plugin.mode.setMode('pano');
                },
                branches: [
                    { id: "audio-end", target: "dp01-intro" }
                ]
            },
            
            // -- DP 01 --
                        
            /*
             * First-person view (FPV) panorama in the hallway outside the high school library.
             * View is from several feet back. There is a sign hanging from the ceiling indicating
             * the location of the library.
             */
            
            {
                id: "dp01-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    aden.pano.hotspots.hideAll();
                    currAudio = aden.objects.load('s05-dispatch02-audio');
                    currPopup = aden.objects.load('s05-dispatch02-text');
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
                    { id: "audio-end", target: "move" }
                ]
            },
            
            {
                id: "move",
                onEnter: function () {
                    aden.pano.hotspots.showAll();
					aden.pano.camera.lookTo(118,0);
                    currPopup = aden.objects.load('s05-move-prompt');
                },
                onExit: function () {
                    if (currPopup) { currPopup.destroy(); }
                },
                branches: [
                    { id: "click-arrow", target: "cinematic01" }
                ]
            },
            
            {
                id: "cinematic01",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s05-cin01');
                    aden.pano.load('entrance');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp01" }
                ]
            },
                        
            {
                id: "dp01",
                onEnter: function () {
                    if (currScreen) {
                        currScreen.destroy();
                    }

                    setupTimedObj('s05-dp01', 's05-dp01-warning');
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
                object: 's05-dp01-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp01-r2',
                object: 's05-dp01-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp01-r3',
                object: 's05-dp01-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },

            // -- DP 02 --
            
            {
                id: "cinematic02",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                    // currScreen = aden.objects.load('s05-still-cin02');
                    currVideo = aden.objects.load('s05-cin02');
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                    aden.plugin.mode.setMode('static');
                },
                branches: [
                    { id: "video-end", target: "dp02" }
                ]
            },
            
            {
                id: "dp02",
                onEnter: function () {
                    setupTimedObj('s05-dp02', 's05-dp02-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp02-r1" },
                    { id: "option1", target: "dp02-r2" },
                    { id: "option2", target: "dp02-r3" },
                    { id: "option3", target: "dp02-r4" },
                    { id: "option4", target: "dp02-r5" }
                ]
            },
            {
                id: 'dp02-r1',
                object: 's05-dp02-r01',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r2',
                object: 's05-dp02-r02',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r3',
                object: 's05-dp02-r03',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r4',
                object: 's05-dp02-r04',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r5',
                object: 's05-dp02-r05',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },

            // -- DP 03 --
            
            {
                id: "dp03",
                onEnter: function () {
                    if ( currScreen ) { currScreen.destroy(); } 
                    setupTimedObj('s05-dp03', 's05-dp03-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp03-r1" },
                    { id: "dp-wrong",   target: "dp03-r2" }
                ]
            },
            {
                id: 'dp03-r1',
                object: 's05-dp03-r01',
                branches: [
                    { id: "popup-destroy", target: "dp04" }
                ]
            },
            {
                id: 'dp03-r2',
                object: 's05-dp03-r02',
                branches: [
                    { id: "popup-destroy", target: "dp04" }
                ]
            },

            // -- DP 04 --

            {
                id: "dp04",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s05-dp04', 's05-dp04-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp04-r1" },
                    { id: "option1", target: "dp04-r2" },
                    { id: "option2", target: "dp04-r3" },
                    { id: "option3", target: "dp04-r4" },
                    { id: "option4", target: "dp04-r5" }
                ]
            },
            {
                id: 'dp04-r1',
                object: 's05-dp04-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp04-r2',
                object: 's05-dp04-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp04-r3',
                object: 's05-dp04-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp04-r4',
                object: 's05-dp04-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp04-r5',
                object: 's05-dp04-r05',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: "cinematic03",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s05-cin03');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                    aden.pano.load('acrosshallway');
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                    aden.plugin.mode.setMode('pano');
                },
                branches: [
                    { id: "video-end", target: "dp05" }
                ]
            },
            
            // -- DP 05 --

            {
                id: "dp05",
                onEnter: function () {
                    setupTimedObj('s05-dp05', 's05-dp05-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp05-r1" },
                    { id: "option1", target: "dp05-r2" },
                    { id: "option2", target: "dp05-r3" },
                    { id: "option3", target: "dp05-r4" },
                    { id: "option4", target: "dp05-r5" }
                ]
            },
            {
                id: 'dp05-r1',
                object: 's05-dp05-r01',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r2',
                object: 's05-dp05-r02',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r3',
                object: 's05-dp05-r03',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r4',
                object: 's05-dp05-r04',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r5',
                object: 's05-dp05-r05',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },

            // -- DP 06 --

            {
                id: "dp06",
                onEnter: function () {

                    setupTimedObj('s05-dp06', 's05-dp06-warning');
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
                object: 's05-dp06-r01',
                branches: [
                    { id: "popup-destroy", target: "dp07" }
                ]
            },
            {
                id: 'dp06-r2',
                object: 's05-dp06-r02',
                branches: [
                    { id: "popup-destroy", target: "dp07" }
                ]
            },

            // -- DP 07 --

            {
                id: "dp07",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s05-dp07', 's05-dp07-warning');
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
                object: 's05-dp07-r01',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r2',
                object: 's05-dp07-r02',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r3',
                object: 's05-dp07-r03',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r4',
                object: 's05-dp07-r04',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },

            // -- DP 08 --

            {
                id: "dp08",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s05-dp08', 's05-dp08-warning');
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
                object: 's05-dp08-r01',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },
            {
                id: 'dp08-r2',
                object: 's05-dp08-r02',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },
            {
                id: 'dp08-r3',
                object: 's05-dp08-r03',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },
            {
                id: 'dp08-r4',
                object: 's05-dp08-r04',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },
            {
                id: 'dp08-r5',
                object: 's05-dp08-r05',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },

            // -- DP 09 --

            {
                id: "dp09-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s05-dp09-intro-audio');
                    currPopup = aden.objects.load('s05-dp09-intro-text');
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
                    { id: "audio-end", target: "dp09" }
                ]
            },
            {
                id: "dp09",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s05-dp09', 's05-dp09-warning');
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
                object: 's05-dp09-r01',
                branches: [
                    { id: "popup-destroy", target: "dp10-intro" }
                ]
            },
            {
                id: 'dp09-r2',
                object: 's05-dp09-r02',
                branches: [
                    { id: "popup-destroy", target: "dp10-intro" }
                ]
            },
            {
                id: 'dp09-r3',
                object: 's05-dp09-r03',
                branches: [
                    { id: "popup-destroy", target: "dp10-intro" }
                ]
            },
            {
                id: 'dp09-r4',
                object: 's05-dp09-r04',
                branches: [
                    { id: "popup-destroy", target: "dp10-intro" }
                ]
            },
            {
                id: 'dp09-r5',
                object: 's05-dp09-r05',
                branches: [
                    { id: "popup-destroy", target: "dp10-intro" }
                ]
            },

            // -- DP 10 --
            
            {
                id: "dp10-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s05-dp10-intro-audio');
                    currPopup = aden.objects.load('s05-dp10-intro-text');
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
                    { id: "audio-end", target: "cinematic04" }
                ]
            },
            
            {
                id: "cinematic04",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currScreen = aden.objects.load('s05-bomb-tech');
                    currVideo = aden.objects.load('s05-cin04');
					currPopup = aden.objects.load('s05-dp10-bomb-tech');
                    aden.plugin.mode.setMode('vid');
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
                    setupTimedObj('s05-dp10', 's05-dp10-warning');
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
                    currVideo = aden.objects.load('s05-tech-positive');
					currPopup = aden.objects.load('s05-dp10-r01');
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
                id: 'dp10-r2',
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s05-tech-negative');
					currPopup = aden.objects.load('s05-dp10-r02');
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


