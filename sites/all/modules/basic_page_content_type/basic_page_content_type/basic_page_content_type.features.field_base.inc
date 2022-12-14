<?php
/**
 * @file
 * basic_page_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function basic_page_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_enable_lock_icon'.
  $field_bases['field_enable_lock_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enable_lock_icon',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'off',
        1 => 'Lock',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
