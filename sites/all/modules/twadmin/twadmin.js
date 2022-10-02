jQuery(document).ready(function($) {
    function calc_tw_users() {
        var sum = 0;
        // iterate through each td based on class and add the values
        $("tbody .regusers td.views-field-uid").each(function() {
    
            var value = $(this).text();
            // add only if the value is number
            if(!isNaN(value) && value.length != 0) {
                sum += parseFloat(value);
            }
        });
    
        $('.totalusers span').text(sum);
    }
    calc_tw_users();

    if ($('.view-people').length > 0) {
        jQuery('.views-submit-button').append("<input type=\"button\" id=\"edit-reset\" onclick=\"location.href='/admin/people';\" class=\"form-submit\" value=\"Reset\" />");
    }

     // Find and replace TripWIRE to style it
    $("#admin-menu li a").html(function () {
        return $(this).html().replace(/wire/g, '<span class="wire">wire</span>'); 
    });

    // T2OM-94: Moving export button on maillog page
    if ($('.view-Maillog .view-header .button').length > 0) {
        jQuery('.view-Maillog .view-header .button').insertAfter('.view-Maillog .views-reset-button input');
    }

    // T2OM-147: Adding class to add simple queue link
    $('a[href$="add/nodequeue"]:first').addClass("addqueue");

    // T2OM-145: Changing 'and' to 'to'
    $('.view-content-administration .views-exposed-form .form-item-created-max label, .view-content-administration .views-exposed-form .form-item-changed-max label, .view-content-administration .views-exposed-form .form-item-timestamp-max label').text('through');

      // T2OM-174: Change View button to "Add Carousel Item"
    $('.page-admin-structure-nodequeue .nodequeue-operation a').first().text("Add Carousel Item");
});