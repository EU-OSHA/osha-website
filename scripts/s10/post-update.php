<?php

/**
 * Run this queries if you want to reload the script
 * DELETE FROM `field_data_field_thesaurus` WHERE bundle = 'directive'
 * DELETE FROM `field_data_field_thesaurus` WHERE bundle = 'guideline'
 */

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

    $redirect_nid = get_redirect_id($url_redirect);

    // Find json code (last part) in redirect or url_alias
    if(!$redirect_nid){
      // Extract last term of url from json code
      $position = strrpos($url_redirect, '/') + 1;
      $url_redirect = substr($url_redirect, $position);
      $redirect_nid = get_redirect_id($url_redirect);
    }

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
    }else{
      echo $url_redirect;
      echo PHP_EOL;
    }
  }
}

/**
 * Get node id from redirect or url_alias table
 */
function get_redirect_id($url_redirect){
  // Find json code in redirect table
  $redirect_nid = db_query("SELECT redirect FROM redirect WHERE source = '".$url_redirect."'")->fetchField();

  // Find json code in url_alias table
  if(!$redirect_nid){
    $redirect_nid = db_query("SELECT source FROM url_alias WHERE alias = '".$url_redirect."'")->fetchField();
  }

  // Find json code in redirect table (with LIKE)
  if(!$redirect_nid){
    $redirect_nid = db_query("SELECT redirect FROM redirect WHERE source LIKE '%".$url_redirect."%'")->fetchField();
  }

  // Find json code in url_alias table (with LIKE)
  if(!$redirect_nid){
    $redirect_nid = db_query("SELECT source FROM url_alias WHERE alias LIKE '%".$url_redirect."%'")->fetchField();
  }

  return $redirect_nid;
}