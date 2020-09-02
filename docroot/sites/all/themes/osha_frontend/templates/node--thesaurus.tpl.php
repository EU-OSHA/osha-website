<?php
/**
 * @file
 * Returns the HTML for a thesaurus node.
 */

global $language;
$lang = $language->language;
?>
<?php if($page): ?>
	<h1 id="page-title" class="page__title title"><?php print t('EU-OSHA thesaurus');?></h1>
	<div class="view-header back"><?php print l(t('Back to list of terms'), 'tools-and-resources/eu-osha-thesaurus/search'); ?></div>

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
<?php endif; ?>

<?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
	<header>
		<?php print render($title_prefix); ?>
		<?php if ($page && $title): ?>
			<?php 
				if ($content['field_term_id']['#items'][0]['value'] && $content['field_term_id']['#items'][0]['value'] != ''){
					$titleText = $content['field_term_id']['#items'][0]['value'] . ' - ' . $title;
				}
				else
				{
					$titleText = $title;
				}
			?>
			<div class="content-hierarchical-terms">
				<?php 
					$breadcrumb = array($title);
					if ($content['field_father'])
					{
						$father = $content['field_father'][0]['#item']['target_id'];
						$father = node_load($father);
						array_push($breadcrumb, $father->title_field[$lang][0]["value"]);
						while(sizeof($father->field_father) > 0)
						{
							$father = $father->field_father["und"][0]["target_id"];
							$father = node_load($father);
							array_push($breadcrumb, $father->title_field[$lang][0]["value"]);
						}
					}

					for ($i = sizeof($breadcrumb)-1; $i >= 0; $i--)
					{
						print "<span>".$breadcrumb[$i]."</span>";
						if ($i > 0)
						{
							print "<span>></span>";
						}
					}
				?>
				<!--<span>Lorem</span><span>></span><span><a href="">ipsum</a></span>-->
			</div>
			<h2<?php print $title_attributes; ?>><?php print $titleText; ?></h2>
		<?php endif; ?>
		<?php print render($title_suffix); ?>
	</header>
<?php endif; ?>

<div class="content-link-hierarchical">
	<?php 
		$url = "tools-and-resources/eu-osha-thesaurus/hierarchical";
		if ($content['field_term_id']['#items'][0]['value'] && $content['field_term_id']['#items'][0]['value'] != '')
		{
			$url = $url . "?term=" . $content['field_term_id']['#items'][0]['value'];
		}
		print str_replace('%3D','=', str_replace('%3F','?', l(t('Hierarchical View'), $url))); 
	?>
</div>

<?php if ($content['field_definition']): ?>
	<?php print render($content['field_definition']); ?>
<?php endif; ?>

<?php if ($content['field_synonyms'] && strlen($content['field_synonyms'][0]['#markup']) > 0): ?>
	<div class="field field-name-field-synonyms field-type-text field-label-above">
		<div class="field-label"><?php print t('Synonyms'); ?>:&nbsp;
		</div>
		<div class="field-items">
			<?php 
				for ($i = 0; $i < sizeof($content['field_synonyms']['#items']); $i++)
				{
					$elem = $content['field_synonyms']['#items'][$i];
					print $elem['value'];
					// If not last, add a comma
					if ($i != (sizeof($content['field_synonyms']['#items']) -1))
					{
						print ", ";
					}
				}
			?>
		</div>
	</div>
<?php endif; ?>

<?php if ($content['field_context']): ?>
	<?php print render($content['field_context']); ?>
<?php endif; ?>

<?php if ($content['field_term_reference']): ?>
	<?php print render($content['field_term_reference']); ?>
<?php endif; ?>

<?php if ($content['field_notes']): ?>
	<?php print render($content['field_notes']); ?>
<?php endif; ?>

<div class="accordion-container">
  <div class="set">
	  <h3>
		<?php print t('Translations');?>
		<span class="accordion-icon"></span>
	  </h3>
	<div class="content accordion">
		<?php
			$languages = $content['links']['translation']['#links'];
			foreach($node->title_field as $code=>$titleTranslation)
			{

				if ($code != "en" && $languages[$code]["title"])
				{    				
					print "<div class='label-item'>".$languages[$code]["title"].":</div>";	
				}
				else if ($code == "en")
				{
					print "<div class='label-item'>English:</div>";	
				}
				print "<div class='field-item'>".$titleTranslation[0]["value"]."</div>";
			}
		?>
	</div>
  </div>
</div>

<?php
	hide($content['comments']);
  hide($content['links']);
?>

 