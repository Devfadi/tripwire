<?php
/**
 * @file
 * sf_profiles_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function sf_profiles_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ied-profiles-menu.
  $menus['menu-ied-profiles-menu'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'title' => 'Explosive Profiles',
    'description' => 'Profiles secondary menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Explosive Profiles');
  t('Profiles secondary menu');

  return $menus;
}
