<?php

/**
 * @file
 * Node title validation admin file.
 */

/**
 * Implements hook_form().
 */
function _username_validation_admin_form($form, &$form_state) {

  $form['username_validation_rule'] = array(
    '#type' => 'fieldset',
    '#title' => t('Username condition'),
    '#collapsible' => FAlSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $form['username_validation_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Username Configuration'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $username_validation_rule = variable_get('username_validation_rule', array());
  $username_validation_config = variable_get('username_validation_config', array());

  $form['username_validation_rule']['blacklist_char'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($username_validation_rule['blacklist_char']) ? $username_validation_rule['blacklist_char'] : '',
    '#title' => t('Blacklist Characters/Words'),
    '#description' => '<p>' . t("Comma separated characters or words to avoided while saving username. Ex: !,@,#,$,%,^,&,*,(,),1,2,3,4,5,6,7,8,9,0,have,has,were,aren't.") . '</p>' . '<p>' . t('If any of the blacklisted characters/words found in username ,would return validation error on user save.') . '</p>',
  );
  $form['username_validation_rule']['min_char'] = array(
    '#type' => 'textfield',
    '#title' => t("Minimum characters"),
    '#required' => TRUE,
    '#description' => t("Minimum number of characters username should contain"),
    '#size' => 12,
    '#maxlength' => 3,
    '#default_value' => isset($username_validation_rule['min_char']) ? $username_validation_rule['min_char'] : '1',
  );
  $form['username_validation_rule']['max_char'] = array(
    '#type' => 'textfield',
    '#title' => t("Maximum characters"),
    '#required' => TRUE,
    '#description' => t("Maximum number of characters username should contain"),
    '#size' => 12,
    '#maxlength' => 3,
    '#default_value' => isset($username_validation_rule['max_char']) ? $username_validation_rule['max_char'] : '60',
  );
  $form['username_validation_rule']['min_words'] = array(
      '#type' => 'textfield',
      '#title' => t("Minimum Words"),
      '#required' => TRUE,
      '#description' => t("Minimum number of words username should contain"),
      '#size' => 12,
      '#maxlength' => 3,
      '#default_value' => isset($username_validation_rule['min_words']) ? $username_validation_rule['min_words'] : '1',
  );
  $form['username_validation_rule']['max_words'] = array(
      '#type' => 'textfield',
      '#title' => t("Maximum Words"),
      '#required' => TRUE,
      '#description' => t("Maximum number of words username should contain"),
      '#size' => 12,
      '#maxlength' => 3,
      '#default_value' => isset($username_validation_rule['max_words']) ? $username_validation_rule['max_words'] : '25',
  );
  $form['username_validation_rule']['ajax_validation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Ajax Validation'),
    '#description' => t("By default ajax will be triggered on 'change' event."),
    '#default_value' => isset($username_validation_rule['ajax_validation']) ? $username_validation_rule['ajax_validation'] : '',
  );
  $form['username_validation_config']['user_label'] = array(
    '#type' => 'textfield',
    '#title' => t("Username Label"),
    '#description' => t("This value will display instead of username in the registration form"),
    '#size' => 55,
    '#maxlength' => 55,
    '#default_value' => isset($username_validation_config['user_label']) ? $username_validation_config['user_label'] : '',
  );

  $form['username_validation_config']['user_desc'] = array(
    '#type' => 'textfield',
    '#title' => t("Username description"),
    '#description' => t("This value will display as username description"),
    '#size' => 55,
    '#maxlength' => 55,
    '#default_value' => isset($username_validation_config['user_desc']) ? $username_validation_config['user_desc'] : '',
  );

  $form['#validate'][] = '_username_validation_admin_form_validate';
  return system_settings_form($form);
}

/**
 * The validation function for username_config_validation_admin_form form.
 */
function _username_validation_admin_form_validate($form, &$form_state) {
  $max = $form_state['values']['username_validation_rule']['max_char'];
  // Validate field is numerical.
  if (!is_numeric($max)) {
    form_set_error('max_char', t("These value should be Numerical"));
  }

  // Validate field should be between 0 and 60.
  if ($max <= 0 || $max > 60) {
    form_set_error('username_validation_rule][max_char', t("These value should be between 0 and 60"));
  }

  $min = $form_state['values']['username_validation_rule']['min_char'];

  // Validate field is numerical.
  if (!is_numeric($min)) {
    form_set_error('username_validation_rule][min_char', t("These value should be Numerical"));
  }

  // Validate field is greater than 1.
  if ($min < 1) {
    form_set_error('username_validation_rule][min_char', t("These value should be more than 1"));
  }

  // Validate min is less than max value.
  if ($min > $max) {
    form_set_error('username_validation_rule][min_char', t("Minimum length should not be more than Max length"));
  }
}

