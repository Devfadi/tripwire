/**
 * @file
 * Javascript file for Addressfield Geocomplete.
 */

(function ($, Drupal, window, document) {

  'use strict';

  $.fn.extend({
    /**
     * Update the addressfield component fields with the geocomplete results.
     *
     * Use the geocomplete results and find the addressfield component fields to
     * populate for the form submission. <select> elements will have their
     * values set while textfield elements will have values appended. The latter
     * allows for building the street address 1 field from the various Google
     * address components.
     */
    addressfieldGeocompleteUpdate: function() {
      var addressfieldValue = $(this);
      var addressfieldGeocompleteResults = addressfieldValue.find('.addressfield-geocomplete-results');

      if (addressfieldGeocompleteResults.val()) {
        var geocompleteResults = JSON.parse(addressfieldGeocompleteResults.val());
        var addressComponents = geocompleteResults.address_components;
        var addressComponentsByType = [];

        $.each(addressComponents, function (index, component) {
          addressComponentsByType[component.types[0]] = component.short_name;
        });

        addressfieldValue.find('.addressfield-geocomplete-component').each(function (index) {
          var componentField = $(this);
          var dataGeo = componentField.data('geo').split(' ');

          componentField.val('');

          $.each(dataGeo, function (index, componentType) {
            if (addressComponentsByType.hasOwnProperty(componentType)) {
              // If we have a select field we simply set the value, however if
              // we're dealing with a text field we may be appending values
              // together. If the current value has an existing value from
              // appending values together then we need to add a space.
              if (!componentField.val() || componentField.prop('nodeName') == 'SELECT') {
                componentField.val(addressComponentsByType[componentType]);
              }
              else {
                componentField.val(componentField.val() + ' ' + addressComponentsByType[componentType]);
              }
            }
          });
        });

        // The geocomplete textfield will display the address the user selected
        // so there is no need to show the "rendred" address.
        addressfieldValue.find('.addressfield-geocomplete-rendered-address').hide();

        // Remove the geocomplete results from the hidden field as it is only a
        // temporary storage.
        addressfieldGeocompleteResults.val('');
      }
    }
  });

  /**
   * Initialize / handle geocomplete.
   */
  Drupal.behaviors.addressfieldGeocomplete = {

    attach: function( context, settings ) {

      // Each addressfield value using geocomplete will contain this class. This
      // could be multiple single value addressfields or a single addressfield
      // with multiple values.
      var addressfieldWrappers = $('.addressfield-geocomplete-wrapper');

      addressfieldWrappers.once('addressfield-geocomplete-wrapper').each(function (index) {
        // Each field value.
        var addressfieldValue = $(this);
        // The geocomplete textfield.
        var geocompleteField = addressfieldValue.find('.addressfield-geocomplete');
        // The hidden field containing the geocomplete results.
        var addressfieldGeocompleteResults = addressfieldValue.find('.addressfield-geocomplete-results');
        // The country field.
        // Track whether this value has changed to determine if we need to
        // trigger the country ajax.
        var countryValue = addressfieldValue.find('select.country');
        var countryValueChanged = false;
        // Toggler to show/hide address fields.
        var toggler = addressfieldValue.find('.addressfield-geocomplete-toggler');

        // Attempt to determine if the street address fields exist. If so then
        // we can configure geocomplete for addresses otherwise configure for
        // cities.
        var geocompleteTypes = addressfieldValue.find('.street-block').length ? ['address'] : ['(cities)'];

        // Evaluate the hidden field to see if it contains address components
        // that may have been submitted when the country AJAX fired.
        if (addressfieldGeocompleteResults.length) {
          addressfieldValue.once('addressfield-geocomplete-update').addressfieldGeocompleteUpdate();
        }

        // Initialize the geocomplete textfield to provide autocompletion.
        geocompleteField.geocomplete({
          types: geocompleteTypes
        }).bind("geocode:result", function (event, results) {
          // Add the selected results to the hidden field.
          addressfieldGeocompleteResults.val(JSON.stringify(results));

          // If the country field exists and was changed then trigger the
          // country field change ajax. This is done by setting a bolean to
          // evaluate later. This Drupal Behavior will handle updating the
          // address components.
          if (countryValue.length) {
            $.each(results.address_components, function (delta, component) {
              if (component.types[0] == 'country') {
                countryValueChanged = countryValue.val() != component.short_name;
              }
            });
          }

          if (countryValueChanged) {
            countryValue.val(component.short_name).trigger('change');
          }
          // If the country field doesn't exist then we can populate the
          // address component fields.
          else {
            addressfieldValue.addressfieldGeocompleteUpdate();
          }
        });

        // Add on click handler to show/hide addressfield component fields.
        $(toggler, context).once('addressfield-geocomplete-toggler-initialize').on('click', function (e) {
          e.preventDefault();

          addressfieldValue
            .find('.addressfield-geocomplete-element-invisible-toggle')
            .each(function() {
              if ($(this).hasClass('element-invisible')) {
                $(this).removeClass('element-invisible');
              }
              else {
                $(this).addClass('element-invisible');
              }
          });
        });
      });

    }
  };

})(jQuery, Drupal, this, this.document);
