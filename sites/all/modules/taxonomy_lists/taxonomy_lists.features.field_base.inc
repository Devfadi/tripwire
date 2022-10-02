<?php
/**
 * @file
 * taxonomy_lists.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function taxonomy_lists_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_marking'.
  $field_bases['field_marking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_marking',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
