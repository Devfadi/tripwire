<?php
/**
 * @file
 * open_layers.default_openlayers_maps.inc
 */

/**
 * Implements hook_default_openlayers_maps().
 */
function open_layers_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'obp_event_map';
  $ol_map->name = 'OBP Event Map';
  $ol_map->description = 'Map used for OBP Program Events';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '500px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideBlockLayerSwitcher' => 0,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lon' => -95.844726562499986,
        'lat' => 34.699711656912001,
      ),
      'rotation' => 0,
      'zoom' => 5,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'layers' => array(
      0 => 'bmap_event_layer',
      1 => 'mj_event_layer',
      2 => 'obp_event_layer',
      3 => 'training_event_layer',
      4 => 'openlayers_examples_layer_googlemaps',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
    ),
    'renderer' => 'canvas',
    'components' => array(
      0 => 'openlayers_examples_component_simple_popup',
    ),
  );
  $export['obp_event_map'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'osint_map';
  $ol_map->name = 'OSINT Map';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '600px',
    'provideBlockLayerSwitcher' => 0,
    'view' => array(
      'center' => array(
        'lon' => -96.85546875,
        'lat' => 38.651198332299998,
      ),
      'rotation' => 0,
      'zoom' => 5,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_examples_layer_googlemaps',
      1 => 'bmm_stolen',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
  );
  $export['osint_map'] = $ol_map;

  return $export;
}
