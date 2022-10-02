<?php

/**
 * @file
 * Convert string to timestamp.
 */

$plugin = array(
  'form' => 'feeds_tamper_strtotimeformat_form',
  'callback' => 'feeds_tamper_strtotimeformat_callback',
  'name' => 'String to Unix timestamp with custom format',
  'multi' => 'loop',
  'category' => 'Date/time',
);

function feeds_tamper_strtotimeformat_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
    '#markup' => t('This will take a string and convert it into a Unix Timestamp using custom date format.'),
  );

  $form['format'] = array(
    '#type' => 'textfield',
    '#title' => t('Format'),
    '#required' => TRUE,
    '#default_value' => $settings['format'],
    '#description' => t('See the <a href="http://php.net/manual/en/datetime.createfromformat.php">DateTime::createFromFormat</a> documentation for more details.'),
  );

  return $form;
}

function feeds_tamper_strtotimeformat_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $datetime = DateTime::createFromFormat('!' . $settings['format'], $field);
  $field = $datetime ? $datetime->getTimestamp() : "";
}
