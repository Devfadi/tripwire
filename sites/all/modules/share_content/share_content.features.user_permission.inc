<?php
/**
 * @file
 * share_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function share_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access epostcard'.
  $permissions['access epostcard'] = array(
    'name' => 'access epostcard',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'access forward'.
  $permissions['access forward'] = array(
    'name' => 'access forward',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'forward',
  );

  return $permissions;
}
