/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.checkbox_autosubmit = {
        attach: function(context, settings) {
            $('.form-checkboxes.checkboxes-autosubmit').once('checkbox_autosubmit', function(){
                var $container = $(this);
                var $form = $(this).closest('form');
                var $checkboxes = $container.find('input[type=checkbox]');
                $form.find('input[type=checkbox]').on('click', function(){
                    if ($(this).is(':checked')) {
                        $checkboxes.not(this).prop('checked', false);
                    }
                    $form.submit();
                });
            });
        }
    };

})(jQuery);
