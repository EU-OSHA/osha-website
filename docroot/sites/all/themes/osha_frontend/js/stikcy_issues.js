//Solving issues with stiky header
jQuery(document).ready(function() {
	jQuery(".ui-accordion-header").click(function(){

		jQuery('html, body').animate({
	      scrollTop: jQuery(this).offset().top-145

	    }, 50);

	});
});

(function( $ ){
	$(document).ready(function() {

		
		$('.node-type-events .group-events-description .field-item > p').each(function( index ) {
			console.log( $( this ).html() );
			if( $( this ).html() == '<span><br></span>' || $( this ).html() == '<span><br></span><br>' || $( this ).html() == '<br><br>' || $( this ).html() == '<span>&nbsp;</span>' || $( this ).html() == '&nbsp;' || $( this ).html() == '<br>' ){
				$( this ).remove();
			}
		});


	if( $('.node-type-press-release article.node-press-release .field p') ){
		$('.node-type-press-release article.node-press-release .field p').each(function( index ) {
			if( $( this ).html() == '&nbsp;' || $( this ).html() == '<strong>&nbsp;</strong>'){
				$( this ).remove();
			}
		});
	}

	});
})( jQuery );

