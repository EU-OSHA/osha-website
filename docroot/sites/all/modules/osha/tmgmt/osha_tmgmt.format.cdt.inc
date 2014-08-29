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

  /**
   * Adds a job item to the xml export.
   *
   * @param $item
   *   The job item entity.
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

    // TODO:EDW
    $this->writeElement('Priority', $this->getPriority($job));

    $this->writeElement('CharacterLength', $item->character_count);
    // TODO:EDW
    $this->writeElement('PreviewLink', 'NO PREVIEW LINK');
    $this->writeElement('ContentTitle', 'NO TITLE');
    $this->writeElement('FriendlyUrlName', 'NO FRIENDLY URL');
    $this->writeElement('Keywords', 'NO KEYWORDS');
    foreach ($item->getData() as $key => $field) {
      $text = NULL;
      if ($key == "node_title") {
        break;
      }
      if (isset($field['#text'])) {
        $text = $field['#text'];
      }
      elseif (isset($field['value']['#text'])) {
        $text = $field['value']['#text'];
      }
      elseif (isset($field[0]['value']['#text'])) {
        $text = $field[0]['value']['#text'];
      }

      //@TODO: Check this.
      if (!empty($text)) {
        $this->startElement('DynamicElement');
        $this->writeAttribute('dynamicElementKind', 'TextArea');
        $this->writeAttribute('indexType', $item->item_type);
        $this->writeAttribute('instanceId', $item->item_id);
        $this->writeAttribute('name', $key);
        $this->writeAttribute('repeatable', 'false');
        $this->startElement('DynamicContent');
        $this->writeCdata($text);
        // </DynamicContent>
        $this->endElement();
        // </DynamicElement>
        $this->endElement();
      }
    }
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

    $job_items = OshaTMGMTStatistics::getUniqueItems($job);

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

    foreach ($job_items as $item_type => $item_ids) {
      foreach ($item_ids as $item_id => $item) {
        $this->addItem($item, $job);
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
   * {@inheritdoc}
   */
  public function import($imported_file) {
    $this->getImportedXML($imported_file);
    //TODO:EDW:CHECK
    $tjid = $this->importedXML->xpath("//TransactionIdentifier:phase[@phase-name='extraction']");
    $tjid = reset($tjid);
    $job = tmgmt_job_load((string) $tjid);
    return tmgmt_unflatten_data($this->getImportedTargets($job));
  }

  /**
   * Validates imported XLIFF file.
   *
   * Checks:
   * - Job ID.
   * - Target ans source languages
   * - Content integrity by
   */
  public function validateImport($imported_file) {
    $xml = $this->getImportedXML($imported_file);
    // Check if our phase information is there.
    $phase = $xml->xpath("//TransactionIdentifier:phase[@phase-name='extraction']");
    if ($phase) {
      $phase = reset($phase);
    }
    else {
      return FALSE;
    }

    // Check if the job can be loaded.
    if (!isset($phase['job-id']) || (!$job = tmgmt_job_load((string) $phase['job-id']))) {
      return FALSE;
    }

    // Compare source language.
    if (!isset($xml->file['source-language']) || $job->getTranslator()->mapToRemoteLanguage($job->source_language) != $xml->file['source-language']) {
      return FALSE;
    }

    // Compare target language.
    if (!isset($xml->file['target-language']) || $job->getTranslator()->mapToRemoteLanguage($job->target_language) != $xml->file['target-language']) {
      return FALSE;
    }

    $targets = $this->getImportedTargets($job);

    if (empty($targets)) {
      return FALSE;
    }

    $reader = new XMLReader();

    foreach ($targets as $id => $target) {
      $count = 0;
      $reader->XML('<Translation>' . $target['#text'] . '</Translation>');
      while ($reader->read()) {
        if (in_array($reader->name, array('Translation', '#text'))) {
          continue;
        }
        $count++;
      }
    }

    // Validation successful.
    return $job;
  }

  protected function getImportedXML($imported_file) {
    if (empty($this->importedXML)) {
      // It is not possible to load the file directly with simplexml as it gets
      // url encoded due to the temporary://. This is a PHP bug, see
      // https://bugs.php.net/bug.php?id=61469
      $xml_string = file_get_contents($imported_file);
      $this->importedXML = simplexml_load_string($xml_string);
      // Register the XLIFF namespace, required for xpath.
      $this->importedXML->registerXPathNamespace('xliff', 'urn:oasis:names:tc:xliff:document:1.2');
    }

    return $this->importedXML;
  }

  protected function getImportedTargets(TMGMTJob $job) {
    if (empty($this->importedXML)) {
      return FALSE;
    }

    if (empty($this->importedTransUnits)) {
      $reader = new XMLReader();
      foreach ($this->importedXML->xpath('//xliff:trans-unit') as $unit) {
        $reader->XML($unit->target->asXML());
        $reader->read();
        $this->importedTransUnits[(string) $unit['id']]['#text'] =
          $this->processForImport($reader->readInnerXML(), $job);
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
    // In case we do not want to do xliff processing return the translation as
    // is.
    if (!$job->getSetting('xliff_processing')) {
      return $translation;
    }

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