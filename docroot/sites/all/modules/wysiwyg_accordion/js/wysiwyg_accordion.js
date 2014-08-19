(function ($){
	Drupal.behaviors.wysiwyg_accordion_theme_createAccordions = {
		attach:function (context) {
            $( "#accordion" ).accordion();
		}
	}
}(jQuery));
