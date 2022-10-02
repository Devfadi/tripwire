<?php
/**
 * @file
 * environment_variables.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function environment_variables_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "environment_indicator" && $api == "default_environment_indicator_environments") {
    return array("version" => "1");
  }
}
