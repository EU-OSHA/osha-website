jQuery(document).ready(function() {
  // Select all countries.
  jQuery('#edit-select-all-countries').change(function () {
    select_values('#edit-select-all-countries', '#edit-countries', 'all');
  });
  // Unchecked checkbox if select single options.
  jQuery('#edit-countries').change(function () {
    var selected_option = jQuery('#edit-countries option:selected').length;
    var all_options = jQuery('#edit-countries option').length;
    if (all_options - selected_option === 0) {
      jQuery('#edit-select-all-countries').attr("checked",true);
    }
    else {
      jQuery('#edit-select-all-countries').attr("checked",false);
    }
  });
});

function select_values(source, target, values) {
  jQuery('select' + target + ' > option').attr('selected', '');
  if (jQuery(source).is(":checked")) {
    if (values == 'all') {
      jQuery('select' + target + ' > option').attr('selected', 'selected');
    }
    else {
      jQuery.each(values, function (i, val) {
        jQuery('' + target + ' option[value="' + val + '"]').attr('selected', 'selected');
      });
    }
  }
}
