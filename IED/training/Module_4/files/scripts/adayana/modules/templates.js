define(function (require) {
    'use strict';
    
    var $ = require('jquery'),
        _ = require('lodash'),
        Handlebars = require('handlebars'),
        JST = require('templates');

    var Templates = {};
    
    function getContent(url) {
        return $.ajax({
            type: "GET",
            async: false,
            url: url,
            dataType: "html",
            success: function (data) {},
            error: function (e) {
                alert('The content you requested could not be found. The URL may be incorrect. If you are running this site locally, this functionality may not work correctly.');
            }
        }).responseText;
    }
    
    // Add a Helper to Handlebars to output the toLowerCase version of a string
    Handlebars.registerHelper('toLowerCase', function (str) {
        return str.toLowerCase();
    });

    /**
     * Retrieves the template source through AJAX and caches it. If the source
     * has previously been cached, the cached version is used instead. Useful
     * for pre-cacheing common templates prior to use. Also used internally.
     * @param {Object} path
     */
    Templates.getTemplate = function (path) {
        if (_.has(JST, path)) {
            return JST[path];
        } else {
            var source = getContent(path);
            var template = Handlebars.compile(source);
            JST[path] = template;
            return template;
        }
    };

    /**
     * Retrieves the template source from the provided url path and generates
     * html code from the compiled template.
     * @param {Object} path - location of the template source
     * @param {Object} data - data object to pass into the template generator
     */
    Templates.generate = function (path, data) {
        var template = Templates.getTemplate(path);
        if (template) {
            return template(data);
        } else {
            return null;
        }
    };

    /**
     * Retrieves the partial template source and subsequently registers
     * the partial template with Handlebars.
     * @param {Object} name
     * @param {Object} url
     */
    Templates.registerPartial = function (name, url) {
        var source = getContent(url);
        if (source) {
            Handlebars.registerPartial(name, source);
        }
    };

    return Templates;

});