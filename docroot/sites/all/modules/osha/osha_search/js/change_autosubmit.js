(function ($) {

    Drupal.behaviors.change_autosubmit = {
        attach: function(context, settings) {
            $('select.change-autosubmit').once('change_autosubmit', function(){
                $(this).on('change', function(){
                    $(this).closest('form').submit();
                });
            });
        }
    };

})(jQuery);
