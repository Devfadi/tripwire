(function($,undefined){
  $(document).ready(function (){

    // Personal Information profile field alignment
    // Commented out this code because on April 26 2019 some registration fields were being duplicated.
    //$('#edit-profile-personal-information .fieldset-wrapper, #edit-profile-employment-information .fieldset-wrapper').append('<div class="group-profile-left"></div>');
    //$('#edit-profile-personal-information .fieldset-wrapper, #edit-profile-employment-information .fieldset-wrapper').append('<div class="group-profile-right"></div>');
    $('#edit-profile-personal-information .fieldset-wrapper .form-wrapper').slice(0,5).appendTo('#edit-profile-personal-information .fieldset-wrapper .group-profile-left');
    $('#edit-profile-personal-information .fieldset-wrapper .form-wrapper').slice(0,8).appendTo('#edit-profile-personal-information .fieldset-wrapper .group-profile-right');

    //Employment profile field alignment
    $('#edit-profile-employment-information .fieldset-wrapper .form-wrapper').slice(0,7).appendTo('#edit-profile-employment-information .fieldset-wrapper .group-profile-left');
    $('#edit-profile-employment-information .fieldset-wrapper .form-wrapper').slice(0,3).appendTo('#edit-profile-employment-information .fieldset-wrapper .group-profile-right');

    // Move nav bar into place
    $('#user-register-form .multipage-panes').prepend('<div class="wizard-trail"></div>');
    $('.page-user-register .block-multipage-jumplist ul').appendTo('#user-register-form .multipage-panes .wizard-trail');

    // Format phone number fields
    $('.group-pagetwo .field-name-field-professional-phone-number input, .group-pagetwo .field-name-field-alternate-phone-number input').mask("999-999-9999");
    $('.group-pagethree .field-name-field-employment-verification-p input').mask("999-999-9999");
    

    // Store values for use in confirmation
    $('#edit-profile-confirm-profile .fieldset-wrapper').append('<div class="confirmation-values"></div>');
    $('.form-submit').click(function() {
      localStorage.clear();
      $('input[type="text"]').each(function(){    
        var id = $(this).parent().find('label').text();
        var value = $(this).val();
        localStorage.setItem(id, value);
      });   
    });

    // Ensure privacy box checked
    $('.multipage-jumplist li #jump-user-form-group-privacy').click(function() {
      if ($('.multipage-jumplist li #jump-user-form-group-privacy').hasClass("active")) {
        if ($('.group-privacy input.form-checkbox').is(':checked')) {
          enableRegistration();
        } else {
          disableRegistration();
        }
      }
    });
    $('.group-privacy input.form-checkbox').click(function() {
      if ($('input.form-checkbox').is(':checked')) {
        enableRegistration();
      } else {
        disableRegistration();
      }
    });

    $('.group-privacy .form-item-profile-privacy-information-field-privacy-agreement-und a').attr("onclick", "window.open(this.href,this.target,'height=690, width=1210');return false;");
    
    $('.group-pagethree .form-submit, .multipage-jumplist #jump-user-form-group-confirmation, .group-subscriptions input.multipage-link-next').click(function() {
      $('#edit-profile-confirm-profile .fieldset-wrapper .confirmation-values').empty();
      var output = ''; 
      for (var key in localStorage) {
        //output = output + '<div>' + (key + ':' +localStorage[key]) + '</div>';
        //output = output+(key + ':' +localStorage[key])+'\n';
      }
      //$('#edit-profile-confirm-profile .fieldset-wrapper .confirmation-values').html(output);
      userdata = [];
      x = 1;
      userdata = [];
      $('.field-group-multipage').each(function() {
        
        //userdata.push({name: 'id' + x, labelval: 'label' + x, val: 'value' + x});
        var header = $(this).find('.fieldset-legend').text();
        if (header == 'Hide Security questionsUsername') {
          header = 'Account Info';
        }
        if (header == 'Indicate EVC') {
          header = 'Employment Verification Contact Information';
        }
        userdata.push({name: 'page-header', labelval: header, val: ''});
        if (header == 'My TRIPwire Subscriptions') {
          $('input[type="checkbox"]').each(function(index, element){
            if(element.checked){
              // Checking for the presence of the privacy agreement. If found, skipping it.
              var value = $(element).siblings().text();
              if (value.indexOf("I have read and agree") < 0) {
                var id = 'My TRIPwire Subscriptions';
                var label = $(this).parent().parent().parent().children().first().text();
                userdata.push({name: id, labelval: label, val: value});
              }
            }
          });
        }

        $(this).children().find('input[type="text"], select').each(function(){  
        //$('input[type="text"], select').each(function(){    
          var id = $(this).attr('id');
          var label = $(this).parent().find('label').text().replace('*', '');
          if ($(this).attr('id') == 'edit-tw-security-questions-challenge-1-question' || $(this).attr('id') == 'edit-tw-security-questions-challenge-2-question') {
            var value = $(this).parent().find('select option:selected').text();
          } else {           
            var value = $(this).val();
          }
          if (id == 'edit-profile-personal-information-field-certification-expiration-d-und-0-value-date') {
            label = 'Certification Expiration Date';
          }
          userdata.push({name: id, labelval: label, val: value});
  
        });
        x++;
      });
     
      var str = '';
      for(i in userdata){
          if (userdata[i].labelval !== '') {
            if (userdata[i].labelval !== 'Privacy Information') {
              if (userdata[i].labelval !== 'Confirm Profile') {
                if (userdata[i].name == 'page-header') {
                  if (i == 0) {
                    str += '<div class="' + userdata[i].name + ' page-header-' + i + '"><h2>' + userdata[i].labelval + '</h2>';
                  } else {
                    str += '</div><div class="' + userdata[i].name + ' page-header-' + i + '"><h2>' + userdata[i].labelval + '</h2>';
                  }
                } else {
                  str += '<div class="field-value ' + userdata[i].name + '">' + userdata[i].labelval + ': <span class="response">' + userdata[i].val + '</span></div>';
                }
                
              }
            }
          }
      }
      $('#edit-profile-confirm-profile .fieldset-wrapper .confirmation-values').append(str);
      //fixMyDate();
  });

  function disableRegistration() {
    console.log("disable");
    $('input.multipage-link-next').addClass('disabled').prop("disabled", "true");
    $('input.multipage-link-previous').addClass('disabled').prop("disabled", "true");
    $('.wizard-trail a').css('pointer-events', 'none');
  }

  function enableRegistration() {
    console.log("enable");
    $('input.multipage-link-next').removeClass('disabled').prop("disabled", "false");
    $('input.multipage-link-previous').removeClass('disabled').prop("disabled", "false");
    $('.wizard-trail a').css('pointer-events', 'auto');
    $('input.multipage-link-next').removeAttr("disabled");
    $('input.multipage-link-previous').removeAttr("disabled");
  }
  


    
    // Potentially dont need any of this anymore since it relied on the step module
    $('.BREAKTHISwizard-trail span').each(function() {
      var section = $(this).text();
      var path = '/';
      switch (section) {
        case 'Personal Information': 
          path = '/user/register/personal_information';
          break;
        case 'Privacy Information':
          path = '/user/register/privacy_information';
          $('input.form-checkbox').change(function() {
            if(this.checked) { 
              enableRegistration();
            } else {
              disableRegistration();
            }
          });
          break;
         case 'Employment':
           path = '/user/register/employment';
           $('.field-name-field-professional-phone-number input, .field-name-field-alternate-phone-number input').mask("999-999-9999");
           break;
         case 'Employment Verification Contact Information':
           path = '/user/register/employment_verification_contact_information';
           $('.field-name-field-employment-verification-p input').mask("999-999-9999");
           break;
         case 'Account Information':
           path = '/user/register/account_information';
           break;
         case 'Confirmation':
           path = '/user/register/confirmation';
           if ($('.field_certification_expiration_d .rowval').length > 0) {
             var unixTimestamp = $('.field_certification_expiration_d .rowval').html();
             var date = new Date(unixTimestamp*1000);
             var formattedDate = new Date(date);
             var d = formattedDate.getDate();
             var m = formattedDate.getMonth();
             m += 1; // Javascript months are 0-11
             var y = formattedDate.getFullYear();
             $('.field_certification_expiration_d .rowval').html(m + '/' + d + '/' + y);
           }
           break;
      }
      $(this).wrapInner('<a href="' + path + '"></a>');
    });

  if (location.pathname == '/user/register/privacy_information') {
    if ($('input.form-checkbox').is(':checked')) {
      enableRegistration();
    } else {
      disableRegistration();
    }
  }

  if (location.pathname == '/user/register/confirmation') {
    $('#edit-profile-confirmation input.form-text').each(function() {
      $(this).prop("disabled", "true");
    });
    $('#edit-profile-confirmation select').each(function() {
      $(this).prop("disabled", "true");
    });
  }

  // T2OM-164: Adding Subscriptions markup text
  $('.page-user-register #edit-profile-my-tripwire-subscriptions .field-name-field-caution-text p').html("To modify your subscriptions after registration, please visit the My TRIP<em>wire</em> page.");

  })
})(jQuery);
