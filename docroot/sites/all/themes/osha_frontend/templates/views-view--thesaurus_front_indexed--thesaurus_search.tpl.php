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
