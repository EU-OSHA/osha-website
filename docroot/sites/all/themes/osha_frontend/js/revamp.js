jQuery(document).ready(function($){

	var video1 = $(".videoModal-1").attr("src");
	var video2 = $(".videoModal-2").attr("src");
	var video3 = $(".videoModal-3").attr("src");

   // Get the modal
	var modal1 = document.getElementById('myModal1');
	var modal2 = document.getElementById('myModal2');
	var modal3 = document.getElementById('myModal3');

	// Get the button that opens the modal
	var btn1 = document.getElementById("myBtn1");
	var btn2 = document.getElementById("myBtn2");
	var btn3 = document.getElementById("myBtn3");

	// Get the <span> element that closes the modal
	var span1 = document.getElementsByClassName("close1")[0];
	var span2 = document.getElementsByClassName("close2")[0];
	var span3 = document.getElementsByClassName("close3")[0];

	// When the user clicks the button, open the modal 
	$(btn1).click(function() {
	  modal1.style.display = "block";
	  $(".videoModal-1").attr("src",video1);
	  $(".videoModal-1").prop("allow",'autoplay');
	});

	$(btn2).click(function() {
	  modal2.style.display = "block";
	  $(".videoModal-2").attr("src",video2);
	  $(".videoModal-2").prop("allow",'autoplay');
	});

	$(btn3).click(function() {
	  modal3.style.display = "block";
	  $(".videoModal-3").attr("src",video3);
	  $(".videoModal-3").prop("allow",'autoplay');
	});

	// When the user clicks on <span> (x), close the modal
	$(span1).click(function() {
	  modal1.style.display = "none";
      $(".videoModal-1").attr("src","");
		
	});

	// When the user clicks on <span> (x), close the modal
	$(span2).click(function() {
	  modal2.style.display = "none";
	  $(".videoModal-2").attr("src","");
	  
	});

	// When the user clicks on <span> (x), close the modal
	$(span3).click(function() {
	  modal3.style.display = "none";
	  $(".videoModal-3").attr("src","");
	  
	});



	/* Responsive Search Menu */
	if ($(window).width() < 1023) {
		$('#edit-actions').on('click', function() {
		    if ($('#edit-search-block-form--2').css('opacity') == 0) {
		       $('#edit-search-block-form--2').css('display', 'block');
		       $('#edit-search-block-form--2').addClass('expand');
		       $('#block-search-form').addClass('expand'); 
		    }
		    else {
		        $('#edit-search-block-form--2').css('display', 'none');
		        $('#edit-search-block-form--2').removeClass('expand');
		        $('#block-search-form').removeClass('expand');
		        //$("#edit-submit--2").click() TO DO
		    }
		});
	}  


	/* Sticky menu revamp desing */

	if (!$(".no-sticky-infographic")[0]){
	    var nav = $('#block-menu-block-1');
		pos = nav.offset();
		if($("body").height()>=1100){
			if($("body").width()>= 1024) {
				$(window).scroll(function(){
					if ( ($(this).scrollTop() >= 340)){
						$('#header').addClass('fixedHeader');
						var text = '/blog';
						var url_blog = $(location).attr('href');
						if (url_blog.indexOf(text) != -1) {
							$('.breadcrumb').removeClass('stickey');
						}else{
							$('.breadcrumb').addClass('stickey');
						}			
					} else if ( ($(this).scrollTop() <= 110)){
						$('.breadcrumb').removeClass('stickey');
						$('#header').removeClass('fixedHeader');
					}
				});
			}
		}
	}

	/* No pagerer display - move result @total results */
	if (!$(".pagerer-pager ")[0]){
		$('.pager-total').addClass('no-pagerer');
	}
	

	/*Ellipsis News and Events Home page*/

	var character = 60;
	var count1 = $("div.view-news-and-events > div.row > div:nth-child(1) > h3 > a").text().length;
	var count2 = $("div.view-news-and-events > div.row > div:nth-child(2) > h3 > a").text().length;
	var count3 = $("div.view-news-and-events > div.row > div:nth-child(3) > div:nth-child(2) > h3 > a").text().length;

	if (count1 > character){
		$("div.view-news-and-events > div.row > div:nth-child(1) > h3 a").text(function(){
    		return $(this).text().substring(0,character);
		});
		$( "div.view-news-and-events > div.row > div:nth-child(1) > h3 a" ).append( "..." );
	}

	if (count2 > character){
		$("div.view-news-and-events > div.row > div:nth-child(2) > h3 a").text(function(){
    		return $(this).text().substring(0,character);
		});
		$( "div.view-news-and-events > div.row > div:nth-child(2) > h3 a" ).append( "..." );
	}

	if (count3 > character){
		$("div.view-news-and-events > div.row > div:nth-child(3) > div:nth-child(2) > h3 a").text(function(){
    		return $(this).text().substring(0,character);
		});
		$( "div.view-news-and-events > div.row > div:nth-child(3) > div:nth-child(2) > h3 a" ).append( "..." );
	}

	/*Ellipsis Home intro boxes*/
	
	var character_intro = 72;
	var count1_intro = $(".home-intro > div:nth-child(1) > a:nth-child(1) > h2").text().length;
	var count2_intro = $(".home-intro > div:nth-child(2) > a:nth-child(1) > h2").text().length;
	var count3_intro = $(".home-intro > div:nth-child(3) > a:nth-child(1) > h2").text().length;

	if (count1_intro >= character_intro){
		$(".home-intro > div:nth-child(1) > a:nth-child(1) > h2").text(function(){
    		return $(this).text().substring(0,character_intro);
		});
		$( ".home-intro > div:nth-child(1) > a:nth-child(1) > h2" ).append( "..." );
	}

	if (count2_intro >= character_intro){
		$(".home-intro > div:nth-child(2) > a:nth-child(1) > h2").text(function(){
    		return $(this).text().substring(0,character_intro);
		});
		$( ".home-intro > div:nth-child(2) > a:nth-child(1) > h2" ).append( "..." );
	}

	if (count3_intro >= character_intro){
		$(".home-intro > div:nth-child(3) > a:nth-child(1) > h2").text(function(){
    		return $(this).text().substring(0,character_intro);
		});
		$( ".home-intro > div:nth-child(3) > a:nth-child(1) > h2" ).append( "..." );
	}

	/* Cookies declined */
	$(".decline-button").click(function() {
		$('#sliding-popup').remove();
	});
	
});
