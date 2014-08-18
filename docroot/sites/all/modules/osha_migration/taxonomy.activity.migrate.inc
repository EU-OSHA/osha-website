<?php

/**
 * Class MigrateOshaTaxonomyActivity migrates activity.json taxonomy. The data
 * is stored inside the <em>Activity</em> taxonomy.
 *
 * Part of the <em>OSHA Taxonomies</em> translation group.
 */
class MigrateOshaTaxonomyActivity extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance("OSHA Taxonomies"));
    $this->description = 'Populate the "Activity" taxonomy from JSON file in osha_migration module';

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => 100,
          'not null' => TRUE,
          'description' => 'Term code',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new OSHAMigrationListJSON($source_file, 'code'),
      new OSHATaxonomyMigrationItemJSON($source_file),
      array(
        'code' => 'Term code',
        'name' => 'Term name in english',
        'parent' => 'Parent term',
        'level' => 'The level of the term',
      )
    );

    $this->destination = new MigrateDestinationTerm(OSHA_TAXONOMIES_ACTIVITY);

    $this->addFieldMapping('field_activity_code', 'code');
    $this->addFieldMapping('parent', 'parent');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('name_field', 'name');
    $this->addFieldMapping('name_field:language')->defaultValue("en");
    $this->addFieldMapping('field_activity_level', 'level');

    $this->addUnmigratedDestinations(array(
      'description',
      'parent_name',
      'weight',
      'description_field',
      'description_field:summary',
      'description_field:format',
      'description_field:language',
      'field_activity_level:language',
      'field_activity_code:language',
      'path',
    ));
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc }
   */
  public function prepareRow($row) {
    $row->parent = 0;
    if (!empty($row->parent_code)) {
      $row->parent = MigrationUtil::findTermByFieldValue($row->parent_code, 'field_activity_code');
    }

    return TRUE;
  }

  /**
   * Called by destination right before saving.
   *
   * Here we set the entity language
   *
   * @param object $entity
   *   Entity to save
   * @param object $row
   *   Source row
   */
  public function prepare($entity, $row) {
    $entity->language = "en";
  }

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_TAXONOMY_ACTIVITY;
  }
}
