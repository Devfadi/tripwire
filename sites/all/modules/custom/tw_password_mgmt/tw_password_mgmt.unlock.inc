<?php
  function tw_password_mgmt_unlock($form, &$form_state) {

    $form['username'] = array(

        '#type' => 'textfield', 
      
        '#title' => t('User name'), 
      
        '#size' => 60, 
      
        '#maxlength' => 128, 
      
        '#required' => TRUE,
      
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
function tw_password_mgmt_unlock_submit($form, &$form_state) {
    $user = user_load_by_name($form_state['values']['username']);
    $user->tw_password_mgmt = 0;
    
    $edit = array(
        'uid' => $user->uid,
        'type' => 'password',
        'log' => 'Password lock manually removed with admin tool',
        'timestamp' => REQUEST_TIME,
        'name' => $user->name,
        'account_state' => '',
        'current_account_status' => '',
        'old_account_status'  => '',
        'author' => $authoruid = $_SESSION['usertrack']['name'],
      );
    drupal_write_record('tw_user_history', $edit);
    user_save($user);
}