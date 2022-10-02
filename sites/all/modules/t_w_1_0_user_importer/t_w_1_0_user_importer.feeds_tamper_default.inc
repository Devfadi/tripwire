<?php
/**
 * @file
 * t_w_1_0_user_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function t_w_1_0_user_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-certification_day-default_value';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Certification Day';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '01/01/1970',
    'only_if_empty' => 1,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Set value or default value';
  $export['tw_1_0_user_importer-certification_day-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-certification_day-find_replace';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Certification Day';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '//',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['tw_1_0_user_importer-certification_day-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-certification_day-rewrite';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Certification Day';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[certification month]/[certification day]/[certification year]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['tw_1_0_user_importer-certification_day-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-certification_day-strtotime';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Certification Day';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['tw_1_0_user_importer-certification_day-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-certification_month-default_value';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Certification Month';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '',
    'only_if_empty' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['tw_1_0_user_importer-certification_month-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-certification_year-default_value';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Certification Year';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '',
    'only_if_empty' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['tw_1_0_user_importer-certification_year-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-security_answer_1-debug';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Security Answer 1';
  $feeds_tamper->plugin_id = 'debug';
  $feeds_tamper->settings = array(
    'watchdog' => 0,
    'errorlog' => 0,
    'message' => 0,
    'dpm' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Debug';
  $export['tw_1_0_user_importer-security_answer_1-debug'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-security_answer_2-debug';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Security Answer 2';
  $feeds_tamper->plugin_id = 'debug';
  $feeds_tamper->settings = array(
    'watchdog' => 0,
    'errorlog' => 0,
    'message' => 0,
    'dpm' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Debug';
  $export['tw_1_0_user_importer-security_answer_2-debug'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-security_question_1-debug';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Security Question 1';
  $feeds_tamper->plugin_id = 'debug';
  $feeds_tamper->settings = array(
    'watchdog' => 0,
    'errorlog' => 0,
    'message' => 0,
    'dpm' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Debug';
  $export['tw_1_0_user_importer-security_question_1-debug'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-security_question_2-debug';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Security Question 2';
  $feeds_tamper->plugin_id = 'debug';
  $feeds_tamper->settings = array(
    'watchdog' => 0,
    'errorlog' => 0,
    'message' => 0,
    'dpm' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Debug';
  $export['tw_1_0_user_importer-security_question_2-debug'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-temporary_target_1-default_value';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Temporary target 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'Pending||Imported from TW 1.0',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['tw_1_0_user_importer-temporary_target_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-temporary_target_1-explode';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Temporary target 1';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '||',
    'limit' => '',
    'real_separator' => '||',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['tw_1_0_user_importer-temporary_target_1-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-terms_service-convert_booleanx';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Terms Service';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'TRUE',
    'false_value' => 'FALSE',
    'match_case' => 1,
    'no_match' => 'true',
    'other_text' => '',
    'no_match_value' => TRUE,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Convert to boolean';
  $export['tw_1_0_user_importer-terms_service-convert_booleanx'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-terms_service-debug';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Terms Service';
  $feeds_tamper->plugin_id = 'debug';
  $feeds_tamper->settings = array(
    'watchdog' => 1,
    'errorlog' => 1,
    'message' => 0,
    'dpm' => 1,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Debug';
  $export['tw_1_0_user_importer-terms_service-debug'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-terms_service-find_replace';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Terms Service';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'TRUE',
    'replace' => 'I have read and agree to the <a href="/drupal/?q=terms_of_service" target="_blank">Terms of Service and Privacy Notice</a>.',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Find replace';
  $export['tw_1_0_user_importer-terms_service-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tw_1_0_user_importer-zip_code-truncate_text';
  $feeds_tamper->importer = 'tw_1_0_user_importer';
  $feeds_tamper->source = 'Zip Code';
  $feeds_tamper->plugin_id = 'truncate_text';
  $feeds_tamper->settings = array(
    'num_char' => '5',
    'ellipses' => 0,
    'wordsafe' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Truncate';
  $export['tw_1_0_user_importer-zip_code-truncate_text'] = $feeds_tamper;

  return $export;
}
