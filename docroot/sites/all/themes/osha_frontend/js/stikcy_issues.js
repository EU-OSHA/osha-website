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
$( window ).on("load resize",function(e){
	if( $('.view-flickr-albums') ){
		if(  $(window).width()  > 660){
			 $('.view-flickr-albums .gallery-row .field-content > a').each(function( index ) {
			 	if( $('img',this ).attr('src') != undefined ){
				 	$(this).css('background','url(' + $('img',this ).attr('src')  + ')');
				 	$('img',this).css('display','none');
			 	}
			});
		} else {
			$('.view-flickr-albums .gallery-row .field-content > a').each(function( index ) {
				$(this).css('background','none');
				$('img',this).css('display','block');
			});
		}

	}
});

	});
})( jQuery );


//Js to adapt the caption to the image
jQuery( window ).load(function() {
  	width = jQuery( '.node-news .field-name-field-image img' ).width();
	jQuery( '.node-news .image-field-caption' ).css('width' , width - 30);

	width_highlight = jQuery( '.node-highlight .field-name-field-image img' ).width();
	jQuery( '.node-highlight .image-field-caption' ).css('width' , width_highlight - 30);

	width_blog = jQuery( '.node-blog .field-name-field-image img' ).width();
	jQuery( '.node-blog .image-field-caption' ).css('width' , width_blog - 30);

	
	
});
