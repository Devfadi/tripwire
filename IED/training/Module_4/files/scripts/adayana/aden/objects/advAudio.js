define(function(require){
    
    require('jplayer');
    
    var $         = require('jquery'),
        _         = require('lodash'),
        aden      = require('adayana/aden/engine'),
        detect    = require('adayana/utilities/detect'),
        Templates = require('adayana/modules/templates'),
        parseUri  = require('adayana/utilities/parseUri'),
        AdvObject = require('./advObject');
    
	require('adayana/aden/modules/objectFactory');
	
    var defaults = {
        "path"         : "",
        "template"     : "",
        "onShow"       : "audio-show",
        "onHide"       : "audio-hide",
        "onStart"      : "audio-start",
        "onDestroy"    : "audio-destroy",
        "onActivate"   : "audio-activate",
        "onDeactivate" : "audio-deactivate",
        "onAudioStart" : "audio-start",
        
        "onAudioReady" : "audio-ready",
        "onAudioPlay"  : "audio-play",
        "onAudioEnd"   : "audio-end"
    };
    
    var defaultData = {
        loop            : false
    };
    
    //TODO - reimplement timed events during video playback.
    // Note - this will not work on iPhone devices as videos play in full-size player
    
    var AdvAudio = AdvObject.extend(
    /** @lends AdvAudio */        
    {   
        currTime: null,
        prevTime: null,
         
        /**
         * Initializes a the Node
         * @class
         * @augments Class
         * @constructs
         */
        init: function( mediator, data, options ) {
            data = $.extend(true,{},defaultData,data);
            debug.info('creating an instance of AdvAudio');
            this._super(mediator,data,options);
            this.settings = $.extend(true,{},defaults,options);
            this.template = Templates.getTemplate(this.settings.source);
            this.eventNamespace = '.AdvAudio';
            this.mediator.publish('msg:object:init');
        },
        
        destroy: function() {
            if ( this.isDestroyed ) {return;}
            this.mediator.publish('msg:object:destroy');
            if ( this.el ) {
                if ( this.player ) {
                    this.player.jPlayer("destroy");
                    this.player = null;
                }
                this.el.remove();
                delete this.el;
            }            
            this._super();
            this.settings = null;
            this.template = null;
            this.mediator = null;
        },
        
        /**
         * Subscribe to mediator channels 
         */
        subscribe: function() {
            //this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
            this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
            this.mediator.subscribe('msg:engine:pause',  this.onPause,  null, this);
            this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
        },
        
        /**
         * Unsubscribe from mediator channels 
         */
        unsubscribe: function() {
            //this.mediator.remove('msg:engine:update', this.onUpdate);
            this.mediator.remove('msg:engine:resize', this.onResize);
            this.mediator.remove('msg:engine:pause',  this.onPause);
            this.mediator.remove('msg:engine:resume', this.onResume);
        },

        /**
         * Updates Node
         */
        onUpdate : function() {
            if (this.isActive) {
                //this.prevTime = this.currTime;
                //this.currTime = this.player.jPlayer().data('jPlayer').status.currentTime * 1000;
                //this.triggerTimedAction();
            }
        },

        /**
         * Resizes stuff when display area size changes.
         */
        onResize : function() {
            if (this.isActive || this.isVisible) {
                // resize stuff
            }
        },

        /**
         * Pauses stuff
         */
        onPause : function() {
            if (this.isActive) {
                this.pause();
            }
        },

        /**
         * Resumes stuff
         */
        onResume : function() {
            if (this.isActive) {
                this.play();
            }
        },
        
        /**
         * Reloads Object
         */
        reload : function() {},

        /**
         * Starts Object
         */
        start : function() {
            this._super();
            this.el = $(this.template(this.data)).appendTo(aden.el);
            this.hasPlayed = false;
            var self = this;
            
            var mp3_file = this.data.file;
            
            this.control = this.el.find('.jp-audio');
            this.control.attr('id', this.data.id + "_controls");
            this.player = this.el.find('.jp-jplayer');
            
            var sourceString = "flash,html";
            if ( detect.isStandalone ) {
                sourceString = "html,flash";
            }
            
            this.player.jPlayer({
                ready    : function () {
                    self.handleEvent('onAudioReady');
                    // determine the root directory
                    var uri  = parseUri(window.location);
                    var root = "";
                    if ( !detect.isStandalone ) {
                        root = "http://" + uri.authority + uri.directory;
                    }
                    // set the media file
                    $(this).jPlayer("setMedia", {
                        mp3 : root + mp3_file
                    }).jPlayer('play'); // attempt auto play
                },
                play: function(){
                    self.handleEvent('onAudioPlay');
                    if(!self.hasPlayed) {
                        //$('#skipBtn').show();
                        self.hasPlayed = true;
                    }
                },
                solution : sourceString,
                swfPath  : "files/Jplayer.swf",
                supplied : "mp3",
                wmode    : "window",
                preload  : "auto",
                loop     : this.data.loop,
                cssSelectorAncestor : '#' + this.data.id + "_controls"
            })
            .on($.jPlayer.event.ended, $.proxy(self.onEnd, self));
            //.on($.jPlayer.event.play, function(){ $('.jp-audio').hide(); });
        },

        /**
         * Method called when video has finished. Hides video player dom object and sets advNode as complete.
         */
        onEnd: function() {           
            //$('#skipBtn').hide();
            this.handleEvent('onAudioEnd');
            this.hide();
            this.destroy();
        },
        
        /**
         * Activate the object
         */
        activate : function() {
            this._super();
        },

        /**
         * Deactivate the object
         */
        deactivate : function() {
            this._super();
        },

        /**
         * Skips stuff
         */
        skip : function() {
            if ( this.isActive && this.player ) {
                debug.log('skipping from: ' + (this.currTime/1000) + ' seconds');
                // var skipTime = -1,
                    // skipBranch;
                // if ( 'timedEvents' in this.data ) {
                    // _.forEach( this.data.timedEvents, function( data ) {
                        // var ms = _S.parseTime( data.timeStart ) * 1000;
                        // if ( this.currTime < ms && !data.skipped && ( ms < skipTime || skipTime === -1 )) {
                            // skipBranch = data;
                            // skipTime = ms;
                        // }
                    // },this);
                // }
                
                // if ( skipBranch ) {
                    // skipBranch.skipped = true;
                    // // I've read some circumstantial information online that html5 seeks to the first decimal place.
                    // // this should help make sure that if we have a number like 1.1999, we skip to 1.1 not 1.2 seconds.
                    // var seekTime = Math.floor(skipTime / 1000) + Math.floor(((skipTime / 1000) - Number(Math.floor(skipTime / 1000)))*10)/10;
                    // this.player.jPlayer("play", seekTime );
                    // debug.log('skipping to: ' + ( skipTime / 1000 ) + ' seconds');
                // } else {
                    this.player.jPlayer("stop");
                    this.onEnd();
                    debug.log('skipping to end');
                // }
            }
        },
        
        pause: function(){
            if ( this.isActive && this.player ) {
                this.player.jPlayer("pause");
            }    
        },
        
        play: function(){
            if ( this.isActive && this.player ) {
                this.player.jPlayer('play');
            }
        },
        
        /**
         * Positions node
         */
        position : function() {},
        
        /**
         * Closes the video 
         */
        close: function() {
            this.destroy();
        }
    });
    
    AdvAudio.prototype.type = 'audio';
    aden.factory.addType(AdvAudio);
    
    return AdvAudio;
    
});
