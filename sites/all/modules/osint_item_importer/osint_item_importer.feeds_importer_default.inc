<?php
/**
 * @file
 * osint_item_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function osint_item_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'osint_item_importer';
  $feeds_importer->config = array(
    'name' => 'OSINT Item Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '72',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Event Date',
            'target' => 'field_event_date:start',
            'timezone' => 'America/New_York',
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Source',
            'target' => 'field_osint_source',
            'format' => 'tripwire',
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Other Notes',
            'target' => 'field_osint_other_notes',
            'format' => 'tripwire',
            'language' => 'und',
          ),
          3 => array(
            'source' => 'City',
            'target' => 'field_address:locality',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'State',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Arrested',
            'target' => 'field_osint_arrested',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Dead',
            'target' => 'field_osint_dead',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Injured',
            'target' => 'field_osint_injured',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Unspecified',
            'target' => 'field_osint_unspecified',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Social Media',
            'target' => 'field_osint_social_media',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Automated Phone',
            'target' => 'field_osint_automated_phone',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Verbal',
            'target' => 'field_osint_verbal',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Phone',
            'target' => 'field_osint_phone',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Email',
            'target' => 'field_osint_email',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Written',
            'target' => 'field_osint_written',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Incident Type',
            'target' => 'field_profiles_classification',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Main Charge',
            'target' => 'field_main_charge',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Device Type',
            'target' => 'field_device_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Actor',
            'target' => 'field_osint_actor',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'School Grade',
            'target' => 'field_school_grade',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'School Type',
            'target' => 'field_osint_school_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Latitude',
            'target' => 'field_osint_lat_lon:lat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'Longitude',
            'target' => 'field_osint_lat_lon:lon',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Lat/Lon Notes',
            'target' => 'field_osint_lat_lon_notes',
            'format' => 'tripwire',
            'language' => 'und',
          ),
          24 => array(
            'source' => 'Religious Nexus',
            'target' => 'field_osint_religious_nexus',
            'unique' => FALSE,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'International Nexus',
            'target' => 'field_osint_international_nexus',
            'unique' => FALSE,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'Bomb Squad Response',
            'target' => 'field_osint_bomb_squad_response',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Parent Infrastructure (for Reports)',
            'target' => 'field_target',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'Federal Region',
            'target' => 'field_federal_region',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'Zip',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          30 => array(
            'source' => 'Country',
            'target' => 'field_address:country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          31 => array(
            'source' => 'User Roles',
            'target' => 'field_secured_areas',
            'unique' => FALSE,
            'language' => 'und',
          ),
          32 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          33 => array(
            'source' => 'Outcome',
            'target' => 'field_osint_outcome',
            'unique' => FALSE,
            'language' => 'und',
          ),
          34 => array(
            'source' => 'Infrastructure/Site',
            'target' => 'field_infrastructure_site',
            'unique' => FALSE,
            'language' => 'und',
          ),
          35 => array(
            'source' => 'School Grade',
            'target' => 'field_school_grade',
            'unique' => FALSE,
            'language' => 'und',
          ),
          36 => array(
            'source' => 'Actor',
            'target' => 'field_osint_actor',
            'unique' => FALSE,
            'language' => 'und',
          ),
          37 => array(
            'source' => 'Religious Nexus',
            'target' => 'field_osint_religious_nexus',
            'unique' => FALSE,
            'language' => 'und',
          ),
          38 => array(
            'source' => 'Narcotics Nexus',
            'target' => 'field_osint_narcotics_nexus',
            'unique' => FALSE,
            'language' => 'und',
          ),
          39 => array(
            'source' => 'International Nexus',
            'target' => 'field_osint_international_nexus',
            'unique' => FALSE,
            'language' => 'und',
          ),
          40 => array(
            'source' => 'Bomb Squad Response',
            'target' => 'field_osint_bomb_squad_response',
            'unique' => FALSE,
            'language' => 'und',
          ),
          41 => array(
            'source' => 'Description',
            'target' => 'body',
            'format' => 'tripwire',
            'language' => 'und',
          ),
          42 => array(
            'source' => 'Address',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
            'language' => 'und',
          ),
          43 => array(
            'source' => 'Federal/Military Involvement',
            'target' => 'field_osint_fed_mil',
            'unique' => FALSE,
            'language' => 'und',
          ),
          44 => array(
            'source' => 'ID',
            'target' => 'field_osint_team_id',
            'unique' => 1,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'osint_item',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['osint_item_importer'] = $feeds_importer;

  return $export;
}
