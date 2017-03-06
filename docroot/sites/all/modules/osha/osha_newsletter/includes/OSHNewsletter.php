<?php

use \TijsVerkoyen\CssToInlineStyles\CssToInlineStyles;

class OSHNewsletter {

  public static $fontUrl = 'https://fonts.googleapis.com/css?family=Oswald:200,300,400,500';

  public static function getTemplatesList() {
    return [
      'newsletter_full_width_details' => 'Full width: detail',
      'newsletter_full_width_list' => 'Full width: summary',
      'newsletter_half_width_list' => '1/2 width: summary',
      'newsletter_half_image_left' => 'Healthy Workplaces Campaigns',
      'newsletter_full_width_2_col_blocks' => 'Events',
      'newsletter_half_width_twitter' => 'Twitter',
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

  public static function getCellContent($template, $node) {
    $nodeContent = node_view($node['node'], $node['#style']);
    return [
      'data' => drupal_render($nodeContent),
      'class' => ['item', drupal_clean_css_identifier("{$template}-item")],
    ];
  }

  public static function renderTemplate($template, $variables) {
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
      $content['#header'] = ['data' => ['data' => $variables['section']->name]];
      $cssClass = drupal_clean_css_identifier('section-' . strtolower($variables['section']->name));
      $content['#attributes']['class'][] = $cssClass;
    }
    switch ($template) {
      case 'newsletter_multiple_columns':
        $columnWidth = round((800 / count($variables)), 2) - 20;
        foreach ($variables as $column) {
          $content['#rows'][0]['data'][] = [
            'data' => self::renderTemplate($column['#style'], $column),
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
        // @todo: get the image and the fallback bg color from the taxonomy
        $image_url = 'https://healthy-workplaces.eu/sites/default/files/frontpage_slider/home_slide-2r-1.png';
        $image_fallback_bg = '#8DAA02';
        $content['#header']['data']['colspan'] = 2;

        // Avoid rendering the section title twice
        unset($variables['section']);

        $content['#rows'] = [
          'data' => [
            [
              'data' => sprintf("<div style=\"background-color: %s;\"><img src=\"%s\"></div>",
                $image_fallback_bg,
                $image_url),
              'width' => '50%',
              'class' => 'template-column',
            ],
            [
              'data' => sprintf("<div style=\"background-color: %s;\">%s</div>",
                $image_fallback_bg,
                self::renderTemplate('newsletter_full_width_list', $variables)),
              'width' => '50%',
              'class' => 'template-column',
            ],
          ],
        ];
        break;
      case 'newsletter_full_width_2_col_blocks':
        $content['#header']['data']['colspan'] = 2;
        $currentRow = $currentCol = 0;
        foreach ($variables['nodes'] as $node) {
          $cellContent = self::getCellContent($template, $node);
          $cellContent['width'] = '397';
          $cellContent['height'] = '100%';
          $cellContent['align'] = 'left';
          $cellContent['valign'] = 'top';
          $cellContent['style'] .= 'max-width:397px;';
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
          $cellContent['width'] = '49%';
          $cellContent['height'] = '100%';
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
            $content[$current_section]['nodes'] = self::getTwitterNodes($source);
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
          $renderedContent .= self::renderTemplate('newsletter_multiple_columns', [$half_column, $section]);
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
          $renderedContent .= self::renderTemplate($half_column['#style'], $half_column);
          $half_column = null;
        }
        $renderedContent .= self::renderTemplate($section['#style'], $section);
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
    // @todo https://trello.com/c/9YyKgowC
    $nodes = [];

    $q = db_select('node', 'n');
    $q->fields('n', ['nid']);
    $q->condition('n.type', 'twitter_tweet_feed');
    $q->range(0, 4);
    $q->orderBy('n.created', 'DESC');
    $nids = $q->execute()->fetchCol();
    foreach ($nids as $nid) {
      $node = node_load($nid);
      if (!empty($node)) {
        $nodes[] = [
          '#style' => self::getChildStyle('newsletter_half_width_twitter'),
          'node' => $node,
        ];
      }
    }
    return $nodes;
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