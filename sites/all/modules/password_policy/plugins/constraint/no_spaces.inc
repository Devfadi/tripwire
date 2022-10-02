<?php

/**
 * @file
 * No spaces constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_no_spaces_admin_form',
  'constraint callback' => 'password_policy_no_spaces_constraint',
  'message' => t('Password must not contain any blank spaces.'),
  'prime value' => 'no_spaces',
  'config' => array(
    'no_spaces' => FALSE,
  ),
);

/**
 * Admin form callback for no blank spaces constraint.
 */
function password_policy_no_spaces_admin_form($form, &$form_state, $constraint) {
  $sub_form['no_spaces_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('No blank spaces'),
  );
  $sub_form['no_spaces_fieldset']['no_spaces'] = array(
    '#type' => 'checkbox',
    '#title' => t('Password must not contain any blank spaces.'),
    '#default_value' => $constraint->config['no_spaces'],
  );

  return $sub_form;
}

/**
 * Constraint callback for no spaces constraint.
 */
function password_policy_no_spaces_constraint($password, $account, $constraint) {
    if (stripos($password, ' ') !== FALSE) {
      return FALSE;
    } else {
      return TRUE;
    }
}

