<?php
/**
 * @file
 * profiles_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function profiles_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "slick" && $api == "slick_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function profiles_content_type_node_info() {
  $items = array(
    'profiles' => array(
      'name' => t('Profiles'),
      'base' => 'node_content',
      'description' => t('Use this to create a Profile page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
