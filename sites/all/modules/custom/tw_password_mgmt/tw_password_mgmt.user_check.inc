<?php

function tw_password_mgmt_user_check() {

    // Load all approved users
    $tid = taxonomy_get_term_by_name('Approved', 'user_status');
    $tid_id = array_shift($tid)->tid;
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'user')
        ->fieldCondition('field_user_status', 'tid', $tid_id, '=');

    $results = $query->execute();

    // Load the user data
    foreach ($results['user'] as $r) {
        // Skip anonymous users
        if($r->uid == 0) { continue; }
        // Fetch date when password was last changed
        $user_password_data = tw_password_mgmt_user_expiry($r->uid);
        $last_password_change = $user_password_data->last_password_change;
        // Fetch how long until user expires, based on the user's role
        $user = user_load($r->uid);
        $expiry = tw_password_mgmt_when_to_expire($user->roles);
        // Now we can figure out if this user is within 14 days of expiring
        if($expiry && ($last_password_change != '' && (REQUEST_TIME > (strtotime('-14 days', $last_password_change + $expiry))))) {
            // Check if this user has already been emailed about their password expiring within 14 days
            $check_fourteen = tw_password_mgmt_email_check('14', $user->uid);
            if (empty($check_fourteen->fourteen_day_email)) {
                //if((REQUEST_TIME - $expiry) < $last_password_change) {
                    $ten_days_email_body = variable_get('my_richtext_field');
                    $ten_days_email_body_val = array($ten_days_email_body['value']);
                    $ten_days_email_body_val['0'] = token_replace($ten_days_email_body_val['0'], array('user' => $user), array('clear' => TRUE,));
                    drupal_mail('tw_password_mgmt', 'fourteendays', $user->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $ten_days_email_body_val), $from = NULL, $send = TRUE);
                    $query = db_update('tw_password_mgmt_emails')
                      ->fields(array('fourteen_day_email' => REQUEST_TIME))
                      ->condition('uid', $user->uid)
                      ->execute();
                    watchdog('tw_password_mgmt', 'Username ' . $user->name . ' was sent an email that their password will expire. Email sent ' . date('m/d/Y h:i'), array(), WATCHDOG_INFO, NULL);
                  //}   
            }
        }
        // Now we can figure out if this user is within 7 days of expiring
        if($expiry && ($last_password_change != '' && (REQUEST_TIME > (strtotime('-7 days', $last_password_change + $expiry))))) {
            $check_seven = tw_password_mgmt_email_check('7', $user->uid);
            if (empty($check_seven->seven_day_email)) {
                //if((REQUEST_TIME - $expiry) < $last_password_change) {
                    $seven_days_email_body = variable_get('password_7_days_email_field');
                    $seven_days_email_body_val = array($seven_days_email_body['value']);
                    $seven_days_email_body_val['0']= token_replace($seven_days_email_body_val['0'], array('user' => $user), array('clear' => TRUE,));
                    drupal_mail('tw_password_mgmt', 'sevendays', $user->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $seven_days_email_body_val), $from = NULL, $send = TRUE);
                    $query = db_update('tw_password_mgmt_emails')
                    ->fields(array('seven_day_email' => REQUEST_TIME))
                    ->condition('uid', $user->uid)
                    ->execute();
                    watchdog('tw_password_mgmt', 'Username ' . $user->name . ' was sent an email that their password will expire. Email sent ' . date('m/d/Y h:i'), array(), WATCHDOG_INFO, NULL);
                  //}
            }
        }
        
        // Test to see if their password has expired
		if($expiry && ($last_password_change != '' && (REQUEST_TIME - $expiry) > $last_password_change) || ($last_password_change == '' && (REQUEST_TIME - $expiry) > $user->created))
		{
            $check_locked = tw_password_mgmt_email_check('locked', $user->uid);
            if (empty($check_locked->locked_email)) {
                if((REQUEST_TIME - $expiry) > $last_password_change) {
                    $tid = taxonomy_get_term_by_name('Locked', 'account_states');
                    $tid_id = array_shift($tid)->tid;
                    // Checking if TW Account State is set to Locked. If it is, this user is likely already locked and there is no point in sending more emails and/or changing the state
                    if ($user->field_account_states['und'][0]['tid'] !== $tid_id) {
                        $user->field_account_states['und'][0]['tid'] = $tid_id;
                        user_save($user);
                        $account_locked_email_body = variable_get('account_locked_email_field');
                        $account_locked_email_body_val = array($account_locked_email_body['value']);
                        $account_locked_email_body_val['0'] = token_replace($account_locked_email_body_val['0'], array('user' => $user), array('clear' => TRUE,));
                        drupal_mail('tw_password_mgmt', 'locked', $user->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $account_locked_email_body_val), $from = NULL, $send = TRUE);
                    }
                    $query = db_update('tw_password_mgmt_emails')
                      ->fields(array('locked_email' => REQUEST_TIME))
                      ->condition('uid', $user->uid)
                      ->execute();
                      $data = array(
                        'uid' => $user->uid,
                        'type' => 'password_expiration',
                        'log' => 'Username ' . $user->name . ' password has expired. TW Account State set to Locked.',
                        'timestamp' => REQUEST_TIME,
                        'name' => $user->name,
                        'account_state' => $user->status,
                        'current_account_status' => '',
                        'old_account_status'  =>'',
                        'account_type' => NULL,
                        'author' => 'System',
                    );
                    drupal_write_record('tw_user_history', $data);
                    watchdog('tw_password_mgmt', 'Username ' . $user->name . ' password has expired', array(), WATCHDOG_INFO, NULL);
                }
            }
        }
        // Check if a user's password expired, and it has been at least six months.  If so, we will email them and set user status to Expired
        if($expiry && ($last_password_change != '' && (REQUEST_TIME > (strtotime('+6 months', $last_password_change + $expiry))))) {
            // Checking to see if this user is already set to expired. If so, not sending another email.
            $tid = taxonomy_get_term_by_name('Expired', 'account_states');
            $tid = array_shift($tid)->tid;
            if ($user->field_account_states['und'][0]['tid'] !== $tid) {
                $six_months_email_body = variable_get('six_months_email_field');
                $six_months_email_body_val = array($six_months_email_body['value']);
                $six_months_email_body_val['0'] = token_replace($six_months_email_body_val['0'], array('user' => $user), array('clear' => TRUE,));
                drupal_mail('tw_password_mgmt', 'sixmonths', $user->mail, language_default(), $params = array('homepage' => url('http://tripwire.dhs.gov'), 'emailbody' => $six_months_email_body_val), $from = NULL, $send = TRUE);
                watchdog('tw_password_mgmt', 'Username ' . $user->name . ' was sent an email that their password expired over six months ago. Email sent ' . date('m/d/Y h:i'), array(), WATCHDOG_INFO, NULL);
                // Setting user status to expired
                //$tid = taxonomy_get_term_by_name('Expired', 'account_states');
                $user->field_account_states['und'][0]['tid'] = $tid;
                user_save($user);
            } else {
                //dpm("user expired already");
            }
        }
    }
}

function tw_password_mgmt_user_expiry($uid) {
    $query = db_select('tw_password_mgmt_users', 'fpcu');
	$alias = $query->join('users', 'u', 'u.uid = fpcu.uid');
	$query
		->fields('fpcu', array('last_password_change'))
		->fields($alias, array('created'))
		->condition($alias . '.uid', $uid);
	$user_data = $query->execute()->fetchObject();
    return $user_data;
}

function tw_password_mgmt_when_to_expire($roles) {
    $expquery = db_select('tw_password_mgmt_expiry', 'fpce');
    $expiry = $expquery
        ->fields('fpce', array('expiry'))
		->condition('fpce.rid', array_keys($roles), 'IN')
		->orderBy('fpce.weight')
		->range(0, 1)
		->addTag('tw_password_mgmt_expiry_check')
		->execute()
		->fetchField();
    return $expiry;
}

function tw_password_mgmt_email_check($type, $uid) {
    // Check if user is in the database table
    $result = db_query('SELECT COUNT(uid) FROM {tw_password_mgmt_emails} WHERE uid = :uid', array(
        ':uid' => $uid,
      ))->fetchField();
    if ($result == 0) {
        //If user is not found in tw_password_mgmt_emails db, we need to add them so that we can track when password reset emails get sent out
        tw_password_mgmt_adduser($uid);
    }
    if ($type == '14') {
        $query = db_select('tw_password_mgmt_emails', 'fpcm');
        $alias = $query->join('users', 'u', 'u.uid = fpcm.uid');
        $query
            ->fields('fpcm', array('fourteen_day_email'))
            ->fields($alias, array('created'))
            ->condition($alias . '.uid', $uid);
        $user_data = $query->execute()->fetchObject();
    }

    if ($type == '7') {
        $query = db_select('tw_password_mgmt_emails', 'fpcm');
        $alias = $query->join('users', 'u', 'u.uid = fpcm.uid');
        $query
            ->fields('fpcm', array('seven_day_email'))
            ->fields($alias, array('created'))
            ->condition($alias . '.uid', $uid);
        $user_data = $query->execute()->fetchObject();
    }

    if ($type == 'locked') {
        $query = db_select('tw_password_mgmt_emails', 'fpcm');
        $alias = $query->join('users', 'u', 'u.uid = fpcm.uid');
        $query
            ->fields('fpcm', array('locked_email'))
            ->fields($alias, array('created'))
            ->condition($alias . '.uid', $uid);
        $user_data = $query->execute()->fetchObject();
    }
    return $user_data;
}

function tw_password_mgmt_adduser($uid) {
	// Create a row for each user in the {tw_password_mgmt_emails} table
    $query3 = db_insert('tw_password_mgmt_emails')->fields(array('uid'));
    $query3->values(array($uid));
    $query3->execute();
}