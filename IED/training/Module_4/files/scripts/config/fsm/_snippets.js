var temp = [
            // popup with image
            {
                id: "start",
                object: "",
                onEnter: function(){
                    currScreen = aden.objects.load('');
                    aden.pano.hotspots.hideAll();
                },
                onExit: function(){
                    if ( currScreen ) {
                        currScreen.destroy();                        
                    }
                },
                branches: [
                    { id: "popup-destroy", target: "" }
                ]
            },
            
            // Dispatcher Sequencing
            {
                id: "dispatch",
                onEnter: function(){
                    aden.plugin.mode.setMode('static');
                    setupRadioCall( null, 's09-dispatch-call-audio', 's09-dispatch-call-text');
                },
                onExit: clearRadioCall,
                branches: [
                    { id: "audio-end", target: "dispatch-reply" }
                ]
            },
            {
                id: "dispatch-reply",
                onEnter: function(){
                    currPopup = aden.objects.load('s09-dispatch-response');
                    setupRadioReply(TIME_SHORT_YEL, TIME_SHORT_RED, TIME_SHORT_END);
                },
                onExit: function(){
                    if ( currPopup ) {
                        currPopup.destroy();
                    }
                    clearRadioReply();
                },
                branches: [
                    { id: "ignore",      target: "dispatch-warning" },
                    { id: "radio-click", target: "dispatch-response" }
                ]
            },
            {
                id: "dispatch-warning",
                onEnter: function(){
                    currPopup = aden.objects.load('s09-dispatch-warning');
                    aden.plugin.radio.addGlow();
                    aden.plugin.radio.activate();
                },
                onExit: function(){
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
                onEnter: function(){
                    aden.plugin.radio.addGlow();
                    currPopup = aden.objects.load('s09-dispatch-reply-text');
                    currAudio = aden.objects.load('s09-dispatch-reply-audio');
                },
                onExit: function(){
                    if (currPopup) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                },
                branches: [
                    { id: "audio-end", target: "" }
                ]
            },
            
            // Movement
            {
                id: "wait-move",
                onEnter: function(){
                    aden.plugin.mode.setMode('pano');
                    aden.pano.hotspots.showAll();
                    setupTimedObj('','');
                },
                onExit: function(){
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "move-van", target: "investigate-van" },
                ]
            },
            
            {
                id: "dp09-intro",
                object: "s08-dp09-intro",
                branches: [
                    { id: "popup-destroy", target: "dp09" }
                ]
            },
    
            // Timed Intro
            {
                id: "dp09-intro",
                onEnter: function(){
                    aden.plugin.status.set('green');
                    currPopup = aden.objects.load('s09-dp09-intro');
                    aden.plugin.status.add(WAIT_TIME, function(){ 
                        aden.fsm.scenario06.trigger('timeup'); 
                    });
                    aden.plugin.status.setTime(WAIT_TIME);
                },
                onExit: function(){
                   if (currPopup) {
                       currPopup.destroy();
                   }
                   aden.plugin.status.clear();
                },
                branches: [
                    { id: 'skip',   target: 'dp09' },
                    { id: 'timeup', target: 'dp09' }
                ]
            },
            
            // Audio Intro
            {
                id: "dp09-intro",
                onEnter: function(){
                    aden.plugin.radio.addGlow();
                    currAudio = aden.objects.load('s09-dp09-intro-audio');
                    currPopup = aden.objects.load('s09-dp09-intro-text');
                },
                onExit: function(){
                    if ( currPopup ) {
                        currPopup.destroy();
                    }
                    aden.plugin.radio.removeGlow();
                    if ( currAudio ) {
                        currAudio.destroy();
                    }
                },
                branches: [
                    { id: "audio-end", target: "dp09" }
                ]
            },
            
            // Decision Point
            {
                id: "dp09",
                onEnter: function(){
                    if ( currScreen ) { 
                        currScreen.destroy(); 
                    }
                    aden.plugin.mode.setMode('pano');
                    setupTimedObj('s09-dp09','s09-dp09-warning');
                },
                onExit: function(){
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
                object: 's09-dp09-r01',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r2',
                object: 's09-dp09-r02',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r3',
                object: 's09-dp09-r03',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r4',
                object: 's09-dp09-r04',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r5',
                object: 's09-dp09-r05',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r6',
                object: 's09-dp09-r06',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            
            
            // DP Multi
            
            {
                id: "dp09",
                onEnter: function(){
                    aden.plugin.mode.setMode('pano');
                    setupTimedObj('s09-dp09','s09-dp09-warning');
                },
                onExit: function(){
                    aden.plugin.status.clear();
                },
                branches: [
                    { id: "dp-correct", target: "dp09-r1" },
                    { id: "dp-wrong",   target: "dp09-r2" }
                ]
            },
            {
                id: 'dp09-r1',
                object: 's09-dp09-r01',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            {
                id: 'dp09-r2',
                object: 's09-dp09-r02',
                branches: [
                    { id: "popup-destroy", target: "dp10" }
                ]
            },
            
];