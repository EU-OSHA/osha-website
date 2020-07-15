<?php

/**
 * @file
 * Template file for a banner informing a user that he has agreed to cookies.
 *
 * When overriding this template it is important to note that jQuery will use
 * the following classes to assign actions to buttons:
 *
 * hide-popup-button - destroy the pop-up
 * find-more-button  - link to an information page
 *
 * Variables available:
 * - $message:  Contains the text that will be display within the pop-up
 * - $hide_button: Contains hide button title
 * - $find_more_button: Contains find more button title
 */
?>
<div>
  <div class="popup-content agreed">
    <div id="popup-text">
      <?php print $message ?>
    </div>
    <div id="popup-buttons">
      <button type="button" class="hide-popup-button eu-cookie-compliance-hide-button"><?php print $hide_button; ?></button>
      <?php if ($find_more_button) : ?>
        <button type="button" class="find-more-button eu-cookie-compliance-more-button-thank-you" ><?php print $find_more_button; ?></button>
      <?php endif; ?>
    </div>
  </div>
</div>
