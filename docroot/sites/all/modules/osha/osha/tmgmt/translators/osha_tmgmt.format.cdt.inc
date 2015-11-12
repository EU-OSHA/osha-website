<?php

/**
 * Export to CdT XML format.
 *
 * The purpose of this class is to mask or process HTML elements in the source
 * and target elements so that translation tools are able to understand which
 * content needs to be translated and ignored.
 *
 * On the other hand we need to properly unmask the markup back to HTML on
 * the translation import. So the process is bidirectional and prior to running
 * the unmasking process we try to validate the integrity in the
 * validateJobTranslationUponImport() method. Currently the integrity check
 * involves only a counter of elements that have been created during
 * source processing and has to mach number of elements being imported
 * with the translation.
 *
 * To process the content DOMDocument object is used due to its ability to
 * read broken HTML. This also implies that if broken HTML is in the source
 * content the translation content will be fixed into the extend of DOMDocument
 * abilities.
 */
class OSHATranslatorFileformatCDT extends XMLWriter {

  /**
   * Contains a reference to the currently being exported job.
   *
   * @var TMGMTJob
   */
  protected $job;

  protected $importedXML;
  protected $importedTransUnits;

  // Store mapped Job Item Ids [lang][entity_type][entity_id].
  public $mappedItemsIDs = array();

  /**
   * Adds a job item to the xml export.
   */
  protected function addItem(TMGMTJobItem $item, TMGMTJob $job) {
    // <Translation>
    $this->startElement('Translation');
    $this->writeElement('TranslationSourceLanguage', $item->source_language);
    foreach ($item->target_languages as $language) {
      $this->writeElement('TranslationTargetLanguage', $language);
    }

    // <ContentIdentifier>
    $this->startElement('ContentIdentifier');
    $this->writeAttribute('transactionId', $job->tjid);
    $this->text($item->tjiid);
    // </ContentIdentifier>
    $this->endElement();

    $this->writeElement('Priority', $this->getPriority($job));
    $this->writeElement('CharacterLength', $item->character_count);
    $this->writeElement('PreviewLink', 'NO PREVIEW LINK');
    $this->writeElement('ContentTitle', 'NO TITLE');
    $this->writeElement('FriendlyUrlName', 'NO FRIENDLY URL');
    $this->writeElement('Keywords', 'NO KEYWORDS');

    $data = array_filter(tmgmt_flatten_data($item->getData()), '_tmgmt_filter_data');
    foreach ($data as $key => $field) {
      $this->startElement('DynamicElement');
      $this->writeAttribute('dynamicElementKind', 'TextArea');
      $this->writeAttribute('indexType', $item->item_type);
      $this->writeAttribute('instanceId', $item->item_id);
      $this->writeAttribute('name', ']['.$key);
      $this->writeAttribute('repeatable', 'false');
      $this->startElement('DynamicContent');
      $this->writeCdata($field['#text']);
      // </DynamicContent>
      $this->endElement();
      // </DynamicElement>
      $this->endElement();
    }

    /*
    foreach ($item->getData() as $key => $field) {
      $text = NULL;

      if (isset($field['#text'])) {
        $text = $field['#text'];
      }
      elseif (isset($field['value']['#text'])) {
        $text = $field['value']['#text'];
      }
      elseif (isset($field[0]['value']['#text'])) {
        $text = $field[0]['value']['#text'];
      }

      if (!empty($text)) {
        $this->startElement('DynamicElement');
        $this->writeAttribute('dynamicElementKind', 'TextArea');
        $this->writeAttribute('indexType', $item->item_type);
        $this->writeAttribute('instanceId', $item->item_id);

        // Construct the name key flattened.
        $data = array_filter(tmgmt_flatten_data($field), '_tmgmt_filter_data');
        reset($data);
        $name_attr = '][' . $key;
        $data_key = key($data);
        // On menu and strings there is no key for $data.
        if (!empty($data_key)) {
          $name_attr .= '][' . $data_key;
        }

        $this->writeAttribute('name', $name_attr);

        $this->writeAttribute('repeatable', 'false');
        $this->startElement('DynamicContent');
        $this->writeCdata($text);
        // </DynamicContent>
        $this->endElement();
        // </DynamicElement>
        $this->endElement();
      }
    }*/
    // </Translation>
    $this->endElement();
  }

  /**
   * Returns the priority of the job.
   *
   * @param TMGMTJob $job
   *   The TMGMT job
   *
   * @return string
   *   Returns the corresponding priority
   */
  public function getPriority(TMGMTJob $job) {
    static $priorities = array(
      OSHA_TMGMT_JOB_PRIORITY_NORMAL => "Normal",
      OSHA_TMGMT_JOB_PRIORITY_LOW => "Low",
      OSHA_TMGMT_JOB_PRIORITY_HIGH => "High",
    );

    return $priorities[$job->priority];
  }
  /**
   * {@inheritdoc}
   */
  public function export(TMGMTJob $job) {
    $this->job = $job;

    $this->openMemory();
    $this->setIndent(TRUE);
    $this->setIndentString(' ');
    $this->startDocument('1.0', 'UTF-8', 'no');

    // <Transaction> Root element.
    $this->startElement('Transaction');
    $this->writeAttribute('xmlns:xsi', 'http://www.w3.org/2001/XMLSchema-instance');
    $this->writeAttribute('xsi:noNamespaceSchemaLocation', 'http://oami.europa.eu/schemas/common/EM-Translation-V0-3.xsd');


    $this->startElement('TransactionHeader');
    $this->startElement('SenderDetails');
    $this->writeElement('ProducerDateTime', date('c', $job->created));
    // </SenderDetails>
    $this->endElement();
    // </TransactionHeader>
    $this->endElement();

    // <TransactionIdentifier>777</TransactionIdentifier>
    $this->writeElement('TransactionIdentifier', $job->tjid);

    $this->writeElement('TransactionCode', 'EM-OWS Translation Request');

    // <TransactionData>
    $this->startElement('TransactionData');
    $this->startElement('TranslationDetails');
    $this->writeElement('TotalCharacterLength', $job->character_count);

    $job_items = self::getUniqueItems($job);
    foreach ($job_items as $item_type => $item_ids) {
      foreach ($item_ids as $item_id => $item_list) {
        foreach ($item_list as $item) {
          $this->addItem($item, $job);
        }
      }
    }

    // </TransactionDetails>
    $this->endElement();
    // </TransactionData>
    $this->endElement();

    $this->endDocument();
    return $this->outputMemory();
  }

  /**
   * Generates an unique array of items, based on item content
   * Also sets $item->target_languages array, used in addItem
   *
   * @return array
   *   Items -> Items[item_type][item_id] contains an array of items
   */
  public static function getUniqueItems($job) {
    $job_items = array();
    foreach ($job->getItems() as $item) {
      // Search if node already exists in job_items
      if (isset($job_items[$item->item_type][$item->item_id])) {
        // $is_new will be FALSE when $item is added to an existing element of $job_items
        $is_new = TRUE;
        foreach ($job_items[$item->item_type][$item->item_id] as $new_item) {
          // Now check if the two items have the same content
          if (serialize($new_item->getData()) == serialize($item->getData()) ) {
            // Same content, simply add another language
            $new_item->target_languages[] = $item->target_language;
            $is_new = FALSE;
            break;
          }
        };
        if ($is_new) {
          // If not found until now, add it
          $item->target_languages = array($item->target_language);
          $job_items[$item->item_type][$item->item_id][] = $item;
        }
      } else {
        // This is the first job item for the node, add it
        $item->target_languages = array($item->target_language);
        $job_items[$item->item_type][$item->item_id][] = $item;
      }
    }
    return $job_items;
  }

  /**
   * {@inheritdoc}
   */
  public function import($imported_file) {
    $this->getImportedXML($imported_file);
    $tjid = $this->importedXML->xpath("//TransactionIdentifier");
    $tjid = reset($tjid);
    $job = tmgmt_job_load((string) $tjid);

    $flat_data = $this->getImportedTargets($job);
    $data = tmgmt_unflatten_data($flat_data);
    return $data;
  }

  /**
   * Populates $this->mappedItemsIDs.
   *
   * Job Item ids are stored in [lang][entity_type][entity_id].
   */
  public function getMappedItemIDs(TMGMTJob $job) {
    $items = $job->getItems();
    foreach ($items as $item_id => $item) {
      $this->mappedItemsIDs[$item->target_language][$item->item_type][$item->item_id] = $item_id;
    }
  }

  /**
   * Validates imported XLIFF file.
   *
   * Checks:
   * - Job ID.
   * - Target and source languages
   * - Content integrity by
   */
  public function validateImport($imported_file) {
    $xml = $this->getImportedXML($imported_file);
    if (empty($xml)) {
      drupal_set_message('Cannot parse XML file, check XML integrity and syntax', 'error');
      return FALSE;
    }
    $phase = $xml->xpath('//TransactionIdentifier');
    if ($phase) {
      $phase = reset($phase);
    }
    else {
      drupal_set_message('TransactionIdentifier tag is missing. XML is not valid', 'error');
      return FALSE;
    }
    // Check if the job can be loaded.
    $tjid = (string) $phase;
    $job = tmgmt_job_load($tjid);
    if (empty($job)) {
      drupal_set_message(sprintf('Cannot find inside the system a matching job for ID: %s', $tjid), 'error');
      return FALSE;
    }
    // Check if Job Items IDs from file belongs to this Job.
    $items_ids = array_keys($job->getItems());
    $identifiers = $xml->xpath('//ContentIdentifier');
    foreach ($identifiers as $identifier) {
      $tjiid = (string) $identifier;
      if (!in_array($tjiid, $items_ids)) {
        drupal_set_message(sprintf('The job inside the system does not have a corresponding job item with ID: %s', $tjiid), 'error');
        return FALSE;
      }
    }
    // Check if file contains other languages than those from the job.
    $this->getMappedItemIDs($job);
    $languages = $xml->xpath("//TranslationTargetLanguage");
    foreach ($languages as $language) {
      $lang = (string) $language;
      if ($lang != $job->source_language && !isset($this->mappedItemsIDs[$lang])) {
        drupal_set_message(sprintf('Invalid target language. This job does not accept translations in: %s', $lang), 'error');
        return FALSE;
      }
    }
    $targets = $this->getImportedTargets($job);
    if (empty($targets)) {
      drupal_set_message('No translations processed (missing Translation or TranslationTargetLanguage elements?)', 'error');
      return FALSE;
    }
    return $job;
  }

  protected function getImportedXML($imported_file) {
    if (empty($this->importedXML)) {
      // It is not possible to load the file directly with simplexml as it gets
      // url encoded due to the temporary://. This is a PHP bug, see
      // https://bugs.php.net/bug.php?id=61469
      $xml_string = file_get_contents($imported_file);
      if ($this->importedXML = simplexml_load_string($xml_string)) {
        // Register the XLIFF namespace, required for xpath.
        $this->importedXML->registerXPathNamespace('cdt', 'urn:oasis:names:tc:cdt:document:1.2');
      }
    }
    return $this->importedXML;
  }

  protected function getImportedTargets(TMGMTJob $job) {
    if (empty($this->importedXML)) {
      return FALSE;
    }
    // Populates Job Item Ids array.
    $this->getMappedItemIDs($job);
    if (empty($this->importedTransUnits)) {
      $reader = new XMLReader();
      foreach ($this->importedXML->xpath('//Translation') as $translation) {
        $target_language = (string) $translation->TranslationTargetLanguage;
        if ($job->source_language != $target_language) {
          foreach ($translation->xpath('DynamicElement') as $unit) {
            // Get the Job Item ID that handles the language translation
            // of the current entity id and type.
            $entity_id = (string) $unit['instanceId'];
            $entity_type = (string) $unit['indexType'];
            if (!empty($this->mappedItemsIDs[$target_language][$entity_type][$entity_id])) {

              $item_id = $this->mappedItemsIDs[$target_language][$entity_type][$entity_id];
              $reader->XML($unit->DynamicContent->asXML());
              $reader->read();
              $key = $item_id . (string) $unit['name'];
              $this->importedTransUnits[$key]['#text'] = $this->processForImport($reader->readInnerXML(), $job);
            }
          }
        }
      }
    }
    return $this->importedTransUnits;
  }

  /**
   * Processes trans-unit/target to rebuild back the HTML.
   *
   * @param string $translation
   *   Job data array.
   * @param TMGMTJob $job
   *   Translation job.
   *
   * @return string
   */
  protected function processForImport($translation, TMGMTJob $job) {
    $reader = new XMLReader();
    $reader->XML('<translation>' . $translation . '</translation>');
    $text = '';

    while ($reader->read()) {
      // If the current element is text append it to the result text.
      if ($reader->name == '#text' || $reader->name == '#cdata-section') {
        $text .= $reader->value;
      }
      elseif ($reader->name == 'x') {
        if ($reader->getAttribute('ctype') == 'lb') {
          $text .= '<br />';
        }
      }
      elseif ($reader->name == 'ph') {
        if ($reader->getAttribute('ctype') == 'image') {
          $text .= '<img';
          while ($reader->moveToNextAttribute()) {
            // @todo - we have to use x-html: prefixes for attributes.
            if ($reader->name != 'ctype' && $reader->name != 'id') {
              $text .= " {$reader->name}=\"{$reader->value}\"";
            }
          }
          $text .= ' />';
        }
      }
    }
    return $text;
  }
}
