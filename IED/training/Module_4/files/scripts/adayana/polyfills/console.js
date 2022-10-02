define(function(require) {
    var methods = [
        "assert",
        "count",
        "clear",
        "debug",
        "dir",
        "dirxml", 
        "error",
        "exception",
        "group",
        "groupCollapsed",
        "groupEnd",
        "info",
        "log",
        "profile",
        "profileEnd",
        "table",
        "time",
        "timeEnd",
        "timeStamp",
        "trace",
        "warn"
    ];
    var properties = [
        "memory"
    ];
    var console = window.console = window.console || {};
    function nonFn(){}
    for ( var i = 0, len = methods.length; i < len; i++ ) {
        console[methods[i]] = console[methods[i]] || nonFn;
    }
    len = properties.length;
    for ( i = 0; i < len; i++ ) {
        console[properties[i]] = console[properties[i]] || {};
    }
});