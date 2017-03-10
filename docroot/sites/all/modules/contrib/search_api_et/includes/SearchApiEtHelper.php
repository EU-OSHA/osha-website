<?php

/**
 * @file
 * Helper class for SearchAPI ET
 */
class SearchApiEtHelper {

  const ITEM_ID_ENTITY_ID = 'entity_id';
  const ITEM_ID_LANGUAGE = 'language';
  const ITEM_ID_SEPARATOR = '/';

  /**
   * Helper function to build the complete item_id from.
   *
   * @param string|int $entity_id
   *  The entity ID
   * @param string $language
   *  The entity language
   * @return string
   */
  static function buildItemId($entity_id, $language) {
    return $entity_id . self::ITEM_ID_SEPARATOR . $language;
  }

  /**
   * Helper function to check if the given $item_id is valid.
   * @param $item_id
   *   The Item ID (in the form "{entity_id}/{language}")
   * @return bool
   */
  static function isValidItemId($item_id) {
    // Check if the entity_id is not empty: '/' position must be 1 or more.
    if (!is_string($item_id))
      return FALSE;

    $id = trim($item_id);

    return !empty($id) &&
      // The minimum id length is 3 ("1/a")
      strlen($id) >= 3 &&
      strpos($item_id, self::ITEM_ID_SEPARATOR) > 0;
  }

  /**
   * Helper function to split the Item ID into language or entity_id.
   * 
   * @param $item_id
   *   The Item ID (in the form "{entity_id}/{language}")
   * @param string $return_part
   *   The item part to return, available options: 'entity_id' or 'language'
   * @return array|string|null
   *   Returns <entity_id, language> couple, if no $part is given.
   *   Returns an empty array if the item_id is not valid.
   */
  static function splitItemId($item_id, $return_part = NULL) {
    if (!self::isValidItemId($item_id)) {
      return array();
    }

    $parts_names = array(self::ITEM_ID_ENTITY_ID, self::ITEM_ID_LANGUAGE);

    // Split the item_id in its parts: {entity_id}/{language}
    $item_id_components = explode(self::ITEM_ID_SEPARATOR, $item_id);
    $item_id_components = array_combine($parts_names, $item_id_components);

    if (!empty($return_part)) {
      if (array_key_exists($return_part, $item_id_components)) {
        return $item_id_components[$return_part];
      }
      else {
        return NULL;
      }
    }

    return $item_id_components;
  }
  
  /**
   * Returns multilingual item type name for provided entity type.
   *
   * @param string $entity_type
   *   Entity type name.
   * @return string
   *   Multilingual item type name.
   */
  static function getItemType($entity_type) {
    return 'search_api_et_' . $entity_type;
  }

  /**
   * Helper function to group the given list of ItemIds by EntityIds
   *
   * @param array $item_ids
   *  The list of trackable ItemID (in the form "{entity_id}/{language}")
   * @return array
   *   A multilevel array where the outer array is keyed by the EntityID, and
   *   contains all the corresponding ItemIDs.
   */
  static function getGroupedItemsIdsByEntity($item_ids) {
    $ret = array();
    foreach ($item_ids as $item_id) {
      $entity_id = self::splitItemId($item_id, self::ITEM_ID_ENTITY_ID);
      if ($entity_id) {
        $ret[$entity_id][] = $item_id;
      }
    }
    return $ret;
  }

}
