(function ($) {

  Drupal.behaviors.search_sort = {
    attach: function (context, settings) {
      jQuery('#edit-sort-by').change(function () {
        jQuery('#views-exposed-form-musculoskeletal-disorders-list-page #edit-sort-by--2').val(jQuery(this).val());
        jQuery('#views-exposed-form-musculoskeletal-disorders-list-page').submit();
      });
      jQuery('#edit-sort-order').change(function () {
        jQuery('#views-exposed-form-musculoskeletal-disorders-list-page #edit-sort-order--2').val(jQuery(this).val());
        jQuery('#views-exposed-form-musculoskeletal-disorders-list-page').submit();
      });
      if (jQuery('#osha-musculoskeletal-disorders-sort-form').length) {
        document.getElementById('osha-musculoskeletal-disorders-sort-form').onsubmit = function () {
          return false;
        };
      }
    }
  }
})(jQuery);
