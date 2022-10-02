<?php
/**
 * @file
 * what_s_new_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function what_s_new_content_type_node_info() {
  $items = array(
    'what_s_new_article' => array(
      'name' => t('What\'s New Article'),
      'base' => 'node_content',
      'description' => t('Use this content type for creating a What\'s New article.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
