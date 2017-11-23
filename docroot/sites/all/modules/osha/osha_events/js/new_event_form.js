jQuery(document).ready(function() {
    var organization_div = jQuery('#edit-field-organization');

    jQuery('.description', organization_div).text('');
    jQuery('.form-item-field-organization-und-0-value > label').find('span').remove();

    var start_date = jQuery('#edit-field-start-date-und-0-value-datepicker-popup-0');
    var end_date = jQuery('#edit-field-start-date-und-0-value2-datepicker-popup-0');
    start_date.change(function() {
        end_date.val(start_date.val());
    });
});
