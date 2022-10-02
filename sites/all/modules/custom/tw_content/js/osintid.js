(function($) {
    Drupal.behaviors.confirmPopUp = {
      attach: function (context, settings) {
    
        $(document).ready(function() {
          if ( typeof Drupal.settings.tw_content !== 'undefined') {
            if ( typeof Drupal.settings.tw_content.osint_replace !== 'undefined' && Drupal.settings.tw_content.osint_replace !== '' ){
                var box = $("<div class='popup-box'><b>This OSINT item currently exists, are you sure you want to overwrite it?</b><div class='btns-wrapper'><span class='save-btn'>Overwrite</span><span class='cancel-btn'>Cancel</span></div></div>");
        
                $("body").prepend('<div class="blackbg"></div>').prepend(box);
              }
          }
          
    
          $(document).on("click", ".save-btn", function(){
            jQuery.ajax({
				type:'POST',
				url: Drupal.settings.basePath+'node/osint-team-id',
				data: 'count=' + Drupal.settings.tw_content.osint_replace,
                dataType: 'json',
            });
            alert("Previous OSINT Item has been deleted. Please re-submit.")
            delete Drupal.settings.tw_content.osint_replace;
            $(".blackbg").remove();
            $(".popup-box").remove();
            //$('#edit-submit')[0].click();
          });
    
          $(document).on("click", ".cancel-btn", function(){
            $(".blackbg").remove();
            $(".popup-box").remove();
          });
    
        });
    
      }
    };
    })(jQuery);