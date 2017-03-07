<?php

use \TijsVerkoyen\CssToInlineStyles\CssToInlineStyles;

class OSHNewsletter {

  public static $fontUrl = 'https://fonts.googleapis.com/css?family=Oswald:200,300,400,500';
  public static $tweetsLimit = 4;

  public static function getTemplatesList() {
    return [
      'newsletter_full_width_details' => 'Full width: detail',
      'newsletter_full_width_list' => 'Full width: summary',
      'newsletter_half_width_list' => '1/2 width: summary',
      'newsletter_half_image_left' => 'Healthy Workplaces Campaigns',
      'newsletter_full_width_2_col_blocks' => 'Events',
      'newsletter_half_width_twitter' => 'Tweets',
    ];
  }

  public static function getChildStyle($parentTemplate, $default = 'newsletter_item') {
    $styles = [
      'newsletter_full_width_details' => 'highlights_item',
      'newsletter_full_width_list' => 'newsletter_item',
      'newsletter_half_width_list' => 'newsletter_item',
      'newsletter_half_image_left' => 'newsletter_item',
      'newsletter_full_width_2_col_blocks' => 'newsletter_item',
      'newsletter_half_width_twitter' => 'newsletter_item',
    ];
    if (empty($styles[$parentTemplate])) {
      return $default;
    }
    return $styles[$parentTemplate];
  }

  public static function alterContentForm(&$form, &$form_state) {
    // add submit button to send newsletter and send test newsletter
    if (isset($form['content'])) {
      $q = db_select('field_data_field_newsletter_template', 'nt');
      $q->fields('nt', ['entity_id', 'field_newsletter_template_value']);
      $default_templates = $q->execute()->fetchAllKeyed();

      foreach ($form['content'] as $k => &$v) {
        if (strpos($k, 'taxonomy_term:') !== FALSE) {
          $v['style']['#options'] = self::getTemplatesList();
          if (empty($v['style']['#default_value']) && !empty($v['entity_id']['#value'])) {
            $tid = $v['entity_id']['#value'];
            if (!empty($default_templates[$tid])) {
              $v['style']['#default_value'] = $default_templates[$tid];
            }
          }
        }
        elseif (strpos($k, 'node:') === 0) {
          $node = $v['#content']->content;
          $v['title']['#markup'] .= " <b>({$node->type})</b>";
          hide($v['style']);
        }
      }

      $form['actions']['send_test_newsletter'] = array(
        '#type' => 'submit',
        '#value' => t('Send test newsletter'),
        '#submit' => array('osha_newsletter_send_test_email')
      );
      $form['actions']['send_newsletter'] = array(
        '#type' => 'submit',
        '#value' => t('Send newsletter to subscribers'),
        '#submit' => array('osha_newsletter_send_email_to_subscribers')
      );
    }

    $modulePath = drupal_get_path('module', 'osha_newsletter');
    $form['#attached']['js'][] = "{$modulePath}/includes/js/collection_form.js";
    $form['#attached']['js'][] = [
      'data' => [
        'osha_newsletter' => ['basepath' => $modulePath]
      ],
      'type' => 'setting',
    ];
  }

  /**
   * Saves the newsletter configuration within field_configuration.
   * The following options are stored:
   *  - sections: an array with newsletter sections and their field values (field_background_image,
   * field_icon, field_background_color, field_newsletter_template)
   *  - tweets: an array containing tweet_feed nodes ids
   *  - fids: an array with the fids of used files
   *
   * @param \EntityCollection $entityCollection
   */
  public static function saveConfiguration(EntityCollection $entityCollection) {
    $sections = taxonomy_get_tree('11', 0, null, true);

    $configuration = [
      'sections' => [],
      'tweets' => self::getTwitterNodes($entityCollection),
      'fids' => [],
    ];
    foreach ($sections as $section) {
      $sectionConfig = [];
      if (!empty($section->field_background_image[LANGUAGE_NONE][0]['uri'])) {
        $configuration['fids'][] = $section->field_background_image[LANGUAGE_NONE][0]['fid'];
        $sectionConfig['field_background_image'] = $section->field_background_image;
      }
      if (!empty($section->field_icon[LANGUAGE_NONE][0]['uri'])) {
        $configuration['fids'][] = $section->field_icon[LANGUAGE_NONE][0]['fid'];
        $sectionConfig['field_icon'] = $section->field_icon;
      }
      if (!empty($section->field_background_color[LANGUAGE_NONE][0]['value'])) {
        $sectionConfig['field_background_color'] = $section->field_background_color;
      }
      if (!empty($section->field_newsletter_template[LANGUAGE_NONE][0]['value'])) {
        $sectionConfig['field_newsletter_template'] = $section->field_newsletter_template;
      }

      if (!empty($sectionConfig)) {
        $configuration['sections'][$section->tid] = $sectionConfig;
      }
    }

    foreach ($configuration['fids'] as $fid) {
      // We are referencing the files so they won't be deleted by the garbage collector
      $entityCollection->field_images[LANGUAGE_NONE][] = ['fid' => $fid];
    }

    $entityCollection->field_newsletter_configuration[LANGUAGE_NONE][0]['value'] = json_encode($configuration);
    entity_save('entity_collection', $entityCollection);
  }

  /**
   * @param \EntityCollection $entityCollection
   * @param string $config_name
   *  Available options:
   *    - tweets
   *    - field_background_image
   *    - field_icon
   *    - field_background_color
   *    - field_newsletter_template
   * @param $section
   *
   * @return array
   */
  public static function getConfiguration(EntityCollection $entityCollection, $config_name, $section = null, $default_value = null) {
    $configuration = !empty($entityCollection->field_newsletter_configuration[LANGUAGE_NONE][0]['value'])
      ? json_decode($entityCollection->field_newsletter_configuration[LANGUAGE_NONE][0]['value'], true)
      : null;

    switch ($config_name) {
      case 'tweets':
        return !empty($configuration['tweets']) ? $configuration['tweets'] : self::getTwitterNodes($entityCollection);
      case 'field_background_image':
      case 'field_icon':
        if (!empty($configuration['sections'][$section->tid][$config_name][LANGUAGE_NONE][0]['uri'])) {
          // Field value found in newsletter configuration
          return file_create_url($configuration['sections'][$section->tid][$config_name][LANGUAGE_NONE][0]['uri']);
        }
        elseif (!empty($section->{$config_name}[LANGUAGE_NONE][0]['uri'])) {
          // Field value not found - get the field value from the term
          return file_create_url($section->{$config_name}[LANGUAGE_NONE][0]['uri']);
        }
        break;
      case 'field_background_color':
      case 'field_newsletter_template':
        if (!empty($configuration['sections'][$section->tid][$config_name][LANGUAGE_NONE][0]['value'])) {
          // Field value found in newsletter configuration
          return $configuration['sections'][$section->tid][$config_name][LANGUAGE_NONE][0]['value'];
        }
        elseif (!empty($section->{$config_name}[LANGUAGE_NONE][0]['value'])) {
          // Field value not found - get the field value from the term
          return $section->{$config_name}[LANGUAGE_NONE][0]['value'];
        }
        break;
    }

    return $default_value;
  }

  public static function getCellContent($template, $node) {
    if ($template == 'newsletter_full_width_2_col_blocks' && $node['#style'] == 'newsletter_item') {
      $node['node']->arrow_color = 'white';
    }

    $nodeContent = node_view($node['node'], $node['#style']);

    return [
      'data' => drupal_render($nodeContent),
      'class' => ['item', drupal_clean_css_identifier("{$template}-item")],
    ];
  }

  public static function renderTemplate(EntityCollection $entityCollection, $template, $variables) {
    $content = [
      '#theme' => 'table',
      '#header' => [],
      '#rows' => [0 => []],
      '#attributes' => [
        'class' => [
          drupal_clean_css_identifier($template),
          'newsletter-section',
          'template-container',
        ],
        'width' => '100%',
        'cellpadding' => '0',
        'cellspacing' => '0',
      ],
      '#printed' => false,
      '#sticky' => false,
      '#children' => [],
    ];
    if (!empty($variables['section']->name)) {
      $icon = self::getConfiguration($entityCollection, 'field_icon', $variables['section']);
      if (!empty($icon)) {
        $cellContent = sprintf("<img src=\"%s\" class=\"section-icon\"><div>%s</div>", $icon, $variables['section']->name);
      }
      else {
        $cellContent = $variables['section']->name;
      }
      $content['#header'] = ['data' => ['data' => $cellContent]];
      $cssClass = drupal_clean_css_identifier('section-' . strtolower($variables['section']->name));
      $content['#attributes']['class'][] = $cssClass;
    }
    switch ($template) {
      case 'newsletter_multiple_columns':
        $columnWidth = round((800 / count($variables)), 2) - 20;
        foreach ($variables as $column) {
          $content['#rows'][0]['data'][] = [
            'data' => self::renderTemplate($entityCollection, $column['#style'], $column),
            'width' => "$columnWidth",
            'height' => '100%',
            'class' => 'multiple-columns-cell template-column',
          ];
        }
        break;
      case 'newsletter_full_width_list':
      case 'newsletter_half_width_list':
      case 'newsletter_full_width_details':
        if($template === 'newsletter_half_width_list') {
          $content['#attributes']['width'] = '100%';
        }
        foreach ($variables['nodes'] as $node) {
          $cellContent = self::getCellContent($template, $node);
          $content['#rows'][] = [
            'data' => [$cellContent],
            'class' => ['row', drupal_clean_css_identifier("{$template}-row")],
            'no_striping' => true,
          ];
        }
        break;
      case 'newsletter_half_image_left':
        // @todo: remove
        $image_url = 'https://healthy-workplaces.eu/sites/default/files/frontpage_slider/home_slide-2r-1.png';
        $image_fallback_bg = '#acc830';
        // 
        $content['#header']['data']['colspan'] = 2;

        // $image_url = self::getConfiguration($entityCollection, 'field_background_image', $variables['section'], '');
        // $image_fallback_bg = self::getConfiguration($entityCollection, 'field_background_color', $variables['section'], '');

        // Avoid rendering the section title twice
        unset($variables['section']);
        $content['#rows'][0]['data'][] = [
          'data' => '',
          'style' => 'padding: 10px 0px 10px 0px',
        ];
        $content['#rows'][1] = [
          'data' => [
            [
              // 'data' => sprintf("<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"100%%\" height=\"100%%\" style=\"height:100%%!important;background-color:%s;\" ><tbody><tr><td style=\"background-color:%s;\"><img src=\"%s\" width=\"370\" style=\"width:370px;max-width:100%%;background-color:%s; \"/></td></tr></tbody></table>", $image_fallback_bg, $image_fallback_bg, $image_url, $image_fallback_bg),
              'data' => sprintf("<img src=\"%s\" width=\"380\" style=\"width:380px;max-width:100%%;background-color:%s; \"/>", $image_url, $image_fallback_bg),
              'width' => '380',
              'height' => '100%',
              'class' => ['template-column', 'newsletter-half-image'],
              'style' => sprintf("max-width: 380px;height:100%%!important;background-color: %s;",$image_fallback_bg),
            ],
            [

              // 'data' => sprintf("<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"100%%\" height=\"100%%\" style=\"height:100%%!important;background-color:%s;\" ><tbody><tr><td style=\"background-color:%s;\">%s</td></tr></tbody></table>",
              //   $image_fallback_bg,
              //   $image_fallback_bg, 
              //   self::renderTemplate($entityCollection, 'newsletter_full_width_list', $variables)),

                // self::renderTemplate('newsletter_full_width_list', $variables)),

              'data' => self::renderTemplate($entityCollection, 'newsletter_full_width_list', $variables),
              'width' => '380',
              'height' => '100%',
              'class' => ['template-column', 'newsletter-half-content'],
              'style' => sprintf("max-width: 380px;height:100%%!important;background-color: %s;",$image_fallback_bg),

            ],
          ],
        ];
        $content['#rows'][2]['data'][] = [
          'data' => '',
          'style' => 'padding: 10px 0px 10px 0px',
        ];
        break;
      case 'newsletter_full_width_2_col_blocks':
        $content['#header']['data']['colspan'] = 2;
        $currentRow = $currentCol = 0;
        foreach ($variables['nodes'] as $node) {
          $cellContent = self::getCellContent($template, $node);
          $cellContent['width'] = '377'; // half - 3px of margin
          $cellContent['height'] = '100%';
          $cellContent['align'] = 'left';
          $cellContent['valign'] = 'top';
          if (empty($cellContent['style'])) {
            $cellContent['style'] = 'max-width:377px;';
          }
          else {
            $cellContent['style'] .= 'max-width:377px;';
          }
          array_push($cellContent['class'], 'template-column');
          if ($currentCol++ === 0) {
            $content['#rows'][$currentRow] = [
              'data' => [$cellContent],
              'class' => ['row', drupal_clean_css_identifier("{$template}-row")],
              'no_striping' => true,
            ];
          }
          else {
            $content['#rows'][$currentRow++]['data'][] = $cellContent;
            $currentCol = 0;
          }
        }
        break;
      case 'newsletter_half_width_twitter':
        $content['#header']['data']['colspan'] = 2;
        $currentRow = $currentCol = 0;
        foreach ($variables['nodes'] as $node) {
          $cellContent = self::getCellContent($template, $node);
          $cellContent['width'] = '400';
          $cellContent['height'] = '100%';
          $cellContent['style'] .= 'max-width:400px;';
          array_push($cellContent['class'], 'template-column');
          if ($currentCol++ === 0) {
            $content['#rows'][$currentRow] = [
              'data' => [$cellContent],
              'class' => ['row', drupal_clean_css_identifier("{$template}-row")],
              'no_striping' => true,
            ];
          }
          else {
            $content['#rows'][$currentRow++]['data'][] = $cellContent;
            $currentCol = 0;
          }
        }
        break;
      default:
        return theme($template, $variables);
    }
    return drupal_render($content);
  }

  public static function render(EntityCollection $source) {
    $content = [];
    $entityCollectionItems = entity_collection_load_content($source->bundle, $source);

    $campaign_id = '';
    if (!empty($source->field_campaign_id[LANGUAGE_NONE][0]['value'])) {
      $campaign_id = $source->field_campaign_id[LANGUAGE_NONE][0]['value'];
    };

    $items = $entityCollectionItems->children;
    $last_section = null;

    $templatesList = self::getTemplatesList();
    foreach ($items as $item) {
      switch ($item->type) {
        case 'taxonomy_term':
          $current_section = $item->entity_id;
          $content[$current_section] = [
            '#style' => !empty($item->style) ? $item->style : key($templatesList),
            'section' => $item->content,
            'nodes' => [],
          ];
          if ($content[$current_section]['#style'] == 'newsletter_half_width_twitter') {

            $tweets_ids = self::getConfiguration($source, 'tweets');
            foreach ($tweets_ids as $tweets_id) {
              $tweet = node_load($tweets_id);
              if (!empty($tweet)) {
                $content[$current_section]['nodes'][] = [
                  '#style' => self::getChildStyle('newsletter_half_width_twitter'),
                  'node' => $tweet,
                ];
              }
            }
          }
          break;
        case 'node':
          if (empty($current_section)) {
            // Found a node before all sections
            // @todo: maybe we should display a warning?
            continue;
          }
          $content[$current_section]['nodes'][] = [
            '#style' => self::getChildStyle($content[$current_section]['#style']),
            'node' => $item->content,
          ];
          break;
      }
    }

    $languages = osha_language_list(TRUE);

    $renderedContent = '';
    foreach ($content as $section) {
      if (empty($section['nodes'])) {
        continue;
      }
      if (preg_match('/.*(half_width).*/', $section['#style'])) {
        if (!empty($half_column)) {
          // Found 2 half-width templates in a row
          $renderedContent .= self::renderTemplate($source, 'newsletter_multiple_columns', [$half_column, $section]);
          $half_column = null;
        }
        else {
          $half_column = $section;
        }
      }
      else {
        if (!empty($half_column)) {
          // We couldn't find 2 half-width columns in a row, so we stick the only
          // one to the entire width
          $renderedContent .= self::renderTemplate($source, $half_column['#style'], $half_column);
          $half_column = null;
        }
        $renderedContent .= self::renderTemplate($source, $section['#style'], $section);
      }
    }

    $header = theme('newsletter_header', array(
      'languages' => $languages,
      'newsletter_title' => $source->title,
      'newsletter_id' => $source->eid,
      'newsletter_date' =>
        !empty($source->field_publication_date)
          ? $source->field_publication_date[LANGUAGE_NONE][0]['value']
          : $source->field_created[LANGUAGE_NONE][0]['value'],
      'campaign_id' => $campaign_id
    ));

    $footer = theme('newsletter_footer', array('campaign_id' => $campaign_id));

    $fullNewsletter = [
      '#theme' => 'table',
      '#header' => [],
      '#rows' => [
        'header' => [
          'data' => [$header],
          'no_striping' => true,
          'class' => 'header-container',
        ],
        'content' => [
          'data' => [$renderedContent],
          'no_striping' => true,
          'class' => 'content-container',
        ],
        'footer' => [
          'data' => [$footer],
          'no_striping' => true,
          'class' => 'footer-container',
        ],
      ],
      '#attributes' => ['class' => ['newsletter-container'], 'border' => '0', 'cellpadding' => '0', 'width' => '800'],
      '#printed' => false,
      '#sticky' => false,
      '#children' => [],
    ];

    $fullNewsletter = drupal_render($fullNewsletter);

    $stylesheet_path = drupal_get_path('module', 'osha_newsletter') . '/includes/css/newsletter.css';
    $fullNewsletter = self::cssToInlineStyles($fullNewsletter, $stylesheet_path);
    $fullNewsletter = self::appendFontInHead($fullNewsletter);

    return $fullNewsletter;
  }

  public static function getTwitterNodes(EntityCollection $source) {
    $q = db_select('node', 'n');
    $q->fields('n', ['nid']);
    $q->condition('n.type', 'twitter_tweet_feed');
    $q->range(0, self::$tweetsLimit);
    $q->orderBy('n.created', 'DESC');
    return $q->execute()->fetchCol();
  }

  /**
   * @param array|string $item
   * @param string $styles
   * @param CssToInlineStyles $cssToInlineStyles
   */
  public static function applyCss(&$item, $styles, CssToInlineStyles $cssToInlineStyles) {
    if (is_array($item)) {
      foreach ($item as &$subItem) {
        self::applyCss($subItem, $styles, $cssToInlineStyles);
      }
    }
    else {
      $item = $cssToInlineStyles->convert($item, $styles);
    }
  }

  /**
   * Converts the css styles from stylesheet into inline styles and returns the
   * full html
   *
   * @param $item
   * @param $stylesheet_path
   * @return mixed
   */
  public static function cssToInlineStyles($item, $stylesheet_path) {
    if (($library = libraries_load('CssToInlineStyles')) && !empty($library['loaded'])) {
      $cssToInlineStyles = new CssToInlineStyles();
      $styles = file_get_contents($stylesheet_path);
      self::applyCss($item, $styles, $cssToInlineStyles);
    }
    return $item;
  }

  public static function appendFontInHead($html) {
    $domDocument = new \DOMDocument('1.0', 'UTF-8');
    $domDocument->loadHTML(mb_convert_encoding($html, 'HTML-ENTITIES', 'UTF-8'));
    $domDocument->formatOutput = true;

    $font = $domDocument->createElement('link');
    $font->setAttribute('rel', 'stylesheet');
    $font->setAttribute('href', self::$fontUrl);

    $head = $domDocument->getElementsByTagName('head');
    if (empty($head->length)) {
      $head = $domDocument->createElement('head');
      $head->appendChild($font);
      $body = $domDocument->getElementsByTagName('body')->item(0);
      $body->parentNode->insertBefore($head, $body);
    }
    else {
      $head = $head->item(0);
      $head->appendChild($font);
    }

    return $domDocument->saveHTML();
  }

}