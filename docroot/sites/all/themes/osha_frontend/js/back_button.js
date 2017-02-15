(function($){
    Drupal.behaviors.osha_back_button = {
        attach: function(context, settings) {
            $(".view-header.back a").once('osha_back_button', function(){
                var $this = $(this);
                var url = window.location.origin + $this.attr('href');
                // if user is coming from the listing, make history back
                // to keep the potential query parameters.
                if (document.referrer.indexOf(url) === 0) {
                    $this.on('click', function(e){
                        e.preventDefault();
                        history.go(-1);
                    });
                }
            });
        }
    }
})(jQuery);
