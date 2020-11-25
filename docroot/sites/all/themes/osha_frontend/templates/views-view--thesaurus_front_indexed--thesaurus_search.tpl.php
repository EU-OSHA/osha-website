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
   

    <div id="tabs">
      <?php
        print l(t('Search'), 'tools-and-resources/eu-osha-thesaurus');
        print l(t('Alphabetical view'), 'tools-and-resources/eu-osha-thesaurus/alphabetical');
        print l(t('Hierarchical view'), 'tools-and-resources/eu-osha-thesaurus/hierarchical');
      ?>
    </div>

    <?php if ($header): ?>
      <div class="view-header">
        <?php print $header; ?>
      </div>
    <?php endif; ?>

    <?php if ($exposed): ?>
      <div class="view-filters">
        <?php print $exposed; ?>
      </div>
    <?php endif; ?>

    <?php if ($attachment_before): ?>
      <div class="attachment attachment-before">
        <?php print $attachment_before; ?>
      </div>
    <?php endif; ?>

    <?php if ($rows): ?>
      <div class="view-content">
      	<?php
      	  $view_display = $view->style_plugin->rendered_fields;
      	  $view_result = $view->result;
      	  $i = 0;
      	  foreach ($view_display as $key=>$element)
      	  {
      	  	$synonyms = $view_result[$i]->_entity_properties['entity object']->field_synonyms;
      	  	$i++;
      	  	$rowClasess = "views-row revamp-row views-row-".$i." ";
      	  	if ($i % 2 == 0)
      	  	{
      	  	  $rowClasess = $rowClasess . "views-row-even";
      	  	  if ($i == sizeof($view_display))
      	  	  {
      	  	  	$rowClasess = $rowClasess . " views-row-last";
      	  	  }
      	  	}
      	  	else
      	  	{
      	  	  $rowClasess = $rowClasess . "views-row-odd";
      	  	  if ($i == 1)
      	  	  {
      	  	  	$rowClasess = $rowClasess . " views-row-first";
      	  	  }
      	  	  else if ($i == sizeof($view_display))
      	  	  {
      	  	  	$rowClasess = $rowClasess . " views-row-last";
      	  	  }
      	  	}
      	  	print '<div class="'.$rowClasess.'">';
      	  	if ($element['title_field'])
      	  	{
      	  	  print '<div class="views-field views-field-title-field"><h2 class="field-content">'.$element['title_field'].'</h2></div>';
      	  	}
      	  	if ($synonyms[$lang] && $synonyms[$lang][0]['value'] != "")
      	  	{
      	  	  print '<div class="views-field views-field-field-synonyms"><span class="views-label views-label-field-synonyms">'.t("Synonyms").':</span> ';
      	  	  print '<span class="field-content">'.$element['field_synonyms'].'</span></div>';
      	  	}
      	  	if ($element['field_definition'])
      	  	{
      	  	  print '<div class="views-field views-field-field-definition"><span class="field-content">'.$element['field_definition'].'</span></div>';
      	  	}
      	  	if ($element['view_node'])
      	  	{
      	  	  print '<div><div class="views-field views-field-view-node">'.$element['view_node'].'</div></div>';
      	  	}
      	  	print '</div>';
      	  }
      	?>
      </div>
    <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print $empty; ?>
      </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
      <!-- <div class="feed-icon"> -->
        <!-- <a href="/en/tools-and-resources/eu-osha-thesaurus/search/export?search_api_views_fulltext=contrato&amp;sort_by=search_api_relevance"><img typeof="foaf:Image" src="http://46.105.212.7:8085/sites/all/modules/contrib/views_data_export/images/xls.png" alt="XLS" title="XLS" /></a>-->
        <!-- <?php print $feed_icon; ?> -->
      <!-- </div> -->
      
    	<div class="download-content-theasaurus download-content-theasaurus-small">
        <div class="download-content-theasaurus-label">
          <img src="/sites/all/themes/osha_frontend/images/info-thesaurus.png" alt="Info" 
          title="<?php print t('Download the EU-OSHA thesaurus terms from your search in Excel format'); ?>" >
          <label><?php print t('Download results');?></label>
          <?php
            $urlParams = drupal_get_query_parameters();
            $params = "";
            if (sizeof($urlParams) > 0)
            {
              $i = 0;
              foreach ($urlParams as $key => $value) {
                if ($i==0)
                {
                  $params = "?";
                  $i++;
                }
                else
                {
                  $params = $params."&";
                }
                $params = $params.$key."=".$value;
              }
            }
          ?>
          <a href="<?php print '/' . $lang . '/tools-and-resources/eu-osha-thesaurus/search/export' .$params ?>"><img class="download" src="/sites/all/themes/osha_frontend/images/download-thesaurus.png" alt="<?php print t('Download'); ?>" title="<?php print t('Download'); ?>"></a>
    	  </div>
      </div>
    <?php endif; ?>

    <div class="content-pagination container">
	  <?php if ($pager): ?>
	    <?php print $pager; ?>
	  <?php endif; ?>
	  <?php if ($footer): ?>
	    <?php print $footer; ?>
	  <?php endif; ?>
	</div>

    <?php if ($attachment_after): ?>
      <div class="attachment attachment-after">
        <?php print $attachment_after; ?>
      </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <?php print $more; ?>
    <?php endif; ?>

  </div><?php /* class view */ ?>
</div>
