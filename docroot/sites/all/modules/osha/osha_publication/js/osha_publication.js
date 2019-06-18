(function ($) {
    Drupal.behaviors.osha_publication = {
        attach: function (context, settings) {
            jQuery('#osha-publication-download-form select').change(function () {
                if (jQuery('#edit-selected option:selected').length == 1) {
                    var lang = jQuery('#edit-selected option:selected').val();
                    var href = Drupal.settings.osha_publication.links[lang];
                    jQuery('#osha-publication-download-form #download_pdf').attr('href', href);
                }
            });
            jQuery('#osha-publication-download-form #download_pdf').click(function (e) {
                if (jQuery('#edit-selected option:selected').length != 1) {
                    e.preventDefault();
                    var $form = $(this).closest('form');
                    $form.submit();
                }
            });
            
            jQuery('.view-slideshare').click(function (e) {
                e.preventDefault();
                id = jQuery(this).data('id');
                popup = '<div id="slideshare-popup-container">' +
                '<div class="close-slideshare-popup-container"><button class="close-slideshare-popup"><span>x</span></button></div>' +
                '<div class="slideshare-widget-container">' +
                Drupal.settings.osha_slideshare.html[id] +
                '</div></div>';
                jQuery('.related-resources').append(popup);
                jQuery('#slideshare-popup-container button').click(function (e) {
                    jQuery("#slideshare-popup-container").remove();
                });
            });
        }
    }
}(jQuery));
