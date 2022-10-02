define(function(require){
    var $ = require('jquery'),
        _ = require('lodash'),
        fullscreen = require('adayana/modules/fullscreen'),
        debug = require('adayana/debug/debug');
    
    var pauseEnabled = true;
    
    var keyboard = {};
    
    var state = {};
    
    /**
     * Initialize the scenario's main GUI functionality
     */
    keyboard.init = function () {
        $(document).keyup($.proxy(onKeyUp, this));
        $(document).keydown($.proxy(onKeyDown, this));
        
        //$(document).click(function(){console.log('mouseclick')});
        //$(document).mouseup(function(){console.log('mouseup')});
        
        $(document).mousedown(function(){
            //console.log('mousedown');
            if (aden && aden.pano && aden.pano.krpano) {
                aden.pano.krpano.set("hlookat_moveforce", 0);
                aden.pano.krpano.set("vlookat_moveforce", 0);
            }
        });
        
        function addEvent(obj, evt, fn) {
            if (obj.addEventListener) {
                obj.addEventListener(evt, fn, false);
            } else if (obj.attachEvent) {
                obj.attachEvent("on" + evt, fn);
            }
        }
        
        addEvent(document, "mouseout", function (e) {
            e = e ? e : window.event;
            var from = e.relatedTarget || e.toElement;
            if (!from || from.nodeName == "HTML") {
                //console.log('mouseout');
                if (aden && aden.pano && aden.pano.krpano) {
                    aden.pano.krpano.set("hlookat_moveforce", 0);
                    aden.pano.krpano.set("vlookat_moveforce", 0);
                }
            }
        });
    };
    
    /**
     * process keyboard events
     */
    function onKeyUp(e) {
        var code = (e.keyCode ? e.keyCode : e.which);
        
        // if key is down, set to up; otherwise exit.
        if ( state[code] === true ) {
            state[code] = false;
        } else {
            return;
        }
        
        console.log(code + ' up');
        
        switch( code ) {
            /* TAB */   //case 9   : break;
            /* esc */   //case 27  : break;    
            /* space */ //case 32  : skipStuff(); break;
            /* right */ case 37  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("hlookat_moveforce",0); break;
            /* up */    case 38  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("vlookat_moveforce",0); break;
            /* left */  case 39  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("hlookat_moveforce",0); break;
            /* down */  case 40  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("vlookat_moveforce",0); break;
            /* 1 */     //case 49  : toggleGodView(); break;
            /* f */     case 70  : toggleFullscreen(); break;
            /* m */     case 77  : break;
            /* p */     case 80  : aden.fsm.gameState.trigger('toggle-pause'); break;
            /* q */     //case 81  : skipStuff(); break;
            /* ~ */     case 192 : debug.toggle(); break;
        }
    }
    
    function onKeyDown(e) {
        var code = (e.keyCode ? e.keyCode : e.which);
        
        // if key is down, exit; otherwise set to down.
        if ( state[code] === true ) {
            return;
        } else {
            state[code] = true;
        }
        
        console.log(code + ' down');
        
        switch( code ) {
            /* right */ case 37  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("hlookat_moveforce",-1); break;
            /* up */    case 38  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("vlookat_moveforce",-1); break;
            /* left */  case 39  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("hlookat_moveforce",1); break;
            /* down */  case 40  : if (aden && aden.pano && aden.pano.krpano) aden.pano.krpano.set("vlookat_moveforce",1); break;
        }
    }
    
    function skipStuff() {
        aden.objects.skip();
        _.forEach( aden.fsm, function( fsm ) {
            fsm.trigger('skip');
        });
    }
    function toggleFullscreen(){
        fullscreen.toggle();
    }
    function toggleGodView(){
        $('#god-view').toggle();
    }
   
    return keyboard;
    
});