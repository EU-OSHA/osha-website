<?php

/**
 * @file
 * This is a template file for the cookie consent withdraw button.
 *
 * When overriding this template it is important to note that jQuery will use
 * the following classes to assign actions to the button:
 *
 * eu-cookie-withdraw-button - withdraw button
 * eu-cookie-withdraw-tab - tab that reveals the withdraw interface
 *
 * Variables available:
 * - $message: Contains the text that will be displayed within the banner.
 * - $withdraw_tab_button_label: Label for the tab that sits at the window edge.
 * - $withdraw_action_button_label: Label for the withdraw button.
 */
?>
<button type="button" class="eu-cookie-withdraw-tab"><?php print $withdraw_tab_button_label; ?></button>
<div class="eu-cookie-withdraw-banner">
  <div class="popup-content info">
    <div id="popup-text">
      <?php print $message; ?>
    </div>
    <div id="popup-buttons">
      <button type="button" class="eu-cookie-withdraw-button"><?php print $withdraw_action_button_label; ?></button>
    </div>
  </div>
</div>
