<?php
/**
 * @file
 * osha_breadcrumbs.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function osha_breadcrumbs_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'directive';
  $path_breadcrumb->name = 'Directive';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Legislation',
      1 => 'European Directives',
      2 => '%node:field-directive-type:name',
      3 => '%node:field-legislation-category:name',
      4 => '!page_title',
    ),
    'paths' => array(
      0 => 'articles/safety-and-health-legislation',
      1 => 'articles/european-directives',
      2 => '%node:field-directive-type:url',
      3 => 'legislation/directives/%node:field-legislation-category:field-directive-category-code',
      4 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'directive' => 'directive',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['directive'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'directive_view';
  $path_breadcrumb->name = 'Directive view';
  $path_breadcrumb->path = 'legislation/directives/%string';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Legislation',
      1 => 'European Directives',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'articles/safety-and-health-legislation',
      1 => 'articles/european-directives',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'string' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['directive_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'guideline';
  $path_breadcrumb->name = 'Guideline';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Legislation',
      1 => 'European Guidelines',
      2 => '%node:field-legislation-category:name',
      3 => '!page_title',
    ),
    'paths' => array(
      0 => 'articles/safety-and-health-legislation',
      1 => 'articles/european-guidelines',
      2 => 'legislation/guidelines/%node:field-legislation-category:field-guideline-category-code',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'guideline' => 'guideline',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['guideline'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'guideline_view';
  $path_breadcrumb->name = 'Guideline view';
  $path_breadcrumb->path = 'legislation/guidelines/%string';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Legislation',
      1 => 'European Guidelines',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'articles/safety-and-health-legislation',
      1 => 'articles/european-guidelines',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'string' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['guideline_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'highlights';
  $path_breadcrumb->name = 'Highlights';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Highlights',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'highlights',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'highlight' => 'highlight',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['highlights'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'highlights_view';
  $path_breadcrumb->name = 'Highlights view';
  $path_breadcrumb->path = 'highlights';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['highlights_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'news';
  $path_breadcrumb->name = 'News';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'OSH news',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'oshnews',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'news' => 'news',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['news'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_breadcrumbs';
  $path_breadcrumb->name = 'Node breadcrumbs';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'highlight' => 'highlight',
              'directive' => 'directive',
              'guideline' => 'guideline',
              'news' => 'news',
              'publication' => 'publication',
            ),
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['node_breadcrumbs'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'osh_news';
  $path_breadcrumb->name = 'OSH news';
  $path_breadcrumb->path = 'oshnews';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'OSH news',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['osh_news'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'osh_publications';
  $path_breadcrumb->name = 'Publications list';
  $path_breadcrumb->path = 'publications';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and resources',
      1 => 'Publications',
    ),
    'paths' => array(
      0 => 'articles/tools-and-resources',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['osh_publications'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'oshmail_newsletter';
  $path_breadcrumb->name = 'OSHMAIL newsletter';
  $path_breadcrumb->path = 'oshmail_newsletter';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'OSHMAIL newsletter',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['oshmail_newsletter'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'press_releases_view';
  $path_breadcrumb->name = 'Press Releases view';
  $path_breadcrumb->path = 'press-releases';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Inside EU-OSHA',
      1 => 'Press room',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'articles/inside-eu-osha',
      1 => 'press-room',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['press_releases_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'press_room_view';
  $path_breadcrumb->name = 'Press Room view';
  $path_breadcrumb->path = 'press-room';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Inside EU-OSHA',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'inside-eu-osha',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['press_room_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'publications';
  $path_breadcrumb->name = 'Publications';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and Resources',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'articles/tools-and-resources',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'publication' => 'publication',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['publications'] = $path_breadcrumb;

  return $export;
}
