<?php

/**
 * @file
 * Character llimit constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_char_limit_admin_form',
  'constraint callback' => 'password_policy_char_limit_constraint',
  'message' => t('Password must not be longer than @char_limit character(s).'),
  'prime value' => 'char_limit',
  'config' => array(
    'char_limit' => NULL,
  ),
);

/**
 * Admin form callback for character limit constraint.
 */
function password_policy_char_limit_admin_form($form, &$form_state, $constraint) {
  $sub_form['char_limit_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Character Limit'),
  );
  $sub_form['char_limit_fieldset']['char_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum total characters'),
    '#default_value' => $constraint->config['char_limit'],
    '#description' => t('Password will be required to have no more than this many characters.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for character limit constraint.
 */
function password_policy_char_limit_constraint($password, $account, $constraint) {
  return drupal_strlen($password) <= $constraint->config['char_limit'];
}
