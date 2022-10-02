<?php

/**
 * @file
 * training_and_education_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function training_and_education_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_tags|node|training_and_education|form';
  $field_group->group_name = 'group_metadata_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_and_education';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '43',
    'children' => array(
      0 => 'field_training_courses',
      1 => 'field_training_education',
      2 => 'field_subject',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-metadata-tags field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_metadata_tags|node|training_and_education|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Metadata');

  return $field_groups;
}
