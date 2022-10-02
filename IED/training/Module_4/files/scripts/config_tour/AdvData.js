define(function( require ){
    
   var AdvData = {
       "settings" : require('./data/settings'),
       "plugins"  : require('./data/plugins'),
       "models"   : require('./data/models'),
       "levels"   : [
            require('./levels/scenario00'),
            null,
            require('./levels/scenario02')
       ]
   };
   
   return AdvData;
    
});
