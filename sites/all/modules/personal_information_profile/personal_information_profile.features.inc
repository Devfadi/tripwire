<?php

/**
 * @file
 * personal_information_profile.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function personal_information_profile_default_profile2_type() {
  $items = array();
  $items['personal_information'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "personal_information",
    "label" : "Personal Information",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
