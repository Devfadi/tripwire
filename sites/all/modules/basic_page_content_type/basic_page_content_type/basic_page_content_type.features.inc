<?php
/**
 * @file
 * basic_page_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function basic_page_content_type_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use this for creating top menu pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
