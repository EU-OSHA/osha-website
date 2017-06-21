jQuery(document).ready(function() {
    var tags_div = jQuery('#edit-field-tags');
    var organization_div = jQuery('#edit-field-organization');
    jQuery('.description', tags_div).text(Drupal.t('Mandatory'));
    jQuery('.description', organization_div).text(Drupal.t('Mandatory'));
    jQuery('.form-item-field-tags-und > label').append('<span class="form-required" title="This field is required.">*</span>');
    jQuery('.form-item-field-organization-und-0-value > label').append('<span class="form-required" title="This field is required.">*</span>');
});
