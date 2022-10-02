define(function(require){
    // dependencies:
    var $         = require('jquery'),
        _         = require('lodash'),
        AdvPlugin = require('./advPlugin');
        
    var AdvOverlay = AdvPlugin.extend(
    /** @lends AdvOverlay.prototype */        
    {
        init: function( name, mediator, data ) {
            this._super(name,mediator,data);
        }
    });
    
    return AdvOverlay;
});
