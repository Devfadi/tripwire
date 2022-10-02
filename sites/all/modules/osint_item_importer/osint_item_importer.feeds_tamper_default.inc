<?php
/**
 * @file
 * osint_item_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function osint_item_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-automated_phone-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Automated Phone';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'TRUE',
    'false_value' => 'FALSE',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-automated_phone-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-bomb_squad_response-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Bomb Squad Response';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'Yes',
    'false_value' => 'No',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-bomb_squad_response-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-email-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Email';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'true',
    'false_value' => 'false',
    'match_case' => 0,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-email-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-international_nexus-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'International Nexus';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'Yes',
    'false_value' => 'No',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-international_nexus-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-phone-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Phone';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'TRUE',
    'false_value' => 'FALSE',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-phone-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-religious_nexus-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Religious Nexus';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'Yes',
    'false_value' => 'No',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-religious_nexus-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-social_media-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Social Media';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'TRUE',
    'false_value' => 'FALSE',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-social_media-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-unspecified-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Unspecified';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'TRUE',
    'false_value' => 'FALSE',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-unspecified-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-user_roles-explode';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'User Roles';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['osint_item_importer-user_roles-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-verbal-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Verbal';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'TRUE',
    'false_value' => 'FALSE',
    'match_case' => 1,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-verbal-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'osint_item_importer-written-convert_boolean';
  $feeds_tamper->importer = 'osint_item_importer';
  $feeds_tamper->source = 'Written';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'true',
    'false_value' => 'false',
    'match_case' => 0,
    'no_match' => 'null',
    'other_text' => '',
    'no_match_value' => NULL,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['osint_item_importer-written-convert_boolean'] = $feeds_tamper;

  return $export;
}
