/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_sort = {
        attach: function(context, settings) {
            jQuery('#edit-sort-by').change(function() {
                jQuery('#views-exposed-form-practical-tools-and-guidance-on-dangerous-substances-page #edit-sort-by--2').val(jQuery(this).val());
                jQuery('#views-exposed-form-practical-tools-and-guidance-on-dangerous-substances-page').submit();
            });
            jQuery('#edit-sort-order').change(function() {
                jQuery('#views-exposed-form-practical-tools-and-guidance-on-dangerous-substances-page #edit-sort-order--2').val(jQuery(this).val());
                jQuery('#views-exposed-form-practical-tools-and-guidance-on-dangerous-substances-page').submit();
            });
            if (jQuery('#hwc-practical-tool-sort-form').length) {
              document.getElementById('osha-practical-tool-sort-form').onsubmit = function() {
                return false;
              };
            }
        }
    }
})(jQuery);
