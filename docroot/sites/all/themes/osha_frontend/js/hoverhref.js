jQuery(document).ready(function () {

    hoverThemes();
  
});


function hoverThemes() {
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-image img",this).mouseover(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #DC2E81");
		obj.find(".introduction-title a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 50% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-image img",this).mouseout(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #D2DCED");
		obj.find(".introduction-title a").css("background","none");
		});
	});
	
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-title",this).mouseover(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #DC2E81");
		obj.find(".introduction-title a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 50% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-title",this).mouseout(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #D2DCED");
		obj.find(".introduction-title a").css("background","none");
		});
	});
}




