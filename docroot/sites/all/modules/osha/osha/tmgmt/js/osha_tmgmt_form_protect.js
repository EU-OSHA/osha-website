(function($) {
  Drupal.behaviors.osha_tmgmt_form_protect = {
    attach : function(context) {
      $("ul.tabs.primary li a, input[type='submit']").each(function() {
        $(this).click(function() {
          var msg = $("#edit-action-message");
          if (msg && msg.val().length != 0) {
            localStorage.setItem('osha_tmgmt_form_protect', msg.val());
          }
          return true;
        });
      });

      // check local storage on refresh
      var input = $("#edit-action-message");
      var msg = localStorage.getItem('osha_tmgmt_form_protect');
      if (input && input.val().length == 0 && msg && msg.length != 0) {
        // restore value from local storage if none provided
        $("#edit-action-message").val(msg);
      }
    }
  };
})(jQuery);
