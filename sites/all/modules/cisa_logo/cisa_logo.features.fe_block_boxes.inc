<?php

/**
 * @file
 * cisa_logo.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function cisa_logo_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'CISA Logo';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'cisa';
  $fe_block_boxes->body = '<img alt="" src="/sites/all/themes/rubix_responsive_theme/images/cisa-logo.png" class="cisalogo">';

  $export['cisa'] = $fe_block_boxes;

  return $export;
}
