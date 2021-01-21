<?php
header ('Content-type: text/html; charset=utf-8');
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
          <div class="content-tooltip">
			<img src="/sites/all/themes/osha_frontend/images/info-thesaurus.png" alt="Info">
			<span class="thesaurus-tooltip"><?php print t("Download your complete EU-OSHA thesaurus terms in Excel format. Choose the language from the box"); ?><span class="close-thes-tooltip">x</span></span>
		  </div>
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
  
	

    <?php
      $block = block_load('views','f8943d024f1b482909a322eb70d8f514');
      print drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
    ?>
    <div id="tabs">
      <?php
        print l(t('Search'), 'tools-and-resources/eu-osha-thesaurus');
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
	<?php include(drupal_get_path('theme', 'osha_frontend').'/templates/thesaurus-alphabetical-tpl/'. $language->language .'-alphabetical.php'); ?>
	</div>
</div>
</div>


<!--</div>-->
<script>
var lang = "<?php echo $lang  ?>";
//document.getElementById("content_"+ lang).style.display = "block";

	
var url = window.location.href; 
var parts = url.split("/");
var last_part = parts[parts.length-1];
if (last_part == ""){
	last_part = parts[parts.length-2];
}

last_part=decodeURIComponent(last_part);
if (last_part != "alphabetical"){
	var letter = lang + "_letter_" + last_part;
	var term = lang+"_term_"+last_part; 	

	if(document.getElementById(term)){
	    tablinks = document.getElementsByClassName("glossary-letter");
		x = document.getElementsByClassName("content-term");
		for (i = 0; i < x.length; i++) {
			x[i].style.display = "none";
		}	
		for (i = 0; i < x.length; i++) {
			if (tablinks[i]  != 'undefined' && tablinks[i] != null){
				tablinks[i].className = tablinks[i].className.replace(" active", "");
			}
		}
		var element = document.getElementById(letter);			
			element.classList.add("active");
			document.getElementById(term).style.display = "block";   
		}else{ //if the letter does not exist we go to main
			window.location.replace("/" +lang + "/tools-and-resources/eu-osha-thesaurus/alphabetical");
   }
}
	
</script>

