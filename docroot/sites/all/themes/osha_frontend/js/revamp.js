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

		$('#edit-actions--2').on('click', function() {
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


	/* No pagerer display - move result @total results */
	if (!$(".pagerer-pager ")[0]){
		$('.pager-total').addClass('no-pagerer');
	}

	/* Add class to Related Resources content depend the sidebars*/
	if ($(".sidebars_first")[0]){
		$('.article_related_resources').addClass('sidebars_first_true');
	}

	if ($(".sidebars_second")[0]){
		$('.article_related_resources').addClass('sidebars_second_true');
	}

	if ($(".publication_related_resources")[0]){
		$('#footer').addClass('no-margin');
	}


	/*Ellipsis News and Events Home page*/

	var character = 60;
	var count3 = $("div.view-news-and-events > div.row > div:nth-child(3) > div:nth-child(2) > h3 > a").text().length;

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

	/* Track in Matomo if Page not found, the URl that led to it */
	if (typeof _paq != 'undefined') {
		var url = document.location.href;

		var http = new XMLHttpRequest();
		http.open("HEAD", url, false);
		http.send();

		if (http.status == 404)
		{
			console.log("PAGE NOT FOUND");
			_paq.push(['trackEvent', 'Page not found', 'Page not found', url, 1]);
		}
    }


  jQuery(".page-themes-dangerous-substances-glossary .view-content .glossary_type .type-name").click(function(){
    jQuery(this).parent().toggleClass("active");
  });

  	/* Hide country and location if is empty */
  	$("body.page-oshevents .event-country").filter(function() {
    	return $(this).text() === ", ";
	}).css("display", "none");


  	/* Fix responsive menu scroll - MDR-3893 */ 
  	$(".meanmenu-reveal ").click(function() {
		$('.fixedHeader').toggleClass('no-fixed-menu-expanded');
	});

	if (typeof _paq != 'undefined') {
		$('.view-osha-home-banner-top .home-boxes a').click(function(e) {
			var l = document.createElement("a");
			l.href = jQuery(this).attr('href');
			var path = l.pathname;
			if (l.hostname === 'healthy-workplaces.eu') {
				path = l.pathname.substring(3);
			}
			if (l.hostname === 'oiraproject.eu') {
				path = l.pathname.substring(3);
			}
			if (l.hostname === 'osha.europa.eu') {
				path = l.pathname.substring(3);
			}
			if (l.hostname === 'www.napofilm.net') {
				path = l.pathname.substring(3);
			}
			path = 'https://' + l.hostname + path + '|' + $(this).closest('.home-boxes').data('changed');
			_paq.push(['trackEvent', 'Banner', 'Click', path]);
		});
	}
});

function agree_processing(id) {
    if (jQuery(id).prop('checked')) {
      return true;
    }
    return false;
}

function onSubscribe(button) {
    if (agree_processing('#edit-agree-processing-personal-data')) {
      return true;
    }
    return false;
}

function onFooterSubscribe(button) {
    if (agree_processing('#edit-agree-processing-personal-data--2')) {
      return true;
    }
    return false;
}

function onCaptchaSubscribe(button) {
    if (agree_processing('#edit-agree-processing-personal-data--3')) {
      return true;
    }
    return false;
}

function toggleNewsletterSubmit(checkbox_id, submit_id) {
    if (agree_processing(checkbox_id)) {
      jQuery(submit_id).prop('disabled', false).removeAttr('disabled');
    }
    else {
      jQuery(submit_id).prop('disabled', true);
    }
}
function onCaptchaCheckboxChange(obj) {
	// console.log(obj);
	// console.log(jQuery(obj));
}

jQuery(document).ready(function($) {

    // Left newsletter block.
    var checkbox_id = '#edit-agree-processing-personal-data';
    var submit_id = '#osha-newsletter-block-subscribe-form .form-submit';
    jQuery(checkbox_id).click(function () {
      toggleNewsletterSubmit(checkbox_id, submit_id);
    });

    // Footer newsletter block.
    var footer_checkbox_id = '#edit-agree-processing-personal-data--2';
    var footer_submit_id = '#osha-newsletter-footer-block-subscribe-form .form-submit';
    jQuery(footer_checkbox_id).click(function () {
      toggleNewsletterSubmit(footer_checkbox_id, footer_submit_id);
    });
});
