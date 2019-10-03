(function ($) {
    Drupal.behaviors.search_sort = {
        attach: function (context, settings) {
            jQuery('#edit-from-date-datepicker-popup-0').change(function () {
                jQuery('#edit-field-start-date-value-datepicker-popup-0').val(jQuery(this).val());
                jQuery('#views-exposed-form-newevents-page').submit();
            });
            jQuery('#edit-to-date-datepicker-popup-0').change(function () {
                jQuery('#edit-field-start-date-value2-datepicker-popup-0').val(jQuery(this).val());
                jQuery('#views-exposed-form-newevents-page').submit();
            });
            if (jQuery('#osha-events-dates-form').length) {
              document.getElementById('osha-events-dates-form').onsubmit = function () {
                return false;
              };
            }
        }
    }
})(jQuery);
