<?php
/**
 * @file
 * what_s_new_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function what_s_new_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_pin_to_top'.
  $field_bases['field_pin_to_top'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pin_to_top',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
