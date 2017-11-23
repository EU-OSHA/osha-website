jQuery(document).ready(function() {
    var organization_div = jQuery('#edit-field-organization');

    jQuery('.description', organization_div).text(Drupal.t('Mandatory'));
    jQuery('.form-item-field-organization-und-0-value > label').append('<span class="form-required" title="This field is required.">*</span>');
});
