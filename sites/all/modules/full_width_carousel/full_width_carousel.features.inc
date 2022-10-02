<?php
/**
 * @file
 * full_width_carousel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function full_width_carousel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "slick" && $api == "slick_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function full_width_carousel_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function full_width_carousel_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: post_auth_carousel
  $nodequeues['post_auth_carousel'] = array(
    'name' => 'post_auth_carousel',
    'title' => 'Carousel',
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
      0 => 'carousel_item',
      1 => 'video',
      2 => 'what_s_new_article',
    ),
    'roles' => array(
      0 => 'OSINT Administrator',
    ),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function full_width_carousel_image_default_styles() {
  $styles = array();

  // Exported image style: carousel_thumbnail.
  $styles['carousel_thumbnail'] = array(
    'label' => 'Carousel thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
