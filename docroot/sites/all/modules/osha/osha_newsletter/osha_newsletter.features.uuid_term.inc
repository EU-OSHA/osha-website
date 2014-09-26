<?php
/**
 * @file
 * osha_newsletter.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function osha_newsletter_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'News',
    'description' => NULL,
    'format' => NULL,
    'weight' => 5,
    'uuid' => '04648f6e-d60f-4ce7-b800-e7842ad4f320',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'News',
          'format' => NULL,
          'safe_value' => 'News',
        ),
      ),
    ),
    'name_original' => 'News',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 11,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Highlights',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '4edd574b-8dbd-4af8-b82c-6e85eeb5be99',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Highlights',
          'format' => NULL,
          'safe_value' => 'Highlights',
        ),
      ),
    ),
    'name_original' => 'Highlights',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 12,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Coming soon',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => '6255c5ce-9b1f-4be1-85f2-79199e789e3f',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Coming soon',
          'format' => NULL,
          'safe_value' => 'Coming soon',
        ),
      ),
    ),
    'name_original' => 'Coming soon',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 13,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Blog',
    'description' => NULL,
    'format' => NULL,
    'weight' => 4,
    'uuid' => '798b75d1-a135-495f-805d-fb3293be88c3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Blog',
          'format' => NULL,
          'safe_value' => 'Blog',
        ),
      ),
    ),
    'name_original' => 'Blog',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 14,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Events',
    'description' => NULL,
    'format' => NULL,
    'weight' => 6,
    'uuid' => '9bbceb37-cc1f-4bc1-99a0-0222105568a1',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Events',
          'format' => NULL,
          'safe_value' => 'Events',
        ),
      ),
    ),
    'name_original' => 'Events',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 15,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Latest publications',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => 'ad8da6ba-1101-4181-bba2-1b7094cabab3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Latest publications',
          'format' => NULL,
          'safe_value' => 'Latest publications',
        ),
      ),
    ),
    'name_original' => 'Latest publications',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 16,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'OSH matters',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'c6feccca-fa35-4655-b048-39849aef6ab2',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'OSH matters',
          'format' => NULL,
          'safe_value' => 'OSH matters',
        ),
      ),
    ),
    'name_original' => 'OSH matters',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 17,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  return $terms;
}
