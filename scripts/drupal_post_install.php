<?php

if (function_exists('drush_log')) {
  drush_log('Executing post-install tasks ...', 'ok');
}

//osha_configure_solr_entities();
osha_change_field_size();
osha_configure_file_translator();
osha_newsletter_create_taxonomy();
osha_configure_search_autocomplete();
osha_configure_addtoany_social_share();
osha_disable_blocks();
osha_configure_permissions();
osha_configure_recaptcha();
osha_configure_on_the_web();
osha_add_menu_position_rules();

variable_set('admin_theme', 'osha_admin');
variable_set('theme_default', 'osha_frontend');

/**
 * Configure permissions.
 *
 * @todo this is here because I cannot add it inside module due to SQL error:
 * SQLSTATE[23000]: Integrity constraint violation: 1048 Column 'module' cannot
 * be null.
 *
 * {@inheritdoc}
 */
function osha_configure_permissions() {
  if ($role = user_role_load_by_name('administrator')) {
    $vocabularies = array(
      'activity',
      'article_types',
      'esener',
      'nace_codes',
      'section',
      'thesaurus',
      'wiki_categories',
      'workflow_status',

      'publication_types',
      'newsletter_sections',
    );
    $permissions = array();
    foreach ($vocabularies as $voc_name) {
      if ($voc = taxonomy_vocabulary_machine_name_load($voc_name)) {
        $permissions[] = 'add terms in ' . $voc_name;
        $permissions[] = 'edit terms in ' . $voc->vid;
        $permissions[] = 'delete terms in ' . $voc->vid;
      }
    }

    $permissions[] = 'translate taxonomy_term entities';

    $permissions[] = 'moderate content from draft to final_draft';
    $permissions[] = 'moderate content from final_draft to draft';
    $permissions[] = 'moderate content from final_draft to needs_review';
    $permissions[] = 'moderate content from needs_review to to_be_approved';
    $permissions[] = 'moderate content from to_be_approved to rejected';
    $permissions[] = 'moderate content from to_be_approved to approved';

    user_role_grant_permissions($role->rid, $permissions);
  }
}

module_disable(array('overlay'));

/**
 * Configure the apachesolr and search_api_solr modules with proper settings.
 */
function osha_configure_solr_entities() {
  // Configure apachesolr: submit apachesolr_environment_edit_form
  if (module_exists('apachesolr') && module_load_include('inc', 'apachesolr', 'apachesolr.admin')) {
    drupal_set_message('Configuring apachesolr entities...');
    // Mark all entities for search indexing - admin/config/search/apachesolr
    $env_id = 'solr';
    $form_state = array(
      'values' => array(
        'env_id' => $env_id,
        'entities' => array(
          'node' => array(
            'article',
            'page',
            'blog',
            'calls',
            'highlight',
            'job_vacancies',
            'news',
            'newsletter_article',
            'press_release',
            'publication',
            'wiki_page',
          ),
        ),
      ),
    );
    drupal_form_submit('apachesolr_index_config_form', $form_state, $env_id);
  }
}



/**
 * Config file translator not available during osha_tmgmt installation.
 */
function osha_configure_file_translator() {
  /* @var TMGMTTranslator $file */
  $file = tmgmt_translator_load('file');
  if ($file) {
    $file->settings['export_format'] = 'xml';
    $file->settings['allow_override'] = FALSE;
    $file->save();
  }
}


/**
 * Populate initial terms into the newsletter_sections taxonomy.
 */
function osha_newsletter_create_taxonomy() {
  $voc = taxonomy_vocabulary_machine_name_load('newsletter_sections');
  $terms = taxonomy_get_tree($voc->vid);

  if (empty($terms)) {
    $new_terms = array(
      'highlight' => 'Highlights',
      '' => 'OSH matters',
      'publication' => 'Latest publications',
      'newsletter_article' => 'Coming soon',
      'blog' => 'Blog',
      'news' => 'News',
      'event' => 'Events',
    );
    $cont_type_term_map = array();
    $new_terms_ct = array_flip($new_terms);

    $weight = 0;

    foreach ($new_terms as $idx => $term_name) {
      $term = new stdClass();
      $term->name = $term_name;
      $term->language = 'en';
      $term->vid = $voc->vid;
      // weight must be an integer
      $term->weight = $weight++;
      taxonomy_term_save($term);
      if ($term->name == 'Coming soon') {
        variable_set('osha_newsletter_coming_soon_tid', $term->tid);
      }
      $cont_type_term_map[$new_terms_ct[$term->name]] = $term->tid;
    }
    variable_set('osha_newsletter_term_ct_map', $cont_type_term_map);
  }
}


/**
 * Set-up the search_autocomplete module.
 */
function osha_configure_search_autocomplete() {
  // Disable other search forms - we dont' use them.
  db_update('search_autocomplete_forms')
    ->fields(array(
      'enabled' => 0,
    ))
    ->condition('selector', '#edit-search-block-form--2', '<>')
    ->execute();
  // Configure the search form.
  $fid = db_select('search_autocomplete_forms', 'f')
    ->fields('f', array('fid'))
    ->condition('selector', '#edit-search-block-form--2')
    ->execute()->fetchField(0);
  if ($fid) {
    db_update('search_autocomplete_forms')
      ->fields(array(
        'data_view' => 'search_autocomplete',
        'theme' => 'basic-blue.css',
        'data_callback' => 'search_autocomplete/autocomplete/' . $fid . '/',
      ))
      ->condition('selector', '#edit-search-block-form--2')
      ->execute();
  }
  else {
    drupal_set_message('Failed to configure search_autocomplete form', 'error');
  }
}

/**
 * Add configuration to addtoany contrib module.
 */
function osha_configure_addtoany_social_share() {
  drupal_set_message('Configuring Addtoany contrib module ...');

  variable_set('addtoany_buttons_size', 16);
  variable_set('addtoany_additional_html', '<a class="a2a_button_twitter"></a><a class="a2a_button_facebook"></a><a class="a2a_button_linkedin"></a><a class="a2a_button_google_plus"></a>');
  variable_set('addtoany_additional_html_placement', 'after');
  variable_set('addtoany_display_in_nodecont', '0');
  variable_set('addtoany_display_in_nodelink', '1');
  variable_set('addtoany_display_in_teasers', '0');
  variable_set('addtoany_link_text', 'Share this news on:');
  variable_set('addtoany_image', 'text');
  variable_set('addtoany_custom_image', '');
  variable_set('addtoany_image_attributes', 'Share');

  variable_set('addtoany_nodetypes', array(
    'news' => 'news',
    'article' => 0,
    'page' => 0,
    'blog' => 0,
    'calls' => 0,
    'highlight' => 'highlight',
    'job_vacancies' => 0,
    'newsletter_article' => 0,
    'press_release' => 0,
    'publication' => 0,
    'wiki_page' => 0,
    )
  );
}

/**
 * Add configuration for recaptcha contrib module.
 */
function osha_configure_recaptcha() {
  drupal_set_message('Configuring reCaptcha contrib module ...');

  variable_set('captcha_default_challenge', 'recaptcha/reCAPTCHA');
  variable_set('captcha_default_validation', 1);
  variable_set('recaptcha_theme', 'custom');
}

/**
  * Add menu position rules for publication content type
  */
function osha_add_menu_position_rules(){
  if (module_exists('menu_position') && module_load_include('inc', 'menu_position', 'menu_position.admin')) {
    drupal_set_message('Create menu position rules ...');

    // config menu_position contrib module
    variable_set('menu_position_active_link_display','parent');

    $options = menu_parent_options(menu_get_menus(), array('mlid' => 0));
    $publications_menu_entry = array_search('------ Publications', $options);

    $form_state = array(
      'values' => array(
        'admin_title' => 'Publications Menu Rule',
        'plid' => $publications_menu_entry !== NULL ? $publications_menu_entry : 'main-menu:0',
        'content_type' => array('publication' => 'publication'),
        'op' => 'Save'
      )
    );

    drupal_form_submit('menu_position_add_rule_form', $form_state);
  }
}

/**
 * Add configuration for on_the_web contrib module.
 */
function osha_configure_on_the_web() {
  drupal_set_message('Configuring on_the_web contrib module ...');

  variable_set('on_the_web_sitename', 0);
  variable_set('on_the_web_facebook_page', 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork');
  variable_set('on_the_web_flickr_page', 'www.flickr.com/photos/euosha/');
  variable_set('on_the_web_twitter_page', 'https://twitter.com/eu_osha');
}

/**
 * Disable drupal default blocks
 */
function osha_disable_blocks(){
  drupal_set_message('Disable navigation block on osha_frontend theme');

  db_update('block')
  ->fields(array('status' => 0))
  ->condition('module', 'system')
  ->condition('delta', 'navigation')
  ->condition('theme', 'osha_frontend')
  ->execute();

  db_update('block')
  ->fields(array('status' => 0))
  ->condition('module', 'user')
  ->condition('delta', 'login')
  ->condition('theme', 'osha_frontend')
  ->execute();

  // we could also use drush
  // block-configure --module=user --delta=login --region=-1 --theme=osha_frontend

  // Flush cache
  cache_clear_all();
}
