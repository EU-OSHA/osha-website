<?php
?>

<div id="share-popup-container">
  <div class="close-share-popup-container">
    <button class="close-share-popup"><span>x</span></button>
  </div>
  <div class="share-popup-title">
    <h3><?php print t('Share'); ?></h3>
    <h4><?php print drupal_get_title(); ?></h4>
  </div>
  <div class="share-widget-container">
    <?php print $widget; ?>
  </div>

  <script>
    (function($) {
      $(window).ready(function(){
        $('#share-popup-container button').click(function(e) {
          $( "#share-popup-container" ).remove();
        });
      });
    })(jQuery);
  </script>
</div>