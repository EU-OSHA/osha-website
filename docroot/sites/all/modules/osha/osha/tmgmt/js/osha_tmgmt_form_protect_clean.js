(function($) {
  Drupal.behaviors.osha_tmgmt_form_protect = {
    attach : function(context) {
      localStorage.removeItem('osha_tmgmt_form_protect');
    }
  };
})(jQuery);
