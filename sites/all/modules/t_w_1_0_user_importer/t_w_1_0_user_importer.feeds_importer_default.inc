<?php
/**
 * @file
 * t_w_1_0_user_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function t_w_1_0_user_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'tw_1_0_user_importer';
  $feeds_importer->config = array(
    'name' => 'TW 1.0 User Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          7 => 0,
          8 => 0,
          9 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
          14 => 0,
          6 => 0,
          4 => 0,
          3 => 0,
        ),
        'status' => '0',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'UserName',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Citizenship',
            'target' => 'profile2:personal_information:field_citizenship',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'First Name',
            'target' => 'profile2:personal_information:field_first_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Middle Initial',
            'target' => 'profile2:personal_information:field_middle_initial',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Last Name',
            'target' => 'profile2:personal_information:field_last_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Title',
            'target' => 'profile2:personal_information:field_title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Professional Email',
            'target' => 'profile2:employment_information:field_professional_email_address',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Alt Email',
            'target' => 'profile2:employment_information:field_alternate_email_address',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Employer Name',
            'target' => 'profile2:employment_information:field_employer_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Professional Address',
            'target' => 'profile2:employment_information:field_professional_street_addres',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'City',
            'target' => 'profile2:employment_information:field_city',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'State',
            'target' => 'profile2:employment_information:field_state_province_region',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Zip Code',
            'target' => 'profile2:employment_information:field_zipcode',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Country',
            'target' => 'profile2:employment_information:field_country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Job Title',
            'target' => 'profile2:employment_information:field_job_title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Verification Name',
            'target' => 'profile2:indicate_evc:field_employment_verification_co',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Verification Title',
            'target' => 'profile2:indicate_evc:field_verification_contact_title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Verification Email',
            'target' => 'profile2:indicate_evc:field_verification_contact_email',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Found Site',
            'target' => 'profile2:personal_information:field_please_tell_us_how_you_fou',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Terms Service',
            'target' => 'profile2:privacy_information:field_privacy_agreement',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'Certifications',
            'target' => 'profile2:personal_information:field_certification_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Certification Month',
            'target' => 'profile2:personal_information:field_certification_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'Certification Year',
            'target' => 'profile2:personal_information:field_certification_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Certification Day',
            'target' => 'profile2:personal_information:field_certification_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'Email address',
            'target' => 'mail',
            'unique' => FALSE,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'Security Answer 1',
            'target' => 'password_reset:answer1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'Security Answer 2',
            'target' => 'password_reset:answer2',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Security Question 1',
            'target' => 'password_reset:question1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'Security Question 2',
            'target' => 'password_reset:question2',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'Temporary target 1',
            'target' => 'field_user_status',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'user',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['tw_1_0_user_importer'] = $feeds_importer;

  return $export;
}
