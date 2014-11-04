<?php

define("ID_PREFIX", "tmgmt-");

class OshaTMGMTRetranslate {

  /**
   * Add data-translation-id for level 1 HTML elements
   */
   public static function prepare_text($text) {
     if (empty($text)) {
       return $text;
     }
     $items = self::getDOMNodeList($text);
     // Get all existing ID's and compute max
     $max = 0;
     for($i = 0; $i < $items->length; $i++) {
       if (get_class($items->item($i)) != 'DOMElement' ) {
         // ignore text between tags and comments, can happen during migration
         continue;
       }
       $id = $items->item($i)->getAttribute('id');
       if (!empty($id) && !preg_match('/^'.ID_PREFIX.'/', $id)) {
         // invalid id, remove it
         $items->item($i)->removeAttribute('id');
         $id = NULL;
       }
       if (!empty($id)) {
         $max = max(substr($id, strlen(ID_PREFIX)), $max);
       }
     }
     // Once again, and set id's where we have new tags
     $current_id = $max+1;
     for($i = 0; $i < $items->length; $i++) {
       $item = $items->item($i);
       if (get_class($items->item($i)) != 'DOMElement' ) {
         // ignore text between tags and comments, can happen during migration
         continue;
       }
       if (empty($item->getAttribute('id'))) {
         $item->setAttribute('id', ID_PREFIX.($current_id++));
       }
     }
     
     return self::getHTML($items);
  }
  
  public static function getDOMDocument($text) {
     $DOM = new DOMDocument;
     libxml_use_internal_errors(true);
     $text = mb_convert_encoding($text, 'HTML-ENTITIES', 'UTF-8');
     $DOM->loadHTML($text);
     libxml_clear_errors();
     return $DOM;
  }

  public static function getDOMNodeList($text) {
     $DOM = self::getDOMDocument($text);
     $body = $DOM->getElementsByTagName('body')->item(0);
     return $body->childNodes;
  }

  public static function getElementById($domNodeList, $id) {
    // Use this function instead of doc->getElementById, which needs to validate the DOM.
    // Validation requires HTTP access to http://www.w3.org/TR/REC-html40/loose.dtd
    if (!$domNodeList) {
      return NULL;
    }
    for($i = 0; $i < $domNodeList->length; $i++) {
      $item = $domNodeList->item($i);
      if (get_class($item) == 'DOMElement' && $item->getAttribute('id') == $id) {
        return $item;
      }
    }
    return NULL;
  }
  
  public static function getHTML($domNodeList) {
     $Document = new DOMDocument();
     for($i = 0; $i < $domNodeList->length; $i++) {
       $Document->appendChild($Document->importNode($domNodeList->item($i),true));
     }
     return html_entity_decode($Document->saveHTML());
  }

  public static function getHTMLStructure($text) {
    $items = self::getDOMNodeList($text);
    $structure = array();
    for($i = 0; $i < $items->length; $i++) {
      $item = $items->item($i);
      if (get_class($item) == 'DOMElement' ) {
        $structure[$item->getAttribute('id')] = $item->tagName;
      }
    }
    return $structure;
  }

  /*
   * Set checkbox if a revision has been translated and body has been changed
   */
  public static function mark_dirty($node) {
    $node_lang = $node->translations->original;
    if (empty($node->body[$node_lang])) {
      return;
    }
    $new_text = $node->body[$node_lang][0]['value'];
    if (!isset($node->original->body[$node_lang])) {
      // no body before
      $old_text = '';
    } else {
      $old_text = $node->original->body[$node_lang][0]['value'];
    }
    $new_text_plain = preg_replace("/\s+/", "", strip_tags($new_text));
    $old_text_plain = preg_replace("/\s+/", "", strip_tags($old_text));
    if ( $new_text_plain != $old_text_plain) {
      $node->field_needs_retranslation[LANGUAGE_NONE][0]['value'] = 1;
    }
  }

  /*
   * Returns latest revision where original language is synchronized with translations
   */
  public static function get_latest_clean_revision($entity_id) {
    $rev = db_query("SELECT MAX(f.revision_id) FROM {field_revision_field_needs_retranslation} f
      WHERE f.entity_id = :entity_id AND f.field_needs_retranslation_value = 0",
      array(':entity_id' => $entity_id)
    )->fetchField();
    if (!$rev) {
      // No clean revision found, probably field_needs_retranslation_value was not there
      // Return the first available revision
      $rev = db_query("SELECT MIN(nr.vid) FROM {node_revision} nr WHERE nr.nid = :entity_id",
        array(':entity_id' => $entity_id)
      )->fetchField();
    }
    return $rev;
  }
  
  /*
   * Returns latest revision where original language is synchronized with translations
   */
  public static function get_latest_revision($entity_id) {
    $count = db_query("SELECT MAX(f.revision_id) FROM {field_revision_field_needs_retranslation} f
      WHERE f.entity_id = :entity_id",
      array(':entity_id' => $entity_id)
    )->fetchField();
    return $count;
  }

  public static function get_field_value($entity_id, $bundle, $revision, $lang = 'en', $field_name = 'body') {
    $entities = array(
      $entity_id => (object)array(
        'type' => $bundle, 'nid' => $entity_id, 'vid' => $revision,
      ),
    );
    $fields = field_info_instances('node', $bundle);
    $field_id = $fields[$field_name]['field_id'];
    field_attach_load_revision('node', $entities, array('field_id' => $field_id));
    $field = $entities[$entity_id]->$field_name;
    if (!isset($field[$lang])) {
      return NULL;
    }
    if (isset($field[$lang][0]['fid'])) {
      // @todo handle files and image
      return NULL;
    }
    return $field[$lang][0]['value'];
  }
  
  public static function get_changed_ids($old_text, $new_text) {
    $old_items = self::getDOMNodeList($old_text);
    $new_items = self::getDOMNodeList($new_text);
    // Array of element id's
    $changes = array();
    for($i = 0; $i < $new_items->length; $i++) {
      $new_item = $new_items->item($i);
      if (get_class($new_item) != 'DOMElement') {
        continue;
      }
      $new_id = $new_item->getAttribute('id');
      // Check if added or existing
      $old_item = self::getElementById($old_items, $new_id);
      if (!$old_item || $old_item->nodeValue !== $new_item->nodeValue ) {
        $changes[] = $new_id;
      }
    }
    return $changes;
  }
  
  public static function get_text_to_retranslate($entity_id, $bundle, $source_lang, $target_lang, $field_name = 'body') {
    $revision = self::get_latest_revision($entity_id);
    $clean_revision = self::get_latest_clean_revision($entity_id);

    // This is the latest version in the source language
    $source_text = self::get_field_value($entity_id, $bundle, $revision, $source_lang, $field_name);
    if (!$clean_revision) {
      // All text must be translated
      return $source_text;
    }
    // This is the most recent version that has been already translated
    $clean_source_text = self::get_field_value($entity_id, $bundle, $clean_revision, $source_lang, $field_name);
    // If field is not body, check if it has been changed in the source language
    if ($field_name != 'body' && $source_text != $clean_source_text) {
        return $source_text;
    }
    // For body, get the different paragraphs only
    // The latest version in the target language
    $translated_text = self::get_field_value($entity_id, $bundle, $revision, $target_lang, $field_name);
    if (!$translated_text) {
      return $source_text;
    }
    if ($field_name != 'body') {
      // If we got here for other fields it means that target_lang exists,
      // but field has not been changed, so no retranslation is needed
      return NULL;
    }

    // This is just a list of element id's (changed or added in the source language)
    $changed_ids = self::get_changed_ids($clean_source_text, $source_text);

    $translated_items = self::getDOMNodeList($translated_text);
    // Changed/added elements will be added here
    $changes = new DOMDocument();
    $source_items = self::getDOMNodeList($source_text);
    for($i = 0; $i < $source_items->length; $i++) {
      $source_item = $source_items->item($i);
      if (get_class($source_item) != 'DOMElement') {
        continue;
      }
      if ( in_array($source_item->getAttribute('id'), $changed_ids) ) {
        // this element has been changed in source language, so it is added by default
        $changes->appendChild($changes->importNode($source_item, true));
      } else if (!self::getElementById($translated_items, $source_item->getAttribute('id'))) {
        // This item does not exist at all in the translated version
        $changes->appendChild($changes->importNode($source_item,true));
      }
    }
    if ($changes->hasChildNodes()) {
      return html_entity_decode($changes->saveHTML());
    } else {
      return NULL;
    }
  }
  
  /**
    * Input: $node->nid
    * The latest clean revision is returned in $revision
    * Status messages are returned in array $messages[key => severity_level]
    * Results are returned in arrays $valid_languages and $invalid_languages, keyed by language code
    * @todo Check all full_html fields, not only in body!
    */
  public static function validate_can_retranslate(&$node, &$vid, &$messages, &$valid_languages, &$invalid_languages) {
    if (!$vid) {
      $vid = self::get_latest_clean_revision($node->nid);
    }
    if (!isset($node->nid)) {
      throw new TMGMTException('node->nid not provided');
    }
    $node = node_load($node->nid, $vid);
    if (empty($node->body)) {
      // no body
      $messages['warning'] = t('Empty node body in initial revision.');
      return;
    }
    $orig_lang = $node->translations->original;
    $orig_structure = self::getHTMLStructure($node->body[$orig_lang][0]['value']);
    $languages = array_keys($node->body);
    if (count($languages) == 1 ) {
      $messages['warning'] = t('Node has no translations');
      return;
    }
    $valid_languages = array();
    foreach ($languages as $lang) {
      if ($lang == $orig_lang) {
        continue;
      }
      $html = $node->body[$lang][0]['value'];
      $translated_structure = self::getHTMLStructure($html);
      // Search for id's that are present in $translated_structure but with different tags
      $diffs = array();
      foreach ($orig_structure as $id => $tag) {
        if (isset($translated_structure[$id]) && $tag != $translated_structure[$id]) {
          $diffs[$id] = $translated_structure[$id];
        }
      }
      // $diffs contains tags that exist in source language but not in target language
      if (!empty($diffs)) {
        $first_diff = current(array_keys($diffs));
        // See if that element id exists in translation
        $first_diff_in_trans = NULL;
        if (isset($translated_structure[$first_diff])) {
          $first_diff_in_trans = $translated_structure[$first_diff];
        }
        // Add first different tag in returned data
        $invalid_languages[$lang] = array(
          'id' => $first_diff,
          'source' => $orig_lang,
          $orig_lang => $diffs[$first_diff],
          $lang => $first_diff_in_trans,
        );
      } else {
        // Check if target language contains more tags
        foreach ($translated_structure as $id => $tag) {
          if (!isset($orig_structure[$id])) {
            $diffs[$id] = $tag;
          }
        }
        if (!empty($diffs)) {
          $first_diff = current(array_keys($diffs));
          // Add first different tag in returned data (non-existing in source lang?)
          $invalid_languages[$lang] = array(
            'id' => $first_diff,
            'source' => $orig_lang,
            $orig_lang => NULL,
            $lang => $diffs[$first_diff]
          );
        } else {
          $valid_languages[] = $lang;
        }
      }
    }
    if (!empty($valid_languages)) {
      $messages['status'] = t('Node can be re-translated in ')
        .implode(", ", array_map('strtoupper', $valid_languages));
    }
    if (!empty($invalid_languages)) {
      $messages['error'] = t('Node cannot be re-translated in ')
        .implode(", ", array_map('strtoupper', array_keys($invalid_languages)));
    }
  }

  /**
   * @param string $new_translation contains the translated changes
   * @param string $old_translation represents the old translation
   * @param string $source_text represents the full text in the source language
   */
  public static function get_merged_translation($new_translation, $old_translation, $source_text) {
    $orig_structure = self::getHTMLStructure($source_text);
    $new_items = self::getDOMNodeList($new_translation);
    $old_items = self::getDOMNodeList($old_translation);
    $result = new DOMDocument();
    foreach ($orig_structure as $id => $tag) {
      // Follow the structure of the source language
      $item = self::getElementById($new_items, $id);
      if ($item) {
        // Found in new translation, now check if the same tag
        if ($item->tagName == $tag) {
          $result->appendChild($result->importNode($item,true));
        } else {
          // We have a different tag in the translation, raise error
          throw new TMGMTException('Element @id is a <@tag_new> instead of <@tag_old>.',
            array('@id' => $id, '@tag_new' => $item->tagName, '@tag_old' => $tag));
        }
      } else {
        // Item not found in translation, re-use the old one
        $item = self::getElementById($old_items, $id);
        if ($item) {
          $result->appendChild($result->importNode($item,true));
        } else {
          // We don't have this tag at all, raise error
          throw new TMGMTException('<@tag id="@id"> not included in translation.',
            array('@id' => $id, '@tag' => $tag));
        }
      }
    }
    // Check for extra tags in the translated text
    // not using getHTMLStructure to avoid the re-creation of a node
    for($i = 0; $i < $new_items->length; $i++) {
      $item = $new_items->item($i);
      if (get_class($item) == 'DOMElement' ) {
        $id = $item->getAttribute('id');
        // Should exist in $orig_structure
        if (!isset($orig_structure[$id])) {
          throw new TMGMTException('Unexpected element <@tag id="@id"> in translation.',
            array('@id' => $id, '@tag' => $item->tagName));
        }
      }
    }
    return html_entity_decode($result->saveHTML());
  }

  public static function apply_partial_translation($node, $job_data, $source_lang, $target_lang) {
    // Get old_translation from latest clean version
    $revision = self::get_latest_clean_revision($node->nid);
    if (!$revision) {
      return $job_data;
    }
    foreach ($job_data as $field => $field_data) {
      if ($field == 'body') {
        // Get full reference text from source lang of latest revision
        $source_text = $node->{$field}[$source_lang][0]['value'];
        $old_translation = self::get_field_value($node->nid, $node->type, $revision, $target_lang, $field);
        if (!$old_translation) {
          // $new_translation contains the entire needed text
          continue;
        }
        // Get new translation from job data
        $new_translation = $field_data[0]['value']['#translation']['#text'];
        $source_lang = $node->translations->original;
        $result = self::get_merged_translation($new_translation, $old_translation, $source_text);
        // Write it in job data (must return it, array is passed by value in this function)
        $job_data[$field][0]['value']['#translation']['#text'] = $result;
      }
    }
    // Return the array, passed by value
    return $job_data;
  }
}