(function($){
  Drupal.behaviors.osha_newsletter_captcha_block = {
    attach: function (context, settings) {
      $('#edit-email').once('osha_newsletter_captcha_block', function () {
        var ajax_settings = {};
        ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'newsletter/ajax/block';
        if (!jQuery('body').hasClass('front') && !$('#block-osha-newsletter-osha-newsletter-subscribe').length) {
          ajax_settings.url = ajax_settings.url + '/footer';
        }
        ajax_settings.event = 'click';
        var base = '#edit-email';
        Drupal.ajax['captcha-block'] = new Drupal.ajax(base, this, ajax_settings);
      });
      var agree = '';
      var email = '';
      if (typeof Drupal.settings.osha_newsletter != 'undefined') {
        if (typeof Drupal.settings.osha_newsletter.agree != 'undefined') {
          agree = Drupal.settings.osha_newsletter.agree;
        }
        if (typeof Drupal.settings.osha_newsletter.email != 'undefined') {
          email = Drupal.settings.osha_newsletter.email;
        }
      }
      if (email) {
        jQuery('div.form-item-email input.form-text').val(Drupal.checkPlain(email));
      }
      if (agree && agree != '0') {
        jQuery(".form-item-agree-processing-personal-data input.form-checkbox").prop('checked', true);
      }
      $('#edit-email--2').once('osha_newsletter_captcha_block', function () {
        var ajax_settings = {};
        ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'newsletter/ajax/block/footer';
        ajax_settings.event = 'click';
        var base = '#edit-email--2';
        Drupal.ajax['captcha-block-2'] = new Drupal.ajax(base, this, ajax_settings);
      });
    }
  };
})(jQuery);
var captcha_ready = false;
(function($) {
  $.fn.captcha_init = function() {
    if (!captcha_ready) {
      // Left newsletter captcha form.
      var captcha_checkbox_id = '#edit-agree-processing-personal-data--3';
      var captcha_submit_id = '#osha-newsletter-block-subscribe-captcha-form #edit-submit--3';

      if (agree_processing(captcha_checkbox_id)) {
        jQuery(captcha_submit_id).prop('disabled', false).removeAttr('disabled');
      }
      jQuery(captcha_checkbox_id).click(function () {
        toggleNewsletterSubmit(captcha_checkbox_id, captcha_submit_id);
      });
    }
    captcha_ready = true;
  };
})(jQuery, captcha_ready);
