<?php
/**
 * @file
 * osint_item_importer.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function osint_item_importer_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'OSINT Team ID';
  $rule->name = 'osint_team_id';
  $rule->field_name = 'field_osint_team_id';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'osint_item';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
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
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'OSINT Team ID must be unique value.';
  $export['osint_team_id'] = $rule;

  return $export;
}
