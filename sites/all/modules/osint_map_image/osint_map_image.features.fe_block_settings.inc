<?php
/**
 * @file
 * osint_map_image.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osint_map_image_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-osint_map_image'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'osint_map_image',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'home',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -16,
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
