<?php
/**
 * @file
 * user_status_field.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function user_status_field_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_user_status'.
  $field_instances['user-user-field_user_status'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_user_status',
    'label' => 'User Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 16,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('User Status');

  return $field_instances;
}
