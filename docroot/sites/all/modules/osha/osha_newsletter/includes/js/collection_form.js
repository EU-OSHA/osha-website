(function($) {
    $(document).ready(function() {
        $('input[name*=taxonomy_term]').closest('tr').addClass('osha_newsletter_section_admin_content');

        // Show thumbnails for selected styles
        $('#entity-collection-content-form select').each(function() {
            show_thumbnail_image(this);
        });
        $('#entity-collection-content-form select').change(function() {
            show_thumbnail_image(this);
        });

        function show_thumbnail_image(select) {
            var path = Drupal.settings.osha_newsletter.basepath;
            var img = $('<img src="/' + path + '/images/' + $(select).val() + '.png" />');
            if ($(select).siblings('img').length > 0) {
                $(select).siblings('img').replaceWith(img);
            }
            else {
                img.insertAfter($(select));
            }
        }
    });
})(jQuery);