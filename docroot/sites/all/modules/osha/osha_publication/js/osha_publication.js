(function ($) {
    Drupal.behaviors.osha_publication = {
        attach: function (context, settings) {
            jQuery('.view-slideshare').click(function (e) {
                e.preventDefault();
                id = jQuery(this).data('id');
                popup = '<div id="slideshare-popup-container">' +
                '<div class="close-slideshare-popup-container"><button class="close-slideshare-popup"><span>x</span></button></div>' +
                '<div class="slideshare-widget-container">' +
                Drupal.settings.osha_slideshare.html[id] +
                '</div></div>';
                jQuery('#page .related-resources').append(popup);
                jQuery('#slideshare-popup-container button').click(function (e) {
                    jQuery("#slideshare-popup-container").remove();
                });
            });
        }
    }
}(jQuery));
