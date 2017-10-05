//Solving issues with stiky header
jQuery(document).ready(function() {
	jQuery(".ui-accordion-header").click(function(){

		jQuery('html, body').animate({
	      scrollTop: jQuery(this).offset().top-145

	    }, 50);

	});
});