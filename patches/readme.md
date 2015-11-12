#Patches

When patching a contrib module, the following steps should be followed:
1. Copy the patch file in this folder: <module_name>/<patch_file>
2. Apply the patch to the module
3. Commit

List of patches (most recent first)

* match_redirect
  * checks redirect module in match_redirect_url_exists
  * /patches/match_redirect/match_redirect.patch

* recaptcha
  * Captcha is broken (always falls back and answers are incorrect)
  * /patches/recaptcha/recaptcha_no_preprocess.patch

* youtube
  * Always return HTTPS version
  * /patches/youtube/https-friendly.patch

* entityreference
 * Rendered entity is not language aware (https://www.drupal.org/node/1674792#comment-9304507)
 * /patches/entityreference/entityreference-rendered-entity-is-not-language-aware-1674792-58.patch

* xmlsitemap
 * Support for translated nodes - store and export url of node translations.
 * /patches/xmlsitemap/xmlsitemap-support-multilingual-nodes.patch

* site_map
  * Page title translatable
  * https://www.drupal.org/files/issues/site_map-page_title_translation-2500421-1-D7.patch

* addtoany
  * Always return HTTPS version
  * /patches/addtoany/https-friendly.patch

* ldap_user
  * Disable the watchdog successful messages
  * /patches/ldap/ldap_user/disable-watchdg.patch

* flickr
  * Applied patch for HTTPS font error
  * /patches/flickr/ssl-font-error.patch

* drupal
  * Applied patch to allow HTTPS
  * /patches/drupal/471970_0.patch
  * /patches/drupal/961508-20.patch

* varnish
  * req.http.host not correct when using custom port for varnish.
  * /patches/varnish/parse_url_fix.patch

* workbench_access
  * read-only screen for editorrial management
  * /patches/workbench_access/read_only_root_section.patch

* ldap_server
  * DN is not correctly parsed
  * /patches/ldap/ldap_servers/dn_parsing_bug.patch

* workbench_moderation
  * path to add access check in workbench moderation form to prevent change of status
  * /patches/workbench_moderation/workbench_moderation_access_check_in_moderation_form.patch

* path_breadcrumbs
  * dirty patch for the translation of Home (path_breadcrumbs._home_translate.patch)
  * see also https://www.drupal.org/node/2081375 and https://www.drupal.org/node/2028845 for alternative solutions

* ldap_authentication
  * Entrypt password when updating account
  * https://www.drupal.org/node/2037887
  * ldap_authentication-check_password_against_LDAP-2037887-10.patch

* search_api_views
  * Calling t($name) yields double translation
  * patches/search_api_views/double-translation.patch

* features
  * Fixed double-string translation
  * patches/features/features-double-translations-2462991-1-D7.patch
  * https://www.drupal.org/node/2462991
  * https://www.drupal.org/files/issues/features-double-translations-2462991-1-D7.patch

* entity_collection
  * Fix position and depth when adding new item
  * patches/entity_collection/entity_collection-depth-position.patch

* pdf_to_imagefield
  * Integrate with workbench_moderation
  * patches/pdf_toimagefield/pdf_to_image_moderation_integration.patch

* workbench_moderation
  * Fix saving 2 current statuses for same revision
  * https://www.drupal.org/files/issues/1436260-workbench_moderation-states-node_save-74.patch
  * https://www.drupal.org/node/1436260
  
* spamspan
  * Get default settings from variables
  * https://www.drupal.org/files/issues/spamspan-default-settings-from-variables-2430079_1.patch
  * https://www.drupal.org/node/2430079

* shs
  * Fixes undefined property when no parent is present (undefined_property.patch)

* ldap
  * ldap-property_of_non_object_in_ldap_authentication_init-2182413-3.patch

* search_autocomplete
  * Escapes the search term before submit (to accept %)
  * patches/search_autocomplete/search_autocomplete_escape_search_term.patch

* pathologic
  * Fixes cache issue wiht lagnuage
  * https://www.drupal.org/files/issues/348421-129.patch
  * https://www.drupal.org/node/348421
  
* field_collection
    * Fixes error when deleting node.
    * https://www.drupal.org/files/issues/field_collection-error-deleting-node-null-field-collection-2394875-1.module.patch
    * https://www.drupal.org/node/2394875

* i18n_string
    * Fixes undefined method strings_remove and strings_update
    * File: strings_remove_update_undefined_method.patch
* scanner
  * patches by Ruben@BBM - disable Undo and avoid to creating a new revision; permissions for S&R tab

* menu_item_visibility
  * Avoid db hit on menu links without menu_item_visibility enabled
  * https://www.drupal.org/node/1848724
  * https://www.drupal.org/files/issues/menu_item_visibility-performance-issues-1848724-1_0.patch

* tmgmt
  * Menu link source search is not case sensitive
  * patches/tmgmt/i18n_string-search-case-insensitive.patch

* drupal (core)
  * Menu links with query string params (from views exposed filters, solr facetAPI search, etc) get munged by url encoding
  * https://www.drupal.org/node/1220410
  * core/core-menu_links_with_query_param-1220410-coment-16.patch

* workbench_access
  * Preview error (Warning: array_keys() expects parameter 1 to be array, string given in workbench_access_node_form_element() (line 1467 of ...
  * workbench_access/1935190-wa-array-keys_0_1.patch
  * https://www.drupal.org/node/1935190#pift-results-1935190
  * https://www.drupal.org/files/1935190-wa-array-keys_0_1.patch

* nodeblock
  * Default options on/off for nodeblock
  * 2072427-default-on-off-6.patch
  * https://www.drupal.org/node/2072427

* tmgmt
  * Notice: Undefined index: format in text_tmgmt_source_translation_structure() (line 27 of /Users/cristiroma/Work/osha/project/docroot/sites/all/modules/contrib/tmgmt/sources/field/tmgmt_field.module). when creating nodes
  * patches/tmgmt/undefined_index_format.patch

* pdf_to_imagefield
  * Do not overwrite existing images
  * https://www.drupal.org/node/2049725
  * https://www.drupal.org/files/pdf_to_imagefield-allow-image-uploaded-2049725-4.patch

* workbench_moderation
  * Added patch for hard-coded label
  * https://www.drupal.org/node/2360059
  * https://www.drupal.org/files/issues/workbench_moderation_hardcoded_set_moderation_state-2360059-1.patch

* workbench_moderation
  * Fix bug CW-438 when URL in original language is lost when adding a new translation
  * -workbench_moderation/workbench_moderation/cw_438_workbench_moderation_url_1_D7.patch.patch-
  * Bug report: https://www.drupal.org/node/1946392
  * Applied patch from here: https://www.drupal.org/files/et_language-1946392-1.patch

* entity_collection
  * Fixed bug when using autocomplete for entities
  * https://www.drupal.org/node/2351417
  * entity_collection/entity_collection-disable_bundle_query-2351417-1-D7.patch

* features_extra
  * Fix tests error for nodequeue
  * features_extra-invalid-argument-foreach-2018515-1.patch
  * https://www.drupal.org/files/features_extra-invalid-argument-foreach-2018515-1.patch

* blockgroup
  * Allow feature revert
  * https://www.drupal.org/node/2189393
  * https://www.drupal.org/files/issues/blockgroup-7.x-1.x-features-revert-bug.diff

* blockgroup
  * Allow region theme hook
  * https://www.drupal.org/node/2043743
  * https://www.drupal.org/files/issues/blockgroup-region_template_suggestion-2043743-2.patch

* workbench_moderation
  * Added patch for node_export
  * https://www.drupal.org/node/2176841
  * https://www.drupal.org/files/issues/node_export-2176841-4.patch

* entity_translation
  * Added entity_translation in views (to be able to filter by language)
  * https://www.drupal.org/node/1330332
  * https://www.drupal.org/files/issues/entity_translation-filter_views-1330332-47.patch

* rules
  * added && if isset($data[$hook]) to avoid error when running update.sh (https://www.drupal.org/node/2161847)
  * https://www.drupal.org/files/issues/rules-fix-unsupported-operand-types-2161847-2.patch
* nodequeue
  * Fix undefined function apachesolr_mark_node (https://www.drupal.org/node/1425326)
  * https://www.drupal.org/files/nodequeue-apachesolr-fix.patch

* uuid_features
  * Add support for workbench moderation states. It sets published if exported revision published.
  * uuid_features/uuid_features-workbench-moderation-state-support.patch

* features
  * Add support for node UUID in menu import/export
  * features/features_menu_uuid_export.patchs

* menuimage
  * Modify menulink options to use image uri, not fid. Useful for features export/import
  * menuimage/menuimage_store_path_not_fid.patch

* workbench_moderation
  * Fix bug when insert/update node, current revision exclude form updating
  * workbench_moderation/workbench_moderation_bug_set_revision_state_0_of_current_revision.patch

* entity_collection
  * Fix bug when saving different entities with same eid (overwrites one another)
  * entity_collection/entity_collection-entities-with-same-eid.patch

* entity_collection
  * Fixed undefined variable
  * [https://www.drupal.org/node/2330513](https://www.drupal.org/files/issues/entity_collection_undefined_variable.patch)
  * entity_collection/entity_collection_undefined_variable.patch
  * content_add_form_validation.patch

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

* pdf_to_image
  * Generated image is saved on the revision and not for the published version
  * pdf_to_imagefield_save_to_revision.patch

* link
  * Duplicate fragment/query saved to database - https://www.drupal.org/node/1646360
  * duplicate-fragment-query-1646360-1.patch
  * Display url - ":" is converted to "%3A" and "?" to "&"
  * link-character_conversion-1984398.patch

* addtoany
  * make text of link translatable
  * translatable_link_text.patch

Patch documentation should be in the following format:

* module name
  * brief description
  * issue link (if exists)
  * patch file location
---
