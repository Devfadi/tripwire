jQuery(document).ready(function($) {
    $('.field-name-field-notes textarea').on("propertychange input", function() {
        if (this.value.length > 200) {
            this.value = this.value.substring(0, 200);
        }  
    });

    $('.field-name-field-notes label ').append('<span class="form-required" title="This field is required.">*</span>');

    /* TRIP2-393: Disabling privacy checkbox change for help desk role */
    if (typeof Drupal.settings.tw_user_history !== 'undefined') {
        /* Disabling Manage Display tab for help desk role */
        if (typeof Drupal.settings.tw_user_history.helpdesk !== 'undefined') {
            if (Drupal.settings.tw_user_history.helpdesk == 'true') { 
                $('#branding ul.tabs li a').each(function(index, element) {
                    if($(element).text() == "Manage display") {
                        $(this).parent().hide();
                    }
                });
            }
        }
        if (typeof Drupal.settings.tw_user_history.privacy !== 'undefined') {
            if (Drupal.settings.tw_user_history.privacy.length > 0) { 
                $('.field-name-field-privacy-agreement input.form-checkbox').attr("disabled", "true");
            }
        }
    }

    /* TRIP2-372: converting action taken log to render HTML */
    $('.view-account-action-log tbody .views-field-log').each(function() {
        var log = $(this).text();
        $(this).html(log);
    });

    /* TRIP2-501: Adding a read-only copy of the Drupal status to user edit */
    $('#edit-mimemail').hide();
    var drupal_status = '';
    $('.form-item-status .form-radios .form-item-status').each(function() {
        if ($(this).find('input').val() == 1) {
            drupal_status += '<div class="form-item"> <input disabled="disabled" type="radio" value="' + $(this).find('input').val() + '" checked="checked" class="form-radio">  <label class="option">' + $(this).find('label').text() + '</label></div>'
        } else {
            drupal_status += '<div class="form-item"> <input disabled="disabled" type="radio" value="' + $(this).find('input').val() + '" class="form-radio">  <label class="option">' + $(this).find('label').text() + '</label></div>'
        }
    });
    $('.group-accountstatus .horizontal-tabs-panes .group-drupal-status .fieldset-wrapper').append(drupal_status);

    /* TRIP2-503 */
    $('.form-item-roles .form-checkboxes, .form-item-roleassign-roles .form-checkboxes').append('<div class="roles-block userroles"><h3 class="userroles">User Roles</h3></div><div class="roles-block"><div class="elevated"><h3 class="elevated">Elevated Roles (manager approval)</h3></div><div class="attribute"><h3 class="attribute">Role Atttribute (manager approval)</h3></div></div><div class="roles-block regattr"><h3 class="regattr">Registration Attributes (testing only)</h3></div>');
    $('.form-item-roles .form-checkboxes  .form-item-roles-8, .form-item-roles .form-checkboxes  .form-item-roles-7, .form-item-roles .form-checkboxes  .form-item-roles-21, .form-item-roles .form-checkboxes  .form-item-roles-10, .form-item-roles .form-checkboxes  .form-item-roles-9, .form-item-roles .form-checkboxes  .form-item-roles-11, .form-item-roles .form-checkboxes  .form-item-roles-12, .form-item-roles .form-checkboxes  .form-item-roles-14, .form-item-roles .form-checkboxes  .form-item-roles-42').appendTo('div.userroles');
    $('.form-item-roles .form-checkboxes  .form-item-roles-3, .form-item-roles .form-checkboxes  .form-item-roles-41, .form-item-roles .form-checkboxes  .form-item-roles-4, .form-item-roles .form-checkboxes  .form-item-roles-6').appendTo('div.elevated');
    $('.form-item-roles .form-checkboxes  .form-item-roles-36').appendTo('div.attribute');
    $('.form-item-roles .form-checkboxes  .form-item-roles-31, .form-item-roles .form-checkboxes  .form-item-roles-26, .form-item-roles .form-checkboxes  .form-item-roles-43').appendTo('div.regattr');
    $('.form-item-roles .form-checkboxes  .form-item-roles-2').hide();

    $('.form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-8, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-7, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-21, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-10, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-9, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-11, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-12, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-14, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-42').appendTo('div.userroles');
    $('.form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-3, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-41, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-4, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-6').appendTo('div.elevated');
    $('.form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-36').appendTo('div.attribute');
    $('.form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-31, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-26, .form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-43').appendTo('div.regattr');
    $('.form-item-roleassign-roles .form-checkboxes  .form-item-roleassign-roles-2').hide();
    /*
    $('.form-item-roles .form-checkboxes  .form-item-roles-8').before('<div class="userroles"><h3 class="userroles">User Roles</h3>');
    $('.form-item-roles .form-checkboxes  .form-item-roles-3').before('</div><div class="elevated"><h3 class="elevated">Elevated Roles (manager approval)</h3>');
    $('.form-item-roles .form-checkboxes  .form-item-roles-36').before('</div><div class="attribute"><h3 class="attribute">Role Atttribute (manager approval)</h3>');
    $('.form-item-roles .form-checkboxes  .form-item-roles-31').before('</div><div class="regattr"><h3 class="regattr">Registration Attributes (testing only)</h3>');
    $('.form-item-roles .form-checkboxes  .form-item-roles-31').after('</div>');*/

    /* TRIP2-545: Adding alert to email user drop down */
    $('.field-name-field-email-user select').change(function(){
        if($(this).val() !== "_none") {
                alert("Are you sure you want to send this email to the user? Please make sure Account and Drupal Status, State, EVC Status align with the email correspondence submitted to the user.")
            }
    });

    /* T2OM-29: Adding alert to warn HD to assign role before approving */
    $('.field-name-field-account-approved select').change(function(){
        if($(this).val() == "approved") {
                alert("Attention! Be sure to assign a role to this user and then save the user BEFORE approving the account.")
            }
    });

    /* T2OM-49: Adding alert to warn HD when user is set to EVC Denied */
    $('.field-name-field-evc-actions select').change(function(){
        if($(this).val() == "evc_denied") {
                alert("By taking this action, the user's access to TRIPwire will be removed until an EVC verifies `their need to know` a new user role is assigned. Please advise the user before proceeding.")
            }
    });

    // T2OM-26: Adding a notification next to save button
    if ($('.page-user .messages.status ul li:contains("The changes have been saved"), .page-user .messages.status:contains("The changes have been saved")').length > 0) {
        $('.page-user .form-actions #edit-submit').after('<span style="color:red; font-style: italic;">Action Saved</span> ');
    }

});