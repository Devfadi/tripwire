<?php
/**
 * @file
 * bmap_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bmap_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-bmap-menu.
  $menus['menu-bmap-menu'] = array(
    'menu_name' => 'menu-bmap-menu',
    'title' => 'BMAP Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('BMAP Menu');

  return $menus;
}
