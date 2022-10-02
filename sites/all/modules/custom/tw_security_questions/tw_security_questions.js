(function ($) {

Drupal.behaviors.password_reset = {
  attach: function() {
    var f = $('.password-reset-question-set');
    $('#edit-password-reset-question', f).attr('disabled', 'disabled');
    var a = $('.form-item-password-reset-answer', f)
      .hide()
      .after('<div id="password-reset-change">' + Drupal.t('Your answer for the chosen question has <strong>already</strong> been saved. <a href="#">Click here</a> if you would like to change the question or your answer.') + '</div>')
      .next('#password-reset-change')
      .children('a')
      .click(function(e) {
        $('#edit-password-reset-question', f).removeAttr('disabled');
        $('.form-item-password-reset-answer', f).show('slow');
        $(this).parent().hide();
        e.preventDefault();
      });
    
    // If there's an answer validation error, then unhide the answer field.
    if (Drupal.settings.password_reset) {
      $(a).click();
    }

    // T2OM-359: HSIN user registration: adding class to indicate this is a new HSIN user registering
    if (window.location.href.indexOf("?hsinuser") > -1) {
      $('#user-profile-form').addClass("hsinreg");
      $('body').addClass("page-user-register");
      $('form.hsinreg fieldset').first().addClass("tw-security-q-wrapper");

      // T2OM-359: Re-ordering the tabs on binding page
      var tabcount = 0;
      $('.page-user-edit.page-user-register ul.secondary li').each(function(){
        var urlpath = $(this).children().attr("href");
        var parts = urlpath.split("/");
        $(this).addClass(parts[parts.length-1]);
      });


      $('.page-user-edit.page-user-register ul.secondary li a').each(function(){
        $(this).attr('href', function() {
           return '#';
         });
       });

       $('.indicate_evc').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.employment_information').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.personal_information').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.privacy_information').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.edit').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.employment_information a').text('Employment');
       $('.indicate_evc a').text('Employment Verification Contact Information');
    }
  }
};

}(jQuery));
