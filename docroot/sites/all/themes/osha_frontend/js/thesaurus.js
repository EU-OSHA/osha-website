
// Hierarchical view tree, js animation for the tree.
(function( $ ){
    $(document).ready(function() {
        $('.view-display-id-thesaurus_hierarchical > div.view-content > div > ul').attr('id', 'tree');
        $('#tree li a').before("<span class='expand_menu'>&nbsp;</span>");
        $('#tree li a').attr('title', Drupal.t("See more"));
        $('#tree ul').hide();
        $('.expand_menu').click(function() {
            $(this).toggleClass('expanded');
            $(this).parent().find(' > .item-list > ul').slideToggle();
        });

        //Add class to li when have childs
        $('#tree li:has(.item-list)').addClass('has-child');
        $('#tree li.has-child > span.expand_menu').attr("title", Drupal.t("Expand / Collapse tree"));

        // Expand tree for current element if it comes on the URL
        if (window.location.pathname.indexOf("/tools-and-resources/eu-osha-thesaurus/hierarchical") > -1)
        {
          if (window.location.search.length > 0 && window.location.search.indexOf("term") > -1)
          {
            var term = window.location.search;
            term = term.substring(term.indexOf("term=")+5);
            if (term.indexOf("&") > -1)
            {
              term = term.substring(0, term.indexOf("&"));  
            }
            // Open the accordion for the current term
            $("span.thesaurus-term-"+term).parent().siblings("span.expand_menu").click();
            // Add the class to highlight the term
            $("span.thesaurus-term-"+term).addClass("highlight");
            // Open the accordion for the children elements - Not required ofr now
            // $("span.thesaurus-term-"+term).parent().siblings("div.item-list").find("span.expand_menu").click();
            // Open the accordion for the parent elements
            var elem = $("span.thesaurus-term-"+term).closest("div.item-list");
            while(elem.length > 0)
            {
              elem.siblings("span.expand_menu").click();
              elem = elem.parent().closest("div.item-list");
            }
          }
        }

        // Remove the duplicated element in the breadcrumb
        var breadcrumb = $("div.breadcrumb span.inline");
        var urls = [];
        for (var i = 0; i < breadcrumb.size(); i++)
        {
          var url = $(" a", breadcrumb[i]).attr("href");
          if (urls.indexOf(url) == -1)
          {
            // The URL has not appeared yet
            urls.push(url);
          }
          else
          {
            // Duplicated element, remove the element
            breadcrumb[i].nextElementSibling.remove();
            breadcrumb[i].remove();
          }
        }
    });
})( jQuery );

//Thesaurus accordion
(function( $ ){
    $(document).ready(function() {
      $(".set > h3").on("click", function() {
        if ($(this).hasClass("active")) {
          $(this).removeClass("active");
          $(this)
            .siblings(".content")
            .slideUp(200);
          $(".set > h3 i")
            .removeClass("fa-minus")
            .addClass("fa-plus");
        } else {
          $(".set > h3 i")
            .removeClass("fa-minus")
            .addClass("fa-plus");
          $(this)
            .find("i")
            .removeClass("fa-plus")
            .addClass("fa-minus");
          $(".set > h3").removeClass("active");
          $(this).addClass("active");
          $(".content").slideUp(200);
          $(this)
            .siblings(".content")
            .slideDown(200);
        }
      });
    });
})( jQuery );

// Thesaurus Export language
(function( $ ){
    $(document).ready(function() {
      $("select#language-export-select").change(function()
      {
        var language= $(this).val();
        var href = $("a#language-export-button").attr("href");
        href = href.substring(0,href.indexOf("EU-OSHA_thesaurus_"));
        var href = href + "EU-OSHA_thesaurus_" + language + ".xls";
        $("a#language-export-button").attr("href",href);
      });
    });
})( jQuery );

// Add classes to active the left menu item
(function( $ ){
    $(document).ready(function() {
      if ($(".page-tools-and-resources-eu-osha-thesaurus ")[0]){
        $('.page-tools-and-resources-eu-osha-thesaurus #block-menu-block-2 li:last-child > a').addClass('is-active is-active-trail active-trail active');
      }
    });
})( jQuery );

// Submit the search form if the order changes
(function ( $ ){
  $(document).ready(function() {
    $("form#views-exposed-form-thesaurus-front-indexed-thesaurus-search select#edit-sort-by").change(function()
    {
      $(this).parents('form').submit();
    });
  })
})(jQuery);

// Sticky behaviour of the alphabetical menu
(function ( $ ){
  $(document).ready(function() {
    var glosaryLettersOffset= $("#glossary-letters").offset();
    var glosaryLettersWidth= $("#glossary-letters").outerWidth(true);
    if (glosaryLettersOffset != null)
    {
      var glosaryLettersTop=glosaryLettersOffset.top + 206; //206 is the padding giving in the css to the body as 12.9rem
      $(window).on("scroll", function () {
        if ($(document).scrollTop() >= glosaryLettersTop ) {
         $("#glossary-letters").css({"position":"fixed", "top":"0px", "left":glosaryLettersOffset.left, "z-index":"8888", "background-color":"#ffffff", "width": glosaryLettersWidth + "px", "margin":"0px"});
        } else if ($(document).scrollTop() < glosaryLettersTop) {
          $("#glossary-letters").css({"position":"", "top":"", "left":"", "z-index":"", "background-color":"", "width": "", "margin":""});
        }
      });
    }    
  })
})(jQuery);

// Tootip

(function ( $ ){
  $(document).ready(function() {
	$('.content-tooltip img').mouseenter(function() {
		$(".thesaurus-tooltip").fadeIn(300);
    });
	$('.close-thes-tooltip').click(function() {
		$(".thesaurus-tooltip").fadeOut(300);
    });
	
  })
})(jQuery);




