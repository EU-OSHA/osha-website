(function ($) {
    $(window).load(function() {
        $('#menu_local_task_open_all_translations').click(function() {
            // MC-123 Open all languages with one click
            translations = Drupal.settings.osha.node_translations
            translations.shift()
            for (i in translations) {
                window.open(Drupal.settings.basePath + translations[i] + '/node/' + Drupal.settings.osha.node_nid + '/edit', '_blank');
            }
        });
    });
}(jQuery));
