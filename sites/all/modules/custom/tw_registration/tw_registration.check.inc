<?php

function tw_registration_check_users() {
    $check = variable_get('enable_evc_check');
    if (!$check) {
        return;
    }
    $today = REQUEST_TIME;
    $nine_days = strtotime('-9 days', $today);
    $fourteen_days = strtotime('-14 days', $today);
    
    $nine_result = db_select('tw_registration_evc_email', 'c')
        ->fields('c') 
        ->condition('verification_date', NULL)
        ->condition('evc_hash', $nine_days, '<')
        ->condition('nineday_date', NULL)
        ->execute()
        ->fetchAll();
    
    if (!empty($nine_result)) {
        foreach ($nine_result as $n) {
            $fulluser = user_load($n->uid);
            $approved_term = taxonomy_get_term_by_name('Approved', 'user_status');
            $approved_term = array_shift($approved_term);
            if (isset($fulluser->uid)) {
                if($fulluser->field_user_status['und'][0]['tid'] == $approved_term->tid) {
                    tw_registration_nine_day($fulluser->uid, "annual");
                } else {
                    tw_registration_nine_day($fulluser->uid);
                }
            } else {
                //dpm($n->uid . " is not found");
                // We delete the user since this is an orphaned UID.  
                $delete_empty_uid = db_delete('tw_registration_evc_email')
                    ->condition('uid', $n->uid)
                    ->execute();
            }
        }
    }

    $fourteen_result = db_select('tw_registration_evc_email', 'c')
    ->fields('c') 
    ->condition('verification_date', NULL)
    ->condition('evc_hash', $fourteen_days, '<')
    ->condition('fourteenday_date', NULL)
    ->condition('nineday_date', '', '<>')
    ->execute()
    ->fetchAll();

    if (!empty($fourteen_result)) {
        foreach ($fourteen_result as $n) {
            $fulluser = user_load($n->uid);
            if (isset($fulluser->uid)) {
                tw_registration_fourteen_day($fulluser->uid);
            }
        }
    }
}

function tw_registration_check_evc() {
    $today = REQUEST_TIME;
    $intlexpiration = strtotime('-180 days', $today);
    // International user check.  These users need to expire after just 6 months, per T2OM-59 
    $intlquery = "SELECT users_tw_registration_evc_email.uid AS users_tw_registration_evc_email_uid
    FROM 
    {tw_registration_evc_email} tw_registration_evc_email
    LEFT JOIN {users} users_tw_registration_evc_email ON tw_registration_evc_email.uid = users_tw_registration_evc_email.uid
    LEFT JOIN {field_data_field_user_status} users_tw_registration_evc_email__field_data_field_user_status ON users_tw_registration_evc_email.uid = users_tw_registration_evc_email__field_data_field_user_status.entity_id AND users_tw_registration_evc_email__field_data_field_user_status.field_user_status_tid = '4776'
    INNER JOIN {users_roles} users_tw_registration_evc_email__users_roles ON users_tw_registration_evc_email.uid = users_tw_registration_evc_email__users_roles.uid
    WHERE (( (tw_registration_evc_email.verification_date < $intlexpiration) AND (tw_registration_evc_email.verification_status = '1') AND (users_tw_registration_evc_email__field_data_field_user_status.field_user_status_tid IS NULL ) AND (users_tw_registration_evc_email__users_roles.rid = '14') ))";
    $intlqueryresult = db_query($intlquery);
    $result = $intlqueryresult->fetchCol();
    if (!empty($result)) {
        foreach ($result as $n) {
            _evc_expire_user($n);
        }
    }

    // Search for non-international users.  EFQ cannot access roles, but we will assume the verification date condition will guard against them showing up in this query.
    $expiration = strtotime('-365 days', $today);
    $query = db_select('tw_registration_evc_email', 'c')
        ->fields('c') 
        ->condition('verification_status', '1')
        ->condition('verification_date', $expiration, '<')
        ->execute()
        ->fetchAll();
    if (!empty($query)) {
        foreach ($query as $n) {
            _evc_expire_user($n);
        }
    }
}

function _evc_expire_user($n) {
    $term = taxonomy_get_term_by_name('EVC Overdue', 'evc_status');
            $term = array_shift($term);
            if (isset($n->uid)) {
                $fulluser = user_load($n->uid);
            } else {
                $fulluser = user_load($n);
            }
            $fulluser->field_evc_status['und'][0]['tid'] = $term->tid;
            user_save($fulluser);
            // If VIP user, skip sending emails
            //if (in_array('VIP', $fulluser->roles)) {
                //return;
            //}
            // Resetting db fields so that new email timer can be set
            $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
            tw_registration_evc_due($fulluser->uid, $fulluser->mail, $profile->field_verification_contact_email['und'][0]['safe_value'], 'annual');
            // Use tw_registration_evc_due function
}

function tw_registration_nine_day($uid, $type = NULL) {
    $fulluser = user_load($uid);
    $profile = profile2_load_by_user($uid, 'indicate_evc');
    // THESE ACCOUNTS ARE PAST 9 DAYS OF NOT BEING VERIFIED BY EVC. NOW NEED TO SEND EMAILS, AS OUTLINED IN 3f
    $evc_timestamp = REQUEST_TIME;
    global $base_url;
    $approve_link = $base_url . '/evc-verify/' . $uid . '/' . $evc_timestamp . '/approve';
    $deny_link = $base_url . '/evc-verify/' . $uid . '/' . $evc_timestamp . '/deny';

    if ($type == 'initial' || $type == NULL) {
        $evc_conf_body = variable_get('evc_nine_day_email_field');
        $evc_conf_body_val = array($evc_conf_body['value']);
        $evc_conf_body_val['0'] = str_replace("[EVC Verified Link]", $approve_link, $evc_conf_body_val['0']);
        $evc_conf_body_val['0'] = str_replace("[EVC Denied Link]", $deny_link, $evc_conf_body_val['0']);
        $evc_conf_body_val['0'] = token_replace($evc_conf_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
        $evc_action_body = variable_get('evc_action_required_email_field');
        $evc_action_body_val = array($evc_action_body['value']);
        $evc_action_body_val['0'] = str_replace("[EVC Verified Link]", $approve_link, $evc_action_body_val['0']);
        $evc_action_body_val['0'] = str_replace("[EVC Denied Link]", $deny_link, $evc_action_body_val['0']);
        $evc_action_body_val['0'] = token_replace($evc_action_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
        drupal_mail('tw_registration', 'evc_nine', $profile->field_verification_contact_email['und'][0]['safe_value'], language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $evc_conf_body_val), $from = NULL, $send = TRUE);
        drupal_mail('tw_registration', 'evcactionrequired', $fulluser->mail, language_default(), $params = array('approve_link' => 'http://' . $_SERVER['SERVER_NAME'] . '/evc-verify/' . $fulluser->uid . '/' . $evc_timestamp . '/approve', 'deny_link' => 'http://' . $_SERVER['SERVER_NAME'] . '/evc-verify/' . $fulluser->uid . '/' . $evc_timestamp . '/deny', 'homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $evc_action_body_val), $from = NULL, $send = TRUE);
    }
    if ($type == 'annual') {
        // Email to user
        $evcpending_to_accountholder = variable_get('evc_annual_verification_user_email_field');
        $evcpending_to_accountholder_val = array($evcpending_to_accountholder['value']);
        $evcpending_to_accountholder_val['0'] = str_replace("[EVC Verified Link]", $approve_link, $evcpending_to_accountholder_val['0']);
        $evcpending_to_accountholder_val['0'] = str_replace("[EVC Denied Link]", $deny_link, $evcpending_to_accountholder_val['0']);
        $evcpending_to_accountholder_val['0'] = token_replace($evcpending_to_accountholder_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
        drupal_mail('tw_registration', 'evc_annual_nine_day_user', $fulluser->mail, language_default(), $params = array('emailbody' => $evcpending_to_accountholder_val), $from = NULL, $send = TRUE);

        // Email to EVC
        $evcpending_to_evc = variable_get('evc_annual_verification_evc_email_field');
        $evcpending_to_evc_val = array($evcpending_to_evc['value']);
        $evcpending_to_evc_val['0'] = str_replace("[EVC Verified Link]", $approve_link, $evcpending_to_evc_val['0']);
        $evcpending_to_evc_val['0'] = str_replace("[EVC Denied Link]", $deny_link, $evcpending_to_evc_val['0']);
        $evcpending_to_evc_val['0'] = token_replace($evcpending_to_evc_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
        drupal_mail('tw_registration', 'evc_confirmation_reminder', $profile->field_verification_contact_email['und'][0]['safe_value'], language_default(), $params = array('emailbody' => $evcpending_to_evc_val), $from = NULL, $send = TRUE);
    }
    $query = db_update('tw_registration_evc_email')
        ->fields(array('nineday_date' => $evc_timestamp))
        ->condition('uid', $fulluser->uid)
        ->execute();
    // Checking if this is an existing or new account. Inactive = new account. Antyhing else is (likely) an existing account.
    $inactiveterm = taxonomy_get_term_by_name('Inactive', 'account_states');
    $inactiveterm = array_shift($inactiveterm);
    $lockedterm = taxonomy_get_term_by_name('Locked', 'account_states');
    $lockedterm = array_shift($lockedterm);
    if ($fulluser->field_account_states['und'][0]['tid'] !== $inactiveterm->tid) {
        $fulluser->field_account_states['und'][0]['tid'] = $lockedterm->tid;
    }
    user_save($fulluser);
}

function tw_registration_fourteen_day($uid, $type = NULL) {
    $fulluser = user_load($uid);
    $profile = profile2_load_by_user($fulluser->uid, 'indicate_evc');
    if ($type == 'initial' || $type == NULL) {
        // THESE ACCOUNTS ARE PAST 14 DAYS OF NOT BEING VERIFIED BY EVC. NOW NEED TO SEND EMAILS, AS OUTLINED IN 3h
        $evc_nonresponse_body = variable_get('evc_init_reminder_email_field');
        $evc_nonresponse_body_val = array($evc_nonresponse_body['value']);
        $evc_nonresponse_body_val['0'] = token_replace($evc_nonresponse_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
        drupal_mail('tw_registration', 'evc_fourteen', $fulluser->mail, language_default(), $params = array('emailbody' => $evc_nonresponse_body_val, 'homepage' => url('http://tripwire.dhs.gov')), $from = NULL, $send = TRUE);
    }
    if ($type == 'annual') {
        // THESE ACCOUNTS ARE PAST 14 DAYS OF NOT BEING VERIFIED BY EVC. NOW NEED TO SEND EMAILS, AS OUTLINED IN 5e
        $evc_nonresponse_body = variable_get('evc_nonresponse_user_email_field');
        $evc_nonresponse_body_val = array($evc_nonresponse_body['value']);
        $evc_nonresponse_body_val['0'] = token_replace($evc_nonresponse_body_val['0'], array('user' => $fulluser), array('clear' => TRUE,));
        drupal_mail('tw_registration', 'evc_nonresponse_user', $fulluser->mail, language_default(), $params = array('emailbody' => $evc_nonresponse_body_val, 'homepage' => url('http://tripwire.dhs.gov')), $from = NULL, $send = TRUE);
        $term = taxonomy_get_term_by_name('EVC Overdue', 'evc_status');
        $term = array_shift($term);
        $fulluser->field_evc_status['und'][0]['tid'] = $term->tid;
        user_save($fulluser);
    }
    $evc_timestamp = REQUEST_TIME;
    $query = db_update('tw_registration_evc_email')
    ->fields(array('fourteenday_date' => $evc_timestamp))
    ->condition('uid', $fulluser->uid)
    ->execute();
}