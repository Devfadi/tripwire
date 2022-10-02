<?php
/**
 * @file
 * new_user_registration.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function new_user_registration_user_default_roles() {
  $roles = array();

  // Exported role: Awaiting Approval.
  $roles['Awaiting Approval'] = array(
    'name' => 'Awaiting Approval',
    'weight' => 15,
  );

  // Exported role: Pre-Authenticated.
  $roles['Pre-Authenticated'] = array(
    'name' => 'Pre-Authenticated',
    'weight' => 14,
  );

  return $roles;
}
