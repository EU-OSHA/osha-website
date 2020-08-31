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

    <div class="intro-text-content">
      <div class="intro-text-thesaurus">
        <?php
          $block = block_load('block','3');
          print drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
        ?>
      </div>
      <div class="download-content-theasaurus">
        <label><?php print t('Download'); ?></label>
        <img src="/sites/all/themes/osha_frontend/images/info-thesaurus.png" alt="Info" 
        title="<?php print t('Download your complete EU-OSHA thesaurus terms in Excel format. Choose the language from the box'); ?>" >
        <select id="language-export-select" class="form-select">
          <option value="bg">Български</option>
          <option value="cs">Čeština</option>
          <option value="da">Dansk</option>
          <option value="de">Deutsch</option>
          <option value="et">Eesti</option>
          <option value="el">Ελληνικά</option>
          <option value="en" selected="selected">English</option>
          <option value="es">Español</option>
          <option value="fr">Français</option>
          <option value="hr">Hrvatski</option>
          <option value="is">Íslenska</option>
          <option value="it">Italiano</option>
          <option value="lv">Latviešu</option>
          <option value="lt">Lietuvių</option>
          <option value="hu">Magyar</option>
          <option value="mt">Malti</option>
          <option value="nl">Nederlands</option>
          <option value="no">Norsk</option>
          <option value="pl">Polski</option>
          <option value="pt">Português</option>
          <option value="ro">Română</option>
          <option value="sk">Slovenčina</option>
          <option value="sl">Slovenščina</option>
          <option value="fi">Suomi</option>
          <option value="sv">Svenska</option>
        </select>
        <a id="language-export-button" href="/en/tools-and-resources/eu-osha-thesaurus/export"><img class="download" src="/sites/all/themes/osha_frontend/images/download-thesaurus.png" alt="<?php print t('Download'); ?>" title="<?php print t('Download'); ?>"></a>
      </div>
    </div>

    <div id="tabs">
      <a href="/tools-and-resources/eu-osha-thesaurus/search"><?php print t("Search"); ?></a>
      <a class="active" href="/tools-and-resources/eu-osha-thesaurus/alphabetical"><?php print t("Alphabetical view"); ?></a>
      <a href="/tools-and-resources/eu-osha-thesaurus/hierarchical"><?php print t("Hierarchical View"); ?></a>
    </div>

    <div class="view-content">
      <?php
      $thesaurus_list = views_get_view_result('thesaurus_front', 'thesaurus_alphabetical');
      $alphas = t('A B C D E F G H I J K L M N O P Q R S T U V W X Y Z');
      $alphas = explode(' ', $alphas);
      $letters = [];
      $letter_num = [];
      foreach ($thesaurus_list as $term) {
        $term_title = $term->field_title_field[0]['rendered']['#markup'];
        $letter = drupal_substr($term_title, 0, 1);
        $letters[$letter] = $letter;
        @$letter_num[$letter]++;
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
        if (in_array(strtoupper($letter), $alphas)) {
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
          foreach ($thesaurus_list as $term) {
            $dd_class = '';
            $term_path = "/node/".$term->nid;
            $term_title = $term->field_title_field[0]['rendered']['#markup'];
            $term_desc = $term->field_field_definition[0]['rendered']['#markup'];
            $term_synonyms = [];
            foreach($term->field_field_synonyms as $synonym)
            {
              if (strlen($synonym["rendered"]["#markup"]) > 0 && $synonym["rendered"]["#markup"] != "")
              {
                array_push($term_synonyms, $synonym["rendered"]["#markup"]);
              }
            }
            $term_synonyms = implode(", ", $term_synonyms);
            $letter = strtoupper(drupal_substr($term_title, 0, 1));
            if ($letter_num[$letter] == 1) {
              $dd_class = ' one-term';
            }
            if ($prev_letter != $letter) { ?>
              <div class="glossary_letter" id="glossary-<?php print $letter; ?>">
                <?php print $letter; ?><hr/>
              </div>
              <?php
            }
            ?>
            <dt class="term-title">
              <a href="<?php print $term_path ?>"><?php print $term_title; ?></a>
            </dt>
            <dd class="term-description<?php echo $dd_class;?>">
              <?php if (strlen($term_synonyms) > 0) { ?>
                <label><?php print t("Synonyms"); ?>:</label>
                <span><?php print $term_synonyms?></span>
              <?php } ?>
              <?php print $term_desc; ?>
              <div class="views-field views-field-view-node">
                <a href="<?php print $term_path ?>"><?php print t("See more"); ?></a>
              </div>
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
