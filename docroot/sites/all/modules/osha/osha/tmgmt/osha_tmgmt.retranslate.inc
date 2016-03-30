<?php

define("ID_PREFIX", "tmgmt-");


function osha_tmgmt_retranslate_ui_form($form, &$form_state, $node) {
  $form = array();
  $form['#node'] = $node;
  $form['title']['#markup'] = theme('html_tag', array('element' => array('#tag' => 'h1', '#value' => 'Re-translation for ' . $node->title)));
  $form['desc']['#markup'] = 'Choose the fields and text that you want to re-translate';

  $trans_lang = array_keys($node->translations->data);
  unset($trans_lang['en']);
  if (empty($trans_lang)) {
    drupal_set_message('The node it is not translated so you cannot re-translate.', 'warning');
    drupal_goto('node/' . $node->nid . '/translate');
  }

  // Validate retranslation.
  $messages = array();
  $valid_languages = array();
  $invalid_languages = array();
  OshaTMGMTRetranslate::validate_can_retranslate($node, $messages, $valid_languages, $invalid_languages);
  foreach ($messages as $severity => $message_list) {
    foreach ($message_list as $message) {
      drupal_set_message($message, $severity);
    }
  }
  if (!empty($invalid_languages)) {
    $details = array();
    foreach ($invalid_languages as $lang => $data) {
      $details[$lang] = sprintf("Different HTML at id = '%s', <%s> in %s, <%s> in %s",
        $data['id'],
        $data[$data['source']], strtoupper($data['source']),
        $data[$lang], strtoupper($lang));
    }
    if (!empty($details)) {
      drupal_set_message('<pre>'.htmlspecialchars(print_r($details, TRUE)).'</pre>', 'warning');
    }
    drupal_goto('node/' . $node->nid . '/translate');
  }

  $plugin = 'entity';
  $item_type = 'node';
  $item_id = $node->nid;
  $cart = tmgmt_ui_cart_get();
  $in_cart = $cart->isSourceItemAdded($plugin, $item_type, $item_id);

  $existing_job_items = $cart->getJobItemsFromCart();
  $retranslation_data = array();
  $is_retranslation = FALSE;
  $is_full_translation = FALSE;
  if ($in_cart) {
    foreach ($existing_job_items as $job_item) {
      if ($job_item->item_type == 'node'
        && $job_item->item_id == $node->nid) {
        $form['#job_item'] = $job_item;
        if (!empty($job_item->retranslation_data)) {
          $retranslation_data = unserialize($job_item->retranslation_data);
          $is_retranslation = TRUE;
        }
        if (!empty($job_item->is_full_translation)) {
          $is_full_translation = TRUE;
        }
      }
    }
    if ($is_full_translation) {
      drupal_set_message(strtr('Content is already in <a href="@url">cart</a> as full translation.', array('@url' => url('admin/tmgmt/cart'))), 'warning');
    }
    else if ($is_retranslation) {
      drupal_set_message(strtr('Content is already in <a href="@url">cart</a> as re-translation.', array('@url' => url('admin/tmgmt/cart'))), 'warning');
    }
  }

  $current = workbench_moderation_node_current_load($node);
  $wrapper_current = entity_metadata_wrapper('node', $current, array('langcode' => 'en'));
  $clean_revision = OshaTMGMTRetranslate::get_latest_clean_revision($node->nid);

  $fields = field_info_instances('node', $node->type);
  $form['#fields'] = array();
  foreach ($fields as $field_name => $field) {
    $field_info = field_info_field($field_name);
    if ($field_info['translatable'] && in_array($field_info['type'], array('text', 'text_with_summary', 'text_long'))) {
      $form['#fields'][] = $field_name;
      $value = $wrapper_current->{$field_name}->value();
      if (!empty($value)) {
        switch ($field_info['type']) {
          case 'text':
            $form[$field_name] = array(
              '#type' => 'checkbox',
              '#prefix' => '<label>' . $fields[$field_name]['label'] . '</label>',
              '#title' => $value,
            );
            if (!empty($retranslation_data[$field_name])) {
              $form[$field_name]['#default_value'] = TRUE;
            }
            else {
              $clean_source_text = OshaTMGMTRetranslate::get_field_value($node->nid, $node->type, $clean_revision, 'en', $field_name);
              if ($value != $clean_source_text) {
                $form[$field_name]['#default_value'] = TRUE;
              }
            }
            break;

          case 'text_with_summary':
            $value = $value['value'];
            $elem_ids = OshaTMGMTRetranslate::getHTMLStructure($value);
            $document = OshaTMGMTRetranslate::getDOMDocument($value);
            $options = array();
            $xpath = new DOMXPath($document);
            foreach ($elem_ids as $elem_id => $element_tag) {
              $dom_list = $xpath->query("//*[@id='" . $elem_id . "']");
              foreach ($dom_list as $dom_elem) {
                $options[$elem_id] = $document->saveHTML($dom_elem);
                break;
              }
            }
            $form[$field_name] = array(
              '#type' => 'checkboxes',
              '#title' => $fields[$field_name]['label'],
              '#options' => $options,
            );
            if (!empty($retranslation_data[$field_name])) {
              $form[$field_name]['#default_value'] = drupal_map_assoc($retranslation_data[$field_name]);
            }
            else {
              $clean_source_text = OshaTMGMTRetranslate::get_field_value($node->nid, $node->type, $clean_revision, 'en', $field_name);
              $changed_ids = OshaTMGMTRetranslate::get_changed_ids($clean_source_text, $value);
              if (!empty($changed_ids)) {
                $form[$field_name]['#default_value'] = array_values($changed_ids);
              }
            }
            break;

          case 'text_long':
            $form[$field_name] = array(
              '#type' => 'checkbox',
              '#prefix' => '<label>' . $fields[$field_name]['label'] . '</label>',
              '#title' => $value,
            );

            if (!empty($retranslation_data[$field_name])) {
              $form[$field_name]['#default_value'] = TRUE;
            }
            else {
              if ($value != $clean_source_text) {
                $clean_source_text = OshaTMGMTRetranslate::get_field_value($node->nid, $node->type, $clean_revision, 'en', $field_name);
                $form[$field_name]['#default_value'] = TRUE;
              }
            }
            break;
        }
      }
    }
  }

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'osha_tmgmt') . '/css/retranslation.css',
  );
  $form['submit'] = array(
    '#value' => 'Add to cart',
    '#type' => 'submit',
  );
  return $form;
}

function osha_tmgmt_retranslate_ui_form_submit(&$form, &$form_state) {
  $plugin = 'entity';
  $item_type = 'node';
  $item_id = $form['#node']->nid;
  $node = $form['#node'];

  $messages = array();
  $valid_languages = array();
  $invalid_languages = array();
  OshaTMGMTRetranslate::validate_can_retranslate($node, $messages, $valid_languages, $invalid_languages);
  if (!empty($invalid_languages)) {
    foreach ($messages['error'] as $message) {
      drupal_set_message($message, 'error');
      return;
    }
  }

  $values = $form_state['values'];
  $elements = array();
  foreach ($form['#fields'] as $field) {
    if (!empty($values[$field])) {
      if (is_array($values[$field])) {
        $elements[$field] = array_filter($values[$field]);
      }
      else {
        $elements[$field] = TRUE;
      }
    }
  }

  if (empty($form['#job_item'])) {
    $job_item = tmgmt_ui_cart_get()->addJobItem($plugin, $item_type, $item_id);
    if (empty($job_item)) {
      drupal_set_message('Content was not added to cart');
      return;
    }
  }
  else {
    $job_item = $form['#job_item'];
  }
  // Add retranslation data.
  $job_item->source_language = 'en';
  $job_item->target_language = 'es';
  $job_item->is_full_translation = 0;
  $job_item->retranslation_data = serialize($elements);
  $job_item->save();

  drupal_set_message(strtr('Content source was added into the <a href="@url">cart</a>.', array('@url' => url('admin/tmgmt/cart'))));
  $form_state['redirect'] = 'node/' . $node->nid . '/translate';
}

class OshaTMGMTRetranslate {

  /**
   * Add data-translation-id for level 1 HTML elements.
   */
  public static function prepare_text($text) {
    if (empty($text)) {
      return $text;
    }
    // Remove invalid existing ID's and compute max.
    $max = 0;
    $callback = function(&$item, &$max, $div_start, $div_end) {
      if ($div_start || $div_end) return;
      // First pass, compute max(id)
      $id = $item->getAttribute('id');
      if (!empty($id) && !preg_match('/^' . ID_PREFIX . '/', $id)) {
        // Invalid id, remove it.
        $item->removeAttribute('id');
        $id = NULL;
      }
      if (!empty($id)) {
        $max = max(substr($id, strlen(ID_PREFIX)), $max);
      }
    };
    $dom = self::getDOMDocument($text);
    $body = $dom->getElementsByTagName('body')->item(0);

    self::browseDOMRecursive($body->childNodes, $callback, $max);
    // Once again, and set id's where we have new tags.
    $callback = function(&$item, &$current_id, $div_start, $div_end) {
      if ($div_end) {
        return;
      }
      if ($div_start) {
        // backwards fix: remove old div id's
        $item->removeAttribute('id');
        return;
      }
      if (get_class($item) == 'DOMText') {
        $span = $item->ownerDocument->createElement('span', $item->textContent);
        $item->parentNode->replaceChild($span, $item);
        $item = $span;
      }
      $item_id = $item->getAttribute('id');
      if (empty($item_id)) {
        $item->setAttribute('id', ID_PREFIX . ($current_id++));
      }
    };
    $current_id = $max + 1;
    // invoke with $force_recurse_divs = TRUE
    self::browseDOMRecursive($body->childNodes, $callback, $current_id, TRUE, TRUE);
    return self::getHTML($body->childNodes);
  }

  public static function getDOMDocument($text) {
    $dom = new DOMDocument();
    libxml_use_internal_errors(TRUE);
    $text = mb_convert_encoding($text, 'HTML-ENTITIES', 'UTF-8');
    $dom->loadHTML($text);
    libxml_clear_errors();
    return $dom;
  }

  public static function getDOMNodeList($text) {
    if (empty($text)) {
      // Return empty array for empty text to avoid warnings
      return array();
    }
    $dom = self::getDOMDocument($text);
    $body = $dom->getElementsByTagName('body')->item(0);

    $result = array();
    $callback = function(&$item, &$result, $div_start, $div_end) {
      if ($div_start || $div_end) return;
      $id = $item->getAttribute('id');
      if (!empty($id)) {
        $result[$id] = $item;
      }
    };
    self::browseDOMRecursive($body->childNodes, $callback, $result);
    return $result;
  }

  public static function browseDOMRecursive(&$nodeList, &$callback, &$options, $force_recurse_divs = FALSE, $force_text_items = FALSE) {
    for ($i = 0; $i < $nodeList->length; $i++) {
      $item = $nodeList->item($i);
      if (get_class($item) == 'DOMText' && $force_text_items) {
        $callback($item, $options, FALSE, FALSE);
        continue;
      };
      if (get_class($item) != 'DOMElement') {
        // Ignore text between tags and comments, can happen during migration.
        continue;
      }
      if ($item->tagName == 'div') {
        // backwards compatibility check: if div has tmgmt-id, handle it the old way
        $div_id = $item->getAttribute('id');
        if (!$force_recurse_divs && !empty($div_id) && strpos($div_id, ID_PREFIX) === 0) {
          $callback($item, $options, FALSE, FALSE);
        } else {
          // $callback parameters: $item, $options, is begin div, is end div
          $callback($item, $options, TRUE, FALSE);
          self::browseDOMRecursive($item->childNodes, $callback, $options, $force_recurse_divs, $force_text_items);
          $callback($item, $options, FALSE, TRUE);
        }
      } else {
        $callback($item, $options, FALSE, FALSE);
      }
    }
  }

  public static function getHTML($domNodeList) {
    $dom = new DOMDocument();
    for ($i = 0; $i < $domNodeList->length; $i++) {
      $dom->appendChild($dom->importNode($domNodeList->item($i), TRUE));
    }
    return html_entity_decode($dom->saveHTML());
  }

  public static function getHTMLStructure($text) {
    $items = self::getDOMNodeList($text);
    $structure = array();
    foreach ($items as $id => $item) {
      $structure[$id] = $item->tagName;
    }
    return $structure;
  }

  /*
   * Return latest revision where original language is synchronized with translations.
   */
  public static function get_latest_clean_revision($entity_id) {
    // Get the latest published revision.
    $rev = db_query("SELECT MAX(vid) FROM {workbench_moderation_node_history} WHERE
      nid = :entity_id AND published=1" ,array(':entity_id' => $entity_id)
    )->fetchField();
    if (!$rev ) {
      $rev = db_query("SELECT MAX(nr.vid) FROM {node_revision} nr WHERE
      nr.nid = :entity_id AND status=1",array(':entity_id' => $entity_id)
      )->fetchField();
    }
    return $rev;
  }

  /*
   * Returns latest revision where original language is synchronized with translations.
   */
  public static function get_latest_revision($entity_id) {
    // Get the current revision from workbench moderation.
    $rev = db_query("SELECT MAX(vid) FROM {workbench_moderation_node_history} WHERE
      nid = :entity_id AND current=1" ,array(':entity_id' => $entity_id)
    )->fetchField();
    if (!$rev ) {
      // Get the latest available revision.
      $rev = db_query("SELECT MAX(nr.vid) FROM {node_revision} nr WHERE
        nr.nid = :entity_id", array(':entity_id' => $entity_id)
      )->fetchField();
    }
    return $rev;
  }

  public static function get_field_value($entity_id, $bundle, $revision,
                                         $lang = 'en', $field_name = 'body') {
    $entities = array(
      $entity_id => (object) array(
        'type' => $bundle,
        'nid' => $entity_id,
        'vid' => $revision,
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
      // @todo handle files and images
      return NULL;
    }
    if (isset($field[$lang][0]['url'])) {
      // Handle link field type
      // @todo check the import of translations
      return $field[$lang][0]['title'];
    }
    return $field[$lang][0]['value'];
  }

  public static function get_changed_ids($old_text, $new_text) {
    $old_items = self::getDOMNodeList($old_text);
    $new_items = self::getDOMNodeList($new_text);
    // Array of element id's
    $changes = array();
    foreach ($new_items as $new_id => $new_item) {
      // Check if added or existing.
      if (empty($old_items[$new_id])) {
        // Item is new.
        $changes[] = $new_id;
      } else {
        // Compare nodeValues without whitespace.

        $new_text_plain = preg_replace("/\s+/", "", $new_item->nodeValue);
        $old_text_plain = preg_replace("/\s+/", "", $old_items[$new_id]->nodeValue);
        if ( $new_text_plain !== $old_text_plain ) {
          $changes[] = $new_id;
        }
      }
    }
    return $changes;
  }

  public static function get_text_to_retranslate($entity_id, $bundle,
                                                 $source_lang, $target_lang,
                                                 $field_name = 'body') {
    $revision = self::get_latest_revision($entity_id);
    // This is the latest version in the source language.
    $source_text = self::get_field_value($entity_id, $bundle, $revision, $source_lang, $field_name);
    if (!workbench_moderation_node_type_moderated($bundle)) {
      // Node type is not moderated, always return text for full translation.
      return $source_text;
    }

    $clean_revision = self::get_latest_clean_revision($entity_id);

    if (!$clean_revision) {
      // All text must be translated.
      return $source_text;
    }
    // This is the most recent version that has been already translated.
    $clean_source_text = self::get_field_value($entity_id, $bundle, $clean_revision, $source_lang, $field_name);
    // If field is not body, check if has been changed in the source language.
    if ($field_name != 'body' && $source_text != $clean_source_text) {
      return $source_text;
    }
    // The latest published version in the target language.
    $translated_text = self::get_field_value($entity_id, $bundle, $clean_revision, $target_lang, $field_name);
    if (!$translated_text) {
      return $source_text;
    }
    if ($field_name != 'body') {
      // If we got here for other fields it means that target_lang exists,
      // but field has not been changed, so no re-translation is needed.
      return NULL;
    }
    return self::get_text_to_retranslate_plain($clean_source_text, $source_text, $translated_text);
  }

  public static function get_text_to_retranslate_plain($clean_source_text, $source_text, $translated_text) {
    // For body, get the different paragraphs only.
    // Just a list of element id's (changed or added in the source language).
    $changed_ids = self::get_changed_ids($clean_source_text, $source_text);

    $translated_items = self::getDOMNodeList($translated_text);
    // Changed/added elements will be added here.
    $changes = new DOMDocument();
    $source_items = self::getDOMNodeList($source_text);
    foreach ($source_items as $item_id => $source_item) {
      if (in_array($item_id, $changed_ids)) {
        // This element has been changed in source language, so it is added by default.
        $changes->appendChild($changes->importNode($source_item, TRUE));
      }
      else {
        if (empty($translated_items[$item_id])) {
          // This item does not exist at all in the translated version.
          $changes->appendChild($changes->importNode($source_item, TRUE));
        }
      }
    }
    if ($changes->hasChildNodes()) {
      return html_entity_decode($changes->saveHTML());
    }
    return NULL;
  }

  public static function getTextByIds($text, $ids) {
    $source_items = self::getDOMNodeList($text);
    $changes = new DOMDocument();
    foreach ($source_items as $item_id => $source_item) {
      if (in_array($item_id, $ids)) {
        $changes->appendChild($changes->importNode($source_item, TRUE));
      }
    }
    if ($changes->hasChildNodes()) {
      return html_entity_decode($changes->saveHTML());
    }
    return NULL;
  }


    /**
   * Input: $node->nid
   * The latest clean revision is returned in $vid
   * Status messages are returned in array $messages[key => severity_level][]
   * $valid_languages is a simple array with language code as elements
   * $invalid_languages[language_code] contains detailed explanatory messages
   * @todo Check all full_html fields, not only in body!
   */
  public static function validate_can_retranslate(&$node, &$messages,
                                                  &$valid_languages,
                                                  &$invalid_languages)
  {
    if (!isset($node->nid)) {
      throw new TMGMTException('node->nid not provided');
    }
    $nid = $node->nid;
    $published_rev = self::get_latest_clean_revision($nid);
    $node_published = node_load($nid, $published_rev);
    if (!workbench_moderation_node_type_moderated($node_published->type)) {
      // Node type is not moderated, always return text for full translation.
      $messages['status'][] = t('This node has no revisions, retranslation not applicable.');
      return NULL;
    }
    if (!$published_rev) {
      $messages['status'][] = t('This node has no published revision, retranslation not applicable.');
      return NULL;
    }

    if(!isset($node_published->body)) {
      // body is not present on this node
      $messages['status'][] = t('This node has no body field, retranslation not applicable.');
      return NULL;
    }
    $orig_lang = $node_published->translations->original;
    if (empty($node_published->body)) {
      $published_source_text = '';
      $published_source_structure = array();
    } else {
      $published_source_text = $node_published->body[$orig_lang][0]['value'];
      $published_source_structure = self::getHTMLStructure($published_source_text);
    }
    // Get the list of languages from the published revision.
    // Get the keys from body, because ->translations considers the latest revision
    //$languages = array_diff(array_keys($node_published->translations->data), [$orig_lang]);
    $languages = array_diff(array_keys($node_published->body), [$orig_lang]);

    $latest_rev = self::get_latest_revision($nid);
    $messages['status'][] = t('Comparing revision @latest to revision @original in source language @lang',
      array('@latest' => $latest_rev, '@original' => $published_rev, '@lang' => strtoupper($orig_lang)));

    $node = node_load($nid, $latest_rev);
    if (empty($node->body)) {
      $latest_source_text = '';
      $latest_source_structure = array();
    } else {
      $latest_source_text = $node->body[$orig_lang][0]['value'];
      $latest_source_structure = self::getHTMLStructure($latest_source_text);
    }

    if (!empty($languages)) {
      // Check if source language has been changed and retranslation is possible.
      // Compare latest revision with published revision (both in source language).
      $result = self::check_same_tags($published_rev, $latest_rev, $published_source_structure, $latest_source_structure);
      if (!empty($result)) {
        foreach ($languages as $lang) {
          $result[$lang] = t('Incompatible change in @lang from @tag1 to @tag2', array(
            '@lang' => strtoupper($orig_lang),
            '@tag1' => $result[$published_rev],
            '@tag2' => $result[$latest_rev]
          ));
          $invalid_languages[$lang] = $result;
        }
        $messages['error'][] = t('Node cannot be re-translated in: ')
          . implode(", ", array_map('strtoupper', $languages));
        return;
      }
    }
    // Get changes in source language.
    $changed_ids = self::get_changed_ids($published_source_text, $latest_source_text);
    if (empty($changed_ids)) {
      $messages['status'][] = t('No changes detected in language @lang.',
        array('@lang' => strtoupper($orig_lang)));
    } else {
      $msg = ' ';
      foreach ($changed_ids as $id) {
        $msg = $msg . '<' . $latest_source_structure[$id] . ' id="' . $id . '">,';
      }
      $messages['status'][] = t('Detected changes in @lang: @msg',
        array('@lang' => strtoupper($orig_lang), '@msg' => substr($msg, 0, -1)));
    }

    if ( empty($languages)) {
      $messages['status'][] = t('Full translation in all languages.');
    }
    // This array will store the languages eligible for retranslation
    $valid_languages = array();
    // Check for incompatibilities
    foreach ($languages as $lang) {
      $published_trans_structure = self::getHTMLStructure($node_published->body[$lang][0]['value']);
      // Check if tags in translations match the tags in source language.
      $result = self::check_same_tags($orig_lang, $lang, $published_source_structure, $published_trans_structure);
      if (!empty($result)) {
        $invalid_languages[$lang] = $result;
        continue;
      }

      // Check if the latest revision of target language contains tags
      // that are not found in the published revision of the source language.
      $latest_trans_structure = self::getHTMLStructure($node_published->body[$lang][0]['value']);
      $result = self::check_more_tags_in_translation(
        $orig_lang, $lang, $published_source_structure, $latest_trans_structure);
      if (!empty($result)) {
        $invalid_languages[$lang] = $result;
        continue;
      }
      // Check if source language has been changed.
      if (!empty($changed_ids)) {
        // Check if target language really needs retranslation and show changes for each valid language.
        $changed_text = self::get_text_to_retranslate($nid, $node->type, $orig_lang, $lang, 'body');
        if (empty($changed_text)) {
          $messages['status'][] = t('Language @lang does not need retranslation',
            array('@lang' => strtoupper($lang)));
        } else {
          $valid_languages[] = $lang;
          $changes = self::getHTMLStructure($changed_text);
          $msg = ' ';
          foreach ($changes as $id => $tag) {
            $msg = $msg . '<' . $tag . ' id="' . $id . '">';
          }
          $messages['status'][] = t('Node can be re-translated in @lang. Changes: @msg',
            array('@lang' => strtoupper($lang), '@msg' => $msg));
        }
      }
    }

    if (!empty($invalid_languages)) {
      $messages['error'][] = t('Node cannot be re-translated in: ')
        . implode(", ", array_map('strtoupper', array_keys($invalid_languages)));
    }
  }

  protected static function check_same_tags($orig_lang, $lang, $orig_structure, $new_structure) {
    foreach ($orig_structure as $id => $tag) {
      if (isset($new_structure[$id]) && $tag != $new_structure[$id]) {
        return array(
          'id' => $id,
          'source' => $orig_lang,
          $orig_lang => $tag,
          $lang => $new_structure[$id],
        );
      }
    }
    return NULL;
  }

  protected static function check_more_tags_in_translation($orig_lang, $lang, $orig_structure, $translated_structure) {
    foreach ($translated_structure as $id => $tag) {
      if (!isset($orig_structure[$id])) {
        return array(
          'id' => $id,
          'source' => $orig_lang,
          $orig_lang => NULL,
          $lang => $tag,
        );
      }
    }
    return NULL;
  }

  /**
   * @param string $new_translation contains the translated changes
   * @param string $old_translation represents the old translation
   * @param string $source_text represents the full text in the source language
   */
  public static function get_merged_translation($new_translation,
                                                $old_translation,
                                                $source_text) {
    $orig_structure = self::getDOMNodeList($source_text);
    $new_items = self::getDOMNodeList($new_translation);
    $old_items = self::getDOMNodeList($old_translation);
    // Check for extra tags in the translated text
    foreach ($new_items as $id => $item) {
      // Should exist in $orig_structure
      if (!isset($orig_structure[$id])) {
        throw new TMGMTException('Unexpected element <@tag id="@id"> in translation.',
          array('@id' => $id, '@tag' => $item->tagName));
      }
    }
    $callback = function(&$item, &$options, $div_start, $div_end) {
      $dom = $options['dom'];
      $current_parent = end($options['parents']);
      if ($div_start) {
        $div = $dom->importNode($item, FALSE);
        $current_parent->appendChild($div);
        array_push($options['parents'], $div);
        return;
      } else if ($div_end) {
        array_pop($options['parents']);
        return;
      }
      $id = $item->getAttribute('id');
      $new_items = $options['new_items'];
      $old_items = $options['old_items'];
      $orig_items = $options['orig_items'];
      if (!empty($new_items[$id])) {
        // Found in new translation, now check if the same tag.
        if ($new_items[$id]->tagName == $orig_items[$id]->tagName) {
          $current_parent->appendChild($dom->importNode($new_items[$id], TRUE));
        } else {
          // We have a different tag in the translation, raise error.
          throw new TMGMTException('Element @id is a <@tag_new> instead of <@tag_old>.',
            array(
              '@id' => $id,
              '@tag_new' => $new_items[$id]->tagName,
              '@tag_old' => $orig_items[$id]->tagName,
            ));
        }
      } else {
        if (!empty($old_items[$id])) {
          // Item not found in translation, re-use the old one.
          $current_parent->appendChild($dom->importNode($old_items[$id], TRUE));
        }
        else if (!empty($orig_items[$id])) {
          // if not found in old, add the english one.
          $current_parent->appendChild($dom->importNode($orig_items[$id], TRUE));
        }
        else {
          // We don't have this tag at all, raise error.
          throw new TMGMTException('<@tag id="@id"> not included in translation.',
            array('@id' => $id, '@tag' => $orig_items[$id]->tagName));
        }
      }
    };

    $dom = self::getDOMDocument($source_text);
    $body = $dom->getElementsByTagName('body')->item(0);
    // Follow the structure of the source language.
    $result = new DOMDocument();
    $options = array(
      'orig_items' => $orig_structure,
      'new_items' => $new_items,
      'old_items' => $old_items,
      'dom' => $result,
      'parents' => array($result)
    );
    self::browseDOMRecursive($body->childNodes, $callback, $options);
    // Note: html_entity_decode will convert &nbsp; to 0xa0
    return html_entity_decode($result->saveHTML());
  }

  public static function apply_partial_translation($node, $job_data,
                                                   $source_lang, $target_lang) {
    // Get old_translation from latest clean version.
    $revision = self::get_latest_clean_revision($node->nid);
    if (!$revision) {
      return $job_data;
    }
    foreach ($job_data as $field => $field_data) {
      if ($field == 'body' && isset($field_data[0]['value']['#translation']['#text'])) {
        // Get full reference text from source lang of latest revision.
        $source_text = $node->{$field}[$source_lang][0]['value'];
        $old_translation = self::get_field_value($node->nid, $node->type, $revision, $target_lang, $field);
        if (!$old_translation) {
          // $new_translation contains the entire needed text.
          continue;
        }
        // Get new translation from job data.
        $new_translation = $field_data[0]['value']['#translation']['#text'];
        $source_lang = $node->translations->original;
        $result = self::get_merged_translation($new_translation, $old_translation, $source_text);
        // Write it in job data
        // (must return it, array is passed by value in this function).
        $job_data[$field][0]['value']['#translation']['#text'] = $result;
      }
    }
    // Return the array, passed by value.
    return $job_data;
  }

  public static function validate_translation_structure($job_item) {
    // Validate that structure is the same in field body
    if (isset($job_item->data['body'][0]['value'])) {
      $orig_text = $job_item->data['body'][0]['value']['#text'];
      $trans_text = $job_item->data['body'][0]['value']['#translation']['#text'];
      $orig_structure = self::getHTMLStructure($orig_text);
      $trans_structure = self::getHTMLStructure($trans_text);
      $result = self::check_same_tags(
        $job_item->source_language, $job_item->target_language,
        $orig_structure, $trans_structure);
      if (!empty($result)) {
        return t('Tag @id changed from @tag1 to @tag2.', array(
          '@id' => $result['id'],
          '@tag1' => $result[$job_item->source_language],
          '@tag2' => $result[$job_item->target_language]
        ));
      }
      // check missing tags
      $orig_id_list = array_keys($orig_structure);
      $trans_id_list = array_keys($trans_structure);
      $missing_tags = array_diff($orig_id_list, $trans_id_list);
      if (!empty($missing_tags)) {
        $first = array_pop($missing_tags);
        return 'Tag '.$orig_structure[$first].' id="'.$first.'" missing in translation.';
      }
      $extra_tags = array_diff($trans_id_list, $orig_id_list);
      if (!empty($extra_tags)) {
        $first = array_pop($extra_tags);
        return 'Unexpected tag '.$trans_structure[$first].' id="'.$first.'" in translation.';
      }
    }
    return NULL;
  }

}
