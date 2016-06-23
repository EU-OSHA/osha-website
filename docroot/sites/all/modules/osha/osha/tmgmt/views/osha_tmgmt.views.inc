<?php

/**
 * Implements hook_views_data_alter().
 *
 * We override the filter handler for table workbench_moderation_node_history
 * to allow proper filtering for non-moderated content in content selection
 * screen.
 *
 * {@inheritdoc}
 */
function osha_tmgmt_views_data_alter(&$data) {
  // Used by tmgmt_node_selection_view.
  if (isset($data['workbench_moderation_node_history']['state']['filter']['handler'])) {
    $data['workbench_moderation_node_history']['state']['filter']['handler'] = 'osha_workbench_moderation_handler_filter_state';
  }
}

/**
 * Implements hook_views_pre_render().
 */
function osha_tmgmt_views_pre_render(&$view) {
  if ($view->name == 'tmgmt_node_selection_view') {
    // For publication, the link has to be with /view.
    // Couldn't use field_title with formatter because it doesn't take the
    // current revision title.
    foreach ($view->result as &$result) {
      $entity = $result->_field_data['nid']['entity'];
      if ($entity->type == 'publication') {
        $result->field_title_field[0]['rendered']['#markup'] = l($result->node_revision_title, 'node/' . $entity->nid . '/view');
      }
      else {
        $result->field_title_field[0]['rendered']['#markup'] = l($result->node_revision_title, 'node/' . $entity->nid);
      }
    }
  }
}

/**
 * Implements hook_query_TAG_alter().
 */
function osha_tmgmt_query_group_by_job_item_id_alter(QueryAlterableInterface $query){
  $query->groupBy('tmgmt_job_item.item_id');
}

/**
 * Alter the view tmgmt_node_selection_view to show latest node state.
 *
 * Alter LEFT JOIN node_revision ON node.vid = node_revision.vid
 * to LEFT JOIN node_revision ON node.nid = node_revision.nid
 */
function osha_tmgmt_views_query_alter(&$view, &$query) {
  // Alter the query for Content tab form Workflow Dashboard.
  // Get the latest state of nodes.
  if ($view->name == 'tmgmt_node_selection_view' && $view->current_display == 'tmgmt_node_selection_view_page') {
    if (!empty($query->table_queue['node_revision'])) {
      $query->table_queue['node_revision']['join']->field = 'nid';
      $query->table_queue['node_revision']['join']->left_field = 'nid';

      // Filter out items in cart.
      $existing = array();
      $cart = tmgmt_ui_cart_get();
      foreach ($cart->getJobItemsFromCart() as $item) {
        if ($item->plugin == 'entity' && $item->item_type == 'node') {
          $existing[] = $item->item_id;
        }
      }
      if (!empty($existing)) {
        $query->where[1]['conditions'][] = array(
          'field' => 'node.nid',
          'operator' => 'not in',
          'value' => $existing,
        );
      }
    }
  }
  if ($view->name == 'content_validators_group' && $view->current_display == 'content_validators_group_page') {
    $query->where[0]['type'] = 'AND';
    $query->where[0]['conditions'][] = array(
      'field' => 'entity_collection_collections.bundle',
      'operator' => '=',
      'value' => 'translators_group',
    );
  }

  // Switch from JOIN to LEFT JOIN with workbench_moderation_node_history
  // to allow adding content types which are not moderated (i.e. page).
  if ($view->name == 'tmgmt_node_selection_view') {
    if (isset($query->table_queue['workbench_moderation_node_history']['join']->type)) {
      $query->table_queue['workbench_moderation_node_history']['join']->type = 'LEFT';
    }
  }

  // Switch from JOIN to LEFT JOIN with workbench_moderation_node_history
  // to allow showing job items that doesn't have items moderated.
  if ($view->name == 'osha_job_overview_job_items') {
    if ($view->current_display == 'job_preview') {
      $query->add_tag('group_by_job_item_id');
    } else {
      if (isset($query->table_queue['node_tmgmt_job_item__workbench_moderation_node_history']['join']->type)) {
        $query->table_queue['node_tmgmt_job_item__workbench_moderation_node_history']['join']->type = 'LEFT';
      }
    }
  }
}

function osha_tmgtm_entity_list() {
  $entities = array();
  foreach (entity_get_info() as $name => $entity) {
    $entities[$name] = $entity['label'];
  }
  return $entities;
}

class OshaTMGMTJobItemViewsController extends TMGMTJobItemViewsController {

  /**
   * {@inheritdoc}
   */
  public function views_data() {
    $data = parent::views_data();

    $data['tmgmt_job_item']['source_language'] = array(
      'title' => t('Source language'),
      'help' => t('Language to translate from.'),
      'real field' => 'source_language',
      'field' => array(
        'handler' => 'tmgmt_handler_field_tmgmt_job_item_language',
      ),
    );

    $data['tmgmt_job_item']['label']['field']['handler'] = 'osha_tmgmt_handler_field_tmgmt_entity_label';

    $data['tmgmt_job_item']['target_language'] = array(
      'title' => t('Target language'),
      'help' => t('Language to translate to.'),
      'real field' => 'target_language',
      'field' => array(
        'handler' => 'tmgmt_handler_field_tmgmt_job_item_language',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_in_operator',
        'options callback' => 'entity_metadata_language_list',
        'real field' => 'target_language',
      ),
      'argument' => array(
        'real field' => 'target_language',
        'handler' => 'views_handler_argument_string',
      ),
    );

    $data['tmgmt_job_item']['page_count'] = array(
      'title' => t('Page count'),
      'help' => t('Number of pages for translation'),
      'field' => array(
        'float' => TRUE,
        'real field' => 'page_count',
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
    );

    $data['tmgmt_job_item']['character_count'] = array(
      'title' => t('Character count'),
      'help' => t('Number of characters for translation'),
      'field' => array(
        'real field' => 'character_count',
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),

    );

    $data['tmgmt_job_item']['plugin'] = array(
      'title' => t('Plugin'),
      'help' => t('Source plugin'),
      'real field' => 'plugin',
      'field' => array(
        'real field' => 'plugin',
        'handler' => 'views_handler_field',
      ),
    );

    $data['tmgmt_job_item']['item_type'] = array(
      'title' => t('Item type'),
      'help' => t('The type of entity in the job item'),
      'real field' => 'plugin',
      'field' => array(
        'real field' => 'item_type',
        'handler' => 'views_handler_field',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_in_operator',
        'options callback' => 'osha_tmgtm_entity_list',
        'real field' => 'item_type',
      ),
    );

    $data['tmgmt_job_item']['operations']['field']['handler'] = 'osha_tmgmt_handler_field_tmgmt_job_item_operations';
    $data['tmgmt_job_item']['state']['field']['handler'] = 'osha_tmgmt_handler_field_tmgmt_job_item_state';

    $data['tmgmt_job_item']['activity'] = array(
      'title' => t('Node activity'),
      'help' => t('Value of activity field'),
      'real field' => 'item_id',
      'field' => array(
        'handler' => 'osha_tmgmt_handler_field_tmgmt_job_item_activity',
        'click sortable' => TRUE,
      ),
    );

    $data['tmgmt_job_item']['section'] = array(
      'title' => t('Node section'),
      'real field' => 'item_id',
      'help' => t('Value of section field'),
      'field' => array(
        'handler' => 'osha_tmgmt_handler_field_tmgmt_job_item_section',
        'click sortable' => TRUE,
      ),
    );

    $data['tmgmt_job_item']['creator'] = array(
      'title' => t('Node author'),
      'real field' => 'item_id',
      'help' => t('Node author'),
      'field' => array(
        'handler' => 'osha_tmgmt_handler_field_tmgmt_job_item_creator',
        'click sortable' => TRUE,
      ),
    );

    $data['tmgmt_job_item']['changed'] = array(
      'title' => t('Changed date'),
      'real field' => 'changed',
      'help' => t('The date job item was last changed.'),
      'field' => array(
        'handler' => 'views_handler_field_date',
      ),
    );

    $data['tmgmt_job_item']['job_item_to_node'] = array(
      'title' => t('Content'),
      'help' => t('Content that is associated with this job item.'),
      'real field' => 'item_id',
      'relationship' => array(
        'label' => t('Content'),
        'base' => 'node',
        'base field' => 'nid',
        'handler' => 'views_handler_relationship',
        'field' => 'item_id',

        'relationship field' => 'item_id',
        'extra' => array(
          array(
            'table' => 'tmgmt_job_item',
            'field' => 'item_type',
            'operator' => '=',
            'value' => 'node',
          ),
          array(
            'table' => 'tmgmt_job_item',
            'field' => 'plugin',
            'operator' => '=',
            'value' => 'entity',
          ),
        ),
      ),
    );

    $data['tmgmt_job_item']['job_item_to_node_revision'] = array(
      'title' => t('Content'),
      'help' => t('Content revision that is associated with this job item.'),
      'real field' => 'vid',
      'relationship' => array(
        'label' => t('Content Revision'),
        'base' => 'node_revision',
        'base field' => 'vid',
        'handler' => 'views_handler_relationship',
        'field' => 'vid',
        'relationship field' => 'vid',
        'extra' => array(
          array(
            'table' => 'tmgmt_job_item',
            'field' => 'item_type',
            'operator' => '=',
            'value' => 'node',
          ),
          array(
            'table' => 'tmgmt_job_item',
            'field' => 'plugin',
            'operator' => '=',
            'value' => 'entity',
          ),
        ),
      ),
    );
    $data['tmgmt_job_item']['type']['field']['handler'] = 'osha_tmgmt_handler_field_tmgmt_job_item_type';

    return $data;
  }
}

class OshaTMGMTJobViewsController extends TMGMTJobViewsController {

  /**
   * {@inheritdoc}
   */
  public function views_data() {
    $data = parent::views_data();

    $data['tmgmt_job']['changed']['field']['handler'] = 'tmgmt_handler_field_tmgmt_job_changed';

    $data['tmgmt_job']['priority'] = array(
      'title' => t('Priority'),
      'help' => t('Urgency of translation'),
      'real field' => 'priority',
      'field' => array(
        'handler' => 'tmgmt_handler_field_tmgmt_job_priority',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_in_operator',
        'options callback' => 'osha_tmgmt_job_priority_list',
        'real field' => 'priority',
      ),
    );

    $data['tmgmt_job']['page_count'] = array(
      'title' => t('Page count'),
      'help' => t('Number of pages for translation'),
      'real field' => 'page_count',
      'field' => array(
        'float' => TRUE,
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
    );

    $data['tmgmt_job']['character_count'] = array(
      'title' => t('Character count'),
      'help' => t('Number of characters for translation'),
      'real field' => 'character_count',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
    );

    $data['tmgmt_job']['progress_job_items'] = array(
      'title' => t('Progress items'),
      'help' => t("Displays the progress of a job job's items"),
      'real field' => 'tjid',
      'field' => array(
        'handler' => 'osha_tmgmt_handler_field_tmgmt_progress_items',
      ),
    );

    return $data;
  }
}
