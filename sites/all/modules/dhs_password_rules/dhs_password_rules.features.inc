<?php
/**
 * @file
 * dhs_password_rules.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dhs_password_rules_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "password_policy" && $api == "default_password_policy") {
    return array("version" => "1");
  }
}
