define(function (require) {
    // dependencies:
    var $ = require('jquery'),
        _ = require('lodash'),
        aden = require('adayana/aden/engine'),
        Templates = require('adayana/modules/templates'),
        AdvPlugin = require('adayana/aden/plugins/advPlugin');

    var events = [];

    var AdvPause = AdvPlugin.extend({
        
        init: function (name, mediator, data) {
            this._super(name, mediator, data);
            this.onPauseClick = $.proxy(this.onPauseClick, this);
        },

        onInit: function (instance) {
            this.el = $('<div id="pause-icon" class="layer"></div>');
            this.el.appendTo(aden.el);
            this.el.on('click', this.onPauseClick);
            debug.info('Pause module is ready');
        },

        onPauseClick: function () {
            if (this.isActive) {
                aden.fsm.gameState.trigger('toggle-pause');
            }
        }
    });

    return AdvPause;
});