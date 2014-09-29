<?php
/**
 * @file
 * osha.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function osha_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'publication_bookshop_id';
  $formatter->label = 'publication_bookshop_id';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = 'global $language ;
$curr_lang = $language->language;
$object = isset($variables[\'#object\']->field_publication_bookshop_id[$curr_lang]) ? $variables[\'#object\']->field_publication_bookshop_id[$curr_lang] :$variables[\'#object\']->field_publication_bookshop_id[\'en\'];
$code = $object[0][\'value\'];

$output = \'<span>Order a printed copy <a href="http://bookshop.europa.eu/is-bin/INTERSHOP.enfinity/WFS/EU-Bookshop-Site/en_GB/-/EUR/ViewPublication-Start?PublicationKey=\' . $code . \'"><img src="\' . $GLOBALS[\'base_url\'] . \'/sites/all/themes/osha_frontend/images/content/eu_bookshop.gif" alt="EU Bookshop: You can order a printed copy of this document" title="EU Bookshop: You can order a printed copy of this document"></a></span>\';
return $output;';
  $formatter->fapi = '';
  $export['publication_bookshop_id'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'publication_file';
  $formatter->label = 'publication_file';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = '$output = "<span>Download PDF in: </span>";

foreach($variables[\'#object\']->field_file as $lang => $object) {
    $output .=  \'<a href="\' . file_create_url($object[0][\'uri\']) . \'">\' . strtoupper($lang) . \'</a> | \';
}
$output = substr($output, 0, -3);
return $output;';
  $formatter->fapi = '';
  $export['publication_file'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'publication_related_publications';
  $formatter->label = 'publication_related_publications';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'entityreference';
  $formatter->code = 'global $language ;
$curr_lang = $language->language ;
$output = \'<h3>Summary &amp; Resources</h3>\';
$output .= \'<ul id="publication_related_publications">\';
$related_pubs = $variables[\'#object\']->field_related_publications[\'und\'];
foreach ($related_pubs as $pub) {
	$output .= \'<li>\';
	$node = node_load($pub[\'target_id\']);
	$title = isset($node->title_field[$curr_lang][0]) ? $node->title_field[$curr_lang][0][\'value\'] : $node->title_field[\'en\'][0][\'value\'];
	$output .=  \'<a href="\' . url(\'node/\' . $node->nid, array(\'absolute\' => TRUE)) . \'">\' . $title . \'</a>\';
	$output .= \'<span>Download PDF in:</span>\';
	foreach ($node->field_file as $lang => $object) {
		$output .=  \' <a href="\' . file_create_url($object[0][\'uri\']) . \'">\' . strtoupper($lang) . \'</a> | \';
	}
	$output = substr($output, 0, -3);
	$output .= \'</li>\';
}
$output .= \'</ul>\';
return $output;';
  $formatter->fapi = '';
  $export['publication_related_publications'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'publication_related_res';
  $formatter->label = 'publication_related_res';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = '$output = \'<ul id="publication_related_res">\';
global $language ;
$curr_lang = $language->language;
$object = isset($variables[\'#object\']->field_publication_related_res[$curr_lang]) ? $variables[\'#object\']->field_publication_related_res[$curr_lang] :$variables[\'#object\']->field_publication_related_res[\'en\'];
foreach ($object as $obj) {
	$name = ($obj[\'description\'] != NULL) ? $obj[\'description\'] : $obj[\'filename\'];
	$output .= \'<li><a href="\' . file_create_url($obj[\'uri\']) . \'">\' . $name . \' - \' . format_size(filesize($obj[\'uri\'])) . \'</a></li>\';
}
$output .= \'</ul>\';

return $output;
';
  $formatter->fapi = '';
  $export['publication_related_res'] = $formatter;

  return $export;
}
