<?php

/**
 * @file
 * Template file for consent banner.
 *
 * When overriding this template it is important to note that jQuery will use
 * the following classes to assign actions to buttons:
 *
 * agree-button      - agree to setting cookies
 * find-more-button  - link to an information page
 *
 * Variables available:
 * - $message:  Contains the text that will be display within the pop-up
 * - $agree_button: Label for the primary/agree button. Note that this is the
 *   primary button. For backwards compatibility, the name remains agree_button.
 * - $disagree_button: Contains Cookie policy button title. (Note: for
 *   historical reasons, this label is called "disagree" even though it just
 *   displays the privacy policy.)
 * - $secondary_button_label: Contains the action button label. The current
 *   action depends on whether you're running the module in Opt-out or Opt-in
 *   mode.
 * - $primary_button_class: Contains class names for the primary button.
 * - $secondary_button_class: Contains class names for the secondary button
 *   (if visible).
 * - $cookie_categories: Contains a array with cookie categories that can be
 *   agreed or disagreed to separately.
 * - $save_preferences_button_label: Label text for a button to save the consent
 *   preferences.
 * - $fix_first_cookie_category: Boolean value to indicate that the first
 *   consent category cannot be unchecked.
 * - $privacy_settings_tab_label: Label text for the Privacy settings tab.
 * - $withdraw_button_on_info_popup: Show the withdraw button on this popup.
 * - $method: Chosen consent method.
 */
?>
<?php if ($privacy_settings_tab_label) : ?>
  <button type="button" class="eu-cookie-withdraw-tab"><?php print $privacy_settings_tab_label; ?></button>
<?php endif ?>
<?php $classes = array(
  'eu-cookie-compliance-banner',
  'eu-cookie-compliance-banner-info',
  'eu-cookie-compliance-banner--' . str_replace('_', '-', $method),
); ?>
<div class="<?php print implode(' ', $classes); ?>">
  <div class="popup-content info">
    <div id="popup-text">
      <?php print $message ?>
      <?php if ($disagree_button) : ?>
        <button type="button" class="find-more-button eu-cookie-compliance-more-button"><?php print $disagree_button; ?></button>
      <?php endif; ?>
    </div>
    <?php if ($cookie_categories) : ?>
      <div id="eu-cookie-compliance-categories" class="eu-cookie-compliance-categories">
        <?php
          $first_loop = TRUE;
          foreach ($cookie_categories as $key => $category) {
        ?>
          <div class="eu-cookie-compliance-category">
            <div>
              <input type="checkbox" name="cookie-categories" id="cookie-category-<?php print $key; ?>"
                     value="<?php print $key; ?>" <?php if ($fix_first_cookie_category && $first_loop) : ?>checked disabled<?php endif; ?>>
              <label for="cookie-category-<?php print $key; ?>"><?php print $category['label']; ?></label>
            </div>
          <?php if (isset($category['description'])) : ?>
            <div class="eu-cookie-compliance-category-description"><?php print $category['description'] ?></div>
          <?php endif; ?>
        </div>
        <?php
          $first_loop = FALSE;
          } //end for ?>
        <?php if ($save_preferences_button_label) : ?>
          <div class="eu-cookie-compliance-categories-buttons">
            <button type="button"
                    class="eu-cookie-compliance-save-preferences-button"><?php print $save_preferences_button_label; ?></button>
          </div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <div id="popup-buttons" class="<?php if ($cookie_categories) : ?>eu-cookie-compliance-has-categories<?php endif; ?>">
      <button type="button" class="<?php print $primary_button_class; ?>"><?php print $agree_button; ?></button>
      <?php if ($secondary_button_label) : ?>
        <button type="button" class="<?php print $secondary_button_class; ?>" ><?php print $secondary_button_label; ?></button>
      <?php endif; ?>
    </div>
  </div>
</div>
