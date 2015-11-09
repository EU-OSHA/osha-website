jQuery(document).ready(function() {
    jQuery('#edit-field-country-tid').change(filter_language_list);
});

jQuery(document).ajaxComplete(function(e, xhr, settings) {
    filter_language_list();
    jQuery('#edit-field-country-tid').change(filter_language_list);

});

function filter_language_list() {
    country_langs = Drupal.settings.osha_eguide.country_langs;
    country = jQuery('#edit-field-country-tid').val();
    current_country_langs = country_langs[country];
    language_dropdown = jQuery('#edit-field-language-value');
    language_dropdown_current_value = language_dropdown.val();
    language_dropdown.find('option').remove();
    for ( i = 0 ; i < current_country_langs.length; i++) {
        is_selected = language_dropdown_current_value == current_country_langs[i].code ? true : false;
        option = jQuery('<option>', {
            value: current_country_langs[i].code,
            text: current_country_langs[i].language
        });
        if (is_selected) {
            option.attr({'selected': 'selected'});
        }
        language_dropdown.append( option );
    }
}