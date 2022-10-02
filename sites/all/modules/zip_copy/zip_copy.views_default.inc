<?php

/**
 * @file
 * zip_copy.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function zip_copy_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'copy_zip';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Copy zip';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Copy zip';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Field: Profile: Zip Code */
  $handler->display->display_options['fields']['field_zip_code']['id'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['table'] = 'field_data_field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['field'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['label'] = 'NEW Zip Code';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_zipcode']['id'] = 'field_zipcode';
  $handler->display->display_options['fields']['field_zipcode']['table'] = 'field_data_field_zipcode';
  $handler->display->display_options['fields']['field_zipcode']['field'] = 'field_zipcode';
  $handler->display->display_options['fields']['field_zipcode']['label'] = 'OLD Zip/Postal Code';
  /* Field: Bulk operations: Profile */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_script_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['user']['alter']['text'] = '<a href="/user/[user]/edit">[user]</a>';
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'employment_information' => 'employment_information',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_zipcode_value']['id'] = 'field_zipcode_value';
  $handler->display->display_options['filters']['field_zipcode_value']['table'] = 'field_data_field_zipcode';
  $handler->display->display_options['filters']['field_zipcode_value']['field'] = 'field_zipcode_value';
  $handler->display->display_options['filters']['field_zipcode_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_zipcode_value']['value'] = array(
    'min' => '',
    'max' => '',
    'value' => '',
  );
  $handler->display->display_options['filters']['field_zipcode_value']['group'] = 1;
  /* Filter criterion: Profile: Zip Code (field_zip_code) */
  $handler->display->display_options['filters']['field_zip_code_value']['id'] = 'field_zip_code_value';
  $handler->display->display_options['filters']['field_zip_code_value']['table'] = 'field_data_field_zip_code';
  $handler->display->display_options['filters']['field_zip_code_value']['field'] = 'field_zip_code_value';
  $handler->display->display_options['filters']['field_zip_code_value']['operator'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/copy-zip';
  $export['copy_zip'] = $view;

  return $export;
}
