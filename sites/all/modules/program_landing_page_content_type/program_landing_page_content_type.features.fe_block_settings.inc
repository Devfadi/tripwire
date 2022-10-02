<?php

/**
 * @file
 * program_landing_page_content_type.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function program_landing_page_content_type_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-7e3193aed309a432a598965c0ec829cf'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '7e3193aed309a432a598965c0ec829cf',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -66,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-929a85cb9c768f31c3cbe55c799c4095'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '929a85cb9c768f31c3cbe55c799c4095',
    'module' => 'views',
    'node_types' => array(
      0 => 'program_landing_page',
    ),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -67,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
