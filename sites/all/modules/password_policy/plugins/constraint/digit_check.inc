<?php

/**
 * @file
 * Character llimit constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_digit_check_admin_form',
  'constraint callback' => 'password_policy_digit_check_constraint',
  'message' => t('Password must not be appended with a single digit or with a two-digit "year" string.'),
  'prime value' => 'digit_check',
  'config' => array(
    'digit_check' => FALSE,
  ),
);

/**
 * Admin form callback for character limit constraint.
 */
function password_policy_digit_check_admin_form($form, &$form_state, $constraint) {
  $sub_form['digit_check_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Digit Check at end of string'),
  );
  $sub_form['digit_check_fieldset']['digit_check'] = array(
    '#type' => 'checkbox',
    '#title' => t('Password must not be appended with a single digit or with a two-digit "year" string.'),
    '#default_value' => $constraint->config['digit_check'],
  );

  return $sub_form;
}

/**
 * Constraint callback for character limit constraint.
 */
function password_policy_digit_check_constraint($password, $account, $constraint) {
  $four = substr($password, -4);
  // First, we check if last 4 characters are numerical. If they are, we exit out because we only care if last 1 or 2 are numerical.
  if (is_numeric($four)) {
    return TRUE;
  }
  // Next, check if last 3 characters are numerical. If they are, we exit out because we only care if last 1 or 2 are numerical.
  $three = substr($password, -3);
  if (is_numeric($three)) {
    return TRUE;
  }

  // If previous two checks were not succesful, then the password is either a mix of letters and numbers, or has no numbers. 
  // Now we check if last two characters are numbers 
  $two = substr($password, -2);
  if (is_numeric($two)) {
    return FALSE;
  }

  // Check for last character being a single digit
  $one = substr($password, -1);
  if (is_numeric($one)) {
    return FALSE;
  }
  else {
    return TRUE;
  }
  
}
