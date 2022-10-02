<?php
/**
 * @file
 * carousel_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function carousel_content_type_node_info() {
  $items = array(
    'carousel_item' => array(
      'name' => t('Carousel Item'),
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
