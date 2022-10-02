<?php

/**
 * @file
 * program_landing_page_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function program_landing_page_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function program_landing_page_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function program_landing_page_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: program_landing_page_carousel.
  $styles['program_landing_page_carousel'] = array(
    'label' => 'Program Landing Page carousel',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function program_landing_page_content_type_node_info() {
  $items = array(
    'program_landing_page' => array(
      'name' => t('Program Landing Page'),
      'base' => 'node_content',
      'description' => t('This content type is for program landing pages, that have a 3 column design'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
