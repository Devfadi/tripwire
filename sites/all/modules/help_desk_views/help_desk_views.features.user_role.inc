<?php
/**
 * @file
 * help_desk_views.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function help_desk_views_user_default_roles() {
  $roles = array();

  // Exported role: Help Desk.
  $roles['Help Desk'] = array(
    'name' => 'Help Desk',
    'weight' => 11,
  );

  return $roles;
}
