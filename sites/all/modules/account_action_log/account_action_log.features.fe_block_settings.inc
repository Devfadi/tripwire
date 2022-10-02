<?php
/**
 * @file
 * account_action_log.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function account_action_log_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-account_action_log-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'account_action_log-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'user/*/edit',
    'roles' => array(),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rubix_responsive_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
