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
                // Prevent submit of form - we build the pretty path url and
                // redirect the user to that path.
                $form.submit(function(e) {
                    var tags =[], languages = [], types = [];
                    var uri = '';
                    $form.find('[name^=tags]:checked').each(function(){
                        tags.push($(this).val());
                    });
                    if (tags.length) {
                        uri += '/' + 'tags_' + tags.join('_');
                    }
                    $form.find('[name^=languages]:checked').each(function(){
                        languages.push($(this).val());
                    });
                    if (languages.length) {
                        uri += '/' + 'l_' + languages.join('_');
                    }
                    $form.find('[name^=publication_type]:checked').each(function(){
                        types.push($(this).val());
                    });
                    if (types.length) {
                        uri += '/' + 'tags_' + types.join('_');
                    }
                    var url = Drupal.settings.basePath + Drupal.settings.pathPrefix;
                    url += 'tools-and-publications/publications';
                    url += uri;
                    if (typeof Drupal.settings.osha_publication.get_params != 'undefined' && Drupal.settings.osha_publication.get_params != null) {
                        var params_uri = [];
                        $.each(Drupal.settings.osha_publication.get_params, function(idx, elem){
                            params_uri.push(elem + '=' + $('[name=' + elem +']').val());
                        });
                        if (params_uri.length) {
                            url += '?' + params_uri.join('&');
                        }
                    }
                    window.location = url;
                    return false;
                });
            });
        }
    }
})(jQuery);
