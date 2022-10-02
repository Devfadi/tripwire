<?php
/**
 * @file
 * training_courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function training_courses_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'training_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Training Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_course_listing_node']['id'] = 'reverse_field_course_listing_node';
  $handler->display->display_options['relationships']['reverse_field_course_listing_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_course_listing_node']['field'] = 'reverse_field_course_listing_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Checkmarks */
  $handler->display->display_options['fields']['field_checkmarks']['id'] = 'field_checkmarks';
  $handler->display->display_options['fields']['field_checkmarks']['table'] = 'field_data_field_checkmarks';
  $handler->display->display_options['fields']['field_checkmarks']['field'] = 'field_checkmarks';
  $handler->display->display_options['fields']['field_checkmarks']['label'] = '';
  $handler->display->display_options['fields']['field_checkmarks']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_checkmarks']['alter']['text'] = '<i class="fas fa-check"></i> [field_checkmarks]';
  $handler->display->display_options['fields']['field_checkmarks']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_checkmarks']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_checkmarks']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_checkmarks']['multi_type'] = 'ul';
  /* Field: Content: Link URL */
  $handler->display->display_options['fields']['field_link_url']['id'] = 'field_link_url';
  $handler->display->display_options['fields']['field_link_url']['table'] = 'field_data_field_link_url';
  $handler->display->display_options['fields']['field_link_url']['field'] = 'field_link_url';
  $handler->display->display_options['fields']['field_link_url']['label'] = '';
  $handler->display->display_options['fields']['field_link_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_url']['element_label_colon'] = FALSE;
  /* Field: Content: Training Course Image */
  $handler->display->display_options['fields']['field_training_course_image']['id'] = 'field_training_course_image';
  $handler->display->display_options['fields']['field_training_course_image']['table'] = 'field_data_field_training_course_image';
  $handler->display->display_options['fields']['field_training_course_image']['field'] = 'field_training_course_image';
  $handler->display->display_options['fields']['field_training_course_image']['label'] = '';
  $handler->display->display_options['fields']['field_training_course_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_training_course_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_training_course_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_training_course_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="training-left">
  <a href="[field_link_url]">[field_training_course_image]</a>
</div>
<div class="training-right">
  <div class="training-title"><a href="[field_link_url]">[title]</a></div>
  <div class="training-body">[body]</div>
  <div class="training-checkmarks">[field_checkmarks]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_course_listing_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'training_courses' => 'training_courses',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['training_courses'] = $view;

  return $export;
}
