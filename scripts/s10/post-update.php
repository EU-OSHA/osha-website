<?php

osha_update_directive_thesaurus();

/**
 * Update Thesaurus Field with values from JSON file
 */
function osha_update_directive_thesaurus(){
  // Decode JSON file
  $json_file = file_get_contents('../scripts/s10/legislation_thesaurus.json');
  $codes = json_decode($json_file, true);

  foreach($codes as $redirect => $code){
    $url_redirect = substr($redirect, 4);

    $redirect_nid = db_query("SELECT redirect FROM redirect WHERE source = '".$url_redirect."'")->fetchField();
    if(substr($redirect_nid, 0, 4) == 'node'){
      $node = node_load(substr($redirect_nid, 5));

      if($node){
        $thesaurus_codes = explode(',', $code);
        foreach($thesaurus_codes as $thesaurus_code){
          // GET Thesaurus taxonomy term ID
          $thesaurus = db_query("SELECT entity_id FROM field_data_field_thesaurus_code WHERE field_thesaurus_code_value = '".trim($thesaurus_code)."'")->fetchField();
          // Update Thesaurus field
          if($thesaurus){
            $node->field_thesaurus[LANGUAGE_NONE][]['tid'] = $thesaurus;
          }
        }
        field_attach_update('node', $node);
      }
    }
  }
}