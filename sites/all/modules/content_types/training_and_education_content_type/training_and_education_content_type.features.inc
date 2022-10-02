<?php

/**
 * @file
 * training_and_education_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function training_and_education_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function training_and_education_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function training_and_education_content_type_node_info() {
  $items = array(
    'training_and_education' => array(
      'name' => t('Training and Education'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
