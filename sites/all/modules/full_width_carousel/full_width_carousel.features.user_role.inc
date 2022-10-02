<?php
/**
 * @file
 * full_width_carousel.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function full_width_carousel_user_default_roles() {
  $roles = array();

  // Exported role: OSINT Administrator.
  $roles['OSINT Administrator'] = array(
    'name' => 'OSINT Administrator',
    'weight' => 12,
  );

  return $roles;
}
