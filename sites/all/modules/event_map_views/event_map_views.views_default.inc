<?php

/**
 * @file
 * event_map_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function event_map_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'obp_event_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OBP Event Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'more2';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '200';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'field_address' => 'field_address',
    'field_federal_region' => 'field_federal_region',
    'field_poc_email' => 'field_poc_email',
    'field_poc_phone_number' => 'field_poc_phone_number',
    'field_event_date' => 'field_event_date',
  );
  $handler->display->display_options['style_options']['default'] = 'field_event_date';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
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
    'field_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_federal_region' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poc_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poc_phone_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_date' => array(
      'sortable' => 1,
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
  $handler->display->display_options['empty']['area']['label'] = 'No Results Message';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results for your specified search.  Please modify your criteria and try again.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => '',
    'function' => 'option-1',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Event Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_event_type']['id'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['fields']['field_event_type']['field'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_event_type']['delta_offset'] = '0';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_obp_event_date']['id'] = 'field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['table'] = 'field_data_field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['field'] = 'field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['settings'] = array(
    'format_type' => 'search_api_facetapi_DAY',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_obp_event_date']['delta_offset'] = '0';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: POC Email */
  $handler->display->display_options['fields']['field_poc_email']['id'] = 'field_poc_email';
  $handler->display->display_options['fields']['field_poc_email']['table'] = 'field_data_field_poc_email';
  $handler->display->display_options['fields']['field_poc_email']['field'] = 'field_poc_email';
  /* Field: Content: POC Phone Number */
  $handler->display->display_options['fields']['field_poc_phone_number']['id'] = 'field_poc_phone_number';
  $handler->display->display_options['fields']['field_poc_phone_number']['table'] = 'field_data_field_poc_phone_number';
  $handler->display->display_options['fields']['field_poc_phone_number']['field'] = 'field_poc_phone_number';
  /* Sort criterion: Content: Event Date -  start date (field_obp_event_date) */
  $handler->display->display_options['sorts']['field_obp_event_date_value']['id'] = 'field_obp_event_date_value';
  $handler->display->display_options['sorts']['field_obp_event_date_value']['table'] = 'field_data_field_obp_event_date';
  $handler->display->display_options['sorts']['field_obp_event_date_value']['field'] = 'field_obp_event_date_value';
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
    'map_data' => 'map_data',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    8 => 0,
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
    44 => 0,
  );
  /* Filter criterion: Content: Event Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_tid']['id'] = 'field_event_type_tid';
  $handler->display->display_options['filters']['field_event_type_tid']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_tid']['field'] = 'field_event_type_tid';
  $handler->display->display_options['filters']['field_event_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_event_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['operator_id'] = 'field_event_type_tid_op';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['label'] = 'Event Type';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['operator'] = 'field_event_type_tid_op';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['identifier'] = 'field_event_type_tid';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_event_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_event_type_tid']['vocabulary'] = 'event_type';
  /* Filter criterion: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['filters']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['group'] = 1;
  $handler->display->display_options['filters']['field_address_administrative_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['operator_id'] = 'field_address_administrative_area_op';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['label'] = 'Address - Administrative area (i.e. State / Province)';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['operator'] = 'field_address_administrative_area_op';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['identifier'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['label'] = 'State';
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['identifier'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Alabama',
      'operator' => '=',
      'value' => 'AL',
    ),
    2 => array(
      'title' => 'Alaska',
      'operator' => '=',
      'value' => 'AK',
    ),
    3 => array(
      'title' => 'Arizona',
      'operator' => '=',
      'value' => 'AZ',
    ),
    4 => array(
      'title' => 'Arkansas',
      'operator' => '=',
      'value' => 'AR',
    ),
    5 => array(
      'title' => 'California',
      'operator' => '=',
      'value' => 'CA',
    ),
    6 => array(
      'title' => 'Colorado',
      'operator' => '=',
      'value' => 'CO',
    ),
    7 => array(
      'title' => 'Connecticut',
      'operator' => '=',
      'value' => 'CT',
    ),
    8 => array(
      'title' => 'Delaware',
      'operator' => '=',
      'value' => 'DE',
    ),
    9 => array(
      'title' => 'District of Columbia',
      'operator' => '=',
      'value' => 'DC',
    ),
    10 => array(
      'title' => 'Florida',
      'operator' => '=',
      'value' => 'FL',
    ),
    11 => array(
      'title' => 'Georgia',
      'operator' => '=',
      'value' => 'GA',
    ),
    12 => array(
      'title' => 'Hawaii',
      'operator' => '=',
      'value' => 'HI',
    ),
    13 => array(
      'title' => 'Idaho',
      'operator' => '=',
      'value' => 'ID',
    ),
    14 => array(
      'title' => 'Illinois',
      'operator' => '=',
      'value' => 'IL',
    ),
    15 => array(
      'title' => 'Indiana',
      'operator' => '=',
      'value' => 'IN',
    ),
    16 => array(
      'title' => 'Iowa',
      'operator' => '=',
      'value' => 'IA',
    ),
    17 => array(
      'title' => 'Kansas',
      'operator' => '=',
      'value' => 'KS',
    ),
    18 => array(
      'title' => 'Kentucky',
      'operator' => '=',
      'value' => 'KY',
    ),
    19 => array(
      'title' => 'Louisiana',
      'operator' => '=',
      'value' => 'LA',
    ),
    20 => array(
      'title' => 'Maine',
      'operator' => '=',
      'value' => 'ME',
    ),
    21 => array(
      'title' => 'Maryland',
      'operator' => '=',
      'value' => 'MD',
    ),
    22 => array(
      'title' => 'Massachusetts',
      'operator' => '=',
      'value' => 'MA',
    ),
    23 => array(
      'title' => 'Michigan',
      'operator' => '=',
      'value' => 'MI',
    ),
    24 => array(
      'title' => 'Minnesota',
      'operator' => '=',
      'value' => 'MN',
    ),
    25 => array(
      'title' => 'Mississippi',
      'operator' => '=',
      'value' => 'MS',
    ),
    26 => array(
      'title' => 'Missouri',
      'operator' => '=',
      'value' => 'MO',
    ),
    27 => array(
      'title' => 'Montana',
      'operator' => '=',
      'value' => 'MT',
    ),
    28 => array(
      'title' => 'Nebraska',
      'operator' => '=',
      'value' => 'NE',
    ),
    29 => array(
      'title' => 'Nevada',
      'operator' => '=',
      'value' => 'NV',
    ),
    30 => array(
      'title' => 'New Hampshire',
      'operator' => '=',
      'value' => 'NH',
    ),
    31 => array(
      'title' => 'New Jersey',
      'operator' => '=',
      'value' => 'NJ',
    ),
    32 => array(
      'title' => 'New Mexico',
      'operator' => '=',
      'value' => 'NM',
    ),
    33 => array(
      'title' => 'New York',
      'operator' => '=',
      'value' => 'NY',
    ),
    34 => array(
      'title' => 'North Carolina',
      'operator' => '=',
      'value' => 'NC',
    ),
    35 => array(
      'title' => 'North Dakota',
      'operator' => '=',
      'value' => 'ND',
    ),
    36 => array(
      'title' => 'Ohio',
      'operator' => '=',
      'value' => 'OH',
    ),
    37 => array(
      'title' => 'Oklahoma',
      'operator' => '=',
      'value' => 'OK',
    ),
    38 => array(
      'title' => 'Oregon',
      'operator' => '=',
      'value' => 'OR',
    ),
    39 => array(
      'title' => 'Pennsylvania',
      'operator' => '=',
      'value' => 'PA',
    ),
    40 => array(
      'title' => 'Rhode Island',
      'operator' => '=',
      'value' => 'RI',
    ),
    41 => array(
      'title' => 'South Carolina',
      'operator' => '=',
      'value' => 'SC',
    ),
    42 => array(
      'title' => 'South Dakota',
      'operator' => '=',
      'value' => 'SD',
    ),
    43 => array(
      'title' => 'Tennessee',
      'operator' => '=',
      'value' => 'TN',
    ),
    44 => array(
      'title' => 'Texas',
      'operator' => '=',
      'value' => 'TX',
    ),
    45 => array(
      'title' => 'Utah',
      'operator' => '=',
      'value' => 'UT',
    ),
    46 => array(
      'title' => 'Vermont',
      'operator' => '=',
      'value' => 'VT',
    ),
    47 => array(
      'title' => 'Virginia',
      'operator' => '=',
      'value' => 'VA',
    ),
    48 => array(
      'title' => 'Washington ',
      'operator' => '=',
      'value' => 'WA',
    ),
    49 => array(
      'title' => 'West Virginia',
      'operator' => '=',
      'value' => 'WV',
    ),
    50 => array(
      'title' => 'Wisconsin',
      'operator' => '=',
      'value' => 'WI',
    ),
    51 => array(
      'title' => 'Wyoming',
      'operator' => '=',
      'value' => 'WY',
    ),
  );
  /* Filter criterion: Content: Event Date -  start date (field_obp_event_date) */
  $handler->display->display_options['filters']['field_obp_event_date_value']['id'] = 'field_obp_event_date_value';
  $handler->display->display_options['filters']['field_obp_event_date_value']['table'] = 'field_data_field_obp_event_date';
  $handler->display->display_options['filters']['field_obp_event_date_value']['field'] = 'field_obp_event_date_value';
  $handler->display->display_options['filters']['field_obp_event_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_obp_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_obp_event_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_obp_event_date_value']['expose']['operator_id'] = 'field_obp_event_date_value_op';
  $handler->display->display_options['filters']['field_obp_event_date_value']['expose']['label'] = 'Event Date';
  $handler->display->display_options['filters']['field_obp_event_date_value']['expose']['operator'] = 'field_obp_event_date_value_op';
  $handler->display->display_options['filters']['field_obp_event_date_value']['expose']['identifier'] = 'field_obp_event_date_value';
  $handler->display->display_options['filters']['field_obp_event_date_value']['expose']['remember_roles'] = array(
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
    44 => 0,
  );
  $handler->display->display_options['filters']['field_obp_event_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_obp_event_date_value']['year_range'] = '-0:+3';
  /* Filter criterion: Content: Event Date -  start date (field_obp_event_date) */
  $handler->display->display_options['filters']['field_obp_event_date_value_1']['id'] = 'field_obp_event_date_value_1';
  $handler->display->display_options['filters']['field_obp_event_date_value_1']['table'] = 'field_data_field_obp_event_date';
  $handler->display->display_options['filters']['field_obp_event_date_value_1']['field'] = 'field_obp_event_date_value';
  $handler->display->display_options['filters']['field_obp_event_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_obp_event_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_obp_event_date_value_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_obp_event_date_value_1']['year_range'] = '-0:+3';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'OBP Event Map';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'more2';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_geofield';
  $handler->display->display_options['style_options']['name_field'] = 'nothing';
  $handler->display->display_options['style_options']['map'] = 'esri-world_street_map';
  $handler->display->display_options['style_options']['height'] = '460';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '4';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = '<none>';
  $handler->display->display_options['header']['area']['content'] = 'Search for upcoming events scheduled for your area.  Search by Event, Date Range, and/or State. ';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_geofield']['id'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_geofield']['delta_offset'] = '0';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Event Description';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: POC Email */
  $handler->display->display_options['fields']['field_poc_email']['id'] = 'field_poc_email';
  $handler->display->display_options['fields']['field_poc_email']['table'] = 'field_data_field_poc_email';
  $handler->display->display_options['fields']['field_poc_email']['field'] = 'field_poc_email';
  $handler->display->display_options['fields']['field_poc_email']['label'] = '';
  $handler->display->display_options['fields']['field_poc_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_poc_email']['element_label_colon'] = FALSE;
  /* Field: Content: POC Phone Number */
  $handler->display->display_options['fields']['field_poc_phone_number']['id'] = 'field_poc_phone_number';
  $handler->display->display_options['fields']['field_poc_phone_number']['table'] = 'field_data_field_poc_phone_number';
  $handler->display->display_options['fields']['field_poc_phone_number']['field'] = 'field_poc_phone_number';
  $handler->display->display_options['fields']['field_poc_phone_number']['label'] = '';
  $handler->display->display_options['fields']['field_poc_phone_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_poc_phone_number']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_obp_event_date']['id'] = 'field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['table'] = 'field_data_field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['field'] = 'field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_obp_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_obp_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_obp_event_date']['settings'] = array(
    'format_type' => 'search_api_facetapi_DAY',
    'custom_date_format' => '',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_obp_event_date']['delta_offset'] = '0';
  /* Field: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['field_address_administrative_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_administrative_area']['display_name'] = 1;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_locality']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="title">[title]</div>
<div class="email">[field_obp_event_date]</div>
<div class="phone">[field_address_locality]</div>
<div class="date">[field_address_administrative_area]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'training/obp_event_map';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'more2';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Event Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Local POC Contact Information */
  $handler->display->display_options['fields']['field_local_poc_contact_info']['id'] = 'field_local_poc_contact_info';
  $handler->display->display_options['fields']['field_local_poc_contact_info']['table'] = 'field_data_field_local_poc_contact_info';
  $handler->display->display_options['fields']['field_local_poc_contact_info']['field'] = 'field_local_poc_contact_info';
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
  $handler->display->display_options['fields']['value']['label'] = 'Like/Dislike';
  $handler->display->display_options['fields']['value']['element_type'] = 'div';
  $handler->display->display_options['fields']['value']['element_class'] = 'smallrate';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget_compact';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_obp_event_date']['id'] = 'field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['table'] = 'field_data_field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['field'] = 'field_obp_event_date';
  $handler->display->display_options['fields']['field_obp_event_date']['settings'] = array(
    'format_type' => 'search_api_facetapi_DAY',
    'custom_date_format' => '',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_obp_event_date']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event Date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Field: Federal Region (field_federal_region) */
  $handler->display->display_options['sorts']['field_federal_region_tid']['id'] = 'field_federal_region_tid';
  $handler->display->display_options['sorts']['field_federal_region_tid']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['sorts']['field_federal_region_tid']['field'] = 'field_federal_region_tid';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page_1' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $export['obp_event_map'] = $view;

  return $export;
}
