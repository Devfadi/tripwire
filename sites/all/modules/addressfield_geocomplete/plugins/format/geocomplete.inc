<?php
/**
 * @file
 * Addressfield Format plugin using Geocomplete.
 *
 * @todo Test more against non-US locations.
 * @todo Add ability to remove a value / clear addressfield component fields.
 */

$plugin = array(
  'title' => t('Geocomplete'),
  'format callback' => 'addressfield_format_geocomplete_generate',
  'type' => 'geocomplete',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_geocomplete_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    // Add a class to the wrapping element so we can more easily handle multiple
    // addresses on the same page and multi-value address fields.
    $format['#prefix'] = '<div id="' . $format['#wrapper_id'] . '" class="addressfield-geocomplete-wrapper">';

    // Add data-geo attributes to the address fields.
    // Note: Due to country field ajax, unable to use Geocomplete capabilities
    // to auto-populate the fields. However we'll still utilize the data-geo
    // attribute.
    $field_geo_map = array(
      'street_block' => array(
        'thoroughfare' => 'street_number route',
        'premise' => 'subpremise premise',
      ),
      'locality_block' => array(
        'locality' => 'postal_town locality',
        'dependent_locality' => 'sublocality_level_1 sublocality',
        'administrative_area' => 'administrative_area_level_1',
        'postal_code' => 'postal_code_prefix postal_code',
      ),
    );

    foreach ($field_geo_map as $block_key => $elements) {
      foreach ($elements as $element_key => $data_geo) {
        if (isset($format[$block_key]) && isset($format[$block_key][$element_key])) {
          // Hide the block element as well.
          $format[$block_key]['#attributes']['class'][] = 'addressfield-geocomplete-element-invisible-toggle';
          $format[$block_key][$element_key]['#attributes']['data-geo'] = $data_geo;
          $format[$block_key][$element_key]['#attributes']['class'][] = 'addressfield-geocomplete-component';
        }
      }
    }

    if (isset($format['country'])) {
      $format['country']['#attributes']['class'][] = 'element-invisible';
      $format['country']['#attributes']['class'][] = 'addressfield-geocomplete-element-invisible-toggle';
      $format['country']['#title_display'] = 'invisible';
      $format['country']['#attributes']['data-geo'] = 'country';
    }

    // Geocomplete block.
    $format['geocomplete_block'] = array(
      '#type' => 'addressfield_container',
      '#attributes' => array('class' => array('addressfield-geocomplete-block')),
      '#weight' => $format['country']['#weight'] - 1,
    );
    $format['geocomplete_block']['geocomplete'] = array(
      '#type' => 'textfield',
      '#title' => t('Address'),
      '#title_display' => 'invisible',
      '#attributes' => array(
        'class' => array('addressfield-geocomplete', 'addressfield-geocomplete-element-invisible-toggle'),
      ),
    );
    // When first loading the form the geocomplete textfield is blank so the
    // user may not know what the current address value is. Render the address
    // to display for the user.
    $address_render_array = addressfield_generate($address, array('address' => 'address'), array('mode' => 'render'));
    $format['geocomplete_block']['rendered_address'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'addressfield-geocomplete-rendered-address',
          'addressfield-geocomplete-element-invisible-toggle',
        ),
      ),
      'label' => array(
        '#prefix' => '<label>',
        '#suffix' => '</label>',
        '#markup' => t('Current value:'),
      ),
      'address' => array(
        '#markup' => drupal_render($address_render_array),
      ),
    );

    // Render the current address for this field value.
    // A hidden field is used to stash the geocomplete returned address
    // components. After the country AJAX is complete then we can populate the
    // address fields.
    $format['geocomplete_block']['geocomplete_address_results'] = array(
      '#type' => 'hidden',
      '#default_value' => isset($address['geocomplete_address_results']) ? $address['geocomplete_address_results'] : '',
      '#attributes' => array(
        'class' => array('addressfield-geocomplete-results'),
      ),
    );

    // Attach the geocomplete library.
    $format['#attached']['libraries_load'] = array(
      array('geocomplete', 'minified'),
    );
  }
}
