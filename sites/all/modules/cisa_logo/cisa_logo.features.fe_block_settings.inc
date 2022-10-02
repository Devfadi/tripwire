<?php

/**
 * @file
 * cisa_logo.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cisa_logo_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-cisa'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'cisa',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'right_header',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -75,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
