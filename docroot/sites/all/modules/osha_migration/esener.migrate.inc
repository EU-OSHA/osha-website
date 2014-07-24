<?php
class MigrateOshaEsenerTaxonomy extends DynamicMigration {

    protected $vocabulary = NULL;
    protected $cache = NULL;

    public function __construct($arguments) {
        parent::__construct();

        $this->changeFieldSize();

        $this->description = 'Import the "Esener" taxonomy into Esener';
        $this->vocabulary = 'Esener';

        if(isset($arguments['file_name'])) {
            $file_name = $arguments['file_name'];
        } else {
            $file_name = 'data/esener.json';
        }
        $source_file = sprintf('%s/%s', drupal_get_path('module', 'osha_migration'), $file_name);

        $this->generateCacheFromFile($source_file);

        $this->map = new MigrateSQLMap($this->machineName,
            array(
              'code' => array(
                  'type' => 'varchar',
                  'length' => 30,
                  'not null' => true,
                  'description' => 'Nace code'
                  ),
              ),
            MigrateDestinationTerm::getKeySchema()
        );

        $this->source = new MigrateSourceList(
            new EsenerTaxonomyMigrationListJSON($source_file),
            new EsenerTaxonomyMigrationItemJSON($source_file, array()), $this->fields()
        );

        $term_options = MigrateDestinationTerm::options('en', 'text', TRUE);
        $this->destination = new MigrateDestinationTerm($this->vocabulary, $term_options);

        $this->addFieldMapping('parent', 'parent');
        $this->addFieldMapping('field_esener_code', 'code');
        $this->addFieldMapping('format')->defaultValue('plain_text');
        $this->addFieldMapping('name', 'en');
        $this->addFieldMapping('description_field:format')->defaultValue('plain_text');
    }

    /**
     * Change field size to 768 characters to accomodate Esener questions which are very long. Applies to
     *  - taxonomy_term_data.name
     *  - field_data_name_field.name_field_value
     *  - field_revision_name_field.name_field_value
     */
    private function changeFieldSize() {
        $column_size = 768;
        if(osha_get_mysql_column_size('taxonomy_term_data', 'name') < $column_size) {
            drupal_set_message("Changing taxonomy_term_data size to $column_size");
            db_change_field('taxonomy_term_data', 'name', 'name',
                array('type' => 'varchar','length' => $column_size)
            );
        }

        if(osha_get_mysql_column_size('field_data_name_field', 'name_field_value') < $column_size) {
            drupal_set_message("Changing field_data_name size to $column_size");
            db_change_field('field_data_name_field', 'name_field_value', 'name_field_value',
                array('type' => 'varchar', 'length' => $column_size)
            );
        }

        if(osha_get_mysql_column_size('field_revision_name_field', 'name_field_value') < $column_size) {
            drupal_set_message("Changing field_revision_name size to $column_size");
            db_change_field('field_revision_name_field', 'name_field_value', 'name_field_value',
                array('type' => 'varchar','length' => $column_size)
            );
        }
    }

    protected  function createStub($migration, array $source) {
        static $voc = NULL;
        if($voc == NULL) {
            $voc = taxonomy_vocabulary_machine_name_load($this->vocabulary);
        }
        $term = new stdClass();
        $term->parent = 0;
        $term->language = 'en';
        $term->name = t('Stub for @code', array('@code' => $source[0]));
        $term->vid = $voc->vid;
        taxonomy_term_save($term);
        return array($term->tid);
    }

    public function prepareRow($row) {
        $row->parent = 0;
        $row->language = 'en';
        $row->parent = $this->getParent($row);
        $row->ID = $row->code;
        return TRUE;
    }

    function prepare($entity, stdClass $row){
        $correspondingRowAssocArray = $this->cache[$row->ID];
        $entity->language = 'en';
        $translationsData = array();
        $languages = $this->generateLanguagesWithFieldsMap();

        foreach($languages as $language => $fields) {
            $this->addTranslationToEntityFromRow($entity, $correspondingRowAssocArray, $language, $fields);
            $sourceLanguage = ($language == 'en') ? '' : 'en';
            $translationsData[$language] = array(
                'entity_type' => 'term',
                'language'    => $language,
                'source'      => $sourceLanguage,
                'uid'         => '1',
                'status'      => '1',
                'translate'   => '0',
                );
        }

        $entity->translations = (object) array(
            'original' => 'en',
            'data' => $translationsData
            );
    }

    protected function generateCacheFromFile($source_file) {
        $rows = json_decode(file_get_contents($source_file), TRUE);
        foreach($rows as $row) {
            $this->cache[$row['code']] = $row;
        }
    }

    protected function generateMachineName($class_name = NULL) {
        return 'EsenerTaxonomy';
    }

    private function getParent($row) {
        $parent_code = $this->getParentCode($row);
        if(!empty($parent_code)) {
            $parent_id = self::_getTidByCode($parent_code);
            if(empty($parent_id)) {
                $parent_id = $this->handleSourceMigration('EsenerTaxonomy', $parent_code);
            }
            return $parent_id;
        }
        return 0;
    }

    private static function _getTidByCode($code) {
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition('entity_type', 'taxonomy_term')
            ->fieldCondition('field_esener_code', 'value', $code, '=')
            ->execute();
        if(!empty($result['taxonomy_term'])) {
            return current(array_keys($result['taxonomy_term']));
        }
        return array();
    }


    private function getParentCode($row) {
        return $row->parent_code;
    }

    function fields() {
        return array(
            'parent' => 'Parent tid',
            'en' => 'Text of field',
            'code' => 'Item code (PK)',
            );
    }

    private function generateLanguagesWithFieldsMap() {
        $languages = array(
            'en' => 'en', 'bg' => 'bg', 'cs' => 'cs', 'da' => 'da', 'el' => 'el',
            'et' => 'est', 'es' => 'es', 'fi' => 'fi', 'hr' => 'hr', 'hu' => 'hu',
            'fr' => 'fr', 'it' => 'it', 'lt' => 'lt', 'lv' => 'lv', 'mt' => 'mt',
            'nl' => 'nl', 'no' => 'no', 'pl' => 'pl', 'pt' => 'pt', 'ro' => 'ro',
            'ru' => 'ru', 'sv' => 'se', 'sl' => 'si', 'sk' => 'sk', 'tr' => 'tr',
            'de' => 'de'
            );
        $languageFieldsMap = array();
        foreach($languages as $language => $field_language_code) {
            $languageFieldsMap[$language] = array(
                'description' => $field_language_code);
        }
        return $languageFieldsMap;
    }

    private function addTranslationToEntityFromRow(&$entity, $row, $language, $fields) {
        if(!empty($row[$fields['description']])) {
            $entity->name_field[$language][0]['value'] = $row[$fields['description']];
        }
        if(!empty($row[$fields['description']])) {
            $entity->description_field[$language][0]['value'] = $row[$fields['description']];
        }
    }
}

class EsenerTaxonomyMigrationListJSON extends MigrateListJSON {
    /**
     * The default implementation assumes the IDs are top-level array elements,
     * but the array elements are the data items - we need to look inside them
     * for the IDs.
     */
    protected function getIDsFromJSON(array $data) {
        $ids = array();
        foreach($data as $item) {
            $ids[] = $item['code'];
        }
        return $ids;
    }
}

class EsenerTaxonomyMigrationItemJSON extends MigrateItemJSON {
    protected $data = array();
    /**
     * Two problems with the default getItem() - it reads and parses the JSON on
     * each call, which we don't want to do for multiple items in the file; and,
     * we need to retrieve a given item from the file according to its 'id' element.
     */
    public function getItem($id) {
        // Object caching
        if(empty($this->data)) {
            $data = $this->loadJSONUrl($this->itemUrl);
            if($data) {
                foreach($data as $item) {
                    $this->data[$item->code] = $item;
                }
            }
        }
        return isset($this->data[$id]) ? $this->data[$id] : NULL;
    }
}
