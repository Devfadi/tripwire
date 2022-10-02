define(function (require) {
    'use strict';

    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        debug = require('adayana/debug/debug'),
        Splash = require('modules/screens/splash'),
        NavScreen = require('modules/screens/navScreen'),
        SelectionScreen = require('modules/screens/selectionScreen'),
        ScenarioScreen = require('modules/screens/scenarioScreen'),
        mediator = require('adayana/modules/mediatorShim');

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
        aden.plugin.status.add(time1, function () {
            aden.plugin.status.set('yellow');
        });
        aden.plugin.status.add(time2, function () {
            aden.plugin.status.set('red');
        });
        aden.plugin.status.add(time3, function () {
            aden.fsm.scenario03.trigger('ignore');
        });
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
        aden.plugin.status.add(TIME_LONG_YEL, function () {
            aden.plugin.status.set('yellow');
        });
        aden.plugin.status.add(TIME_LONG_RED, function () {
            aden.plugin.status.set('red');
        });
        aden.plugin.status.add(TIME_LONG_END, function () {
            aden.objects.load(warning);
            aden.plugin.status.clearTime();
        });
        aden.plugin.status.setTime(TIME_LONG_END);
    }

    function setupSplitDP1(dp) {
        currDP = aden.objects.load(dp);
        aden.plugin.status.set('green');
        aden.plugin.status.add(TIME_SPLIT_1, function () {
            aden.plugin.status.set('yellow');
        });
        aden.plugin.status.add(TIME_SPLIT_2, function () {
            aden.fsm.scenario03.trigger('ignored');
        });
        aden.plugin.status.setTime(TIME_SPLIT_2);
    }

    function setupSplitDP2(dp, warning) {
        aden.objects.load(dp);
        aden.plugin.status.add(TIME_SPLIT_3, function () {
            aden.plugin.status.set('red');
        });
        aden.plugin.status.add(TIME_SPLIT_4, function () {
            aden.objects.load(warning);
            aden.plugin.status.clearTime();
        });
        aden.plugin.status.setTime(TIME_SPLIT_4);
    }

    var fsm = {
        id: 'scenario03',
        type: 'graph',
        initial: 'idle',
        inactive: 'idle',
        debug: '#fsm-game-state',

        states: [
            {
                id: "idle",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                },
                branches: [
                    {
                        id: "start",
                        target: "start"
                    }
                ]
            },

            {
                id: "start",
                object: "s03-intro",
                onEnter: function () {
                    aden.pano.hotspots.hideAll();
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('pano');
                },
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic01"
                    }
                ]
            },

            /*
             * Cinematic 01
             * Triggers cinematic of a football fan walking up to you and saying,
             * “Someone left a backpack at the hallway entrance just around the corner there.”
             * (Fan points out direction)
             */
            {
                id: "cinematic01",
                onEnter: function () {
                    if (currScreen) {
                        currScreen.destroy();
                    }
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currScreen = aden.objects.load('s03-fan-pointing');
                    currVideo = aden.objects.load('s03-cin01');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('static');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    {
                        id: "video-end",
                        target: "dp01"
                    }
                ]
            },
            {
                id: "dp01",
                onEnter: function () {
                    setupTimedObj('s03-dp01', 's03-dp01-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "option0",
                        target: "dp01-r1"
                    },
                    {
                        id: "option1",
                        target: "dp01-r2"
                    },
                    {
                        id: "option2",
                        target: "dp01-r3"
                    }
                ]
            },
            {
                id: 'dp01-r1',
                object: 's03-dp01-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic02"
                    }
                ]
            },
            {
                id: 'dp01-r2',
                object: 's03-dp01-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic02"
                    }
                ]
            },
            {
                id: 'dp01-r3',
                object: 's03-dp01-r03',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic02"
                    }
                ]
            },

            /*
             * Cinematic 02
             * Initiate a cinematic FPV walking to the concourse area and going around the corner
             * in the direction pointed out by the fan. When the cinematic pauses, the backpack
             * should be a few feet away sitting next to a concession stand, clearly visible, with
             * the cover partially open, showing the top of a pressure cooker and some wires taped
             * to the top of the pressure cooker.
             */
            {
                id: "cinematic02",
                onEnter: function () {
                    if (currScreen) {
                        currScreen.destroy();
                    }
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.mode.setMode('vid');
                    aden.plugin.status.set('green');
                    currScreen = aden.objects.load('s03-backpack');
                    currScreen.zoom();
                    currVideo = aden.objects.load('s03-cin02');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('static');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    {
                        id: "video-end",
                        target: "dp02-intro"
                    }
                ]
            },

            {
                id: "dp02-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s03-dp02-audio');
                    currPopup = aden.objects.load('s03-dp02-intro');
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
                    {
                        id: "audio-end",
                        target: "dp02"
                    }
                ]
            },
            {
                id: "dp02",
                onEnter: function () {
                    setupTimedObj('s03-dp02', 's03-dp02-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "dp-correct",
                        target: "dp02-r1"
                    },
                    {
                        id: "dp-wrong",
                        target: "dp02-r2"
                    }
                ]
            },
            {
                id: 'dp02-r1',
                object: 's03-dp02-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp03-intro"
                    }
                ]
            },
            {
                id: 'dp02-r2',
                object: 's03-dp02-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp03-intro"
                    }
                ]
            },
            {
                id: "dp03-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s03-dp03-intro-audio');
                    currPopup = aden.objects.load('s03-dp03-intro-text');
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
                    {
                        id: "audio-end",
                        target: "dp03"
                    }
                ]
            },
            {
                id: "dp03",
                onEnter: function () {

                    setupTimedObj('s03-dp03', 's03-dp03-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "option0",
                        target: "dp03-r1"
                    },
                    {
                        id: "option1",
                        target: "dp03-r2"
                    },
                    {
                        id: "option2",
                        target: "dp03-r3"
                    }
                ]
            },
            {
                id: 'dp03-r1',
                object: 's03-dp03-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic03"
                    }
                ]
            },
            {
                id: 'dp03-r2',
                object: 's03-dp03-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic03"
                    }
                ]
            },
            {
                id: 'dp03-r3',
                object: 's03-dp03-r03',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic03"
                    }
                ]
            },

            /**
             * Cinematic 03
             * Cinematic shows FPV of moving to a safer location, and other characters moving away
             * from the immediate area of the backpack. FPV goes around the corner of the concourse
             * and turns around. See Decision 4.
             */
            {
                id: "cinematic03",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.mode.setMode('vid');
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s03-cin03');
                    aden.pano.load('behindcolumn');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    {
                        id: "video-end",
                        target: "dp04-intro"
                    }
                ]
            },
            {
                id: "dp04-intro",
                onEnter: function () {
                    aden.plugin.status.clearTime();
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s03-dp04-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario03.trigger('timeup');
                    });
                    aden.plugin.status.setTime(WAIT_TIME);
                },
                onExit: function () {
                    currPopup.destroy();
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: 'skip',
                        target: 'dp04'
                    },
                    {
                        id: 'timeup',
                        target: 'dp04'
                    }
                ]
            },
            {
                id: "dp04",
                onEnter: function () {

                    setupTimedObj('s03-dp04', 's03-dp04-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "dp-correct",
                        target: "dp04-r1"
                    },
                    {
                        id: "dp-wrong",
                        target: "dp04-r2"
                    }
                ]
            },
            {
                id: 'dp04-r1',
                object: 's03-dp04-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp05"
                    }
                ]
            },
            {
                id: 'dp04-r2',
                object: 's03-dp04-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp05"
                    }
                ]
            },

            // -- DP 05 --

            {
                id: "dp05",
                onEnter: function () {

                    setupTimedObj('s03-dp05', 's03-dp05-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "option0",
                        target: "dp05-r1"
                    },
                    {
                        id: "option1",
                        target: "dp05-r2"
                    },
                    {
                        id: "option2",
                        target: "dp05-r3"
                    }
                ]
            },
            {
                id: 'dp05-r1',
                object: 's03-dp05-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp06-intro"
                    }
                ]
            },
            {
                id: 'dp05-r2',
                object: 's03-dp05-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp06-intro"
                    }
                ]
            },
            {
                id: 'dp05-r3',
                object: 's03-dp05-r03',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp06-intro"
                    }
                ]
            },
            {
                id: "dp06-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s03-dp06-intro-audio');
                    currPopup = aden.objects.load('s03-dp06-intro-text');
                },
                onExit: function () {
                    currPopup.destroy();
                    aden.plugin.radio.removeGlow();
                    if (currAudio) {
                        currAudio.destroy();
                    }
                },
                branches: [
                    { 
                        id: "audio-end",
                        target: "dp06"
                    }
                ]
            },

            {
                id: "dp06",
                onEnter: function () {

                    aden.objects.load('s03-dp06');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "option0",
                        target: "dp06-r1"
                    },
                    {
                        id: "option1",
                        target: "dp06-r2"
                    },
                    {
                        id: "option2",
                        target: "dp06-r3"
                    },
                    {
                        id: "option3",
                        target: "dp06-r4"
                    }
                ]
            },
            {
                id: 'dp06-r1',
                object: 's03-dp06-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic04"
                    }
                ]
            },
            {
                id: 'dp06-r2',
                object: 's03-dp06-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic04"
                    }
                ]
            },
            {
                id: 'dp06-r3',
                object: 's03-dp06-r03',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic04"
                    }
                ]
            },
            {
                id: 'dp06-r4',
                object: 's03-dp06-r04',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "cinematic04"
                    }
                ]
            },

            /*
             * Cinematic 04
             * Cinematic of people walking past the previous stadium concourse FPV location.
             * Show FPV falling in behind the people and walking away from the concourse with them.
             */
            {
                id: "cinematic04",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s03-cin04');
                    aden.pano.load('evacuate');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    {
                        id: "video-end",
                        target: "dp07"
                    }
                ]
            },
            {
                id: "dp07",
                onEnter: function () {
                    setupTimedObj('s03-dp07', 's03-dp07-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "option0",
                        target: "dp07-r1"
                    },
                    {
                        id: "option1",
                        target: "dp07-r2"
                    },
                    {
                        id: "option2",
                        target: "dp07-r3"
                    },
                    {
                        id: "option3",
                        target: "dp07-r4"
                    },
                    {
                        id: "option4",
                        target: "dp07-r5"
                    }
                ]
            },
            {
                id: 'dp07-r1',
                object: 's03-dp07-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp08"
                    }
                ]
            },
            {
                id: 'dp07-r2',
                object: 's03-dp07-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp08"
                    }
                ]
            },
            {
                id: 'dp07-r3',
                object: 's03-dp07-r03',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp08"
                    }
                ]
            },
            {
                id: 'dp07-r4',
                object: 's03-dp07-r04',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp08"
                    }
                ]
            },
            {
                id: 'dp07-r5',
                object: 's03-dp07-r05',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp08"
                    }
                ]
            },            

            /*
             * Cinematic 05
             * FPV of parking lot with barricades set-up. Several characters in scene. Some should be moving around.
             */
            /*
            {
                id: "cinematic05",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s03-cin05');
                    aden.pano.load('parkinglot');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    {
                        id: "video-end",
                        target: "dp08"
                    }
                ]
            },
            */
            {
                id: "dp08",
                onEnter: function () {

                    setupTimedObj('s03-dp08', 's03-dp08-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "option0",
                        target: "dp08-r1"
                    },
                    {
                        id: "option1",
                        target: "dp08-r2"
                    },
                    {
                        id: "option2",
                        target: "dp08-r3"
                    }
                ]
            },
            {
                id: 'dp08-r1',
                object: 's03-dp08-r01',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp09-intro"
                    }
                ]
            },
            {
                id: 'dp08-r2',
                object: 's03-dp08-r02',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp09-intro"
                    }
                ]
            },
            {
                id: 'dp08-r3',
                object: 's03-dp08-r03',
                branches: [
                    {
                        id: "popup-destroy",
                        target: "dp09-intro"
                    }
                ]
            },
            /*
             * Cinematic 06
             * Cinematic of Bomb Tech Lead walking up.
             */
            {
                id: "dp09-intro",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currScreen = aden.objects.load('s03-bomb-tech');
                    // currVideo = aden.objects.load('s03-cin06');
                    currVideo = aden.objects.load('s03-cin05');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('static');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    {
                        id: "video-end",
                        target: "dp09"
                    }
                ]
            },

            {
                id: "dp09",
                onEnter: function () {
                    setupTimedObj('s03-dp09', 's03-dp09-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    {
                        id: "dp-correct",
                        target: "dp09-r1"
                    },
                    {
                        id: "dp-wrong",
                        target: "dp09-r2"
                    }
                ]
            },
            {
                id: 'dp09-r1',
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.objects.load('s03-dp09-r01');
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s03-tech-positive');
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
                    {
                        id: "video-end",
                        target: "end"
                    }
                ]
            },
            {
                id: 'dp09-r2',
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.objects.load('s03-dp09-r02');
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s03-tech-negative');
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
                    {
                        id: "video-end",
                        target: "end"
                    }
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