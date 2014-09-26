<?php
/**
 * @file
 * osha_taxonomies_uuid.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function osha_taxonomies_uuid_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Road Transport',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'road_transport',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Автомобилен транспорт',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Silniční doprava',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Vejtransport',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Straßenverkehr',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Οδικές μεταφορές',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Road Transport',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Transporte por carretera',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Maanteetransport',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Tieliikenne',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Transport routier',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Közúti fuvarozás',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Közúti közlekedés',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Flutningar á vegum',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Trasporto stradale',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Kelių transportas',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Autotransports',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Trasport bit-Triq',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Wegvervoer',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Veitransport',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Transport drogowy',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Transporte rodoviários',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Transport rutier',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Cestná doprava',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Cestni promet',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Vägtransporter',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '003fdea3-8f3a-43fc-be60-2f76e1773dd1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => '1: Anticipating change',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '00cf9383-d3f2-4220-a8a2-42a0d4b4a33b',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'anticipating_change',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '1: Anticipating change',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '00cf9383-d3f2-4220-a8a2-42a0d4b4a33b',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Restructuring',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '02c241c2-0325-4d15-b87b-431a4dabacd0',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669371,
          'entity_uuid' => '02c241c2-0325-4d15-b87b-431a4dabacd0',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '974895cc-177f-4d46-82c6-63a7d309b716',
    ),
  );
  $terms[] = array(
    'name' => 'Slips, trips and falls',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '02fa5f88-67d0-4df9-9f43-619df14d81bc',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669288,
          'entity_uuid' => '02fa5f88-67d0-4df9-9f43-619df14d81bc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Worker participation and involvement',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0686c47f-a6ef-4fff-9fd4-1d71a0735180',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668680,
          'entity_uuid' => '0686c47f-a6ef-4fff-9fd4-1d71a0735180',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    ),
  );
  $terms[] = array(
    'name' => 'Dust and aerosols',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '07962edd-6d68-4047-8568-941aa79a1212',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674559,
          'entity_uuid' => '07962edd-6d68-4047-8568-941aa79a1212',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => 'Working time',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '07c425ee-869a-4469-a928-1bf420c1faf7',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669382,
          'entity_uuid' => '07c425ee-869a-4469-a928-1bf420c1faf7',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '974895cc-177f-4d46-82c6-63a7d309b716',
    ),
  );
  $terms[] = array(
    'name' => '3: Tools for OSH management',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '08e11f8b-4122-4e6e-83cb-2e0b3c06d082',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'tools_for_osh_management',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '3: Tools for OSH management',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '08e11f8b-4122-4e6e-83cb-2e0b3c06d082',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Workplace Health Promotion',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '09960840-6211-4b9f-80a0-7c85a4f33fcd',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668787,
          'entity_uuid' => '09960840-6211-4b9f-80a0-7c85a4f33fcd',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => 'Substance abuse',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0bbdb03b-3a5a-4166-a87f-89cd29f6ee9c',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669593,
          'entity_uuid' => '0bbdb03b-3a5a-4166-a87f-89cd29f6ee9c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '6438f9a5-8a5d-417b-b20e-ffea262b0999',
    ),
  );
  $terms[] = array(
    'name' => 'Risk assessment',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0c49de45-8df0-4531-9275-c95ce47ee39a',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668667,
          'entity_uuid' => '0c49de45-8df0-4531-9275-c95ce47ee39a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    ),
  );
  $terms[] = array(
    'name' => 'Distribution and logistics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0c963db3-d548-4d16-9c83-bbdefdf64ca4',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669709,
          'entity_uuid' => '0c963db3-d548-4d16-9c83-bbdefdf64ca4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Construction',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0e403655-c86a-4876-8aeb-d1a93a1ba564',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669703,
          'entity_uuid' => '0e403655-c86a-4876-8aeb-d1a93a1ba564',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Psychosocial issues',
    'description' => '',
    'format' => 'full_html',
    'weight' => 8,
    'uuid' => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670460,
          'entity_uuid' => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Dangerous substances',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'dangerous_substances',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Опасни вещества',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Nebezpečné látky',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Farlige stoffer',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Gefahrstoffe',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Επικίνδυνες ουσίες',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Dangerous substances',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Sustancias peligrosas',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Ohtlikud ained',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Vaaralliset aineet',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Substances dangereuses',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Veszélyes anyagok',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Sostanze pericolose',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Pavojingos medžiagos',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Bīstamās vielas',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Sustanzi Perikolużi',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Gevaarlijke stoffen',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Substancje niebezpieczne',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Substâncias perigosas',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Substanţe periculoase',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Nebezpečné látky',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Nevarne snovi',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Farliga ämnen',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Transport',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '1589c71a-9063-4a1f-bad6-de14c1f0d317',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669740,
          'entity_uuid' => '1589c71a-9063-4a1f-bad6-de14c1f0d317',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Nanoparticles',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '1a593acc-a54a-4713-81dc-29c5804fbb65',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
        1 => array(
          'tid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411675012,
          'entity_uuid' => '1a593acc-a54a-4713-81dc-29c5804fbb65',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => 'Management Systems',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '1a5a0de7-5dc6-4477-86bf-c83db8b03dc2',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668653,
          'entity_uuid' => '1a5a0de7-5dc6-4477-86bf-c83db8b03dc2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    ),
  );
  $terms[] = array(
    'name' => 'Job design',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '1cc28e95-d6a5-4273-83d2-c031b02aa685',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669367,
          'entity_uuid' => '1cc28e95-d6a5-4273-83d2-c031b02aa685',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '974895cc-177f-4d46-82c6-63a7d309b716',
    ),
  );
  $terms[] = array(
    'name' => 'Fisheries',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'fisheries',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Fiskerisektoren',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Fischerei',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Pesca',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Kalandussektor',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Pêche',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Halászat',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Pesca',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Žuvininkystė',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Zvejsaimniecība',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Settur tal-pixkeriji',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Fisheries',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '1d3d24cb-0c1f-4de5-b167-fdc1bea0e731',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Occupational diseases',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '20521222-4218-49f8-b679-af0b80fc3d3a',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '46b05090-3a00-4815-922f-c3998858aa5d',
          'uuid' => '46b05090-3a00-4815-922f-c3998858aa5d',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411675167,
          'entity_uuid' => '20521222-4218-49f8-b679-af0b80fc3d3a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '6438f9a5-8a5d-417b-b20e-ffea262b0999',
    ),
  );
  $terms[] = array(
    'name' => 'Anthropometry',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '22d17eb8-e49f-4225-ae54-0684bca19960',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669148,
          'entity_uuid' => '22d17eb8-e49f-4225-ae54-0684bca19960',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => '2.1. European Survey of Enterprises on New & Emerging Risks (ESENER)',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2a207a55-e8be-4910-9b9a-47995c11e39c',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'facts_and_figures_1',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '2.1. European Survey of Enterprises on New & Emerging Risks (ESENER)',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '2a207a55-e8be-4910-9b9a-47995c11e39c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'e9fa57e4-b0c3-476b-898c-176ae24d6062',
    ),
  );
  $terms[] = array(
    'name' => '7.1. Finance & Accounting',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2b5014f8-9d88-489d-9f16-75cb35fadb09',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'governance_1',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '7.1. Finance & Accounting',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '2b5014f8-9d88-489d-9f16-75cb35fadb09',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'f77ff1e1-cccc-4f56-b470-ad638467b135',
    ),
  );
  $terms[] = array(
    'name' => 'Physiological fatigue',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '2cd439fb-b631-4724-97c2-58a54565695d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669198,
          'entity_uuid' => '2cd439fb-b631-4724-97c2-58a54565695d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => 'Accident prevention',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'accident_prevention',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Превенция на злополуки',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Prevence úrazů',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Forebyggelse af ulykker',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Unfallverhütung',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Πρόληψη ατυχημάτων',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Accident prevention',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Prevención de accidentes',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Õnnetuste ärahoidmine',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Tapaturmien torjunta',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Prévention des accidents',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Balesetmegelőzés',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Prevenzione degli infortuni',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Nelaimingų atsitikimų prevencija',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Nelaimes gadījumu profilakse',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Prevenzjoni ta’ Aċċidenti',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Voorkomen van arbeidsongevallen',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Zapobieganie nieszczęśliwym wypadkom',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Prevenção de acidentes',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Prevenirea accidentelor',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Prevencia úrazov',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Preprečevanje nesreč',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Förebyggande av olyckor',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2dd789d4-c119-466a-8791-85c8635d9ca1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Green jobs',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'green_jobs',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'зелени работни места',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'zelená pracovní místa',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'grønne job',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Grüne Arbeitsplätze',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => '\'πράσινες\' θέσεις εργασίας',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Green jobs',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'trabajos \'verdes\'',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'rohelised töökohad',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'vihreät työpaikat',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'emplois verts',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'zöld munkahelyek',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'græn störf',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'posti di lavoro verdi',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'su ekologija susiję darbai',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'ekoloģiskas darbavietas',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'impjiegi ħodor',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'groene banen',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'grønne jobber',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'zielone miejsca pracy',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'empregos verdes',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'locuri de muncă ecologice',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'zelené pracovné miesta',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Zelena delovna mesta',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'gröna jobb',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2df7d9f5-c966-4f91-9fe6-12bd173e21c3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Training',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '2f752436-8777-426f-af8c-8f06ab49351d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668772,
          'entity_uuid' => '2f752436-8777-426f-af8c-8f06ab49351d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => 'Corporate Social Responsibility',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'corporate_social_responsibility',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Корпоративна социална отговорност',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Společná sociální odpovědnost',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Virksomhedernes sociale ansvar',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Soziale Verantwortung der Unternehmen',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Εταιρική κοινωνική ευθύνη',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Corporate Social Responsibility',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Responsabilidad Social de las Empresas',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Ettevõtete sotsiaalne vastutus',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Responsabilité sociale des entreprises',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Monde du travail en mutation',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Corporate Social Responsibility',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Vállalati szociális felelősség',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Corporate Social Responsibility',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Responsabilità sociale dell’impresa',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Įmonių socialinė atsakomybė',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Korporatīvā sociālā atbildība',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Responsabbiltà Soċjali mill-Kumpaniji',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Sociale verantwoordelijkheid van bedrijven',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Corporate Social Responsibility',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Odpowiedzialność społeczna przedsiębiorstw',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Responsabilidade social das empresas',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Răspunderea socială a întreprinderii',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Podniková sociálna zodpovednosť',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Družbena odgovornost podjetij',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Företagens sociala ansvar',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '2faad959-2b29-40e6-a25e-e205453565c4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Vibration',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '328a8f48-55f4-4d79-9059-2100dc6f2c24',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669077,
          'entity_uuid' => '328a8f48-55f4-4d79-9059-2100dc6f2c24',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '8f36d40f-4400-432c-9067-2b5836ec2717',
    ),
  );
  $terms[] = array(
    'name' => '5: Networking knowledge',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '341c68a0-184a-4c11-8789-178251c02872',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'networking_knowledge',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '5: Networking knowledge',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '341c68a0-184a-4c11-8789-178251c02872',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Leadership',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '355f1f5b-d5da-4caf-b4c9-d4315c421b01',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
          'uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670090,
          'entity_uuid' => '355f1f5b-d5da-4caf-b4c9-d4315c421b01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    ),
  );
  $terms[] = array(
    'name' => 'Disability management',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '3c20382e-6fcd-4275-9fd8-1c591ef83cf3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668745,
          'entity_uuid' => '3c20382e-6fcd-4275-9fd8-1c591ef83cf3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => 'Emerging risks',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3c5a05a7-9569-42e1-9afa-8fcc3e539ca0',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'emerging_risks',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Emerging risks',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3c5a05a7-9569-42e1-9afa-8fcc3e539ca0',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => '2.5. Costs and benefits of OSH',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3cca98a5-f928-4543-a290-e6c009efcb1e',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'facts_and_figures_5',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '2.5. Costs and benefits of OSH',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '3cca98a5-f928-4543-a290-e6c009efcb1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'e9fa57e4-b0c3-476b-898c-176ae24d6062',
    ),
  );
  $terms[] = array(
    'name' => 'Cleaning workers',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'cleaning_workers',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Почистване на работниците',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Čištění pracovníků',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Rengøring arbejdstagere',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Reinigungskräfte',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Καθαρισμού εργαζομένων',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Cleaning workers',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Trabajadores de la limpiez',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Puhastus töötajate',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Siivoustyöntekijöitä',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Employés de nettoyage',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Cleaning workers',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Takarító személyzet',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Cleaning workers',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Addetti alle pulizie',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Valytojams',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Uzkopšanas darbiniekiem',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Ħaddiema tat-tindif',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Reiniging werknemers',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Cleaning workers',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Pracowników do czyszczenia',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Trabalhadores de limpeza',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Personalului de curăţenie',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Čistenie pracovníkov',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Čiščenje delavci',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Städpersonal',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '3d7a5f11-bb2f-4825-8f2b-e77f8dbada7a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Nanomaterials',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'nanomaterials',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Наноматериалите',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Nanomateriály',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Nanomaterialer',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Nanomaterialien',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Νανοϋλικά',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Nanomaterials',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Nanomateriales',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Nanomaterjalid',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Nanomateriaalit',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Nanomatériaux',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Nanomaterijala',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Nanoanyagok',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Nanóefni',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Nanomateriali',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Nanomedžiagos',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Nanomateriāli',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Nanomaterjali',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Nanomaterialen',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Nanomaterialer',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Nanomateriały',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Nanomateriais',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Nanomaterialele',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Nanomateriály',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Nanomateriali',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Nanomaterial',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4063bbba-5ca1-4c6c-9dc2-8275e6477b1e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Ergonomic work design',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '416df567-ec5c-42d9-88bb-71948cb5256d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669167,
          'entity_uuid' => '416df567-ec5c-42d9-88bb-71948cb5256d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => 'ESENER',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'esener',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'ESENER',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '43ca7077-7aba-44e3-af54-8fca1479563c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Transport',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'transport',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Транспорт',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Doprava',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Verkehr',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Μεταφορές',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Transportes',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Liikenne',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Transports',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Közlekedés',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Trasporti',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Transportas',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Transports',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Trasport',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Vervoer',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Transportes',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Transport',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Doprava',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Promet',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Transporter',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '44b49d76-a785-48b2-8c64-2e3f455eb6a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Electricity',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '44c88915-07a9-468e-b068-ac0f8cc016e3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669052,
          'entity_uuid' => '44c88915-07a9-468e-b068-ac0f8cc016e3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '8f36d40f-4400-432c-9067-2b5836ec2717',
    ),
  );
  $terms[] = array(
    'name' => 'Road safety',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '458f9d8c-f9fb-4033-8969-3871af27e87d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669282,
          'entity_uuid' => '458f9d8c-f9fb-4033-8969-3871af27e87d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Young workers',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '4638fb7d-c73a-4e4c-bc64-19317fb5ae87',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '4866de41-3d93-49b2-8149-8ef2116de40a',
          'uuid' => '4866de41-3d93-49b2-8149-8ef2116de40a',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670244,
          'entity_uuid' => '4638fb7d-c73a-4e4c-bc64-19317fb5ae87',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => 'Work related diseases',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '46b05090-3a00-4815-922f-c3998858aa5d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'work_related_diseases',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Work related diseases',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '46b05090-3a00-4815-922f-c3998858aa5d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'OSH and young people',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4866de41-3d93-49b2-8149-8ef2116de40a',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'osh_and_young_people',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'OSH and young people',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '4866de41-3d93-49b2-8149-8ef2116de40a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Page',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '4d106060-5ea2-448e-92b8-3cd649f867a9',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'article_types',
    'field_article_type_code' => array(
      'und' => array(
        0 => array(
          'value' => 'page',
          'format' => NULL,
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411244110,
          'entity_uuid' => '4d106060-5ea2-448e-92b8-3cd649f867a9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OSH in general',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '4f931fb7-8258-4da9-9226-b26ffe706e24',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411667891,
          'entity_uuid' => '4f931fb7-8258-4da9-9226-b26ffe706e24',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Main OSH players - organisations',
    'description' => '',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '54369f06-5dec-4010-9591-aeffcf516d3c',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668421,
          'entity_uuid' => '54369f06-5dec-4010-9591-aeffcf516d3c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '4f931fb7-8258-4da9-9226-b26ffe706e24',
    ),
  );
  $terms[] = array(
    'name' => 'Maintenance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'maintenance',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Поддръжка',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Údržba',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Vedligeholdelse',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Instandhaltung',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Συντήρηση',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Maintenance',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Mantenimiento',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Hooldus',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Kunnossapito',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Maintenance',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Maintenance',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Karbantartás',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Maintenance',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Manutenzione',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Techninė priežiūra',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Uzturēšana',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Manutenzjoni',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Onderhoud',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Maintenance',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Bezpieczeństwo eksploatacji',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Manutenção',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Mentenanţă',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Údržba',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Vzdrževalna dela',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Underhåll',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '55bc45c3-f37c-4354-85c0-f5abe922ee8d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => '4: Raising awareness',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '57c7ff22-5cd8-49c4-8789-262d2a3453bd',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'raising_awareness',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '4: Raising awareness',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '57c7ff22-5cd8-49c4-8789-262d2a3453bd',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Ergonomics in office work',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '57d88eb2-ba6e-4bc5-9418-f3834a95a0bd',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669173,
          'entity_uuid' => '57d88eb2-ba6e-4bc5-9418-f3834a95a0bd',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => 'Manufacturing',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '58d638b3-2de2-4c17-b0b8-6b186b994e39',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669736,
          'entity_uuid' => '58d638b3-2de2-4c17-b0b8-6b186b994e39',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Legislation',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'publication',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'legislation',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'законодателство',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Právní předpisy',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Lovgivning',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Gesetzgebung',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Νομοθεσία',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Legislation',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Legislación',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Õigusaktid',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Säädökset',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Législation',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Zakonodavstvo',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Jogszabályok',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Löggjöf',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Normativa',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Teisės aktai',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Tiesību akti',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Leġiżlazzjoni',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Wetgeving',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Lovgivning',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Akty prawne',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Legislação',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Legislaţie',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Právne predpisy',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Zakonodaja',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Lagstiftning',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Introduction',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '5cd70528-4ea1-4cce-9370-370c22dee0d7',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'article_types',
    'field_article_type_code' => array(
      'und' => array(
        0 => array(
          'value' => 'introduction',
          'format' => NULL,
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411244110,
          'entity_uuid' => '5cd70528-4ea1-4cce-9370-370c22dee0d7',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Legislation',
    'description' => '',
    'format' => 'full_html',
    'weight' => 3,
    'uuid' => '5f77cf38-4d5b-4e7b-93d1-f17c3aac9d18',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
          'uuid' => '592c99f9-a1a2-47a3-81b4-ad72906c1a28',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670277,
          'entity_uuid' => '5f77cf38-4d5b-4e7b-93d1-f17c3aac9d18',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '4f931fb7-8258-4da9-9226-b26ffe706e24',
    ),
  );
  $terms[] = array(
    'name' => 'Risk assessment',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'risk_assessment',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Оценка на риска',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Hodnocení rizik',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Risikovurdering',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Gefährdungsbeurteilung',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Αξιολόγηση κινδύνων',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Risk assessment',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Evaluación de riesgos',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Riskihindamine',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Riskinarviointi',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Évaluation des risques',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Kockázatértékelés',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Valutazione dei rischi',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Rizikos vertinimas',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Risku novērtēšana',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Evalwazzjoni tar-riskji',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Risicobeoordeling',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Ocena ryzyka',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Avaliação de risco',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Evaluarea riscului',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Hodnotenie rizík',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Ocena tveganja',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Riskbedömning',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '5f786f64-1537-4357-a0cd-015c41eba9ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Workplace transport',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '61454728-dc7d-46f5-98dc-897682c6732f',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669300,
          'entity_uuid' => '61454728-dc7d-46f5-98dc-897682c6732f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Safety',
    'description' => '',
    'format' => 'full_html',
    'weight' => 6,
    'uuid' => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668175,
          'entity_uuid' => '639aa2d8-9b19-4103-9602-c8baea1a3551',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Health',
    'description' => '',
    'format' => 'full_html',
    'weight' => 9,
    'uuid' => '6438f9a5-8a5d-417b-b20e-ffea262b0999',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668218,
          'entity_uuid' => '6438f9a5-8a5d-417b-b20e-ffea262b0999',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ageing workers',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '646b7e62-30de-4c8a-a14e-ab52f960c897',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'e424b19c-5dc8-474a-a787-c80debb3b8bb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669963,
          'entity_uuid' => '646b7e62-30de-4c8a-a14e-ab52f960c897',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => 'Disabled people',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '66060c24-6b5d-4f20-89e5-0a5d13a9028d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'disabled_people',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Disabled people',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '66060c24-6b5d-4f20-89e5-0a5d13a9028d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Gender',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '67c2fe30-fe2e-4744-9b7e-d26c7f159d4f',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '9532d0b9-b8ca-4a4f-bab0-bcc49a4a9b18',
          'uuid' => '9532d0b9-b8ca-4a4f-bab0-bcc49a4a9b18',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670215,
          'entity_uuid' => '67c2fe30-fe2e-4744-9b7e-d26c7f159d4f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => 'Leadership',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'leadership',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Лидерство',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Lederskab',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Führung',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Leadership',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Liderazgo',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Leadership',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '68307727-0256-4b98-b8f1-3c63b155a3b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Temporary workers',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '68e39593-c07f-4c57-87f8-532b49bcf8ce',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669839,
          'entity_uuid' => '68e39593-c07f-4c57-87f8-532b49bcf8ce',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => '5.2. Other networking knowledge actions',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '68ed2a83-8327-4c9a-9a1d-c77cf9860cde',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'networking_knowledge_2',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '5.2. Other networking knowledge actions',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '68ed2a83-8327-4c9a-9a1d-c77cf9860cde',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '341c68a0-184a-4c11-8789-178251c02872',
    ),
  );
  $terms[] = array(
    'name' => 'Statistics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '6ca2f8a4-cb84-4006-8744-c8cb4c5f393e',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668443,
          'entity_uuid' => '6ca2f8a4-cb84-4006-8744-c8cb4c5f393e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '4f931fb7-8258-4da9-9226-b26ffe706e24',
    ),
  );
  $terms[] = array(
    'name' => 'Section',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '6ccf7187-42f8-4813-bf55-b5b3d218dc37',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'article_types',
    'field_article_type_code' => array(
      'und' => array(
        0 => array(
          'value' => 'section',
          'format' => NULL,
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411244110,
          'entity_uuid' => '6ccf7187-42f8-4813-bf55-b5b3d218dc37',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '6: Networking and Corporate Communications',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6d67c342-6a54-409f-a512-9796ab5d2fc0',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'networking_and_corporate_communications',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '6: Networking and Corporate Communications',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '6d67c342-6a54-409f-a512-9796ab5d2fc0',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Social Dialogue',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6e104d4b-46b5-41c7-b2b0-60d61de0fe85',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668436,
          'entity_uuid' => '6e104d4b-46b5-41c7-b2b0-60d61de0fe85',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '4f931fb7-8258-4da9-9226-b26ffe706e24',
    ),
  );
  $terms[] = array(
    'name' => 'Disabled persons',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6eaee36d-0b50-4ab5-a291-958d9f69b3ed',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669811,
          'entity_uuid' => '6eaee36d-0b50-4ab5-a291-958d9f69b3ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => 'Work arrangements',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6eb37f0a-4e15-426a-8a9c-34a158b24424',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669377,
          'entity_uuid' => '6eb37f0a-4e15-426a-8a9c-34a158b24424',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '974895cc-177f-4d46-82c6-63a7d309b716',
    ),
  );
  $terms[] = array(
    'name' => 'Machinery and work equipment',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '717e3179-b662-42ad-82e0-84944f34d266',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669270,
          'entity_uuid' => '717e3179-b662-42ad-82e0-84944f34d266',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Sectors and occupations',
    'description' => '',
    'format' => 'full_html',
    'weight' => 10,
    'uuid' => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668228,
          'entity_uuid' => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mental Health',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '724a67c7-423a-4164-a031-b685f6ab1b91',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670483,
          'entity_uuid' => '724a67c7-423a-4164-a031-b685f6ab1b91',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    ),
  );
  $terms[] = array(
    'name' => '5.1 OSHwiki',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '724a92e2-016d-4611-bebc-11f3b09eaf64',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'networking_knowledge_1',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '5.1 OSHwiki',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '724a92e2-016d-4611-bebc-11f3b09eaf64',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '341c68a0-184a-4c11-8789-178251c02872',
    ),
  );
  $terms[] = array(
    'name' => '2.3. OSH overview: Micro and small enterprises',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '745eb89c-b6a3-455e-94ae-3244e10df1e9',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'facts_and_figures_3',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '2.3. OSH overview: Micro and small enterprises',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '745eb89c-b6a3-455e-94ae-3244e10df1e9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'e9fa57e4-b0c3-476b-898c-176ae24d6062',
    ),
  );
  $terms[] = array(
    'name' => 'Prevention measures',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '76890600-3073-44e6-bff0-8056c1030824',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668762,
          'entity_uuid' => '76890600-3073-44e6-bff0-8056c1030824',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => '3.2. Tool for implementing OSH solutions',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '777ac578-5ecf-4c08-bf2f-72ebe7b14871',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'tools_for_osh_management_2',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '3.2. Tool for implementing OSH solutions',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '777ac578-5ecf-4c08-bf2f-72ebe7b14871',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '08e11f8b-4122-4e6e-83cb-2e0b3c06d082',
    ),
  );
  $terms[] = array(
    'name' => 'Lighting',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '7803ae00-5844-45ae-afea-40431615d5c9',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669063,
          'entity_uuid' => '7803ae00-5844-45ae-afea-40431615d5c9',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '8f36d40f-4400-432c-9067-2b5836ec2717',
    ),
  );
  $terms[] = array(
    'name' => 'Psychosocial risks and stress',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'psychosocial_risks_and_stress',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Психосоциални рискове и стрес на работното място',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Stres a psychosociální rizika',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Stress og psykosociale risici',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Stress und psychosoziale Risiken',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Άγχος και ψυχοκοινωνικοί κίνδυνοι',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Psychosocial risks and stress',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Estrés y riesgos psicosociales',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Stress ja psühhosotsiaalsed riskid',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Stressi ja psykososiaaliset riskit',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Risques psychosociaux et stress',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Psihosocijalni rizici i stres',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Pszichoszociális kockázatok és stressz',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Sálfélagslegar áhættur og streita',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Stress e rischi psicosociali',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Stresas ir psichosocialinė rizika',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Stress and psihosociālā riska veidi',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Stress u riskji psikoloġiċi',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Stress en psychosociale risico’s',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Psykososiale risikoer og stress',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Stres i zagrożenia psychospołeczne',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Stress e riscos psicossociais',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Stresul şi riscurile psihosociale',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Stres a psychosociálne riziká',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Stres in psihosocialna tveganja',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Stress och psykosociala risker',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Identifying new and emerging risks',
    'description' => '',
    'format' => 'full_html',
    'weight' => 4,
    'uuid' => '7c841af9-9860-4e22-9ca9-f4a033403457',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '3c5a05a7-9569-42e1-9afa-8fcc3e539ca0',
          'uuid' => '3c5a05a7-9569-42e1-9afa-8fcc3e539ca0',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674433,
          'entity_uuid' => '7c841af9-9860-4e22-9ca9-f4a033403457',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '4f931fb7-8258-4da9-9226-b26ffe706e24',
    ),
  );
  $terms[] = array(
    'name' => 'Employment status',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '7ca44f05-ac4a-430e-8ab9-382036976f5f',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669362,
          'entity_uuid' => '7ca44f05-ac4a-430e-8ab9-382036976f5f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '974895cc-177f-4d46-82c6-63a7d309b716',
    ),
  );
  $terms[] = array(
    'name' => '2.2. OSH overview: Older workers',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7df1e54d-8ab2-45f8-a8db-def8330ece19',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'facts_and_figures_2',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '2.2. OSH overview: Older workers',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '7df1e54d-8ab2-45f8-a8db-def8330ece19',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'e9fa57e4-b0c3-476b-898c-176ae24d6062',
    ),
  );
  $terms[] = array(
    'name' => '3.1. Online interactive Risk Assessment (OiRA) tool',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7f6e2e39-911c-4f0c-88fc-8eb42dc8f370',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'tools_for_osh_management_1',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '3.1. Online interactive Risk Assessment (OiRA) tool',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '7f6e2e39-911c-4f0c-88fc-8eb42dc8f370',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '08e11f8b-4122-4e6e-83cb-2e0b3c06d082',
    ),
  );
  $terms[] = array(
    'name' => 'Worker Participation',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'worker_participation',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Участие на работниците',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Účast zaměstnanců',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Medarbejderdeltagelse',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Arbeitnehmerbeteiligung',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Συμμετοχή των εργαζομένων',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Worker Participation',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Participación de los trabajadores',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Töötajate osalemine',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Työntekijöiden osallistuminen',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Participation des travailleurs',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Dolgozói részvétel',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Þátttaka starfsmanna',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Partecipazione dei lavoratori',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Darbuotojų dalyvavimas',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Darba ņēmēju dalība',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Parteċipazzjoni tal-ħaddiema',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Werknemersparticipatie',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Medarbeiderdeltakelse',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Udział pracowników',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Participação dos trabalhadores',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Participarea lucrătorilor',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Účasť zamestnancov',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Soodločanje delavcev',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Arbetstagarnas medverkan',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '8205dae4-a004-4cd1-acab-c601e5a4a6bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Hotels, restaurants and catering',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '828fa764-366a-474d-b4fc-e8834cadaabf',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669732,
          'entity_uuid' => '828fa764-366a-474d-b4fc-e8834cadaabf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Indoor air quality',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '82fe247b-13fc-4a22-ae08-95c228842aa2',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674755,
          'entity_uuid' => '82fe247b-13fc-4a22-ae08-95c228842aa2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => 'Health Care',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'health_care',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Здравеопазване',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Zdravotní péče',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Sundhedspleje',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Gesundheitsfürsorge',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Υγειονομική περίθαλψη',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Health Care',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Atención sanitaria',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Tervishoid',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Terveydenhuolto',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Soins de santé',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Health Care',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Egészségügy',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Heilsugæsla',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Sanità',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Sveikatos priežiūra',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Veselības aprūpe',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Il-kura tas-saħħa',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Gezondheidszorg',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Helse og omsorg',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Opieka zdrowotna',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Cuidados de saúde',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Sănătate',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Zdravotnícka starostlivosť',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Zdravstveno varstvo',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Hälsovård',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84a1bd37-d7af-4d5f-9c14-bb25e3d0d28c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Migrant workers',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'migrant_workers',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Работници мигранти',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Migrující pracovníci',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Vandrende arbejdstagere',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Wanderarbeitnehmer',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Διακινούμενοι εργαζόμενοι',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Migrant workers',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Trabajadores emigrantes',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Võõrtöötajad',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Siirtotyöläiset',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Travailleurs migrants',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Migrant workers',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Bevándorló munkavállalók',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Farandverkafólk',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Lavoratori migranti',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Darbuotojai migrantai',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Migrējošie darba ņēmēji',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Ħaddiema migranti',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Migrerende werknemers',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Vandrearbeidere',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Pracownicy migrujący',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Trabalhadores migrantes',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Lucrători migranţi',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Migrujúci pracovníci',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Delavci migranti',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Gästarbetare',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '84db267f-3929-401c-8bb9-492c256d5242',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Health, screening and surveillance',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '8618a480-41d9-475c-a78d-5b16b778b2f6',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669579,
          'entity_uuid' => '8618a480-41d9-475c-a78d-5b16b778b2f6',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '6438f9a5-8a5d-417b-b20e-ffea262b0999',
    ),
  );
  $terms[] = array(
    'name' => 'Emergency workers',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '871c53d5-962d-4630-be5f-ee0193168c67',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669719,
          'entity_uuid' => '871c53d5-962d-4630-be5f-ee0193168c67',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Musculoskeletal disorders',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '88a0f3c3-a3bf-40b2-a605-6de78effce85',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670126,
          'entity_uuid' => '88a0f3c3-a3bf-40b2-a605-6de78effce85',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => '6.2. Operational Networking',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8b9e5d84-e921-4b97-9ffe-04a509ca2d8f',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'networking_and_corporate_communications_2',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '6.2. Operational Networking',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '8b9e5d84-e921-4b97-9ffe-04a509ca2d8f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '6d67c342-6a54-409f-a512-9796ab5d2fc0',
    ),
  );
  $terms[] = array(
    'name' => '4.1. Healthy Workplace Campaign (HWC): Working together for risk prevention',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8f1f0efc-a820-4e0a-858f-0abefa0a78ab',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'raising_awareness_1',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '4.1. Healthy Workplace Campaign (HWC): Working together for risk prevention',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '8f1f0efc-a820-4e0a-858f-0abefa0a78ab',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '57c7ff22-5cd8-49c4-8789-262d2a3453bd',
    ),
  );
  $terms[] = array(
    'name' => 'Physical agents',
    'description' => '',
    'format' => 'full_html',
    'weight' => 4,
    'uuid' => '8f36d40f-4400-432c-9067-2b5836ec2717',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411667942,
          'entity_uuid' => '8f36d40f-4400-432c-9067-2b5836ec2717',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Self-employed',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '900391f9-632b-4492-af03-caaac33a3309',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669833,
          'entity_uuid' => '900391f9-632b-4492-af03-caaac33a3309',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => 'Mainstreaming OSH into education',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'mainstreaming_osh_into_education',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Включване на БЗУТ в образованието',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Zaměření BOZP na vzdělávání',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Integration af arbejdsmiljø i uddannelse',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Einbeziehung des Themas Sicherheit und Gesundheitsschutz bei der Arbeit in die Bildung',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Ένταξη της Επαγγελματικής Ασφάλειας & Υγείας στην εκπαίδευση',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Mainstreaming OSH into education',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Integración de la SST en la educación',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Tööohutuse ja töötervishoiu süvalaiendamine hariduses',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'TTT-asiat osaksi koulusta',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'La SST et l\'éducation',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'A munkavédelem beépítése az oktatásba',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Integrazione della SSL nell’istruzione',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'OSH įtraukimas į švietimą',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'DDV popularizēšana izglītībā',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'L-implimentazzjoni tal-OHS fl-Edukazzjoni',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Het integreren van veiligheid en gezondheid op het werk in het onderwijs',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Włączanie BHP do głównego nurtu kształcenia',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Investigação',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Integrarea SSM în educaţie',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Prenikanie BOZP do vzdelania',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Vključevanje varnosti in zdravja pri delu v izboraževanje',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Integrera arbetsmiljön i utbildningen',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '94d0e9f0-9722-4cce-b0ff-5a570dcb414f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Women and OSH',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9532d0b9-b8ca-4a4f-bab0-bcc49a4a9b18',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'women_and_osh',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Women and OSH',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9532d0b9-b8ca-4a4f-bab0-bcc49a4a9b18',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Work organisation',
    'description' => '',
    'format' => 'full_html',
    'weight' => 7,
    'uuid' => '974895cc-177f-4d46-82c6-63a7d309b716',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668184,
          'entity_uuid' => '974895cc-177f-4d46-82c6-63a7d309b716',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '1.1. Foresight of new and emerging OSH risks  associated with new technologies in green jobs',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '981044b4-313e-494c-abab-40e139c26244',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'anticipating_change_1',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '1.1. Foresight of new and emerging OSH risks  associated with new technologies in green jobs',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '981044b4-313e-494c-abab-40e139c26244',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '00cf9383-d3f2-4220-a8a2-42a0d4b4a33b',
    ),
  );
  $terms[] = array(
    'name' => '4.4. Awareness raising actions',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9a44b23c-2e25-4133-a5a6-200e85a2f3a3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'raising_awareness_4',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '4.4. Awareness raising actions',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => '9a44b23c-2e25-4133-a5a6-200e85a2f3a3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '57c7ff22-5cd8-49c4-8789-262d2a3453bd',
    ),
  );
  $terms[] = array(
    'name' => 'Napo',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'publication',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'napo',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Напо',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Napo',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => '9c242673-d19b-4b53-8567-fd6e613f5f44',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Risk management for dangerous substances',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'a0d1c7d8-4f6a-480d-821f-658312cde646',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674919,
          'entity_uuid' => 'a0d1c7d8-4f6a-480d-821f-658312cde646',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => 'Migrant workers',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'a1aafd52-91b3-4530-96d5-f2188d794c98',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669827,
          'entity_uuid' => 'a1aafd52-91b3-4530-96d5-f2188d794c98',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => 'Health services',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'a213ea46-37b7-4ec6-9edb-0f4b764b97b7',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669725,
          'entity_uuid' => 'a213ea46-37b7-4ec6-9edb-0f4b764b97b7',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Workplace Health Promotion',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'workplace_health_promotion',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Насърчаване на здравето на работното място',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Podpora ochrany zdraví na pracovišti',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Fremme af sundheden på arbejdspladsen',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Betriebliche Gesundheitsförderung',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Προαγωγή της υγείας στον χώρο εργασίας',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Workplace Health Promotion',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Fomento de la Salud en el Trabajo',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Töötervise edendamine',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Terveyden edistäminen työpaikoilla',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Promotion de la santé sur le lieu de travail',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Munkahelyi egészségfejlesztés',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Heilsuefling á vinnustað',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Promozione della salute nei luoghi di lavoro',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Skatinimas kurti sveikas darbo vietas',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Veselības veicināšana darbavietā',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Il-Promozzjoni tas-Saħħa fuq il-Post tax-Xogħol',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Bevordering van gezondheid op het werk',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Helsefremmende arbeidsplasser',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Promowanie zdrowych miejsc pracy',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Promoção da saúde no local de trabalho',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Promovarea sănătăţii la locul de muncă',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Podpora ochrany zdravia na pracovisku',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Spodbujanje zdravja na delovnem mestu',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Hälsofrämjande insatser på arbetsplatsen',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a3e45cb1-4f6e-47a3-9acc-6e0def05f4dc',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => '7.3. Human Resources',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a45acdc6-c5cd-4590-bd0a-145a80e204e4',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'governance_2',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '7.3. Human Resources',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'a45acdc6-c5cd-4590-bd0a-145a80e204e4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'f77ff1e1-cccc-4f56-b470-ad638467b135',
    ),
  );
  $terms[] = array(
    'name' => 'Campaign 2014-2015',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'publication',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'campaign_2014_2015',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Кампания 2014 - 2015 г.',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Kampaň 2014–2015',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Kampagne 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Kampagne 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Εκστρατεία 2014-2015',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Campaign 2014-2015',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Campaña 2014 -2015',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Kampaania 2014–2015',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Vuosien 2014 - 2015 kampanja',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Campagne 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Kampanja 2014. – 2015.',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => '2014-2015. évi kampány',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Herferð 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Campagna 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => '2014–2015 m. kampanija',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Kampaņa 2014 – 2015',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Kampanja 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Campagne 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Kampanje 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Europejska Kampania 2014-2015',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Campanha 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Campania 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Kampaň 2014 – 2015',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Kampanja 2014 - 2015',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Kampanj 2014–2015',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Microenterprises',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a5c13f57-77aa-4874-9afd-f182456ab8ee',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'microenterprises',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Microenterprises',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Microempresas',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Microenterprises',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Microîntreprinderi',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a5c13f57-77aa-4874-9afd-f182456ab8ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a5c13f57-77aa-4874-9afd-f182456ab8ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a5c13f57-77aa-4874-9afd-f182456ab8ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'a5c13f57-77aa-4874-9afd-f182456ab8ee',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Noise',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'a8eada5f-3531-46f9-80d9-c067ae4ff07f',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669068,
          'entity_uuid' => 'a8eada5f-3531-46f9-80d9-c067ae4ff07f',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '8f36d40f-4400-432c-9067-2b5836ec2717',
    ),
  );
  $terms[] = array(
    'name' => 'Physical ergonomics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'aa56c0a4-20d8-4702-9803-5e1d30fad214',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669192,
          'entity_uuid' => 'aa56c0a4-20d8-4702-9803-5e1d30fad214',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => 'Ergonomics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 5,
    'uuid' => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411667952,
          'entity_uuid' => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Dangerous substances (chemical and biological)',
    'description' => '',
    'format' => 'full_html',
    'weight' => 3,
    'uuid' => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674538,
          'entity_uuid' => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '4.2. Healthy Workplace Campaign (HWC): Healthy Workplaces manage stress',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'abecc2cf-c60c-4be6-8d3d-10d03d051feb',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'raising_awareness_2',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '4.2. Healthy Workplace Campaign (HWC): Healthy Workplaces manage stress',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'abecc2cf-c60c-4be6-8d3d-10d03d051feb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '57c7ff22-5cd8-49c4-8789-262d2a3453bd',
    ),
  );
  $terms[] = array(
    'name' => 'Work ability',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'af036f1b-97e5-4383-a9c6-c949827a12b3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668779,
          'entity_uuid' => 'af036f1b-97e5-4383-a9c6-c949827a12b3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => 'Agriculture',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'af3301ae-2904-45a6-9a84-a8319991777e',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669699,
          'entity_uuid' => 'af3301ae-2904-45a6-9a84-a8319991777e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Contractors',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'b18d852b-d042-46cf-a197-9e79f9a7539c',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669805,
          'entity_uuid' => 'b18d852b-d042-46cf-a197-9e79f9a7539c',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => '2.4. OSH overview : Work-related diseases',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b26d842e-3a43-4f77-a2cc-0d2df9412e29',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'facts_and_figures_4',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '2.4. OSH overview : Work-related diseases',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'b26d842e-3a43-4f77-a2cc-0d2df9412e29',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'e9fa57e4-b0c3-476b-898c-176ae24d6062',
    ),
  );
  $terms[] = array(
    'name' => 'Psychosocial risk factors',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'b3a8f8d4-5128-44b1-a3ee-80541c85f590',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670493,
          'entity_uuid' => 'b3a8f8d4-5128-44b1-a3ee-80541c85f590',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    ),
  );
  $terms[] = array(
    'name' => 'HORECA',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'horeca',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'ХОРЕКА',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'HORECA',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'b3f4cde5-9c8c-4532-978b-a204c01a15b2',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Irritants and allergens',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'b63831f6-2840-4e91-9124-4b124c557a60',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674759,
          'entity_uuid' => 'b63831f6-2840-4e91-9124-4b124c557a60',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => 'Violence',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'b8997d19-4cc6-43fc-a858-feba998129a3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670498,
          'entity_uuid' => 'b8997d19-4cc6-43fc-a858-feba998129a3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    ),
  );
  $terms[] = array(
    'name' => 'Personal Protective Equipment',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'ba57795a-3025-4c17-83e2-45a06fad81a5',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668757,
          'entity_uuid' => 'ba57795a-3025-4c17-83e2-45a06fad81a5',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => 'Corporate Social Responsibility',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'bb0668c0-47be-4b65-adc4-e7faba504705',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668636,
          'entity_uuid' => 'bb0668c0-47be-4b65-adc4-e7faba504705',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    ),
  );
  $terms[] = array(
    'name' => 'Statistics',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'statistics',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Статистика',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Statistika',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Statistik',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Statistik',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Στατιστικά στοιχεία',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Statistics',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Estadísticas',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Statistika',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Tilastot',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Statistiques',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Statisztikák',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Statistiche',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Statistika',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Statistika',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Statistiċi',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Statistiek',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Statystyka',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Estatísticas',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Statistici',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Štatistiky',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Statistika',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Statistik',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bbc824c8-e39a-4d99-9143-78363d49a89d',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Occupational exposure limit values',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'bcf85bb1-723f-45c1-8eda-0145f7c9aba4',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674897,
          'entity_uuid' => 'bcf85bb1-723f-45c1-8eda-0145f7c9aba4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => 'Human errors',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'bd88ba24-84b4-4ec3-8117-87f50e5dca4e',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669178,
          'entity_uuid' => 'bd88ba24-84b4-4ec3-8117-87f50e5dca4e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => 'Construction',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'construction',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Bygge- og anlægssektoren',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Hoch- und Tiefbau',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Construcción',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Ehitussektor',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Építés',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Edilizia',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Statyba',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Būvniecība',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Kostruzzjoni',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Construction',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'bdccd06a-1c16-462c-8ba9-52e7c61e2b15',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Health and well-being',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'be1c3522-f3cd-4012-8580-0c6f36f4d727',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669573,
          'entity_uuid' => 'be1c3522-f3cd-4012-8580-0c6f36f4d727',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '6438f9a5-8a5d-417b-b20e-ffea262b0999',
    ),
  );
  $terms[] = array(
    'name' => 'Education',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'be8cce66-29c3-4a73-95e7-beef273795e4',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '76890600-3073-44e6-bff0-8056c1030824',
          'uuid' => '76890600-3073-44e6-bff0-8056c1030824',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674973,
          'entity_uuid' => 'be8cce66-29c3-4a73-95e7-beef273795e4',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '71f8013e-dc42-4f02-beef-80ce70d2b1a1',
    ),
  );
  $terms[] = array(
    'name' => 'Indoor climate',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'c17b9082-60ef-4a49-bf70-72121ed89f2b',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669058,
          'entity_uuid' => 'c17b9082-60ef-4a49-bf70-72121ed89f2b',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '8f36d40f-4400-432c-9067-2b5836ec2717',
    ),
  );
  $terms[] = array(
    'name' => 'Packaging and labeling',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'c2314819-3035-4e7d-839d-be7b1823c1ff',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674124,
          'entity_uuid' => 'c2314819-3035-4e7d-839d-be7b1823c1ff',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => '6.3. Corporate Communications',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c2c4838f-f565-49d0-8318-d2ad08add644',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'networking_and_corporate_communications_3',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '6.3. Corporate Communications',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'c2c4838f-f565-49d0-8318-d2ad08add644',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '6d67c342-6a54-409f-a512-9796ab5d2fc0',
    ),
  );
  $terms[] = array(
    'name' => 'Biological agents',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'c70519b6-c32b-47e6-b5d9-6018f8e64b61',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674543,
          'entity_uuid' => 'c70519b6-c32b-47e6-b5d9-6018f8e64b61',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => 'Communication',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'c8f0562c-f230-4d28-801e-e4a167bb8aef',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668739,
          'entity_uuid' => 'c8f0562c-f230-4d28-801e-e4a167bb8aef',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => 'What\'s OSH',
    'description' => '',
    'format' => 'full_html',
    'weight' => 5,
    'uuid' => 'c9be5bcd-3459-492e-afa6-52bdd8dd6213',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668451,
          'entity_uuid' => 'c9be5bcd-3459-492e-afa6-52bdd8dd6213',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '4f931fb7-8258-4da9-9226-b26ffe706e24',
    ),
  );
  $terms[] = array(
    'name' => '4.3. Healthy Workplace Campaign (HWC): 2016-17',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cafceb2e-0be4-4e47-ad9a-781b708f58e6',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'raising_awareness_3',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '4.3. Healthy Workplace Campaign (HWC): 2016-17',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'cafceb2e-0be4-4e47-ad9a-781b708f58e6',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '57c7ff22-5cd8-49c4-8789-262d2a3453bd',
    ),
  );
  $terms[] = array(
    'name' => 'Agriculture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'agriculture',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Zemědělství',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Landbrug',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Landwirtschaft',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Γεωργία',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Agricultura',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Põllumajandus',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Maatalous',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Mezőgazdaság',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Agricoltura',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Žemės ūkis',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Lauksaimniecība',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Agrikoltura',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Landbouw',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Rolnictwo',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Agricultura',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Agricultură',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Poľnohospodárstvo',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Kmetijstvo',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Jordbruk',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'cc1b6782-3780-441b-abc7-02ecb46218fa',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Expectant mothers',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'ce58a3de-8efe-4fe7-9800-7e3008cc766a',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669817,
          'entity_uuid' => 'ce58a3de-8efe-4fe7-9800-7e3008cc766a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    ),
  );
  $terms[] = array(
    'name' => '6.1. Strategic Networking',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd38c0d0c-fd42-4b0c-ab9d-02cb0e66d6e5',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'networking_and_corporate_communications_1',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '6.1. Strategic Networking',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'd38c0d0c-fd42-4b0c-ab9d-02cb0e66d6e5',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '6d67c342-6a54-409f-a512-9796ab5d2fc0',
    ),
  );
  $terms[] = array(
    'name' => 'Harassment',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'd6cb3a4d-3551-42fa-a202-e07a1cb39bc5',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670477,
          'entity_uuid' => 'd6cb3a4d-3551-42fa-a202-e07a1cb39bc5',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    ),
  );
  $terms[] = array(
    'name' => '8: Operational Management and Support',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd84eb437-a202-4c8b-84c8-537ad1d2c5f5',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'operational_management_and_support',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '8: Operational Management and Support',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'd84eb437-a202-4c8b-84c8-537ad1d2c5f5',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Cognitive ergonomics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'd892d9b5-c17f-4e0a-bd14-52683d43a0ae',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669157,
          'entity_uuid' => 'd892d9b5-c17f-4e0a-bd14-52683d43a0ae',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aa8f1f07-57ac-4b6d-940c-5e53b96826e8',
    ),
  );
  $terms[] = array(
    'name' => 'Work-related stress management',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'd8cc7ad1-e71b-4c15-b912-d7c9951aac13',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670508,
          'entity_uuid' => 'd8cc7ad1-e71b-4c15-b912-d7c9951aac13',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    ),
  );
  $terms[] = array(
    'name' => 'Prevention and control strategies',
    'description' => '',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411667922,
          'entity_uuid' => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '1.2. Large-scale foresight',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e1e5ddc6-1c79-4bf9-8e4a-2f83b12483ef',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'anticipating_change_2',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '1.2. Large-scale foresight',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'e1e5ddc6-1c79-4bf9-8e4a-2f83b12483ef',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => '00cf9383-d3f2-4220-a8a2-42a0d4b4a33b',
    ),
  );
  $terms[] = array(
    'name' => 'OSH Management and organisation',
    'description' => '',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411667908,
          'entity_uuid' => 'e268a4d0-9874-487e-8899-1d6d354bc720',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Accidents and incidents',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'e37a03ec-73a5-40da-b6da-efadfc8d5d8e',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669259,
          'entity_uuid' => 'e37a03ec-73a5-40da-b6da-efadfc8d5d8e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Ageing and OSH',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e424b19c-5dc8-474a-a787-c80debb3b8bb',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ageing_and_osh',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Ageing and OSH',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'e424b19c-5dc8-474a-a787-c80debb3b8bb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Working on height',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'e55c95b1-6f43-4892-b1f9-471afda213d3',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669293,
          'entity_uuid' => 'e55c95b1-6f43-4892-b1f9-471afda213d3',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Carcinogenic, mutagenic, reprotoxic (CMR) substances',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'e57fcd12-848b-442e-8a5f-1cc4183d61a6',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
          'uuid' => '123af0ff-7a0b-42a9-b0c3-de32c80522fb',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411674550,
          'entity_uuid' => 'e57fcd12-848b-442e-8a5f-1cc4183d61a6',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'aac24ed1-6221-4ae3-88ac-e6ff1629c036',
    ),
  );
  $terms[] = array(
    'name' => '2: Facts and figures',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e9fa57e4-b0c3-476b-898c-176ae24d6062',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'facts_and_figures',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '2: Facts and figures',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'e9fa57e4-b0c3-476b-898c-176ae24d6062',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Fire and explosion',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'ed0fcaa9-c16a-4bfd-a879-acca82d51059',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669265,
          'entity_uuid' => 'ed0fcaa9-c16a-4bfd-a879-acca82d51059',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Noise',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(
      'und' => array(
        0 => array(
          'value' => 'article',
        ),
        1 => array(
          'value' => 'page',
        ),
        2 => array(
          'value' => 'blog',
        ),
        3 => array(
          'value' => 'highlight',
        ),
        4 => array(
          'value' => 'job_vacancies',
        ),
        5 => array(
          'value' => 'news',
        ),
        6 => array(
          'value' => 'press_release',
        ),
      ),
    ),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'noise',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'cs' => array(
        0 => array(
          'value' => 'Hluk při práci',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Støj på arbejdspladsen',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Lärm bei der Arbeit',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Θόρυβος στην εργασία',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Noise',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'El ruido en el trabajo',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Müra töökohal',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Työperäinen melu',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Le bruit au travail',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Munkahelyi zaj',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Noise',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Rumore nei luoghi di lavoro',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Triukšmas darbe',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Troksnis darbā',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Storbju fuq ix-xogħol',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Lawaai op het werk',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Hałas w miejscu pracy',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Ruído no trabalho',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Zgomot',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Hluk pri práci',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Hrup pri delu',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Buller på arbetet',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'ee02a481-7613-4269-9f0d-e3aa27a6b6ed',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Discrimination',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'ef440e9c-a0c0-439d-bae8-20e2029f9755',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670466,
          'entity_uuid' => 'ef440e9c-a0c0-439d-bae8-20e2029f9755',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    ),
  );
  $terms[] = array(
    'name' => 'Musculoskeletal disorders',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'musculoskeletal_disorders',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Мускулно-скелетни смущения',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Muskuloskeletální poruchy',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Muskel- og skeletbesvær',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Muskel- und Skeletterkrankungen',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Μυοσκελετικές παθήσει',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Musculoskeletal disorders',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Trastornos musculoesqueléticos',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Luu- ja lihaskonna vaevused',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Tuki- ja liikuntaelinsairaudet',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'Troubles musculo-squelettiques',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'A váz- és izomrendszeri megbetegedések',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Disturbi muscoloscheletrici',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Kaulų ir raumenų sistemos pažeidimai',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'Balsta un kustību aparāta slimības',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'Problemi muskuloskeletali',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Aandoeningen aan het bewegingsapparaat',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Choroby układu mięśniowo-szkieletowego',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Perturbações músculo-esqueléticas',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Afecţiunile aparatului locomotor',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Poškodenia podporno-pohybovej sústavy',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Mišično-kostna obolenja',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Belastningsbesvär',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'f11d06a6-e3d1-4e7d-ae06-a4a4ea9c388a',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Radiation',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'f233f664-6a3f-41c3-a861-2a3df768cd2e',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669072,
          'entity_uuid' => 'f233f664-6a3f-41c3-a861-2a3df768cd2e',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '8f36d40f-4400-432c-9067-2b5836ec2717',
    ),
  );
  $terms[] = array(
    'name' => 'OSH Culture',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'f482f22e-9944-4310-aec1-e7615140be82',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668659,
          'entity_uuid' => 'f482f22e-9944-4310-aec1-e7615140be82',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    ),
  );
  $terms[] = array(
    'name' => '7: Governance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f77ff1e1-cccc-4f56-b470-ad638467b135',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'governance',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '7: Governance',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'f77ff1e1-cccc-4f56-b470-ad638467b135',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Maintenance',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'f7a0a2a0-753b-4562-b757-c5337d069a46',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669275,
          'entity_uuid' => 'f7a0a2a0-753b-4562-b757-c5337d069a46',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '639aa2d8-9b19-4103-9602-c8baea1a3551',
    ),
  );
  $terms[] = array(
    'name' => 'Groups at risk',
    'description' => '',
    'format' => 'full_html',
    'weight' => 11,
    'uuid' => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668237,
          'entity_uuid' => 'f9ae2eca-8f7c-4435-a3e1-143430592af0',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Emergency planning',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'fa9b716e-de10-4338-8076-6ed468b43042',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411668751,
          'entity_uuid' => 'fa9b716e-de10-4338-8076-6ed468b43042',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'dc31454a-dff4-49b9-a52c-2baa781874cd',
    ),
  );
  $terms[] = array(
    'name' => 'Economic aspects',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'fceffe36-fbe5-4267-a3f0-f831c6343c70',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01'
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411669982,
          'entity_uuid' => 'fceffe36-fbe5-4267-a3f0-f831c6343c70',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => 'e268a4d0-9874-487e-8899-1d6d354bc720',
    ),
  );
  $terms[] = array(
    'name' => 'Good OSH is good for business',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'tags',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_excluded_from' => array(),
    'field_tags_code' => array(
      'und' => array(
        0 => array(
          'value' => 'good_osh_is_good_for_business',
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'bg' => array(
        0 => array(
          'value' => 'Доброто управление на БЗР е добро за бизнеса',
          'format' => NULL,
        ),
      ),
      'cs' => array(
        0 => array(
          'value' => 'Dobrá BOZP je přínosem pro firmu',
          'format' => NULL,
        ),
      ),
      'da' => array(
        0 => array(
          'value' => 'Et godt arbejdsmiljø er godt for din virksomhed',
          'format' => NULL,
        ),
      ),
      'de' => array(
        0 => array(
          'value' => 'Gute Sicherheits- und Gesundheitsschutzmaßnahmen bei der Arbeit bedeuten geschäftlichen Erfolg',
          'format' => NULL,
        ),
      ),
      'el' => array(
        0 => array(
          'value' => 'Η καλή διαχείριση της ΕΑΥ είναι επωφελής για τις επιχειρήσεις',
          'format' => NULL,
        ),
      ),
      'en' => array(
        0 => array(
          'value' => 'Good OSH is good for business',
          'format' => NULL,
        ),
      ),
      'es' => array(
        0 => array(
          'value' => 'Una buena SST es un buen negocio',
          'format' => NULL,
        ),
      ),
      'et' => array(
        0 => array(
          'value' => 'Hea tööohutus ja töötervishoid on hea äritegevusele',
          'format' => NULL,
        ),
      ),
      'fi' => array(
        0 => array(
          'value' => 'Hyvä työterveys ja työturvallisuus on yrityksen etu',
          'format' => NULL,
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => 'La sécurité et la santé au travail, un atout pour l\'entreprise',
          'format' => NULL,
        ),
      ),
      'hr' => array(
        0 => array(
          'value' => 'Dobar OSH (sigurnost i zdravlje na radu) dobar je za poslovanje',
          'format' => NULL,
        ),
      ),
      'hu' => array(
        0 => array(
          'value' => 'Dobar OSH (sigurnost i zdravlje na radu) dobar je za poslovanje',
          'format' => NULL,
        ),
      ),
      'is' => array(
        0 => array(
          'value' => 'Góð vinnuvernd er góð fyrir viðskiptin',
          'format' => NULL,
        ),
      ),
      'it' => array(
        0 => array(
          'value' => 'Una buona SSL è un vantaggio dal punto di vista economico',
          'format' => NULL,
        ),
      ),
      'lt' => array(
        0 => array(
          'value' => 'Gera darbuotojų sauga ir sveikata (DSS) yra naudinga verslui',
          'format' => NULL,
        ),
      ),
      'lv' => array(
        0 => array(
          'value' => 'DDVA nāk par labu uzņēmumam',
          'format' => NULL,
        ),
      ),
      'mt' => array(
        0 => array(
          'value' => 'OHS tajba hija tajba għan-negozju',
          'format' => NULL,
        ),
      ),
      'nl' => array(
        0 => array(
          'value' => 'Veiligheid en gezondheid op het werk is goed voor uw bedrijf',
          'format' => NULL,
        ),
      ),
      'no' => array(
        0 => array(
          'value' => 'God HMS-praksis er bra for bedriften',
          'format' => NULL,
        ),
      ),
      'pl' => array(
        0 => array(
          'value' => 'Wysoki poziom BHP opłaca się przedsiębiorstwom',
          'format' => NULL,
        ),
      ),
      'pt' => array(
        0 => array(
          'value' => 'Bons níveis de SST são um bom negócio',
          'format' => NULL,
        ),
      ),
      'ro' => array(
        0 => array(
          'value' => 'Securitatea şi sănătatea în muncă. În beneficiul companiilor',
          'format' => NULL,
        ),
      ),
      'sk' => array(
        0 => array(
          'value' => 'Dobrá bezpečnosť a ochrana zdravia pri práci je prínosom pre podniky',
          'format' => NULL,
        ),
      ),
      'sl' => array(
        0 => array(
          'value' => 'Dobrá bezpečnosť a ochrana zdravia pri práci je prínosom pre podniky',
          'format' => NULL,
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'En bra arbetsmiljö är bra för affärerna',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'lt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'lv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'lv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'mt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'mt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'nl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'nl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'no' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'no',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'pt' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'pt',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'ro' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'ro',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sk' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sk',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sl' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sl',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'sv',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'it' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'it',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'is' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'is',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hu' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hu',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'bg' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'bg',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'cs' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'cs',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'da' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'da',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'de' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'de',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'el' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'el',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'es' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'es',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'et' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'et',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fi',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'fr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'fr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
        'hr' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'hr',
          'source' => 'en',
          'status' => 1,
          'translate' => 0,
          'created' => 1411328866,
          'entity_uuid' => 'fd147cda-e7c1-4ce3-ba57-8cdae4c5bc01',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => '7.5. Documentation',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fdfcaba5-538e-42e1-aa7f-0e747e1766bb',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'activity',
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'plain_text',
          'safe_summary' => '',
        ),
      ),
    ),
    'field_activity_code' => array(
      'und' => array(
        0 => array(
          'value' => 'governance_3',
          'format' => NULL,
        ),
      ),
    ),
    'field_activity_level' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
        ),
      ),
    ),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => '7.5. Documentation',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1410866602,
          'entity_uuid' => 'fdfcaba5-538e-42e1-aa7f-0e747e1766bb',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'metatags' => array(),
    'parent' => array(
      0 => 'f77ff1e1-cccc-4f56-b470-ad638467b135',
    ),
  );
  $terms[] = array(
    'name' => 'Work-life balance',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'ffca7ebb-6749-41ac-9b21-aa369f0c6f53',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'wiki_categories',
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
          'uuid' => 'a4ae6370-5185-40d1-b6dd-fbcfe4f114bf',
        ),
        1 => array(
          'tid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
          'uuid' => '790cdad9-f8a9-4eb7-ba7d-df897e3e5500',
        ),
      ),
    ),
    'metatags' => array(),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1411670503,
          'entity_uuid' => 'ffca7ebb-6749-41ac-9b21-aa369f0c6f53',
          'user_uuid' => 'ad1178c7-e011-4d1a-a3db-eb14e3094dbe',
        ),
      ),
    ),
    'parent' => array(
      0 => '10adc82d-ce69-4ef8-bbeb-2794d7c383ab',
    ),
  );
  return $terms;
}
