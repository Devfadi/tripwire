(function($,undefined){
  $(document).ready(function () {

  if (location.pathname == '/user/register') {
    var validname = 0;
    $('#edit-account input.username').change(function(){
      var charone = $(this).val();
      var fullname = $(this).val();
      console.log(fullname);
      charone = charone.slice(0,1);
      if (isNumeric(charone)) {
          $('#edit-account .form-item-name .description').append('<div class="namealert">Usernames may not begin with a number.</div>');
          $('#edit-account .form-item-name input.username').addClass("alertborder");
          validname = 0;
          //$('#user-register-form .multipage-pane input.multipage-link-next').addClass('disabled').prop('disabled', true).css('pointer-events', 'none');
      } else {
        $('#edit-account .form-item-name input.username').removeClass("alertborder");
        $('.namealert').remove();
        validname = 1;
        //$('#user-register-form .multipage-pane input.multipage-link-next').removeClass('disabled').prop('disabled', false).css('pointer-events', 'auto');
      }

      $min_char = 5;
      $max_char = 15;
      console.log($(this).val().length);
      if ($(this).val().length < $min_char || $(this).val().length > $max_char) {
        validname = 0;
      } else {
        validname = 1;
      }

    });

    /* TRIP2-408*/
    var target = $('#edit-account input.username')[0];
    var whatToObserve = {childList: true, attributes: true, subtree: true, attributeOldValue: true, attributeFilter: ['class', 'style']};
    var mutationObserver = new MutationObserver(function(mutationRecords) {
      $.each(mutationRecords, function(index, mutationRecord) {
        if (mutationRecord.type === 'childList') {
          if (mutationRecord.addedNodes.length > 0) {
            //DOM node added, do something
          }
          else if (mutationRecord.removedNodes.length > 0) {
            //DOM node removed, do something
          }
        }
        else if (mutationRecord.type === 'attributes') {
          if (mutationRecord.attributeName === 'class') {
            //class changed, do something
            if (mutationRecord.target.className.indexOf("progress-disabled") >= 0) {
              $('#user-register-form input.multipage-link-next').addClass('disabled').prop('disabled', true);
            } else {
              if (validname == 1) {
                $('#user-register-form input.multipage-link-next').removeClass('disabled').prop('disabled', false);
              }
            }
          } 
        }
      });
    });
    mutationObserver.observe(target, whatToObserve);
  }

  function isNumeric(n) {
    return !isNaN(parseFloat(n)) && isFinite(n);
  }

  })
})(jQuery);
