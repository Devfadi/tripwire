<?php

/**
 * @file
 * osint_data_integrity_tool.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osint_data_integrity_tool_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'osint_data_integrity_tool';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OSINT Data Integrity Tool';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OSINT Data Integrity Tool';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'State / Province';
  $handler->display->display_options['fields']['field_address_administrative_area']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_administrative_area']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_address_administrative_area']['empty'] = 'Field missing!';
  $handler->display->display_options['fields']['field_address_administrative_area']['display_name'] = 1;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'Field missing!';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Content: Device Type/Description */
  $handler->display->display_options['fields']['field_device_description']['id'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['fields']['field_device_description']['field'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_device_description']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_device_description']['empty'] = 'Field missing!';
  $handler->display->display_options['fields']['field_device_description']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_event_date']['empty'] = 'Field missing!';
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_date']['delta_offset'] = '0';
  /* Field: Content: Incident Type/Classification */
  $handler->display->display_options['fields']['field_profiles_classification']['id'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['field'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profiles_classification']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_profiles_classification']['empty'] = 'Field missing!';
  $handler->display->display_options['fields']['field_profiles_classification']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Lat/Long */
  $handler->display->display_options['fields']['field_osint_lat_lon']['id'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['table'] = 'field_data_field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['field'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_osint_lat_lon']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_osint_lat_lon']['empty'] = 'Field missing!';
  $handler->display->display_options['fields']['field_osint_lat_lon']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_osint_lat_lon']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_osint_lat_lon']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  /* Filter criterion: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['filters']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_address_administrative_area']['group'] = 1;
  /* Filter criterion: Content: Address - Country */
  $handler->display->display_options['filters']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_address_country']['group'] = 1;
  /* Filter criterion: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['filters']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['filters']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['filters']['field_address_locality']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_address_locality']['group'] = 1;
  /* Filter criterion: Content: Device Type/Description (field_device_description) */
  $handler->display->display_options['filters']['field_device_description_tid']['id'] = 'field_device_description_tid';
  $handler->display->display_options['filters']['field_device_description_tid']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['filters']['field_device_description_tid']['field'] = 'field_device_description_tid';
  $handler->display->display_options['filters']['field_device_description_tid']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_device_description_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_device_description_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_device_description_tid']['vocabulary'] = 'device_description';
  /* Filter criterion: Content: Event Date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  /* Filter criterion: Content: Incident Type/Classification (field_profiles_classification) */
  $handler->display->display_options['filters']['field_profiles_classification_tid']['id'] = 'field_profiles_classification_tid';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['field'] = 'field_profiles_classification_tid';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_profiles_classification_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['vocabulary'] = 'profile_classification';
  /* Filter criterion: Content: Lat/Long (field_osint_lat_lon:lat) */
  $handler->display->display_options['filters']['field_osint_lat_lon_lat']['id'] = 'field_osint_lat_lon_lat';
  $handler->display->display_options['filters']['field_osint_lat_lon_lat']['table'] = 'field_data_field_osint_lat_lon';
  $handler->display->display_options['filters']['field_osint_lat_lon_lat']['field'] = 'field_osint_lat_lon_lat';
  $handler->display->display_options['filters']['field_osint_lat_lon_lat']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_osint_lat_lon_lat']['group'] = 1;
  /* Filter criterion: Content: Lat/Long (field_osint_lat_lon:lon) */
  $handler->display->display_options['filters']['field_osint_lat_lon_lon']['id'] = 'field_osint_lat_lon_lon';
  $handler->display->display_options['filters']['field_osint_lat_lon_lon']['table'] = 'field_data_field_osint_lat_lon';
  $handler->display->display_options['filters']['field_osint_lat_lon_lon']['field'] = 'field_osint_lat_lon_lon';
  $handler->display->display_options['filters']['field_osint_lat_lon_lon']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_osint_lat_lon_lon']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'osint_item' => 'osint_item',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/dashboard/osint-data-integrity-tool';
  $export['osint_data_integrity_tool'] = $view;

  return $export;
}
