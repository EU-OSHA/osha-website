<?php
/**
 * @file
 * osha_resources.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function osha_resources_taxonomy_default_vocabularies() {
  return array(
    'flickr_tags' => array(
      'name' => 'Flickr tags',
      'machine_name' => 'flickr_tags',
      'description' => 'Grab Flickr photos with these tags only. Comma separated.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
