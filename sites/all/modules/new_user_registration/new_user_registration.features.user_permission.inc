<?php
/**
 * @file
 * new_user_registration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function new_user_registration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access homepage only'.
  $permissions['access homepage only'] = array(
    'name' => 'access homepage only',
    'roles' => array(
      'Pre-Authenticated' => 'Pre-Authenticated',
    ),
    'module' => 'tw_registration',
  );

  return $permissions;
}
