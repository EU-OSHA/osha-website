<?php

/**
 * Class MigrateOshaPublicationFiles
 * @TODO: Not implemented yet
 */
class OshaMigratePublicationsFiles extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct();
    $this->description = t('Imports files needed bt publication');

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $file_name = NULL;
    if (isset($arguments['file_name'])) {
      $file_name = $arguments['file_name'];
    }

    $source_file = sprintf('%s/%s', drupal_get_path('module', 'osha_migration'), $file_name);
    $this->source = new MigrateSourceList(new PublicationMigrateFilesListCSV($source_file),
      new PublicationMigrateFilesItemCSV(), $this->fields());

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 200,
          'not null' => TRUE,
          'description' => 'File old path',
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    $this->destination = new MigrateDestinationFile('file');

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('source_dir')->defaultValue(osha_migration_get_data_dir() . "/export");
    $this->addFieldMapping('value', 'file');
    $this->addFieldMapping('destination_file', 'file');
    $this->addFieldMapping('destination_dir')->defaultValue('public://publications/documents');
    $this->addFieldMapping('preserve_files')->defaultValue(FALSE);
    $this->addFieldMapping('file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('timestamp', 'timestamp');
  }

  /**
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_FILES_PUBLICATION;
  }

  /**
   * Prepares the source row before migration.
   *
   * @param object $row
   *   One source $row as returned by getItem
   *
   * @return bool
   *   TRUE if row is valid
   */
  public function prepareRow($row) {
    $row->timestamp = time();

    return TRUE;
  }

  /**
   * Return an array of mapped fields from source.
   *
   * @return array
   *   The array of fields
   */
  private function fields() {
    return array(
      'id' => "It's used for mapping internally, and it's actually the old path to the file, as it is unique",
      'file' => "The old path to the file",
      'timestamp' => "Represents the moment the file got into Drupal",
    );
  }
}

class PublicationMigrateFilesListCSV extends MigrateList {

  protected $fileUrl = '';
  protected $multilingualFields;
  public static $csvData;

  /**
   * Populates csvData with parsed information from $file_url.
   *
   * @param string $file_url
   *   The location of the file with source raw data
   */
  public function __construct($file_url) {
    parent::__construct();
    $this->fileUrl = $file_url;

    self::$csvData = $this->parseMultilingualCSV($this->fileUrl);
  }

  /**
   * Returns the file url.
   *
   * @return string
   *   The file url
   */
  public function __toString() {
    return $this->fileUrl;
  }

  /**
   * Parses the csv $file and molds the data, to best suit our needs.
   *
   * The data is cached
   *
   * @param string $file
   *   The csv file url
   *
   * @return array
   *   Returns assoc array of assoc arrays which represents one source row
   *   array[id][field] -- row
   */
  protected function parseMultilingualCSV($file) {
    $handle = fopen($file, 'r');
    $fields = $data = fgetcsv($handle, 1000, ';');
    $final = array();
    while (($data = fgetcsv($handle, 100000, ';')) !== FALSE) {
      $row_id = $data[0];
      foreach ($fields as $key => $field) {
        $final[$row_id][$field] = $data[$key];
      }
      $final[$row_id]['id'] = $row_id;
    }

    foreach (array_keys($final) as $row_id) {
      if ($final[$row_id]['workflow_state'] !== 'published' ||
        strlen($final[$row_id]['file']) > 224 ||
        empty($final[$row_id]['file'])
      ) {
        unset($final[$row_id]);
      }
    }
    $final["some_id"]["file"]
      = "/en/resources/qualitative-post-test-evaluation-of-esener-overview-report/National Overview report de.pdf";
    return $final;
  }

  /**
   * {@inheritdoc}
   */
  public function getIdList() {
    if (self::$csvData) {
      return array_keys(self::$csvData);
    }
    Migration::displayMessage(
      t('Loading of !fileUrl failed:',
        array('!listurl' => $this->fileUrl))
    );
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function computeCount() {
    return count(self::$csvData);
  }
}

class PublicationMigrateFilesItemCSV extends MigrateItem {

  protected $data;

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (empty($this->data)) {
      $csv_data = PublicationMigrateFilesListCSV::$csvData;
      foreach ($csv_data as $csv_id => $item) {
        $this->data[$csv_id] = (object) $item;
      }
    }
    return isset($this->data[$item_id]) ? $this->data[$item_id] : NULL;
  }
}
