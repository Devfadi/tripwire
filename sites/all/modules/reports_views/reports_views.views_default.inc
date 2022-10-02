<?php

/**
 * @file
 * reports_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function reports_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Reports';
  $handler->display->display_options['css_class'] = 'metadata-blocks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset All Filters';
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
      'secondary_collapse_override' => '1',
      'butons_as_secondary_options' => 0,
    ),
    'sort' => array(
      'bef_format' => 'bef_toggle_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => 'Date Asc|Date
Date Desc|Date
Title Asc|Title
Title Desc|Title
Author Asc|Author
Author Desc|Author
Valuable Desc|Valuable
Valuable Asc|Valuable
Views Asc|Views
Views Desc|Views',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 1,
      ),
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 1,
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
    'field_subject_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_library_report_type_tid_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_author_publisher_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => '',
    'function' => 'option-1',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['element_label_type'] = 'strong';
  /* Field: Content: PDF Document */
  $handler->display->display_options['fields']['field_pdf_doc']['id'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['table'] = 'field_data_field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['field'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['label'] = '';
  $handler->display->display_options['fields']['field_pdf_doc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_doc']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pdf_doc']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_pdf_doc']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_pdf_doc']['delta_offset'] = '0';
  /* Field: Content: Link to content */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['rel'] = 'tag';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Field: Read more link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Read more link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="links inline"><li class="node-readmore first last">[view_node]</li>
</ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget_disabled';
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'Views';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['sorts']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['sorts']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['sorts']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['sorts']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_author_publisher_tid']['expose']['label'] = 'Author';
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['value']['expose']['label'] = 'Valuable';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  /* Sort criterion: Content statistics: Total views */
  $handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['totalcount']['expose']['label'] = 'Views';
  /* Filter criterion: Content: Published status */
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
    'library_document' => 'library_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    3271 => '3271',
    3386 => '3386',
    4356 => '4356',
    3276 => '3276',
    4361 => '4361',
    3681 => '3681',
    3836 => '3836',
    4261 => '4261',
    4366 => '4366',
    4216 => '4216',
    3316 => '3316',
    4326 => '4326',
    3161 => '3161',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['id'] = 'field_library_report_type_tid_1';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['expose']['operator_id'] = 'field_library_report_type_tid_1_op';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['expose']['label'] = 'Report Type';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['expose']['operator'] = 'field_library_report_type_tid_1_op';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['expose']['identifier'] = 'field_library_report_type_tid_1';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['vocabulary'] = 'reports';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'all-reports';
  $export['all_reports'] = $view;

  $view = new view();
  $view->name = 'emergency_responder_notes_erns_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Emergency Responder Notes (ERNs)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Emergency Responder Notes (ERNs)';
  $handler->display->display_options['css_class'] = 'metadata-blocks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset All Filters';
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
      'butons_as_secondary_options' => 0,
    ),
    'sort' => array(
      'bef_format' => 'bef_toggle_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => 'Date Asc|Date
Date Desc|Date
Title Asc|Title
Title Desc|Title
Author Asc|Author
Author Desc|Author
Valuable Desc|Valuable
Valuable Asc|Valuable
Views Asc|Views
Views Desc|Views',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 0,
      ),
    ),
    'combine' => array(
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
    'field_subject_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_author_publisher_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => '',
    'function' => 'option-1',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['created']['date_format'] = 'search_api_facetapi_DAY';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['timezone'] = 'America/New_York';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['element_label_type'] = 'strong';
  /* Field: Content: PDF Document */
  $handler->display->display_options['fields']['field_pdf_doc']['id'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['table'] = 'field_data_field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['field'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['label'] = '';
  $handler->display->display_options['fields']['field_pdf_doc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_doc']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pdf_doc']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_pdf_doc']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_pdf_doc']['delta_offset'] = '0';
  /* Field: Content: Link to content */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Field: Read more link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Read more link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="links inline"><li class="node-readmore first last">[view_node]</li>
</ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'Views';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget_disabled';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date';
  /* Sort criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['sorts']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['sorts']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['sorts']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['sorts']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_author_publisher_tid']['expose']['label'] = 'Author';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content statistics: Total views */
  $handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['totalcount']['expose']['label'] = 'Views';
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['value']['expose']['label'] = 'Valuable';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    4356 => '4356',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';

  /* Display: ERN */
  $handler = $view->new_display('page', 'ERN', 'page');
  $handler->display->display_options['path'] = 'reports/emergency-responder-notes';

  /* Display: ETR */
  $handler = $view->new_display('page', 'ETR', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Extremists Threat Reports (ETRs)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    3386 => '3386',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  $handler->display->display_options['path'] = 'reports/extremists-threat-reports';

  /* Display: C3 */
  $handler = $view->new_display('page', 'C3', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Counter-Improvised Threat Collaboration Center (C3)';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    45 => '45',
    3 => '3',
    41 => '41',
    44 => '44',
    4 => '4',
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No reports found.';
  $handler->display->display_options['empty']['area']['format'] = 'tripwire';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    4943 => '4943',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  $handler->display->display_options['path'] = 'reports/c3';

  /* Display: TRIPwire Reports */
  $handler = $view->new_display('page', 'TRIPwire Reports', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TRIPwire Reports';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    4944 => '4944',
    3271 => '3271',
    4356 => '4356',
    3386 => '3386',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  $handler->display->display_options['path'] = 'reports/tripwire';

  /* Display: TABs */
  $handler = $view->new_display('page', 'TABs', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TRIPwire Awareness Bulletins (TABs)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    4948 => '4948',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  $handler->display->display_options['path'] = 'reports/tabs';

  /* Display: RedOps */
  $handler = $view->new_display('page', 'RedOps', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'RedOps & Raptor Reports';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    10 => '10',
    8 => '8',
    41 => '41',
    9 => '9',
    44 => '44',
    4 => '4',
    7 => '7',
    21 => '21',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    4948 => '4948',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  $handler->display->display_options['path'] = 'reports/redops';
  $export['emergency_responder_notes_erns_'] = $view;

  $view = new view();
  $view->name = 'reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'metadata-blocks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset All Filters';
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
    'sort' => array(
      'bef_format' => 'bef_toggle_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => 'Date Asc|Date
Date Desc|Date
Title Asc|Title
Title Desc|Title
Author Asc|Author
Author Desc|Author
Valuable Desc|Valuable
Valuable Asc|Valuable
Views Asc|Views
Views Desc|Views
Attachment Size Asc|Attachment Size
Attachment Size Desc|Attachment Size',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 1,
      ),
    ),
    'combine' => array(
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
    'field_subject_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_author_publisher_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_library_report_type_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No content found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Taxonomy terms on node (Library Report Type) */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'Content: Taxonomy terms on node (Library Report Type)';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'report-type-term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'reports' => 'reports',
    'author_publisher' => 0,
    'access_classification' => 0,
    'critical_infrastructure_category' => 0,
    'document_types' => 0,
    'federal_region' => 0,
    'glossary' => 0,
    'ied_profile_sub_type' => 0,
    'ied_profiles' => 0,
    'account_states' => 0,
    'allow_for_pre_auth_carousel' => 0,
    'device_description' => 0,
    'evc_status' => 0,
    'event_type' => 0,
    'incidents_location' => 0,
    'profile_classification' => 0,
    'program' => 0,
    'school_type' => 0,
    'target' => 0,
    'training_courses' => 0,
    'user_group' => 0,
    'user_roles' => 0,
    'user_status' => 0,
    'international' => 0,
    'osint_map' => 0,
    'state_territory' => 0,
    'subject' => 0,
    'training_education' => 0,
  );
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => '',
    'function' => 'option-1',
  );
  /* Relationship: Content: Taxonomy terms on node (Author) */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['ui_name'] = 'Content: Taxonomy terms on node (Author)';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'author-term';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'author_publisher' => 'author_publisher',
    'access_classification' => 0,
    'critical_infrastructure_category' => 0,
    'document_types' => 0,
    'federal_region' => 0,
    'glossary' => 0,
    'ied_profile_sub_type' => 0,
    'ied_profiles' => 0,
    'account_states' => 0,
    'allow_for_pre_auth_carousel' => 0,
    'device_description' => 0,
    'evc_status' => 0,
    'event_type' => 0,
    'incidents_location' => 0,
    'profile_classification' => 0,
    'program' => 0,
    'school_type' => 0,
    'target' => 0,
    'training_courses' => 0,
    'user_group' => 0,
    'user_roles' => 0,
    'user_status' => 0,
    'international' => 0,
    'reports' => 0,
    'osint_map' => 0,
    'state_territory' => 0,
    'subject' => 0,
    'training_education' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['created']['date_format'] = 'search_api_facetapi_DAY';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['timezone'] = 'America/New_York';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<span><strong>Description</strong>:</span> [body]';
  $handler->display->display_options['fields']['body']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Field: Author/Publisher */
  $handler->display->display_options['fields']['field_author_publisher']['id'] = 'field_author_publisher';
  $handler->display->display_options['fields']['field_author_publisher']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['fields']['field_author_publisher']['field'] = 'field_author_publisher';
  $handler->display->display_options['fields']['field_author_publisher']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_author_publisher']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_author_publisher']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Document';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: PDF Document */
  $handler->display->display_options['fields']['field_pdf_doc']['id'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['table'] = 'field_data_field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['field'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['label'] = '';
  $handler->display->display_options['fields']['field_pdf_doc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_doc']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pdf_doc']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_pdf_doc']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_pdf_doc']['delta_offset'] = '0';
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'Views';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget_disabled';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date';
  /* Sort criterion: Content: Page Title (field_page_title) */
  $handler->display->display_options['sorts']['field_page_title_value']['id'] = 'field_page_title_value';
  $handler->display->display_options['sorts']['field_page_title_value']['table'] = 'field_data_field_page_title';
  $handler->display->display_options['sorts']['field_page_title_value']['field'] = 'field_page_title_value';
  $handler->display->display_options['sorts']['field_page_title_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_page_title_value']['expose']['label'] = 'Title';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'term_node_tid_1';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Author';
  /* Sort criterion: Content statistics: Total views */
  $handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['order'] = 'DESC';
  $handler->display->display_options['sorts']['totalcount']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['totalcount']['expose']['label'] = 'Views';
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['value']['expose']['label'] = 'Valuable';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  /* Contextual filter: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['arguments']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_library_report_type_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_library_report_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['validate_options']['vocabularies'] = array(
    'reports' => 'reports',
  );
  $handler->display->display_options['arguments']['field_library_report_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_library_report_type_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['field_library_report_type_tid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Published status */
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
    'library_document' => 'library_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'reports/%';

  /* Display: All Reports */
  $handler = $view->new_display('page', 'All Reports', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Reports';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
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
    'library_document' => 'library_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['id'] = 'field_library_report_type_tid_1';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['value'] = array(
    4947 => '4947',
    4943 => '4943',
    4948 => '4948',
    3271 => '3271',
    3316 => '3316',
    4366 => '4366',
    4216 => '4216',
    4326 => '4326',
    3836 => '3836',
    3276 => '3276',
    4356 => '4356',
    4361 => '4361',
    3681 => '3681',
    4261 => '4261',
    3386 => '3386',
    3161 => '3161',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid_1']['vocabulary'] = 'reports';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator_id'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['label'] = 'Report Type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['identifier'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  $handler->display->display_options['path'] = 'reports/all-reports';

  /* Display: Private Sector */
  $handler = $view->new_display('page', 'Private Sector', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Private Sector';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
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
    'library_document' => 'library_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Enter terms to search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    3316 => '3316',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  $handler->display->display_options['path'] = 'reports/private-sector-awareness-documents';
  $export['reports'] = $view;

  $view = new view();
  $view->name = 'tripwire_library_list_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TRIPwire Library list view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TRIPwire Library';
  $handler->display->display_options['css_class'] = 'metadata-blocks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_library_report_type_tid' => array(
      'bef_format' => 'bef',
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_author_publisher_tid' => array(
      'bef_format' => 'bef',
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_access_classification_tid' => array(
      'bef_format' => 'bef',
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_federal_region_tid' => array(
      'bef_format' => 'bef',
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_subject_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_state_province_region_value' => array(
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
    'field_country_value' => array(
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
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
    'library_document' => 'library_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Site-wide Tags by Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_subject_tid']['vocabulary'] = 'subject';
  $handler->display->display_options['filters']['field_subject_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator_id'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['label'] = 'Report Type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['identifier'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';
  /* Filter criterion: Field: Author/Publisher (field_author_publisher) */
  $handler->display->display_options['filters']['field_author_publisher_tid']['id'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['table'] = 'field_data_field_author_publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['field'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_author_publisher_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator_id'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['label'] = 'Author/Publisher';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['operator'] = 'field_author_publisher_tid_op';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['identifier'] = 'field_author_publisher_tid';
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_publisher_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_author_publisher_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_author_publisher_tid']['vocabulary'] = 'author_publisher';
  /* Filter criterion: Content: Classification Markings (field_access_classification) */
  $handler->display->display_options['filters']['field_access_classification_tid']['id'] = 'field_access_classification_tid';
  $handler->display->display_options['filters']['field_access_classification_tid']['table'] = 'field_data_field_access_classification';
  $handler->display->display_options['filters']['field_access_classification_tid']['field'] = 'field_access_classification_tid';
  $handler->display->display_options['filters']['field_access_classification_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_access_classification_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_access_classification_tid']['expose']['operator_id'] = 'field_access_classification_tid_op';
  $handler->display->display_options['filters']['field_access_classification_tid']['expose']['label'] = 'Classification';
  $handler->display->display_options['filters']['field_access_classification_tid']['expose']['operator'] = 'field_access_classification_tid_op';
  $handler->display->display_options['filters']['field_access_classification_tid']['expose']['identifier'] = 'field_access_classification_tid';
  $handler->display->display_options['filters']['field_access_classification_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_access_classification_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_access_classification_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_access_classification_tid']['vocabulary'] = 'access_classification';
  /* Filter criterion: Field: Federal Region (field_federal_region) */
  $handler->display->display_options['filters']['field_federal_region_tid']['id'] = 'field_federal_region_tid';
  $handler->display->display_options['filters']['field_federal_region_tid']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['filters']['field_federal_region_tid']['field'] = 'field_federal_region_tid';
  $handler->display->display_options['filters']['field_federal_region_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_federal_region_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_federal_region_tid']['expose']['operator_id'] = 'field_federal_region_tid_op';
  $handler->display->display_options['filters']['field_federal_region_tid']['expose']['label'] = 'Federal Region';
  $handler->display->display_options['filters']['field_federal_region_tid']['expose']['operator'] = 'field_federal_region_tid_op';
  $handler->display->display_options['filters']['field_federal_region_tid']['expose']['identifier'] = 'field_federal_region_tid';
  $handler->display->display_options['filters']['field_federal_region_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_federal_region_tid']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['field_federal_region_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_federal_region_tid']['vocabulary'] = 'federal_region';
  /* Filter criterion: Field: State/Province/Region (field_state_province_region) */
  $handler->display->display_options['filters']['field_state_province_region_value']['id'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['table'] = 'field_data_field_state_province_region';
  $handler->display->display_options['filters']['field_state_province_region_value']['field'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['group'] = 1;
  $handler->display->display_options['filters']['field_state_province_region_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['operator_id'] = 'field_state_province_region_value_op';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['label'] = 'State/Province/Region';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['operator'] = 'field_state_province_region_value_op';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['identifier'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Field: Country (field_country) */
  $handler->display->display_options['filters']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['filters']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['group'] = 1;
  $handler->display->display_options['filters']['field_country_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_value']['expose']['operator_id'] = 'field_country_value_op';
  $handler->display->display_options['filters']['field_country_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_value']['expose']['operator'] = 'field_country_value_op';
  $handler->display->display_options['filters']['field_country_value']['expose']['identifier'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['expose']['remember_roles'] = array(
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
    36 => 0,
    41 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tripwire-library';
  $export['tripwire_library_list_view'] = $view;

  $view = new view();
  $view->name = 'tripwire_video_list_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video Library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Video Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
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
    'video' => 'video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'video-library';
  $export['tripwire_video_list_view'] = $view;

  $view = new view();
  $view->name = 'tripwire_weekly_and_monthly_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TRIPwire Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TRIPwire Reports';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Library Report Type (field_library_report_type) */
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['value'] = array(
    3646 => '3646',
  );
  $handler->display->display_options['filters']['field_library_report_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_report_type_tid']['vocabulary'] = 'reports';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tripwire-reports';
  $export['tripwire_weekly_and_monthly_'] = $view;

  return $export;
}
