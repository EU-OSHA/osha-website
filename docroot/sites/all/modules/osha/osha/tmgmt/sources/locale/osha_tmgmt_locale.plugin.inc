<?php


class OSHATMGMTLocaleSourcePluginController extends TMGMTLocaleSourcePluginController {

  public function saveTranslation(TMGMTJobItem $job_item) {
    $data = $job_item->getData();
    if (isset($data['singular']['#translation']['#text'])) {
      $translation = $data['singular']['#translation']['#text'];
      // Update the locale string in the system.
      // @todo: Send error message to user if update fails.
      if ($this->updateTranslation($job_item->item_id, $job_item->target_language, $translation)) {
        // OSHA: In addition to merging the translation for this lid, we also update all identical strings.
        $identical = db_query(
          'SELECT lid FROM {locales_source} WHERE source = :source AND lid <> :lid',
          array('source' => $data['singular']['#text'], 'lid' => $job_item->item_id)
        )->fetchCol();
        foreach ($identical as $ilid) {
          $this->updateTranslation($ilid, $job_item->target_language, $translation);
        }
        $job_item->accepted();
      }
    }
  }
}
