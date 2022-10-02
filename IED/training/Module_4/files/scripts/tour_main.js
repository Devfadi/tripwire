/**
 * @fileOverview main.js houses the RequireJS configuration options as well as the
 * main module. The main module is the launch point for all code.  
 * @history 2014-06-10 VRB - Initial Version
 */
require.config({
    baseUrl: 'files/scripts/',
    paths: {
        'jquery'        : 'vendor/jquery/jquery-1.10.2',
        'jqueryui'      : 'vendor/jquery/jquery-ui-1.11.0',
        'lodash'        : 'vendor/lodash/lodash.compat',
        'handlebars'    : 'vendor/handlebars/handlebars',
        'mediator-js'   : 'vendor/mediator',
        'registry'      : 'adayana/registry',
        'jplayer'       : 'vendor/jplayer/jquery.jplayer.min'
    },
    shim: {
        handlebars : {
            deps: ['jquery'],
            exports: 'Handlebars'
        },
        lodash : {
            exports: '_'
        },
        jquery : {
            exports: 'jQuery'
        },
        jqueryui : ['jquery'],
        jplayer  : ['jquery']
    }
});

requirejs.onError = function (err) {
    console.log(err.requireType);
    if (err.requireType === 'timeout') {
        console.log('modules: ' + err.requireModules);
    }
    throw err;
};

require(['jquery','tour_app', 'jqueryui', 'adayana/polyfills/console','adayana/aden/engine' ], 
function( $, app ) {
    'use strict';
    console.log('Initializing Shared Reality Application');
    console.log('Running jQuery %s', $().jquery);
    console.log('Waiting for document ready');
    
    // Start app once the document is ready
    $(document).ready(function(){
        console.log('Document ready - starting application.');
        app.start();
    });
    
    // Resize app when the window resizes
    $(window).on('resize',function( event ){
        if ( event.target === event.currentTarget ) {
            app.resize();
        }
    });
}); 

