(function($) {
    Drupal.behaviors.confirmPopUp = {
      attach: function (context, settings) {
    
        $(document).ready(function() {
    
          $("#edit-submit").attr("type", "fake");    
          $("#edit-submit").attr("id", "fake");
    
          $(document).on("click", "#fake", function(){
            var box = $("<div class='popup-box'><b>Warning! You are about to send out the email to TRIPwire users. Confirm you have completed the following:</b><ol><li>Applied the appropriate filters on the user population.</li><li>Drafted and reviewed your email message.</li><li>Received appropriate approval(s)?</li></ol><div class='btns-wrapper'><span class='save-btn'>Send</span><span class='cancel-btn'>Cancel</span></div></div>");
    
            $("form.confirmation").prepend('<div class="blackbg"></div>').prepend(box);
            $("form.confirmation").addClass('transbg');
            $("form.confirmation").prepend('<div class="blackbg"></div>');
          });
    
          $(document).on("click", ".save-btn", function(){
            $('#fake').attr("type","submit");         
            $('#fake').attr("id","edit-submit");
            $('#edit-submit')[0].click();
          });
    
          $(document).on("click", ".cancel-btn", function(){
            $(".blackbg").remove();
            $(".popup-box").remove();
          });
    
        });
    
      }
    };
    })(jQuery);