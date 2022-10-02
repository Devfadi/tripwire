(function($,undefined){
    $(document).ready(function (){
console.log("hi");
         // T2OM-359: HSIN user registration: adding class to indicate this is a new HSIN user registering
           $('#user-profile-form').addClass("hsinreg");
           $('body').addClass("page-user-register");
           $('form.hsinreg fieldset').first().addClass("tw-security-q-wrapper");

    // T2OM-359: HSIN user registration: adding class to indicate this is a new HSIN user registering
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

      // TWDEV-26: Only mask Url for HSIN users
      if (window.location.href.indexOf("?hsinuser") > -1) {
        $('.page-user-edit.page-user-register ul.secondary li a').each(function(){
          $(this).attr('href', function() {
            return '#';
          });
        });
      }

       $('.indicate_evc').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.employment_information').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.personal_information').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.privacy_information').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.edit').prependTo('.page-user-edit.page-user-register ul.secondary');
       $('.employment_information a').text('Employment');
       $('.indicate_evc a').text('Employment Verification Contact Information');


    })
})(jQuery); 
