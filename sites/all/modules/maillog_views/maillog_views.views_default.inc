<?php
/**
 * @file
 * maillog_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function maillog_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Maillog';
  $view->description = 'Displays the list of e-mails logged by the \'Mail Log\' module.';
  $view->tag = '';
  $view->base_table = 'maillog';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Maillog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view maillog';
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
          'format' => 'tripwire',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'header_to' => array(
      'bef_format' => 'default',
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
      ),
    ),
    'header_from' => array(
      'bef_format' => 'default',
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
      ),
    ),
    'subject' => array(
      'bef_format' => 'default',
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
      ),
    ),
    'sent_date' => array(
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'Maillog is currently empty. Send a mail!';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Field: Maillog: Maillog_ID */
  $handler->display->display_options['fields']['idmaillog']['id'] = 'idmaillog';
  $handler->display->display_options['fields']['idmaillog']['table'] = 'maillog';
  $handler->display->display_options['fields']['idmaillog']['field'] = 'idmaillog';
  $handler->display->display_options['fields']['idmaillog']['exclude'] = TRUE;
  /* Field: Maillog: Date */
  $handler->display->display_options['fields']['sent_date']['id'] = 'sent_date';
  $handler->display->display_options['fields']['sent_date']['table'] = 'maillog';
  $handler->display->display_options['fields']['sent_date']['field'] = 'sent_date';
  /* Field: Maillog: Message_ID */
  $handler->display->display_options['fields']['header_message_id']['id'] = 'header_message_id';
  $handler->display->display_options['fields']['header_message_id']['table'] = 'maillog';
  $handler->display->display_options['fields']['header_message_id']['field'] = 'header_message_id';
  /* Field: Maillog: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'maillog';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['subject']['alter']['path'] = 'maillog/details/[idmaillog]';
  /* Field: Maillog: From */
  $handler->display->display_options['fields']['header_from']['id'] = 'header_from';
  $handler->display->display_options['fields']['header_from']['table'] = 'maillog';
  $handler->display->display_options['fields']['header_from']['field'] = 'header_from';
  /* Field: Maillog: To */
  $handler->display->display_options['fields']['header_to']['id'] = 'header_to';
  $handler->display->display_options['fields']['header_to']['table'] = 'maillog';
  $handler->display->display_options['fields']['header_to']['field'] = 'header_to';
  /* Sort criterion: Maillog: Date */
  $handler->display->display_options['sorts']['sent_date']['id'] = 'sent_date';
  $handler->display->display_options['sorts']['sent_date']['table'] = 'maillog';
  $handler->display->display_options['sorts']['sent_date']['field'] = 'sent_date';
  $handler->display->display_options['sorts']['sent_date']['order'] = 'DESC';
  /* Filter criterion: Maillog: To */
  $handler->display->display_options['filters']['header_to']['id'] = 'header_to';
  $handler->display->display_options['filters']['header_to']['table'] = 'maillog';
  $handler->display->display_options['filters']['header_to']['field'] = 'header_to';
  $handler->display->display_options['filters']['header_to']['operator'] = 'word';
  $handler->display->display_options['filters']['header_to']['group'] = 1;
  $handler->display->display_options['filters']['header_to']['exposed'] = TRUE;
  $handler->display->display_options['filters']['header_to']['expose']['operator_id'] = 'header_to_op';
  $handler->display->display_options['filters']['header_to']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['header_to']['expose']['operator'] = 'header_to_op';
  $handler->display->display_options['filters']['header_to']['expose']['identifier'] = 'header_to';
  $handler->display->display_options['filters']['header_to']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Maillog: From */
  $handler->display->display_options['filters']['header_from']['id'] = 'header_from';
  $handler->display->display_options['filters']['header_from']['table'] = 'maillog';
  $handler->display->display_options['filters']['header_from']['field'] = 'header_from';
  $handler->display->display_options['filters']['header_from']['operator'] = 'word';
  $handler->display->display_options['filters']['header_from']['group'] = 1;
  $handler->display->display_options['filters']['header_from']['exposed'] = TRUE;
  $handler->display->display_options['filters']['header_from']['expose']['operator_id'] = 'header_from_op';
  $handler->display->display_options['filters']['header_from']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['header_from']['expose']['operator'] = 'header_from_op';
  $handler->display->display_options['filters']['header_from']['expose']['identifier'] = 'header_from';
  $handler->display->display_options['filters']['header_from']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Maillog: Subject */
  $handler->display->display_options['filters']['subject']['id'] = 'subject';
  $handler->display->display_options['filters']['subject']['table'] = 'maillog';
  $handler->display->display_options['filters']['subject']['field'] = 'subject';
  $handler->display->display_options['filters']['subject']['operator'] = 'allwords';
  $handler->display->display_options['filters']['subject']['group'] = 1;
  $handler->display->display_options['filters']['subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject']['expose']['operator_id'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['subject']['expose']['operator'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['identifier'] = 'subject';
  $handler->display->display_options['filters']['subject']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Maillog: Date */
  $handler->display->display_options['filters']['sent_date']['id'] = 'sent_date';
  $handler->display->display_options['filters']['sent_date']['table'] = 'maillog';
  $handler->display->display_options['filters']['sent_date']['field'] = 'sent_date';
  $handler->display->display_options['filters']['sent_date']['operator'] = 'between';
  $handler->display->display_options['filters']['sent_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sent_date']['expose']['operator_id'] = 'sent_date_op';
  $handler->display->display_options['filters']['sent_date']['expose']['label'] = 'Date Start/End';
  $handler->display->display_options['filters']['sent_date']['expose']['operator'] = 'sent_date_op';
  $handler->display->display_options['filters']['sent_date']['expose']['identifier'] = 'sent_date';
  $handler->display->display_options['filters']['sent_date']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Export button */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['ui_name'] = 'Export button';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/admin/reports/maillog/export" class="button">Export</a>';
  $handler->display->display_options['path'] = 'admin/reports/maillog';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Maillog';
  $handler->display->display_options['menu']['description'] = 'Show the logged mails';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/reports/maillog/export';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page_1' => 'page_1',
  );
  $export['Maillog'] = $view;

  return $export;
}
