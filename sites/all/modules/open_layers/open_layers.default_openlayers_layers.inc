<?php
/**
 * @file
 * open_layers.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function open_layers_default_openlayers_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'bmap_event_layer';
  $ol_layer->name = 'BMAP Event layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_bmap_feed_feed_1',
    'visible' => 1,
    'style' => 'openlayers_style_invisible',
  );
  $export['bmap_event_layer'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'bmm_found';
  $ol_layer->name = 'BMM Found';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_osint_feeds_feed_bmm_found',
    'visible' => 1,
    'style' => 'openlayers_style_invisible',
  );
  $export['bmm_found'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'bmm_stolen';
  $ol_layer->name = 'BMM Stolen';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_osint_feeds_feed_bmm_stolen',
    'visible' => 1,
    'style' => 'openlayers_style_invisible',
  );
  $export['bmm_stolen'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'bomb_threat';
  $ol_layer->name = 'Bomb Threat';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_osint_feeds_feed_bomb_threat',
    'visible' => 1,
    'style' => 'openlayers_style_invisible',
  );
  $export['bomb_threat'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'mj_event_layer';
  $ol_layer->name = 'MJ Event layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_mj_feed_feed_1',
    'visible' => 1,
    'style' => 'openlayers_style_invisible',
  );
  $export['mj_event_layer'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'obp_event_layer';
  $ol_layer->name = 'OBP Event layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_obp_event_feed_1',
    'visible' => 1,
    'style' => 'openlayers_style_invisible',
  );
  $export['obp_event_layer'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'obp_event_map_geojson';
  $ol_layer->name = 'OBP Event Map GeoJSON';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_views_source_obp_event_map_page_1',
    'visible' => 1,
    'style' => 'openlayers_examples_style_red',
  );
  $export['obp_event_map_geojson'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'training_event_layer';
  $ol_layer->name = 'Training Event layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_training_event_feed_1',
    'visible' => 1,
    'style' => 'openlayers_style_invisible',
  );
  $export['training_event_layer'] = $ol_layer;

  return $export;
}
