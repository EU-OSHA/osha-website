#Patches

When patching a contrib module, the following steps should be followed:
1. Copy the patch file in this folder: <module_name>/<patch_file>
2. Apply the patch to the module
3. Commit the

List of patches

* entity_translation
  * Fix bug of incorrect language none for pathauto alias
  * https://www.drupal.org/node/1925848
  * entity_translation/entitytranslation-incorrect_pathauto_pattern-1925848-8.patch

* pdf_to_image
	* Allows files of other types than .pdf to be uploaded when field is using pdf_to_image widget
	* 	This patch is needed by doc_to_imagefield module
	* pdf_to_imagefield/pdf_to_imagefield-allow_non_pdf_file.patch

* pdf_to_image
	* Fix for thumbnails of translated files
	*
	* pdf_to_imagefield/pdf_to_imagefield_7-3-3-fix-for-multilingual.patch

* pdf_to_image
	* Skip it if entity saved trough cli (used for migrate)
	*
	* pdf_to_imagefield/pdf_to_image_skip_if_cli.patch

* pdf_to_image
	* Check for empty values to prevent errors (occured in migrate)
	*
	* pdf_to_image_check_empty_values.patch



Patch documentation should be in the following format:

* module name
  * brief description
  * issue link (if exists)
  * patch file location
---