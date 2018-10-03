(function($) {
    Drupal.behaviors.osha_musculoskeletal_disorders = {
        attach : function(context) {
            jQuery('#edit-field-for-pictogram-guide-und .form-checkbox').change(function() {
                jQuery('#edit-field-for-pictogram-guide-und .form-checkbox').not(this).prop('checked',false);
            });
        }
    };
})(jQuery);
