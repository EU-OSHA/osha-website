(function ($) {

  Drupal.behaviors.tooltip = {
    attach: function(context, settings) {
      for (id in Drupal.settings.tooltips) {
        let label = jQuery('#' + id + ' label');
        label.html(label.html() + Drupal.settings.tooltips[id]);
      }
      Drupal.behaviors.qtip.attach(document, Drupal.settings);
    }
  }
})(jQuery);
