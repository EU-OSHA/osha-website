
// Hierarchical view tree, js animation for the tree.
(function( $ ){
    $(document).ready(function() {
        $('.view-display-id-thesaurus_hierarchical > div.view-content > div > ul').attr('id', 'tree');
        $('#tree li a').before("<span class='expand_menu'>&nbsp;</span>");
        $('#tree ul').hide();
        $('.expand_menu').click(function() {
            $(this).toggleClass('expanded');
            $(this).parent().find(' > .item-list > ul').slideToggle();
        });

        //Add class to li when have childs
        $('#tree li:has(.item-list)').addClass('has-child');

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
            // Open the accordion for the children elements
            $("span.thesaurus-term-"+term).parent().siblings("div.item-list").find("span.expand_menu").click();
            // Open the accordion for the parent elements
            var elem = $("span.thesaurus-term-"+term).closest("div.item-list");
            while(elem.length > 0)
            {
              elem.siblings("span.expand_menu").click();
              elem = elem.parent().closest("div.item-list");
            }
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
        var href = "/" + language + "/tools-and-resources/eu-osha-thesaurus/export";
        $("a#language-export-button").attr("href",href);
      });
    });
})( jQuery );