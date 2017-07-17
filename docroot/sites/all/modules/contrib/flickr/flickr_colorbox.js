(function ($) {
  Drupal.behaviors.addLinkToColorboxCurrent = {
    attach: function(context, settings) {
      var url = $("img[class='cboxPhoto']").attr('src');
      var regex = new RegExp(/^https?:\/\/([a-z0-9-]+\.)*flickr\.com(\/.*)?$/);
      if (url && url.match(regex)) {
        var photo_id = url.split('/')[4];
        var link = /^[^_]*/.exec(photo_id);
        var linktext = Drupal.t('View on Flickr.');
        var linktitle = Drupal.t('Opens in a new tab.');
        $('#cboxCurrent').append(' <a href="https://flickr.com/photo.gne?id='+link+'" target="_blank" title="'+linktitle+'">'+linktext+'</a>');
      }
    }
  };
})(jQuery);
