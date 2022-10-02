<?php
/**
 * @file
 * my_tripwire_subscriptions.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function my_tripwire_subscriptions_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_caution_text'.
  $field_bases['field_caution_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_caution_text',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'markup',
    'settings' => array(
      'markup' => array(
        'format' => 'tripwire',
        'value' => '<p>Caution: Modifying My TRIP<em>wire</em> Subscriptions will cause changes site-wide.</p>',
      ),
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'markup',
  );

  return $field_bases;
}
