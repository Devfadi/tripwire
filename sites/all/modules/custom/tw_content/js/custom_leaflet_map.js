(function($) {
    Drupal.behaviors.tw_content = {
      attach: function(context, settings) {
        if ($(Drupal.settings.leaflet).length) {
          if ($(Drupal.settings.leaflet[0].lMap).length) {
            var mymap = Drupal.settings.leaflet[0].lMap;
            mymap.setView([39.8283,-98.5795], 4);
          }
        }
      }
    };
  })(jQuery);
