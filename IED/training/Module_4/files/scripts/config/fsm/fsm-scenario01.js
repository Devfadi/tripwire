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

    function clearRadioResponse() {
        aden.plugin.status.clear();
        aden.plugin.radio.deactivate();
        aden.plugin.radio.removeGlow();
    }

    var fsm = {
        id      : 'scenario01',
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
                    { id: "load", target: "loading" }
                ]
            },
            {
                id: "loading",
                onEnter: function () {
                    aden.plugin.mode.el.show();
                    aden.plugin.mode.setMode('static');
                    currScreen = aden.objects.load('s01-start-screen');
                },
                branches : [
                    { id: "start", target: "dispatch01-load" }
                ]
            },
            {
                id: "dispatch01-load",
                onEnter: function () {
                    aden.pano.hotspots.hideAll();
                    currAudio  = aden.objects.load('audio-01');
                },
                branches: [
                    { id: "audio-play", target: "dispatch01-play" }
                ]
            },
            {
                id: "dispatch01-play",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currPopup  = aden.objects.load('s01-pop2');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "wait-response" }
                ]
            },
            {
                id: "wait-response",
                onEnter: function () {
                    currPopup = aden.objects.load('s01-dispatch-prompt');

                    aden.plugin.radio.addGlow();
                    aden.plugin.radio.activate();

                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_SHORT_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_SHORT_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_SHORT_END, function () { aden.fsm.scenario01.trigger('ignore'); });
                    aden.plugin.status.setTime(TIME_SHORT_END);
                },
                onExit: function () {
                    clearRadioResponse();
                    if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "ignore",      target: "call-fail" },
                    { id: "radio-click", target: "dispatch01-response" }
                ]
            },
            {
                id: "call-fail",
                onEnter: function () {
                    currPopup = aden.objects.load('s01-fail01');
                    aden.plugin.radio.addGlow();
                    aden.plugin.radio.activate();
                },
                onExit: function () {
                    clearRadioResponse();
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
                    currPopup = aden.objects.load('narration-05');
                    currAudio = aden.objects.load('audio-05');
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

            {
                id: "cinematic01",
                // squad car rolls up behind the van;
                onEnter: function () {
                    if (currAudio) {
                        currAudio.destroy();
                    }
                    aden.plugin.status.set('green');
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s01-cin01');
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
                    { id: "video-end", target: "wait-move" }
                ]
            },



            {
                id: "wait-move",
                // wait for player to move up to the parked van
                onEnter: function () {
                    aden.pano.hotspots.showAll();
                    aden.plugin.radio.activate();
                    currPopup = aden.objects.load('s01-instructions');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-warning-popup');
                        aden.plugin.status.clearTime();
                    });

                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                    aden.plugin.radio.deactivate();
                    if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "ignore",      target: "move-fail" },
                    { id: "move-van",    target: "investigate-van"       },
                    { id: "move-cafe",   target: "move-fail" }
                ]
            },
            {
                id: "move-fail",
                object: "s01-fail02",
                branches: [
                    { id: "popup-destroy", target: "end" }
                ]
            },
            {
                id: "investigate-van",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s01-30sec');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario01.trigger('timeup');
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
                    { id: 'skip',   target: 'dp1' },
                    { id: 'timeup', target: 'dp1' }
                ]
            },

            // -- dp 1 --

            {
                id: "dp1",
                onEnter: function () {
                    aden.plugin.tracker.set({
                        id     : 's01-investigate',
                        state  : 'success',
                        points : 0
                    });
                    aden.objects.load('s01-dp01');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp01-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp1-r1" },
                    { id: "option1", target: "dp1-r2" },
                    { id: "option2", target: "dp1-r3" }
                ]
            },
            {
                id: 'dp1-r1',
                object: 's01-dp01-r01',
                branches: [
                    { id: "popup-destroy", target: "dp2" }
                ]
            },
            {
                id: 'dp1-r2',
                object: 's01-dp01-r02',
                branches: [
                    { id: "popup-destroy", target: "dp2" }
                ]
            },
            {
                id: 'dp1-r3',
                object: 's01-dp01-r03',
                branches: [
                    { id: "popup-destroy", target: "dp2" }
                ]
            },

            // -- dp2 --
            {
                id: 'dp2',
                object: 's01-dp02',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL,  function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED,  function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp02-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct",      target: "dp2-r1" },
                    { id: "dp-wrong",        target: "dp2-r2" },
                    { id: "dp-max-attempts", target: "dp2-r2" }
                ]
            },
            {
                id: 'dp2-r1',
                object: 's01-dp02-r01',
                branches: [
                    { id: "popup-destroy", target: "dp3" }
                ]
            },
            {
                id: 'dp2-r2',
                object: 's01-dp02-r02',
                branches: [
                    { id: "popup-destroy", target: "dp3" }
                ]
            },

            // -- dp3 --
            {
                id: 'dp3',
                object: 's01-dp03',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL,  function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED,  function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp03-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp3-r1" },
                    { id: "option1", target: "dp3-r2" },
                    { id: "option2", target: "dp3-r3" }
                ]
            },
            {
                id: 'dp3-r1',
                object: 's01-dp03-r01',
                branches: [
                    { id: 'popup-destroy', target: 'cinematic02' }
                ]
            },
            {
                id: 'dp3-r2',
                object: 's01-dp03-r02',
                branches: [
                    { id: 'popup-destroy', target: 'cinematic02' }
                ]
            },
            {
                id: 'dp3-r3',
                object: 's01-dp03-r03',
                branches: [
                    { id: 'popup-destroy', target: 'cinematic02' }
                ]
            },

            {
                id: "cinematic02",
                // move away from van.
                onEnter: function () {
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s01-cin02');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp4-setup" }
                ]
            },

            // -- dp 4 --
            {
                id: 'dp4-setup',
                onEnter: function () {
                    aden.pano.load('car');
                },
                branches: [
                    { id: "move-car", target: "dp4" }
                ]
            },
            {
                id: 'dp4',
                onEnter: function () {
                    currDP = aden.objects.load('s01-dp04');
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_SPLIT_1, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_SPLIT_2, function () { aden.fsm.scenario01.trigger('ignored'); });
                    aden.plugin.status.setTime(TIME_SPLIT_2);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp4-r1" },
                    { id: "option1", target: "dp4-r2" },
                    { id: "ignored", target: "dp4-ignore" }
                ]
            },
            {
                id: 'dp4-2',
                object: 's01-dp04',
                onEnter: function () {
                    aden.plugin.status.add(TIME_SPLIT_3, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_SPLIT_4, function () {
                        aden.objects.load('s01-dp04-ignore02');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_SPLIT_4);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp4-r1" },
                    { id: "option1", target: "dp4-r2" }
                ]
            },
            {
                id: 'dp4-r1',
                object: 's01-dp04-r01',
                branches: [
                    { id: 'popup-destroy', target: 'dp5' }
                ]
            },
            {
                id: 'dp4-r2',
                object: 's01-dp04-r02',
                branches: [
                    { id: 'popup-destroy', target: 'dp5' }
                ]
            },
            {
                id: 'dp4-ignore',
                onEnter: function () {
                    if (currDP) {
                        currDP.destroy();
                    }
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('s01-dp04-ignore01');
                    currAudio = aden.objects.load('audio-02');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "dp4-2" }
                ]
            },

            // -- dp 5 --
            {
                id: 'dp5',
                object: 's01-dp05',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp05-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp5-r1" },
                    { id: "dp-wrong", target: "dp5-r2" }
                ]
            },
            {
                id: 'dp5-r1',
                object: 's01-dp05-r01',
                branches: [
                    { id: 'popup-destroy', target: 'dp6' }
                ]
            },
            {
                id: 'dp5-r2',
                object: 's01-dp05-r02',
                branches: [
                    { id: 'popup-destroy', target: 'dp6' }
                ]
            },

            // -- dp 6 --
            {
                id: 'dp6',
                object: 's01-dp06',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp06-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp6-r1" },
                    { id: "option1", target: "dp6-r2" }
                ]
            },
            {
                id: 'dp6-r1',
                object: 's01-dp06-r01',
                branches: [
                    { id: 'popup-destroy', target: 'assess-threats' }
                ]
            },
            {
                id: 'dp6-r2',
                object: 's01-dp06-r02',
                branches: [
                    { id: 'popup-destroy', target: 'assess-threats' }
                ]
            },

            // -- dp 7 --

            {
                id: "assess-threats",
                onEnter: function () {
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s01-assess-threats');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario01.trigger('timeup');
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
                    { id: 'skip', target: 'dp7' },
                    { id: 'timeup', target: 'dp7' }
                ]
            },

            {
                id: 'dp7',
                object: 's01-dp07',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp07-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp7-r1" },
                    { id: "dp-wrong",   target: "dp7-r2" }
                ]
            },
            {
                id: 'dp7-r1',
                object: 's01-dp07-r01',
                branches: [
                    { id: 'popup-destroy', target: 'dp8' }
                ]
            },
            {
                id: 'dp7-r2',
                object: 's01-dp07-r02',
                branches: [
                    { id: 'popup-destroy', target: 'dp8' }
                ]
            },

            // -- dp 8 --

            {
                id: 'dp8',
                object: 's01-dp08',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp08-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp8-r1" },
                    { id: "option1", target: "dp8-r2" },
                    { id: "option2", target: "dp8-r3" }
                ]
            },
            {
                id: 'dp8-r1',
                object: 's01-dp08-r01',
                branches: [
                    { id: 'popup-destroy', target: 'dp9-intro' }
                ]
            },
            {
                id: 'dp8-r2',
                object: 's01-dp08-r02',
                branches: [
                    { id: 'popup-destroy', target: 'dp9-intro' }
                ]
            },
            {
                id: 'dp8-r3',
                object: 's01-dp08-r03',
                branches: [
                    { id: 'popup-destroy', target: 'dp9-intro' }
                ]
            },

            // -- dp 9 --

            {
                id: "dp9-intro",
                onEnter: function () {
                    aden.plugin.status.clearTime();
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s01-dp09-intro');
                    aden.plugin.status.add(WAIT_TIME, function () {
                        aden.fsm.scenario01.trigger('timeup');
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
                    { id: 'skip',   target: 'dp9' },
                    { id: 'timeup', target: 'dp9' }
                ]
            },
            {
                id: 'dp9',
                object: 's01-dp09',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp09-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp9-r1" },
                    { id: "dp-wrong", target: "dp9-r2" }
                ]
            },
            {
                id: 'dp9-r1',
                object: 's01-dp09-r01',
                branches: [
                    { id: 'popup-destroy', target: 'dispatcher-response-02' }
                ]
            },
            {
                id: 'dp9-r2',
                object: 's01-dp09-r02',
                branches: [
                    { id: 'popup-destroy', target: 'dispatcher-response-02' }
                ]
            },

            {
                id: "dispatcher-response-02",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('narration-05');
                    currAudio = aden.objects.load('audio-05');
                },
                onExit: function () {
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "cinematic03" }
                ]
            },

            {
                id: "cinematic03",
                // move away from van.
                onEnter: function () {
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s01-cin03');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('pano');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dispatcher-arriving" }
                ]
            },
            {
                id: "dispatcher-arriving",
                onEnter: function () {
                    aden.pano.hotspots.hideAll();
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('s01-pop4');
                    currAudio = aden.objects.load('audio-04');
                },
                onExit: function () {
                    currPopup.destroy();
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "dp10" }
                ]
            },

            // -- dp 10 --
            {
                id: 'dp10',
                object: 's01-dp10',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL,  function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED,  function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp10-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp10-r1" },
                    { id: "option1", target: "dp10-r2" },
                    { id: "ignored", target: "dp10-ignore" }
                ]
            },
            {
                id: 'dp10-r1',
                object: 's01-dp10-r01',
                branches: [
                    { id: 'popup-destroy', target: 'dispatch-cordon' }
                ]
            },
            {
                id: 'dp10-r2',
                object: 's01-dp10-r02',
                branches: [
                    { id: 'popup-destroy', target: 'dispatch-cordon' }
                ]
            },

            {
                id: "dispatch-cordon",
                onEnter: function () {
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('narration-06');
                    currAudio = aden.objects.load('audio-06');
                },
                onExit: function () {
                    currPopup.destroy();
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "cinematic04" }
                ]
            },

            {
                id: "cinematic04",
                // move away from van.
                onEnter: function () {
                    aden.plugin.mode.setMode('vid');
                    currScreen = aden.objects.load('s01-screen04');
                    currVideo = aden.objects.load('s01-cin04');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('static');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp11" }
                ]
            },

            // -- dp 11 --
            {
                id: 'dp11',
                object: 's01-dp11',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL,  function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED,  function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp11-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "option0", target: "dp11-r1" },
                    { id: "option1", target: "dp11-r2" }
                ]
            },
            {
                id: 'dp11-r1',
                object: 's01-dp11-r01',
                branches: [
                    { id: 'popup-destroy', target: 'cinematic05' }
                ]
            },
            {
                id: 'dp11-r2',
                object: 's01-dp11-r02',
                branches: [
                    { id: 'popup-destroy', target: 'cinematic05' }
                ]
            },
            {
                id: "cinematic05",
                // move away from van.
                onEnter: function () {
                    if (currScreen) {
                        currScreen.destroy();
                    }
                    aden.plugin.mode.setMode('vid');
                    currScreen = aden.objects.load('s01-screen05');
                    currVideo = aden.objects.load('s01-cin05');
                },
                onExit: function () {
                    aden.plugin.mode.setMode('static');
                    if (currVideo) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "dp12" }
                ]
            },

            // -- dp 12 --
            {
                id: 'dp12',
                object: 's01-dp12',
                onEnter: function () {
                    aden.plugin.status.set('green');
                    aden.plugin.status.add(TIME_LONG_YEL, function () { aden.plugin.status.set('yellow'); });
                    aden.plugin.status.add(TIME_LONG_RED, function () { aden.plugin.status.set('red'); });
                    aden.plugin.status.add(TIME_LONG_END, function () {
                        aden.objects.load('s01-dp12-ignore');
                        aden.plugin.status.clearTime();
                    });
                    aden.plugin.status.setTime(TIME_LONG_END);
                },
                onExit: function () {
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp12-r1" },
                    { id: "dp-wrong",   target: "dp12-r2" },
                    { id: "ignored",    target: "dp12-ignore" }
                ]
            },
            {
                id: 'dp12-r1',
                onEnter: function () {
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s01-cin05a');
                    currPopup = aden.objects.load('s01-dp12-r01');
                },
                onExit: function () {
                    if (currVideo) {
                        currVideo.destroy();
                    }
                    if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: 'end' }
                ]
            },
            {
                id: 'dp12-r2',
                onEnter: function () {
                    aden.plugin.mode.setMode('vid');
                    currVideo = aden.objects.load('s01-cin05b');
                    currPopup = aden.objects.load('s01-dp12-r02');
                },
                onExit: function () {
                    if (currVideo) {
                        currVideo.destroy();
                    }
                    if (currPopup) {
                        currPopup.destroy();
                    }
                },
                branches: [
                    { id: 'video-end', target: 'end' }
                ]
            },
            {
                id: 'end',
                onEnter: function () {
                    aden.plugin.map.close();
                    aden.fsm.gameView.trigger('end');
                    aden.plugin.mode.setMode('static');
                    if (currAudio) { currAudio.destroy(); }
                    if (currScreen) { currScreen.destroy(); }
                    aden.plugin.mode.el.hide();
                }
            }
        ]
    };

    return fsm;
});
