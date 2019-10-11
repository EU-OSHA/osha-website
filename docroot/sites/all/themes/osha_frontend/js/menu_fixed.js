// Menu scroll
/* Sticky menu revamp desing */
(function( $ ){
	$(document).ready(function() {

		if (!$(".no-sticky-infographic")[0])
		{
			var prevScrollpos = $(window).offset.top;

			$(window).on("load resize scroll",function(e){
				if( $(window).width() > 1006 )
				{
					$('body').css('padding-top','12.9rem');
				} else {
					$('body').css('padding-top','155px');
				}
			});
			
			$('#header').addClass('fixedHeader');

			$(window).scroll(function(){
		    var currentScrollPos = $(window).scrollTop();
	      if(prevScrollpos > currentScrollPos)
	      {
	        $('#header').removeClass('hide-header');
	      }
	      else
	      {
					$('#header').addClass('hide-header');
					if( ($(this).scrollTop() <= 80) )
					{
						//$('#header').removeClass('hide-header');
					}		        
	      }
		    prevScrollpos = currentScrollPos;
		  });
		}
	});
})( jQuery );