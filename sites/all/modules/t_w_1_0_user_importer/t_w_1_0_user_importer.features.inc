<?php
/**
 * @file
 * t_w_1_0_user_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function t_w_1_0_user_importer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}
