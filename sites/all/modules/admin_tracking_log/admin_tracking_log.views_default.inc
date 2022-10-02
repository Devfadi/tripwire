<?php
/**
 * @file
 * admin_tracking_log.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function admin_tracking_log_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_tracking_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tw_admin_history';
  $view->human_name = 'Admin Tracking Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin History';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
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
    'role' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'action' => 'action',
    'error_message' => 'error_message',
    'item_id' => 'item_id',
    'page_label' => 'page_label',
    'search' => 'search',
    'session_id' => 'session_id',
    'timestamp' => 'timestamp',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'action' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'error_message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'page_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'search' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'session_id' => array(
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
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: TripWIRE Admin History: Username */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: TripWIRE Admin History: Session ID */
  $handler->display->display_options['fields']['session_id']['id'] = 'session_id';
  $handler->display->display_options['fields']['session_id']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['session_id']['field'] = 'session_id';
  /* Field: TripWIRE Admin History: Timestamp field */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Date/time';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: TripWIRE Admin History: Search */
  $handler->display->display_options['fields']['search']['id'] = 'search';
  $handler->display->display_options['fields']['search']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['search']['field'] = 'search';
  $handler->display->display_options['fields']['search']['label'] = 'Note';
  /* Field: TripWIRE Admin History: Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Field: TripWIRE Admin History: Action */
  $handler->display->display_options['fields']['action']['id'] = 'action';
  $handler->display->display_options['fields']['action']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['action']['field'] = 'action';
  /* Field: TripWIRE Admin History: Error Message */
  $handler->display->display_options['fields']['error_message']['id'] = 'error_message';
  $handler->display->display_options['fields']['error_message']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['error_message']['field'] = 'error_message';
  /* Field: TripWIRE Admin History: Page Label */
  $handler->display->display_options['fields']['page_label']['id'] = 'page_label';
  $handler->display->display_options['fields']['page_label']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['page_label']['field'] = 'page_label';
  /* Field: TripWIRE Admin History: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'tw_admin_history';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Sort criterion: TripWIRE Admin History: Timestamp field */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'tw_admin_history';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: TripWIRE Admin History: Account Role */
  $handler->display->display_options['filters']['role']['id'] = 'role';
  $handler->display->display_options['filters']['role']['table'] = 'tw_admin_history';
  $handler->display->display_options['filters']['role']['field'] = 'role';
  $handler->display->display_options['filters']['role']['operator'] = 'contains';
  $handler->display->display_options['filters']['role']['exposed'] = TRUE;
  $handler->display->display_options['filters']['role']['expose']['operator_id'] = 'role_op';
  $handler->display->display_options['filters']['role']['expose']['label'] = 'Account Role';
  $handler->display->display_options['filters']['role']['expose']['operator'] = 'role_op';
  $handler->display->display_options['filters']['role']['expose']['identifier'] = 'role';
  $handler->display->display_options['filters']['role']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['role']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['role']['group_info']['label'] = 'Account Role';
  $handler->display->display_options['filters']['role']['group_info']['identifier'] = 'role';
  $handler->display->display_options['filters']['role']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'OBP Admin',
      'operator' => 'contains',
      'value' => 'OBP Admin',
    ),
    2 => array(
      'title' => 'Content Editor',
      'operator' => 'contains',
      'value' => 'Content Editor',
    ),
    3 => array(
      'title' => 'Administrator',
      'operator' => 'contains',
      'value' => 'administrator',
    ),
  );
  /* Filter criterion: TripWIRE Admin History: Timestamp field */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'tw_admin_history';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['value']['value'] = '+1 month';
  $handler->display->display_options['filters']['timestamp']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Date';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/dashboard/admin-history';
  $export['admin_tracking_log'] = $view;

  return $export;
}
