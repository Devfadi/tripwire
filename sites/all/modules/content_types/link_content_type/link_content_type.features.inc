<?php
/**
 * @file
 * link_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function link_content_type_node_info() {
  $items = array(
    'link' => array(
      'name' => t('Link'),
      'base' => 'node_content',
      'description' => t('This content type allows to create a link to a URL.  This is meant to be used in conjunction with other features of the site that require a linking ability.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
