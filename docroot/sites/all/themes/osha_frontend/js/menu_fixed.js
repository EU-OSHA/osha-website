// Menu scroll
jQuery(document).ready(function() {
var nav = jQuery('#block-menu-block-1');
pos = nav.offset();
	if(jQuery("body").height()>=1100){
		// Esperamos al DOM
		jQuery(window).scroll(function(){
			// Anclamos el menú si el scroll es
			// mayor a la posición superior del tag
			if ( (jQuery(this).scrollTop() >= 140)){
			// Añadimos la clase fixes al menú y la clase stickey a breadcrumb para que se siga viendo
				//jQuery('#block-menu-block-1').addClass('fixed');
				jQuery('#header').addClass('fixedHeader');
				var text = '/blog';
				var url_blog = jQuery(location).attr('href');
				//If the URL have blog. Remove the class stickey
				if (url_blog.indexOf(text) != -1) {
					jQuery('.breadcrumb').removeClass('stickey');
				}else{
					jQuery('.breadcrumb').addClass('stickey');
				}			
			// Eliminamos las clases para volver a la posición original
			} else if ( (jQuery(this).scrollTop() <= 110)){
			// Elimina clase fixes y stickey
				//jQuery('#block-menu-block-1').removeClass('fixed');
				jQuery('.breadcrumb').removeClass('stickey');
				jQuery('#header').removeClass('fixedHeader');
			}
		});
	}
});
