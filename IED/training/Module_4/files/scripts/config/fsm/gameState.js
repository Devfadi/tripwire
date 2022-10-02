define(function(require){
    
    var $ = require('jquery'),
        _ = require('lodash'),
        PauseScreen = require('modules/screens/pauseScreen'),
        aden = require('adayana/aden/engine');
    
    var currScreen;
    
    var gameState = {
        id      : 'gameState',
        type    : 'graph',
        initial : 'menu',
        debug   : '#game-state',
        states  : [
            {
                // player is navigating through menus
                id: "menu",
                branches: [
                    { id: "launch", target: "loading" }
                ]
            },
            {
                id: "loading",
                branches: [
                    { id: "complete", target: "active" }
                ]
            },
            {
                id: 'active',
                branches: [
                    { id: "toggle-pause", target: 'paused' } // pause game
                ]
            },
            {
                // game is paused
                id: "paused",
                onEnter: function(){
                    currScreen = new PauseScreen('game-pause-screen','files/templates/screens/pause2.html', null, {
                        shouldOpenOnEvent: false,
                        shouldTogglePosition: false,
                        shouldToggleVisibility: true,
                        openOnInit: true,
                        clickElToggle: false
                    });
                },
                onExit: function(){
                    if (currScreen){
                        currScreen.destroy();
                    }
                },
                branches: [
                    { id: "toggle-pause", target: 'active' }
                ]
            }
        ]
    };
    
    return gameState;
});
