<?php
/**
 * @file
 * email_blast.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function email_blast_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'email_blast';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Email Blast';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TRIPwire Email Blast';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<strong>Warning! Clicking Send Email will send out emails to the user population based on filters applied</strong>';
  $handler->display->display_options['footer']['area']['format'] = 'tripwire';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile - Personal info';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'personal_information' => 'personal_information',
  );
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Profile - Employment';
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'employment_information' => 'employment_information',
  );
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'User Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'users';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Drupal Status';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  /* Filter criterion: User: Account States (field_account_states) */
  $handler->display->display_options['filters']['field_account_states_tid']['id'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['table'] = 'field_data_field_account_states';
  $handler->display->display_options['filters']['field_account_states_tid']['field'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['value'] = array(
    4751 => '4751',
  );
  $handler->display->display_options['filters']['field_account_states_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_account_states_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['operator_id'] = 'field_account_states_tid_op';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['label'] = 'Account State';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['operator'] = 'field_account_states_tid_op';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['identifier'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  $handler->display->display_options['filters']['field_account_states_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_account_states_tid']['vocabulary'] = 'account_states';
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    4401 => '4401',
    4771 => '4771',
    4776 => '4776',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_status_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['operator_id'] = 'field_user_status_tid_op';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['label'] = 'Account Status';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['operator'] = 'field_user_status_tid_op';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['identifier'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4786 => '4786',
    4791 => '4791',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_evc_status_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['operator_id'] = 'field_evc_status_tid_op';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['label'] = 'EVC Status';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['operator'] = 'field_evc_status_tid_op';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['identifier'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['error_message'] = FALSE;
  /* Filter criterion: Profile: Federal Sector of Employment (field_federal_sector_of_employme) */
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['id'] = 'field_federal_sector_of_employme_value';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['table'] = 'field_data_field_federal_sector_of_employme';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['field'] = 'field_federal_sector_of_employme_value';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['group'] = 1;
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['operator_id'] = 'field_federal_sector_of_employme_value_op';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['label'] = 'Federal Sector';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['operator'] = 'field_federal_sector_of_employme_value_op';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['identifier'] = 'field_federal_sector_of_employme_value';
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_federal_sector_of_employme_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  /* Filter criterion: Field: State/Province/Region (field_state_province_region) */
  $handler->display->display_options['filters']['field_state_province_region_value']['id'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['table'] = 'field_data_field_state_province_region';
  $handler->display->display_options['filters']['field_state_province_region_value']['field'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['relationship'] = 'profile_1';
  $handler->display->display_options['filters']['field_state_province_region_value']['group'] = 1;
  $handler->display->display_options['filters']['field_state_province_region_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['operator_id'] = 'field_state_province_region_value_op';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['label'] = 'State/Province/Region';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['operator'] = 'field_state_province_region_value_op';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['identifier'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  /* Filter criterion: Field: Country (field_country) */
  $handler->display->display_options['filters']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['filters']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['relationship'] = 'profile_1';
  $handler->display->display_options['filters']['field_country_value']['group'] = 1;
  $handler->display->display_options['filters']['field_country_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_value']['expose']['operator_id'] = 'field_country_value_op';
  $handler->display->display_options['filters']['field_country_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_value']['expose']['operator'] = 'field_country_value_op';
  $handler->display->display_options['filters']['field_country_value']['expose']['identifier'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_country_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );
  /* Filter criterion: Profile: Subscribe to TRIPwire communications? (field_subscribe_to_tripwire_comm) */
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['id'] = 'field_subscribe_to_tripwire_comm_value';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['table'] = 'field_data_field_subscribe_to_tripwire_comm';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['field'] = 'field_subscribe_to_tripwire_comm_value';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['expose']['operator_id'] = 'field_subscribe_to_tripwire_comm_value_op';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['expose']['label'] = 'Subscribe';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['expose']['operator'] = 'field_subscribe_to_tripwire_comm_value_op';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['expose']['identifier'] = 'field_subscribe_to_tripwire_comm_value';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
    42 => 0,
    43 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/people/blast';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/people/blast/export';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page_1' => 'page_1',
  );
  $export['email_blast'] = $view;

  return $export;
}
