(function ($) {
	$(document).ready(function(){
			if($('#edit-field-county-und-0-value').length){
					$('.form-item.form-type-textfield.form-item-field-county-und-0-value').append($('<br /><a id="btnFindCounty" href="#a">Lookup County</a>'));
			}

			$("#btnFindCounty").click(function(){
					//get value from zipcode field})(jQuery);
					var value = $("#edit-field-address-und-0-postal-code").val();
					if (value.length === 5)
					{
							//request to get data
							$.ajax({
									url: Drupal.settings.basePath + 'api/county-zip?zip_code='+value,
									type: "get",
									data: {
											format: "json"
									},
									success:function(result){
											// pass json format data to variable
											let arrayCounties = result;
											$("#edit-field-county-und-0-value").val(arrayCounties[0].county);
									},
									error: function (xhr, ajaxOptions, thrownError) {
													alert(xhr.status);
													alert(thrownError);
									}
							});
							$("#edit-field-county-und-0-value").focus();
					}
					else
					{
							alert('Please enter zip code for county lookup');
							$("#edit-field-address-und-0-postal-code").focus();
					}
			});
	});
})(jQuery);