<?php

/**
 * @file
 * Contains the SearchApiEtPropertyInfoAlter class.
 */

/**
 * Helper class for altering Entity API property info arrays.
 *
 * This is necessary since the "property info alter" option for metadata
 * wrappers (and similar Entity API functionality) only supports one value, but
 * when inserting our own callback we also have to make sure the previously set
 * ones are called.
 */
class SearchApiEtPropertyInfoAlter {

  /**
   * An additional callback to invoke.
   *
   * @var callable|null
   */
  protected $callback;

  /**
   * Constructs a new SearchApiEtPropertyInfoAlter object.
   *
   * @param callable|null $callback
   *   The previous set property info alter callback.
   */
  public function __construct($callback = NULL) {
    if ($callback && is_callable($callback)) {
      $this->callback = $callback;
    }
  }

  /**
   * Alters property information to add ET-specific properties.
   *
   * @param EntityMetadataWrapper $wrapper
   *   The wrapper whose property info should be altered.
   * @param array $property_info
   *   The current property info array.
   *
   * @return array
   *   An altered property info array, with ET-specific properties added.
   *
   * @see entity_metadata_wrapper()
   */
  function propertyInfoAlter(EntityMetadataWrapper $wrapper, array $property_info) {
    if ($this->callback) {
      $property_info = call_user_func($this->callback, $wrapper, $property_info);
    }
    $additional['search_api_et_id'] = array(
      'type' => 'token',
      'label' => t('Multilingual ID'),
      'description' => t("The item's language-specific ID."),
    );
    if (!empty($property_info['properties']['language'])) {
      // Just make sure the language has the right type.
      $property_info['properties']['language']['type'] = 'token';
    }
    else {
      $additional['language'] = array(
        'type' => 'token',
        'label' => t('Language'),
        'description' => t("The item's language."),
        'options list' => 'entity_metadata_language_list',
      );
    }
    // It's just prettier if ID and language are the first, not last.
    $property_info['properties'] = array_merge($additional, $property_info['properties']);
    return $property_info;
  }

}
