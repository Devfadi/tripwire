jQuery(document).ready(function($) {
    var fieldCount = [];
    var status = [];
    var i = 0;
    $('#tw-maintenance-settings input.form-text').each(function(){
        i++;
        fieldCount[i] = 0;
        $(this).attr("envname", "env" + i);
        var envname = $(this).attr("envname");
        checkUrls(envname, i, $(this));
        $(this).on('input',function(e){
            checkUrls(fieldCount[i], i, $(this));
    
        });
    });

    function checkUrls(envname, i, val) {
        if(/^(http|https|ftp):\/\/[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,5}(:[0-9]{1,5})?(\/.*)?$/i.test($(val).val())){
            //console.log("valid URL!");
            $(val).css("border", "2px solid green");
            status[envname] = 1;
            //console.log("val for " + envname + " is " + status[i]);
        } else {
            //console.log("invalid URL!");
            $(val).css("border", "2px solid red");
            status[envname] = 0;
            //console.log("val for " + envname + " is " + status[i]);
        }

        if (status[envname] == 0 || status[envname] == 0 || status[envname] == 0) {
            $('#tw-maintenance-settings input.form-submit').attr("disabled", "disabled");
            $('#tw-maintenance-settings input.form-submit').addClass("disabled");
        } else {
            $('#tw-maintenance-settings input.form-submit').removeAttr("disabled");
            $('#tw-maintenance-settings input.form-submit').removeClass("disabled");
        }
    }
});