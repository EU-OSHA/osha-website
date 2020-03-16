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
						$('#header').removeClass('hide-header');
					}		        
	      }
		    prevScrollpos = currentScrollPos;
		  });
		}
	});
})( jQuery );





  //Tools and resources page GRID
(function( $ ){
	$(document).ready(function() {
	  if($('.content-box-sub')) 
	  {
	  	var arrayHeight = [];
	  	var items = $('.content-box-sub');
	  	var titleBox = $('.content-box-sub .menu__link h2');
			$.each(items, function( key, value ) {
				arrayHeight[key] = $('h2',this).height();
			  $('h2',this).prependTo( $('.menu__link .content-img',this));
			});

			 maxValueInArray = Math.max.apply(Math, arrayHeight);
			 $(titleBox).css('min-height',maxValueInArray+'px');

			$(window).resize(function(){
				$(titleBox).removeAttr('style');
				var arrayHeight = [];
				$.each(items, function( key, value ) {
					arrayHeight[key] = $('h2',this).height();
				});
				maxValueInArray = Math.max.apply(Math, arrayHeight);
				$(titleBox).css('min-height',maxValueInArray+'px');
			});
	  };
	});
})( jQuery );


/* Hide border on publications */
(function( $ ){
	$(document).ready(function() {

		if ($(".container.additional")[0]){
			$(".publications-detail").addClass('add-border');
		}
	});
})( jQuery );