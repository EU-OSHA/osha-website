<?php

/**
 * Class MigrateOshaNews migrates news.txt contents. The data
 * is stored inside the <em>News</em> content type.
 */
class MigrateOshaNews extends DynamicMigration {

    public function __construct($arguments) {
        parent::__construct();

        $this->description = 'Import "News" contents from CSV file';

        $arguments['file_name'] = isset($arguments['file_name']) ? $arguments['file_name'] : '';
        $file_name = $arguments['file_name'];
        $source_file = sprintf("%s/%s", drupal_get_path('module', 'osha_migration'), $file_name);

        $this->source = new MigrateSourceList(
            new NewsContentListCSV($source_file, array('title', 'description', 'text')),
            new NewsContentItemCSV(),
            $this->fields());

        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'id' => array(
                    'type' => 'varchar',
                    'length' => 200,
                    'not null' => TRUE,
                    'description' => 'News code'
                ),
            ),
            MigrateDestinationNode::getKeySchema()
        );

        $node_options = MigrateDestinationNode::options('en', 'text');
        $this->destination = new MigrateDestinationNode(CONTENT_TYPE_NEWS, $node_options);

        $this->addFieldMapping('field_news_image', 'image');
        $this->addFieldMapping('field_news_image:title', 'imageCaption');
        $this->addFieldMapping('field_news_image:file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);
        $this->addFieldmapping('field_news_image:preserve_files')->defaultValue(TRUE);
        $this->addFieldMapping('field_news_image:source_dir')->defaultValue(osha_migration_get_data_dir() . '/export/');

        $this->addFieldMapping('field_tags', 'subject')->separator(',');
        $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
        $this->addFieldMapping('field_thesaurus', 'multilingual_thesaurus')->separator(',');
        $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');
        $this->addFieldMapping('field_news_publication_date', 'publication_date');

        $this->addFieldMapping('path', 'id');
        $this->addFieldMapping('created', 'creation_date');
        $this->addFieldMapping('changed', 'modification_date');

        $this->addUnmigratedSources(array(
            'path',
            'language',
            'workflow_state',
            'creator',
            'country'
        ));

        $this->addUnmigratedDestinations(array(
            'uid',
            'promote',
            'status',
            'sticky',
            'revision',
            'log',
            'language',
            'tnid',
            'translate',
            'revision_uid',
            'is_new',
            'body:language',
            'field_news_image:file_class',
            'field_news_image:language',
            'field_news_image:destination_dir',
            'field_news_image:destination_file',
            'field_news_image:alt',
            'field_news_publication_date:timezone',
            'field_news_publication_date:rrule',
            'field_news_publication_date:to',
            'field_news_summary',
            'field_news_summary:format',
            'field_news_summary:language',
            'field_tags:create_term',
            'field_tags:ignore_case',
            'field_thesaurus:create_term',
            'field_thesaurus:ignore_case',
            'title_field',
            'title_field:language',
            'comment'
        ));
    }

    protected function generateMachineName($class_name = NULL) {
        return 'NewsContentType';
    }

    public function prepareRow($row) {
        $row->language = 'en';

        $tags = explode(', ', $this->news_map_categories($row->subject));
        $subcat = explode(', ', $this->news_map_categories($row->subcategory));
        $tags = array_unique(array_merge($tags, $subcat));

        $row->subject = $this->getTidsFromField('tags', 'field_tags_code', implode(', ', $tags));
        $row->multilingual_thesaurus = $this->getTidsFromField('thesaurus', 'field_thesaurus_code', $row->multilingual_thesaurus);

        return TRUE;
    }

    private function getTidsFromField($voc, $field, $data) {
        $dataArray = explode(', ', $data);
        $results = $this->news_get_tids($voc, $field, $dataArray);
        if (!empty($results)) {
            return implode(', ', $results);
        }
        return null;
    }

    public function prepare($entity, stdClass $row) {
        $migration = Migration::currentMigration();
        $entity_type = $migration->getDestination()->getEntityType();
        $translation_handler = entity_translation_get_handler($entity_type, $entity);
        $entity->translations = $translation_handler->getTranslations();
        $supported_languages = array_keys(language_list());
        $entity->title = $row->title->en;
        foreach ($supported_languages as $lang_code) {
            if (!empty($row->title->$lang_code)) {
                $entity->title_field[$lang_code][0]['value'] = $row->title->$lang_code;
                $entity->field_news_summary[$lang_code][0]['value'] = str_replace('<@#&>', '"', $row->description->$lang_code);
                $entity->field_news_summary[$lang_code][0]['format'] = 'full_html';
                $entity->body[$lang_code][0]['value'] = str_replace('<@#&>', '"', $row->text->$lang_code);
                $entity->body[$lang_code][0]['format'] = 'full_html';
                if ($lang_code != $row->language) { // Don't translate default language (en)
                    if (!isset($entity->translations->data[$lang_code])) {
                        $translation_handler->setTranslation(array(
                            'translate' => 0, 'status' => 1, 'uid' => 1,
                            'language' => $lang_code, 'source' => $row->language,
                            'created' => time(),
                        ));
                    }
                }
            }
        }
    }

    private function news_get_tids($vocabulary, $field_match, $termCodes) {
        static $cache = array();
        $ret = array();

        $newTerms = array();

        foreach($termCodes as $code) {
            if (strlen($code)) {
                $newTerms[] = $code;
            }
        }

        $termCodes = $newTerms;

        if (empty($cache[$vocabulary][$field_match])) {
            $voc = taxonomy_vocabulary_machine_name_load($vocabulary);
            $terms = taxonomy_get_tree($voc->vid, 0, NULL, TRUE);
            foreach ($terms as $term) {
                if (!empty($term->$field_match)) {
                    $field = $term->$field_match;
                    $cache[$vocabulary][$field_match][$field['und'][0]['value']] = $term->tid;
                }
            }
        }

        if (!empty($cache[$vocabulary][$field_match])) {
            foreach ($termCodes as $t) {
                if (!empty($cache[$vocabulary][$field_match][$t])) {
                    $ret[] = $cache[$vocabulary][$field_match][$t];
                }
            }
        }

        if (count($ret) != count($termCodes)) {
            drupal_set_message(sprintf('Invalid tags [%s] => [%s]', implode(', ', $termCodes), implode(', ', $ret)), 'warning');
        }

        return $ret;
    }

    private function news_map_categories($categories) {
        $categories = explode(', ', $categories);

        $new_categories = array();
        foreach ($categories as $cat) {
            if ($cat == 'young_people::educators_mainstreaming') {
                $new_categories[] = 'mainstreaming_osh_into_education';
            }
            elseif (count(explode('::', $cat)) == 2) {
                $exp = explode('::', $cat);
                $new_categories[] = $exp[0];
            } else {
                $new_categories[] = $cat;
            }
        }

        $categories = $new_categories;

        $replace = array(
            'accident_prevention' => 'accident_prevention',
            'ageing' => 'ageing_and_osh',
            'businessOSH' => 'good_osh_is_good_for_business',
            'campaign_2014_15' => 'campaign_2014_2015',
            'dangerous_substances' => 'dangerous_substances',
            'economic_incentives' => 'good_osh_is_good_for_business',
            'education' => 'mainstreaming_osh_into_education',
            'osh_education' => 'mainstreaming_osh_into_education',
            'osheducation' => 'mainstreaming_osh_into_education',
            'esener' => 'esener',
            'foresight' => 'emerging_risks',
            'gender' => 'women_and_osh',
            'green_jobs' => 'green_jobs',
            'legislation' => 'legislation',
            'management_leadership' => 'leadership',
            'msd' => 'musculoskeletal_disorders',
            'nanotechnology' => 'nanomaterials',
            'prevention' => 'accident_prevention',
            'risk_observatory' => 'emerging_risks',
            'risks' => 'emerging_risks',
            'stress' => 'psychosocial_risks_and_stress',
            'young_people' => 'osh_and_young_people'
        );

        $new_categories = array();

        foreach ($categories as $cat) {
            if (isset($replace[$cat])) {
                $new_categories[] = $replace[$cat];
            }
        }

        return implode(', ', $new_categories);
    }

    function fields() {
        return array(
            'id' => 'Primary Key (URL pattern)',
            'path' => 'URL pattern without language',
            'language' => 'Row language',
            'workflow_state' => '',
            'creation_date' => '',
            'modification_date' => '',
            'publication_date' => '',
            'creator' => 'Author user id from the old website',
            'title' => '',
            'description' => '',
            'text' => 'Body of the news',
            'image' => 'Path to image file',
            'imageCaption' => 'Image tooltip',
            'subject' => 'Categories/Tags',
            'country' => '',
            'subcategory' => 'Merged into categories',
            'multilingual_thesaurus' => '',
            'nace' => 'Nace codes taxonomy',
        );
    }

    /**
     * This function sets the node aliases after the migration, when node nid is available
     * @param $entity
     * @param stdClass $row
     */
    function complete($entity, stdClass $row) {
        $languages = array_keys(language_list());
        foreach ($languages as $lang_code) {
            $args = array(
                'source' => 'node/'. $entity->nid,
                'alias' => $row->id, // Same alias for all languages (see mappings)
                'language' => $lang_code,
            );
            path_save($args);
        }
    }
}

class NewsContentListCSV extends MigrateList {
    protected $fileUrl = '';
    protected $httpOptions;
    protected $multilingualFields;
    public static $csvData;

    public function __construct($file_url, $multilingualFields = array(), $http_options = array()) {
        parent::__construct();
        $this->fileUrl = $file_url;
        $this->httpOptions = $http_options;
        $this->multilingualFields = $multilingualFields;
    }

    public function  __toString() {
        return $this->fileUrl;
    }

    protected function parse_multilingual_csv($file, $multiFields = array()) {
        $handle = fopen($file, 'r');
        $fields = $data = fgetcsv($handle, 1000, ';');

        $final = [];

        while (($data = fgetcsv($handle, 100000, ';')) !== FALSE) {
            $country = $data[1];
            $id = explode('/', $data[0], 3)[2];


            foreach ($fields as $key => $field) {
                if (in_array($field, $multiFields)) {
                    $final[$id][$field][$country] = $data[$key];
                    continue;
                }
                $final[$id][$field] = $data[$key];
            }

            $final[$id]['id'] = $id;
        }

        foreach ($final as $id => $id_value) {
            foreach ($id_value as $key_field => $field) {
                if (is_array($field) && !isset($final[$id][$key_field]['en'])) {
                    unset($final[$id]);
                }
            }
        }

        return $final;
    }

    public function getIdList() {
        self::$csvData = $this->parse_multilingual_csv($this->fileUrl, $this->multilingualFields);
        if (self::$csvData) {
            return $this->getIDsFromCSV(self::$csvData);
        }
        Migration::displayMessage(t('Loading of !fileUrl failed:',
            array('!listurl' => $this->fileUrl)));
        return NULL;
    }

    protected function getIDsFromCSV(array $data) {
        $ids = array();
        foreach ($data as $key => $value) {
            $ids[] = $key;
        }
        return $ids;
    }

    public function computeCount() {
        return count(self::$csvData);
    }
}

class NewsContentItemCSV extends MigrateItem {
    protected $data;

    public function getItem($id) {
        if (empty($this->data)) {
            $csvData = NewsContentListCSV::$csvData;
            foreach ($csvData as $csvId => $item) {
                $this->data[$csvId] = json_decode(json_encode($item), FALSE);
            }
        }

        return isset($this->data[$id]) ? $this->data[$id] : NULL;
    }
}
