<?php

/**
 * @file
 * bmap_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function bmap_content_type_node_info() {
  $items = array(
    'bmap_activity_data' => array(
      'name' => t('BMAP Activity Data'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Activity Category'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

