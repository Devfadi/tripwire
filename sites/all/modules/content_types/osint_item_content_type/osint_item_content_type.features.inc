<?php
/**
 * @file
 * osint_item_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function osint_item_content_type_node_info() {
  $items = array(
    'osint_item' => array(
      'name' => t('OSINT Item'),
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
