<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<script>

jQuery(document).ready(function ($) {	
	var disp = 0;	
	if (window.innerWidth < 1220)  var numPieces = 4; else 	var numPieces = 5;
	
	var options = {
        $AutoPlay: false,
        $AutoPlaySteps: 1,
        $SlideDuration: 160,
        $SlideWidth: 200,
        $SlideSpacing: 3,
        $DisplayPieces: numPieces,
		$HWA: false,
        $BulletNavigatorOptions: {
            $Class: $JssorBulletNavigator$,
            $ChanceToShow: 1,
            $AutoCenter: 1,
        },

        $ArrowNavigatorOptions: {
            $Class: $JssorArrowNavigator$,
            $ChanceToShow: 1,
            $AutoCenter: 2,
            $Steps: 1
        }
    };
    var jssor_slider1 = new $JssorSlider$("recommended_resources", options);	
});

</script>
<div class="title_recomended_resources_home"><?php print t('Recommended resources'); ?></div>
<div id="recommended_resources">
    <div id="num_slides" u="slides">
    <?php print $rows ?>
    </div>
	<script>
		var numberOfItems = jQuery('#num_slides > div').length;
		var numPieces = 5;
		
		if (window.innerWidth < 1220) numPieces = 4;

		if (numberOfItems > numPieces) {			
			document.write("<span u='arrowleft' class='jssora03l\'></span>");
			
			document.write("<span u='arrowright' class='jssora03r'></span>");
		}
	</script>
</div>
