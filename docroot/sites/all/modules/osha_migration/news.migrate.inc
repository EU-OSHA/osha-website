<?php
class MigrateOshaNews extends DynamicMigration {
    protected $vocabulary = NULL;

    public function __construct($arguments) {
        parent::__construct();

        $this->description = 'Import "News" taxonomy from JSON file';
        $this->contentType = 'news';

        if(isset($arguments['file_name'])) {
            $file_name = $arguments['file_name'];
        }
        else {
            $file_name = '';
        }

        $multilingualFields = array('title', 'description', 'text');
        $source_file = sprintf('%s/%s', drupal_get_path('module', 'osha_migration'), $file_name);
        $this->source = new MigrateSourceList(new OSHAMigrateListCSV($source_file, $multilingualFields),
            new OSHAMigrateItemCSV(), $this->fields());

        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'id' => array(
                    'type' => 'varchar',
                    'length' => 200,
                    'not null' => TRUE,
                    'description' => 'Nace code'
                ),
            ),
            MigrateDestinationNode::getKeySchema()
        );

        $node_options = MigrateDestinationNode::options('en', 'text');
        $this->destination = new MigrateDestinationNode('news', $node_options);

        $this->addFieldMapping('field_tags', 'subjectTids')->separator(',');
        $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');

        $this->addFieldMapping('field_thesaurus', 'thesaurusTids')->separator(',');
        $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');

        $this->addFieldMapping('field_news_publication_date', 'publication_date');

        $this->addFieldMapping('path', 'id');
        $this->addFieldMapping('created', 'creation_date');
        $this->addFieldMapping('changed', 'modification_date');

        //images migration
        $this->addFieldMapping('field_news_image:file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);
        $this->addFieldmapping('field_news_image:preserve_files')->defaultValue(TRUE);
        $this->addFieldMapping('field_news_image:source_dir')->defaultValue(osha_migration_get_data_dir() . '/export/');

        $this->addFieldMapping('field_news_image', 'image');
        $this->addFieldMapping('field_news_image:title', 'imageCaption');
        $this->addUnmigratedSources(array('creator', 'nace'));
    }

    protected function generateMachineName($class_name = NULL) {
        return 'NewsContentType';
    }

    public function prepareRow($row) {
        $row->language = 'en';

        $tags = explode(', ', mapCategories($row->subject));
        $subcat = explode(', ', mapCategories($row->subcategory));
        $tags = array_unique(array_merge($tags, $subcat));
        $row->subjectTids = $this->getTidsFromField('tags', 'field_tags_code', implode(', ', $tags));
        $row->thesaurusTids = $this->getTidsFromField('thesaurus', 'field_thesaurus_code', $row->multilingual_thesaurus);

        return TRUE;
    }

    private function getTidsFromField($voc, $field, $data) {
        $dataArray = explode(', ', $data);
        $results = getTids($voc, $field, $dataArray);
        if(!empty($results)) {
            return implode(', ', $results);
        }
        return null;
    }

    function prepare($entity, stdClass $row) {
        $entity->language = 'en';
        $translationsData = array();

        foreach ($row->title as $language => $translation) {
            if(!empty($row->title->$language)) {
                $entity->title_field[$language][0]['value'] = $translation;
            }
            $sourceLanguage = ($language == 'en' ? '' : 'en');
            $translationsData[$language] = array(
                'entity_type' => 'term',
                'language' => $language,
                'source' => $sourceLanguage,
                'uid' => '1',
                'status' => '1',
                'translate' => '0',
            );
        }

        foreach ($row->text as $language => $translation) {
            if(!empty($row->text->$language)) {
                $entity->body[$language][0]['value'] = str_replace('<@#&>', '"', $translation);
                $entity->body[$language][0]['format'] = 'full_html';
            }
            $sourceLanguage = ($language == 'en' ? '' : 'en');
            $translationsData[$language] = array(
                'entity_type' => 'term',
                'language' => $language,
                'source' => $sourceLanguage,
                'uid' => '1',
                'status' => '1',
                'translate' => '0',
            );
        }

        foreach ($row->description as $language => $translation) {
            if(!empty($row->description->$language)) {
                $entity->field_news_summary[$language][0]['value'] = str_replace('<@#&>', '"', $translation);
                $entity->field_news_summary[$language][0]['format'] = 'full_html';
            }
            $sourceLanguage = ($language == 'en' ? '' : 'en');
            $translationsData[$language] = array(
                'entity_type' => 'term',
                'language' => $language,
                'source' => $sourceLanguage,
                'uid' => '1',
                'status' => '1',
                'translate' => '0',
            );
        }

        #$entity->path['pathauto'] = 0;
        $entity->translations = (object)array(
            'original' => 'en',
            'data' => $translationsData
        );
    }

    function fields() {
        return array(
            'id' => 'Primary Key (URL pattern)',
            'path' => '',
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
        foreach($languages as $lang_code) {
            $args = array(
                'source' => 'node/'. $entity->nid,
                'alias' => $row->id, // Same alias for all languages (see mappings)
                'language' => $lang_code,
            );
            path_save($args);
        }
    }
}
