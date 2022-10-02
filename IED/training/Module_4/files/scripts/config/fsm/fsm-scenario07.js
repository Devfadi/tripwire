//^\s+aden\.plugin\.mode\.setMode\('[a-z]+'\);
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
        aden.plugin.status.add(time1, function () {
            aden.plugin.status.set('yellow');
        });
        aden.plugin.status.add(time2, function () {
            aden.plugin.status.set('red');
        });
        aden.plugin.status.add(time3, function () {
            aden.fsm.scenario07.trigger('ignore');
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
        currDP = aden.objects.load(dp);
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
            aden.fsm.scenario07.trigger('ignored');
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
        id      : 'scenario07',
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
                onEnter: function () {
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('static');
                    aden.pano.hotspots.hideAll();
                    currScreen = aden.objects.load('s07-start-screen');
                    currPopup = aden.objects.load('s07-intro');
                },
                onExit: function () {},
                branches: [
                    { id: "popup-destroy", target: "dispatch" }
                ]
            },

            // -- dispatch --

            {
                id: "dispatch",
                onEnter: function () {
                    setupRadioCall(null, 's07-dispatch-call-audio', 's07-dispatch-call-text');
                },
                onExit: clearRadioCall,
                branches: [
                    { id: "audio-end", target: "dispatch-reply" }
                ]
            },
            {
                id: "dispatch-reply",
                onEnter: function () {
                    currPopup = aden.objects.load('s07-dispatch-response');
                    setupRadioReply(TIME_SHORT_YEL, TIME_SHORT_RED, TIME_SHORT_END);
                },
                onExit: function () {
                    if (currPopup) { currPopup.destroy(); }
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
                    currPopup = aden.objects.load('s07-dispatch-warning');
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
                    currPopup = aden.objects.load('s07-dispatch-reply-text');
                    currAudio = aden.objects.load('s07-dispatch-reply-audio');
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
             * cinematic 01
             * Cinematic (S07_Cin01):
             * Patrol car pulls up on the scene but remains a distance of about 50 feet from the
             * bus, which is stopped in the right lane near an intersection.
             */
            {
                id: "cinematic01",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-cin01');
                    aden.plugin.mode.setMode('vid');
                    aden.pano.load('outsidecar');
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
                    aden.pano.hotspots.showAll();
					aden.pano.camera.face(-44);
                    setupTimedObj('s07-arrival-text', 's07-arrival-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                    if (currDP) {
                        currDP.destroy();
                    }
                },
                branches: [
                    { id: "move-sidewalk", target: "cinematic02" }
                ]
            },

            /*
             * cinematic 02
             * Cinematic (S07_Cin02):
             */
            {
                id: "cinematic02",
                onEnter: function () {
                    aden.pano.hotspots.hideAll();
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
					
                    currVideo = aden.objects.load('s07-cin02', false);
					currVideo.setTimedActions([{ 
						start: "00:00:09.00", 
						onStart: function(){
							currPopup = aden.objects.load('s07-cin02-text');
						}
					}]);
					currVideo.start();
					
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                    aden.plugin.mode.setMode('pano');
                },
                branches: [
                    { id: "video-end", target: "dp01" }
                ]
            },
            
            /*
             * Continued from Scenario Start-up. FPV panorama from sidewalk near the bus driver.
             */
            
            {
                id: "dp01",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }
					aden.pano.camera.lookTo(-26.95, 12.17);
                    setupTimedObj('s07-dp01', 's07-dp01-warning');
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
                object: 's07-dp01-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp01-r2',
                object: 's07-dp01-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp01-r3',
                object: 's07-dp01-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp01-r4',
                object: 's07-dp01-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            {
                id: 'dp01-r5',
                object: 's07-dp01-r05',
                branches: [
                    { id: "popup-destroy", target: "cinematic03" }
                ]
            },
            
            /*
             * Cinematic (S07_Cin03):
             * Moves closer to the open front door of the bus to look inside.
             */
            {
                id: "cinematic03",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-cin03');
                    aden.pano.load('busdoor');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp02-intro" }
                ]
            },

            // -- dp 02 --
            
            /*
             * FPV panorama from just outside the open front door of the bus.
             * The computer bag is visible on the seat directly behind the driver’s seat.
             * The computer bag has a cell phone clipped to the side with wires running
             * from the phone to inside the computer bag. Rows of nails are duct-taped to
             * the outside of the computer bag. See Decision 2.
             */
            
            {
                id: "dp02-intro",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('bus-investigation');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario07.trigger('timeup');
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
					aden.pano.camera.lookTo(46.01, 14.04);
                    setupTimedObj('s07-dp02', 's07-dp02-warning');
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
                object: 's07-dp02-r01',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r2',
                object: 's07-dp02-r02',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r3',
                object: 's07-dp02-r03',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r4',
                object: 's07-dp02-r04',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },

            // -- dp 03 --

            {
                id: "dp03",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s07-dp03', 's07-dp03-warning');
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
                object: 's07-dp03-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            {
                id: 'dp03-r2',
                object: 's07-dp03-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            {
                id: 'dp03-r3',
                object: 's07-dp03-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            {
                id: 'dp03-r4',
                object: 's07-dp03-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            
            /*
             * Cinematic (S07_Cin04): From the learner’s POV, we see pedestrians moving quickly away from the immediate area. No one should be walking past the bus. All moving away from it quickly.
             */
            {
                id: "cinematic04",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-cin04');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp04" }
                ]
            },

            // -- dp 04 --
            
            /*
             * FPV panorama from just outside the open front door of the bus.
             */
            
            {
                id: "dp04",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s07-dp04', 's07-dp04-warning');
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
                object: 's07-dp04-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp04-r2',
                object: 's07-dp04-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            {
                id: 'dp04-r3',
                object: 's07-dp04-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic05" }
                ]
            },
            
            /*
             * Cinematic (S07_Cin05):
             * FPV moving quickly back to the patrol car and taking cover behind the car.
             * In the background people would be continuing to leave the area.
             * No one should be near the bus at this time though. See Decision 4.
             */
            {
                id: "cinematic05",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-cin05');
                    aden.plugin.mode.setMode('vid');
					aden.pano.load('patrolcar');
					aden.pano.hotspots.hideAll();
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp05" }
                ]
            },
            
            // -- dp 5 --
            // Continued from Decision 3. FPV panorama looking at the bus from behind the patrol car approx. 50 ft. away.
            
            {
                id: "dp05",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }
					aden.pano.camera.lookTo(-1.54, 14.58);
					aden.pano.hotspots.hideAll();
                    setupTimedObj('s07-dp05', 's07-dp05-warning');
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
                object: 's07-dp05-r01',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r2',
                object: 's07-dp05-r02',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r3',
                object: 's07-dp05-r03',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },
            {
                id: 'dp05-r4',
                object: 's07-dp05-r04',
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },

            // -- dp 06 --

            {
                id: "dp06",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s07-dp06', 's07-dp06-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp06-r1" },
                    { id: "option1", target: "dp06-r2" },
                    { id: "option2", target: "dp06-r3" },
                    { id: "option3", target: "dp06-r4" },
                    { id: "option4", target: "dp06-r5" },
                    { id: "option5", target: "dp06-r6" }
                ]
            },
            {
                id: 'dp06-r1',
                object: 's07-dp06-r01',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            {
                id: 'dp06-r2',
                object: 's07-dp06-r02',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            {
                id: 'dp06-r3',
                object: 's07-dp06-r03',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },

            // -- dp 07 --

            {
                id: "dp07-intro",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s07-threat-assess');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario07.trigger('timeup');
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
                    { id: 'skip',   target: 'dp07' },
                    { id: 'timeup', target: 'dp07' }
                ]
            },
            {
                id: "dp07",
                onEnter: function () {

                    setupTimedObj('s07-dp07', 's07-dp07-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp07-r1" },
                    { id: "dp-wrong",   target: "dp07-r2" }
                ]
            },
            {
                id: 'dp07-r1',
                object: 's07-dp07-r01',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r2',
                object: 's07-dp07-r02',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },

            // -- dp 08 --

            {
                id: "dp08",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s07-dp08', 's07-dp08-warning');
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
                object: 's07-dp08-r01',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },
            {
                id: 'dp08-r2',
                object: 's07-dp08-r02',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },
            {
                id: 'dp08-r3',
                object: 's07-dp08-r03',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },
            {
                id: 'dp08-r4',
                object: 's07-dp08-r04',
                branches: [
                    { id: "popup-destroy", target: "dp09-intro" }
                ]
            },

            // -- dp 09 --

            {
                id: "dp09-intro",
                object: "s07-dp09-intro",
                branches: [
                    { id: "popup-destroy", target: "dp09" }
                ]
            },
            {
                id: "dp09",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s07-dp09', 's07-dp09-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp09-r1" },
                    { id: "option1", target: "dp09-r2" },
                    { id: "option2", target: "dp09-r3" },
                    { id: "option3", target: "dp09-r4" },
                    { id: "option4", target: "dp09-r5" },
                    { id: "option5", target: "dp09-r6" }
                ]
            },
            {
                id: 'dp09-r1',
                object: 's07-dp09-r01',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r2',
                object: 's07-dp09-r02',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r3',
                object: 's07-dp09-r03',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r4',
                object: 's07-dp09-r04',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },

            // -- dp 10 --

            {
                id: "dp10",
                onEnter: function () {

                    setupTimedObj('s07-dp10', 's07-dp10-warning');
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
                object: 's07-dp10-r01',
                branches: [
                    { id: "popup-destroy", target: "dp11" }
                ]
            },
            {
                id: 'dp10-r2',
                object: 's07-dp10-r02',
                branches: [
                    { id: "popup-destroy", target: "dp11" }
                ]
            },

            // -- dp 11 --

            {
                id: "dp11",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }

                    setupTimedObj('s07-dp11', 's07-dp11-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp11-r1" },
                    { id: "option1", target: "dp11-r2" },
                    { id: "option2", target: "dp11-r3" },
                    { id: "option3", target: "dp11-r4" },
                    { id: "option4", target: "dp11-r5" },
                    { id: "option5", target: "dp11-r6" }
                ]
            },
            {
                id: 'dp11-r1',
                object: 's07-dp11-r01',
                branches: [
                    { id: "popup-destroy", target: "dp11-response" }
                ]
            },
            {
                id: 'dp11-r2',
                object: 's07-dp11-r02',
                branches: [
                    { id: "popup-destroy", target: "dp11-response" }
                ]
            },
            {
                id: 'dp11-r3',
                object: 's07-dp11-r03',
                branches: [
                    { id: "popup-destroy", target: "dp11-response" }
                ]
            },
            {
                id: 'dp11-r4',
                object: 's07-dp11-r04',
                branches: [
                    { id: "popup-destroy", target: "dp11-response" }
                ]
            },
            {
                id: 'dp11-r5',
                object: 's07-dp11-r05',
                branches: [
                    { id: "popup-destroy", target: "dp11-response" }
                ]
            },
            {
                id: "dp11-response",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s07-dp11-response-audio');
                    currPopup = aden.objects.load('s07-dp11-response-text');
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
                    { id: "audio-end", target: "cinematic06" }
                ]
            },
            
            /*
             * Cinematic (S07_C06): 
             * FPV from inside the patrol car driving slowly out of the area 
             * with siren chirping. Approaching police assembly area. 
             * See Decision 9.
             */
            {
                id: "cinematic06",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-cin06');
                    aden.plugin.mode.setMode('vid');
                    aden.pano.load('barricades');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp12" }
                ]
            },
            
            // -- dp 12 --

            {
                id: "dp12",
                onEnter: function () {
                    if (currScreen) { currScreen.destroy(); }
                    setupTimedObj('s07-dp12', 's07-dp12-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp12-r1" },
                    { id: "option1", target: "dp12-r2" },
                    { id: "option2", target: "dp12-r3" },
                    { id: "option3", target: "dp12-r4" }
                ]
            },
            {
                id: 'dp12-r1',
                object: 's07-dp12-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic07" }
                ]
            },
            {
                id: 'dp12-r2',
                object: 's07-dp12-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic07" }
                ]
            },
            {
                id: 'dp12-r3',
                object: 's07-dp12-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic07" }
                ]
            },
            {
                id: 'dp12-r4',
                object: 's07-dp12-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic07" }
                ]
            },
            
            /*
             * Play cinematic (S07_Cin07):
             * FPV of pedestrians approaching and stopping at the police barricade.
             */
            {
                id: "cinematic07",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-cin07');
                    aden.plugin.mode.setMode('vid');
                    if (currScreen) { currScreen.destroy(); }
                },
                onExit: function () {
                    if (currVideo) { currVideo.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "cinematic08" }
                ]
            },
            
            /*
             * Play cinematic (S07_Cin08): Bomb Tech Lead asks for a briefing.
             */
            {
                id: "cinematic08",
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    if (currScreen) { currScreen.destroy(); }
                    currScreen = aden.objects.load('s07-bomb-tech');
                    currVideo = aden.objects.load('s07-cin08');
                    currPopup = aden.objects.load('s07-dp13-intro-text');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('static');
                    if (currVideo) { currVideo.destroy(); }
                    if (currPopup) { currPopup.destroy(); }
                },
                branches: [
                    { id: "video-end", target: "dp13" }
                ]
            },
            
            // -- dp 13 --

            {
                id: "dp13",
                onEnter: function () {
                    setupTimedObj('s07-dp13', 's07-dp13-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp13-r1" },
                    { id: "dp-wrong",   target: "dp13-r2" }
                ]
            },
            {
                id: 'dp13-r1',
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-tech-positive');
					currPopup = aden.objects.load('s07-dp13-r01');
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
                id: 'dp13-r2',
                onEnter: function () {
                    if (currAudio) { currAudio.destroy(); }
                    aden.plugin.status.set('green');
                    currVideo = aden.objects.load('s07-tech-negative');
					currPopup = aden.objects.load('s07-dp13-r02');
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


