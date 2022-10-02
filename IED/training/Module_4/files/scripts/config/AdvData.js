define(function( require ){
    
   var AdvData = {
       "version"  : "1.0.0",
       "settings" : require('./data/settings'),
       "plugins"  : require('./data/plugins'),
       "models"   : require('./data/models'),
       "levels"   : [
            require('./levels/scenario00'),
            require('./levels/scenario01'),
            require('./levels/scenario02'),
            require('./levels/scenario03'),
            require('./levels/scenario04'),
            require('./levels/scenario05'),
            require('./levels/scenario06'),
            require('./levels/scenario07'),
            require('./levels/scenario08'),
            require('./levels/scenario09')
       ]
   };
   
   return AdvData; 
});
