<?php

/**
 * @file
 * osint_map_views.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osint_map_views_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-osint_map-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osint_map-block_1',
    'module' => 'views',
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
        'weight' => -63,
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

  $export['views-osint_map-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osint_map-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'domestic-ied-incident-map
domestic-ied-incident-map/*',
    'roles' => array(),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -64,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
