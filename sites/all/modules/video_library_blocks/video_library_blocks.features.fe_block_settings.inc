<?php

/**
 * @file
 * video_library_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function video_library_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-video_blocks-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'video_blocks-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'video-library',
    'roles' => array(),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'content',
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
    'title' => '',
    'visibility' => 1,
  );

  $export['views-video_blocks-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'video_blocks-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'video-library',
    'roles' => array(),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -65,
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

  $export['views-video_tags-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'video_tags-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'video-library',
    'roles' => array(),
    'themes' => array(
      'rubix_responsive_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'rubix_responsive_theme',
        'weight' => -37,
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
