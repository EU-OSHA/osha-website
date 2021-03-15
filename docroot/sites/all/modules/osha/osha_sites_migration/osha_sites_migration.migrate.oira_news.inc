<?php

/**
 * Class NCWNewsMigration migrates news
 *
 * Set hwc_migration_news_url variable for explicit source URL.
 */
class OiraNewsMigration extends AbstractNCWNodeMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'OiraNewsSource', 'news');
    $this->description = 'Import news from HWC';
  }

  /**
   * {@inheritdoc}
   */
  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('uid')->defaultValue(0);
    $this->addFieldMapping('field_tags', 'field_tags');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);

//    $this->addFieldMapping('field_aditional_resources', 'field_aditional_resources');

    $this->addUnmigratedDestinations(array(
      'field_tags:ignore_case',
      'field_expiration_date:rrule',
      'field_image:source_dir',
      'field_image:urlencode',
      'field_image:alt',
      'field_image:title',
      'field_publication_date:rrule',
    ));
    $this->ignoreMetatagMigration();
  }

  protected function getManuallyMigratedFields() {
    return array_merge(array('field_tags'), parent::getManuallyMigratedFields());
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_tags = osha_migration_normalize_code_term_reference($row->field_tags, 'field_tags_code', 'tags');
    // field_aditional_resources
//    $fi = field_info_field('field_aditional_resources');
//    osha_migration_normalize_field_entityreference($row, 'field_aditional_resources', $fi);
//    $additional_resources = $row->field_aditional_resources;
//    $row->field_aditional_resources = array();
//    foreach ($additional_resources as $original_nid) {
//      if ($destid1 = ncw_migration_find_additional_resource($original_nid)) {
//        $row->field_aditional_resources[] = $destid1;
//      }
//    }
  }
}


class OiraNewsSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_summary',
      'field_summary_format',
      'field_summary_language',
      'field_image',
      'field_image_caption',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
//      'field_tags',
    );
    return array_combine($fields, $fields);
  }
}
