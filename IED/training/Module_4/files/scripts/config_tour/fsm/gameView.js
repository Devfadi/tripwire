define(function(require){
    
    var $               = require('jquery'),
        _               = require('lodash'),
        aden            = require('adayana/aden/engine'),
        advText         = require('config_tour/AdvText'),
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
    
    var gameView = {
        id      : 'gameView',
        type    : 'graph',
        initial : 'loading',
        debug   : '#fsm-game-view',
        states  : [
            {
                // displays loading screen
                id: "loading",
                onEnter: function(){
                    mediator.publish('trigger:preload:show');
                },
                branches : [
                    { id: "complete", target: "splash" }
                ]
            },
            {
                // display the splash screen after loading is complete
                id: "splash",
                onEnter: function(){
                    mediator.publish('trigger:preload:hide');
                    currScreen = new Splash('splash-screen','files/templates/screens/splash.html', advText.splash );
                    instruction = 0;
                },
                onExit: function(){
                    currScreen.destroy();
                },
                branches : [
                    // { id: "start", target: "introduction" },
                    { id: "start", target: "menu" },
                    { id: "skip",  target: "menu" }
                ]
            },
            {
                // display course menu
                id: "menu",
                onEnter: function(){
                    currScreen = new SelectionScreen('selection-screen','files/templates/screens/selection.html',{
                        enableHelpBtn: false,
                        selections:[
                            { name: 'Scenario 1',  event: 'scenario1',   enabled: false },
                            { name: 'Scenario 2',  event: 'scenario2',   enabled: true },
                            { name: 'Scenario 3',  event: 'scenario3',   enabled: false },
                            { name: 'Scenario 4',  event: 'scenario4',   enabled: false },
                            { name: 'Scenario 5',  event: 'scenario5',   enabled: false },
                            { name: 'Scenario 6',  event: 'scenario6',   enabled: false },
                            { name: 'Scenario 7',  event: 'scenario7',   enabled: false },
                            { name: 'Scenario 8',  event: 'scenario8',   enabled: false },
                            { name: 'Scenario 9',  event: 'scenario9',   enabled: false },
                            { name: 'Certificate', event: 'certificate', enabled: false },
                        ]
                    });
                },
                onExit   : function(){
                    currScreen.destroy();
                },
                branches : [
                    { id: "help",        target: "introduction"   },
                    { id: "scenario1",   target: "scenario1-load" },
                    { id: "scenario2",   target: "scenario2-load" },
                    { id: "scenario3",   target: "scenario3-load" },
                    { id: "scenario4",   target: "scenario4-load" },
                    { id: "scenario5",   target: "scenario5-load" },
                    { id: "scenario6",   target: "scenario6-load" },
                    { id: "scenario7",   target: "scenario7-load" },
                    { id: "scenario8",   target: "scenario8-load" },
                    { id: "scenario9",   target: "scenario9-load" },
                    { id: "certificate", target: "certificate"    }
                ]
            },
            
            {
                id: "scenario2-load",
                onEnter : function(){
                    mediator.publish('set:preload:message','Loading Scenario 2');
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
                onEnter : function(){
                    currScreen = new PauseScreen('pause-screen','files/templates/screens/pause.html', null );
                    mediator.publish('trigger:preload:hide');
                    aden.fsm.scenario02.trigger('start');
                },
                onExit: function() {
                    currScreen.destroy();
                    // reset fsm
                    aden.fsm.scenario02.reset();
                },
                branches: [
                    { id: 'end', target: 'menu' }
                ]
            }
        ]
    };
    
    return gameView;
});
