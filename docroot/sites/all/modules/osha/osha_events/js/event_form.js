jQuery(document).ready(function() {
    var type_input = jQuery('#edit-field-event-type-und');
    var country_div = jQuery('#edit-field-country-code');
    var city_div = jQuery('#edit-field-city');

    if (type_input.val() == 'Webminar') {
        jQuery('.form-item-field-country-code-und > label').find('span').remove();
        jQuery('.form-item-field-city-und-0-value > label').find('span').remove();
        jQuery('.description', country_div).text('N/A');
        jQuery('.description', city_div).text('N/A');
        jQuery('input', city_div).val('None');
        jQuery('#edit-field-city-und-0-value').attr('disabled','disabled').val('');
        jQuery('#edit-field-country-code-und').attr('disabled', true).val('').trigger("chosen:updated");
    } else {
        if (!jQuery('.form-item-field-country-code-und > label > span').hasClass('form-required')) {
            jQuery('.form-item-field-country-code-und > label').append('<span class="form-required" title="This field is required.">*</span>');
        }
        if (!jQuery('.form-item-field-city-und-0-value > label > span').hasClass('form-required')) {
            jQuery('.form-item-field-city-und-0-value > label').append('<span class="form-required" title="This field is required.">*</span>');
        }
    }
    type_input.change(function() {
        if (jQuery(this).val() == 'Webminar') {
            jQuery('.form-item-field-country-code-und > label').find('span').remove();
            jQuery('.form-item-field-city-und-0-value > label').find('span').remove();
            jQuery('.description', country_div).text('N/A');
            jQuery('.description', city_div).text('N/A');
            jQuery('#edit-field-city-und-0-value').attr('disabled','disabled').val('');
            jQuery('#edit-field-country-code-und').attr('disabled', true).val('').trigger("chosen:updated");
            jQuery('input', city_div).val('None');
        }
        else {
            if (!jQuery('.form-item-field-country-code-und > label > span').hasClass('form-required')) {
                jQuery('.form-item-field-country-code-und > label').append('<span class="form-required" title="This field is required.">*</span>');
            }
            if (!jQuery('.form-item-field-city-und-0-value > label > span').hasClass('form-required')) {
                jQuery('.form-item-field-city-und-0-value > label').append('<span class="form-required" title="This field is required.">*</span>');
            }
            jQuery('.description', country_div).text(Drupal.t('Mandatory'));
            jQuery('.description', city_div).text(Drupal.t('Mandatory'));
            if (jQuery(this).val() != 'FAST') {
              jQuery('input', city_div).val('');
            }
            jQuery('#edit-field-city-und-0-value').removeAttr('disabled');
            jQuery('#edit-field-country-code-und').removeAttr('disabled').trigger("chosen:updated");
        }
    });
});
