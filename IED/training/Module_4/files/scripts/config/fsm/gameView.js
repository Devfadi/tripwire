/**
 * Game View Finite State Machine Definition.
 */
define(function (require) {
    'use strict';
    
    var $               = require('jquery'),
        _               = require('lodash'),
        aden            = require('adayana/aden/engine'),
        advText         = require('config/AdvText'),
        debug           = require('adayana/debug/debug'),
        Splash          = require('modules/screens/splash'),
        NavScreen       = require('modules/screens/navScreen'),
        AARScreen       = require('modules/screens/aarScreen'),
        PauseScreen     = require('modules/screens/pauseScreen'),
        SelectionScreen = require('modules/screens/selectionScreen'),
        ScenarioScreen  = require('modules/screens/scenarioScreen'),
        mediator        = require('adayana/modules/mediatorShim');
    
    var currScreen;
    var instruction = 0;
	var seenSelection = false;
	
    var gameView = {
        id      : 'gameView',
        type    : 'graph',
        initial : 'loading',
        debug   : '#fsm-game-view',
        states  : [
            {
                // displays loading screen
                id: "loading",
                onEnter: function () {
                    mediator.publish('trigger:preload:show');
                },
                branches : [
                    { id: "complete", target: "splash" }
                ]
            },
            {
                // display the splash screen after loading is complete
                id: "splash",
                onEnter: function () {
                    aden.plugin.mode.el.hide();
                    mediator.publish('trigger:preload:hide');
                    advText.splash.version = aden.version;
                    currScreen = new Splash('splash-screen', 'files/templates/screens/splash.html', advText.splash);
                },
                onExit: function () {
                    if (currScreen){
                        currScreen.destroy();
                    }
                },
                branches : [
                    // { id: "start", target: "introduction" },
                    { id: "start", target: "introduction" },
                    { id: "skip",  target: "menu" }
                ]
            },
            {
                // display course introduction
                id: "introduction",
                onEnter: function () {
                    instruction = 0;
                    aden.fsm.gameView.trigger('next');
                },
                branches : [
                    { id: "next", target: "instruction-view" }
                ]
            },
            {
                // show the current instruction index.
                id: "instruction-view",
                onEnter: function () {
                    currScreen = new NavScreen('introduction-screen', 'files/templates/screens/instructions.html', advText.instructions[instruction]);
                },
                branches : [
                    { id: "next", target: "instruction-next-gate" },
                    { id: "back", target: "instruction-back-gate" }
                ]
            },
            {
                // determines if there's a previous instruction to display, or returns to instructions
                id: "instruction-back-gate",
                onEnter: function () {
                    instruction--;
                    if (instruction < 0) {
                        if (seenSelection) {
							aden.fsm.gameView.trigger('selection');
						} else {
							aden.fsm.gameView.trigger('splash');
						}
                    } else {
                        aden.fsm.gameView.trigger('prev-instruction');
                    }
                },
                onExit: function () {
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                branches: [
                    // { id: "prev-instruction", target: "instruction-view" },
                    { id: "prev-instruction", target: "instruction-view" },
                    { id: "splash", target: "splash" },
                    { id: "selection", target: "menu" }
                ]
            },
            {
                // determines if there's another instruction to display, or proceeds to next view
                id: "instruction-next-gate",
                onEnter: function () {
                    instruction++;
                    if (instruction < advText.instructions.length) {
                        aden.fsm.gameView.trigger('next-instruction');
                    } else {
                        aden.fsm.gameView.trigger('next-section');
                    }
                },
                onExit: function () {
                    if (currScreen) {
                        currScreen.destroy();
                    }
                },
                branches: [
                    { id: "next-instruction", target: "instruction-view" },
                    { id: "next-section",     target: "menu" }
                ]
            },
            {
                // display course menu
                id: "menu",
                onEnter: function () {
					seenSelection = true;
					instruction = advText.instructions.length - 1;
					
                    var isComplete = (aden.variables.get('scenario01_complete').value &&
                                      aden.variables.get('scenario02_complete').value &&
                                      aden.variables.get('scenario03_complete').value &&
                                      aden.variables.get('scenario04_complete').value &&
                                      aden.variables.get('scenario05_complete').value &&
                                      aden.variables.get('scenario06_complete').value &&
                                      aden.variables.get('scenario07_complete').value &&
                                      aden.variables.get('scenario08_complete').value &&
                                      aden.variables.get('scenario09_complete').value);
                    
                    if (isComplete) {
                        aden.save.recordCompletion();
                    }
                    
					var isScenarioOneComplete = !!aden.variables.get('scenario01_complete').value;
					
                    var screenData = {
                        enableHelpBtn: true,
                        selections: [
                            { name: 'Scenario 1', event: 'scenario1', 'enabled': true,                  'complete': aden.variables.get('scenario01_complete').value, 'attempted': aden.variables.get("scenario01_attempted").get() },
                            { name: 'Scenario 2', event: 'scenario2', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario02_complete').value, 'attempted': aden.variables.get("scenario02_attempted").get() },
                            { name: 'Scenario 3', event: 'scenario3', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario03_complete').value, 'attempted': aden.variables.get("scenario03_attempted").get() },
                            { name: 'Scenario 4', event: 'scenario4', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario04_complete').value, 'attempted': aden.variables.get("scenario04_attempted").get() },
                            { name: 'Scenario 5', event: 'scenario5', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario05_complete').value, 'attempted': aden.variables.get("scenario05_attempted").get() },
                            { name: 'Scenario 6', event: 'scenario6', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario06_complete').value, 'attempted': aden.variables.get("scenario06_attempted").get() },
                            { name: 'Scenario 7', event: 'scenario7', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario07_complete').value, 'attempted': aden.variables.get("scenario07_attempted").get() },
                            { name: 'Scenario 8', event: 'scenario8', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario08_complete').value, 'attempted': aden.variables.get("scenario08_attempted").get() },
                            { name: 'Scenario 9', event: 'scenario9', 'enabled': isScenarioOneComplete, 'complete': aden.variables.get('scenario09_complete').value, 'attempted': aden.variables.get("scenario09_attempted").get() }
                        ],
                        certificate: {
                            'enabled': isComplete
                        }
                    };
                    
                    currScreen = new SelectionScreen('selection-screen', 'files/templates/screens/selection.html', screenData);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "help",        target: "introduction"    },
                    { id: "clear",       target: "menu"            },
					{ id: "back", 		 target: "instruction-view" },
                    { id: "scenario1",   target: "scenario1-title" },
                    { id: "scenario2",   target: "scenario2-title" },
                    { id: "scenario3",   target: "scenario3-title" },
                    { id: "scenario4",   target: "scenario4-title" },
                    { id: "scenario5",   target: "scenario5-title" },
                    { id: "scenario6",   target: "scenario6-title" },
                    { id: "scenario7",   target: "scenario7-title" },
                    { id: "scenario8",   target: "scenario8-title" },
                    { id: "scenario9",   target: "scenario9-title" },
                    { id: "certificate", target: "certificate"     }
                ]
            },
            
            // SCENARIO 1 --------------------------------------------------------------------------
            
            {
                // display scenario 1 title screen
                id: "scenario1-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario01, {
                        attempted: aden.variables.get("scenario01_attempted").get(),
                        score: aden.variables.get("scenario01_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario1-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu" },
                    { id: "start", target: "scenario1-load" },
                    { id: "skip",  target: "scenario1-load" }
                ]
            },
            {
                // scenario 1 loading state
                id: "scenario1-load",
                onEnter : function () {
                    // send game state to loading
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 1 - Introductory Scenario');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(1);
                },
                branches : [
                    { id: "complete", target: "scenario1-run" }
                ]
            },
            {
                // scenario 1 running state
                id: 'scenario1-run',
                onEnter : function () {
                    aden.variables.get("scenario01_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    // send game state to idle
                    aden.fsm.gameState.trigger('complete');
                    // hide loading screen
                    mediator.publish('trigger:preload:hide');
                    // send scenario01 to start state
                    aden.fsm.scenario01.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario1-aar' }
                ]
            },
            {
                id: 'scenario1-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario01.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario1-load' },
                    { id: 'menu',    target: 'menu' }
                ]
            },
            
            // SCENARIO 2 --------------------------------------------------------------------------
            
            {
                id: "scenario2-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario02, {
                        attempted: aden.variables.get("scenario02_attempted").get(),
                        score: aden.variables.get("scenario02_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario2-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario2-load" },
                    { id: "skip",  target: "scenario2-load" }
                ]
            },
            {
                id: "scenario2-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 2');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(2);
                },
                branches : [
                    { id: "complete", target: "scenario2-run" }
                ]
            },
            {
                id: 'scenario2-run',
                onEnter : function () {
                    aden.variables.get("scenario02_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario02.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario2-aar' }
                ]
            },
            {
                id: 'scenario2-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario02.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario2-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // SCENARIO 3 --------------------------------------------------------------------------
            
            {
                id: "scenario3-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario03, {
                        attempted: aden.variables.get("scenario03_attempted").get(),
                        score: aden.variables.get("scenario03_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario3-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario3-load" },
                    { id: "skip",  target: "scenario3-load" }
                ]
            },
            {
                id: "scenario3-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 3');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(3);
                },
                branches : [
                    { id: "complete", target: "scenario3-run" }
                ]
            },
            {
                id: 'scenario3-run',
                onEnter : function () {
                    aden.variables.get("scenario03_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario03.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario3-aar' }
                ]
            },
            {
                id: 'scenario3-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario03.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario3-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // SCENARIO 4 --------------------------------------------------------------------------
            
            {
                id: "scenario4-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario04, {
                        attempted: aden.variables.get("scenario04_attempted").get(),
                        score: aden.variables.get("scenario04_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario4-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario4-load" },
                    { id: "skip",  target: "scenario4-load" }
                ]
            },
            {
                id: "scenario4-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 3');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(4);
                },
                branches : [
                    { id: "complete", target: "scenario4-run" }
                ]
            },
            {
                id: 'scenario4-run',
                onEnter : function () {
                    aden.variables.get("scenario04_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario04.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario4-aar' }
                ]
            },
            {
                id: 'scenario4-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario04.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario4-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // SCENARIO 5 --------------------------------------------------------------------------
            
            {
                id: "scenario5-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario05, {
                        attempted: aden.variables.get("scenario05_attempted").get(),
                        score: aden.variables.get("scenario05_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario5-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario5-load" },
                    { id: "skip",  target: "scenario5-load" }
                ]
            },
            {
                id: "scenario5-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 5');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(5);
                },
                branches : [
                    { id: "complete", target: "scenario5-run" }
                ]
            },
            {
                id: 'scenario5-run',
                onEnter : function () {
                    aden.variables.get("scenario05_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario05.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario5-aar' }
                ]
            },
            {
                id: 'scenario5-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario05.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario5-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // SCENARIO 6 --------------------------------------------------------------------------
            
            {
                id: "scenario6-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario06, {
                        attempted: aden.variables.get("scenario06_attempted").get(),
                        score: aden.variables.get("scenario06_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario6-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario6-load" },
                    { id: "skip",  target: "scenario6-load" }
                ]
            },
            {
                id: "scenario6-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 6');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(6);
                },
                branches : [
                    { id: "complete", target: "scenario6-run" }
                ]
            },
            {
                id: 'scenario6-run',
                onEnter : function () {
                    aden.variables.get("scenario06_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario06.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario6-aar' }
                ]
            },
            {
                id: 'scenario6-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario06.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario6-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // SCENARIO 7 --------------------------------------------------------------------------
            
            {
                id: "scenario7-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario07, {
                        attempted: aden.variables.get("scenario07_attempted").get(),
                        score: aden.variables.get("scenario07_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario7-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario7-load" },
                    { id: "skip",  target: "scenario7-load" }
                ]
            },
            {
                id: "scenario7-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 7');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(7);
                },
                branches : [
                    { id: "complete", target: "scenario7-run" }
                ]
            },
            {
                id: 'scenario7-run',
                onEnter : function () {
                    aden.variables.get("scenario07_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario07.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario7-aar' }
                ]
            },
            {
                id: 'scenario7-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario07.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario7-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // SCENARIO 8 --------------------------------------------------------------------------
            
            {
                id: "scenario8-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario08, {
                        attempted: aden.variables.get("scenario08_attempted").get(),
                        score: aden.variables.get("scenario08_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario8-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario8-load" },
                    { id: "skip",  target: "scenario8-load" }
                ]
            },
            {
                id: "scenario8-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 8');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(8);
                },
                branches : [
                    { id: "complete", target: "scenario8-run" }
                ]
            },
            {
                id: 'scenario8-run',
                onEnter : function () {
                    aden.variables.get("scenario08_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario08.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario8-aar' }
                ]
            },
            {
                id: 'scenario8-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario08.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario8-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // SCENARIO 9 --------------------------------------------------------------------------
            
            {
                id: "scenario9-title",
                onEnter : function () {
                    var data = $.extend({}, advText.scenario09, {
                        attempted: aden.variables.get("scenario09_attempted").get(),
                        score: aden.variables.get("scenario09_score").get()
                    });
                    currScreen = new ScenarioScreen('scenario9-screen', 'files/templates/screens/scenarioTitle.html', data);
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches : [
                    { id: "back",  target: "menu"           },
                    { id: "start", target: "scenario9-load" },
                    { id: "skip",  target: "scenario9-load" }
                ]
            },
            {
                id: "scenario9-load",
                onEnter : function () {
                    aden.fsm.gameState.trigger('launch');
                    mediator.publish('set:preload:message', 'Loading Scenario 9');
                    $('#menu-bg').hide();
                    mediator.publish('trigger:preload:show');
                    aden.loadLevel(9);
                },
                branches : [
                    { id: "complete", target: "scenario9-run" }
                ]
            },
            {
                id: 'scenario9-run',
                onEnter : function () {
                    aden.variables.get("scenario09_attempted").set(true);
                    aden.save.setState();
                    currScreen = new PauseScreen('pause-screen', 'files/templates/screens/pause.html', null);
                    aden.fsm.gameState.trigger('complete');
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario09.trigger('start');
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'end', target: 'scenario9-aar' }
                ]
            },
            {
                id: 'scenario9-aar',
                onEnter: function () {
                    aden.plugin.map.close();
                    $('#menu-bg').show();
                    currScreen = new AARScreen('aar-screen', 'files/templates/screens/aar.html', null);
                    aden.plugin.review.generate('#aar');
                    aden.fsm.scenario09.reset();
                },
                onExit: function () {
                    currScreen.destroy();
                },
                branches: [
                    { id: 'restart', target: 'scenario9-load' },
                    { id: 'menu',    target: 'menu'           }
                ]
            },
            
            // -------------------------------------------------------------------------------------
            
            {
                // display course certificate
                id       : "certificate",
                branches : [
                    { id: "back", target: "menu" }
                ]
            }
        ]
    };
    
    return gameView;
});
