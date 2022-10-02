define(function(require){
    
    var $               = require('jquery'),
        _               = require('lodash'),
        aden            = require('adayana/aden/engine'),
        debug           = require('adayana/debug/debug'),
        Splash          = require('modules/screens/splash'),
        NavScreen       = require('modules/screens/navScreen'),
        SelectionScreen = require('modules/screens/selectionScreen'),
        ScenarioScreen  = require('modules/screens/scenarioScreen'),
        mediator        = require('adayana/modules/mediatorShim');
    
    var currAudio;
    var currVideo;
    var currPopup;
    var currDP;
        
    var TIME_SHORT_YEL = 3000,
        TIME_SHORT_RED = 6000,
        TIME_SHORT_END = 10000,
        
        TIME_SPLIT_1   = 8000,
        TIME_SPLIT_2   = 10000,
        TIME_SPLIT_3   = 8000,
        TIME_SPLIT_4   = 10000,
        
        TIME_LONG_YEL  = 10000,
        TIME_LONG_RED  = 15000,
        TIME_LONG_END  = 20000;
        
    var fsm = {
        id      : 'scenario01',
        type    : 'graph',
        initial : 'home',
        debug   : '#fsm-game-state',
        
        states  : [
            {
                id: "home",
                onEnter: function(){
                    if ( currAudio ) {
                        currAudio.destroy();
                    }
                },
                branches : [
                    { id: "start", target: "start" }
                ]
            },
            {
                id: "start",
                object: "s02-tour-intro",
                onEnter: function(){
                    aden.plugin.playlist.setFSM( aden.fsm.scenario02 );
                    aden.plugin.playlist.setTriggers({
                        triggers: [
                            { id: "s02-trigger-vid-01", "event": "play-video-01", "name": "Play Video 01" },
                            { id: "s02-trigger-vid-02", "event": "play-video-02", "name": "Play Video 02" },
                            { id: "s02-trigger-vid-03", "event": "play-video-03", "name": "Play Video 03" },
                            { id: "s02-trigger-vid-04", "event": "play-video-04", "name": "Play Video 04" },
                            { id: "s02-trigger-vid-05", "event": "play-video-05", "name": "Play Video 05" }
                        ]
                    });
                },
                branches: [
                    { id: "obj-destroy", target: "idle" }
                ]
            },
            {
                id: "idle",
                branches: [
                    { id: "play-video-01", target: "video01" },
                    { id: "play-video-02", target: "video02" },
                    { id: "play-video-03", target: "video03" },
                    { id: "play-video-04", target: "video04" },
                    { id: "play-video-05", target: "video05" }
                ]
            }, 
            {
                id: "video01",
                onEnter: function(){
                    currVideo = aden.objects.load('s02-cin01');
                },
                onExit: function(){
                    if ( currVideo ) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "idle" }                
                ]
            }, 
            {
                id: "video02",
                onEnter: function(){
                    currVideo = aden.objects.load('s02-cin02');
                },
                onExit: function(){
                    if ( currVideo ) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "idle" }                
                ]
            }, 
            {
                id: "video03",
                onEnter: function(){
                    currVideo = aden.objects.load('s02-cin03');
                },
                onExit: function(){
                    if ( currVideo ) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "idle" }                
                ]
            }, 
            {
                id: "video04",
                onEnter: function(){
                    currVideo = aden.objects.load('s02-cin04');
                },
                onExit: function(){
                    if ( currVideo ) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "idle" }                
                ]
            }, 
            {
                id: "video05",
                onEnter: function(){
                    currVideo = aden.objects.load('s02-cin05');
                },
                onExit: function(){
                    if ( currVideo ) {
                        currVideo.destroy();
                    }
                },
                branches: [
                    { id: "video-end", target: "idle" }                
                ]
            }
        ]
    };
    
    return fsm;
});
