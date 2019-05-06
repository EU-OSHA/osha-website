(function($){
  Drupal.behaviors.osha_newsletter_captcha_block = {
    attach: function (context, settings) {
      $('#edit-email').once('osha_newsletter_captcha_block', function() {
        var ajax_settings = {};
        ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'newsletter/ajax/block';
        ajax_settings.event = 'click';
        var base = '#edit-email';
        Drupal.ajax['captcha-block'] = new Drupal.ajax(base, this, ajax_settings);
      });
      if (eval('typeof URLSearchParams')) {
        var searchParams = new URLSearchParams(window.location.search);
        var agree = searchParams.get('agree');
        var email = searchParams.get('email');
        if (email) {
          jQuery('div.form-item-email input.form-text').val(Drupal.checkPlain(email));
        }
        if (agree && agree != '0') {
          jQuery(".form-item-agree-processing-personal-data input.form-checkbox").prop('checked', true);
        }
      }
    }
  };
})(jQuery);

(function($) {
  $.fn.captcha_init = function() {
    captcha.init();
  };
})(jQuery);
