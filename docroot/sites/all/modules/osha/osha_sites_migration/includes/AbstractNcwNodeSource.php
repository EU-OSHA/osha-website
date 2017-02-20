<?php

/**
 * Class AbstractNCWNodeSource base for all NCW JSON node imports.
 */
abstract class AbstractNCWNodeSource extends MigrateSource {

  protected $endpoint_url = NULL;
  protected $rows = array();
  protected $count = -1;
  protected $skip_ids = array();
  protected $site_source;

  public function __construct($options) {
    parent::__construct($options);
    $this->endpoint_url = $options['endpoint_url'];
    if (!empty($options['skip_ids'])) {
      $this->skip_ids = $options['skip_ids'];
    }
    if (!empty($options['site_source'])) {
      $this->site_source = $options['site_source'];
    }
  }

  /**
   * Return a string representing the source, for display in the UI.
   */
  public function __toString() {
    return 'Extract data from Other websites endpoint';
  }

  /**
   * Total number of entities.
   */
  public function computeCount() {
    osha_sites_migration_debug('!klass: Starting counting !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    if ($this->count == -1) {
      $data = $this->fileGetContents($this->endpoint_url);
      $this->count = 0;
      if ($data = json_decode($data)) {
        if (!empty($data->items)) {
          $data = $data->items;
          foreach ($data as $ob) {
            $ob = $ob->item;
            $id = $this->itemIdentifier($ob);
            if (!in_array($id, $this->skip_ids)) {
              $this->count++;
            }
          }
        }
      }
    }
    osha_sites_migration_debug('!klass: Found !count items', array('!klass' => get_class($this), '!count' => $this->count));
    return $this->count;
  }

  /**
   * Do whatever needs to be done to start a fresh traversal of the source data.
   *
   * This is always called at the start of an import, so tasks such as opening
   * file handles, running queries, and so on should be performed here.
   */
  public function performRewind() {
    reset($this->rows);
  }

  /**
   * Fetch the next row of data, returning it as an object.
   *
   * @return object
   *   FALSE data as stdClass, FALSE when there is no more data available.
   */
  public function getNextRow() {
    if (empty($this->rows)) {
      $this->readData();
    }
    $item = NULL;
    if (count($this->rows)) {
      $item = current($this->rows);
      next($this->rows);
    }
    return $item;
  }

  /**
   * Remote call to load the data from the endpoint URL
   */
  public function readData() {
    osha_sites_migration_debug('!klass: Starting reading items from !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      osha_sites_migration_debug('!klass:      * Processing !count items', array('!klass' => get_class($this), '!count' => count($data->items)));
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        if (in_array($id, $this->skip_ids)) {
          continue;
        }
        $node_url = $this->itemURL($id);
        osha_sites_migration_debug('!klass:      * Reading item: !url', array('!klass' => get_class($this), '!url' => $node_url));
        if ($rowd = $this->fileGetContents($node_url)) {
          if ($row_ob = json_decode($rowd, TRUE)) {
            $row = new stdClass();
            foreach($row_ob as $k => $v) {
              $row->$k = $v;
            }
            $this->rows[$id] = $row;
          }
        }
        else {
          $msg = format_string('Failed to read data from !url', array('!url' => $node_url));
          watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
          $this->rows[$id] = NULL;
        }
      }
    }
    else {
      $msg = format_string('Failed to read data from !url', array('!url' => $this->endpoint_url));
      watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
      throw new MigrateException($msg, Migration::MESSAGE_ERROR);
    }
    osha_sites_migration_debug('!klass: Done reading items', array('!klass' => get_class($this)));
    reset($this->rows);
  }

  public function fileGetContents($url) {
    //@todo replace all instances of fileGetContents
    return ncw_migration_file_get_contents($url);
  }

  public function itemURL($id) {
    return ncw_migration_datasource_url($this->site_source) . '/export/node/' . $id;
  }

  public function itemIdentifier($ob) {
    return $ob->nid;
  }

  public function fields() {
    return array(
        'nid' => 'nid',
        'title' => 'title',
        'created' => 'created',
        'changed' => 'changed',
        'status' => 'status',
        'promote' => 'promote',
        'sticky' => 'sticky',
        'log' => 'log',
        'language' => 'language',
        'path' => 'path',
      ) + $this->contentFields();
  }

  /**
   * Check the provided ID exists in the migrated source.
   *
   * @param mixed $id
   *   ID to verify
   *
   * @return bool
   *   TRUE if the key exists, FALSE otherwise
   */
  public function containsKey($id) {
    return array_key_exists($id, $this->rows);
  }

  public abstract function contentFields();
}
