<?php


/**
 * This function creates the settings page. It is a callback function for drupal_get_form()
 */
function tw_user_history_settings($form, &$form_state)
{
  $form['user-status-tracking'] = array(
    '#type' => 'submit',
    '#value' => 'Track user statuses right now',
    '#submit' => array('tw_user_history_status_track_now')
  );

  return $form;
}

function tw_user_history_status_track_now($form, &$form_state) {
  module_load_include('status.inc', 'tw_user_history');
  watchdog('tw_user_history', 'Running user status tracking script', array(), WATCHDOG_INFO, NULL);
  tw_user_history_status_track();
}

function tw_user_history_edit_date($form, &$form_state) {
  $form['#attached']['css'][] = drupal_get_path('module', 'tw_user_history') . '/css/edit_date.css';
  module_load_include('check.inc', 'tw_registration');
  module_load_include('user_check.inc', 'tw_password_mgmt');

  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('username'),
    '#size' => 10,
    '#maxlength' => 15,
    '#required' => TRUE,
  );

  $form['evc_initial_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('EVC Initial Date'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+2',
  );

  $form['evc_verification_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('EVC Verification Date'),
    '#description' => t('This date also applies to the VIP COR Confirm date'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+2',
  );

  $form['evc_9day_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('EVC 9-day email'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+2',
  );

  $form['evc_14day_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('EVC 14-day email'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+2',
  );

  $form['last_access_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('User Last Access'),
    '#description' => t('This date determines when if a user is inactive or not.'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+2',
  );

  $form['last_password_change'] = array(
    '#type' => 'date_popup',
    '#title' => t('Last Password Change'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+2',
  );

  $form['privacy_notice'] = array(
    '#type' => 'date_popup',
    '#title' => t('Privacy notice accept'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+2',
  );

  $form['reset_evc'] = array(
    '#title' => t('Reset EVC'),
    '#type' => 'checkbox',
    '#description' => t('This will reset the EVC email fields to a state when no emails have been sent yet.'),
    '#default_value' => FALSE,
  ); 

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['evc_script'] = array(
    '#type' => 'submit',
    '#value' => t('Execute Initial EVC Script'),
    '#limit_validation_errors' => array(),
    '#submit' => array('tw_registration_check_users'), //call function
    );

  $form['annual_evc_script'] = array(
    '#type' => 'submit',
    '#value' => t('Execute Annual EVC Script'),
    '#limit_validation_errors' => array(),
    '#submit' => array('tw_registration_check_evc'), //call function
  );

  $form['evc_check_users'] = array(
    '#type' => 'submit',
    '#value' => t('Execute EVC Check of Users Script'),
    '#limit_validation_errors' => array(),
    '#submit' => array('tw_registration_check_users'), //call function
  );

  $form['password_reset_script'] = array(
    '#type' => 'submit',
    '#value' => t('Execute Password Reset Script'),
    '#limit_validation_errors' => array(),
    '#submit' => array('tw_password_mgmt_user_check'), //call function
  );


  return $form;
}

/**
 * Add a submit handler/function to the form.
 *
 * This will add a completion message to the screen when the
 * form successfully processes
 */
function tw_user_history_edit_date_submit($form, &$form_state) {
  $fulluser = user_load_by_name($form_state['values']['username']);

  // EVC Initial Date
  if (isset($form_state['values']['evc_initial_date'])) {
    $evc_init_date = strtotime($form_state['values']['evc_initial_date']);
    $query = db_update('tw_registration_evc_email')
                ->fields(array('evc_hash' => $evc_init_date))
                ->condition('uid', $fulluser->uid)
                ->execute();
  }
  // EVC Verification Date
  if (isset($form_state['values']['evc_verification_date'])) {
    $evc_verification_date = strtotime($form_state['values']['evc_verification_date']);
    $query = db_update('tw_registration_evc_email')
                ->fields(array('verification_date' => $evc_verification_date))
                ->condition('uid', $fulluser->uid)
                ->execute();
  }
  // EVC 9 day email
  if (isset($form_state['values']['evc_9day_date'])) {
    $evc_nine = strtotime($form_state['values']['evc_9day_date']);
    $query = db_update('tw_registration_evc_email')
                ->fields(array('nineday_date' => $evc_nine))
                ->condition('uid', $fulluser->uid)
                ->execute();
  }
// EVC 14 day email
  if (isset($form_state['values']['evc_14day_date'])) {
    $evc_fourteen = strtotime($form_state['values']['evc_14day_date']);
    $query = db_update('tw_registration_evc_email')
                ->fields(array('fourteenday_date' => $evc_fourteen))
                ->condition('uid', $fulluser->uid)
                ->execute();
  }

  // Inactivity date
  if (isset($form_state['values']['last_access_date'])) {
    $access = strtotime($form_state['values']['last_access_date']);
    $fulluser->access = $access;
    user_save($fulluser);
  }

  // Last password change
  if (isset($form_state['values']['last_password_change'])) {
    $passdate = strtotime($form_state['values']['last_password_change']);
    $query = db_update('tw_password_mgmt_users')
                ->fields(array('last_password_change' => $passdate))
                ->condition('uid', $fulluser->uid)
                ->execute();
  }

  // Privacy notice
  if (isset($form_state['values']['privacy_notice'])) {
    $privdate = strtotime($form_state['values']['privacy_notice']);
    $query = db_update('tw_security_check_users')
                ->fields(array('last_security_accept' => $privdate))
                ->condition('uid', $fulluser->uid)
                ->execute();
  }

  // Reset EVC
  if (isset($form_state['values']['reset_evc'])) {
    if ($form_state['values']['reset_evc'] == 1) {
      // First, testing if row in db exists.  If not, we will create it.
      $result = db_select('tw_registration_evc_email', 'c')
      ->fields('c') 
      ->condition('uid', $fulluser->uid)
      ->execute()
      ->fetchAll();
      if (empty($result)) {
        // No row found, so we will create one.
        $evc_timestamp = REQUEST_TIME;
        $query= db_insert('tw_registration_evc_email')
        ->fields(array(
          'uid' => $fulluser->uid,
          'evc_hash' => $evc_timestamp,
          'verification_date' => NULL,
          'verification_status' => 0,
        ))
        ->execute();
      } else {
        // We found a result, so going ahead and reseting that row.
        $querynine = db_update('tw_registration_evc_email')
          ->fields(array('verification_date' => NULL, 'nineday_date' => NULL, 'fourteenday_date' => NULL))
          ->condition('uid', $fulluser->uid)
          ->execute();
      }
    }
  }

  drupal_set_message(t('Dates have been changed.'));
}