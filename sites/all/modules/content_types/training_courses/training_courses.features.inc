<?php
/**
 * @file
 * training_courses.features.inc
 */

/**
 * Implements hook_views_api().
 */
function training_courses_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function training_courses_node_info() {
  $items = array(
    'training_courses' => array(
      'name' => t('Training Courses'),
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
