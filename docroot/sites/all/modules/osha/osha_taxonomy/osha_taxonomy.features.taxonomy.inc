<?php
/**
 * @file
 * osha_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function osha_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'activity' => array(
      'name' => 'Activity',
      'machine_name' => 'activity',
      'description' => 'Activities and sub-activities will be used to classify all the content, but only for internal use',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
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
