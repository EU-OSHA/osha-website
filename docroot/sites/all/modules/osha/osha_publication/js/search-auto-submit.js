(function($){
    Drupal.behaviors.osha_publication_search_auto_submit = {
        attach: function(context, settings) {
            $('#osha-publication-menu-publications-form').once('osha_publication_search_auto_submit', function(){
                var $form = $(this);
                $form.find('input[type=checkbox]').click(function(){
                    $form.submit();
                });
                $form.find('select').on('change', function(){
                    $form.submit();
                });
            });
        }
    }
})(jQuery);
