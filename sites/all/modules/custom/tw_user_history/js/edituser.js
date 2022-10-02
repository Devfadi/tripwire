jQuery(document).ready(function($) {
    $('.form-item-current-pass .description').html('Enter your current password if you wish to change your email address.');
    $('.page-user-edit-indicate-evc #user-profile-form #edit-profile-indicate-evc-field-notes').remove();
    $('.page-user-edit-indicate-evc #user-profile-form .field-type-text input, .page-user-edit-indicate-evc #user-profile-form .form-actions input').each(function(){
        $(this).attr("disabled", "disabled");
        $(this).addClass("disabled");
    });
    $('.page-user-edit-privacy-information #user-profile-form input').each(function(){
        $(this).attr("disabled", "disabled");
        $(this).addClass("disabled");
    });
    $('.page-user-edit-indicate-evc #user-profile-form').append('<div>Contact Trip<span class="wire">wire</span> Help Desk to update your EVC information.')

});