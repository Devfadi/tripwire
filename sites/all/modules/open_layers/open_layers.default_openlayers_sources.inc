<?php
/**
 * @file
 * open_layers.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function open_layers_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_bmap_feed_feed_1';
  $ol_source->name = 'Views GeoJSON source: bmap_feed_feed_1';
  $ol_source->description = 'This source is automatically generated. See View bmap_feed at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'bmap_source_feed',
  );
  $export['views_geojson_bmap_feed_feed_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_mj_feed_feed_1';
  $ol_source->name = 'Views GeoJSON source: mj_feed_feed_1';
  $ol_source->description = 'This source is automatically generated. See View mj_feed at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'mj-source-feed',
  );
  $export['views_geojson_mj_feed_feed_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_obp_event_feed_1';
  $ol_source->name = 'Views GeoJSON source: obp_event_feed_1';
  $ol_source->description = 'This source is automatically generated. See View obp_event at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'obp_source_feed',
  );
  $export['views_geojson_obp_event_feed_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_openlayers_examples_geojson_feed_1';
  $ol_source->name = 'Views GeoJSON source: openlayers_examples_geojson_feed_1';
  $ol_source->description = 'This source is automatically generated. See View openlayers_examples_geojson at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'openlayers-examples/feed.geojson',
  );
  $export['views_geojson_openlayers_examples_geojson_feed_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_openlayers_examples_geojson_feed_2';
  $ol_source->name = 'Views GeoJSON source: openlayers_examples_geojson_feed_2';
  $ol_source->description = 'This source is automatically generated. See View openlayers_examples_geojson at display feed_2';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'openlayers-examples/popup.geojson',
  );
  $export['views_geojson_openlayers_examples_geojson_feed_2'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_training_event_feed_1';
  $ol_source->name = 'Views GeoJSON source: training_event_feed_1';
  $ol_source->description = 'This source is automatically generated. See View training_event at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'training_source_feed',
  );
  $export['views_geojson_training_event_feed_1'] = $ol_source;

  return $export;
}
