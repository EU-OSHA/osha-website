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
		      $block = block_load('block','3');
		      print drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
		    ?>
    	</div>
    	<div class="download-content-theasaurus">
    		<label><?php print t('Download'); ?></label>
    		<img src="/sites/all/themes/osha_frontend/images/info-thesaurus.png" alt="Info" 
    		title="<?php print t('Download your complete EU-OSHA thesaurus terms in Excel format. Choose the language from the box'); ?>" >
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
   

    <div id="tabs">
      <a class="active" href="/tools-and-resources/eu-osha-thesaurus/search"><?php print t("Search"); ?></a>
      <a href="/tools-and-resources/eu-osha-thesaurus/alphabetical"><?php print t("Alphabetical view"); ?></a>
      <a href="/tools-and-resources/eu-osha-thesaurus/hierarchical"><?php print t("Hierarchical View"); ?></a>
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
        <?php print $rows; ?>
      </div>
    <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print $empty; ?>
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


    <?php if ($feed_icon): ?>
      <div class="feed-icon">
        <?php print $feed_icon; ?>
      </div>
    <?php endif; ?>

  </div><?php /* class view */ ?>
</div>
