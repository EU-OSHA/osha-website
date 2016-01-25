(function ($) {
    $(window).load(function() {
        // MC-123 Open all languages with one click
        $('#menu_local_task_open_all_translations').click(function() {
            translations = Drupal.settings.osha.node_translations
            translations.shift()
            for (i in translations) {
                window.open(Drupal.settings.basePath + translations[i] + '/node/' + Drupal.settings.osha.node_nid + '/edit', '_blank');
            }
        });
        $('#menu_local_task_view_all_translations').click(function() {
            translations = Drupal.settings.osha.node_translations
            translations.shift()
            for (i in translations) {
                if (Drupal.settings.osha.is_publication_node == true) {
                    window.open(Drupal.settings.basePath + translations[i] + '/' + Drupal.settings.osha.path_alias + '/view', '_blank');
                }
                else {
                    window.open(Drupal.settings.basePath + translations[i] + '/' + Drupal.settings.osha.path_alias, '_blank');
                }
            }
        });
    });
}(jQuery));
