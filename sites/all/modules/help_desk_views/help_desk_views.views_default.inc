<?php
/**
 * @file
 * help_desk_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function help_desk_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'evc_vip';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tw_registration_evc_email';
  $view->human_name = 'EVC VIP';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'VIP - Pre EVC Due';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    41 => '41',
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
    'evc_hash' => 'evc_hash',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'evc_hash' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'These VIP accounts are coming up for EVC Re-Verification in the next 90 days.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No accounts found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: EVC Mail: UID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'indicate_evc' => 'indicate_evc',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: EVC Mail: Verification Date */
  $handler->display->display_options['fields']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['fields']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['label'] = 'EVC Due';
  $handler->display->display_options['fields']['verification_date']['date_format'] = 'long';
  $handler->display->display_options['fields']['verification_date']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  /* Sort criterion: EVC Mail: Verification Date */
  $handler->display->display_options['sorts']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['sorts']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['sorts']['verification_date']['field'] = 'verification_date';
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4786 => '4786',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    36 => '36',
  );
  /* Filter criterion: EVC Mail: Verification Date */
  $handler->display->display_options['filters']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['filters']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['filters']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['filters']['verification_date']['operator'] = 'between';
  $handler->display->display_options['filters']['verification_date']['value']['min'] = '-365 days';
  $handler->display->display_options['filters']['verification_date']['value']['max'] = '-275 days';
  $handler->display->display_options['filters']['verification_date']['value']['type'] = 'offset';

  /* Display: VIP Annual Re-Vet */
  $handler = $view->new_display('page', 'VIP Annual Re-Vet', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'VIP Annual Re-Vet';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'These VIP accounts are coming up for EVC Re-Verification in the next 90 days.
<h3>Total Accounts in Queue: @total</h3>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['relationship'] = 'uid';
  /* Field: User: EVC Status */
  $handler->display->display_options['fields']['field_evc_status']['id'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['field'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['relationship'] = 'uid';
  /* Field: Profile: Employment Verification Contact */
  $handler->display->display_options['fields']['field_employment_verification_co']['id'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['table'] = 'field_data_field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['field'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Email Address */
  $handler->display->display_options['fields']['field_verification_contact_email']['id'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['table'] = 'field_data_field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['field'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_verification_contact_email']['type'] = 'text_plain';
  /* Field: Profile: Employment Verification Contact Phone Number */
  $handler->display->display_options['fields']['field_employment_verification_p']['id'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['table'] = 'field_data_field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['field'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_employment_verification_p']['type'] = 'text_plain';
  /* Field: Profile: Employment Verification Contact Title */
  $handler->display->display_options['fields']['field_verification_contact_title']['id'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['table'] = 'field_data_field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['field'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_verification_contact_title']['type'] = 'text_plain';
  /* Field: EVC Mail: Verification Date */
  $handler->display->display_options['fields']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['fields']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['label'] = 'EVC Verification Date';
  $handler->display->display_options['fields']['verification_date']['date_format'] = 'inverse time span';
  $handler->display->display_options['fields']['verification_date']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Do Not Approve';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/registrations/dna/[uid]">Do Not Approve</a>';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'uid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit User';
  $handler->display->display_options['path'] = 'admin/help-desk/vip-pre-evc-due';

  /* Display: VIP - EVC Due */
  $handler = $view->new_display('page', 'VIP - EVC Due', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'VIP - EVC Due';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'These VIP accounts are past due for EVC Re-Verification.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: EVC Mail: Verification Date */
  $handler->display->display_options['fields']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['fields']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['label'] = 'EVC Due';
  $handler->display->display_options['fields']['verification_date']['date_format'] = 'long';
  $handler->display->display_options['fields']['verification_date']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Approve Account';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/evc-confirmation/approved/[uid]/vip-approve">Approve Account</a>';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4781 => '4781',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    36 => '36',
  );
  /* Filter criterion: EVC Mail: Verification Date */
  $handler->display->display_options['filters']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['filters']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['filters']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['filters']['verification_date']['operator'] = '<=';
  $handler->display->display_options['filters']['verification_date']['value']['min'] = '-365 days';
  $handler->display->display_options['filters']['verification_date']['value']['max'] = '-275 days';
  $handler->display->display_options['filters']['verification_date']['value']['value'] = '-365 days';
  $handler->display->display_options['filters']['verification_date']['value']['type'] = 'offset';
  /* Filter criterion: EVC Mail: Verification Status */
  $handler->display->display_options['filters']['verification_status']['id'] = 'verification_status';
  $handler->display->display_options['filters']['verification_status']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['filters']['verification_status']['field'] = 'verification_status';
  $handler->display->display_options['filters']['verification_status']['value'] = '1';
  $handler->display->display_options['path'] = 'admin/help-desk/vip-evc-due';

  /* Display: VIP - EVC Edit */
  $handler = $view->new_display('page', 'VIP - EVC Edit', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'VIP - EVC Edit';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: EVC Mail: Verification Date */
  $handler->display->display_options['fields']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['fields']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['label'] = 'EVC Due';
  $handler->display->display_options['fields']['verification_date']['date_format'] = 'long';
  $handler->display->display_options['fields']['verification_date']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'EVC Updated';
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/evc/updated/[uid]/vip">EVC Updated</a>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    36 => '36',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filter criterion: EVC Mail: Verification Date */
  $handler->display->display_options['filters']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['filters']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['filters']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['filters']['verification_date']['operator'] = '<=';
  $handler->display->display_options['filters']['verification_date']['value']['min'] = '-365 days';
  $handler->display->display_options['filters']['verification_date']['value']['max'] = '-275 days';
  $handler->display->display_options['filters']['verification_date']['value']['value'] = '-275 days';
  $handler->display->display_options['filters']['verification_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['verification_date']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/help-desk/vip-evc-edit';
  $export['evc_vip'] = $view;

  $view = new view();
  $view->name = 'help_desk';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Help Desk';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'New User Registrations';
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
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'status' => 'status',
    'field_user_status' => 'field_user_status',
    'field_account_states' => 'field_account_states',
    'created_1' => 'created_1',
    'field_password_email_sent' => 'field_password_email_sent',
    'created' => 'created',
    'uid' => 'uid',
    'uid_1' => 'uid_1',
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
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'field_user_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_account_states' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_password_email_sent' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid_1' => array(
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
  $handler->display->display_options['header']['result']['content'] = 'Total Accounts in Queue: @total';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'personal_information' => 'personal_information',
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
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_first_name] [field_last_name] ';
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
  $handler->display->display_options['fields']['field_user_status']['label'] = 'Account Status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_status']['delta_offset'] = '0';
  /* Field: User: Account States */
  $handler->display->display_options['fields']['field_account_states']['id'] = 'field_account_states';
  $handler->display->display_options['fields']['field_account_states']['table'] = 'field_data_field_account_states';
  $handler->display->display_options['fields']['field_account_states']['field'] = 'field_account_states';
  $handler->display->display_options['fields']['field_account_states']['label'] = 'Account State';
  $handler->display->display_options['fields']['field_account_states']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Hidden registration date field */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'users';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['ui_name'] = 'Hidden registration date field';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  /* Field: User: Password email sent */
  $handler->display->display_options['fields']['field_password_email_sent']['id'] = 'field_password_email_sent';
  $handler->display->display_options['fields']['field_password_email_sent']['table'] = 'field_data_field_password_email_sent';
  $handler->display->display_options['fields']['field_password_email_sent']['field'] = 'field_password_email_sent';
  $handler->display->display_options['fields']['field_password_email_sent']['label'] = 'Time Since Last Email';
  $handler->display->display_options['fields']['field_password_email_sent']['empty'] = '[created_1] ';
  $handler->display->display_options['fields']['field_password_email_sent']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_password_email_sent']['settings'] = array(
    'interval' => '2',
    'interval_display' => 'time ago',
  );
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Registration Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Resend Initial Email Verification Email';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/registrations/resend/[uid]">Resend Email</a>';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = 'Do Not Approve';
  $handler->display->display_options['fields']['uid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = '<a href="/admin/help-desk/registrations/dna/[uid_1]">Do Not Approve</a>';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    4406 => '4406',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
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
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name';
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
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'User Role';
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
    36 => 0,
    41 => 0,
  );

  /* Display: New User Registrations */
  $handler = $view->new_display('page', 'New User Registrations', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Awaiting Verification';
  $handler->display->display_options['path'] = 'admin/help-desk/registrations';

  /* Display: EVC */
  $handler = $view->new_display('page', 'EVC', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'EVC Initial Employment Verification';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'indicate_evc' => 'indicate_evc',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: EVC Status */
  $handler->display->display_options['fields']['field_evc_status']['id'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['field'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['label'] = 'Account Status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_status']['delta_offset'] = '0';
  /* Field: Profile: Employment Verification Contact */
  $handler->display->display_options['fields']['field_employment_verification_co']['id'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['table'] = 'field_data_field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['field'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Email Address */
  $handler->display->display_options['fields']['field_verification_contact_email']['id'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['table'] = 'field_data_field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['field'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Phone Number */
  $handler->display->display_options['fields']['field_employment_verification_p']['id'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['table'] = 'field_data_field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['field'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Title */
  $handler->display->display_options['fields']['field_verification_contact_title']['id'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['table'] = 'field_data_field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['field'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['relationship'] = 'profile';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = 'Edit EVC';
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = '<a href="/user/[uid_1]/edit/indicate_evc?destination=admin/help-desk/evc">Edit user EVC data</a>';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Send EVC Updated Email';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/evc/updated/[uid]">Send Email</a>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4791 => '4791',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  $handler->display->display_options['path'] = 'admin/help-desk/evc';

  /* Display: EVC Approved */
  $handler = $view->new_display('page', 'EVC Approved', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Awaiting Approval';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total Accounts in Queue: @total';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'indicate_evc' => 'indicate_evc',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: EVC Status */
  $handler->display->display_options['fields']['field_evc_status']['id'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['field'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['label'] = 'Account Status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_status']['delta_offset'] = '0';
  /* Field: Profile: Employment Verification Contact */
  $handler->display->display_options['fields']['field_employment_verification_co']['id'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['table'] = 'field_data_field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['field'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Email Address */
  $handler->display->display_options['fields']['field_verification_contact_email']['id'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['table'] = 'field_data_field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['field'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Phone Number */
  $handler->display->display_options['fields']['field_employment_verification_p']['id'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['table'] = 'field_data_field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['field'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Title */
  $handler->display->display_options['fields']['field_verification_contact_title']['id'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['table'] = 'field_data_field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['field'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['relationship'] = 'profile';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = 'Edit EVC';
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = '<a href="/user/[uid_1]/edit/indicate_evc?destination=admin/help-desk/evc">Edit user EVC data</a>';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Approve Account';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/evc-confirmation/approved/[uid]">Approve Account</a>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4786 => '4786',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    4401 => '4401',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  $handler->display->display_options['path'] = 'admin/help-desk/evc-confirmation';

  /* Display: Inactive Users */
  $handler = $view->new_display('page', 'Inactive Users', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Inactive Users';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_status']['delta_offset'] = '0';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'long';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = 'Do Not Approve';
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = '<a href="/admin/help-desk/registrations/dna/[uid_1]/inactive">Do Not Approve</a>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    4771 => '4771',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  /* Filter criterion: User: Account States (field_account_states) */
  $handler->display->display_options['filters']['field_account_states_tid']['id'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['table'] = 'field_data_field_account_states';
  $handler->display->display_options['filters']['field_account_states_tid']['field'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['value'] = array(
    4746 => '4746',
  );
  $handler->display->display_options['filters']['field_account_states_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_account_states_tid']['vocabulary'] = 'account_states';
  /* Filter criterion: User: Last access */
  $handler->display->display_options['filters']['access']['id'] = 'access';
  $handler->display->display_options['filters']['access']['table'] = 'users';
  $handler->display->display_options['filters']['access']['field'] = 'access';
  $handler->display->display_options['filters']['access']['operator'] = '<=';
  $handler->display->display_options['filters']['access']['value']['value'] = '-100 days';
  $handler->display->display_options['filters']['access']['value']['type'] = 'offset';
  $handler->display->display_options['path'] = 'admin/help-desk/inactive-users';

  /* Display: Annual EVC */
  $handler = $view->new_display('page', 'Annual EVC', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'EVC Annual Re-Vet';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'indicate_evc' => 'indicate_evc',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: EVC Status */
  $handler->display->display_options['fields']['field_evc_status']['id'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['field'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['label'] = 'Account Status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_status']['delta_offset'] = '0';
  /* Field: Profile: Employment Verification Contact */
  $handler->display->display_options['fields']['field_employment_verification_co']['id'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['table'] = 'field_data_field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['field'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Email Address */
  $handler->display->display_options['fields']['field_verification_contact_email']['id'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['table'] = 'field_data_field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['field'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Phone Number */
  $handler->display->display_options['fields']['field_employment_verification_p']['id'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['table'] = 'field_data_field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['field'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Title */
  $handler->display->display_options['fields']['field_verification_contact_title']['id'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['table'] = 'field_data_field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['field'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['relationship'] = 'profile';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = 'Edit EVC';
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = '<a href="/user/[uid_1]/edit/indicate_evc?destination=admin/help-desk/evc">Edit user EVC data</a>';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Resend EVC Updated Email';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/evc/updated/[uid]/annual">Resend Email</a>';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_2']['id'] = 'uid_2';
  $handler->display->display_options['fields']['uid_2']['table'] = 'users';
  $handler->display->display_options['fields']['uid_2']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_2']['label'] = 'Do Not Approve';
  $handler->display->display_options['fields']['uid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_2']['alter']['text'] = '<a href="/admin/help-desk/registrations/dna/[uid_2]/inactive">Do Not Approve</a>';
  $handler->display->display_options['fields']['uid_2']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4781 => '4781',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  /* Filter criterion: User: Account States (field_account_states) */
  $handler->display->display_options['filters']['field_account_states_tid']['id'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['table'] = 'field_data_field_account_states';
  $handler->display->display_options['filters']['field_account_states_tid']['field'] = 'field_account_states_tid';
  $handler->display->display_options['filters']['field_account_states_tid']['value'] = array(
    4751 => '4751',
    4761 => '4761',
    4756 => '4756',
  );
  $handler->display->display_options['filters']['field_account_states_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_account_states_tid']['vocabulary'] = 'account_states';
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    4771 => '4771',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  $handler->display->display_options['path'] = 'admin/help-desk/evc-annual';

  /* Display: VIP */
  $handler = $view->new_display('page', 'VIP', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'VIP Users';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_status']['delta_offset'] = '0';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit User';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Resend Email Confirmation';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/registrations/resend/[uid]">Resend email confirmation</a>';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = 'Add VIP & Approve Account';
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = '<a href="/admin/help-desk/evc-confirmation/approved/[uid_1]/vip">Approve Account</a>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    4401 => '4401',
    4406 => '4406',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4791 => '4791',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';
  $handler->display->display_options['path'] = 'admin/help-desk/vip';
  $export['help_desk'] = $view;

  $view = new view();
  $view->name = 'help_desk_evc_post_due';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tw_registration_evc_email';
  $view->human_name = 'Help Desk EVC Post-Due';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Annual Employment Verification Overdue';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    41 => '41',
    6 => '6',
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
  $handler->display->display_options['header']['result']['content'] = 'Total Accounts in Queue: @total';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No accounts found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: EVC Mail: UID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile - EVC';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'indicate_evc' => 'indicate_evc',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: EVC Mail: Fourteen Day Email Timestamp */
  $handler->display->display_options['fields']['fourteenday_date']['id'] = 'fourteenday_date';
  $handler->display->display_options['fields']['fourteenday_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['fields']['fourteenday_date']['field'] = 'fourteenday_date';
  $handler->display->display_options['fields']['fourteenday_date']['label'] = '14 Day Email Reminder Sent';
  $handler->display->display_options['fields']['fourteenday_date']['date_format'] = 'long';
  $handler->display->display_options['fields']['fourteenday_date']['second_date_format'] = 'long';
  /* Field: User: EVC Status */
  $handler->display->display_options['fields']['field_evc_status']['id'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['field'] = 'field_evc_status';
  $handler->display->display_options['fields']['field_evc_status']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_evc_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Account Statuses */
  $handler->display->display_options['fields']['field_user_status']['id'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['fields']['field_user_status']['field'] = 'field_user_status';
  $handler->display->display_options['fields']['field_user_status']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_status']['label'] = 'Account Status';
  $handler->display->display_options['fields']['field_user_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Profile: Employment Verification Contact */
  $handler->display->display_options['fields']['field_employment_verification_co']['id'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['table'] = 'field_data_field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['field'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Email Address */
  $handler->display->display_options['fields']['field_verification_contact_email']['id'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['table'] = 'field_data_field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['field'] = 'field_verification_contact_email';
  $handler->display->display_options['fields']['field_verification_contact_email']['relationship'] = 'profile';
  /* Field: Profile: Employment Verification Contact Phone Number */
  $handler->display->display_options['fields']['field_employment_verification_p']['id'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['table'] = 'field_data_field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['field'] = 'field_employment_verification_p';
  $handler->display->display_options['fields']['field_employment_verification_p']['relationship'] = 'profile';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Resend Annual Employment Verification Non-Response';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '<a href="/admin/help-desk/helper/[uid]/evc_non_responsive">Resend Email</a>';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: User: EVC Status (field_evc_status) */
  $handler->display->display_options['filters']['field_evc_status_tid']['id'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['table'] = 'field_data_field_evc_status';
  $handler->display->display_options['filters']['field_evc_status_tid']['field'] = 'field_evc_status_tid';
  $handler->display->display_options['filters']['field_evc_status_tid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_evc_status_tid']['value'] = array(
    4942 => '4942',
  );
  $handler->display->display_options['filters']['field_evc_status_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_evc_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_evc_status_tid']['vocabulary'] = 'evc_status';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/help-desk/evc-postdue';
  $export['help_desk_evc_post_due'] = $view;

  $view = new view();
  $view->name = 'intl_account_six_month_review';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tw_registration_evc_email';
  $view->human_name = 'Intl Account Six Month Review';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'International Accounts Six Month Review';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    41 => '41',
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total Accounts in Queue: @total';
  /* Relationship: EVC Mail: UID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile - Personal info';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'personal_information' => 'personal_information',
  );
  /* Relationship: Profile - Employment */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile_1']['ui_name'] = 'Profile - Employment';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Profile - Employment';
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'employment_information' => 'employment_information',
  );
  /* Relationship: Profile - EVC */
  $handler->display->display_options['relationships']['profile_2']['id'] = 'profile_2';
  $handler->display->display_options['relationships']['profile_2']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_2']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_2']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile_2']['ui_name'] = 'Profile - EVC';
  $handler->display->display_options['relationships']['profile_2']['label'] = 'Profile - EVC';
  $handler->display->display_options['relationships']['profile_2']['bundle_types'] = array(
    'indicate_evc' => 'indicate_evc',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  /* Field: Profile: Employer Name */
  $handler->display->display_options['fields']['field_employer_name']['id'] = 'field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['table'] = 'field_data_field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['field'] = 'field_employer_name';
  $handler->display->display_options['fields']['field_employer_name']['relationship'] = 'profile_1';
  /* Field: Profile: Job Title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['relationship'] = 'profile_1';
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_country']['delta_offset'] = '0';
  /* Field: Profile: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['relationship'] = 'profile_1';
  /* Field: Profile: Employment Verification Contact */
  $handler->display->display_options['fields']['field_employment_verification_co']['id'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['table'] = 'field_data_field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['field'] = 'field_employment_verification_co';
  $handler->display->display_options['fields']['field_employment_verification_co']['relationship'] = 'profile_2';
  /* Field: Profile: Employment Verification Contact Title */
  $handler->display->display_options['fields']['field_verification_contact_title']['id'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['table'] = 'field_data_field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['field'] = 'field_verification_contact_title';
  $handler->display->display_options['fields']['field_verification_contact_title']['relationship'] = 'profile_2';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'uid';
  $handler->display->display_options['fields']['created']['label'] = 'Registration Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'search_api_facetapi_DAY';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: EVC Mail: Verification Date */
  $handler->display->display_options['fields']['verification_date']['id'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['table'] = 'tw_registration_evc_email';
  $handler->display->display_options['fields']['verification_date']['field'] = 'verification_date';
  $handler->display->display_options['fields']['verification_date']['label'] = 'Time since last EVC Status';
  $handler->display->display_options['fields']['verification_date']['empty'] = 'User is in process of (re) validating their EVC.';
  $handler->display->display_options['fields']['verification_date']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['verification_date']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Filter criterion: User: Account Statuses (field_user_status) */
  $handler->display->display_options['filters']['field_user_status_tid']['id'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['table'] = 'field_data_field_user_status';
  $handler->display->display_options['filters']['field_user_status_tid']['field'] = 'field_user_status_tid';
  $handler->display->display_options['filters']['field_user_status_tid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_user_status_tid']['value'] = array(
    4406 => '4406',
    4401 => '4401',
    4771 => '4771',
  );
  $handler->display->display_options['filters']['field_user_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_status_tid']['vocabulary'] = 'user_status';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    14 => '14',
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  /* Filter criterion: Field: Country (field_country) */
  $handler->display->display_options['filters']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['filters']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['relationship'] = 'profile_1';
  $handler->display->display_options['filters']['field_country_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_value']['expose']['operator_id'] = 'field_country_value_op';
  $handler->display->display_options['filters']['field_country_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_value']['expose']['operator'] = 'field_country_value_op';
  $handler->display->display_options['filters']['field_country_value']['expose']['identifier'] = 'field_country_value';
  $handler->display->display_options['filters']['field_country_value']['expose']['remember_roles'] = array(
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
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/help-desk/intl-six-month';
  $export['intl_account_six_month_review'] = $view;

  return $export;
}
