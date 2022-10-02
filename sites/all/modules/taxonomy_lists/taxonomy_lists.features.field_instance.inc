<?php
/**
 * @file
 * taxonomy_lists.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function taxonomy_lists_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-access_classification-field_marking'.
  $field_instances['taxonomy_term-access_classification-field_marking'] = array(
    'bundle' => 'access_classification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Type the classification marking ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_marking',
    'label' => 'Marking',
    'qtip' => array(
      'custom_text' => '',
      'instance' => 'default',
      'qtip_label' => 0,
      'text' => 'none',
      'title' => '',
    ),
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-ied_profile_sub_type-field_ied_profile'.
  $field_instances['taxonomy_term-ied_profile_sub_type-field_ied_profile'] = array(
    'bundle' => 'ied_profile_sub_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_ied_profile',
    'label' => 'IED Profile Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-ied_profile_sub_type-field_ied_profile_sub_type'.
  $field_instances['taxonomy_term-ied_profile_sub_type-field_ied_profile_sub_type'] = array(
    'bundle' => 'ied_profile_sub_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_ied_profile_sub_type',
    'label' => 'IED Profile Sub-type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-ied_profile_sub_type-field_incidents_location'.
  $field_instances['taxonomy_term-ied_profile_sub_type-field_incidents_location'] = array(
    'bundle' => 'ied_profile_sub_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_incidents_location',
    'label' => 'Incidents Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('IED Profile Sub-type');
  t('IED Profile Type');
  t('Incidents Location');
  t('Marking');
  t('Type the classification marking ');

  return $field_instances;
}
