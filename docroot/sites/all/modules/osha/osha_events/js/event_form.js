jQuery(document).ready(function() {
    var type_input = jQuery('#edit-field-event-type-und');
    var country_div = jQuery('#edit-field-country-code');
    var city_div = jQuery('#edit-field-city');
    if (type_input.val() == 'Webminar') {
        jQuery('.description', country_div).text('N/A');
        jQuery('.description', city_div).text('N/A');
    }
    type_input.change(function() {
        if (jQuery(this).val() == 'Webminar') {
            jQuery('.description', country_div).text('N/A');
            jQuery('.description', city_div).text('N/A');
        }
        else {
            jQuery('.description', country_div).text(Drupal.t('Mandatory'));
            jQuery('.description', city_div).text(Drupal.t('Mandatory'));
        }
    });
});
