<?php
/**
 * @file
 * osint_map_image.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function osint_map_image_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OSINT map image - post-auth';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'osint_map_image';
  $fe_block_boxes->body = '<p><a href="ied-incident-map"><img alt="OSINT Map" border="0" src="sites/default/files/osint_map.png" /></a></p>';

  $export['osint_map_image'] = $fe_block_boxes;

  return $export;
}
