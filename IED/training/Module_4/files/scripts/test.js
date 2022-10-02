require.config({
    baseUrl: 'files/scripts/',
    paths: {
        'jquery'        : 'vendor/jquery/jquery-1.10.2',
        'jqueryui'      : 'vendor/jquery/jquery-ui-1.10.4.custom',
        'lodash'        : 'vendor/lodash/lodash.compat',
        'handlebars'    : 'vendor/handlebars/handlebars',
        'mediator-js'   : 'vendor/mediator'
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
        jqueryui : ['jquery']
    }
});

require(['jquery', 'adayana/aden/engine'], 
function( $, aden ) {
    'use strict';
    console.log('Initializing Shared Reality Application');
    console.log('Running jQuery %s', $().jquery);
    console.log('Waiting for document ready');
    $(document).ready(function(){
        console.log('Document ready - starting application.');
    });
}); 

