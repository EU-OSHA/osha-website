<?php?>
<script>

  jQuery(document).ready(function ($) {
    var options = {
      $AutoPlay: false,
      $AutoPlaySteps: 1,
      $SlideDuration: 160,
      $SlideWidth: 800,
      $SlideSpacing: 1,
      $DisplayPieces: 1,
      $HWA: false,
      $BulletNavigatorOptions: {
        $Class: $JssorBulletNavigator$,
        $ChanceToShow: 1,
        $AutoCenter: 1
      },

      $ArrowNavigatorOptions: {
        $Class: $JssorArrowNavigator$,
        $ChanceToShow: 1,
        $AutoCenter: 2,
        $Steps: 1
      }
    };
    var jssor_slider1 = new $JssorSlider$("publication_slideshow", options);
  });
</script>
<?php
$intNumberOfItems = substr_count($rows ,'<article');
?>

<div id="publication_slideshow">
  <div id="num_slides" u="slides">
    <?php print $rows ?>
  </div>
  <?php if ($intNumberOfItems > 1): ?>
    <div u="navigator" class="jssorb03" style="position: absolute; bottom: 4px; right: 6px;">
      <div u="prototype" style="width: 21px; height: 21px; line-height:21px; color:white; font-size:12px;"></div>
    </div>
    <span u="arrowleft" class="jssora03l publications" style="width: 55px; height: 55px; top: 115px; left: 8px;"></span>
    <span u="arrowright" class="jssora03r publications" style="width: 55px; height: 55px; top: 115px; right: 8px"></span>
  <?php endif; ?>
</div>
