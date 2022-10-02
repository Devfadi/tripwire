<?php

/**
 * @file
 * video_library_blocks.features.inc
 */

/**
 * Implements hook_views_api().
 */
function video_library_blocks_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function video_library_blocks_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: popular_videos
  $nodequeues['popular_videos'] = array(
    'name' => 'popular_videos',
    'title' => 'Popular Videos',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'video',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
