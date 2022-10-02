<?php
/**
 * @file
 * obp_event_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function obp_event_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'obp_event_importer';
  $feeds_importer->config = array(
    'name' => 'OBP Event Importer',
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
            'source' => 'Class Title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'PROMO Code (if applicable)',
            'target' => 'field_promo_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Start Date',
            'target' => 'field_obp_event_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'End Date',
            'target' => 'field_obp_event_date:end',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Instructor #1',
            'target' => 'field_instructor_1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Instructor #2',
            'target' => 'field_instructor_2',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'PSA Region',
            'target' => 'field_federal_region',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Sector',
            'target' => 'field_sector',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Projected Participants',
            'target' => 'field_projected_participants',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Delivery Method',
            'target' => 'field_delivery_method',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Training Provider',
            'target' => 'field_training_provider',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Training Type',
            'target' => 'field_training_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'PSA Contact Information',
            'target' => 'field_psa_contact_information',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Local POC Contact Information',
            'target' => 'field_local_poc_contact_info',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'RMS Approval Authority',
            'target' => 'field_rms_approval_authority',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'RTC',
            'target' => 'field_rtc',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Start Time (Eastern Standard Time)',
            'target' => 'field_start_time',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Shipping Address',
            'target' => 'field_obp_shipping_address',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Venue',
            'target' => 'field_address:name_line',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Venue Address',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'City',
            'target' => 'field_address:locality',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'State',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'Venue Zip Code',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Country',
            'target' => 'field_address:country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'POC Email',
            'target' => 'field_poc_email',
            'unique' => FALSE,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'POC Phone Number',
            'target' => 'field_poc_phone_number',
            'unique' => FALSE,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'Low Registrants',
            'target' => 'field_low_registrants',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Private Sector Participants',
            'target' => 'field_private_sector_participant',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'Date Admin Package Sent',
            'target' => 'field_date_support_package_sent:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'Date Admin Package Received',
            'target' => 'field_date_admin_package_receive:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          30 => array(
            'source' => 'Date Support Package Sent',
            'target' => 'field_date_support_package_sent:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          31 => array(
            'source' => 'Date Support Package Received',
            'target' => 'field_date_support_package_recei:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          32 => array(
            'source' => 'Comments',
            'target' => 'field_obp_event_comments',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'map_data',
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
  $export['obp_event_importer'] = $feeds_importer;

  return $export;
}
