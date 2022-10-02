<?php

/**
 * @file
 * library_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function library_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function library_content_type_node_info() {
  $items = array(
    'library_document' => array(
      'name' => t('Library'),
      'base' => 'node_content',
      'description' => t('Use this content type when creating a Report page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
