jQuery(document).ready(function($) {
    console.log("loaded");
    if ($('input.form-checkbox').is(':checked')) {
        console.log("check");
        enableRegistration();
      } else {
          console.log("unchecked");
        disableRegistration();
      }

      $('input.form-checkbox').change(function() {
        if(this.checked) { 
            console.log("check");
            enableRegistration();
        } else {
            console.log("unchecked");
            disableRegistration();
        }
    });

    function disableRegistration() {
        $('form.security-annual input.form-submit').addClass('disabled').prop("disabled", "true");
        $('.wizard-trail a').css('pointer-events', 'none');
      }
    
      function enableRegistration() {
        $('form.security-annual input.form-submit').removeClass('disabled').prop("disabled", "false");
        $('.wizard-trail a').css('pointer-events', 'auto');
        $('form.security-annual input.form-submit').removeAttr("disabled");
      }
});