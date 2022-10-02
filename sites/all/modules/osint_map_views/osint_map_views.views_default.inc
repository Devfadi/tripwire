<?php

/**
 * @file
 * osint_map_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osint_map_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'domestic_ied_incident_map_key';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Domestic IED Incident Map Key';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = '<img src="/sites/all/themes/rubix_responsive_theme/images/icon-[tid].png">';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<div class="key-item"><span class="key-icon">[tid]</span><span class="key-name">[name]</span></div>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'profile_classification' => 'profile_classification',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['domestic_ied_incident_map_key'] = $view;

  $view = new view();
  $view->name = 'osint_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OSINT Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Domestic IED Incident Map';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    26 => '26',
    10 => '10',
    4 => '4',
    8 => '8',
    41 => '41',
    14 => '14',
    9 => '9',
    6 => '6',
    12 => '12',
    7 => '7',
    21 => '21',
    11 => '11',
    36 => '36',
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
          'format' => 'tripwire',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_profiles_classification_tid' => array(
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
    'field_device_description_tid' => array(
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
    'field_target_tid' => array(
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
    'field_address_administrative_area' => array(
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
    'field_event_date_value' => array(
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
        'datepicker_options' => 'dateFormat: "DD, MM dd, yy"',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_geofield';
  $handler->display->display_options['style_options']['map'] = 'bing';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results Message';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results for your specified search.  Please modify your criteria and try again.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Device Type/Description */
  $handler->display->display_options['fields']['field_device_description']['id'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['fields']['field_device_description']['field'] = 'field_device_description';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_geofield']['id'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield']['field'] = 'field_geofield';
  /* Field: Content: Incident Type/Classification */
  $handler->display->display_options['fields']['field_profiles_classification']['id'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['field'] = 'field_profiles_classification';
  /* Sort criterion: Content: Event Date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['order'] = 'DESC';
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
    'osint_item' => 'osint_item',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Incident Type/Classification (field_profiles_classification) */
  $handler->display->display_options['filters']['field_profiles_classification_tid']['id'] = 'field_profiles_classification_tid';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['field'] = 'field_profiles_classification_tid';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_profiles_classification_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profiles_classification_tid']['expose']['operator_id'] = 'field_profiles_classification_tid_op';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['expose']['label'] = 'Classification';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['expose']['operator'] = 'field_profiles_classification_tid_op';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['expose']['identifier'] = 'field_profiles_classification_tid';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_profiles_classification_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_profiles_classification_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profiles_classification_tid']['vocabulary'] = 'profile_classification';
  /* Filter criterion: Content: Device Type/Description (field_device_description) */
  $handler->display->display_options['filters']['field_device_description_tid']['id'] = 'field_device_description_tid';
  $handler->display->display_options['filters']['field_device_description_tid']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['filters']['field_device_description_tid']['field'] = 'field_device_description_tid';
  $handler->display->display_options['filters']['field_device_description_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_device_description_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_device_description_tid']['expose']['operator_id'] = 'field_device_description_tid_op';
  $handler->display->display_options['filters']['field_device_description_tid']['expose']['label'] = 'Device Description';
  $handler->display->display_options['filters']['field_device_description_tid']['expose']['operator'] = 'field_device_description_tid_op';
  $handler->display->display_options['filters']['field_device_description_tid']['expose']['identifier'] = 'field_device_description_tid';
  $handler->display->display_options['filters']['field_device_description_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_device_description_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_device_description_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_device_description_tid']['vocabulary'] = 'device_description';
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
    16 => 0,
    21 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    31 => 0,
    26 => 0,
  );
  $handler->display->display_options['filters']['field_federal_region_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_federal_region_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_federal_region_tid']['vocabulary'] = 'federal_region';
  /* Filter criterion: Content: Parent Infrastructure (field_target) */
  $handler->display->display_options['filters']['field_target_tid']['id'] = 'field_target_tid';
  $handler->display->display_options['filters']['field_target_tid']['table'] = 'field_data_field_target';
  $handler->display->display_options['filters']['field_target_tid']['field'] = 'field_target_tid';
  $handler->display->display_options['filters']['field_target_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_target_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_target_tid']['expose']['operator_id'] = 'field_target_tid_op';
  $handler->display->display_options['filters']['field_target_tid']['expose']['label'] = 'Target';
  $handler->display->display_options['filters']['field_target_tid']['expose']['operator'] = 'field_target_tid_op';
  $handler->display->display_options['filters']['field_target_tid']['expose']['identifier'] = 'field_target_tid';
  $handler->display->display_options['filters']['field_target_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_target_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_target_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_target_tid']['vocabulary'] = 'target';
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
      'title' => 'Washington',
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
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Incident Search';
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
    'field_address' => 'field_address',
    'field_device_description' => 'field_device_description',
    'field_federal_region' => 'field_federal_region',
    'field_profiles_classification' => 'field_profiles_classification',
    'field_address_administrative_area' => 'field_address_administrative_area',
    'field_address_locality' => 'field_address_locality',
    'body' => 'body',
  );
  /* Filter criterion: Content: Address - Country */
  $handler->display->display_options['filters']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['filters']['field_address_country']['group'] = 1;
  /* Filter criterion: Content: Event Date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_event_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_date_value']['expose']['operator_id'] = 'field_event_date_value_op';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['operator'] = 'field_event_date_value_op';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['identifier'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_event_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_event_date_value']['year_range'] = '-3:+0';

  /* Display: Domestic IED Incident Map */
  $handler = $view->new_display('page', 'Domestic IED Incident Map', 'page_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '300';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_osint_lat_lon';
  $handler->display->display_options['style_options']['name_field'] = 'field_event_date';
  $handler->display->display_options['style_options']['description_field'] = 'nothing';
  $handler->display->display_options['style_options']['map'] = 'esri-world_street_map';
  $handler->display->display_options['style_options']['height'] = '600';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '4';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['icon']['iconUrl'] = '/sites/all/themes/rubix_responsive_theme/images/icon-[node:field-profiles-classification:tid].png';
  $handler->display->display_options['style_options']['icon']['iconSize']['x'] = '25';
  $handler->display->display_options['style_options']['icon']['iconSize']['y'] = '41';
  $handler->display->display_options['style_options']['icon']['iconAnchor']['x'] = '14';
  $handler->display->display_options['style_options']['icon']['iconAnchor']['y'] = '41';
  $handler->display->display_options['style_options']['icon']['popupAnchor']['x'] = '0';
  $handler->display->display_options['style_options']['icon']['popupAnchor']['y'] = '-32';
  $handler->display->display_options['style_options']['icon']['html'] = 'field_profiles_classification';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Device Type/Description */
  $handler->display->display_options['fields']['field_device_description']['id'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['fields']['field_device_description']['field'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['alter']['text'] = '<a href="[path]">[field_event_date]</a>';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_profiles_classification']['label'] = '';
  $handler->display->display_options['fields']['field_profiles_classification']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profiles_classification']['alter']['text'] = '<a href="[path]">[field_profiles_classification]</a>';
  $handler->display->display_options['fields']['field_profiles_classification']['element_type'] = '0';
  $handler->display->display_options['fields']['field_profiles_classification']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profiles_classification']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profiles_classification']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_geofield']['id'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_geofield']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>[field_device_description]
<br>[field_address_locality], [field_address_administrative_area]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Lat/Long */
  $handler->display->display_options['fields']['field_osint_lat_lon']['id'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['table'] = 'field_data_field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['field'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['label'] = '';
  $handler->display->display_options['fields']['field_osint_lat_lon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_osint_lat_lon']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_osint_lat_lon']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'domestic-ied-incident-map';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date' => 'field_date',
    'field_profiles_classification' => 'field_profiles_classification',
    'field_device_description' => 'field_device_description',
    'field_federal_region' => 'field_federal_region',
    'field_incident_description' => 'field_incident_description',
    'field_address' => 'field_address',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profiles_classification' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_device_description' => array(
      'sortable' => 0,
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
    'field_incident_description' => array(
      'sortable' => 0,
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Incident Type/Classification */
  $handler->display->display_options['fields']['field_profiles_classification']['id'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['field'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['label'] = 'Classification';
  $handler->display->display_options['fields']['field_profiles_classification']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Device Type/Description */
  $handler->display->display_options['fields']['field_device_description']['id'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['fields']['field_device_description']['field'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;

  /* Display: Domestic IED Incident Map (POST-AUTH) */
  $handler = $view->new_display('block', 'Domestic IED Incident Map (POST-AUTH)', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_osint_lat_lon';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'nothing';
  $handler->display->display_options['style_options']['map'] = 'esri-world_street_map';
  $handler->display->display_options['style_options']['height'] = '300';
  $handler->display->display_options['style_options']['hide_empty'] = 1;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '4';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['icon']['iconUrl'] = '/sites/all/themes/rubix_responsive_theme/images/icon-[node:field-profiles-classification:tid].png';
  $handler->display->display_options['style_options']['icon']['iconSize']['x'] = '25';
  $handler->display->display_options['style_options']['icon']['iconSize']['y'] = '41';
  $handler->display->display_options['style_options']['icon']['iconAnchor']['x'] = '14';
  $handler->display->display_options['style_options']['icon']['iconAnchor']['y'] = '41';
  $handler->display->display_options['style_options']['icon']['popupAnchor']['x'] = '0';
  $handler->display->display_options['style_options']['icon']['popupAnchor']['y'] = '-32';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/domestic-ied-incident-map">Domestic IED Incident Map</a>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Incident Type/Classification */
  $handler->display->display_options['fields']['field_profiles_classification']['id'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['field'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['label'] = '';
  $handler->display->display_options['fields']['field_profiles_classification']['alter']['text'] = '<a href="[path]">[field_profiles_classification]</a>';
  $handler->display->display_options['fields']['field_profiles_classification']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profiles_classification']['type'] = 'taxonomy_term_reference_plain';
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>[field_profiles_classification] 
<br>[field_address_locality], [field_address_administrative_area]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Lat/Long */
  $handler->display->display_options['fields']['field_osint_lat_lon']['id'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['table'] = 'field_data_field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['field'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_osint_lat_lon']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
    'osint_item' => 'osint_item',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Address - Country */
  $handler->display->display_options['filters']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['value'] = array(
    'US' => 'US',
  );
  /* Filter criterion: Content: Event Date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = '2 years';

  /* Display: Block 2 */
  $handler = $view->new_display('block', 'Block 2', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['alter']['text'] = '<a href="[path]">[field_event_date]</a>';
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
  $handler->display->display_options['fields']['field_profiles_classification']['label'] = 'Classification';
  $handler->display->display_options['fields']['field_profiles_classification']['alter']['text'] = '<a href="[path]">[field_profiles_classification]</a>';
  $handler->display->display_options['fields']['field_profiles_classification']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Device Type/Description */
  $handler->display->display_options['fields']['field_device_description']['id'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['fields']['field_device_description']['field'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['label'] = 'Device Description';
  $handler->display->display_options['fields']['field_device_description']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region_1']['id'] = 'field_federal_region_1';
  $handler->display->display_options['fields']['field_federal_region_1']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region_1']['field'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_federal_region_1']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_geofield']['id'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_geofield']['delta_offset'] = '0';
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

  /* Display: IED Map CSV Export */
  $handler = $view->new_display('views_data_export', 'IED Map CSV Export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Device Type/Description */
  $handler->display->display_options['fields']['field_device_description']['id'] = 'field_device_description';
  $handler->display->display_options['fields']['field_device_description']['table'] = 'field_data_field_device_description';
  $handler->display->display_options['fields']['field_device_description']['field'] = 'field_device_description';
  /* Field: Field: Federal Region */
  $handler->display->display_options['fields']['field_federal_region']['id'] = 'field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['table'] = 'field_data_field_federal_region';
  $handler->display->display_options['fields']['field_federal_region']['field'] = 'field_federal_region';
  /* Field: Content: Incident Type/Classification */
  $handler->display->display_options['fields']['field_profiles_classification']['id'] = 'field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification']['field'] = 'field_profiles_classification';
  /* Field: Content: Actor */
  $handler->display->display_options['fields']['field_osint_actor']['id'] = 'field_osint_actor';
  $handler->display->display_options['fields']['field_osint_actor']['table'] = 'field_data_field_osint_actor';
  $handler->display->display_options['fields']['field_osint_actor']['field'] = 'field_osint_actor';
  /* Field: Content: Arrested */
  $handler->display->display_options['fields']['field_osint_arrested']['id'] = 'field_osint_arrested';
  $handler->display->display_options['fields']['field_osint_arrested']['table'] = 'field_data_field_osint_arrested';
  $handler->display->display_options['fields']['field_osint_arrested']['field'] = 'field_osint_arrested';
  $handler->display->display_options['fields']['field_osint_arrested']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Automated Phone */
  $handler->display->display_options['fields']['field_osint_automated_phone']['id'] = 'field_osint_automated_phone';
  $handler->display->display_options['fields']['field_osint_automated_phone']['table'] = 'field_data_field_osint_automated_phone';
  $handler->display->display_options['fields']['field_osint_automated_phone']['field'] = 'field_osint_automated_phone';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Dead */
  $handler->display->display_options['fields']['field_osint_dead']['id'] = 'field_osint_dead';
  $handler->display->display_options['fields']['field_osint_dead']['table'] = 'field_data_field_osint_dead';
  $handler->display->display_options['fields']['field_osint_dead']['field'] = 'field_osint_dead';
  $handler->display->display_options['fields']['field_osint_dead']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_osint_email']['id'] = 'field_osint_email';
  $handler->display->display_options['fields']['field_osint_email']['table'] = 'field_data_field_osint_email';
  $handler->display->display_options['fields']['field_osint_email']['field'] = 'field_osint_email';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
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
  $handler->display->display_options['fields']['field_profiles_classification_1']['id'] = 'field_profiles_classification_1';
  $handler->display->display_options['fields']['field_profiles_classification_1']['table'] = 'field_data_field_profiles_classification';
  $handler->display->display_options['fields']['field_profiles_classification_1']['field'] = 'field_profiles_classification';
  /* Field: Content: Injured */
  $handler->display->display_options['fields']['field_osint_injured']['id'] = 'field_osint_injured';
  $handler->display->display_options['fields']['field_osint_injured']['table'] = 'field_data_field_osint_injured';
  $handler->display->display_options['fields']['field_osint_injured']['field'] = 'field_osint_injured';
  $handler->display->display_options['fields']['field_osint_injured']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: International Nexus */
  $handler->display->display_options['fields']['field_osint_international_nexus']['id'] = 'field_osint_international_nexus';
  $handler->display->display_options['fields']['field_osint_international_nexus']['table'] = 'field_data_field_osint_international_nexus';
  $handler->display->display_options['fields']['field_osint_international_nexus']['field'] = 'field_osint_international_nexus';
  /* Field: Content: Lat/Long */
  $handler->display->display_options['fields']['field_osint_lat_lon']['id'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['table'] = 'field_data_field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['field'] = 'field_osint_lat_lon';
  $handler->display->display_options['fields']['field_osint_lat_lon']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_osint_lat_lon']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Main Charge */
  $handler->display->display_options['fields']['field_main_charge']['id'] = 'field_main_charge';
  $handler->display->display_options['fields']['field_main_charge']['table'] = 'field_data_field_main_charge';
  $handler->display->display_options['fields']['field_main_charge']['field'] = 'field_main_charge';
  /* Field: Content: Other Notes */
  $handler->display->display_options['fields']['field_osint_other_notes']['id'] = 'field_osint_other_notes';
  $handler->display->display_options['fields']['field_osint_other_notes']['table'] = 'field_data_field_osint_other_notes';
  $handler->display->display_options['fields']['field_osint_other_notes']['field'] = 'field_osint_other_notes';
  /* Field: Content: Parent Infrastructure */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'field_data_field_target';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_osint_phone']['id'] = 'field_osint_phone';
  $handler->display->display_options['fields']['field_osint_phone']['table'] = 'field_data_field_osint_phone';
  $handler->display->display_options['fields']['field_osint_phone']['field'] = 'field_osint_phone';
  /* Field: Content: Religious Nexus */
  $handler->display->display_options['fields']['field_osint_religious_nexus']['id'] = 'field_osint_religious_nexus';
  $handler->display->display_options['fields']['field_osint_religious_nexus']['table'] = 'field_data_field_osint_religious_nexus';
  $handler->display->display_options['fields']['field_osint_religious_nexus']['field'] = 'field_osint_religious_nexus';
  /* Field: Content: School Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  /* Field: Content: Social Media */
  $handler->display->display_options['fields']['field_osint_social_media']['id'] = 'field_osint_social_media';
  $handler->display->display_options['fields']['field_osint_social_media']['table'] = 'field_data_field_osint_social_media';
  $handler->display->display_options['fields']['field_osint_social_media']['field'] = 'field_osint_social_media';
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_osint_source']['id'] = 'field_osint_source';
  $handler->display->display_options['fields']['field_osint_source']['table'] = 'field_data_field_osint_source';
  $handler->display->display_options['fields']['field_osint_source']['field'] = 'field_osint_source';
  /* Field: Content: Unspecified */
  $handler->display->display_options['fields']['field_osint_unspecified']['id'] = 'field_osint_unspecified';
  $handler->display->display_options['fields']['field_osint_unspecified']['table'] = 'field_data_field_osint_unspecified';
  $handler->display->display_options['fields']['field_osint_unspecified']['field'] = 'field_osint_unspecified';
  /* Field: Content: Updated Phone */
  $handler->display->display_options['fields']['field_osint_updated_phone']['id'] = 'field_osint_updated_phone';
  $handler->display->display_options['fields']['field_osint_updated_phone']['table'] = 'field_data_field_osint_updated_phone';
  $handler->display->display_options['fields']['field_osint_updated_phone']['field'] = 'field_osint_updated_phone';
  /* Field: Content: Verbal */
  $handler->display->display_options['fields']['field_osint_verbal']['id'] = 'field_osint_verbal';
  $handler->display->display_options['fields']['field_osint_verbal']['table'] = 'field_data_field_osint_verbal';
  $handler->display->display_options['fields']['field_osint_verbal']['field'] = 'field_osint_verbal';
  /* Field: Content: Written */
  $handler->display->display_options['fields']['field_osint_written']['id'] = 'field_osint_written';
  $handler->display->display_options['fields']['field_osint_written']['table'] = 'field_data_field_osint_written';
  $handler->display->display_options['fields']['field_osint_written']['field'] = 'field_osint_written';
  $handler->display->display_options['path'] = 'domestic-ied-incident-map-export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '200';
  $export['osint_map'] = $view;

  return $export;
}
