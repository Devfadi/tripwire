<?php
/**
 * @file
 * obp_admin_role.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function obp_admin_role_user_default_roles() {
  $roles = array();

  // Exported role: OBP Admin.
  $roles['OBP Admin'] = array(
    'name' => 'OBP Admin',
    'weight' => 19,
  );

  return $roles;
}
