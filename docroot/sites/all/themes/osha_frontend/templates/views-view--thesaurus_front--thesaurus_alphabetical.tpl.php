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
$langList = osha_language_list(TRUE);
?>
<div class="container-fluid">
  <div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <?php print t($title); ?>
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
            <?php
              $selectedLang = '';
              foreach($langList as $code => $currentLang)
              {
                if (file_exists('public://thesaurus-export/EU-OSHA_thesaurus_' . $code . '.xls'))
                {
                  if ($selectedLang == '')
                  {
                    $selectedLang = $code;
                  }
                  print '<option value="'.$code.'" ';
                  if ($code == $lang)
                  {
                    $selectedLang = $code;
                    print ' selected="selected" class="navigation-language"';
                  }
                  print '>'.$currentLang->native . '</option>';
                }
              }
              $path = "public://";
              $path = file_create_url($path);
            ?>
          </select>
          <a id="language-export-button" href="<?php print $path; ?>thesaurus-export/EU-OSHA_thesaurus_<?php print $selectedLang; ?>.xls"><img class="download" src="/sites/all/themes/osha_frontend/images/download-thesaurus.png" alt="<?php print t('Download'); ?>" title="<?php print t('Download'); ?>"></a>
        </div>
      </div>
    </div>

    <div id="tabs">
      <?php
        print l(t('Search'), 'tools-and-resources/eu-osha-thesaurus/search');
        $path = current_path();
        // The selected letter is the one on the end of the URL
        $path = explode("/",$path);
        if (end($path) != "alphabetical")
        {
          $selectedLetter = mb_strtoupper(end($path));
          // Add the class to the selected link on the tabs
          print l(t('Alphabetical view'), 'tools-and-resources/eu-osha-thesaurus/alphabetical', array('attributes' => array('class' => 'active')));
        }
        else
        {
          // No need to add the class to the link
          print l(t('Alphabetical view'), 'tools-and-resources/eu-osha-thesaurus/alphabetical');
        }        
        print l(t('Hierarchical view'), 'tools-and-resources/eu-osha-thesaurus/hierarchical');
      ?>
    </div>

    <div class="view-content">
      <?php
      $path = current_path();
      // The selected letter is the one on the end of the URL
      $path = explode("/",$path);
      if (end($path) != "alphabetical")
      {
        $selectedLetter = mb_strtoupper(end($path));
      }
      $thesaurus_list = views_get_view_result('thesaurus_front', 'thesaurus_alphabetical');
      $alphabets = array(
        "bg"=>'А Б В Г Д Е Ж З И Й К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ Ъ Ь Ю Я',
        "cs"=>'A B C Č D Ď E F G H I J K L M N Ň O P Q R Ř S Š T Ť U V W X Y Z Ž',
        "da"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Å Æ Ø',
        "de"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Ä Ö Ü ß',
        "et"=>'A B C D E F G H I J K L M N O P Q R S Š Z Ž T U V W Õ Ä Ö Ü X Y',
        "el"=>'Α Β Γ Δ Ε Ζ Η Θ Ι Κ Λ Μ Ν Ξ Ο Π Ρ Σ Τ Υ Φ Χ Ψ Ω',
        "en"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z',
        "es"=>'A B C D E F G H I J K L M N Ñ O P Q R S T U V W X Y Z',
        "fr"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z',
        "hr"=>'A B C Č Ć D Đ E F G H I J K L M N O P Q R S Š T U V W Z Ž',
        "is"=>'A Á B C D Đ E É F G H I Í J K L M N O Ó P Q R S T U Ú V W X Y Ý Þ Æ Ö',
        "it"=>'A B C D E F G H I K L M N O P Q R S T U V Z',
        "lv"=>'A Ā B C Č D E Ē F G Ģ H I Ī J K Ķ L Ļ M N Ņ O P R S Š T U Ū V Z Ž',
        "lt"=>'A Ą B C Č D E Ę Ė F G H I Į Y J K L M N O P R S Š T U Ų Ū V Z Ž',
        "hu"=>'A Á B C D E É F G H I Í J K L M N O Ó Ö Ő P Q R S T U Ú Ü Ű V W X Y Z',
        "mt"=>'A B Ċ D E F Ġ G H Ħ I J K L M N O P Q R S T U V W X Ż Z',
        "nl"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z',
        "no"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Æ Ø Å',
        "pl"=>'A Ą B C Ć D E Ę F G H I J K L Ł M N Ń O Ó P R S Ś T U V W Y Z Ź Ż',
        "pt"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z',
        "ro"=>'A Ă Â B C D E F G H I Î J K L M N O P Q R S Ș T U V W X Y Z',
        "sk"=>'A Á Ä B C Č D Ď E É F G H I Í J K L Ĺ Ľ M N Ň O Ó Ô P Q R Ŕ S Š T Ť U Ú V W X Y Ý Z Ž',
        "sl"=>'A B C Č D E F G H I J K L M N O P R S Š T U V W Z Ž',
        "fi"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Å Ä Ö',
        "sv"=>'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Å Ä Ö',
      );
      $alphas = t($alphabets[$lang]);
      $alphas = explode(' ', $alphas);
      $letters = [];
      $letter_num = [];
      foreach ($thesaurus_list as $term) {
        $term_title = $term->field_title_field[0]['rendered']['#markup'];
        if (drupal_substr($term_title, 0, 1) == "«" || drupal_substr($term_title, 0, 1) == "1")
        {
          /*dpm(preg_replace('/\W+/', '', $term_title));
          dpm(preg_replace('/[^\w]+/', '', $term_title));
          dpm(preg_replace("/&#?[a-z0-9]+;/i",'',$term_title));*/
        }
        // Remove the quotation marks from the string
        $term_title = preg_replace("/&#?[a-z0-9]+;/i",'',$term_title);
        if (drupal_substr($term_title, 0, 1) == "«" || drupal_substr($term_title, 0, 1) == "„" || drupal_substr($term_title, 0, 1) == "("
            || drupal_substr($term_title, 0, 1) == "“" || drupal_substr($term_title, 0, 1) == "[")
        {
          $term_title = preg_replace('/[^\w]+/', '', $term_title);
        }
        // Remove white space from beginning and end of the string
        $term_title = trim($term_title);
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
        if ($lang == "cs" || $lang == "es" || $lang == "et" || $lang == "fr" || $lang == "pt" || $lang == "ro")
        {
          if (mb_strtoupper($letter) == "Á" || mb_strtoupper($letter) == "Â" || mb_strtoupper($letter) == "É" || mb_strtoupper($letter) == "Ó" ||
          mb_strtoupper($letter) == "Ş" || mb_strtoupper($letter) == "Ś" || mb_strtoupper($letter) == "Ţ" || mb_strtoupper($letter) == "Ú")
          {
            continue;
          }
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
            $term_path = "/".$lang."/tools-and-resources/eu-osha-thesaurus/term/". $term->field_field_term_id['0']['raw']['value'];
            $term_title = $term->field_title_field[0]['rendered']['#markup'];
            $titleFirstLetter = trim(preg_replace("/&#?[a-z0-9]+;/i",'',$term_title));
            if (drupal_substr($titleFirstLetter, 0, 1) == "«" || drupal_substr($titleFirstLetter, 0, 1) == "„" || drupal_substr($titleFirstLetter, 0, 1) == "("
            || drupal_substr($titleFirstLetter, 0, 1) == "“" || drupal_substr($titleFirstLetter, 0, 1) == "[")
            {
              $titleFirstLetter = preg_replace('/[^\w]+/', '', $titleFirstLetter);
            }
            $titleFirstLetter = mb_strtoupper(drupal_substr($titleFirstLetter, 0, 1));

            if (($lang == "es" || $lang == "pt") && $titleFirstLetter == "Á")
            {
              $titleFirstLetter = "A";
            }
            else if ($lang == "fr" && $titleFirstLetter == "Â")
            {
              $titleFirstLetter = "A";
            }
            else if (($lang == "cs" || $lang == "es" || $lang=="fr" || $lang == "pt") && $titleFirstLetter == "É")
            {
              $titleFirstLetter = "E";
            }
            else if (($lang == "es" || $lang == "pt") && $titleFirstLetter == "Ó")
            {
              $titleFirstLetter = "O";
            }
            else if ($lang == "et" && $titleFirstLetter == "Ś")
            {
              $titleFirstLetter = "S";
            }
            else if ($lang == "ro" && $titleFirstLetter == "Ş")
            {
              $titleFirstLetter = "Ș";
            }
            else if ($lang == "ro" && $titleFirstLetter == "Ţ")
            {
              $titleFirstLetter = "T";
            }
            else if (($lang == "cs" || $lang == "es") && $titleFirstLetter == "Ú")
            {
              $titleFirstLetter = "U";
            }

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
