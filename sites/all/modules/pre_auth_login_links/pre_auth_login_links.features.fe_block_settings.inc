<?php
/**
 * @file
 * pre_auth_login_links.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pre_auth_login_links_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-custom_login'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'custom_login',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'right_header',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -35,
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

  $export['block-custom_register'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'custom_register',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'right_header',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -34,
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
