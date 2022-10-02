<?php
/**
 * @file
 * bmap_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function bmap_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['superfish-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 2,
    'module' => 'superfish',
    'node_types' => array(),
    'pages' => 'readiness-preparedness/bomb-making-materials-awareness-program-bmap',
    'roles' => array(),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'content_top',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -19,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
