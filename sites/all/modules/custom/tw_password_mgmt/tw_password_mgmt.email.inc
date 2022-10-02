<?php

/**
 * This function creates the settings page. It is a callback function for drupal_get_form()
 */
function tw_password_mgmt_email_settings($form, &$form_state) {
  // Retrieve the default values for 'value' and 'format', if not readily
  // available through other means:
  $defaults = array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $my_richtext_field = variable_get('my_richtext_field', $defaults);
  $sixmonthsdefaults = array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $dnadefaults = array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $lockeddefaults = array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $evc_conf_defaults = array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $evc_action_defaults= array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $evc_approved_defaults= array(
    'value' => '',
    'format' => filter_default_format(),
  );

  $evc_denied_defaults= array(
    'value' => '',
    'format' => filter_default_format(),
  );
  
  $acc_validate_defaults= array(
    'value' => '',
    'format' => filter_default_format(),
  );

  $six_months_email = variable_get('six_months_email_field', $sixmonthsdefaults);
  $dna_email = variable_get('do_not_approve_email_field', $dnadefaults);
  $account_locked_email = variable_get('account_locked_email_field', $lockeddefaults);
  $evc_conf_email = variable_get('evc_confirmation_email_field', $evc_conf_defaults);
  $evc_action_email = variable_get('evc_action_required_email_field', $evc_action_defaults);
  $evc_approved_email = variable_get('evc_approved_email_field', $evc_approved_defaults);
  $evc_denied_email = variable_get('evc_denied_email_field', $evc_denied_defaults);
  $evc_nine_email = variable_get('evc_nine_day_email_field', $evc_denied_defaults);
  $evc_fourteen_email = variable_get('evc_fourteen_day_email_field', $evc_denied_defaults);
  $inactivity_email = variable_get('inactivity_warning_email_field', $evc_denied_defaults);
  $acc_validate_email = variable_get('account_validation_email', $acc_validate_defaults);
  $evc_updated_email = variable_get('evc_updated_email_field', $acc_validate_defaults);
  $evc_init_reminder_email = variable_get('evc_init_reminder_email_field', $acc_validate_defaults);
  $evc_annual_verification_email = variable_get('evc_annual_verification_email_field', $acc_validate_defaults);
  $evc_annual_verification_user_email = variable_get('evc_annual_verification_user_email_field', $acc_validate_defaults);
  $evc_confirmation_reminder_email_field = variable_get('evc_confirmation_reminder_email_field', $acc_validate_defaults);
  $evc_nonresponse_user_email_field = variable_get('evc_nonresponse_user_email_field', $acc_validate_defaults);
  $password_7_days_email_field = variable_get('password_7_days_email_field', $acc_validate_defaults);
  $evc_init_reminder_accountholder_email = variable_get('evc_init_reminder_accountholder_email_field', $acc_validate_defaults);
  $evc_annual_verification_user_reminder_email = variable_get('evc_annual_verification_user_reminder_email_field', $acc_validate_defaults);
  $evc_annual_verification_evc_email = variable_get('evc_annual_verification_evc_email_field', $acc_validate_defaults);
  $password_reset_email_subject = variable_get('user_mail_password_reset_subject', FALSE);
  $password_reset_email_body = variable_get('user_mail_password_reset_body', FALSE);
  $account_approved_hsin = variable_get('account_approved_hsin_body', FALSE);  
  $account_approved_hsin_body = variable_get('account_approved_hsin_email_field', $acc_validate_defaults);
  
   // Just construct a regular #type 'text_format' form element:
  $form['help_text'] = array(
    '#markup' => '<p>Here are the replacement values to use in emails:</p><pre>
    Title: [user:profile-personal-information:field-title] 
    First name: [user:profile-personal-information:field-first-name] 
    Last name: [user:profile-personal-information:field-last-name]
    
    EVC Title: [user:profile-indicate-evc:field_verification_contact_title]
    EVC Contact Name: [user:profile-indicate-evc:field-employment-verification-co]
    Employer Company Name: [user:profile-employment-information:field-employer-name]
    
    EVC Approve Link: [EVC Verified Link]
    EVC Deny Link: [EVC Denied Link]
    
    Verify Account Link: [Verify Account Link]</pre>',
  );

  $form['account_validation_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Initial Email Verification Due'),
	  '#description' => t('Enter the text for the body of the email sent to account holder who has just registered and needs to validate their email address.'),
    '#default_value' => $acc_validate_email['value'],
    '#format' => $acc_validate_email['format'],
  );

  $form['evc_nine_day_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Initial Employment Verification Due (to EVC)'),
	  '#description' => t('Enter the text for the body of the email sent to the EVC to remind them to confirm or deny the account holder.'),
    '#default_value' => $evc_nine_email['value'],
    '#format' => $evc_nine_email['format'],
  );

  $form['evc_action_required_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Initial Employment Verification Due (to Account Holder)'),
	  '#description' => t('Enter the text for the body of the email sent in EVC Action Required email.'),
    '#default_value' => $evc_action_email['value'],
    '#format' => $evc_action_email['format'],
  );

  $form['evc_updated_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('EVC Updated (to Account Holder)'),
	  '#description' => t('Enter the text for the body of the email sent in EVC Updated email.'),
    '#default_value' =>  $evc_updated_email['value'],
    '#format' =>  $evc_updated_email['format'],
  );

  $form['evc_approved_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Account Approved'),
	  '#description' => t('Enter the text for the body of the email sent in EVC Account Approved email.'),
    '#default_value' => $evc_approved_email['value'],
    '#format' => $evc_approved_email['format'],
  );

  $form['account_approved_hsin_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Account Approved - HSIN'),
          '#description' => t('Enter the text for the body of the email sent in Account Approved for a HSIN User.'),
    '#default_value' => $account_approved_hsin_body['value'],
    '#format' => $account_approved_hsin_body['format'],
  );

  $form['evc_denied_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Employment Verification Denied'),
	  '#description' => t('Enter the text for the body of the email sent when the EVC contact denies the account holder.'),
    '#default_value' => $evc_denied_email['value'],
    '#format' => $evc_denied_email['format'],
  );

  $form['evc_init_reminder_accountholder_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Initial Employment Verification Due Reminder (to Account Holder)'),
    '#default_value' => $evc_init_reminder_accountholder_email['value'],
    '#format' => $evc_init_reminder_accountholder_email['format'],
  );

  $form['evc_init_reminder_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Initial Employment Verification Overdue (to Account Holder)'),
    '#default_value' => $evc_init_reminder_email['value'],
    '#format' => $evc_init_reminder_email['format'],
  );

  $form['evc_annual_verification_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Annual Employment Verification Pending (to EVC)'),
    '#default_value' => $evc_annual_verification_email['value'],
    '#format' => $evc_annual_verification_email['format'],
  );

  $form['evc_annual_verification_user_reminder_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Annual Employment Verification Pending (to Account Holder)'),
    '#default_value' => $evc_annual_verification_user_reminder_email['value'],
    '#format' => $evc_annual_verification_user_reminder_email['format'],
  );

  $form['evc_annual_verification_user_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Annual Employment Verification Pending Reminder (to Account Holder)'),
    '#default_value' => $evc_annual_verification_user_email['value'],
    '#format' => $evc_annual_verification_user_email['format'],
  );

  $form['evc_annual_verification_evc_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Annual Employment Verification Pending Reminder (to EVC)'),
    '#default_value' => $evc_annual_verification_evc_email['value'],
    '#format' => $evc_annual_verification_evc_email['format'],
  );

  $form['evc_confirmation_reminder_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Annual Employment Verification Complete (to Account Holder)'),
    '#default_value' => $evc_confirmation_reminder_email_field['value'],
    '#format' => $evc_confirmation_reminder_email_field['format'],
  );

  $form['evc_nonresponse_user_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Annual Employment Verification Non-Response (to Account Holder)'),
    '#default_value' => $evc_nonresponse_user_email_field['value'],
    '#format' => $evc_nonresponse_user_email_field['format'],
  );

  $form['password_7_days_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Password Reset Warning (Lockout in 7 Days)'),
    '#default_value' => $password_7_days_email_field['value'],
    '#format' => $password_7_days_email_field['format'],
  );

  $form['my_richtext_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Password Reset Warning (Lockout in 14 Days)'),
	  '#description' => t('Enter the text for the body of the email sent to a user if their password will expire in 10 or less days.'),
    '#default_value' => $my_richtext_field['value'],
    '#format' => $my_richtext_field['format'],
  );

  $form['account_locked_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Account Locked Notification (Expired Password)'),
	  '#description' => t('Enter the text for the body of the email sent to a user if their account is locked due to their password expiring.'),
    '#default_value' => $account_locked_email['value'],
    '#format' => $account_locked_email['format'],
  );

  $form['six_months_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Six Months Password Expired Email'),
	  '#description' => t('Enter the text for the body of the email sent to a user if their password has expired and it has been six months or more.'),
    '#default_value' => $six_months_email['value'],
    '#format' => $six_months_email['format'],
  );

  $form['do_not_approve_email_field'] = array(
    '#type' => 'text_format',
    '#title' => t('Do Not Approve Email'),
	  '#description' => t('Enter the text for the body of the email sent to a user if a user is set to Do Not Approve.'),
    '#default_value' => $dna_email['value'],
    '#format' => $dna_email['format'],
  );

  $form['email_password_reset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Password recovery'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => t('Edit the e-mail messages sent to users who request a new password.'),
    '#group' => 'email',
  );


  $form['email_password_reset']['user_mail_password_reset_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Password Recovery Subject'),
    '#default_value' => $password_reset_email_subject,
    '#maxlength' => 180,
  );


  $form['email_password_reset']['user_mail_password_reset_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Password Recovery Email'),
    '#default_value' => $password_reset_email_body,
    '#rows' => 12,
  );


  $form['submit'] = array
	(
		'#type' => 'submit',
		'#value' => t('Submit'),
	);
	return $form;
}

/**
 * Submit function for the settings form
 */
function tw_password_mgmt_email_settings_submit($form, &$form_state) {
  $savedform = array(
    'value' => $form_state['values']['my_richtext_field']['value'],
    'format' => $form_state['values']['my_richtext_field']['format'],
  );
  variable_set('my_richtext_field', $savedform);

  $sixmonthsform = array(
    'value' => $form_state['values']['six_months_email_field']['value'],
    'format' => $form_state['values']['six_months_email_field']['format'],
  );
  variable_set('six_months_email_field', $sixmonthsform);

  $dnaform = array(
    'value' => $form_state['values']['do_not_approve_email_field']['value'],
    'format' => $form_state['values']['do_not_approve_email_field']['format'],
  );
  variable_set('do_not_approve_email_field', $dnaform);

  $lockedform = array(
    'value' => $form_state['values']['account_locked_email_field']['value'],
    'format' => $form_state['values']['account_locked_email_field']['format'],
  );
  variable_set('account_locked_email_field', $lockedform);

  $evc_action_form = array(
    'value' => $form_state['values']['evc_action_required_email_field']['value'],
    'format' => $form_state['values']['evc_action_required_email_field']['format'],
  );
  variable_set('evc_action_required_email_field', $evc_action_form);
  
  $evc_approved_form = array(
    'value' => $form_state['values']['evc_approved_email_field']['value'],
    'format' => $form_state['values']['evc_approved_email_field']['format'],
  );
  variable_set('evc_approved_email_field', $evc_approved_form);

  $hsin_approved_form = array(
    'value' => $form_state['values']['account_approved_hsin_email_field']['value'],
    'format' => $form_state['values']['account_approved_hsin_email_field']['format'],
  );
  variable_set('account_approved_hsin_email_field', $hsin_approved_form);

  $evc_denied_form = array(
    'value' => $form_state['values']['evc_denied_email_field']['value'],
    'format' => $form_state['values']['evc_denied_email_field']['format'],
  );
  variable_set('evc_denied_email_field', $evc_denied_form);

  $evc_nine_form = array(
    'value' => $form_state['values']['evc_nine_day_email_field']['value'],
    'format' => $form_state['values']['evc_nine_day_email_field']['format'],
  );
  variable_set('evc_nine_day_email_field', $evc_nine_form);

  $acc_validation_form = array(
    'value' => $form_state['values']['account_validation_email']['value'],
    'format' => $form_state['values']['account_validation_email']['format'],
  );
  variable_set('account_validation_email', $acc_validation_form);

  $evc_updated_form = array(
    'value' => $form_state['values']['evc_updated_email_field']['value'],
    'format' => $form_state['values']['evc_updated_email_field']['format'],
  );
  variable_set('evc_updated_email_field', $evc_updated_form);  

  $evc_init_reminder_form = array(
    'value' => $form_state['values']['evc_init_reminder_email_field']['value'],
    'format' => $form_state['values']['evc_init_reminder_email_field']['format'],
  );
  variable_set('evc_init_reminder_email_field', $evc_init_reminder_form);  

  $evc_annual_verification_form = array(
    'value' => $form_state['values']['evc_annual_verification_email_field']['value'],
    'format' => $form_state['values']['evc_annual_verification_email_field']['format'],
  );
  variable_set('evc_annual_verification_email_field', $evc_annual_verification_form); 

  $evc_annual_verification_user_form = array(
    'value' => $form_state['values']['evc_annual_verification_user_email_field']['value'],
    'format' => $form_state['values']['evc_annual_verification_user_email_field']['format'],
  );
  variable_set('evc_annual_verification_user_email_field', $evc_annual_verification_user_form); 

  $evc_confirmation_reminder_form = array(
    'value' => $form_state['values']['evc_confirmation_reminder_email_field']['value'],
    'format' => $form_state['values']['evc_confirmation_reminder_email_field']['format'],
  );
  variable_set('evc_confirmation_reminder_email_field', $evc_confirmation_reminder_form); 

  $evc_noneresponse_user_form = array(
    'value' => $form_state['values']['evc_nonresponse_user_email_field']['value'],
    'format' => $form_state['values']['evc_nonresponse_user_email_field']['format'],
  );
  variable_set('evc_nonresponse_user_email_field', $evc_noneresponse_user_form); 

  $password_7_days_form = array(
    'value' => $form_state['values']['password_7_days_email_field']['value'],
    'format' => $form_state['values']['password_7_days_email_field']['format'],
  );
  variable_set('password_7_days_email_field', $password_7_days_form); 

  $evc_init_reminder_accountholder_form = array(
    'value' => $form_state['values']['evc_init_reminder_accountholder_email_field']['value'],
    'format' => $form_state['values']['evc_init_reminder_accountholder_email_field']['format'],
  );
  variable_set('evc_init_reminder_accountholder_email_field', $evc_init_reminder_accountholder_form); 

  $evc_annual_verification_user_reminder_email_form = array(
    'value' => $form_state['values']['evc_annual_verification_user_reminder_email_field']['value'],
    'format' => $form_state['values']['evc_annual_verification_user_reminder_email_field']['format'],
  );
  variable_set('evc_annual_verification_user_reminder_email_field', $evc_annual_verification_user_reminder_email_form); 

  $evc_annual_verification_evc_reminder_email_form = array(
    'value' => $form_state['values']['evc_annual_verification_evc_email_field']['value'],
    'format' => $form_state['values']['evc_annual_verification_evc_email_field']['format'],
  );
  variable_set('evc_annual_verification_evc_email_field', $evc_annual_verification_evc_reminder_email_form); 
  
  variable_set('user_mail_password_reset_body', $form_state['values']['user_mail_password_reset_subject']);
  variable_set('user_mail_password_reset_body', $form_state['values']['user_mail_password_reset_body']);  
}
