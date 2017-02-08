/* Align heights */
jQuery(document).ready(function () {
	var maxSize = 0;
	var simpleLine = 16;
	var multiLine = 16;

	function startTest (){
		jQuery("a.f1Level").each(function() {
			checkSize (jQuery(this));
		});
		jQuery("a.f1Level").each(function() {
			updateHeightMenu (jQuery(this));
		});
	}

	
	function checkSize (obj){
		if (obj.height() > maxSize) maxSize = obj.height();
	}
	
	
	function updateHeightMenu (obj) {
		var elTexto = obj.html();		
		if (obj.height() < maxSize) {
			elTexto += '<br><br>';
			obj.html(elTexto);
			
		}
	}
	
	
	function clearBR (){	
		var posFinal = null;

		jQuery("a.f1Level").each(function() {
			var obj = jQuery(this);			
			elTexto = obj.html();						
			posFinal = elTexto.indexOf("<br>");
			if (posFinal != -1) elTexto = elTexto.substring(0, posFinal);			
			obj.html(elTexto);
		});		
		maxSize = 0;
	}

	jQuery("#block-menu-block-1 .menu li").mouseover(function() {	
		if (maxSize > 16)			
			jQuery(this).find("ul").css("margin-top", multiLine+"px");
		else
			jQuery(this).find("ul").css("margin-top", simpleLine+"px");			
	});
	
	jQuery(window).resize(function() {
		clearBR();
		startTest ();
	});
	startTest ();
});


/* remove br in site map */

jQuery(document).ready(function() {
    jQuery(".page-sitemap #content br").remove();
});