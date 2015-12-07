jQuery(document).ready(function() {
    var type_input = jQuery('#edit-field-event-type-und');
    var country_div = jQuery('#edit-field-country-code');
    var city_div = jQuery('#edit-field-city');
    if (type_input.val() == 'Webminar') {
        country_div.hide();
        city_div.hide();
    }
    type_input.change(function() {
        if (jQuery(this).val() == 'Webminar') {
            country_div.hide();
            city_div.hide();
        }
        else {
            country_div.show();
            city_div.show();
        }
    });
});
