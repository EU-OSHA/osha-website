<?php

osha_configure_solr();
osha_change_field_size();
osha_configure_mailsystem();
osha_configure_htmlmail();
osha_configure_simplenews();
osha_configure_imce();
osha_configure_wysiwyg_settings();

module_disable(array('overlay'));

/**
 * Configure the apachesolr and search_api_solr modules with proper settings.
 */
function osha_configure_solr() {
  $config_file = sprintf('%s/../conf/config.json', dirname(__FILE__));
  if (!is_readable($config_file)) {
    drupal_set_message("Cannot read configuration file!", 'warning');
    return;
  }
  $cfg = json_decode(file_get_contents($config_file), TRUE);
  if (empty($cfg)) {
    drupal_set_message('Configuration file was empty, nothing to do here', 'warning');
    return;
  }
  if (!empty($cfg['solr_server'])) {
    if (module_exists('search_api') && module_load_include('inc', 'search_api', 'search_api.admin')) {
      drupal_set_message('Creating Solr server using machine name: search_server ...');
      $cfg = array_merge(
        array(
          'name' => 'Solr server',
          'enabled' => 1,
          'description' => 'Search server',
          'scheme' => 'http',
          'host' => 'localhost',
          'port' => '8983',
          'path' => '/solr',
          'http_user' => '',
          'http_password' => '',
          'excerpt' => NULL,
          'retrieve_data' => NULL,
          'highlight_data' => NULL,
          'skip_schema_check' => NULL,
          'solr_version' => '',
          'http_method' => 'AUTO',
        ), $cfg['solr_server']
      );
      $form_state = array(
        'values' => array(
          'machine_name' => 'solr_server',
          'class' => 'search_api_solr_service',
          'name' => $cfg['name'],
          'enabled' => $cfg['enabled'],
          'description' => $cfg['description'],
          'options' => array(
            'form' => array(
              'scheme' => $cfg['scheme'],
              'host' => $cfg['host'],
              'port' => $cfg['port'],
              'path' => $cfg['path'],
              'http' => array(
                'http_user' => $cfg['http_user'],
                'http_pass' => $cfg['http_pass'],
              ),
              'advanced' => array(
                'excerpt' => $cfg['excerpt'],
                'retrieve_data' => $cfg['retrieve_data'],
                'highlight_data' => $cfg['highlight_data'],
                'skip_schema_check' => $cfg['skip_schema_check'],
                'solr_version' => $cfg['solr_version'],
                'http_method' => $cfg['http_method'],
              ),
            ),
          ),
        ),
      );
      drupal_form_submit('search_api_admin_add_server', $form_state);
    }

    // Configure apachesolr: submit apachesolr_environment_edit_form
    if (module_exists('apachesolr') && module_load_include('inc', 'apachesolr', 'apachesolr.admin')) {
      drupal_set_message('Configuring Apachesolr search environment ...');

      $url = sprintf('%s://%s:%s%s', $cfg['scheme'], $cfg['host'], $cfg['port'], $cfg['path']);
      $env_id = apachesolr_default_environment();
      $environment = apachesolr_environment_load($env_id);

      $environment['url'] = $url;
      $environment['name'] = $cfg['name'];
      $environment['conf']['apachesolr_direct_commit'] = $cfg['apachesolr_direct_commit'];
      $environment['conf']['apachesolr_read_only'] = $cfg['apachesolr_read_only'];
      $environment['conf']['apachesolr_soft_commit'] = $cfg['apachesolr_soft_commit'];

      apachesolr_environment_save($environment);
      // @todo: See ticket #2527 - cannot make the form save new settings!
      // drupal_form_submit('apachesolr_environment_edit_form', $form_state,
      // $environment);
    }
  }
  else {
    drupal_set_message('Unable to find solr_server section in config. Solr integration may be broken', 'warning');
  }
}

/**
 * Configure the drupal mailsystem module with proper settings.
 */
function osha_configure_mailsystem() {
  drupal_set_message('Configuring Drupal Mailsystem module ...');

  $mail_system = array(
    'default-system' => 'HTMLMailSystem',
    'htmlmail' => 'DefaultMailSystem',
  );

  variable_set('mail_system', $mail_system);
  variable_set('mailsystem_theme', 'default');
}

/**
 * Configure the drupal htmlmail module with proper settings.
 */
function osha_configure_htmlmail() {
  drupal_set_message('Configuring Drupal HTML Mail module ...');

  $site_default_theme = variable_get('theme_default', 'bartik');

  variable_set('htmlmail_theme', $site_default_theme);
  variable_set('htmlmail_postfilter', 'full_html');
}

/**
 * Configure the drupal simplenews module with proper settings.
 */
function osha_configure_simplenews() {
  drupal_set_message('Configuring Drupal Simplenews module ...');

  $site_mail = variable_get('site_mail', 'no-reply@osha.org');
  $site_name = variable_get('site_name', 'OSHA');

  variable_set('simplenews_debug', '1');
  variable_set('simplenews_format', 'html');
  variable_set('simplenews_from_address', $site_mail);
  variable_set('simplenews_from_name', $site_name);
  variable_set('simplenews_priority', '3');
  variable_set('simplenews_receipt', 0);
  variable_set('simplenews_send', '0');
  variable_set('simplenews_source_cache', 'SimplenewsSourceCacheNone');
  variable_set('simplenews_spool_expire', '0');
  variable_set('simplenews_test_address', $site_mail);
  variable_set('simplenews_test_address_override', 1);
  variable_set('simplenews_throttle', '20');
  variable_set('simplenews_use_cron', 1);
}

/**
 * Configure IMCE contrib module - Alter User-1 profile and assign User-1 profile to the administrator role.
 */
function osha_configure_imce(){
    drupal_set_message('Configuring Drupal IMCE module ...');
    // /admin/config/media/imce
    if(!module_load_include('inc', 'imce', 'inc/imce.admin')) {
        throw new Exception('Cannot load inc/imce.admin.inc');
    }

    // alter profile User-1
    $profiles = variable_get('imce_profiles', array());

    if (isset($profiles[1])) {
        $profiles[1]['directories'][0]['name'] = "sites/default/files";
        variable_set('imce_profiles', $profiles);
    } else {
        throw new Exception('Cannot load IMCE profile User-1.');
    }

    $roles = user_roles();

    if (in_array("administrator", $roles)) {
        // role administrator found - assign User-1 profile to administrator
        $roles_profiles = variable_get('imce_roles_profiles', array());
        $admin_role = user_role_load_by_name("administrator");

        $roles_profiles[$admin_role->rid]['public_pid'] = 1;
        $roles_profiles[$admin_role->rid]['private_pid'] = 1;
        $roles_profiles[$admin_role->rid]['weight'] = 0;

        variable_set('imce_roles_profiles', $roles_profiles);
    } else {
        // role administrator not found
        throw new Exception('Cannot assign IMCE profile User-1 to administrator - role administrator not found.');
    }
}

/**
 * Sets default WYSIWYG settings.
 */
function osha_configure_wysiwyg_settings() {
  drupal_set_message('Configuring Drupal WYSIWYG module ...');

  $settings = array(
    'default' => 1,
    'user_choose' => 0,
    'show_toggle' => 1,
    'language' => 'en',
    'buttons' => array(
      'default' => array(
        'bold' => 1,
        'italic' => 1,
        'underline' => 1,
        'strikethrough' => 1,
        'justifyfull' => 1,
        'bullist' => 1,
        'numlist' => 1,
        'link' => 1,
        'anchor' => 1,
        'image' => 1,
        'fontselect' => 1,
        'fontsizeselect' => 1,
        'code' => 1,
        'cut' => 1,
        'copy' => 1,
        'paste' => 1,
      ),
      'contextmenu' => array(
        'contextmenu' => 1,
      ),
      'searchreplace' => array(
        'search' => 1,
        'replace' => 1,
      ),
      'paste' => array(
        'pasteword' => 1,
      ),
      'table' => array(
        'tablecontrols' => 1,
      ),
      'media' => array(
        'media' => 1,
      ),
      'imce' => array(
        'imce' => 1,
      ),
    ),
    'toolbar_loc' => 'top',
    'toolbar_align' => 'left',
    'path_loc' => 'bottom',
    'resizing' => 1,
    'verify_html' => 1,
    'preformatted' => 0,
    'convert_fonts_to_spans' => 1,
    'remove_linebreaks' => 1,
    'apply_source_formatting' => 0,
    'paste_auto_cleanup_on_paste' => 0,
    'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
    'css_setting' => 'theme',
    'css_path' => '',
    'css_classes' => '',
  );

  $fields_full_html = array(
    'format' => 'full_html',
    'editor' => 'tinymce',
    'settings' => serialize($settings),
  );

  $fields_filtered_html = array(
    'format' => 'filtered_html',
    'editor' => 'tinymce',
    'settings' => serialize($settings),
  );

  $fields_plain_text = array(
    'format' => 'plain_text',
    'editor' => 'tinymce',
    'settings' => serialize($settings),
  );

  db_insert('wysiwyg')->fields($fields_full_html)->execute();
  db_insert('wysiwyg')->fields($fields_filtered_html)->execute();
  db_insert('wysiwyg')->fields($fields_plain_text)->execute();

  db_update('filter_format')
  ->condition('format', 'filtered_html')
  ->fields(array('weight' => 1))
  ->execute();

  db_update('filter_format')
  ->condition('format', 'full_html')
  ->fields(array('weight' => 0))
  ->execute();
}
