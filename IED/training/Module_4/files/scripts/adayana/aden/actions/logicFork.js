define(function(require){
    
    var _  = require('lodash'),
        _S = require('adayana/utilities/string');
    
    /**
     * Action which fires an event by evaluating a collection of rules
     * agains the value.
     */
    function logicFork( value, rules, fsm ) {
        _.forEach(rules,function(rule){
            switch ( rule.op ) {
                case "lt":
                case "<":
                    if ( value < rule.value ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "lte":
                case "<=":
                    if ( value <= rule.value ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "gt":
                case ">":
                    if ( value > rule.value ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "gte":
                case ">=":
                    if ( value >= rule.value ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "not":
                case "!=":
                case "!":
                    if ( value !== rule.value ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "eq":
                case "equal":
                case "=":
                case "===":
                    if ( value === rule.value ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
                case "===":
                    if ( value === rule.value ) {
                        fsm.trigger(rule.event);
                        return false;
                    }
                    break;
            }
        },this);
    }
    
    return logicFork;
});