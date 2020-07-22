<?php

/**
 * Class NCWNewsMigration migrates news
 *
 * Set hwc_migration_news_url variable for explicit source URL.
 */
class HWCNewsMigration extends AbstractNCWNodeMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'HWCNewsSource', 'news');
    $this->description = 'Import news from HWC';
  }

  /**
   * {@inheritdoc}
   */
  protected function addFieldMappings() {
    parent::addFieldMappings();
    // Node base fields.
    $uid = variable_get('hwc_migration_default_uid', 0);
    $this->addFieldMapping('uid')->defaultValue($uid);

    $this->addFieldMapping('field_tags', 'field_tags');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);

    $this->addFieldMapping('field_activity', 'field_activity');
    $this->addFieldMapping('field_activity:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_activity:create_term')->defaultValue(FALSE);

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

  /**
   * {@inheritdoc}
   */
  protected function getManuallyMigratedFields() {
    return array_merge(array('field_tags', 'field_activity'), parent::getManuallyMigratedFields());
  }

  /**
   * {@inheritdoc}
   */
  function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_tags = osha_migration_normalize_code_term_reference($row->field_tags, 'field_tags_code', 'tags');
    $row->field_activity = osha_migration_normalize_code_term_reference($row->field_activity, 'field_activity_code', 'activity');
  }
}


class HWCNewsSource extends AbstractNCWNodeSource {

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
      'field_expiration_date',
      'field_expiration_date_timezone',
      'field_expiration_date_value2',
      'field_archived',
      'field_show_on',
    );
    return array_combine($fields, $fields);
  }

}
