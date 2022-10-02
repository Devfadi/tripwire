<?php

/**
 * @file
 * user_registrations_by_state.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function user_registrations_by_state_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_registrations_by_state';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Registrations by State';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Registrations by State';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    41 => '41',
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile - Personal Information';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'personal_information' => 'personal_information',
  );
  /* Relationship: Profile - Employer */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['ui_name'] = 'Profile - Employer';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Profile - Employer';
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'employment_information' => 'employment_information',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Registration Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'search_api_facetapi_DAY';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Profile: Employer Name */
  $handler->display->display_options['fields']['field_employer_name']['id'] = 'field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['table'] = 'field_data_field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['field'] = 'field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_employer_name']['label'] = 'Employer';
  /* Field: Field: State/Province/Region */
  $handler->display->display_options['fields']['field_state_province_region']['id'] = 'field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['table'] = 'field_data_field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['field'] = 'field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_state_province_region']['delta_offset'] = '0';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Created date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'users';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Registration Date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Field: State/Province/Region (field_state_province_region) */
  $handler->display->display_options['filters']['field_state_province_region_value']['id'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['table'] = 'field_data_field_state_province_region';
  $handler->display->display_options['filters']['field_state_province_region_value']['field'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['relationship'] = 'profile_1';
  $handler->display->display_options['filters']['field_state_province_region_value']['group'] = 1;
  $handler->display->display_options['filters']['field_state_province_region_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['operator_id'] = 'field_state_province_region_value_op';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['operator'] = 'field_state_province_region_value_op';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['identifier'] = 'field_state_province_region_value';
  $handler->display->display_options['filters']['field_state_province_region_value']['expose']['remember_roles'] = array(
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

  /* Display: Registrations by State */
  $handler = $view->new_display('page', 'Registrations by State', 'page');
  $handler->display->display_options['path'] = 'admin/dashboard/user-states';

  /* Display: Introduction to TRIPwire */
  $handler = $view->new_display('page', 'Introduction to TRIPwire', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Registration Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'search_api_facetapi_DAY';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Profile: Employer Name */
  $handler->display->display_options['fields']['field_employer_name']['id'] = 'field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['table'] = 'field_data_field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['field'] = 'field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_employer_name']['label'] = 'Employer';
  /* Field: Profile: Please tell us how you found out about TRIPwire */
  $handler->display->display_options['fields']['field_please_tell_us_how_you_fou']['id'] = 'field_please_tell_us_how_you_fou';
  $handler->display->display_options['fields']['field_please_tell_us_how_you_fou']['table'] = 'field_data_field_please_tell_us_how_you_fou';
  $handler->display->display_options['fields']['field_please_tell_us_how_you_fou']['field'] = 'field_please_tell_us_how_you_fou';
  $handler->display->display_options['fields']['field_please_tell_us_how_you_fou']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_please_tell_us_how_you_fou']['label'] = 'How the user found out about TRIPwire';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Created date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'users';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Registration Date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Profile: Please tell us how you found out about TRIPwire (field_please_tell_us_how_you_fou) */
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['id'] = 'field_please_tell_us_how_you_fou_value';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['table'] = 'field_data_field_please_tell_us_how_you_fou';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['field'] = 'field_please_tell_us_how_you_fou_value';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['expose']['operator_id'] = 'field_please_tell_us_how_you_fou_value_op';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['expose']['label'] = 'Please tell us how you found out about TRIPwire';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['expose']['operator'] = 'field_please_tell_us_how_you_fou_value_op';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['expose']['identifier'] = 'field_please_tell_us_how_you_fou_value';
  $handler->display->display_options['filters']['field_please_tell_us_how_you_fou_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'admin/reports/introduction-tw';
  $export['user_registrations_by_state'] = $view;

  return $export;
}
