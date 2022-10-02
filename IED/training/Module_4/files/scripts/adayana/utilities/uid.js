define(function(){
    
    var count = 0;
    
    function generateUID( prefix ){
        if ( prefix ) {
            return prefix + count++;
        }
        else {
            return count++;
        }
    }
    
    // could also use this:
    // http://stackoverflow.com/questions/105034/how-to-create-a-guid-uuid-in-javascript
    // 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
        // var r = Math.random()*16|0, v = c === 'x' ? r : (r&0x3|0x8);
        // return v.toString(16);
    // });
    
    return generateUID;
});
