(function($){
    Drupal.behaviors.osha_dangerous_substances_search_auto_submit = {
        attach: function(context, settings) {
            $('#osha-dangerous-substances-menu-dangerous-substances-form').once('osha_dangerous_substances_search_auto_submit', function(){
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
                    var languages = [], item_type = [], provider_type = [], material_country = [], tasks_covered = [], worker_groups_type = [], material_purpose_type = [], target_group = [];
                    //languages = [], types = [];
                    var uri = '';

                    $form.find('[name^=languages]:checked').each(function(){
                        languages.push($(this).val());
                    });
                    if (languages.length) {
                        uri += '/' + 'languages-' + languages.join('-');
                    }

                    $form.find('[name^=item_type]:checked').each(function(){
                        item_type.push($(this).val());
                    });
                    if (item_type.length) {
                        uri += '/' + 'item_type-' + item_type.join('-');
                    }

                    $form.find('[name^=provider_type]:checked').each(function(){
                        provider_type.push($(this).val());
                    });
                    if (provider_type.length) {
                        uri += '/' + 'provider_type-' + provider_type.join('-');
                    }

                    $form.find('[name^=material_country]:checked').each(function(){
                        material_country.push($(this).val());
                    });
                    if (material_country.length) {
                        uri += '/' + 'material_country-' + material_country.join('-');
                    }

                    $form.find('[name^=tasks_covered]:checked').each(function(){
                        tasks_covered.push($(this).val());
                    });
                    if (tasks_covered.length) {
                        uri += '/' + 'tasks_covered-' + tasks_covered.join('-');
                    }

                    $form.find('[name^=worker_groups_type]:checked').each(function(){
                        worker_groups_type.push($(this).val());
                    });
                    if (worker_groups_type.length) {
                        uri += '/' + 'worker_groups_type-' + worker_groups_type.join('-');
                    }

                    $form.find('[name^=material_purpose_type]:checked').each(function(){
                        material_purpose_type.push($(this).val());
                    });
                    if (material_purpose_type.length) {
                        uri += '/' + 'material_purpose_type-' + material_purpose_type.join('-');
                    }

                    $form.find('[name^=target_group]:checked').each(function(){
                        target_group.push($(this).val());
                    });
                    if (target_group.length) {
                        uri += '/' + 'target_group-' + target_group.join('-');
                    }

                    var url = Drupal.settings.basePath + Drupal.settings.pathPrefix;
                    url += 'themes/dangerous-substances/search_old';
                    url += uri;
                    if (typeof Drupal.settings.osha_dangerous_substances.get_params != 'undefined' && Drupal.settings.osha_dangerous_substances.get_params != null) {
                        var params_uri = [];
                        $.each(Drupal.settings.osha_dangerous_substances.get_params, function(idx, elem){
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
