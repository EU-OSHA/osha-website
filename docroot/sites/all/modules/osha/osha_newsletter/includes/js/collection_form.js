(function($) {
    $(document).ready(function() {
        $('input[name*=taxonomy_term]').closest('tr').addClass('osha_newsletter_section_admin_content');

        $('#entity_collection-table select').msDropDown();
    });
})(jQuery);