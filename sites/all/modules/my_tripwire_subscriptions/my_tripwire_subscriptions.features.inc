<?php
/**
 * @file
 * my_tripwire_subscriptions.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function my_tripwire_subscriptions_default_profile2_type() {
  $items = array();
  $items['my_tripwire_subscriptions'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "my_tripwire_subscriptions",
    "label" : "My TRIPwire Subscriptions",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
