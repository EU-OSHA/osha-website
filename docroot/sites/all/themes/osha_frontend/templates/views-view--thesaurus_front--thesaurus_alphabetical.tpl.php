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
global $language;
$lang = $language->language;
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
          $block = block_load('osha_thesaurus','osha_thesaurus_test_block');
          print drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
        ?>
      </div>
      <div class="download-content-theasaurus">
        <div class="download-content-theasaurus-label">
          <label><?php print t('Download'); ?></label>
          <img src="/sites/all/themes/osha_frontend/images/info-thesaurus.png" alt="Info" 
          title="<?php print t('Download your complete EU-OSHA thesaurus terms in Excel format. Choose the language from the box'); ?>" >
        </div>
        <div class="download-content-theasaurus-action">
          <select id="language-export-select" class="form-select">
            <option value="bg" <?php if($lang=="bg"): print 'selected="selected"'; endif;?>>Български</option>
            <option value="cs" <?php if($lang=="cs"): print 'selected="selected"'; endif;?>>Čeština</option>
            <option value="da" <?php if($lang=="da"): print 'selected="selected"'; endif;?>>Dansk</option>
            <option value="de" <?php if($lang=="de"): print 'selected="selected"'; endif;?>>Deutsch</option>
            <option value="et" <?php if($lang=="et"): print 'selected="selected"'; endif;?>>Eesti</option>
            <option value="el" <?php if($lang=="el"): print 'selected="selected"'; endif;?>>Ελληνικά</option>
            <option value="en" <?php if($lang=="en"): print 'selected="selected"'; endif;?>>English</option>
            <option value="es" <?php if($lang=="es"): print 'selected="selected"'; endif;?>>Español</option>
            <option value="fr" <?php if($lang=="fr"): print 'selected="selected"'; endif;?>>Français</option>
            <option value="hr" <?php if($lang=="hr"): print 'selected="selected"'; endif;?>>Hrvatski</option>
            <option value="is" <?php if($lang=="is"): print 'selected="selected"'; endif;?>>Íslenska</option>
            <option value="it" <?php if($lang=="it"): print 'selected="selected"'; endif;?>>Italiano</option>
            <option value="lv" <?php if($lang=="lv"): print 'selected="selected"'; endif;?>>Latviešu</option>
            <option value="lt" <?php if($lang=="lt"): print 'selected="selected"'; endif;?>>Lietuvių</option>
            <option value="hu" <?php if($lang=="hu"): print 'selected="selected"'; endif;?>>Magyar</option>
            <option value="mt" <?php if($lang=="mt"): print 'selected="selected"'; endif;?>>Malti</option>
            <option value="nl" <?php if($lang=="nl"): print 'selected="selected"'; endif;?>>Nederlands</option>
            <option value="no" <?php if($lang=="no"): print 'selected="selected"'; endif;?>>Norsk</option>
            <option value="pl" <?php if($lang=="pl"): print 'selected="selected"'; endif;?>>Polski</option>
            <option value="pt" <?php if($lang=="pt"): print 'selected="selected"'; endif;?>>Português</option>
            <option value="ro" <?php if($lang=="ro"): print 'selected="selected"'; endif;?>>Română</option>
            <option value="sk" <?php if($lang=="sk"): print 'selected="selected"'; endif;?>>Slovenčina</option>
            <option value="sl" <?php if($lang=="sl"): print 'selected="selected"'; endif;?>>Slovenščina</option>
            <option value="fi" <?php if($lang=="fi"): print 'selected="selected"'; endif;?>>Suomi</option>
            <option value="sv" <?php if($lang=="sv"): print 'selected="selected"'; endif;?>>Svenska</option>
          </select>
          <a id="language-export-button" href="/en/tools-and-resources/eu-osha-thesaurus/export"><img class="download" src="/sites/all/themes/osha_frontend/images/download-thesaurus.png" alt="<?php print t('Download'); ?>" title="<?php print t('Download'); ?>"></a>
        </div>
      </div>
    </div>

    <div id="tabs">
      <?php
        print l(t('Search'), 'tools-and-resources/eu-osha-thesaurus/search');
        print l(t('Alphabetical view'), 'tools-and-resources/eu-osha-thesaurus/alphabetical');
        print l(t('Hierarchical view'), 'tools-and-resources/eu-osha-thesaurus/hierarchical');
      ?>
    </div>

    <div class="view-content">
      <?php
      $path = current_path();
      // The selected letter is the one on the end pf the URL
      $path = explode("/",$path);
      if (end($path) != "alphabetical")
      {
        $selectedLetter = mb_strtoupper(end($path));
      }
      $thesaurus_list = views_get_view_result('thesaurus_front', 'thesaurus_alphabetical');
      $alphas = t('A B C D E F G H I J K L M N O P Q R S T U V W X Y Z');
      $alphas = explode(' ', $alphas);
      $letters = [];
      $letter_num = [];
      foreach ($thesaurus_list as $term) {
        $term_title = $term->field_title_field[0]['rendered']['#markup'];
        $letter = drupal_substr($term_title, 0, 1);
        $letter = mb_strtoupper($letter);
        $letters[$letter] = $letter;
        @$letter_num[$letter]++;
      }
      ksort($letters);
      // Check if the selected letter is one of the letters for the current language
      if (!in_array($selectedLetter, $alphas) && !in_array($selectedLetter, $letters))
      {
        unset($selectedLetter);
      }
      echo '<div id="glossary-letters"><div class="container">';
      foreach ($alphas as $letter) {
        if (!empty($letters[$letter])) {
          if ($selectedLetter == null)
          {
            $selectedLetter = mb_strtoupper($letter);
          }
          print '<span><a href="/'.$lang.'/tools-and-resources/eu-osha-thesaurus/alphabetical/' . mb_strtolower($letter) . '">' . $letter . '</a></span>';
        }
        else {
          print '<span>' . $letter . '</span>';
        }
      }
      foreach ($letters as $letter) {
        if (in_array(mb_strtoupper($letter), $alphas)) {
          continue;
        }
        if ($selectedLetter == null)
        {
          $selectedLetter = mb_strtoupper($letter);
        }
        print '<span><a href="/'.$lang.'/tools-and-resources/eu-osha-thesaurus/alphabetical/' . mb_strtolower($letter) . '">' . $letter . '</a></span>';
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
            $titleFirstLetter = mb_strtoupper(drupal_substr($term_title, 0, 1));

            if ($titleFirstLetter != $selectedLetter)
            {
              continue;
            }
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
