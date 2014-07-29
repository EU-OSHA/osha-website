<?php
class OSHAMigrateListCSV extends MigrateList {
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

    /**
     * @param $file
     * @param array $multiFields
     * @return array
     */
    protected function parse_multilingual_csv($file, $multiFields = array()) {
        $handle = fopen($file, 'r');
        $fields = $data = fgetcsv($handle, 1000, ';');

        $final = [];

        while(($data = fgetcsv($handle, 100000, ';')) !== FALSE) {
            $country = $data[1];
            $id = explode('/', $data[0], 3)[2];

            foreach($fields as $key => $field) {
                if(in_array($field, $multiFields)) {
                    $final[$id][$field][$country] = $data[$key];
                    continue;
                }
                $final[$id][$field] = $data[$key];
            }

            $final[$id]['id'] = $id;
        }

        foreach($final as $id => $id_value) {
            foreach($id_value as $key_field => $field) {
                if(is_array($field) && !isset($final[$id][$key_field]['en'])) {
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

class OSHAMigrateItemCSV extends MigrateItem {
    protected $data;

    public function getItem($id) {
        // Object caching
        if (empty($this->data)) {
            $csvData = OSHAMigrateListCSV::$csvData;
            foreach ($csvData as $csvId => $item) {
                $this->data[$csvId] = json_decode(json_encode($item), FALSE);
            }
        }

        return isset($this->data[$id]) ? $this->data[$id] : NULL;
    }

}

function getTids($vocabulary, $field_match, $termCodes) {
    static $cache = array();
    $ret = array();

    if(empty($cache[$vocabulary][$field_match])) {
        $voc = taxonomy_vocabulary_machine_name_load($vocabulary);
        $terms = taxonomy_get_tree($voc->vid, 0, NULL, TRUE);
        foreach($terms as $term) {
            if(!empty($term->$field_match)) {
                $field = $term->$field_match;
                $cache[$vocabulary][$field_match][$field['und'][0]['value']] = $term->tid;
            }
        }
    }

    if(!empty($cache[$vocabulary][$field_match])) {
        foreach($termCodes as $t) {
            if(!empty($cache[$vocabulary][$field_match][$t])) {
                $ret[] = $cache[$vocabulary][$field_match][$t];
            }
        }
    }


    return $ret;
}

function mapCategories($categories) {
    $categories = explode(', ', $categories);

    $new_categories = array();
    foreach($categories as $cat) {
        if($cat == 'young_people::educators_mainstreaming') {
            $new_categories[] = 'mainstreaming_osh_into_education';
        }
        elseif(count(explode('::', $cat)) == 2) {
            $exp = explode('::', $cat);
            $new_categories[] = $exp[0];
        } else {
            $new_categories[] = $cat;
        }
    }

    $categories = $new_categories;

    $initial = array(
        'accident_prevention',
        'ageing',
        'businessOSH',
        'campaign_2014_15',
        'dangerous_substances',
        'economic_incentives',
        'education',
        'osh_education',
        'osheducation',
        'esener',
        'foresight',
        'gender',
        'green_jobs',
        'legislation',
        'management_leadership',
        'msd',
        'nanotechnology',
        'prevention',
        'risk_observatory',
        'risks',
        'stress',
        'young_people'
    );

    $replace = array(
        'accident_prevention',
        'ageing_and_osh',
        'good_osh_is_good_for_business',
        'campaign_2014_2015',
        'dangerous_substances',
        'good_osh_is_good_for_business',
        'mainstreaming_osh_into_education',
        'mainstreaming_osh_into_education',
        'mainstreaming_osh_into_education',
        'esener',
        'emerging_risks',
        'women_and_osh',
        'green_jobs',
        'legislation',
        'leadership',
        'musculoskeletal_disorders',
        'nanomaterials',
        'accident_prevention',
        'emerging_risks',
        'emerging_risks',
        'psychosocial_risks_and_stress',
        'osh_and_young_people'
    );

    $removed = array(
        'agriculture',
        'Campaign 2012-13',
        'cleaners',
        'construction',
        'csr',
        'cww',
        'disabled_people',
        'fisheries',
        'health_care',
        'healthcare',
        'horeca',
        'maintenance',
        'migrant_workers',
        'noise',
        'organisation',
        'Practical Solutions, Good Practice',
        'research',
        'risk_assessment',
        'road_transport',
        'statistics',
        'transport',
        'whp',
        'worker_participation',
        'competitions',
        'disability',
        'hwi',
        'oira',
        'presidency'
    );

    $replace = array_combine($initial, $replace);
    $new_categories = array();

    $categories = array_diff($categories, $removed);

    foreach($categories as $cat) {
        $new_categories[] = $replace[$cat];
    }

    return implode(', ', $new_categories);
}