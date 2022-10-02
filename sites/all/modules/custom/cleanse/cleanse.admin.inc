<?php
/**
 * This function creates the settings page. It is a callback function for drupal_get_form()
 */
function cleanse_settings($form, &$form_state) {

   $form['fields']['first_name'] = array(
      '#type' =>'checkbox',
      '#title'=>t('First Name'),
      '#default_value' =>TRUE, // for default checked and false is not checked
    );

    $form['fields']['last_name'] = array(
        '#type' =>'checkbox',
        '#title'=>t('Last Name'),
        '#default_value' =>TRUE, // for default checked and false is not checked
    );

    $form['fields']['username'] = array(
        '#type' =>'checkbox',
        '#title'=>t('Username'),
        '#default_value' =>TRUE, // for default checked and false is not checked
    );

    $form['fields']['email'] = array(
        '#type' =>'checkbox',
        '#title'=>t('Email'),
        '#default_value' =>TRUE, // for default checked and false is not checked
    );

    $form['fields']['evc_email'] = array(
        '#type' =>'checkbox',
        '#title'=>t('EVC Email'),
        '#default_value' =>TRUE, // for default checked and false is not checked
    );

    $form['fields']['alt_email'] = array(
        '#type' =>'checkbox',
        '#title'=>t('Alternative Email'),
        '#default_value' =>TRUE, // for default checked and false is not checked
    );

    $form['fields']['user'] = array(
        '#type' => 'textfield',
        '#title' => t('Username'),
        '#description' => t('Note, if you specify a username, Cleanse will only change this one account.'),
        '#size' => 10,
        '#maxlength' => 15,
      );

    $form['cleanse'] = array(
        '#type' => 'submit',
        '#value' => 'Cleanse these fields',
        //'#submit' => array('cleanse_now')
        '#ajax' => array(
            'callback' => 'cleanse_now',
            'wrapper' => 'cleanse-form',
            'progress' => array(
                'type' => 'bar',
                'message' => t('Cleansing..'),
                'url' => 'cleanse/progress', //url to fetch current progress percentage
                'interval' => '500' //progress bar will refresh in half second intervals
            )
        ),
      );

  return $form;
}

function cleanse_now($form, &$form_state) {
    // Gather field scrub settings. 
    // 1 = scrub, 0 = skip
    $fname = $form_state['values']['first_name'];
    $lname = $form_state['values']['last_name'];
    $username = $form_state['values']['username'];
    $email = $form_state['values']['email'];
    $evc_email = $form_state['values']['evc_email'];
    $alt_email = $form_state['values']['alt_email'];

    // Get all users
    $query = new EntityFieldQuery;
    // If a username was specified, we only run the cleanse on that user only
    if (!empty($form_state['values']['user'])) {
        $uid = user_load_by_name(check_plain($form_state['values']['user']));
        $result = $query
            ->entityCondition('entity_type', 'user')
            ->propertyCondition('uid', '72', '!=')
            ->propertyCondition('uid', '0', '!=')
            ->propertyCondition('mail', '%gc.com%', 'NOT LIKE')
            ->propertyCondition('mail', '%gc.com%', 'NOT LIKE')
            ->propertyCondition('mail', '%mailinator.com%', 'NOT LIKE')
            ->propertyCondition('uid', $uid->uid, '=')
            ->execute();
    } else {
        // If no username was specified, then we run the script on all users minus Matt and anonymous user.
        $result = $query
        ->entityCondition('entity_type', 'user')
        ->propertyCondition('uid', '72', '!=')
        ->propertyCondition('mail', '%twd.com%', 'NOT LIKE')
         ->propertyCondition('mail', '%gc.com%', 'NOT LIKE')
        ->propertyCondition('uid', '0', '!=')
        ->execute();
    }

    if (!empty($result['user'])) {
        $fullcount = count($result['user']);
        $counter = 0;
        foreach ($result['user'] as $u) {     
            $ul = user_load($u->uid);
            if ($username == 1) {
                $ul->name = 'u' . mt_rand();
            } 

            if ($email == 1) {
                $ul->mail = 'devmail' . $counter . '@mailinator.com';
                $ul->init = 'devmail' . $counter . '@mailinator.com';
            }
            
            $pi = profile2_load_by_user($u->uid, 'personal_information');
            $evc = profile2_load_by_user($u->uid, 'indicate_evc');
            $pro = profile2_load_by_user($u->uid, 'employment_information');
            if (isset($pi->field_first_name)) {
                if ($fname == 1) {
                    $pi->field_first_name['und'][0]['value'] = 'fname' . $counter;
                    $pi->field_first_name['und'][0]['safe_value'] = 'fname' . $counter;
                }

                if ($lname == 1) {
                    $pi->field_last_name['und'][0]['value'] = 'lname' . $counter;
                    $pi->field_last_name['und'][0]['safe_value'] = 'lname' . $counter;
                }
                profile2_save($pi);
            }
            if (isset($evc->field_verification_contact_email)) {
                if ($evc_email == 1) {
                    $evc->field_employment_verification_co['und'][0]['value'] = 'EVC Contact' . $counter;
                    $evc->field_employment_verification_co['und'][0]['safe_value'] = 'EVC Contact' . $counter;
                    $evc->field_verification_contact_email['und'][0]['value'] = 'devevcmail' . $counter . '@mailinator.com';
                    $evc->field_verification_contact_email['und'][0]['safe_value'] = 'devevcmail' . $counter . '@mailinator.com';
                    $evc->field_employment_verification_p['und'][0]['value'] = '555-555-5555';
                    $evc->field_employment_verification_p['und'][0]['safe_value'] = '555-555-5555';
                }
                profile2_save($evc);
            }
            if (isset($pro->field_alternate_email_address)) {
                if ($alt_email == 1) {
                    $pro->field_alternate_email_address['und'][0]['value'] = 'devaltmail' . $counter . '@mailinator.com';
                    $pro->field_alternate_email_address['und'][0]['safe_value'] = 'devaltmail' . $counter . '@mailinator.com';
                }
                profile2_save($pro);
            }
            user_save($ul);
            $counter++;
            $progress = round(($counter/$fullcount) * 100);
            variable_set('cleanse_status', $progress);
        }
    }
}
