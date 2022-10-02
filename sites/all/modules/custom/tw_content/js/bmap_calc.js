(function($) {
    Drupal.behaviors.confirmPopUp = {
      attach: function (context, settings) {

        $(document).ready(function() {
          //jQuery('.field-name-field-products-delivered input').prop("disabled", true);
          function reCalc() {
            var count = 0;
  	    var posters = parseInt(jQuery('.field-name-field-posters input').val());
            var stickers = parseInt(jQuery('.field-name-field-stickers input').val());
            var cards = parseInt(jQuery('.field-name-field-cards input').val());
            var trifolds = parseInt(jQuery('.field-name-field-tri-folds input').val());
            count = posters + stickers + cards + trifolds;
            jQuery('.field-name-field-products-delivered input').val(count);
          }
        reCalc();
        jQuery('.field-name-field-posters input, .field-name-field-stickers input, .field-name-field-cards input, .field-name-field-tri-folds input').keyup(function() {
          reCalc();
        });
        });

      }
    };
    })(jQuery);
