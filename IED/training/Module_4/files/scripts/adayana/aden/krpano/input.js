define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        MathUtil = require('adayana/utilities/math'),
        debug    = require('adayana/debug/debug');
        
    var input = {
        
        init: function( pano ) {
            this.pano = pano;
        },
        
        onLoad: function(){
            
        },
        
        enable: function(){
            this.pano.krpano.set('control.mousespeed', 10);
            this.pano.krpano.set('control.keybspeed', 10);
            this.pano.krpano.set('control.fovspeed', 3);
        },
        
        disable: function(){
            this.pano.krpano.set('control.mousespeed', 0);
            this.pano.krpano.set('control.keybspeed', 0);
            this.pano.krpano.set('control.fovspeed', 0);
        }
    };
    
    return input;
});
