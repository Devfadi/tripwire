define(function(){
    
    var buttons = {
        init: function(){
            $("#leftButtonLink").click(function(){
                aden.pano.player.go('left');
                return false;
            });
            $('#rightButtonLink').click(function(){
                aden.pano.player.go('right');
                return false;
            });
        }
    };
    
    return buttons;
});
