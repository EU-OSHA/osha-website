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
            var thumbnail = $(
                '<p class="template-thumbnail" style="text-align: center">' +
                    '<img src="/' + path + '/images/templates_thumbnails/' + $(select).val() + '.png" />' +
                '</p>'
            );
            if ($(select).siblings('.template-thumbnail').length > 0) {
                $(select).siblings('.template-thumbnail').replaceWith(thumbnail);
            }
            else {
                thumbnail.insertAfter($(select));
            }
        }
    });
})(jQuery);