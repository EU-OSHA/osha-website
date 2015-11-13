/* Expand vertical (left, right) menu on click */
jQuery(document).ready(function() {
    jQuery('div#block-menu-block-2').find('a.menu__link').each(function(i) {
        if (jQuery(this).parent().hasClass('is-expanded') && !jQuery(this).parent().hasClass('is-active-trail')){
            // Hide ul list
            jQuery(this).next('ul.clearfix').hide();
            // Add a span after expandable link
            jQuery(this).after("<span class='expand_menu'>&nbsp;</span>");

            // Expand/collapse menu
            jQuery(this).next('span').click(function(){
                jQuery(this).next('ul.clearfix').slideToggle();
                // Add remove css class for expanded/collapsed menu
                if (jQuery(this).hasClass('expanded')) {
                    jQuery(this).removeClass('expanded');
                }else {
                    jQuery(this).addClass('expanded');
                }
            });
        }
    });
});