(function (jQuery) {
    jQuery(document).ready(function(){
        jQuery('#block-osha-blocks-osha-block-group-related .field-content a').on('click', function() {
            if (jQuery(this).parent().hasClass('more-link')) {
                return true;
            }
            if (typeof _paq != 'undefined') {
                _paq.push(['trackEvent', 'Related', 'click', jQuery(this).attr('href'), 1]);
            }
        });
    });
})(jQuery);
