<?php
/**
 * @file
 * Admin page callbacks for Addressfield Geocomplete module.
 */

/**
 * Page callback (form): Addressfield Geocomplete Settings.
 */
function addressfield_geocomplete_settings_form($form, &$form_state) {
  $form['addressfield_geocomplete_google_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google API Key'),
    '#description' => t('The Google Places API requires an !key_link.', array(
      '!key_link' => l(t('API Key'), 'https://developers.google.com/maps/documentation/javascript/get-api-key', array('external' => TRUE)),
    )),
    '#default_value' => variable_get('addressfield_geocomplete_google_api_key', ''),
    '#size' => 50,
    '#maxlength' => 255,
  );

  return system_settings_form($form);
}
