<?php
/**
 * @file
 * new_user_registration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function new_user_registration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_management';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'mail' => 'mail',
    'name' => 'name',
    'created' => 'created',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'User name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<div class="name">[name] </div>
<div class="email">[mail]</div>';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Registered';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';
  /* Filter criterion: Profile: Federal Sector of Employment (field_federal_sector_of_employme) */
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['id'] = 'field_federal_sector_of_employme_value';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['table'] = 'field_data_field_federal_sector_of_employme';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['field'] = 'field_federal_sector_of_employme_value';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['operator_id'] = 'field_federal_sector_of_employme_value_op';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['label'] = 'Federal Sector of Employment';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['operator'] = 'field_federal_sector_of_employme_value_op';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['identifier'] = 'field_federal_sector_of_employme_value';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    16 => 0,
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Profile: Sector of Employment (field_sector_of_employment) */
  $handler->display->display_options['filters']['field_sector_of_employment_value']['id'] = 'field_sector_of_employment_value';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['table'] = 'field_data_field_sector_of_employment';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['field'] = 'field_sector_of_employment_value';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sector_of_employment_value']['expose']['operator_id'] = 'field_sector_of_employment_value_op';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['expose']['label'] = 'Sector of Employment';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['expose']['operator'] = 'field_sector_of_employment_value_op';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['expose']['identifier'] = 'field_sector_of_employment_value';
  $handler->display->display_options['filters']['field_sector_of_employment_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    16 => 0,
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Profile: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'empty';
  /* Filter criterion: User: User Status (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    0 => '4378',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/people/registration';
  $export['user_management'] = $view;

  return $export;
}
