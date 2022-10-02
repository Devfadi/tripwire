<?php
/**
 * @file
 * video_content_type_custom_breadcrumbs.features.inc
 */

/**
 * Implements hook_custom_breadcrumb_features_default_settings().
 */
function video_content_type_custom_breadcrumbs_custom_breadcrumb_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: video_content_type.
  $custom_breadcrumbs['video_content_type'] = array(
    'name' => 'Video Content Type',
    'titles' => 'Video Library',
    'paths' => 'video-library',
    'visibility_php' => '',
    'node_type' => 'video',
    'language' => '',
    'machine_name' => 'video_content_type',
  );

  return $custom_breadcrumbs;
}
