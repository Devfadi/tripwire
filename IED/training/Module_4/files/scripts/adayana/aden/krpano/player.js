define(function(require){
    
    var $        = require('jquery'),
        _        = require('lodash'),
        MathUtil = require('adayana/utilities/math'),
        debug    = require('adayana/debug/debug');
        
    var Player = {
        allowForwardMovement: false,
        allowBackwardMovement: false,
        
        init: function( parent ) {
            this.pano = parent;
        },
        onPanoLoad: function(){
            
        },
        go: function( direction ) {
            switch ( direction ) {
                case "right"   : this.goRight(); break;
                case "left"    : this.goLeft(); break;
                case "forward" : this.goForward(); break;
                case "back"    : this.goBack(); break;
            }
        },
        goRight: function(){
            this.turnTo( this.getNextTarget('right'), 'right' );
        },
        goLeft: function(){
            this.turnTo( this.getNextTarget('left'), 'left' );
        },
        goForward: function(){
            if ( this.allowForwardMovement ) {
                //TODO - implement method to find closest forward nav point
                var targetScene = "";
                this.pano.load( targetScene );
            }
        },
        goBack: function(){
            if ( this.allowBackwardMovement ) {
                //TODO - implement? - go back to previous node? go to node behind you?
            }
        },
        turnTo: function( name ) {
            this.pano.hotspots.turnTo( name );
        },
        turn: function( direction, magnitude ) {
            
        }
    };
    
    return Player;
});
