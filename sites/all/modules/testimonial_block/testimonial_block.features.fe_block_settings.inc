<?php
/**
 * @file
 * testimonial_block.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function testimonial_block_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-testimonials_v2-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'testimonials_v2-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'home',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -62,
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
