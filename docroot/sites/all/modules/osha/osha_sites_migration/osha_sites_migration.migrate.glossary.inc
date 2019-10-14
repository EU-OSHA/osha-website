<?php
class SimpleHWCTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function __construct($options) {
    $this->site_source = 'hwc';
    parent::__construct($options);
  }

  public function contentFields() {
    return array();
  }
}

class HWCGlossaryTypeMigration extends AbstractNCWTaxonomyTermMigration {
  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleHWCTaxonomyTermSource', 'glossary_type');
    $this->description = 'Import taxonomy "glossary_type" from HWC';
  }
}

class HWCGlossaryMigration extends AbstractNCWTaxonomyTermMigration {
  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleHWCTaxonomyTermSource', 'glossary');
    $this->description = 'Import taxonomy "glossary" from HWC';
  }

  protected function getManuallyMigratedFields() {
    return array('field_migration_source', 'field_glossary_type');
  }
  function getTermReferenceFieldsMap() {
    return [
      'field_glossary_type' => 'glossary_type',
    ];
  }

  function addFieldMappings() {
    parent::addFieldMappings();
    $unmigrated_destinations = [];
    foreach ($this->getTermReferenceFieldsMap() as $taxonomy => $vocabulary) {
      $this->addFieldMapping($taxonomy . ':source_type')->defaultValue('tid');
      $this->addFieldMapping($taxonomy . ':create_term')->defaultValue(FALSE);
      $this->addFieldMapping($taxonomy, $taxonomy);
      $unmigrated_destinations[] = $taxonomy . ':ignore_case';
    }

    $this->addUnmigratedDestinations($unmigrated_destinations);
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $taxonomy = 'field_glossary_type';
    $vocabulary = 'glossary_type';
    $source_migration_name = 'tax_' . $vocabulary;
    if ($row->field_glossary_type) {
      $orig_taxonomies = $row->field_glossary_type;
      $original = [$row->field_glossary_type['tid']];
      $row->field_glossary_type = osha_migration_normalize_migrated_term_reference($original, $source_migration_name);
      if (!$row->field_glossary_type) {
        foreach ($orig_taxonomies as $orig_taxonomy) {
          watchdog('ncw_migration', "[BUG]Cannot find taxonomy '" . serialize($orig_taxonomy) . "', for $vocabulary", array(), WATCHDOG_ERROR);
        }
      }
    }
  }

  public function contentFields() {
    return array(
      'field_glossary_type' => 'field_glossary_type',
    );
  }
}
