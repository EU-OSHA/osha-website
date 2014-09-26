<?php

class OshaMigrateWiki extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Wiki'));
    $this->arguments = $arguments;
    $this->description = 'Import wiki articles from oshawiki.eu';

    $url = 'http://oshwiki.eu/index.php?title=Special%3AAsk&q=%5B%5B%3A%2B%5D%5D&po=%3FModification+date%0D%0A%3FCategory%0D%0A%3FMaster+page%0D%0A%3FModification+date%0D%0A%3FLanguage+code%0D%0A%3FNP%0D%0A%3FOP%0D%0A&eq=yes&p%5Bformat%5D=json&sort_num=&order_num=ASC&p%5Blink%5D=subject&p%5Bsort%5D=Modification+date&p%5Border%5D%5Bdesc%5D=1&p%5Bheaders%5D=show&p%5Bmainlabel%5D=&p%5Bintro%5D=&p%5Boutro%5D=&p%5Bsearchlabel%5D=&p%5Bdefault%5D=&p%5Bsyntax%5D=standard&eq=yes';
    $this->source = new OshaMigrateSourceWiki($url, array(
        'skip_count' => TRUE,
      )
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Wiki page title',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->destination = new MigrateDestinationNode(OSHA_WIKI_CONTENT_TYPE);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    #$this->addFieldMapping('created', 'created');
    #$this->addFieldMapping('field_updated', 'updated');
    #$this->addFieldMapping('field_tags', 'categories');
    $this->addFieldMapping('field_tags:source_type', 'tid');
    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('field_wiki_page_url', 'url');
  }

  /**
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_CONTENT_TYPE_WIKI;
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    // Decode categories.
    $categories = array();
    foreach ($row->categories as $cat_name) {
      $term_id = MigrationUtil::findTermByFieldValue($cat_name, 'name', TRUE);
      if ($term_id) {
        $term = taxonomy_term_load($term_id);
        if (!empty($term->field_tags[LANGUAGE_NONE][0]['tid'])) {
          foreach ($term->field_tags[LANGUAGE_NONE] as $v) {
            $categories[] = $v['tid'];
          }
        }
      }
      else {
        $this->currentMigration()->queueMessage('Could not find term from wiki_categories: ' . $cat_name);
      }
    }
    $row->categories = $categories;
  }

  /**
   * Called by destination right before saving.
   *
   * @param object $entity
   *   Entity to save
   * @param object $row
   *   Source row
   */
  public function prepare($entity, $row) {

    $migration = Migration::currentMigration();
    $languages = array_keys(language_list());
    $entity_type = $migration->getDestination()->getEntityType();

    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $entity->translations = $translation_handler->getTranslations();

    if (!empty($row->categories)) {
      //@todo: Remove manual assignment.
      foreach ($row->categories as $i => $cat) {
        $entity->field_tags[LANGUAGE_NONE][$i]['tid'] = $cat;
      }
    }

    foreach ($languages as $language) {
      $has_translation = FALSE;
      if (!empty($row->ml_title_field[$language])) {
        $entity->title_field[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->ml_title_field[$language]);
        $has_translation = TRUE;
      }
      if (!empty($row->ml_body[$language])) {
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->ml_body[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->ml_summary[$language])) {
        $entity->field_summary[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->ml_summary[$language]);
        $entity->field_summary[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->ml_url[$language])) {
        $entity->field_wiki_page_url[$language][0]['url'] = $row->ml_url[$language];
        $has_translation = TRUE;
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
  }
}


class OshaMigrateSourceWiki extends MigrateSource {

  protected static $templateUrl = 'http://oshwiki.eu/index.php?title=Special%3AAsk&q=%5B%5B%3A%2B%5D%5D&po=%3FModification+date%0D%0A%3FCategory%0D%0A%3FMaster+page%0D%0A%3FModification+date%0D%0A%3FLanguage+code%0D%0A%3FNP%0D%0A%3FOP%0D%0A&eq=yes&p%5Bformat%5D=json&sort_num=&order_num=ASC&p%5Blimit%5D=5&p%5Boffset%5D=2&p%5Blink%5D=subject&p%5Bsort%5D=Modification+date&p%5Border%5D%5Bdesc%5D=1&p%5Bheaders%5D=show&p%5Bmainlabel%5D=&p%5Bintro%5D=&p%5Boutro%5D=&p%5Bsearchlabel%5D=&p%5Bdefault%5D=&p%5Bsyntax%5D=standard&p%5Bprettyprint%5D=1&eq=yes';
  protected $url;
  protected $serviceQueried = FALSE;
  protected $data = array();

  /**
   * {@inheritdoc}
   */
  public function __construct($url, array $options = array()) {
    parent::__construct($options);
    $this->url = $url;
  }

  /**
   * Return a string representing the source, for display in the UI.
   */
  public function __toString() {
    return t(
      "Extract pages from wiki using semantic search. Handles pagination. Query example: <a target='_blank' href='!url'>Open</a>",
      array('!url' => self::$templateUrl)
    );
  }

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function fields() {
    return array(
      'title' => t('Wiki english page title'),
      'title_field' => t('Wiki localized page title'),
      'body' => t('Wiki page content localized'),
      'created' => t('Date when page was created'),
      'updated' => t('Date when page was last modified'),
      'parent' => t('English title of the parent page'),
      'language' => t('Language code'),
      'nace' => t('Nace codes'),
      'thesaurus' => t('Thesaurus codes'),
      'url' => t('Page URL'),
    );
  }

  /**
   * Return the number of available source records.
   */
  public function computeCount() {
    // @todo pre-search for all records without fields to compute all nodes for pagination.
    return 0;
  }

  /**
   * Do whatever needs to be done to start a fresh traversal of the source data.
   *
   * This is always called at the start of an import, so tasks such as opening
   * file handles, running queries, and so on should be performed here.
   */
  public function performRewind() {
    reset($this->data);
  }

  /**
   * Fetch the next row of data, returning it as an object.
   *
   * @return object
   *   FALSE data as stdClass, FALSE when there is no more data available.
   */
  public function getNextRow() {
    if (empty($this->data)) {
      $this->pullRemoteData();
    }
    return next($this->data);
  }

  /**
   * Query the remote source and pull the data.
   */
  protected function pullRemoteData() {
    /* @todo Implement remote filtering
     * $last = variable_get('osha_wiki_last_migration', FALSE)
     * Send this filter so only pull the content created/updated after this date
     */
    if (!$this->serviceQueried) {
      $this->data = array();
      $this->serviceQueried = TRUE;

      $pretty_print = TRUE;
      $base_url = 'http://oshwiki.eu/index.php?title=Special%3AAsk&q=%5B%5B%3A%2B%5D%5D&po=%3FModification+date%0D%0A%3FCategory%0D%0A%3FMaster+page%0D%0A%3FModification+date%0D%0A%3FLanguage+code%0D%0A%3FNP%0D%0A%3FOP%0D%0A&eq=yes&p%5Bformat%5D=json&sort_num=&order_num=ASC&p%5Blink%5D=subject&p%5Bsort%5D=Modification+date&p%5Border%5D%5Bdesc%5D=1&p%5Bheaders%5D=show&p%5Bmainlabel%5D=&p%5Bintro%5D=&p%5Boutro%5D=&p%5Bsearchlabel%5D=&p%5Bdefault%5D=&p%5Bsyntax%5D=standard&eq=yes';
      if ($pretty_print) {
        $base_url .= '&p%5Bprettyprint%5D=1';
      }
      // Result offset and page size.
      $page_size = variable_get('osha_wiki_migration_pagesize', 100);
      $base_url .= '&p%5Blimit%5D=' . $page_size;
      // @todo: implement pagination
      $pages = 4;

      for ($i = 0; $i < $pages; $i++) {
        try {
          $this->setMessage("Processing results page $i", MigrationBase::MESSAGE_INFORMATIONAL);
          $url = $base_url . $base_url .= '&p%5Boffset%5D=' . ($i * $page_size);
          $content = file_get_contents($url);
          $content = json_decode($content, TRUE);
          if (isset($content['results'])) {
            foreach ($content['results'] as $key => $data) {
              if ($this->validateDataRow($key, $data)) {
                $parent = $data['printouts']['Master page'][0]['fulltext'];
                $language = $data['printouts']['Language code'][0];
                $url = 'http:' . $data['fullurl'];

                //@todo: Remove hard-coding
                $page_id = str_replace('//oshwiki.eu/wiki/', '', $data['fullurl']);
                // Deal with translations.
                if ($language != 'en') {
                  if (array_key_exists($parent, $this->data)) {
                    $ob = $this->data[$parent];
                  }
                  else {
                    $ob = new stdClass();
                    $ob->title = $key;
                    $ob->language = $language;
                    $ob->translations[] = $language;
                  }
                }
                else {
                  $ob = new stdClass();
                  $ob->language = 'en';
                  $ob->title = $key;
                }

                $body = $this->getWikiPageContent($page_id);
                $summary = '';
                if (strlen($body)) {
                  $summary = explode('\n', $body);
                  $summary = array_filter($summary);
                  $summary = array_slice($summary, 0, 5);
                  foreach ($summary as &$line) {
                    $line = preg_replace('/==/', '<h2>', $line, 1);
                    $line = preg_replace('/==/', '</h2>', $line, 1);
                  }
                  $summary = implode('\n', $summary);
                }

                $ob->categories = array();
                if (!empty($data['printouts']['Category'])) {
                  foreach ($data['printouts']['Category'] as $cat_data) {
                    $cat_name = str_replace('Category:', '', $cat_data['fulltext']);
                    $ob->categories[] = $cat_name;
                  }
                }
                $ob->ml_summary[$language] = $summary;
                $ob->ml_body[$language] = $body;
                $ob->ml_title_field[$language] = $key;
                $ob->updated = '';
                if (!empty($data['printouts']['Modification date'][0])) {
                  $ob->updated = $data['printouts']['Modification date'][0];
                }
                $ob->parent = $parent;
                $ob->ml_url[$language] = $url;
                // @todo Add fields
                $ob->created = '';
                $ob->nace = '';
                $ob->thesaurus = '';
                if ($language == 'en') {
                  $this->data[$parent] = $ob;
                }
              }
            }
          }
          else {
            continue;
          }
        }
        catch(Exception $e) {
          $msg = sprintf('Error retrieving remote wiki data for page %s (%s) ', $i, $e->getMessage());
          $this->setMessage($msg, MigrationBase::MESSAGE_ERROR);
        }
      }
    }
  }


  function getWikiPageContent($page_id) {
    $url = sprintf('http://oshwiki.eu/api.php?action=parse&format=json&prop=wikitext&page=%s', $page_id);
    $data = drupal_http_request($url);
    if (isset($data) && $data->code == 200) {
      $content = json_decode($data->data, TRUE);
      if (!empty($content['parse']['wikitext']['*'])) {
        $text = $content['parse']['wikitext']['*'];
        if($pos = strpos($text, "==")) {
          $text = substr($text, $pos);
        }
        return $text;
      }
    }
    return '';
  }

  /**
   * Add messages during data retrieval for debugging.
   *
   * @param string $msg
   *   Message string
   * @param int $severity
   *   Migration message level
   */
  protected function setMessage($msg, $severity = MigrationBase::MESSAGE_WARNING) {
    drupal_set_message($msg);
    $this->activeMigration->queueMessage($msg, $severity);
  }

  /**
   * Check if row is importable.
   *
   * @param string $key
   *   Page title
   * @param array $data
   *   Actual data to validate
   *
   * @return bool
   *   TRUE if data is valid
   */
  protected function validateDataRow($key, $data) {
    if (empty($data['printouts']['Language code'][0])) {
      $this->setMessage('Skipping record without language: ' . $key);
      return FALSE;
    }
    if (empty($data['printouts']['Master page'][0]['fulltext'])) {
      $this->setMessage('Skipping record without title: ' . $key);
      return FALSE;
    }
    if (empty($data['fullurl'])) {
      $this->setMessage('Skipping record URL: ' . $key);
      return FALSE;
    }
    $parent = $data['printouts']['Master page'][0]['fulltext'];
    if ($data['printouts']['Language code'][0] != 'en' && empty($parent)) {
      $this->setMessage('Translation has no parent page: ' . $key);
      return FALSE;
    }
    return TRUE;
  }
}
