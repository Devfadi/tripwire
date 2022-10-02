<?php
/**
 * @file
 * open_layers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function open_layers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "openlayers" && $api == "default_openlayers_layers") {
    return array("version" => "1");
  }
  if ($module == "openlayers" && $api == "default_openlayers_maps") {
    return array("version" => "1");
  }
  if ($module == "openlayers" && $api == "default_openlayers_sources") {
    return array("version" => "1");
  }
}
