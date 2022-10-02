<?php
/**
 * @file
 * obp_event_map_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function obp_event_map_content_type_node_info() {
  $items = array(
    'map_data' => array(
      'name' => t('OBP Event Map Data'),
      'base' => 'node_content',
      'description' => t('Use this to create Map Events for OBP, BMAP, MJ, and Training. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
