jQuery(document).ready(function($) {
    /* TRIP2-501 */
    $('#edit-account .form-item-status').hide();

    /* TRIP2-535: Disabling ability for help desk users to edit user name */
    $('.form-item-name input.username').attr("disabled", "disabled");
    $('.form-item-name input.username').addClass('disabled');
    $('.form-item-roles .elevated input, .form-item-roles .regattr input').each(function(){
        //$(this).attr("disabled", "disabled");
        $(this).addClass("readonly");
    });
    $('input.readonly').on('click', function(evt) {
        evt.preventDefault();
    });
});