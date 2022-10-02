<?php

function tw_registration_resend_email() {
    $url = $_SERVER['REQUEST_URI'];
    $url = explode('/', $url);
    if(isset($url[5])) {
        $fulluser = user_load($url[5]);
        $url = user_pass_reset_url($fulluser) . '?gen=resend';
        watchdog('tw_registration', 'resent email confirmation url is ' . $url, array(), WATCHDOG_INFO, NULL);
        $fulluser->field_password_email_sent['und'][0]['value'] = REQUEST_TIME;
        user_save($fulluser);
        $acc_validate_body = variable_get('account_validation_email');
        $acc_validate_body_val = array($acc_validate_body['value']);
        $acc_validate_body_val['0'] = str_replace("[Verify Account Link]", $url, $acc_validate_body_val['0']);
        $acc_validate_body_val['0'] = token_replace($acc_validate_body_val['0'], array('user' => $fulluser), array('sanitize' => FALSE, 'clear' => TRUE));
        drupal_mail('tw_registration', 'mymail', $fulluser->mail, language_default(), $params = array('emailbody' => $acc_validate_body_val, 'link' => $url), $from = NULL, $send = TRUE);
        drupal_goto('/admin/help-desk/registrations/');
    } else {
        drupal_set_message('User ID not specified', 'error', TRUE);
        drupal_goto('/admin/help-desk/registrations/');
    }
}

function tw_registration_dna($UID = NULL, $referrer = NULL) {
    $url = $_SERVER['REQUEST_URI'];
    $url = explode('/', $url);
    if(isset($url[5])) {
        $fulluser = user_load($url[5]);
        $dnaterm = taxonomy_get_term_by_name('Do Not Approve', 'user_status');
        $dnaterm = array_shift($dnaterm);
        $account_state = taxonomy_get_term_by_name('Removed', 'account_states');
        $account_state = array_shift($account_state);
        $fulluser->field_user_status['und'][0]['tid'] = $dnaterm->tid;
        $fulluser->field_account_states['und'][0]['tid'] = $account_state->tid;
        user_save($fulluser);
        $data = array(
            'uid' => $fulluser->uid,
            'type' => 'do_not_approve',
            'log' => 'User was set to Do Not Approve by ' . $_SESSION['currentuid'],
            'timestamp' => REQUEST_TIME,
            'name' => $fulluser->name,
            'account_state' => $fulluser->status,
            'current_account_status' => '',
            'old_account_status'  =>'',
            'account_type' => NULL,
            'author' => $_SESSION['currentuid'],
        );
        drupal_write_record('tw_user_history', $data);
        if ($referrer === NULL) {
            drupal_goto('/admin/help-desk/registrations/');
        } elseif ($referrer == 'postdue') {
            $dna_body = variable_get('do_not_approve_email_field');
            $dna_body_val = array($dna_body['value']);
            $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
            drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val, 'link' => $url), $from = NULL, $send = TRUE);
            drupal_goto('/admin/help-desk/evc-postdue/');
        } elseif ($referrer == 'vip') {
            $dna_body = variable_get('do_not_approve_email_field');
            $dna_body_val = array($dna_body['value']);
            $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
            drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val, 'link' => $url), $from = NULL, $send = TRUE);
            drupal_goto('/admin/help-desk/vip-pre-evc-due');
        } elseif ($referrer == 'inactive') {
            $dna_body = variable_get('do_not_approve_email_field');
            $dna_body_val = array($dna_body['value']);
            $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
            drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val, 'link' => $url), $from = NULL, $send = TRUE);
            drupal_goto('/admin/help-desk/inactive-users');
        } elseif (is_numeric($referrer)) {
            $dna_body = variable_get('do_not_approve_email_field');
            $dna_body_val = array($dna_body['value']);
            $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
            drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val, 'link' => $url), $from = NULL, $send = TRUE);
            drupal_goto('/user' . '/' . $referrer . '/edit');
        }
    }
}

function tw_registration_evc_updated($UID = NULL, $referrer = NULL) {
    $url = $_SERVER['REQUEST_URI'];
    $url = explode('/', $url);
    if(isset($url[5])) {
        $fulluser = user_load($url[5]);
        module_load_include('inc', 'profile2_page', 'profile2_page');
        $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
        tw_registration_evc_due($fulluser->uid, $fulluser->mail, $profile->field_verification_contact_email['und'][0]['safe_value'], 'updated');
        if ($referrer === NULL) {
            drupal_goto('/admin/help-desk/evc');
        } elseif ($referrer == 'vip') {
            drupal_goto('/admin/help-desk/vip-evc-edit');
        } elseif ($referrer == 'annual') {
            drupal_goto('/admin/help-desk/evc-annual');
        }
        return;
    }
}

function tw_registration_evc_approved() {
    // NEED TO ADD TIMESTAMP OF THIS EVENT SO THAT 365 RE-VERIFICATION TIMER CAN BE CHECKED
    $url = $_SERVER['REQUEST_URI'];
    $url = explode('/', $url);
    if(isset($url[5])) {
        $fulluser = user_load($url[5]);
        $role = array();
        $roleone = user_role_load_by_name('Pre-Authenticated');
        $roletwo = user_role_load_by_name('Awaiting Approval');
        //user_multiple_role_edit(array($fulluser->uid), 'remove_role', $roleone->rid);
        //user_multiple_role_edit(array($fulluser->uid), 'remove_role', $roletwo->rid);
        //The Drupal function user_multiple_role_edit did not work for both roles (it would remove one, but not other unless function was ran twice).  
        //Thus, we are just nuking the roles array and re-creating it to ensure it is removed.  This may be a problem down the line if other roles are included with new users.
        //unset($fulluser->roles);
        //$fulluser->roles = array();
        
        $term = taxonomy_get_term_by_name('Approved', 'user_status');
        $term = array_shift($term);
        $fulluser->field_user_status['und'][0]['tid'] = $term->tid;
        $term2 = taxonomy_get_term_by_name('Active', 'account_states');
        $term2 = array_shift($term2);
        $fulluser->field_account_states['und'][0]['tid'] = $term2->tid;
        if(isset($url[6])) {
            if ($url[6] == 'vip') { 
                $vetted_term = taxonomy_get_term_by_name('EVC Vetted', 'evc_status');
                $vetted_term = array_shift($vetted_term);
                $fulluser->field_evc_status['und'][0]['tid'] = $vetted_term->tid;
                $query = db_update('tw_registration_evc_email')
                ->fields(array('verification_date' => REQUEST_TIME, 'verification_status' => 1))
                ->condition('uid', $fulluser->uid)
                ->execute();
                $redirect = '/admin/help-desk/vip';
            } elseif ($url[6] == 'vip-approve') {
                $vetted_term = taxonomy_get_term_by_name('EVC Vetted', 'evc_status');
                $vetted_term = array_shift($vetted_term);
                $fulluser->field_evc_status['und'][0]['tid'] = $vetted_term->tid;
                $query = db_update('tw_registration_evc_email')
                ->fields(array('verification_date' => REQUEST_TIME, 'verification_status' => 1))
                ->condition('uid', $fulluser->uid)
                ->execute();
                $redirect = '/admin/help-desk/vip-evc-due';
            }
        } else {
            $redirect = '/admin/help-desk/evc-confirmation';
        }
        user_save($fulluser);
        $evc_approved_body = variable_get('evc_approved_email_field');
        $evc_approved_body_val = array($evc_approved_body['value']);
        $evc_approved_body_val['0'] = token_replace($evc_approved_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
        drupal_mail('tw_registration', 'evc_account_approved', $fulluser->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $evc_approved_body_val), $from = NULL, $send = TRUE);
        drupal_goto($redirect);
    }
}

function tw_registration_helper($uid = NULL, $action = NULL) {
    if (!is_null($uid) || !is_null($action)) {
        // Load user
        $fulluser = user_load($uid);
        // Set all values to NULL to ensure only fields we need to change get changed
        $dstatus = NULL;
        $account_status = NULL;
        $account_state = NULL;
        $evc_status = NULL;
        $VIP = NULL;
        $log = NULL;

        // Based on value of action, we will determine what fields will be changed.
        switch ($action) {
            case 'nonresponsive':
                $account_status = 'Do Not Approve';
                $account_state = 'Removed';
                $log = 'User set to Initial Registration - Non Responsive';
                $dna_body = variable_get('do_not_approve_email_field');
                $dna_body_val = array($dna_body['value']);
                $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val), $from = NULL, $send = TRUE);
                break;
            case 'evcdenied':
                //$account_status = 'Do Not Approve';
                //$account_state = 'Removed';
                $evc_status = 'EVC Denied';
                $evc_conf_body = variable_get('evc_denied_email_field');
                $evc_conf_body_val = array($evc_conf_body['value']);
                $evc_conf_body_val['0'] = token_replace($evc_conf_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'evc_denied', $fulluser->mail, language_default(), $params = array('emailbody' => $evc_conf_body_val), $from = NULL, $send = TRUE);
                $log = 'User set to EVC Denied Access';
                break;
            case 'evcnonresponsive':
                $account_status = 'Do Not Approve';
                $account_state = 'Removed';
                $evc_status = 'EVC Due';
                $dna_body = variable_get('do_not_approve_email_field');
                $dna_body_val = array($dna_body['value']);
                $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val), $from = NULL, $send = TRUE);
                $log = 'User set to EVC Non-Responsive';
                break;
            case 'vipcordenied':
                $account_status = 'Do Not Approve';
                $account_state = 'Removed';
                $evc_status = 'EVC Denied';
                $dna_body = variable_get('do_not_approve_email_field');
                $dna_body_val = array($dna_body['value']);
                $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val), $from = NULL, $send = TRUE);
                $log = 'User set to VIP - COR Denied Access';
                break;
            case 'inactivity':
                $dstatus = 0;
                $account_status = 'Do Not Approve';
                $account_state = 'Removed';
                $dna_body = variable_get('do_not_approve_email_field');
                $dna_body_val = array($dna_body['value']);
                $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val), $from = NULL, $send = TRUE);
                $log = 'User set to Inactivity - Non-Responsive';
                break;
            case 'passwordexpired':
                $account_status = 'Do Not Approve';
                $account_state = 'Removed';
                $dna_body = variable_get('do_not_approve_email_field');
                $dna_body_val = array($dna_body['value']);
                $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'do_not_approve', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val), $from = NULL, $send = TRUE);
                $log = 'User set to Password Expired';
                break;
            case 'approved':
                $dstatus = 1;
                $account_status = 'Approved';
                $account_state = 'Active';
                $evc_status = 'EVC Vetted';
                tw_registration_remove_role_from_user($fulluser, 'Pre-Authenticated');
                tw_registration_remove_role_from_user($fulluser, 'Awaiting Approval');
                $query = db_update('tw_registration_evc_email')
                    ->fields(array('verification_date' => REQUEST_TIME, 'verification_status' => 1))
                    ->condition('uid', $fulluser->uid)
                    ->execute();
                // Determining if user subscribed to Whats New during registration
                $profile = profile2_load_by_user($fulluser->uid, 'my_tripwire_subscriptions');
                if (isset($profile->field_subscribe_to_what_s_new['und'])) {
                    if ($profile->field_subscribe_to_what_s_new['und'][0]['value'] == 1) {
                        $var = db_query('SELECT value FROM {variable} WHERE name = :name', array(':name' => 'wn_emails'))->fetchField();
                        $emaillist = unserialize($var);
                        $personalprofile = profile2_load_by_user($fulluser->uid, 'personal_information');
                        $wn_sub_body = array();
                        $wn_sub_body[] = "<p>A newly approved TRIPwire user has subscribed to the monthly What's New email list.</p><p><b>Name</b>:" . $personalprofile->field_first_name['und'][0]['value'] . " " . $personalprofile->field_last_name['und'][0]['value'] . "</p><p><b>Email</b>:" . $fulluser->mail . "</p>";
                        drupal_mail('tw_registration', 'wn_emails', $emaillist, language_default(), $params = array('emailbody' => $wn_sub_body), $from = NULL, $send = TRUE);
                    }
                }
                //If HSIN user, need to change the email we send
                if (in_array("HSIN", $fulluser->roles)) {
                  tw_registration_remove_role_from_user($fulluser, 'HSIN Pre-Authenticated');
                  $hsin_approved_body = variable_get('account_approved_hsin_email_field');
		  $hsin_approved_body_val = array($hsin_approved_body['value']);
		  $hsin_approved_body_val['0'] = token_replace($hsin_approved_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                  drupal_mail('tw_registration', 'hsin_evc_account_approved', $fulluser->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $hsin_approved_body_val), $from = NULL, $send = TRUE);
                } else {
                  $resend_url = user_pass_reset_url($fulluser) . '?gen=resend';
                  $evc_approved_body = variable_get('evc_approved_email_field');
                  $evc_approved_body_val = array($evc_approved_body['value']);
                  $evc_approved_body_val['0'] = str_replace("[Verify Account Link]", $resend_url, $evc_approved_body_val['0']);
                  $evc_approved_body_val['0'] = token_replace($evc_approved_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                  drupal_mail('tw_registration', 'evc_account_approved', $fulluser->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $evc_approved_body_val), $from = NULL, $send = TRUE);
                }
                
                $log = 'User set to Account Approved';
                break;
            case 'evc_verified':
                $evc_status = 'EVC Vetted';
                $query = db_update('tw_registration_evc_email')
                    ->fields(array('verification_date' => REQUEST_TIME, 'verification_status' => 1))
                    ->condition('uid', $fulluser->uid)
                    ->execute();
                $evc_approved_body = variable_get('evc_confirmation_reminder_email_field');
                $evc_approved_body_val = array($evc_approved_body['value']);
                $evc_approved_body_val['0'] = token_replace($evc_approved_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'annual_evc_complete', $fulluser->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $evc_approved_body_val), $from = NULL, $send = TRUE);
                $log = 'User set to EVC Verified';
                break;
            case 'resend':
                $url = user_pass_reset_url($fulluser) . '?gen=resend';
                $fulluser->field_password_email_sent['und'][0]['value'] = REQUEST_TIME;
                user_save($fulluser);
                $resend_body = variable_get('account_validation_email');
                $resend_body_val = array($resend_body['value']);
                $resend_url = user_pass_reset_url($fulluser) . '?gen=resend';
                $resend_body_val['0'] = str_replace("[Verify Account Link]", $resend_url, $resend_body_val['0']);
                $resend_body_val['0'] = token_replace($resend_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'mymail', $fulluser->mail, language_default(), $params = array('emailbody' => $resend_body_val), $from = NULL, $send = TRUE);
                $log = 'User was sent the Initial Email Verification Due (to Account Holder) email';
                break;
            case 'evcconfirmationreminder':
                $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
                if (isset($profile->field_verification_contact_email)) {
                    $evc_timestamp = REQUEST_TIME;
                    tw_registration_evc_due($fulluser->uid, $fulluser->mail, $profile->field_verification_contact_email['und'][0]['safe_value'], $evc_timestamp);
                    $log = 'USer was sent the Initial Employment Verification Due (to EVC and Account Holder) emails';
                } else {
                    $log = 'EVC Confirmation Reminder attempted to send, but EVC profile data was missing so email was not sent';
                    drupal_set_message("EVC information not defined in user profile. Please add EVC contact information to this user first, and then try again.", 'error');
                }
                
            break;
            case 'evcconfirm': 
                $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
                if (isset($profile->field_verification_contact_email)) {
                    $evc_timestamp = REQUEST_TIME;
                    tw_registration_evc_due($fulluser->uid, $fulluser->mail, $profile->field_verification_contact_email['und'][0]['safe_value'], $evc_timestamp);
                    $log = 'EVC Confirmation Reminder';
                } else {
                    $log = 'EVC Confirmation Reminder attempted to send, but EVC profile data was missing so email was not sent';
                    drupal_set_message("EVC information not defined in user profile. Please add EVC contact information to this user first, and then try again.", 'error');
                }
                
                break;
            case 'evc_nine_day':
                module_load_include('check.inc', 'tw_registration');
                tw_registration_nine_day($fulluser->uid, 'initial');
                $log = 'User was sent the Initial Employment Verification Due Reminder (9-Day to EVC and Account Holder) emails';
                break;
            case 'evc_fourteen_day':
                module_load_include('check.inc', 'tw_registration');
                tw_registration_fourteen_day($fulluser->uid);
                $log = 'User was sent the Initial Employment Verification Overdue (14-Day to Account Holder) email';
                break;
            case 'evc_annual_pending':
                // Email to user
                $evcpending_to_accountholder = variable_get('evc_annual_verification_user_reminder_email_field');
                $evcpending_to_accountholder_val = array($evcpending_to_accountholder['value']);
                $evcpending_to_accountholder_val['0'] = token_replace($evcpending_to_accountholder_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'evc_annual_verification_user', $fulluser->mail, language_default(), $params = array('emailbody' => $evcpending_to_accountholder_val), $from = NULL, $send = TRUE);

                // Email to EVC
                $evc_timestamp = REQUEST_TIME;
                global $base_url;
                $approve_link = $base_url . '/evc-verify/' . $uid . '/' . $evc_timestamp . '/approve';
                $deny_link = $base_url . '/evc-verify/' . $uid . '/' . $evc_timestamp . '/deny';
                $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
                $evcpending_to_evc = variable_get('evc_annual_verification_email_field');
                $evcpending_to_evc_val = array($evcpending_to_evc['value']);
                $evcpending_to_evc_val['0'] = str_replace("[EVC Verified Link]", $approve_link, $evcpending_to_evc_val['0']);
                $evcpending_to_evc_val['0'] = str_replace("[EVC Denied Link]", $deny_link, $evcpending_to_evc_val['0']);
                $evcpending_to_evc_val['0'] = token_replace($evcpending_to_evc_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'evc_annual_verification', $profile->field_verification_contact_email['und'][0]['safe_value'], language_default(), $params = array('emailbody' => $evcpending_to_evc_val), $from = NULL, $send = TRUE);
                $log = 'User was sent the Annual Employment Verification Pending (to EVC and Account Holder) emails';
                break;
            case 'evc_annual_pending_manual':
                // This is a copy of evc_annual_pending, but for use with the manual dropdown field in the user edit.  We did this because of needing a redirect here
                // Email to user
                $evcpending_to_accountholder = variable_get('evc_annual_verification_user_reminder_email_field');
                $evcpending_to_accountholder_val = array($evcpending_to_accountholder['value']);
                $evcpending_to_accountholder_val['0'] = token_replace($evcpending_to_accountholder_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'evc_annual_verification_user', $fulluser->mail, language_default(), $params = array('emailbody' => $evcpending_to_accountholder_val), $from = NULL, $send = TRUE);

                // Email to EVC
                $evc_timestamp = REQUEST_TIME;
                global $base_url;
                $approve_link = $base_url . '/evc-verify/' . $uid . '/' . $evc_timestamp . '/approve';
                $deny_link = $base_url . '/evc-verify/' . $uid . '/' . $evc_timestamp . '/deny';
                $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
                $evcpending_to_evc = variable_get('evc_annual_verification_email_field');
                $evcpending_to_evc_val = array($evcpending_to_evc['value']);
                $evcpending_to_evc_val['0'] = str_replace("[EVC Verified Link]", $approve_link, $evcpending_to_evc_val['0']);
                $evcpending_to_evc_val['0'] = str_replace("[EVC Denied Link]", $deny_link, $evcpending_to_evc_val['0']);
                $evcpending_to_evc_val['0'] = token_replace($evcpending_to_evc_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'evc_annual_verification', $profile->field_verification_contact_email['und'][0]['safe_value'], language_default(), $params = array('emailbody' => $evcpending_to_evc_val), $from = NULL, $send = TRUE);
                $log = 'User was sent the Annual Employment Verification Pending (to EVC and Account Holder) emails';
                break;
            case 'evc_annual_nine_day':
                module_load_include('check.inc', 'tw_registration');
                tw_registration_nine_day($fulluser->uid, 'annual');
                $log = 'User was sent the Annual Employment Verification Pending Reminder (9-Day to EVC and Account Holder) emails';
                break;
            case 'evc_annual_fourteen_day':
                $account_state = 'Locked';
                module_load_include('check.inc', 'tw_registration');
                tw_registration_fourteen_day($fulluser->uid, 'annual');
                $log = 'EVC Non-Response email logged to database, EVC Status set to EVC Overdue, and User Account State set to Locked ';
                break;
            case 'evc_non_responsive':
                $account_state = 'Locked';
                $dna_body = variable_get('evc_nonresponse_user_email_field');
                $dna_body_val = array($dna_body['value']);
                $dna_body_val['0'] = token_replace($dna_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'evc_nonresponse_user', $fulluser->mail, language_default(), $params = array('emailbody' => $dna_body_val), $from = NULL, $send = TRUE);
                $log = 'EVC Non-Response email logged to database, EVC Status set to EVC Overdue, and User Account State set to Locked ';
                break;
            case 'inactivity_warning':
                $inactivity_email = variable_get('inactivity_warning_email_field');
                $inactivity_email_body_val = array($inactivity_email['value']);
                $inactivity_email_body_val['0'] = token_replace($inactivity_email_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_registration', 'inactivity_warning', $fulluser->mail, language_default(), $params = array('emailbody' => $inactivity_email_body_val), $from = NULL, $send = TRUE);
                $log = 'Account Inactivity Warning email';
                break;
            case 'password_reset_due':
                $account_locked_email_body = variable_get('account_locked_email_field');
                $account_locked_email_body_val = array($account_locked_email_body['value']);
                $account_locked_email_body_val['0'] = token_replace($account_locked_email_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                drupal_mail('tw_password_mgmt', 'locked', $fulluser->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $account_locked_email_body_val), $from = NULL, $send = TRUE);
                $log = 'Password Reset Due';
                break;
            case 'evc_updated':
                $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
                if (isset($profile->field_verification_contact_email)) {
                    $account_status = 'Awaiting Approval';
                    $account_state = 'Inactive';
                    $evc_status = 'EVC Due';
                    // Removing roles from user
                    $user=user_load($fulluser->uid);
                    unset($user->roles);
                    $user->roles = array();
                    
                    // Adding back roles to user
                    $roles = array("Awaiting Approval", "Pre-Authenticated");
                    foreach($roles as $role) {
                        $role = user_role_load_by_name($role);
                        $user->roles[$role->rid] = $role->name;
                    }
                    $evc_timestamp = REQUEST_TIME;
                    tw_registration_evc_due($fulluser->uid, $fulluser->mail, $profile->field_verification_contact_email['und'][0]['safe_value'], $evc_timestamp);
                    $log = 'User set to EVC Updated - Verification Required';
                    $evcupdated_email = variable_get('evc_updated_email_field');
                    $evcupdated_email_body_val = array($evcupdated_email['value']);
                    $evcupdated_email_body_val['0'] = token_replace($evcupdated_email_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
                    drupal_mail('tw_registration', 'evc_updated', $fulluser->mail, language_default(), $params = array('emailbody' => $evcupdated_email_body_val), $from = NULL, $send = TRUE);
                } else {
                    $log = 'EVC Confirmation Reminder attempted to send, but EVC profile data was missing so email was not sent';
                    drupal_set_message("EVC information not defined in user profile. Please add EVC contact information to this user first, and then try again.", 'error');
                }
                break;
                case 'hsin_unbind':
                    db_delete('authmap')
                    ->condition('uid', $uid)
                    ->condition('module', 'simplesamlphp_auth')
                    ->execute();
                    $role_name = 'HSIN';
                    tw_registration_remove_role_from_user($fulluser, 'HSIN');
                    tw_registration_remove_role_from_user($fulluser, 'HSIN Pre-Authenticated');
                    $log = 'HSIN unbind for user';
                break;
        }

        if (!is_null($dstatus)) {
            $fulluser->status = $dstatus;
        }
        if (!is_null($account_status)) {
            $term = taxonomy_get_term_by_name($account_status, 'user_status');
            $term = array_shift($term);
            $fulluser->field_user_status['und'][0]['tid'] = $term->tid;
        }
        if (!is_null($account_state)) {
            $term2 = taxonomy_get_term_by_name($account_state, 'account_states');
            $term2 = array_shift($term2);
            $fulluser->field_account_states['und'][0]['tid'] = $term2->tid;
        }
        if (!is_null($evc_status)) {
            $vetted_term = taxonomy_get_term_by_name($evc_status, 'evc_status');
            $vetted_term = array_shift($vetted_term);
            $fulluser->field_evc_status['und'][0]['tid'] = $vetted_term->tid;
        }
        user_save($fulluser);

        $data = array(
            'uid' => $fulluser->uid,
            'type' => 'do_not_approve',
            'log' => $log . ' by ' . $_SESSION['currentuid'],
            'timestamp' => REQUEST_TIME,
            'name' => $fulluser->name,
            'account_state' => $fulluser->status,
            'current_account_status' => '',
            'old_account_status'  =>'',
            'account_type' => NULL,
            'author' => $_SESSION['currentuid'],
        );
        drupal_write_record('tw_user_history', $data);
        // Added this if statement to avoid redirecting the annual evc check in function tw_registration_check_evc()
        if ($action !== 'evc_annual_pending') {
            $redirect = 'user/' . $fulluser->uid . '/edit';
            drupal_goto($redirect);
        }
        
    }
}

/**
 * Remove a role from a user.
 *
 * @param $user
 *   User object or user ID.
 * @param $role_name
 *   String value of role to be removed.
 */
function tw_registration_remove_role_from_user($user, $role_name) {
    // For convenience, we'll allow user ids as well as full user objects.
    if (is_numeric($user)) {
      $user = user_load($user);
    }
    // Only remove the role if the user already has it.
    $key = array_search($role_name, $user->roles);
    if ($key == TRUE) {
      // Get the rid from the roles table.
      $roles = user_roles(TRUE);
      $rid = array_search($role_name, $roles);
      if ($rid != FALSE) {
        // Make a copy of the roles array, without the deleted one.
        $new_roles = array();
        foreach($user->roles as $id => $name) {
          if ($id != $rid) {
            $new_roles[$id] = $name;
          }
        }
        user_save($user, array('roles' => $new_roles));
        if (isset($_SESSION['currentuid'])) {
          $authorid = $_SESSION['currentuid'];
        } else {
          $authorid = '72';
        }

        $data = array(
            'uid' => $user->uid,
            'type' => 'do_not_approve',
            'log' => 'Username ' . $user->name . ' had this role removed ' . $role_name . ' by ' . $_SESSION['currentuid'],
            'timestamp' => REQUEST_TIME,
            'name' => $user->name,
            'account_state' => $user->status,
            'current_account_status' => '',
            'old_account_status'  =>'',
            'account_type' => NULL,
            'author' => $authorid,
        );
        drupal_write_record('tw_user_history', $data);
      }
    }
  }

  function tw_registration_add_hsin_role($uid) {
    $role = user_role_load_by_name("HSIN");
    $uname = user_load_by_name($uid);
    user_multiple_role_edit(array($uname->uid), 'add_role', $role->rid);
  }

  function tw_registration_hsin_user_verify($username, $password) {
      $result = user_authenticate($_POST['name'], $_POST['pass']);
      if (!empty($result)) {
        global $user;
        // Adding HSIN role to user if they don't already have it
        tw_registration_add_hsin_role($_POST['name']);
        // Delete authmap entry for HSIN account since we do not need it anymore
        db_delete('authmap')->condition('uid', $user->uid)->execute();
        // Insert new authmap entry for the authenticated Drupal account
        db_insert('authmap')->fields(array('uid' => $result, 'authname' => $_SESSION['fed_id'], 'module' => 'simplesamlphp_auth'))->execute();
        // Delete Drupal user that simplesaml created
        user_delete($user->uid);
        $format = 'Thank you for connecting your HSIN account to your TRIPwire account.  Please <a href="/saml_login">login with your HSIN account</a> to access TRIPwire.';
        setcookie('my_message', sprintf($format), time() + (86400 * 30), "/");
        module_load_include('pages.inc', 'user');
        user_logout();
      } else {
        drupal_set_message('Incorrect authentication information entered. Please try again.', 'error');
        drupal_goto('binding');
      }
  }

  function tw_registration_binding() {
    drupal_add_css(drupal_get_path('module', 'tw_registration') . '/css/binding.css', array('weight' => CSS_THEME));
    $html = '';  
    $introtext = 'Welcome to TRIP<span class="wire">wire</span>. Please select one of the following methods to complete your profile for the HSIN Partner Account Registration.  If you are a member of TRIP<span class="wire">wire</span>, please complete the one-time login with your TRIP<span class="wire">wire</span> credentials below.  If not, please select one of the alternative options.';
    $hsinvals = simplesamlphp_auth_get_attributes();
    if (!empty($hsinvals)) {
        $_SESSION['fed_id'] = $hsinvals['gfipm:2.0:user:FederationId'][0];
        //user_cookie_save(array('fed_id' => $hsinvals['gfipm:2.0:user:FederationId'][0]));
    } else {
        //user_cookie_save(array('fed_id' => 'fake value'));
        $_SESSION['fed_id'] = 'test1234';
    }
    $_GET['destination'] = 'binding';
    if (user_is_logged_in()) {
       //module_load_include('pages.inc', 'user');
        //user_logout(); 
    }
    
    $options = '<div class="options">';
    $options .= '<div class="existing-account option-block"><div class="option-title"><h2>Use Existing Account</h2></div><div class="option-body"><form action="hsin-authenticate" method="POST"><div class="form-item form-type-textfield form-item-name">
                    <label for="edit-name">Username <span class="form-required" title="This field is required.">*</span></label>
                <input type="text" id="edit-name" name="name" value="" size="60" maxlength="60" class="form-text required" autocomplete="off" style="background-image: url(&quot;data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAASCAYAAABSO15qAAAAAXNSR0IArs4c6QAAAPhJREFUOBHlU70KgzAQPlMhEvoQTg6OPoOjT+JWOnRqkUKHgqWP4OQbOPokTk6OTkVULNSLVc62oJmbIdzd95NcuGjX2/3YVI/Ts+t0WLE2ut5xsQ0O+90F6UxFjAI8qNcEGONia08e6MNONYwCS7EQAizLmtGUDEzTBNd1fxsYhjEBnHPQNG3KKTYV34F8ec/zwHEciOMYyrIE3/ehKAqIoggo9inGXKmFXwbyBkmSQJqmUNe15IRhCG3byphitm1/eUzDM4qR0TTNjEixGdAnSi3keS5vSk2UDKqqgizLqB4YzvassiKhGtZ/jDMtLOnHz7TE+yf8BaDZXA509yeBAAAAAElFTkSuQmCC&quot;); background-repeat: no-repeat; background-attachment: scroll; background-size: 16px 18px; background-position: 98% 50%; cursor: auto;">
                <div class="description">Enter your TRIPwire username.</div>
                </div><div class="form-item form-type-password form-item-pass">
                <label for="edit-pass">Password <span class="form-required" title="This field is required.">*</span></label>
                <input type="password" id="edit-pass" name="pass" size="60" maxlength="128" class="form-text required" autocomplete="off" style="background-image: url(&quot;data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAASCAYAAABSO15qAAAAAXNSR0IArs4c6QAAAPhJREFUOBHlU70KgzAQPlMhEvoQTg6OPoOjT+JWOnRqkUKHgqWP4OQbOPokTk6OTkVULNSLVc62oJmbIdzd95NcuGjX2/3YVI/Ts+t0WLE2ut5xsQ0O+90F6UxFjAI8qNcEGONia08e6MNONYwCS7EQAizLmtGUDEzTBNd1fxsYhjEBnHPQNG3KKTYV34F8ec/zwHEciOMYyrIE3/ehKAqIoggo9inGXKmFXwbyBkmSQJqmUNe15IRhCG3byphitm1/eUzDM4qR0TTNjEixGdAnSi3keS5vSk2UDKqqgizLqB4YzvassiKhGtZ/jDMtLOnHz7TE+yf8BaDZXA509yeBAAAAAElFTkSuQmCC&quot;); background-repeat: no-repeat; background-attachment: scroll; background-size: 16px 18px; background-position: 98% 50%;">
                <div class="description">Enter the password that accompanies your username.</div>
                </div>
                <input type="submit" id="edit-submit" name="op" value="Log in" class="form-submit">
                </form></div></div>';
    $options .= '  <div class="new-user option-block"><div class="option-title"><h2>Create New User Login</h2></div><div class="option-body"><p>If you are not already a member of TRIP<span class="wire">wire</span>, please proceed to register to the full TRIP<span class="wire">wire</span> website below.</p><p><a href="/hsinlogout?hsinuser"><button type="button">Register</button></a></p></div></div>';
    $options .= '</div>';
    $footer = '<div class="footer"><p>If you believe you have reached this page in error, please contact the TRIP<span class="wire">wire</span> Help Desk by email at <a href="mailto:tripwhirehelp@dhs.gov">tripwhirehelp@dhs.gov</a> or by phone at 1-866-430-0162 from Monday - Friday 8 AM to 5PM EST.<p></div>';
    

    //$elements = tw_registration_fake_reg();
    //$form = drupal_render($elements);
    // TWDEV-95: Setting hsinorigin cookie so that if user registers after authenticating with HSIN we know it is them
    global $user;
    setcookie('hsinorigin',$user->uid);
    $html .= $introtext . $options . $footer;
      return $html;
  }

  function tw_registration_hsin_thanks() {
      global $user;
      if (!in_array('HSIN Pre-Authenticated', $user->roles)) {
          return 'Access Denied.';
      }
      // Sending out initial registration email to verify account
      $url = user_pass_reset_url($fulluser) . '?gen=newuser';
      $acc_validate_body = variable_get('account_validation_email');
      $acc_validate_body_val = array($acc_validate_body['value']);
      $acc_validate_body_val['0'] = str_replace("[Verify Account Link]", $url, $acc_validate_body_val['0']);
      $acc_validate_body_val['0'] = token_replace($acc_validate_body_val['0'], array('user' => $fulluser), array('sanitize' => FALSE, 'clear' => TRUE));
      drupal_mail('tw_registration', 'mymail', $user->mail, language_default(), $params = $params = array('emailbody' => $acc_validate_body_val), $from = NULL, $send = TRUE);
      //Removing HSIN role
      tw_registration_remove_role_from_user($user, 'HSIN Pre-Authenticated');
      $format = 'All new users of TRIPwire must register and provide an Employment Verification Contact (EVC) that confirms a user\'s "need-to-know." Upon registering for TRIPwire, you will not be able to immediately login to the site using HSIN and will need to complete all the registration activities first. Please refer to our <a href="/faqs" target="_blank">FAQ page</a> or contact the Help Desk.';
      setcookie('my_message', sprintf($format), time() + (86400 * 30), "/");
      $message = "Thanks for registering";
      module_load_include('pages.inc', 'user');
      user_logout();
      return $message;
  }
 

function tw_registration_hsin_logout() {
  $html = '<p style="font-size: 28px; margin-top: 20px;"><a href="/user/register?hsinuser">Click here to register for a new account to bind to your HSIN account</a>.</p>';
  drupal_goto('hsinlogoutnow');

  return $html;
}
