<?php

/**
 * Class HWCEventsMigration migrates news
 *
 * Set hwc_migration_news_url variable for explicit source URL.
 */
class HWCEventsMigration extends AbstractNCWNodeMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'HWCEventsSource', 'events');
    $this->description = 'Import events from HWC';
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
      'field_organizer',
      'field_speaker',
      'field_partner_id',
      'field_schedule',
      'field_location',
      'field_contact_name',
      'field_contact_phone',
      'field_contact_email',
      'field_gallery',
      'field_wf_notification',

    ));
    $this->ignoreMetatagMigration();
  }

  /**
   * {@inheritdoc}
   */
  protected function getManuallyMigratedFields() {
    return array_merge(array(
      'field_tags',
      'field_activity',
      'field_event_type',
      ), parent::getManuallyMigratedFields());
  }

  /**
   * {@inheritdoc}
   */
  function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_tags = osha_migration_normalize_code_term_reference($row->field_tags, 'field_tags_code', 'tags');
    $row->field_activity = osha_migration_normalize_code_term_reference($row->field_activity, 'field_activity_code', 'activity');
    $row->field_event_type = 'Event';
    $row->field_for_the_web = 'Yes';
    if (is_array($row->body)) {
      foreach ($row->body as $key => $value) {
        if (!is_array($value)) {
          $row->body[$key] = str_replace("\n", '', $value);
        }
      }
    }
  }
}


class HWCEventsSource extends AbstractNCWNodeSource {

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
      'field_country_code',
      'field_city',
      'field_start_date',
      'field_website_of_event',
      'field_archived',
      'field_tags',
      'field_related_documents',
      'field_event_in_amp',
      'field_for_the_web',
    );
    return array_combine($fields, $fields);
  }
}
