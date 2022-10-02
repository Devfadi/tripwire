Introduction
============

Addressfield Geocomplete integrates the [Geocomplete Library](https://ubilabs.github.io/geocomplete/) with the
[Addressfield](https://www.drupal.org/project/addressfield) module to provide autocomplete capabilities. The Geocomplete
Library utilizes [Google Places API](https://developers.google.com/places/) to offer this functionality.

Similar Modules
---------------

* [Addressfield Autocomplete](https://www.drupal.org/project/addressfield_autocomplete)
  The addressfield autocompletem module depends on the GMap module which is not
  necessary to provide simple autocomplete functionality, however it does
  attempt to provide GMap functionality on the addressfield widget form. This
  module also provides a separate field widget type where-as the Addressfield
  Geocomplete module uses the Addressfield 'format' API to include Geocomplete
  on any addressfield.

Installation
============

Requirements
------------

* [Addressfield](https://www.drupal.org/project/addressfield) module
* [Libraries](https://www.drupal.org/project/libraries) module
* [Geocomplete](https://ubilabs.github.io/geocomplete/) library
* [Google API Key](https://developers.google.com/maps/documentation/javascript/get-api-key)

# Install the Libraries and Addressfield modules.
# Add the Geocomplete library to sites/all/libraries folder (sites/all/libraries/geocomplete).
  Note: A .make file is included with this project to download the Geocomplete library.
# Generate your Google API Key.

Configuration
-------------

# Add your Google API Key to the Addressfield Geocomplete configuration form.
  (admin/config/services/addressfield-geocomplete)
# Add a new or edit an existing Addressfield field.
# Select 'Geocomplete' under Format handlers section.

Maintainers
===========

* Craig Aschbrenner (https://www.drupal.org/u/caschbre)
