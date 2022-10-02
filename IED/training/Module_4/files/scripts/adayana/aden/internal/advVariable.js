define(function(require){
    /**
     * creates an instance of an Adventure Variable
     * @constructs
     */
    var AdvVariable = function( data ){
        if ( data ) {
            this.name       = data.name;
            this.type       = data.type.toLowerCase();
            this.shouldReset      = (data.reset)    ? !!data.reset  : false;
            this.loop       = (data.loop)     ? !!data.loop   : false;
            this.onChange   = (data.onChange) ? data.onChange : function(){};
            this.onTrue     = (data.onTrue)   ? data.onTrue   : function(){};
            this.onFalse    = (data.onFalse)  ? data.onFalse  : function(){};
            this.onMax      = (data.onMax)    ? data.onMax    : function(){};
            this.onMin      = (data.onMin)    ? data.onMin    : function(){};
            this.hasChanged = false;
            if ( this.type.toLowerCase() === "number" ) {
                this.max = (data.max) ? data.max : null;
                this.min = (data.min) ? data.min : null;
            }
            this.set( data.value );
            this.initial = data.value;
        }
    };
    
    AdvVariable.prototype = {
        /**
         * Variable's name 
         */
        name: "undefined",
        /**
         * Variable Type 
         */
        type: "undefined",
        /**
         * stored value 
         */
        value: null,
        /**
         * maximum value for this variable 
         */
        max: null,
        /**
         * minimum value for this variable 
         */
        min: null,
        /**
         * Boolean indicating whether the value should reset on every update cycle 
         */
        shouldReset: false,
        /**
         * Boolean indicating if values should loop back around if extents are surpassed 
         */
        loop: false,
        /**
         *  Boolean indicating whether the value has changed since the last update cycle
         */
        hasChanged: false,
        
        /**
         * updates the variable 
         */
        update: function() {
            if ( this.shouldReset ) {
                reset();
            }
            this.hasChanged = false;
        },
        
        /**
         * reset variable back to its initial value 
         */
        reset: function() {
            this.value = this.initial;
        },
        
        /**
         * retrive the value 
         */
        get: function() {
            return this.value;
        },
        
        /**
         * set the value 
         * @param {Object} val
         */
        set: function( val ) {
            // error checking
            switch ( this.type ) {
                case "number":
                case "float":
                    val = parseFloat(val);
                    break;
                case "integer":
                    val = parseInt(val,10);
                    break;
                case "boolean":
                    val = castToBoolean(val);
                    break;
                case "string":
                    val = '' + val; // cast as string;
                    break;
            }
            // when value has changed
            if ( val !== this.value ) {
                if ( this.loop && this.min !== null && this.max !== null ) {
                    if ( val > this.max ) {
                        val = this.min;                        
                    }
                    else if ( val < this.min ) {
                        val = this.max;                        
                    }
                } else {
                    if ( this.max && val > this.max ) {
                        val = this.max;                        
                    }
                    if ( this.min && val < this.min ) {
                        val = this.min;                        
                    }
                }
                // when value has changed
                if ( val !== this.value ) {
                    this.value = val;
                    this.hasChanged = true;
                    this.onChange();
                    
                    if ( this.type === 'boolean' && this.value === true ) {
                        this.onTrue();  
                    }
                    if ( this.type === 'boolean' && this.value === false ) {
                        this.onFalse();
                    }
                    if ( this.value === this.max ) {
                        this.onMax();
                    }
                    if ( this.value === this.min ) {
                        this.onMin();
                    }
                }
            }
        },
        
        /**
         * check if stored value is equal to the passed in value  
         * @param {Object} val
         */
        is: function( val ) {
            return ( this.value === val );
        },
        
        /**
         * increment the value of the variable 
         * @param {Object} value
         */
        increment: function( value ) {
            value = ( value ) ? value : 1;
            this.setValue( this.value + value );
        },
        
        /**
         * decrement the value of the variable 
         * @param {Object} value
         */
        decrement: function( value ) {
            value = ( value ) ? value : 1;
            this.setValue( this.value - value );
        }
    };
    
    function castToBoolean ( value ) {
        if ( _.isString( value ) ) {
            switch( value.toLowerCase() ) {
                case "true":
                case "yes":
                case "1":
                    return true;
                case "false":
                case "no":
                case "0":
                    return false;
                default:
                    return Boolean(value);
            }
        } else {
            return !!value;
        }
    }
       
    return AdvVariable;
});
