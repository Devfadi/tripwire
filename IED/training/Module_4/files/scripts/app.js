define(function(require){
    // Load (and Execute) Polyfill modules
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
    var AdvData      = require('config/AdvData');

    // ADEN COMPONENTS
    var AdvEngine    = require('adayana/aden/engine'),
        StateMachine = require('adayana/aden/internal/advStateMachine'),
        user         = require('adayana/aden/internal/user');

    // ADEN PLUGINS (plugins allow multiple instances to be created)
    var AdvClock     = require('adayana/aden/plugins/advClock'),
        AdvTracker   = require('adayana/aden/plugins/advTracker'),
        AdvReview    = require('adayana/aden/plugins/advReview'),
        AdvStatus    = require('modules/plugins/advStatus'),
        AdvRadio     = require('modules/plugins/advRadio'),
        AdvPause     = require('modules/plugins/advPause'),
        AdvResources = require('modules/plugins/advResource'),
        AdvMap       = require('modules/plugins/advMap'),
        AdvMode      = require('modules/plugins/advMode');

    // OTHER MODULES
    var keyboard     = require('modules/keyboard'),
        Templates    = require('adayana/modules/templates'),
        preload      = require('adayana/modules/preloadScreen');

    // INITIALIZE PRE-LOADER
    preload.initialize('.preload-display', mediator);

    // LOAD ENGINE MODULES (engine modules can only have one instance)
    require('adayana/aden/modules/objectFactory');
    require('adayana/aden/modules/save');
    require('adayana/aden/modules/clock');
    require('adayana/aden/modules/score');
    require('adayana/aden/modules/objects');
    require('adayana/aden/modules/timedEvents');
    require('adayana/aden/modules/layers');
    require('adayana/aden/modules/variables');
    require('adayana/aden/krpano/krpano');

    // LOAD ENGINE OBJECT CLASSES (engine objects get displayed on screen)
    require('adayana/aden/objects/advPopup');
    require('adayana/aden/objects/advDP');
    require('adayana/aden/objects/advDPMulti');
    require('adayana/aden/objects/advVideo');
    require('adayana/aden/objects/advImage');
    require('adayana/aden/objects/advAudio');
    require('adayana/aden/objects/advNarration');

    // INITIALIZE ENGINE MODULES
    // this sets up modules to respond to events sent on mediator channels
    
    // SCORM
//    AdvEngine.save.initialize(mediator, {
//        autoSave: "auto",
//        enableLMSStorage: true,
//        enableLocalStorage: false,
//        enableCookieStorage: false,
//        priority: [
//            'scorm'
//        ]
//    });
    
    // LOCAL
    AdvEngine.save.initialize(mediator, {
        autoSave: "auto",
        enableLMSStorage: true,
        enableLocalStorage: true,
        enableCookieStorage: false,
        priority: [
            'scorm',
            'local'
        ]
    });
    
    AdvEngine.layers.initialize(mediator);
    AdvEngine.clock.initialize(mediator);
    AdvEngine.score.initialize(mediator);
    AdvEngine.objects.initialize(mediator);
    AdvEngine.factory.initialize(mediator);
    AdvEngine.pano.initialize(mediator);
    AdvEngine.variables.initialize(mediator);

    /**
     * App Module
     */
    var app = {};

    /**
     * Starts the app once the page has loaded
     */
    app.start = function(){
        preload.setMessage('Starting App');
        
        // god menu tab(s)
        $('#god-view').html( Templates.getTemplate('files/templates/screens/godmode.html')());
        $('#god-menu').tabs();
		
        $('#trigger-save-clear').click(function(){
            $.jStorage.flush();
            window.location.reload();
        });
        
		$('#trigger-set-complete').click(function(){
            aden.variables.get("scenario01_complete").set(true);
            aden.variables.get("scenario02_complete").set(true);
            aden.variables.get("scenario03_complete").set(true);
            aden.variables.get("scenario04_complete").set(true);
            aden.variables.get("scenario05_complete").set(true);
            aden.variables.get("scenario06_complete").set(true);
            aden.variables.get("scenario07_complete").set(true);
            aden.variables.get("scenario08_complete").set(true);
            aden.variables.get("scenario09_complete").set(true);
            
            aden.variables.get("scenario01_attempted").set(true);
            aden.variables.get("scenario02_attempted").set(true);
            aden.variables.get("scenario03_attempted").set(true);
            aden.variables.get("scenario04_attempted").set(true);
            aden.variables.get("scenario05_attempted").set(true);
            aden.variables.get("scenario06_attempted").set(true);
            aden.variables.get("scenario07_attempted").set(true);
            aden.variables.get("scenario08_attempted").set(true);
            aden.variables.get("scenario09_attempted").set(true);
            
            aden.save.setState();
            window.location.reload();
        });
        
		$('#trigger-get-view').click(function(){
			aden.pano.camera.getView();
		});
        
		$("#trigger-video-pause").click(function(){
			aden.mediator.publish('msg:engine:pause');
		});
        
		$("#trigger-video-resume").click(function(){
			aden.mediator.publish('msg:engine:resume');
		});
        
		// start our extra modules/code
        detect.checkAll();
        debug.start();
        keyboard.init();

        // SET DEPLOYMENT TYPE
        // FUTURE - engine auto detects these?
        AdvData.settings.engine.isLocal  = detect.isStandalone;
        AdvData.settings.engine.isMobile = detect.isMobile;

        // ADD ENGINE PLUGIN INSTANCES
        new AdvStatus    ( "status",    mediator, AdvData.plugins.status  );
        new AdvRadio     ( "radio",     mediator, AdvData.plugins.radio   );
        new AdvTracker   ( "tracker",   mediator, AdvData.plugins.tracker );
        new AdvReview    ( "review",    mediator, AdvData.plugins.review  );
        new AdvMap       ( "map",       mediator, AdvData.plugins.map     );
        new AdvMode      ( "mode",      mediator, {} );
        new AdvPause     ( "pause",     mediator, {} );
        new AdvResources ( "resources", mediator, {} );
        
        // LOAD FINITE STATE MACHINES (and their config data)
        new StateMachine( mediator, require('config/fsm/gameState')      );
        new StateMachine( mediator, require('config/fsm/gameView')       );
        new StateMachine( mediator, require('config/fsm/fsm-scenario01') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario02') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario03') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario04') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario05') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario06') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario07') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario08') );
        new StateMachine( mediator, require('config/fsm/fsm-scenario09') );
        
        // GUI SETUP
        $("#video-spinner").show().position({
            "my" : "center",
            "at" : "center",
            "of" : "#viewport"
        }).hide();

        // START ENGINE
        // Everything is loaded, start the engine and it will self-initialize.
        AdvEngine.start( mediator, AdvData );
    };

    /**
     * Resizes the application
     */
    app.resize = function() {
        AdvEngine.onResize();
//        $("#spinner-content").position({
//            "my": "center",
//            "at": "center",
//            "of": "#spinner"
//        });
        $("#video-spinner").show().position({
            "my" : "center",
            "at" : "center",
            "of" : "#viewport"
        }).hide();
    };

    return app;
});
