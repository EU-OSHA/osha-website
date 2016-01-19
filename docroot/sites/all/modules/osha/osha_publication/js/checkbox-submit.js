(function($){
    Drupal.behaviors.osha_publication = {
        attach: function(context, settings) {
            $('#osha-publication-menu-publications-form input[type=checkbox]', context).click(function(){
                $('#osha-publication-menu-publications-form').submit();
            });
        }
    }
})(jQuery);
