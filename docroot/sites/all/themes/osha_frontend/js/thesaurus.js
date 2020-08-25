
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
