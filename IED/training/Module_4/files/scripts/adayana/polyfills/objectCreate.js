/**
 * @fileOverview Contains a Module which adds the create() method onto the
 * native Object object.
 * Source: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/create
 * @history 2013-07-19 VRB - Initial Version
 */
define(function (require) {
    if (!Object.create) {
        Object.create = (function () {
            function F () {}
            return function (o) {
                if (arguments.length !== 1) {
                    throw new Error('Object.create implementation only accepts one parameter.');
                }
                F.prototype = o;
                return new F();
            };
        })();
    }
});