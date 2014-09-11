#Patches

When patching a contrib module, the following steps should be followed:
1. Copy the patch file in this folder: <module_name>/<patch_file>
2. Apply the patch to the module
3. Commit

List of patches (most recent first)

* entity_collection
  * Fix bug when saving different entities with same eid (overwrites one another)
  * entity_collection/entity_collection-entities-with-same-eid.patch

* entity_collection
  * Fixed undefined variable
  * [https://www.drupal.org/node/2330513](https://www.drupal.org/files/issues/entity_collection_undefined_variable.patch)
  * entity_collection/entity_collection_undefined_variable.patch

* menu_block
  * Add hooks for editing, saving, deleting menu block. Useful for modules that want to extend the menu block form.
  * menu_block/menu_block_add_hooks_edit_save_delete_block.patch

* menuimage
  * Fix bug of redirect after menu save
  * https://www.drupal.org/node/2139233
  * menuimage/edit_item_alter_submit-page_not_found_if_multilingual_is_activated-2139233_0.patch


* entity_translation
  * Fix bug of incorrect language none for pathauto alias
  * https://www.drupal.org/node/1925848
  * entity_translation/entitytranslation-incorrect_pathauto_pattern-1925848-8.patch

* migrate (7.x-2.5)
  * Add support for FILE_EXISTS_RENAME option
  * migrate/migrate_file_rename_option.patch

* migrate (7.x-2.5)
  * Add support for file entity in file.inc destination plugin
  * patch created from code copied form 2.x-dev version of the module
  * migrate/migrate_file_plugin_file_entity_support.patch

* file_entity
  * Fix to let features export the display settings of the default file types
  * https://www.drupal.org/node/2192391#comment-8878719
  * file_entity/file_entity_remove_file_display-2192391-16.patch

* media
  * Fix to let features export the display settings of the default file types
  * https://www.drupal.org/node/2104193#comment-8878701
  * media/media_remove_file_display_alter-2104193-76.patch

* media
  * Restore Edit button in Media Browser Widget
  * https://www.drupal.org/node/2192981#comment-9004143
  * media/media-restore-edit-button-2192981-13.patch

* pdf_to_image
  * Check for empty values to prevent errors (occured in migrate)
  * pdf_to_image_check_empty_values.patch

* pdf_to_image
  * Skip it if entity saved trough cli (used for migrate)
  * pdf_to_imagefield/pdf_to_image_skip_if_cli.patch

* pdf_to_image
  * Fix for thumbnails of translated files
  * pdf_to_imagefield/pdf_to_imagefield_7-3-3-fix-for-multilingual.patch

* pdf_to_image
  * Allows files of other types than .pdf to be uploaded when field is using pdf_to_image widget
  * This patch is needed by doc_to_imagefield module
  * pdf_to_imagefield/pdf_to_imagefield-allow_non_pdf_file.patch


Patch documentation should be in the following format:

* module name
  * brief description
  * issue link (if exists)
  * patch file location
---