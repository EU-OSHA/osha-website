<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any.
 *
 * @ingroup views_templates
 */
?>
<div class="container-fluid">
  <div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="view-content">
      <?php
      $glossary_list = views_get_view_result('msds_glossary', 'page');
      $alphas = t('A B C D E F G H I J K L M N O P Q R S T U V W X Y Z');
      $alphas = explode(' ', $alphas);
      $letters = [];
      foreach ($glossary_list as $term) {
        $term_title = $term->field_name_field[0]['rendered']['#markup'];
        $letter = drupal_substr($term_title, 0, 1);
        $letters[$letter] = $letter;
      }
      ksort($letters);
      echo '<div id="glossary-letters"><div class="container">';
      foreach ($alphas as $letter) {
        if (!empty($letters[$letter])) {
          print '<span><a href="#glossary-' . $letter . '">' . $letter . '</a></span>';
        }
        else {
          print '<span>' . $letter . '</span>';
        }
      }
      foreach ($letters as $letter) {
        if (in_array($letter, $alphas)) {
          continue;
        }
        print '<span><a href="#glossary-' . $letter . '">' . $letter . '</a></span>';
      }
      echo '</div></div>';
      $prev_letter = '';
      ?>
      <div class="content-term">
        <dl>
          <?php
          foreach ($glossary_list as $term) {
            $term_title = $term->field_name_field[0]['rendered']['#markup'];
            $term_desc = $term->field_description_field[0]['rendered']['#markup'];
            $letter = drupal_substr($term_title, 0, 1);
            if ($prev_letter != $letter) { ?>
              <div class="glossary_letter" id="glossary-<?php print $letter; ?>">
                <?php print $letter; ?><hr/>
              </div>
              <?php
            }
            ?>
            <dt class="term-title">
              <?php print $term_title; ?>
            </dt>
            <dd class="term-description">
              <?php print $term_desc; ?>
            </dd>
            <?php
            $prev_letter = $letter;
          }
          ?>
        </dl>
      </div>
    </div>

  </div><?php /* class view */ ?>
</div>
