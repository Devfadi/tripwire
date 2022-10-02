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
        aden.plugin.status.add(time3, function () { aden.fsm.scenario02.trigger('ignore'); });
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
        aden.plugin.status.add(TIME_SPLIT_2, function () { aden.fsm.scenario02.trigger('ignored'); });
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
        id      : 'scenario02',
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

            {
                id: "start",
                object: "s02-intro",
                onEnter: function () {
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('pano');
                    aden.pano.hotspots.hideAll();
                },
                branches: [
                    { id: "popup-destroy", target: "dispatch01" }
                ]
            },

            // -- Dispatch call --

            {
                id: "dispatch01",
                onEnter: function () {
                    setupRadioCall(null, 's02-dispatch01', 's02-dispatch01-narration');
                },
                onExit: clearRadioCall,
                branches: [
                    { id: "audio-end", target: "dispatch01-reply" }
                ]
            },
            {
                id: "dispatch01-reply",
                onEnter: function () {
                    currPopup = aden.objects.load('s02-dispatch01-instructions');
                    setupRadioReply(TIME_SHORT_YEL, TIME_SHORT_RED, TIME_SHORT_END);
                },
                onExit: function () {
                    clearRadioReply();
                    if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "ignore",      target: "dispatch01-warning" },
                    { id: "radio-click", target: "dispatch01-response" }
                ]
            },
            {
                id: "dispatch01-warning",
                onEnter: function () {
                    currPopup = aden.objects.load('s02-dispatch01-warning');
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
                    currPopup = aden.objects.load('s02-dispatch01-reply-audio');
                    currAudio = aden.objects.load('s02-dispatch01-reply-text');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "cinematic01" }
                    // { id: "audio-end", target: "move-concourse" }
                ]
            },

            /*
             * Cinematic 01:
             * Cinematic plays: FPV of a man running into the concourse area where he stops.
             * The man is re-peatedly scream-ing, “Help me! Please. I have a bomb. I don’t want
             * to hurt anyone!” Stop the cinematic on the last frame with the non-player character (
             * NPC) facing the learner approx. 30–40 ft. away. From this distance, the learner
             * will be able to see the man is wearing a vest that is chained and locked in place, a
             * walkie-talkie and a digital timer can also be seen on the out-side of the vest.
             */
            {
                id: "cinematic01",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.pano.camera.face(275);
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s02-cin01');
                    aden.pano.load('concourse');
                    aden.pano.hotspots.hideAll();
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                branches: [
                    { id: "move-concourse", target: "cinematic-01-video-wait" },
                    { id: "video-end", target: "cinematic-01-pano-wait" }
                ]
            },
            {
                id: 'cinematic-01-pano-wait',
                onEnter: function () {},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "move-concourse", target: "dp01-delay" }
                ]
            },
            {
                id: 'cinematic-01-video-wait',
                onEnter: function(){},
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp01-delay" }
                ]
            },

            //TODO - turn pano view to NPC
            //TODO - probably don't need to move here, hide arrows

            {
                id: "dp01-delay",
                onEnter: function () {
                    window.setTimeout(function () {
                        aden.fsm.scenario02.trigger('complete');
                    }, 5000);
                },
                branches: [
                    { id: "complete", target: "dp01" }
                ]
            },

            //TODO - Cinematic is stopped with the NPC facing the learner at a distance of about 30 to 40 ft.

            {
                id: "dp01",
                onEnter: function () {
                    setupTimedObj('s02-dp01', 's02-dp01-warning');
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
                object: 's02-dp01-r01',
                branches: [
                    { id: "popup-destroy", target: "dp02" }
                ]
            },
            {
                id: 'dp01-r2',
                object: 's02-dp01-r02',
                branches: [
                    { id: "popup-destroy", target: "dp02" }
                ]
            },
            {
                id: 'dp01-r3',
                object: 's02-dp01-r03',
                branches: [
                    { id: "popup-destroy", target: "dp02" }
                ]
            },

            // -- DP 02 --
            //TODO - Return to the paused cinematic with the man facing the learner/player from approx. 30–40 ft. away.

            {
                id: "dp02",
                onEnter: function () {
                    setupTimedObj('s02-dp02', 's02-dp02-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp02-r1" },
                    { id: "option1", target: "dp02-r2" }
                ]
            },
            {
                id: 'dp02-r1',
                object: 's02-dp02-r01',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },
            {
                id: 'dp02-r2',
                object: 's02-dp02-r02',
                branches: [
                    { id: "popup-destroy", target: "dp03" }
                ]
            },

            //TODO - Program is paused on the cinematic with the man facing the learner/player from approx. 30–40 ft. away.

            {
                id: "dp03",
                onEnter: function () {
                    setupTimedObj('s02-dp03', 's02-dp03-warning');
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
                object: 's02-dp03-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r2',
                object: 's02-dp03-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r3',
                object: 's02-dp03-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },
            {
                id: 'dp03-r4',
                object: 's02-dp03-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic02" }
                ]
            },

            /**
             * Cinematic 2
             * Cinematic from the same POV shows characters moving away from the man
             * (who is still the focal point of the scene). And the POV changes to depict
             * the responder/learner moving to nearby cover behind one of the pillars.
             */
            {
                id: "cinematic02",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s02-cin02');
					aden.pano.load('BehindColumn');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                branches: [
                    { id: "move-column", target: "cinematic-02-video-wait" },
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
                    { id: "move-column", target: "dp04-intro" }
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
                    { id: "video-end", target: "dp04-intro" }
                ]
            },

            // -- dp 04 --
            //TODO - Responder/learner has taken a position of cover behind a pillar but is still within sight and speaking distance of the subject. Subject is still facing the camera. Cinematic is paused.

            {
                id: "dp04-intro",
                onEnter: function () {
                    aden.plugin.status.clearTime();
                    aden.plugin.status.set('green');
                    aden.pano.camera.face(220);
                    currPopup = aden.objects.load('s02-dp04-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario02.trigger('timeup');
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
                    { id: 'skip',   target: 'dp04' },
                    { id: 'timeup', target: 'dp04' }
                ]
            },
            {
                id: "dp04",
                onEnter: function () {
                    setupTimedObj('s02-dp04', 's02-dp04-warning');
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
                object: 's02-dp04-r01',
                branches: [
                    { id: "popup-destroy", target: "investigate" }
                ]
            },
            {
                id: 'dp04-r2',
                object: 's02-dp04-r02',
                branches: [
                    { id: "popup-destroy", target: "investigate" }
                ]
            },

            {
                id: "investigate",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s02-assessment');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario02.trigger('timeup');
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
                    setupTimedObj('s02-dp05', 's02-dp05-warning');
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
                object: 's02-dp05-r01',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },
            {
                id: 'dp05-r2',
                object: 's02-dp05-r02',
                branches: [
                    { id: "popup-destroy", target: "dp06-intro" }
                ]
            },

            {
                id: "dp06-intro",
                object: "s02-dp06-intro",
                branches: [
                    { id: "popup-destroy", target: "dp06" }
                ]
            },

            //TODO - Return to responder/learner POV of the subject.

            {
                id: "dp06",
                onEnter: function () {
                    aden.objects.load('s02-dp06');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp06-r1" },
                    { id: "option1", target: "dp06-r2" },
                    { id: "option2", target: "dp06-r3" },
                    { id: "option3", target: "dp06-r4" },
                    { id: "option4", target: "dp06-r5" }
                ]
            },
            {
                id: 'dp06-r1',
                object: 's02-dp06-r01',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            {
                id: 'dp06-r2',
                object: 's02-dp06-r02',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            {
                id: 'dp06-r3',
                object: 's02-dp06-r03',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            {
                id: 'dp06-r4',
                object: 's02-dp06-r04',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },
            {
                id: 'dp06-r5',
                object: 's02-dp06-r05',
                branches: [
                    { id: "popup-destroy", target: "dp07-intro" }
                ]
            },

            // -- DP 07 --
            //TODO - Display 2 to 3 additional emergency first responders in view in the periphery of the scene.
            {
                id: "dp07-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s02-dp07-audio');
                    currPopup = aden.objects.load('s02-dp07-intro');
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
                    { id: "audio-end", target: "dp07" }
                ]
            },

            {
                id: "dp07",
                onEnter: function () {
                    setupTimedObj('s02-dp07', 's02-dp07-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp07-r1" },
                    { id: "option1", target: "dp07-r2" },
                    { id: "option2", target: "dp07-r3" },
                    { id: "option3", target: "dp07-r4" },
                    { id: "option4", target: "dp07-r5" }
                ]
            },
            {
                id: 'dp07-r1',
                object: 's02-dp07-r01',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r2',
                object: 's02-dp07-r02',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r3',
                object: 's02-dp07-r03',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r4',
                object: 's02-dp07-r04',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            {
                id: 'dp07-r5',
                object: 's02-dp07-r05',
                branches: [
                    { id: "popup-destroy", target: "dp08" }
                ]
            },
            
			
			{
                id: "dp08",
                onEnter: function () {
                    setupSplitDP1('s02-dp08');
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
                    { id: "ignored", target: "dp08-ignore" }
                ]
            },
            {
                id: "dp08-ignore",
                onEnter: function () {
                    if (currDP) {
                        currDP.destroy();
                    }
                    aden.objects.load('s02-dp08-warning01');
                },
                branches: [
                    { id: "popup-destroy", target: "dp08-2" }
                ]
            },
            {
                id: "dp08-2",
                onEnter: function () {
                    setupSplitDP2('s02-dp08', 's02-dp08-warning02');
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
                object: 's02-dp08-r01',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            {
                id: 'dp08-r2',
                object: 's02-dp08-r02',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            {
                id: 'dp08-r3',
                object: 's02-dp08-r03',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            {
                id: 'dp08-r4',
                object: 's02-dp08-r04',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
            {
                id: 'dp08-r5',
                object: 's02-dp08-r05',
                branches: [
                    { id: "popup-destroy", target: "cinematic04" }
                ]
            },
			
            /*
             * Cinematic 04
             * Initiate a cinematic in which a civilian enters the scene within a few feet of the responder/ learner, walking toward the subject.
             */
            {
                id: "cinematic04",
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s02-cin03');
                    currPopup = aden.objects.load('s02-cinematic04-text');
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
					if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp09-intro" }
                ]
            },

            
            {
                id: "dp09-intro",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s02-dp09-audio');
                    currPopup = aden.objects.load('s02-dp09-intro');
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
                    setupTimedObj('s02-dp09', 's02-dp09-warning');
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp09-r1" },
                    { id: "dp-wrong",   target: "dp09-r2" }
                ]
            },
            
            //TODO - Need final bomb tech response audio (differs from scenario 01) 
            {
                id: 'dp09-r1',
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s02-dp09-r01-audio');
                    currPopup = aden.objects.load('s02-dp09-r01-text');
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
                    { id: "audio-end", target: "end" }
                ]
            },
            {
                id: 'dp09-r2',
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s02-dp09-r02-audio');
                    currPopup = aden.objects.load('s02-dp09-r02-text');
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
                    { id: "audio-end", target: "end" }
                ]
            },

            {
                id: 'end',
                onEnter: function () {
                    aden.plugin.map.close();
                    aden.fsm.gameView.trigger('end');
                    aden.plugin.mode.el.hide();
                    if (currAudio) { currAudio.destroy(); }
                    if (currScreen) { currScreen.destroy(); }
                }
            }
        ]
    };

    return fsm;
});
