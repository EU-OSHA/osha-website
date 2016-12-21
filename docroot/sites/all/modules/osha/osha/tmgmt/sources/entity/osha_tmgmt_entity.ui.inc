<?php

/**
 * Class OSHATMGMTEntitySourceUIController overrides in order to fix CW-1357 (exclude untranslatable taxonomies & their
 * associated terms)
 */
class OSHATMGMTEntitySourceUIController extends TMGMTEntitySourceUIController {

  public function overviewSearchFormPart($form, &$form_state, $type) {
    $form = parent::overviewSearchFormPart($form, $form_state, $type);

    $entity_info = entity_get_info($type);
    $bundle_key = $entity_info['entity keys']['bundle'];
    $bundle_options = tmgmt_entity_get_translatable_bundles($type);
    foreach($bundle_options as $k => $label) {
      if ($voc = taxonomy_vocabulary_machine_name_load($k)) {
        if (empty($voc->i18n_mode)) {
          unset($bundle_options[$k]);
        }
      }
    }
    asort($bundle_options);
    if (count($bundle_options) > 1) {
      $form['search_wrapper']['search'][$bundle_key] = array(
        '#type' => 'select',
        '#title' => t('@entity_name type', array('@entity_name' => $entity_info['label'])),
        '#options' => $bundle_options,
        '#empty_option' => t('All'),
        '#default_value' => isset($_GET[$bundle_key]) ? $_GET[$bundle_key] : NULL,
      );
    }
    $form['search_wrapper']['search']['target_language']['#options'] = osha_language_list_options();
    return $form;
  }

  /**
   * Gets entities data of provided type needed to build overview form list.
   *
   * @param $type
   *   Entity type for which to get list of entities.
   * @param array $property_conditions
   *   Array of key => $value pairs passed into
   *   tmgmt_entity_get_translatable_entities() as the second parameter.
   *
   * @return array
   *   Array of entities.
   */
  public function getEntitiesTranslationData($type, $property_conditions = array()) {

    $return_value = array();
    $entities = osha_tmgmt_entity_get_translatable_entities($type, $property_conditions, TRUE);

    $bundles = tmgmt_entity_get_translatable_bundles($type);

    // For retrieved entities add translation specific data.
    foreach ($entities as $entity) {

      list($entity_id, , $bundle) = entity_extract_ids($type, $entity);
      $entity_uri = entity_uri($type, $entity);

      // This occurs on user entity type.
      if (empty($entity_id)) {
        continue;
      }

      /**
       * @var EntityTranslationDefaultHandler $handler
       */
      $handler = entity_translation_get_handler($type, $entity);

      // Get existing translations and current job items for the entity
      // to determine translation statuses
      $translations = $handler->getTranslations();
      $source_lang = entity_language($type, $entity);
      $current_job_items = osha_tmgmt_job_item_load_latest('entity', $type, $entity_id, $source_lang);

      // Load basic entity data.
      $return_value[$entity_id] = array(
        'entity_type' => $type,
        'entity_id' => $entity_id,
        'entity_label' => entity_label($type, $entity),
        'entity_uri' => $entity_uri['path'],
      );

      if (count($bundles) > 1) {
        $return_value[$entity_id]['bundle'] = isset($bundles[$bundle]) ? $bundles[$bundle] : t('Unknown');
      }

      // Load entity translation specific data.
      foreach (language_list() as $langcode => $language) {

        $translation_status = 'current';

        if ($langcode == $source_lang) {
          $translation_status = 'original';
        }
        elseif (!isset($translations->data[$langcode])) {
          $translation_status = 'missing';
        }
        elseif (!empty($translations->data[$langcode]['translate'])) {
          $translation_status = 'outofdate';
        }

        $return_value[$entity_id]['current_job_items'][$langcode] = isset($current_job_items[$langcode]) ? $current_job_items[$langcode]: NULL;
        $return_value[$entity_id]['translation_statuses'][$langcode] = $translation_status;
      }
    }

    return $return_value;
  }


  /**
   * Builds a table row for overview form.
   *
   * @param array $data
   *   Data needed to build the list row.
   *
   * @return array
   */
  public function overviewRow($data) {
    $label = $data['entity_label'] ? $data['entity_label'] : t('@type: @id', array('@type' => $data['entity_type'], '@id' => $data['entity_id']));

    $row = array(
      'id' => $data['entity_id'],
      'title' => l($label, $data['entity_uri']),
    );

    if (isset($data['bundle'])) {
      $row['bundle'] = $data['bundle'];
    }

    foreach (language_list() as $langcode => $language) {
      $row['langcode-' . $langcode] = array(
        'data' => theme('osha_tmgmt_ui_translation_language_status_single', array(
          'translation_status' => $data['translation_statuses'][$langcode],
          'job_item' => isset($data['current_job_items'][$langcode]) ? $data['current_job_items'][$langcode] : NULL,
        )),
        'class' => array('langstatus-' . $langcode),
      );
    }

    return $row;
  }
}

/**
 * Gets translatable entities of a given type.
 *
 * Additionally you can specify entity property conditions, pager and limit.
 *
 * @param string $entity_type
 *   Drupal entity type.
 * @param array $property_conditions
 *   Entity properties. There is no value processing so caller must make sure
 *   the provided entity property exists for given entity type and its value
 *   is processed.
 * @param bool $pager
 *   Flag to determine if pager will be used.
 *
 * @return array
 *   Array of translatable entities.
 */
function osha_tmgmt_entity_get_translatable_entities($entity_type, $property_conditions = array(), $pager = FALSE) {

  if (!in_array($entity_type, variable_get('entity_translation_entity_types', array()))) {
    return array();
  }

  $languages = drupal_map_assoc(array_keys(language_list()));

  $entity_info = entity_get_info($entity_type);
  $label_key = isset($entity_info['entity keys']['label']) ? $entity_info['entity keys']['label'] : NULL;

  $id_key = $entity_info['entity keys']['id'];
  $query = db_select($entity_info['base table'], 'e');
  $query->addField('e', $id_key);

  // Searching for sources with missing translation.
  if (!empty($property_conditions['target_status']) && !empty($property_conditions['target_language']) && in_array($property_conditions['target_language'], $languages)) {

    $translation_table_alias = db_escape_field('et_' . $property_conditions['target_language']);
    $query->leftJoin('entity_translation', $translation_table_alias, "%alias.entity_type = :entity_type AND %alias.entity_id = e.$id_key AND %alias.language = :language",
      array(':entity_type' => $entity_type, ':language' => $property_conditions['target_language']));

    // Exclude entities with having source language same as the target language
    // we search for.
    $query->condition('e.language', $property_conditions['target_language'], '<>');

    if ($property_conditions['target_status'] == 'untranslated_or_outdated') {
      $or = db_or();
      $or->isNull("$translation_table_alias.language");
      $or->condition("$translation_table_alias.translate", 1);
      $query->condition($or);
    }
    elseif ($property_conditions['target_status'] == 'outdated') {
      $query->condition("$translation_table_alias.translate", 1);
    }
    elseif ($property_conditions['target_status'] == 'untranslated') {
      $query->isNull("$translation_table_alias.language");
    }
  }

  // Remove the condition so we do not try to add it again below.
  unset($property_conditions['target_language']);
  unset($property_conditions['target_status']);

  // Searching for the source label.
  if (!empty($label_key) && isset($property_conditions[$label_key])) {
    $search_tokens = explode(' ', $property_conditions[$label_key]);
    $or = db_or();

    foreach ($search_tokens as $search_token) {
      $search_token = trim($search_token);
      if (strlen($search_token) > 2) {
        $or->condition($label_key, "%$search_token%", 'LIKE');
      }
    }

    if ($or->count() > 0) {
      $query->condition($or);
    }

    unset($property_conditions[$label_key]);
  }

  // Searching by taxonomy bundles - we need to switch to vid as the bundle key.
  if ($entity_type == 'taxonomy_term') {
    $property_name = 'vid';
    $bundles = tmgmt_entity_get_translatable_bundles($entity_type);
    $untranslatable_voc = array();
    foreach($bundles as $k => $label) {
      if ($voc = taxonomy_vocabulary_machine_name_load($k)) {
        if (empty($voc->i18n_mode)) {
          $untranslatable_voc[] = $voc->vid;
        }
      }
    }
    if (!empty($untranslatable_voc)) {
      $query->condition('e.' . $property_name, $untranslatable_voc, 'NOT IN');
    }

    if (!empty($property_conditions['vocabulary_machine_name'])) {
      $vocabulary = taxonomy_vocabulary_machine_name_load($property_conditions['vocabulary_machine_name']);
      $property_value = $vocabulary->vid;
      $query->condition('e.' . $property_name, $property_value);
      // Remove the condition so we do not try to add it again below.
      unset($property_conditions['vocabulary_machine_name']);
    }
  }
  // Searching by the node bundles - that applies for node entities as well as
  // comment.
  elseif (in_array($entity_type, array('comment', 'node'))) {
    $node_table_alias = 'e';

    // For comments join node table so that we can filter based on type.
    if ($entity_type == 'comment') {
      $query->join('node', 'n', 'e.nid = n.nid');
      $node_table_alias = 'n';
    }

    // Get translatable node types and check if it is worth to continue.
    $translatable_node_types = array_keys(tmgmt_entity_get_translatable_bundles('node'));
    if (empty($translatable_node_types)) {
      return array();
    }

    // If we have type property add condition.
    if (isset($property_conditions['type'])) {
      $query->condition($node_table_alias . '.type', $property_conditions['type']);
      // Remove the condition so we do not try to add it again below.
      unset($property_conditions['type']);
    }
    // If not, query db only for translatable node types.
    else {
      $query->condition($node_table_alias . '.type', $translatable_node_types);
    }
  }

  // Add remaining query conditions which are expected to be handled in a
  // generic way.
  foreach ($property_conditions as $property_name => $property_value) {
    $query->condition('e.' . $property_name, $property_value);
  }

  if ($pager) {
    $query = $query->extend('PagerDefault')->limit(variable_get('tmgmt_source_list_limit', 20));
  }
  else {
    $query->range(0, variable_get('tmgmt_source_list_limit', 20));
  }

  $query->orderBy($entity_info['entity keys']['id'], 'DESC');
  $entity_ids = $query->execute()->fetchCol();
  $entities = array();

  if (!empty($entity_ids)) {
    $entities = entity_load($entity_type, $entity_ids);
  }

  return $entities;
}
