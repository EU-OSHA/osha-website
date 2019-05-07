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
      $('#edit-email--2').once('osha_newsletter_captcha_block', function() {
        var ajax_settings = {};
        ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'newsletter/ajax/block/footer';
        ajax_settings.event = 'click';
        var base = '#edit-email--2';
        Drupal.ajax['captcha-block-2'] = new Drupal.ajax(base, this, ajax_settings);
      });
    }
  };
})(jQuery);
(function($) {
  $.fn.captcha_init = function() {
    captcha.init();
  };
})(jQuery);
