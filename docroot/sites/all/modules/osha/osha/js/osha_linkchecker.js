(function ($) {
    $(window).load(function () {
        if (Drupal.settings.osha_linkchecker.urls) {
            for (var i = 0; i < Drupal.settings.osha_linkchecker.urls.length; i++) {
                var url = Drupal.settings.osha_linkchecker.urls[i];
                jQuery("a[href*='" + url + "']").attr('data-linkchecker', '');
            }
        }
    });
}(jQuery));
