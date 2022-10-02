<?php

/**
 * Menu callback: Display the settings form.
 */
function tw_registration_settings_form() {
    //$config = _tw_registration_variable_get();
    $form = array();

    $form['tw_registration']['enable_evc_check'] = array(
        '#type' => 'checkbox',
        '#title' => t('Enable EVC user check script'),
        '#default_value' => variable_get('enable_evc_check'),
        '#description' => t('If checked, the daily user check for EVC status will be enabled.')
      );

    return system_settings_form($form);
    
}

function tw_registration_wn_form() {
  //$config = _tw_registration_variable_get();
  $form = array();

  $form['wn_emails'] = array(
      '#type' => 'textfield',
      '#title' => t('Email(s) to send new subscriptions to'),
      '#default_value' => variable_get('wn_emails'),
      '#description' => t('Enter emails for alert of new WN subscription.')
    );

  return system_settings_form($form);
  
}