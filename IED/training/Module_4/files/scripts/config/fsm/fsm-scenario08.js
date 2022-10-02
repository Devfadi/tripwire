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
        aden.plugin.status.add(time3, function () { aden.fsm.scenario08.trigger('ignore'); });
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
        currDP = aden.objects.load(dp);
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
        aden.plugin.status.add(TIME_SPLIT_2, function () { aden.fsm.scenario08.trigger('ignored'); });
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
        id      : 'scenario08',
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

            // starting point...

            {
                id: "start",
                object: "s08-intro-pop",
                onEnter: function () {
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('static');
                    currScreen = aden.objects.load('s08-start-screen');
                    aden.pano.hotspots.hideAll();
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

                    setupRadioCall(null, 's08-dispatch-call-audio', 's08-dispatch-call-text');
                },
                onExit: clearRadioCall,
                branches: [
                    { id: "audio-end", target: "dispatch-reply" }
                ]
            },
            {
                id: "dispatch-reply",
                onEnter: function () {
                    currPopup = aden.objects.load('s08-dispatch-response');
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
                    currPopup = aden.objects.load('s08-dispatch-warning');
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
                    currPopup = aden.objects.load('s08-dispatch-reply-text');
                    currAudio = aden.objects.load('s08-dispatch-reply-audio');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "cinematic00" }
                ]
            },

            // -- arrival --
			// s08-cin00
			{
                id: "cinematic00",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-cin00');
                    aden.plugin.mode.setMode('vid');
					aden.pano.hotspots.hideAll();
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "arrival" }
                ]
            },
			
            {
                id: "arrival",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }
                    aden.plugin.mode.setMode('pano');
                    aden.pano.hotspots.showAll();
                    setupTimedObj('s08-move-popup', 's08-move-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                    if (currDP) {
                        currDP.destroy();
                    }
                },
                branches: [
                    { id: "click-arrow", target: "cinematic01" }
                ]
            },
            
            /*
             * Cinematic (S08_Cin01):
             * FPV of walking up closer to the remains of the fire.
             * In view is a misfired stand-off weapon round lying in a charred area at the front of the fire.
             * The misfired round is a camping-sized propane tank with a tail and fins welded to it. See Decision 1.
             */
            {
                id: "cinematic01",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-cin01');
                    aden.plugin.mode.setMode('vid');
					aden.pano.load('charred');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp01" }
                ]
            },
            
            // -- dp 01 --

            {
                id: "dp01",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s08-dp01', 's08-dp01-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp01-r1" },
                    { id: "option1", target: "dp01-r2" },
                    { id: "option2", target: "dp01-r3" },
                    { id: "option3", target: "dp01-r4" },
                    { id: "option4", target: "dp01-r5" },
                    { id: "option5", target: "dp01-r6" }
                ]
            },
            {
                id: 'dp01-r1',
                object: 's08-dp01-r01',
                branches: [
                    { id: "popup-destroy", target: "dp02-intro" }
                ]
            },
            {
                id: 'dp01-r2',
                object: 's08-dp01-r02',
                branches: [
                    { id: "popup-destroy", target: "dp02-intro" }
                ]
            },
            {
                id: 'dp01-r3',
                object: 's08-dp01-r03',
                branches: [
                    { id: "popup-destroy", target: "dp02-intro" }
                ]
            },
            {
                id: 'dp01-r4',
                object: 's08-dp01-r04',
                branches: [
                    { id: "popup-destroy", target: "dp02-intro" }
                ]
            },
            {
                id: 'dp01-r5',
                object: 's08-dp01-r05',
                branches: [
                    { id: "popup-destroy", target: "dp02-intro" }
                ]
            },

            // -- dp 02 --

            {
                id: "dp02-intro",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s08-dp02-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario08.trigger('timeup');
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
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s08-dp02', 's08-dp02-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp02-r1" },
                    { id: "option1", target: "dp02-r2" },
                    { id: "option2", target: "dp02-r3" },
                    { id: "option3", target: "dp02-r4" },
                    { id: "option4", target: "dp02-r5" },
                    { id: "option5", target: "dp02-r6" }
                ]
            },
            {
                id: 'dp02-r1',
                object: 's08-dp02-r01',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r2',
                object: 's08-dp02-r02',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r3',
                object: 's08-dp02-r03',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r4',
                object: 's08-dp02-r04',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },

            // -- dp 03 --

            {
                id: "dp03",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s08-dp03', 's08-dp03-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp03-r1" },
                    { id: "option1", target: "dp03-r2" },
                    { id: "option2", target: "dp03-r3" },
                    { id: "option3", target: "dp03-r4" },
                    { id: "option4", target: "dp03-r5" },
                    { id: "option5", target: "dp03-r6" }
                ]
            },
            {
                id: 'dp03-r1',
                object: 's08-dp03-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r2',
                object: 's08-dp03-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r3',
                object: 's08-dp03-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r4',
                object: 's08-dp03-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },

            /*
             * Cinematic (S08_Cin02):
             * From the learner’s POV. 
             * Show a few pedestrians walking away from the area through the parking lot to take shelter.
             */
            {
                id: "cinematic02",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-cin02');
                    aden.plugin.mode.setMode('vid');
                    aden.pano.load('bathrooms');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    //{ id: "video-end", target: "dp04" } // removed
                    { id: "video-end", target: "dp05-intro" }
                ]
            },

            // -- dp 04 --
			
			/*
            {
                id: "dp04",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s08-dp04', 's08-dp04-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp04-r1" },
                    { id: "option1", target: "dp04-r2" },
                    { id: "option2", target: "dp04-r3" },
                    { id: "option3", target: "dp04-r4" },
                    { id: "option4", target: "dp04-r5" },
                    { id: "option5", target: "dp04-r6" }
                ]
            },
            {
                id: 'dp04-r1',
                object: 's08-dp04-r01',
                branches: [
                    { id: "popup-destroy", target: "dp05-intro" }
                ]
            },
            {
                id: 'dp04-r2',
                object: 's08-dp04-r02',
                branches: [
                    { id: "popup-destroy", target: "dp05-intro" }
                ]
            },
            {
                id: 'dp04-r3',
                object: 's08-dp04-r03',
                branches: [
                    { id: "popup-destroy", target: "dp05-intro" }
                ]
            },
            {
                id: 'dp04-r4',
                object: 's08-dp04-r04',
                branches: [
                    { id: "popup-destroy", target: "dp05-intro" }
                ]
            },
			*/
			
            // -- dp 05 --
            {
                id: "dp05-intro",
                object: "s08-dp05-intro",
                branches: [
                    { id: "popup-destroy", target: "dp05" }
                ]
            },
            {
                id: "dp05",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s08-dp05', 's08-dp05-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp05-r1" },
                    { id: "option1", target: "dp05-r2" },
                    { id: "option2", target: "dp05-r3" },
                    { id: "option3", target: "dp05-r4" },
                    { id: "option4", target: "dp05-r5" },
                    { id: "option5", target: "dp05-r6" }
                ]
            },
            {
                id: 'dp05-r1',
                object: 's08-dp05-r01',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },
            {
                id: 'dp05-r2',
                object: 's08-dp05-r02',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },
            {
                id: 'dp05-r3',
                object: 's08-dp05-r03',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },
            {
                id: 'dp05-r4',
                object: 's08-dp05-r04',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },

            // -- dp 06 --

            {
                id: "dp06-intro",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s08-dp06-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario08.trigger('timeup');
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

                    setupTimedObj('s08-dp06', 's08-dp06-warning');
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
                object: 's08-dp06-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp06-r2',
                object: 's08-dp06-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },

            /*
             * Cinematic (S08_Cin03) :
             * Cinematic shows additional police and fire units arriving on scene 
             * in the vicinity of the rest area parking lot.
             * Audio: (Dispatcher) 
             * “Additional units arriving on-scene. Suspected stand-off weapon.”
             * See Decision 7
            */
            {
                id: "cinematic03",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-cin03');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp07" }
                ]
            },

            // -- DP 07 --

            {
                id: "dp07",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s08-dp07', 's08-dp07-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp07-r1" },
                    { id: "option1", target: "dp07-r2" },
                    { id: "option2", target: "dp07-r3" },
                    { id: "option3", target: "dp07-r4" },
                    { id: "option4", target: "dp07-r5" },
                    { id: "option5", target: "dp07-r6" }
                ]
            },
            {
                id: 'dp07-r1',
                object: 's08-dp07-r01',
                branches: [
                    { id: "popup-destroy", target: "dp07-response" }
                ]
            },
            {
                id: 'dp07-r2',
                object: 's08-dp07-r02',
                branches: [
                    { id: "popup-destroy", target: "dp07-response" }
                ]
            },
            {
                id: 'dp07-r3',
                object: 's08-dp07-r03',
                branches: [
                    { id: "popup-destroy", target: "dp07-response" }
                ]
            },
            {
                id: 'dp07-r4',
                object: 's08-dp07-r04',
                branches: [
                    { id: "popup-destroy", target: "dp07-response" }
                ]
            },
            {
                id: 'dp07-r5',
                object: 's08-dp07-r05',
                branches: [
                    { id: "popup-destroy", target: "dp07-response" }
                ]
            },
            
            {
                id: 'dp07-response',
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('s08-dp07-response-text');
                    currAudio = aden.objects.load('s08-dp07-response-audio');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "cinematic04" }
                ]
            },
            
            /*
             * Cinematic (S07_C04): 
             * FPV walking through the parking lot away from the launch vehicle. See Decision 8.
             */
            {
                id: "cinematic04",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-cin04');
                    aden.plugin.mode.setMode('vid');
                    aden.pano.load('barricades');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "cinematic04a" }
                ]
            },
			{
				id: "cinematic04a",
				 onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-cin04a');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp08" }
                ]
			},

            // -- DP 08 --

            {
                id: "dp08",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s08-dp08', 's08-dp08-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp08-r1" },
                    { id: "option1", target: "dp08-r2" },
                    { id: "option2", target: "dp08-r3" },
                    { id: "option3", target: "dp08-r4" },
                    { id: "option4", target: "dp08-r5" },
                    { id: "option5", target: "dp08-r6" }
                ]
            },
            {
                id: 'dp08-r1',
                object: 's08-dp08-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp08-r2',
                object: 's08-dp08-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp08-r3',
                object: 's08-dp08-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp08-r4',
                object: 's08-dp08-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },

            /*
             * Play cinematic (S07_Cin05):
             * Play cinematic (S07_Cin08): Bomb Tech Lead asks for a briefing.
             * FPV of a few pedestrians lingering around the area with police telling them they need to evacuate the area.
             * Audio: (Non-player character police officer) “For your protection, please move completely out of the rest area until further notice.”
             * See Decision 9.
             */
            {
                id: "cinematic05",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-cin05');
					currPopup = aden.objects.load('s08-dp09-intro');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp09" }
                ]
            },

            // -- dp 09 --
            
            {
                id: "dp09",
                onEnter: function () {
                    setupTimedObj('s08-dp09', 's08-dp09-warning');
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
                object: 's08-dp09-r01',
                branches: [
                    { id: "popup-destroy", target: "dp09-success" }
                ]
            },
            {
                id: 'dp09-r2',
                object: 's08-dp09-r02',
                branches: [
                    { id: "popup-destroy", target: "dp09-failure" }
                ]
            },
            {
                id: "dp09-success",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-tech-positive');
					currPopup = aden.objects.load('s08-dp09-success');
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
                id: "dp09-failure",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s08-tech-negative');
					currPopup = aden.objects.load('s08-dp09-failure');
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


