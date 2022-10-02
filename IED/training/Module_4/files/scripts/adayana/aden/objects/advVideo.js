define(function (require) {
	'use strict';

	require('jplayer');

	var $ = require('jquery'),
		_ = require('lodash'),
		_S = require('adayana/utilities/string'),
		aden = require('adayana/aden/engine'),
		detect = require('adayana/utilities/detect'),
		Templates = require('adayana/modules/templates'),
		parseUri = require('adayana/utilities/parseUri'),
		AdvObject = require('./advObject');
	
	require('adayana/aden/modules/objectFactory');
	
	var defaults = {
		"path": "",
		"template": "",
		"onShow": "video-show",
		"onHide": "video-hide",
		"onStart": "video-start",
		"onDestroy": "video-destroy",
		"onActivate": "video-activate",
		"onDeactivate": "video-deactivate",
		"onVideoStart": "video-start",
		"onVideoEnd": "video-end"
	};

	var defaultData = {
		loop: false,
		stopOnLastFrame: false,
		showControls: false,
		keepVisible: false,
		keepActive: false,
		stopClock: true
	};

	//TODO - re-implement timed events during video playback.
	// Note - this will not work on iPhone devices as videos play in full-size player

	var AdvVideo = AdvObject.extend({
		currTime: null,
		prevTime: null,
		maxTime: null,

		hasTimedActions: false,

		/**
		 * Initializes a the Node
		 * @class
		 * @augments Class
		 * @constructs
		 */
		init: function (mediator, data, options) {
			data = $.extend(true, {}, defaultData, data);
			debug.info('creating an instance of AdvVideo');
			this._super(mediator, data, options);
			this.settings = $.extend(true, {}, defaults, options);
			this.template = Templates.getTemplate(this.settings.template);
			this.eventNamespace = '.advVideo';
			this.mediator.publish('msg:object:init');
			this.hasTimedActions = false;
		},

		/**
		 * Destroy the video object
		 */
		destroy: function () {
			if (this.isDestroyed) {
				return;
			}
			$("#video-spinner").hide();
			aden.layers.remove(this.id);
			this.mediator.publish('msg:object:destroy');
			if (this.el) {
				if (this.player) {
					this.player.jPlayer("destroy");
					this.player = null;
				}
				this.el.remove();
				delete this.el;
			}
			this._super();
			this.settings = null;
			this.playerTemplate = null;
			this.videoTemplate = null;
			this.controlTemplate = null;
			this.mediator = null;
		},

		/**
		 * Subscribe to mediator channels
		 */
		subscribe: function () {
			this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
			this.mediator.subscribe('msg:engine:resize', this.onResize, null, this);
			this.mediator.subscribe('msg:engine:pause', this.onPause, null, this);
			this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
		},

		/**
		 * Unsubscribe from mediator channels
		 */
		unsubscribe: function () {
			this.mediator.remove('msg:engine:update', this.onUpdate);
			this.mediator.remove('msg:engine:resize', this.onResize);
			this.mediator.remove('msg:engine:pause', this.onPause);
			this.mediator.remove('msg:engine:resume', this.onResume);
		},

		/**
		 * Updates Node
		 */
		onUpdate: function () {
			if (this.isActive) {
				this.prevTime = this.currTime;
				this.currTime = this.player.jPlayer().data('jPlayer').status.currentTime;
				if (this.currTime > this.maxTime) {
					this.maxTime = this.currTime;
				}
				if (this.hasTimedActions) {
					this.triggerTimedAction();
				}
			}
		},

		/**
		 * Resizes stuff when display area size changes.
		 */
		onResize: function () {
			if (this.isActive || this.isVisible) {
				this.resize();
			}
		},

		/**
		 * Pauses stuff
		 */
		onPause: function () {
			if (this.isActive) {
				this.pause();
			}
		},

		/**
		 * Resumes stuff
		 */
		onResume: function () {
			if (this.isActive) {
				this.play();
			}
		},

		/**
		 * Reloads Object
		 */
		reload: function () {},

		/**
		 * Starts Object
		 */
		start: function () {
			this._super();
			this.el = $(this.template(this.data)).appendTo(aden.el);
			if ((('addBackground' in this.settings) && this.settings.addBackground === true) || !('addBackground' in this.settings)) {
				this.el.addClass('black-bg');
			}
			
			this.player = this.el.find('.jp-jplayer');
			this.control = this.el.find('.jp-gui');
			this.hasPlayed = false;
			this.currTime = 0;
			this.maxTime = 0;
			
			// determine jPlayer source string to use
			var sourceString = "flash,html";
            
//			if (detect.isStandalone) {
//				sourceString = "html,flash";
//			} else if (detect.isMobile) {
//				sourceString = "html";
//			}

			$("#video-spinner").show();

			var self = this;
			var videoSelector = "#video-" + this.id;
			var winWidth = aden.width;
			var winHeight = aden.height;
			
			var sourceString = "flash,html";
            if ( detect.isStandalone ) {
                sourceString = "html,flash";
            }
			
			this.player.jPlayer({
				ready: function () {
					// Fix - if on a server, get absolute path:
					var root = "";
					if (!detect.isStandalone) {
						var uri = parseUri(window.location);
						root = "http://" + uri.host + uri.directory;
					}

					$(videoSelector).find('img').show();
					//$('#video-spinner').hide();

					var media = {};
					_.forEach(self.data.media, function (value, key) {
						media[key] = root + value;
					});

					debug.log('playing video');
					$(this).jPlayer("setMedia", media);
					// attempt auto play, except on mobile devices
					if (!detect.isMobile) {
						$(this).jPlayer('play');
					}
				},
				play: function () {
					$(videoSelector).find('img').hide();
					$("#video-spinner").hide();
					if (!self.hasPlayed) {
						//$('#skipBtn').show();
						self.hasPlayed = true;
						self.handleEvent('onVideoStart');
					}
				},
				flashreset: function () {
					debug.log('jplayer flashreset');
				},
				resize: function () {
					debug.log('jplayer resize');
				},
				loadstart: function () {
					//$(videoSelector).find('img').show();
					debug.log('jplayer loadStart');
				},
				progress: function () {
					debug.log('jplayer progress');
				},
				suspend: function () {
					debug.log('jplayer suspend');
				},
				loadedmetadata: function () {
					debug.log('jplayer loadedmetadata');
				},
				loadeddata: function () {
					debug.log('jplayer loadeddata');
				},
				waiting: function () {
					debug.log('jplayer waiting');
				},
				playing: function () {
					debug.log('jplayer playing');
				},
				canplay: function () {
					debug.log('jplayer canplay');
				},
				// needs to have the jplayer swf on the same directory as index.html 
				// otherwise relative paths for mp4 files won't work properly
				swfPath: "files/Jplayer.swf",
				backgroundColor: "transparent",
				solution: sourceString,
				wmode: "transparent",
				preload: "auto",
				loop: this.data.loop,
				supplied: "m4v,poster",
				cssSelectorAncestor: '#video-' + this.data.id + "-control",
				size: {
					width: winWidth + 'px',
					height: winHeight + 'px'
				}
			});

			$('.jp-video-play-icon').click(function () {
				$("#video-spinner").show();
				$(videoSelector).find('img').show();
			});

			// bind video end event
			this.player.bind($.jPlayer.event.ended + this.eventNamespace, function (event) {
				if (self.data.stopOnLastFrame) {
					self.player.jPlayer('pause', 100);
				}
				self.onVideoEnd();
			});

			aden.layers.add(this.id);
			aden.layers.sendBelow(this.id, 'menu-bg');
		},

		/**
		 * Method called when video has finished. Hides video player dom object and sets advNode as complete.
		 */
		onVideoEnd: function () {
			//$('#skipBtn').hide();
			this.handleEvent('onVideoEnd');
			this.hide();
			this.destroy();
		},

		/**
		 * Activate the object
		 */
		activate: function () {
			this._super();
		},

		/**
		 * Deactivate the object
		 */
		deactivate: function () {
			this._super();
		},

		/**
		 * Skips stuff
		 */
		skip: function () {
			$("#video-spinner").hide();
			if (this.isActive && this.player) {
				// TODO - reimplement skipping to next timed event
				
				debug.log('skipping from: ' + (this.currTime) + ' seconds');
				this.player.jPlayer("stop");
				this.onVideoEnd();
				$("#video-spinner").hide();
				debug.log('skipping to end');
			}
		},

		pause: function () {
			if (this.isActive && this.player) {
				this.player.jPlayer("pause");
			}
		},

		play: function () {
			if (this.isActive && this.player) {
				this.player.jPlayer('play');
			}
		},

		resize: function () {
			var winWidth = aden.width;
			var winHeight = aden.height;
			if (this.player) {
				this.player.jPlayer({
					size: {
						width: winWidth + 'px',
						height: winHeight + 'px'
					}
				});
			}
		},


		/**
		 * Positions node
		 */
		position: function () {},

		/**
		 * Closes the video
		 */
		close: function () {
			this.destroy();
		},

		/*
		[{ 
			start: "", 
			end: "", 
			onStart: function(){},
			onSkipStart: function(){},
			onEnd: function() {},
			onSkipEnd: function(){}
		}]
		*/

		setTimedActions: function (actions) {
			this.timedActions = actions;
			this.hasTimedActions = true;
			this.timingIndex = 0;
			_.forEach(this.timedActions, function (action) {
				if (action) {
					if (action.start && _.isString(action.start)) {
						action.start = _S.parseTime(action.start);
					}
					if (action.stop && _.isString(action.stop)) {
						action.stop = _S.parseTime(action.stop);
					}
				}
			});
		},

		skipTimedActions: function () {
			var skipTime = 0,
				skipBranch;

			if ('timedEvents' in this.data) {
				_.forEach(this.data.timedEvents, function (data) {
					var ms = _S.parseTime(data.timeStart);
					if (this.currTime < ms && !data.skipped && (ms < skipTime || skipTime === -1)) {
						skipBranch = data;
						skipTime = ms;
					}
				}, this);
			}
		},

		triggerTimedAction: function () {
			// when the time has advanced and is at or beyond the furthest point in time reached.
			if (this.currTime > this.prevTime && this.currTime >= this.maxTime) {
				
				_.forEach(this.timedActions,function(action) {
					
					// when this action begins either at the current time or between the previous and current time
					if (this.prevTime < action.start && this.currTime >= action.start) {
						if (action.onStart && _.isFunction(action.onStart)) {
							action.onStart();
						}
						this.timingIndex = i + 1;
					}
					
					// when this action occurs further into the future, stop checking actions.
					if (action.time > this.currTime) {
						return false;
					}
					
					// TODO - implement stop time
					// TODO - implement going through timed events backwards
					// TODO - implement skipping past timed events both ways
					
				}, this);
			}
		}
	});

	AdvVideo.prototype.type = 'video';
	aden.factory.addType(AdvVideo);

	return AdvVideo;

});