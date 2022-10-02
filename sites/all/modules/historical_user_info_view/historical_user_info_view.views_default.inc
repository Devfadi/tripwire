<?php
/**
 * @file
 * historical_user_info_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function historical_user_info_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'historical_user_information';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tw_user_history';
  $view->human_name = 'Historical User Information';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Historical User Account Changes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    41 => '41',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'timestamp' => array(
      'bef_format' => 'bef_datepicker',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'type' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'account_type' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'hid' => 'hid',
    'log' => 'log',
    'timestamp' => 'timestamp',
    'name' => 'name',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'hid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'log' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total Changes: @total';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: TripWIRE User History: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'tw_user_history';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Account Change Type';
  /* Field: TripWIRE User History: Description of the change */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'tw_user_history';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  $handler->display->display_options['fields']['log']['label'] = 'Account Change Description';
  /* Field: TripWIRE User History: Username */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'tw_user_history';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: TripWIRE User History: Account Type/Role */
  $handler->display->display_options['fields']['account_type']['id'] = 'account_type';
  $handler->display->display_options['fields']['account_type']['table'] = 'tw_user_history';
  $handler->display->display_options['fields']['account_type']['field'] = 'account_type';
  $handler->display->display_options['fields']['account_type']['label'] = 'Account Location';
  $handler->display->display_options['fields']['account_type']['exclude'] = TRUE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = 'Account Location';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'account_type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '7';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'International';
  $handler->display->display_options['fields']['views_conditional']['then'] = 'International';
  $handler->display->display_options['fields']['views_conditional']['or'] = 'Domestic';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: TripWIRE User History: Timestamp field */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'tw_user_history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Change Date';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Sort criterion: TripWIRE User History: Timestamp field */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'tw_user_history';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: TripWIRE User History: Timestamp field */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Date Range';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
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
    31 => 0,
    26 => 0,
  );
  /* Filter criterion: TripWIRE User History: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type']['group_info']['label'] = 'Account Change Type';
  $handler->display->display_options['filters']['type']['group_info']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Added to Active user status',
      'operator' => '=',
      'value' => 'added_to_active',
    ),
    2 => array(
      'title' => 'Added to Awaiting Approval user status',
      'operator' => '=',
      'value' => 'added_to_awaiting',
    ),
    3 => array(
      'title' => 'Added to Awaiting Verification user status',
      'operator' => '=',
      'value' => 'added_to_verification',
    ),
    4 => array(
      'title' => 'Added to Expired user status',
      'operator' => '=',
      'value' => 'added_to_expired',
    ),
    5 => array(
      'title' => 'Added to Inactive user status',
      'operator' => '=',
      'value' => 'added_to_inactive',
    ),
    6 => array(
      'title' => 'Added to Removed user status',
      'operator' => '=',
      'value' => 'added_to_removed',
    ),
    7 => array(
      'title' => 'Added to Locked user status',
      'operator' => '=',
      'value' => 'added_to_locked',
    ),
    8 => array(
      'title' => 'Removed from Active user status',
      'operator' => '=',
      'value' => 'removed_from_active',
    ),
    9 => array(
      'title' => 'Removed from Awaiting Approval user status',
      'operator' => '=',
      'value' => 'removed_from_awaiting',
    ),
    10 => array(
      'title' => 'Removed from Awaiting Verification user status',
      'operator' => '=',
      'value' => 'removed_from_verification',
    ),
    11 => array(
      'title' => 'Removed from Expired user status',
      'operator' => '=',
      'value' => 'removed_from_expired',
    ),
    12 => array(
      'title' => 'Removed from Inactive user status',
      'operator' => '=',
      'value' => 'removed_from_inactive',
    ),
    13 => array(
      'title' => 'Removed from Removed user status',
      'operator' => '=',
      'value' => 'removed_from_removed',
    ),
    14 => array(
      'title' => 'Removed from Locked user status',
      'operator' => '=',
      'value' => 'removed_from_locked',
    ),
    15 => array(
      'title' => 'User Approved',
      'operator' => '=',
      'value' => 'user_activated',
    ),
    16 => array(
      'title' => 'User Do Not Approved',
      'operator' => '=',
      'value' => 'user_deactivated',
    ),
    17 => array(
      'title' => 'Role Added',
      'operator' => '=',
      'value' => 'role_addition',
    ),
    18 => array(
      'title' => 'Role Removed',
      'operator' => '=',
      'value' => 'role_removal',
    ),
    19 => array(
      'title' => 'User Login',
      'operator' => '=',
      'value' => 'user_login',
    ),
  );
  /* Filter criterion: TripWIRE User History: Account Type/Role */
  $handler->display->display_options['filters']['account_type']['id'] = 'account_type';
  $handler->display->display_options['filters']['account_type']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['account_type']['field'] = 'account_type';
  $handler->display->display_options['filters']['account_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['account_type']['expose']['operator_id'] = 'account_type_op';
  $handler->display->display_options['filters']['account_type']['expose']['label'] = 'Account Type/Role';
  $handler->display->display_options['filters']['account_type']['expose']['operator'] = 'account_type_op';
  $handler->display->display_options['filters']['account_type']['expose']['identifier'] = 'account_type';
  $handler->display->display_options['filters']['account_type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['account_type']['group_info']['label'] = 'Account Type';
  $handler->display->display_options['filters']['account_type']['group_info']['identifier'] = 'account_type';
  $handler->display->display_options['filters']['account_type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Domestic',
      'operator' => 'not',
      'value' => 'International',
    ),
    2 => array(
      'title' => 'International',
      'operator' => 'contains',
      'value' => 'International',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: TripWIRE User History: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = '!=';
  $handler->display->display_options['filters']['type_1']['value'] = 'security_answer_changed';
  /* Filter criterion: TripWIRE User History: Type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['operator'] = '!=';
  $handler->display->display_options['filters']['type_2']['value'] = 'email_change';
  /* Filter criterion: TripWIRE User History: Type */
  $handler->display->display_options['filters']['type_3']['id'] = 'type_3';
  $handler->display->display_options['filters']['type_3']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['type_3']['field'] = 'type';
  $handler->display->display_options['filters']['type_3']['operator'] = '!=';
  $handler->display->display_options['filters']['type_3']['value'] = 'note';
  /* Filter criterion: TripWIRE User History: Type */
  $handler->display->display_options['filters']['type_4']['id'] = 'type_4';
  $handler->display->display_options['filters']['type_4']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['type_4']['field'] = 'type';
  $handler->display->display_options['filters']['type_4']['operator'] = 'not';
  $handler->display->display_options['filters']['type_4']['value'] = 'password';
  /* Filter criterion: TripWIRE User History: Type */
  $handler->display->display_options['filters']['type_5']['id'] = 'type_5';
  $handler->display->display_options['filters']['type_5']['table'] = 'tw_user_history';
  $handler->display->display_options['filters']['type_5']['field'] = 'type';
  $handler->display->display_options['filters']['type_5']['operator'] = '!=';
  $handler->display->display_options['filters']['type_5']['value'] = 'MAIL';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/dashboard/historical-user-information';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/dashboard/historical-user-information/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $export['historical_user_information'] = $view;

  return $export;
}
