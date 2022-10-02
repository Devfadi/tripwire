define(function(){
    var MathUtil = {};
    
    /**
     * Rounded value of Pi
     */
    MathUtil.pi = 3.1415926535897932384626433832795028841971693;
    
    /**
     * Calculates Difference of two values
     */
    MathUtil.diff = function(a,b)
    {
        return Math.abs(a-b);
    };
    
    /**
     * Angle between two directional vectors with same origin
     */
    MathUtil.diffAngle = function(ah,av,bh,bv)
    {
        ah = ah * this.pi/180;
        av = av * this.pi/180;
        bh = bh * this.pi/180;
        bv = bv * this.pi/180;
        
        ax = Math.cos(ah) * Math.cos(av);
        ay = Math.sin(av);
        az = Math.sin(ah) * Math.cos(av);
        
        bx = Math.cos(bh) * Math.cos(bv);
        by = Math.sin(bv);
        bz = Math.sin(bh) * Math.cos(bv);
        
        var dotproduct = (ax * bx) + (ay * by) + (az * bz);
        var angle_rad  = Math.acos(dotproduct);
        
        var angle = Math.abs(angle_rad * 180/this.pi);
        if ( angle > 360 ) {angle -= 360;}
        
        return angle;
    };
    
    /**
     * Vector Angle calculation
     */
    MathUtil.vectorAngle = function( ax, ay, az, bx, by, bz )
    {
        var dotproduct = (ax * bx) + (ay * by) + (az * bz);
        var lengtha    = Math.sqrt(ax * ax + ay * ay);
        var lengthb    = Math.sqrt(bx * bx + by * by);
        
        var angle_rad  = Math.acos(dotproduct / (lengtha * lengthb));
        
        if ( dotproduct < 0 ) {
            if ( angle_rad > 0 ){
                angle_rad += this.pi;
            } else {
                angle_rad -= this.pi;
            }
        }
        
        return angle_rad;
    };
    
    /**
     * Calculate angle between two points
     */
    MathUtil.angle = function(x1, y1, x2, y2) {
        
        if ( x1 === x2 && y1 === y2 ) {
            return 0;
        }
        
        var quad  = this.quadrant(x1, y1, x2, y2);
        
        var dy = MathUtil.diff(y1, y2);
        var dx = MathUtil.diff(x1, x2);

        var angle = Math.atan(dy/dx) * (180 / this.pi);
        
        if ( quad === 4 ) {
            angle = 180 - angle;
        } else if ( quad === 3 ) {
            angle = 180 + angle;
        } else if ( quad === 2 ) {
            angle = 360 - angle;
        }
        
        return angle;
    };
    
    MathUtil.sphericalAngle = function(x1, y1, x2, y2) {
        if ( x1 === x2 && y1 === y2 ) {
            return 0;
        }
        
        var dy = y2 - y1;
        var dx = x2 - x1;    
        var angle = Math.atan2(dy,dx) * (180 / this.pi);
        angle = MathUtil.absAngle(angle);
        
        return angle;
    };
    
    /**
     * Convert degrees to radians
     * @param {type} degrees
     * @returns {Number}
     */
    MathUtil.toRadian = function(degrees) {
        return ( degrees * ( this.pi / 180 ));
    };
    
    /**
     * convert radians to degrees
     * @param {type} radians
     * @returns {Number}
     */
    MathUtil.toAngle = function(radians) {
        return ( radians * ( 180 / this.pi ));
    };
    
    /**
     * Returns the hypotenuse
     */
    MathUtil.hypotenuse = function(dx, dy) {
        return Math.sqrt((dy * dy) + (dx * dx));
    };
    
    MathUtil.distance = function( dx, dy ) {
        return Math.sqrt( Math.pow(dx,2) + Math.pow(dy,2));
    };
    
    /**
     * Returns the quadrant of the second point when using the first point as the origin
     */
    MathUtil.quadrant = function(x1, y1, x2, y2) {
        var quad    = 0;
        
        if      ( ( x1 <= x2 ) && ( y1 <= y2 ) ) {quad = 1;}
        else if ( ( x1 <= x2 ) && ( y1 >= y2 ) ) {quad = 2;}
        else if ( ( x1 >= x2 ) && ( y1 >= y2 ) ) {quad = 3;}
        else if ( ( x1 >= x2 ) && ( y1 <= y2 ) ) {quad = 4;}
        
        return quad;
    };
    
    MathUtil.sphericalQuadrant = function(x1, y1, x2, y2) {
        var quad    = 0;
        
        if      ( ( x1 <= x2 ) && ( y1 <= y2 ) ) {quad = 1;}
        else if ( ( x1 <= x2 ) && ( y1 >= y2 ) ) {quad = 4;}
        else if ( ( x1 >= x2 ) && ( y1 >= y2 ) ) {quad = 3;}
        else if ( ( x1 >= x2 ) && ( y1 <= y2 ) ) {quad = 2;}
        
        return quad;
    };
    
    /**
     *  Calculates the absolute value of the remainder
     */
    MathUtil.absAngle = function(angle) {
        var a = angle % 360;
        if ( a < 0 ) {
            a += 360;
        }
        return a;
    };
    
    /**
     * Generates a random integer 
     * @param {Object} min
     * @param {Object} max
     */
    MathUtil.getRandomInt = function(min, max) {
        return Math.floor(Math.random() * (max - min + 1) + min);
    };
    
    return MathUtil;
});
