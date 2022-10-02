<?php
/**
 * @file
 * c3_info_exch_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function c3_info_exch_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-c3-info-exch-menu.
  $menus['menu-c3-info-exch-menu'] = array(
    'menu_name' => 'menu-c3-info-exch-menu',
    'title' => 'C3 Info Exch Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('C3 Info Exch Menu');

  return $menus;
}
