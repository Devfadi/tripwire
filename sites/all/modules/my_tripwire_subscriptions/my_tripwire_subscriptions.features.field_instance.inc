<?php
/**
 * @file
 * my_tripwire_subscriptions.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function my_tripwire_subscriptions_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'profile2-my_tripwire_subscriptions-field_author_publisher'.
  $field_instances['profile2-my_tripwire_subscriptions-field_author_publisher'] = array(
    'bundle' => 'my_tripwire_subscriptions',
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
    'entity_type' => 'profile2',
    'field_name' => 'field_author_publisher',
    'label' => 'Author/Publisher',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(),
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'profile2-my_tripwire_subscriptions-field_caution_text'.
  $field_instances['profile2-my_tripwire_subscriptions-field_caution_text'] = array(
    'bundle' => 'my_tripwire_subscriptions',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_caution_text',
    'label' => 'Caution text',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'profile2-my_tripwire_subscriptions-field_federal_region'.
  $field_instances['profile2-my_tripwire_subscriptions-field_federal_region'] = array(
    'bundle' => 'my_tripwire_subscriptions',
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
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_federal_region',
    'label' => 'Federal Region',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(),
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
  // 'profile2-my_tripwire_subscriptions-field_subject'.
  $field_instances['profile2-my_tripwire_subscriptions-field_subject'] = array(
    'bundle' => 'my_tripwire_subscriptions',
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
    'entity_type' => 'profile2',
    'field_name' => 'field_subject',
    'label' => 'Site-wide Tags by Subject',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(),
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Author/Publisher');
  t('Caution text');
  t('Federal Region');
  t('Site-wide Tags by Subject');

  return $field_instances;
}
