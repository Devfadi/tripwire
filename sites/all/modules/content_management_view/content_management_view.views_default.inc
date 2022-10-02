<?php

/**
 * @file
 * content_management_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function content_management_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_administration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OSINT Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    41 => '41',
    44 => '44',
    4 => '4',
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
          'format' => 'tripwire',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
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
    'status' => array(
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
    'type' => array(
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
    'name' => array(
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
    'field_secured_areas_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_subject_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_library_report_type_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_author_publisher_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_access_classification_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_federal_region_tid' => array(
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
            1 => 'vocabulary',
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
    'field_state_province_region_value' => array(
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
    'created' => array(
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
    'changed' => array(
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
    'field_osint_review_value' => array(
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'name' => 'name',
    'status' => 'status',
    'changed' => 'changed',
    'field_federal_region' => 'field_federal_region',
    'field_subject' => 'field_subject',
    'field_secured_areas' => 'field_secured_areas',
    'field_state_province_region' => 'field_state_province_region',
    'delete_node' => 'delete_node',
    'nid' => 'nid',
    'value' => 'value',
    'value_1' => 'value_1',
    'totalcount' => 'totalcount',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
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
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_federal_region' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subject' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_secured_areas' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_state_province_region' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'totalcount' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a href="/admin/editor_content/export" class="csvbutton">Export</a>';
  /* Relationship: Content: Content author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Helpful count';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => '',
    'function' => 'option-1',
  );
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Unhelpful count';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => '',
    'function' => 'option--1',
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: User Roles */
  $handler->display->display_options['fields']['field_secured_areas']['id'] = 'field_secured_areas';
  $handler->display->display_options['fields']['field_secured_areas']['table'] = 'field_data_field_secured_areas';
  $handler->display->display_options['fields']['field_secured_areas']['field'] = 'field_secured_areas';
  $handler->display->display_options['fields']['field_secured_areas']['label'] = 'User Role Access';
  $handler->display->display_options['fields']['field_secured_areas']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_secured_areas']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_secured_areas']['multi_type'] = 'ul';
  /* Field: Field: State/Province/Region */
  $handler->display->display_options['fields']['field_state_province_region']['id'] = 'field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['table'] = 'field_data_field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['field'] = 'field_state_province_region';
  /* Field: Content: Link to delete content */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Revisions */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Content: Revisions';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/node/[nid]/revisions">revisions</a>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Valuable Count';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['label'] = 'Unhelpful count';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'View count';
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [delete_node] [nid]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Content Title Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['group_info']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['type']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
    4 => array(),
    5 => array(),
    6 => array(),
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Author Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: User Roles (field_secured_areas) */
  $handler->display->display_options['filters']['field_secured_areas_tid']['id'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['table'] = 'field_data_field_secured_areas';
  $handler->display->display_options['filters']['field_secured_areas_tid']['field'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_secured_areas_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['operator_id'] = 'field_secured_areas_tid_op';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['label'] = 'User Role Access';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['operator'] = 'field_secured_areas_tid_op';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['identifier'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_secured_areas_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_secured_areas_tid']['vocabulary'] = 'user_roles';
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
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
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator_id'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['label'] = 'Library Report Type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['identifier'] = 'field_library_report_type_tid';
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Published Date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = 'between';
  $handler->display->display_options['filters']['changed']['group'] = 1;
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated Date';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content revision: Updated date */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['relationship'] = 'nid';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Revised date';
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );

  /* Display: Publisher Content */
  $handler = $view->new_display('page', 'Publisher Content', 'page_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Content Title Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['group_info']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Carousel Item',
      'operator' => 'in',
      'value' => array(
        'carousel_item' => 'carousel_item',
        'all' => 0,
        'page' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    2 => array(
      'title' => 'Library',
      'operator' => 'in',
      'value' => array(
        'library_document' => 'library_document',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    3 => array(
      'title' => 'OSINT Item',
      'operator' => 'in',
      'value' => array(
        'osint_item' => 'osint_item',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    4 => array(
      'title' => 'Profiles',
      'operator' => 'in',
      'value' => array(
        'profiles' => 'profiles',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    5 => array(
      'title' => 'Videos',
      'operator' => 'in',
      'value' => array(
        'video' => 'video',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    6 => array(
      'title' => 'What\'s New Article',
      'operator' => 'in',
      'value' => array(
        'what_s_new_article' => 'what_s_new_article',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
      ),
    ),
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Author Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: User Roles (field_secured_areas) */
  $handler->display->display_options['filters']['field_secured_areas_tid']['id'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['table'] = 'field_data_field_secured_areas';
  $handler->display->display_options['filters']['field_secured_areas_tid']['field'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_secured_areas_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['operator_id'] = 'field_secured_areas_tid_op';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['label'] = 'User Role Access';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['operator'] = 'field_secured_areas_tid_op';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['identifier'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_secured_areas_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_secured_areas_tid']['vocabulary'] = 'user_roles';
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
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
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator_id'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['label'] = 'Library Report Type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['identifier'] = 'field_library_report_type_tid';
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Published Date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = 'between';
  $handler->display->display_options['filters']['changed']['group'] = 1;
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated Date';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content revision: Updated date */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['relationship'] = 'nid';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Revised date';
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
  $handler->display->display_options['path'] = 'admin/editor_content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'OSINT Content';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/editor_content/export';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: All Content */
  $handler = $view->new_display('page', 'All Content', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Site Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: User Roles */
  $handler->display->display_options['fields']['field_secured_areas']['id'] = 'field_secured_areas';
  $handler->display->display_options['fields']['field_secured_areas']['table'] = 'field_data_field_secured_areas';
  $handler->display->display_options['fields']['field_secured_areas']['field'] = 'field_secured_areas';
  $handler->display->display_options['fields']['field_secured_areas']['label'] = 'User Role Access';
  $handler->display->display_options['fields']['field_secured_areas']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_secured_areas']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_secured_areas']['multi_type'] = 'ul';
  /* Field: Field: State/Province/Region */
  $handler->display->display_options['fields']['field_state_province_region']['id'] = 'field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['table'] = 'field_data_field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['field'] = 'field_state_province_region';
  /* Field: Content: Link to delete content */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Revisions */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Content: Revisions';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/node/[nid]/revisions">revisions</a>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Valuable Count';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['label'] = 'Unhelpful count';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'View count';
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [delete_node] [nid]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Content Title Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['group_info']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Carousel Item',
      'operator' => 'in',
      'value' => array(
        'carousel_item' => 'carousel_item',
        'all' => 0,
        'page' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    2 => array(
      'title' => 'Library',
      'operator' => 'in',
      'value' => array(
        'library_document' => 'library_document',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    3 => array(
      'title' => 'OSINT Item',
      'operator' => 'in',
      'value' => array(
        'osint_item' => 'osint_item',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    4 => array(
      'title' => 'Profiles',
      'operator' => 'in',
      'value' => array(
        'profiles' => 'profiles',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    5 => array(
      'title' => 'Videos',
      'operator' => 'in',
      'value' => array(
        'video' => 'video',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'webform' => 0,
        'what_s_new_article' => 0,
      ),
    ),
    6 => array(
      'title' => 'What\'s New Article',
      'operator' => 'in',
      'value' => array(
        'what_s_new_article' => 'what_s_new_article',
        'all' => 0,
        'page' => 0,
        'carousel_item' => 0,
        'filedepot_folder' => 0,
        'homepage' => 0,
        'images' => 0,
        'library_document' => 0,
        'map_data' => 0,
        'osint_item' => 0,
        'profiles' => 0,
        'program_landing_page' => 0,
        'testimonial' => 0,
        'training_and_education' => 0,
        'video' => 0,
        'webform' => 0,
      ),
    ),
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Site Author Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: User Roles (field_secured_areas) */
  $handler->display->display_options['filters']['field_secured_areas_tid']['id'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['table'] = 'field_data_field_secured_areas';
  $handler->display->display_options['filters']['field_secured_areas_tid']['field'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_secured_areas_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['operator_id'] = 'field_secured_areas_tid_op';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['label'] = 'User Role Access';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['operator'] = 'field_secured_areas_tid_op';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['identifier'] = 'field_secured_areas_tid';
  $handler->display->display_options['filters']['field_secured_areas_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_secured_areas_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_secured_areas_tid']['vocabulary'] = 'user_roles';
  /* Filter criterion: Field: Subject (field_subject) */
  $handler->display->display_options['filters']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['filters']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['filters']['field_subject_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator_id'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['operator'] = 'field_subject_tid_op';
  $handler->display->display_options['filters']['field_subject_tid']['expose']['identifier'] = 'field_subject_tid';
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
  $handler->display->display_options['filters']['field_library_report_type_tid']['id'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['table'] = 'field_data_field_library_report_type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['field'] = 'field_library_report_type_tid';
  $handler->display->display_options['filters']['field_library_report_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_report_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator_id'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['label'] = 'Library Report Type';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['operator'] = 'field_library_report_type_tid_op';
  $handler->display->display_options['filters']['field_library_report_type_tid']['expose']['identifier'] = 'field_library_report_type_tid';
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Published Date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = 'between';
  $handler->display->display_options['filters']['changed']['group'] = 1;
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated Date';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content revision: Updated date */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['relationship'] = 'nid';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Revised date';
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
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_osint_review_value']['id'] = 'field_osint_review_value';
  $handler->display->display_options['filters']['field_osint_review_value']['table'] = 'field_data_field_osint_review';
  $handler->display->display_options['filters']['field_osint_review_value']['field'] = 'field_osint_review_value';
  $handler->display->display_options['filters']['field_osint_review_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_osint_review_value']['expose']['operator_id'] = 'field_osint_review_value_op';
  $handler->display->display_options['filters']['field_osint_review_value']['expose']['label'] = 'TW 1.0 Data Migration - Requires OSINT Review';
  $handler->display->display_options['filters']['field_osint_review_value']['expose']['operator'] = 'field_osint_review_value_op';
  $handler->display->display_options['filters']['field_osint_review_value']['expose']['identifier'] = 'field_osint_review_value';
  $handler->display->display_options['filters']['field_osint_review_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'admin/all_content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All Content';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['content_administration'] = $view;

  return $export;
}
