<?php

/**
 * @file
 * program_landing_page_content_type.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function program_landing_page_content_type_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'program_landing_page_documents';
  $ds_field->label = 'Program Landing Page Documents';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|6e806e8b2d1c677aa348adc6a1072756',
    'block_render' => '3',
  );
  $export['program_landing_page_documents'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function program_landing_page_content_type_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|program_landing_page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'program_landing_page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_branding_image',
      ),
      'left' => array(
        1 => 'program_landing_page_documents',
      ),
      'right' => array(
        2 => 'body',
        3 => 'field_questions_and_answers',
      ),
    ),
    'fields' => array(
      'field_branding_image' => 'header',
      'program_landing_page_documents' => 'left',
      'body' => 'right',
      'field_questions_and_answers' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|program_landing_page|default'] = $ds_layout;

  return $export;
}
