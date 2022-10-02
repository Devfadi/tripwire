define(function(require){
    
    var _  = require('lodash'),
        _S = require('adayana/utilities/string');
    
    /**
     * Action which fires an event by evaluating a collection of rules
     * agains the current time.
     * @param {Number|String} currTime - current time
     * @param {Array|Object} rules - collection of rules
     * @param {Object} fsm - fsm object
     */
    function timeFork( time, rules, fsm ) {
        if ( _.isString( time ) ) {
            time = 1000 * ( _S.parseTime( time ) );
        }
        /*
         * rule = {
         *     op: "lte",
         *     time: {String|Number} ex. "00:00:10.00",
         *     event: "name"
         * }
         */
        _.forEach(rules,function(rule){
            if ( _.isString( rule.time ) ) {
                rule.time = 1000 * ( _S.parseTime( rule.time ) );
            }
            switch ( rule.op ) {
                case "lt":
                case "<":
                    if ( time < rule.time ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "lte":
                case "<=":
                    if ( time <= rule.time ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "gt":
                case ">":
                    if ( time > rule.time ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "gte":
                case ">=":
                    if ( time >= rule.time ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "not":
                case "!=":
                case "!":
                    if ( time !== rule.time ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "eq":
                case "equal":
                case "=":
                case "===":
                case "===":
                    if ( time === rule.time ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
            }
        },this);
    }
    
    return timeFork;
});