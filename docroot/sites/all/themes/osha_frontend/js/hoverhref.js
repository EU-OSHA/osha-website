jQuery(document).ready(function () {
    hoverThemes();
	zoomMedium();
	hoverSlideHome();
});


function hoverThemes() {
	jQuery("#block-menu-block-3 .menu-block-3 ul li").each(function(index) {
		var obj=jQuery(this);		
		jQuery(this).mouseover(function() {
			obj.addClass('active');
		});
		jQuery(this).mouseout(function() {
			obj.removeClass('active');
		});

		if( jQuery('.blockquote-copyright',this).text().length < 2 ){
			jQuery('.image-field-caption',this).remove();
		}

	});
	
	/*INFOGRAPHICS*/
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-field-thumbnail img",this).mouseover(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #DC2E81");
		obj.find(".views-field-title-field a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 25% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-field-thumbnail img",this).mouseout(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #D2DCED");
		obj.find(".views-field-title-field a").css("background","none");
		});
	});
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-title-field",this).mouseover(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #DC2E81");
		obj.find(".views-field-title-field a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 25% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-title-field",this).mouseout(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #D2DCED");
		obj.find(".views-field-title-field a").css("background","none");
		});
	});
	
}


function hoverSlideHome() {

	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseover(function() {
		jQuery("h2",this).addClass('text_white');
		jQuery("h2",this).removeClass('text_blue');
		});
	});
	
	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseout(function() {
		jQuery("h2",this).addClass('text_blue');
		jQuery("h2",this).removeClass('text_white');
		});
	});	
	
	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseover(function() {
		jQuery("img",this).addClass('img_opac');
		jQuery("img",this).removeClass('img_no_opac');
		});
	});	
	
	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseout(function() {
		jQuery("img",this).addClass('img_no_opac');
		jQuery("img",this).removeClass('img_opac');
		});
	});	
	
}

function displayMenuThirdLevel() {
	
	
	
 // init: collapse all groups except for the first one
    jQuery("#block-menu-block-2 #main-menu-links #main-menu-links #main-menu-links").each(function(i)
    {
        
		jQuery(this).hide();
       
    });

	
	jQuery('#block-menu-block-2 #main-menu-links #main-menu-links .expanded').each(function () {
    jQuery(this).css("cursor","pointer");
    jQuery(this).click(function () {
      jQuery("ul",this).slideToggle();
		if ( jQuery(this).hasClass("expand")) {
			jQuery(this).removeClass("expand").addClass("is-expanded");
		} else if (jQuery(this).hasClass("is-expanded")) {
			jQuery(this).removeClass("is-expanded").addClass("expand");
		}
	  });
	});
	
	
	jQuery(document).ready(function () {
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .active #main-menu-links" ).show();
		//When the children is active, show the ul
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active" ).parent( "#main-menu-links" ).show();
		
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active" ).parent( "#main-menu-links" ).parent( ".is-active-trail").removeClass('is-expanded');
	  
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active" ).parent( "#main-menu-links" ).parent( ".is-active-trail").addClass('expand');
		
		
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .active #main-menu-links" ).show();
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active").removeClass('is-expanded');
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active").addClass('expand');
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links #main-menu-links .is-active").removeClass('expand');
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links #main-menu-links li a").removeClass('expand');
		
		
		jQuery("#block-menu-block-2 #main-menu-links #main-menu-links .active").each(function() {
			var html=jQuery("#block-menu-block-2 #main-menu-links #main-menu-links .active").html();
			if(html.indexOf("ul")==-1) {
				jQuery(this).removeClass('expand');
			}
		});
		

		
	});
	
}
        
	function zoomSmall() {
		jQuery("body").addClass("bodysmall");
		jQuery("body").removeClass("bodymedium");
		jQuery("body").removeClass("bodybig");
	}
	
	function zoomMedium() {
		jQuery("body").addClass("bodymedium");
		jQuery("body").removeClass("bodysmall");
		jQuery("body").removeClass("bodybig");
	}
	function zoomBig() {
		jQuery("body").addClass("bodybig");
		jQuery("body").removeClass("bodysmall");
		jQuery("body").removeClass("bodymedium");
	}
	
	
// Tools & Publications filters
jQuery(document).ready(function() {
	// Toggle event for facetapi filters blocks.
    jQuery(".block-facetapi .item-list").has('ul, select').each(function() {
		// If no active filters, hide the filtering on init.
		if (jQuery(this).find('a.facetapi-active, option[value]:selected, input:checked').length == 0) {
			jQuery(this).hide();
		}
		else {
			jQuery(this).closest('.block-facetapi').find('h2.block-title').addClass('expand');
		}
	}).closest('.block-facetapi').find('h2.block-title').click(function() {
		jQuery(this).closest('.block-facetapi').find("div.item-list").slideToggle();
		jQuery(this).toggleClass("expand");
    });

    // Toggle event for facetapi filters blocks.
    jQuery(".publications-sidebar-first .form-checkboxes, .dangerous-substances-sidebar-first .form-checkboxes").each(function() {
        // If no active filters, hide the filtering on init.
        if (jQuery(this).find('[type=checkbox]:checked').length == 0) {
            jQuery(this).hide();
        }
        else {
            jQuery(this).closest('.form-type-checkboxes').children('label').addClass('expand');
            jQuery(this).closest('.block').find('h2.block-title').addClass('expand');
        }
    }).closest('.form-type-checkboxes').children('label').click(function() {
        jQuery(this).closest('.form-type-checkboxes').find("div.form-checkboxes").slideToggle();
        jQuery(this).toggleClass("expand");
    });

    jQuery("#osha-search-language-input-form").hide();
    // jQuery(".block-facetapi .item-list").hide();
    // jQuery(".block-facetapi h2").removeClass("expand");
    jQuery("#block-osha-search-osha-search-language h2").click(function(){
    	jQuery(this).toggleClass("expand");
    	jQuery("#osha-search-language-input-form").slideToggle();
    });

});

function showSearcher() {
	jQuery(".mean-container #block-lang-dropdown-language-content").css("display","block");
	jQuery(".mean-container #block-search-form").css("display","block");
	jQuery(".mean-container #languagesAndSearch").css("display","block");
}
function hideSearcher() {	
	jQuery(".mean-container #block-lang-dropdown-language-content").css("display","none");
	jQuery(".mean-container #block-search-form").css("display","none");
	jQuery(".mean-container #languagesAndSearch").css("display","none");
}


/* Add image to External links - _target=blank */

jQuery(document).ready(function() {
    jQuery('#content a[target="_blank"]').not('.forward-newsletter-link').append('<span class="osha_target_external_link">&nbsp;</span>');
});


jQuery(document).ready(function() {
	// Toggle event for facetapi filters blocks.
    jQuery(".region-sidebar-first .view-fop-flags").has('ul, select').each(function() {
		// If no active filters, hide the filtering on init.
		if (jQuery(this).find('.fop-country-list').length == 0) {
			jQuery(this).hide();
		}
		else {
			jQuery(this).closest('.region-sidebar-first').find('h3').addClass('expand');
		}
	}).closest('.region-sidebar-first').find('h3').click(function() {
		jQuery(this).closest('.item-list').find(".fop-country-list").slideToggle();
		jQuery(this).toggleClass("expand");
    });
});


//Flickr Gallery - Scale and Crop images

jQuery(document).ready(function() {

if (jQuery(".node-type-flickr-gallery")[0]){
	
  // assign HTMLCollection with parents of images with objectFit to variable
  var container = document.getElementsByClassName('flickr-img-wrap');
  
  jQuery(".flickr-photoset .flickr-img-wrap").addClass("fix-ie-a");
  // Loop through HTMLCollection
  for(var i = 0; i < container.length; i++) {
    
    // Asign image source to variable
    var imageSource = container[i].querySelector('img').src;

    // Hide image
    container[i].querySelector('img').style.display = 'none';
    
    // Add background-size: cover
    container[i].style.backgroundSize = 'contain';
    
    // Add background-image: and put image source here
    container[i].style.backgroundImage = 'url(' + imageSource + ')';

    // Add background-image: and put image source here
    container[i].style.backgroundRepeat = 'no-repeat';

    // Add background-position: center center
    container[i].style.backgroundPosition = 'center center';
  }
}

});


/*JS que no hace falta en Drupal*/

jQuery(document).ready(function() {
	jQuery( ".accordion-view" ).click(function() {
		jQuery( '#block-views-our-story-block-look-back .item-list-look-back ul li' ).toggleClass("active");
		jQuery( '.accordion-view.less' ).toggleClass("active");
		jQuery( '.accordion-view.more' ).toggleClass("no-active");
	});

	jQuery('.cut-paste').appendTo('.node-25th-anniversary');

	if (jQuery(window).width() < 1006) {
		jQuery('body').addClass('mean-container');
		jQuery('#block-menu-block-1').css('display','none');
		jQuery('.breadcrumb-fluid').css('display','none');
	}
	else {
		jQuery('body').removeClass('mean-container');
		jQuery('#block-menu-block-1').css('display','block');
		jQuery('.breadcrumb-fluid').css('display','block');
	}
	
	jQuery( "body > div.mean-bar > a" ).click(function() {
		jQuery( 'body > div.mean-bar > nav > div > ul' ).toggleClass( "active" );
	});
});
