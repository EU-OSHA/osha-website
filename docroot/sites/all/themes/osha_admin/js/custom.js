(function ($) {
    Drupal.behaviors.oshaAdminTheme = {
        attach: function (context, settings) {
            $('.page-entity-collection #views-form-newsletter-node-selection-newsletter-selection-view-page .views-table tbody .views-field-title').each(function( index ) {
              $('a',this).html( jQuery('a',this).html( jQuery('a',this).text() )[0].innerText );
            }); 
        }
    };
})(jQuery);