<?php
/**
 * @file
 * tripwire_people.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tripwire_people_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'people';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
      'butons_as_secondary_options' => 0,
    ),
    'uid' => array(
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
    'mail' => array(
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
    'field_citizenship_value' => array(
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
    'field_verification_contact_email_value' => array(
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
    'rid' => array(
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
    'field_account_states_tid' => array(
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
    'field_user_status_tid' => array(
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
    'field_evc_status_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
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
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total Accounts: @total';
  /* Relationship: Profile - Personal Info */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['ui_name'] = 'Profile - Personal Info';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile - Personal Info';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'personal_information' => 'personal_information',
  );
  /* Relationship: Profile - Employment Info */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['ui_name'] = 'Profile - Employment Info';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Profile - Employment Info';
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'employment_information' => 'employment_information',
  );
  /* Relationship: Profile - EVC */
  $handler->display->display_options['relationships']['profile_2']['id'] = 'profile_2';
  $handler->display->display_options['relationships']['profile_2']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_2']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_2']['ui_name'] = 'Profile - EVC';
  $handler->display->display_options['relationships']['profile_2']['label'] = 'Profile - EVC';
  $handler->display->display_options['relationships']['profile_2']['bundle_types'] = array(
    'indicate_evc' => 'indicate_evc',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
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
  /* Field: Profile: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['relationship'] = 'profile_1';
  /* Field: Field: State/Province/Region */
  $handler->display->display_options['fields']['field_state_province_region']['id'] = 'field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['table'] = 'field_data_field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['field'] = 'field_state_province_region';
  $handler->display->display_options['fields']['field_state_province_region']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_state_province_region']['label'] = 'State';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['type'] = 'ul';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Drupal Status';
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['label'] = 'TW Account Status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_status']['delta_offset'] = '0';
  /* Field: User: Account States */
  $handler->display->display_options['fields']['field_account_states']['id'] = 'field_account_states';
  $handler->display->display_options['fields']['field_account_states']['table'] = 'field_data_field_account_states';
  $handler->display->display_options['fields']['field_account_states']['field'] = 'field_account_states';
  $handler->display->display_options['fields']['field_account_states']['label'] = 'TW Account State';
  $handler->display->display_options['fields']['field_account_states']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: EVC Status */
  $handler->display->display_options['fields']['field_evc_status']['id'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['field'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: UID only */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['ui_name'] = 'UID only';
  $handler->display->display_options['fields']['uid_1']['label'] = '';
  $handler->display->display_options['fields']['uid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid_1']['link_to_user'] = FALSE;
  /* Field: Unbind */
  $handler->display->display_options['fields']['module']['id'] = 'module';
  $handler->display->display_options['fields']['module']['table'] = 'authmap';
  $handler->display->display_options['fields']['module']['field'] = 'module';
  $handler->display->display_options['fields']['module']['ui_name'] = 'Unbind';
  $handler->display->display_options['fields']['module']['label'] = '';
  $handler->display->display_options['fields']['module']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['module']['alter']['text'] = '<a href="/admin/help-desk/helper/[uid_1]/hsin_unbind">Unbind HSIN User</a>';
  $handler->display->display_options['fields']['module']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Edit';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/user/[uid]/edit">Edit</a>';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['uid']['group_info']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['group_info']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['uid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Profile: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Profile: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Profile: Citizenship (field_citizenship) */
  $handler->display->display_options['filters']['field_citizenship_value']['id'] = 'field_citizenship_value';
  $handler->display->display_options['filters']['field_citizenship_value']['table'] = 'field_data_field_citizenship';
  $handler->display->display_options['filters']['field_citizenship_value']['field'] = 'field_citizenship_value';
  $handler->display->display_options['filters']['field_citizenship_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_citizenship_value']['group'] = 1;
  $handler->display->display_options['filters']['field_citizenship_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_citizenship_value']['expose']['operator_id'] = 'field_citizenship_value_op';
  $handler->display->display_options['filters']['field_citizenship_value']['expose']['label'] = 'Citizenship';
  $handler->display->display_options['filters']['field_citizenship_value']['expose']['operator'] = 'field_citizenship_value_op';
  $handler->display->display_options['filters']['field_citizenship_value']['expose']['identifier'] = 'field_citizenship_value';
  $handler->display->display_options['filters']['field_citizenship_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Profile: Employment Verification Contact Email Address (field_verification_contact_email) */
  $handler->display->display_options['filters']['field_verification_contact_email_value']['id'] = 'field_verification_contact_email_value';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['table'] = 'field_data_field_verification_contact_email';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['field'] = 'field_verification_contact_email_value';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['group'] = 1;
  $handler->display->display_options['filters']['field_verification_contact_email_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_verification_contact_email_value']['expose']['operator_id'] = 'field_verification_contact_email_value_op';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['expose']['label'] = 'EVC Email Address';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['expose']['operator'] = 'field_verification_contact_email_value_op';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['expose']['identifier'] = 'field_verification_contact_email_value';
  $handler->display->display_options['filters']['field_verification_contact_email_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Drupal Status';
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
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Role';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Account States (field_account_states) */
  $handler->display->display_options['filters']['field_account_states_tid']['id'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['table'] = 'field_data_field_account_states';
  $handler->display->display_options['filters']['field_account_states_tid']['field'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_account_states_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['operator_id'] = 'field_account_states_tid_op';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['label'] = 'TW Account State';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['operator'] = 'field_account_states_tid_op';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['identifier'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_account_states_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_account_states_tid']['vocabulary'] = 'account_states';
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_status_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['operator_id'] = 'field_user_status_tid_op';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['label'] = 'TW Account Status';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['operator'] = 'field_user_status_tid_op';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['identifier'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_evc_status_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['operator_id'] = 'field_evc_status_tid_op';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['label'] = 'EVC Status';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['operator'] = 'field_evc_status_tid_op';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['identifier'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['hierarchy'] = 1;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';
  $handler->display->display_options['filters']['uid_raw']['group'] = 1;
  /* Filter criterion: Profile: Subscribe to TRIPwire communications? (field_subscribe_to_tripwire_comm) */
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['id'] = 'field_subscribe_to_tripwire_comm_value';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['table'] = 'field_data_field_subscribe_to_tripwire_comm';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['field'] = 'field_subscribe_to_tripwire_comm_value';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['expose']['operator_id'] = 'field_subscribe_to_tripwire_comm_value_op';
  $handler->display->display_options['filters']['field_subscribe_to_tripwire_comm_value']['expose']['label'] = 'Subscription';
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
  /* Filter criterion: Profile: Employer Name (field_employer_name) */
  $handler->display->display_options['filters']['field_employer_name_value']['id'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['table'] = 'field_data_field_employer_name';
  $handler->display->display_options['filters']['field_employer_name_value']['field'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['relationship'] = 'profile_1';
  $handler->display->display_options['filters']['field_employer_name_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_employer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['operator_id'] = 'field_employer_name_value_op';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['label'] = 'Employer Name';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['operator'] = 'field_employer_name_value_op';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['identifier'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['remember_roles'] = array(
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/people';
  $export['people'] = $view;

  return $export;
}
