(function($,undefined){
    $(document).ready(function (){
        $('h1.page-title').html('User Account');
        $('nav.breadcrumb').parent().html('<nav class="breadcrumb"><a href="/">Home</a> » <a href="/user">User account</a> » User account</nav>');

        // Profile field alignment
        $('.page-user-edit-personal-information #user-profile-form, .page-user-edit-employment-information #user-profile-form').append('<div class="group-profile-left"></div>');
        $('.page-user-edit-personal-information #user-profile-form, .page-user-edit-employment-information #user-profile-form').append('<div class="group-profile-right"></div>');
        $('.page-user-edit-personal-information #user-profile-form .form-wrapper, .page-user-edit-employment-information .form-wrapper').slice(0,6).appendTo('#user-profile-form .group-profile-left');
        $('.page-user-edit-personal-information #user-profile-form .form-wrapper, .page-user-edit-employment-information .form-wrapper').slice(0,7).appendTo('#user-profile-form .group-profile-right');
        $('.form-actions').insertAfter('#user-profile-form .group-profile-right');
         
         // T2OM-359: HSIN user registration: adding class to indicate this is a new HSIN user registering
         if (window.location.href.indexOf("?hsinuser") > -1) {
           $('#user-profile-form').addClass("hsinreg");
           $('body').addClass("page-user-register");
           $('form.hsinreg fieldset').first().addClass("tw-security-q-wrapper");
         }
    })
})(jQuery); 
