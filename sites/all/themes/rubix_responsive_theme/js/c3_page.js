jQuery(document).ready(function() {
	jQuery(".c3-page-filters #edit-title").parent(".form-item").append("<span class='close-icon'></span>");

	jQuery(".c3-page-filters #edit-title").on("input" , function(){
		var thisVal = $(this).val();
		if(thisVal.length > 0){
			$(this).parent(".form-item").addClass("show-cross");
	} else {
		$(this).parent(".form-item").removeClass("show-cross");
	}
	});

	jQuery(".c3-page-filters #edit-title-wrapper .close-icon").on("click" , function(){
		$(this).parent(".form-item").find("#edit-title").val("");
		$(this).parent(".form-item").removeClass("show-cross");
    });
});