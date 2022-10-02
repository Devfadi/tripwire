define(function(require){
    
    // Load and Execute Polyfill modules
    require('adayana/polyfills/animationFrame');
    require('adayana/polyfills/arrayPush');
    require('adayana/polyfills/arrayIndexOf');
    
    // Load Dependencies with references
    var $            = require('jquery'),
        _            = require('lodash'),
        mediator     = require('adayana/modules/mediatorShim'),
        detect       = require('adayana/utilities/detect'),
        debug        = require('adayana/debug/debug');
        
        
    // CONFIG DATA
    var AdvData      = require('config_tour/AdvData'),
        gameView     = require('config_tour/fsm/gameView'),
        scenario02   = require('config_tour/fsm/fsm-scenario02');
    
    // ADEN COMPONENTS
    var AdvEngine    = require('adayana/aden/engine'),
        AdvClock     = require('adayana/aden/plugins/advClock'),
        AdvTracker   = require('adayana/aden/plugins/advTracker'),
        AdvReview    = require('adayana/aden/plugins/advReview'),
        StateMachine = require('adayana/aden/internal/advStateMachine'),
        // ADEN PLUGINS
        AdvStatus    = require('modules/plugins/advStatus'),
        AdvRadio     = require('modules/plugins/advRadio'),
        AdvMap       = require('modules/plugins/advMap'),
        AdvMode      = require('modules/plugins/advMode'),
        AdvPlaylist  = require('modules/plugins/advPlaylist'),
        // OTHER MODULES        
        keyboard     = require('modules/keyboard'),
        Templates    = require('adayana/modules/templates'),
        preload      = require('adayana/modules/preloadScreen');
    
    // INITIALIZE PRE-LOADER
    preload.initialize('.preload-display', mediator);
    
    // LOAD ENGINE MODULES
    require('adayana/aden/modules/objectFactory');
    require('adayana/aden/modules/save');
    require('adayana/aden/modules/clock');
    require('adayana/aden/modules/score');
    require('adayana/aden/modules/objects');
    require('adayana/aden/modules/timedEvents');
    require('adayana/aden/modules/layers');
    require('adayana/aden/krpano/krpano');
    
    // LOAD ENGINE OBJECTS
    require('adayana/aden/objects/advPopup');
    require('adayana/aden/objects/advDP');
    require('adayana/aden/objects/advDPMulti');
    require('adayana/aden/objects/advVideo');
    require('adayana/aden/objects/advImage');
    require('adayana/aden/objects/advAudio');
    require('adayana/aden/objects/advNarration');
    
    // INITIALIZE MODULES
    AdvEngine.layers.initialize(mediator);
    AdvEngine.clock.initialize(mediator);
    AdvEngine.score.initialize(mediator);
    AdvEngine.objects.initialize(mediator);
    AdvEngine.factory.initialize(mediator);
    AdvEngine.pano.initialize(mediator);
    
    /**
     * App Module 
     */
    var app = {};
    
    /**
     * Starts the app once the page has loaded 
     */
    app.start = function(){
        preload.setMessage('Starting App');
        
        // initialize god menu tabs
        $('#god-view').html( Templates.getTemplate('files/templates/screens/godmode.html')());
        $('#god-menu').tabs();
        
        // Configure a few things
        detect.checkAll();
        debug.start();
        keyboard.init();
        
        // SET DEPLOYMENT TYPE
        AdvData.settings.engine.isLocal  = detect.isStandalone;
        AdvData.settings.engine.isMobile = detect.isMobile;
        
        // ADD ENGINE PLUGINS
        AdvEngine.plugin.playlist = new AdvPlaylist ( 'playlist', mediator, AdvData.plugins.playlist );
        
        // LOAD FINITE STATE MACHINES
        AdvEngine.fsm.gameView   = new StateMachine( mediator, gameView   );
        AdvEngine.fsm.scenario02 = new StateMachine( mediator, scenario02 );
        
        // START ENGINE
        AdvEngine.start( mediator, AdvData );
    };
    
    /**
     * Resizes the application 
     */
    app.resize = function() {
        AdvEngine.onResize();
    };
    
    return app;
});
