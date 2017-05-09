<?php

use \TijsVerkoyen\CssToInlineStyles\CssToInlineStyles;

class OSHNewsletter {

  public static $fontUrl = 'https://fonts.googleapis.com/css?family=Oswald:200,400,500';

  public static function getTemplatesList() {
    return [
      'newsletter_full_width_details' => 'Teaser (full width)',
      'newsletter_full_width_list' => 'Summary (full width)',
      'newsletter_half_width_list' => 'Summary (half width)',
      'newsletter_half_image_left' => 'HWC (full width)',
      'newsletter_full_width_2_col_blocks' => 'Events (2 columns)',
      'newsletter_half_width_twitter' => 'Tweets (half width)',
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
      $form['actions']['send_newsletter'] = array(
        '#type' => 'submit',
        '#value' => t('Send newsletter to subscribers'),
        '#submit' => array('osha_newsletter_send_email_to_subscribers')
      );


      $form['test_newsletter_content'] = array(
        '#type' => 'fieldset',
        '#title' => t('Send one test newsletter to the test address'),
      );

      $form['test_newsletter_content']['test_address'] = array(
        '#type' => 'textfield',
        '#title' => t('Test email addresses'),
        '#description' => t('A single email address or a comma-separated list of email addresses cam be used as test addresses.'),
        '#default_value' => $user->mail,
        '#size' => 60,
        '#maxlength' => 128,
      );

      $form['test_newsletter_content']['send_test_newsletter'] = array(
        '#type' => 'submit',
        '#value' => t('Send test newsletter'),
        '#submit' => array('osha_newsletter_send_test_email')
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
    $voc = taxonomy_vocabulary_machine_name_load('newsletter_sections');
    $sections = taxonomy_get_tree($voc->vid, 0, null, true);

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
      'data' => render($nodeContent),
      'class' => ['item', drupal_clean_css_identifier("{$template}-item")],
    ];
  }

  public static function renderTemplate(EntityCollection $entityCollection, $template, $variables) {
    $campaign_id = '';
    if (!empty($entityCollection->field_campaign_id[LANGUAGE_NONE][0]['value'])) {
      $campaign_id = $entityCollection->field_campaign_id[LANGUAGE_NONE][0]['value'];
    };
    $url_query = array();
    if (!empty($campaign_id)) {
      $url_query = array('pk_campaign' => $campaign_id);
    }
    $content = [
      '#theme' => 'table',
      '#header' => [0 => []],
      '#rows' => [0 => []],
      '#attributes' => [
        'class' => [
          drupal_clean_css_identifier($template),
          'newsletter-section',
          'template-container'
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

        $cellContent = sprintf("<img src=\"%s\">", $icon);
        $content['#header'][0]['data'][] = ['data' => $cellContent, 'class' => ['section-icon'] ];

        $cellContent = sprintf("<span>%s</span>", $variables['section']->name);
        $content['#header'][1]['data'][] = ['data' => $cellContent, 'class' => ['section-title']];

      }
      else {
        $cellContent = sprintf("<span>%s</span>", $variables['section']->name);
        $content['#header'][0]['data'][] = ['data' => $cellContent, 'class' => ['section-title']];
      }


      $cssClass = drupal_clean_css_identifier('section-' . strtolower($variables['section']->name));
      $content['#attributes']['class'][] = $cssClass;
    }
    if (!empty($variables['section']->field_link[LANGUAGE_NONE][0]['url'])) {
      $url = $variables['section']->field_link[LANGUAGE_NONE][0]['url'];
      $arrow = theme('image', array(
        'path' => drupal_get_path('module','osha_newsletter') . '/images/' . 'pink-arrow.png',
        'width' => '19',
        'height' => '11',
        'attributes' => array('style' => 'border:0px;width:19px;height:11px;')
      ));
      $view_all = [
        '#theme' => 'table',
        '#header' => [],
        '#rows' => [0 => [
          [
            'data' => l(t('View all') . $arrow, $url, [
              'html' => true,
              'absolute' => true,
              'query' => $url_query,
              'attributes' => ['class' => ['view-all', 'see-more']]
            ]),
            'align' => 'Right',
            'style' => 'padding-top: 10px; padding-bottom: 20px; border-top: 1px dashed #dddddd;',
          ],
        ]],
        '#attributes' => [
          'class' => ['view-all-table'],
          'width' => '100%',
          'cellpadding' => '0',
          'cellspacing' => '0',
        ],
        '#printed' => false,
        '#sticky' => false,
        '#children' => [],
      ];
      $content['#suffix'] = render($view_all);
    }
    switch ($template) {
      case 'newsletter_multiple_columns':
        $columnWidth = round((760 / count($variables)), 2) - 20; // 20px padding for each column
        foreach ($variables as $column) {
          $content['#rows'][0]['data'][] = [
            'data' => self::renderTemplate($entityCollection, $column['#style'], $column),
            'width' => "$columnWidth",
            'class' => ['multiple-columns-cell', 'template-column'],
            'style' => sprintf('max-width:%spx;',$columnWidth, $columnWidth),
          ];
        }
        break;
      case 'newsletter_full_width_list':
      case 'newsletter_half_width_list':
      case 'newsletter_full_width_details':
        if($template === 'newsletter_half_width_list') {
          $content['#attributes']['width'] = '100%';
        }
        if($template !== 'newsletter_full_width_details') {
          $content['#rows'][]['data'][] = [
            'data' => '&nbsp;',
            'colspan' => 1,
            'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
          ];
        }
        foreach ($variables['nodes'] as $node) {
          $cellContent = self::getCellContent($template, $node);
          $content['#rows'][] = [
            'data' => [$cellContent],
            'class' => ['row', drupal_clean_css_identifier("{$template}-row")],
            'no_striping' => true,
          ];
        }
        if($template !== 'newsletter_full_width_details') {
          $content['#rows'][]['data'][] = [
            'data' => '&nbsp;',
            'colspan' => 1,
            'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
          ];
        }
        break;
      case 'newsletter_half_image_left':
        $content['#header'][0]['data'][0]['colspan'] = '2';

        $image_url = self::getConfiguration($entityCollection, 'field_background_image', $variables['section'], '');
        $image_fallback_bg = self::getConfiguration($entityCollection, 'field_background_color', $variables['section'], '');

        // Avoid rendering the section title twice
        unset($variables['section']);
        $content['#rows'][]['data'][] = [
          'data' => '&nbsp;',
          'colspan' => 2,
          'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
        ];
        $content['#rows'][] = [
          'data' => [
            [
              'data' => sprintf("<img src=\"%s\" style=\"width:100%%;max-width:100%%;background-color:%s; \"/>", $image_url, $image_fallback_bg),
              'width' => '380',
              'class' => ['template-column', 'newsletter-half-image'],
              'style' => sprintf("max-width: 380px;background-color: %s;",$image_fallback_bg),
            ],
            [

              'data' => self::renderTemplate($entityCollection, 'newsletter_full_width_list', $variables),
              'width' => '380',
              // 'height' => '100%',
              'class' => ['template-column', 'newsletter-half-content'],
              'style' => sprintf("max-width: 380px;background-color: %s;",$image_fallback_bg),

            ],
          ],
        ];
        $content['#rows'][]['data'][] = [
          'data' => '&nbsp;',
          'colspan' => 2,
          'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
        ];
        break;
      case 'newsletter_full_width_2_col_blocks':
        $content['#header'][0]['data'][0]['colspan'] = '3';

        $currentRow = 0;
        $currentCol = 0;

        $content['#rows'][$currentRow]['no_striping'] = true;
        $content['#rows'][$currentRow]['data'][] = [
          'data' => '&nbsp;',
          'colspan' => '3',
          'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
        ];

        $currentRow++;

        foreach ($variables['nodes'] as $node) {
          $cellContent = self::getCellContent($template, $node);
          $cellWidth = 378;
          $cellContent['width'] = $cellWidth; // half - 2px of margin
          // $cellContent['height'] = '100%';
          $cellContent['align'] = 'left';
          $cellContent['valign'] = 'top';
          $cellStyle = sprintf('max-width:%spx;background-color: #003399;', $cellWidth);
          if (empty($cellContent['style'])) {
            $cellContent['style'] = $cellStyle;
          }
          else {
            $cellContent['style'] .= $cellStyle;
          }
          array_push($cellContent['class'], 'template-column');

          if ($currentCol++ === 0) {
            $content['#rows'][$currentRow] = [
              'data' => [$cellContent],
              'class' => ['row', drupal_clean_css_identifier("{$template}-row")],
              'no_striping' => true,
            ];
            $content['#rows'][$currentRow]['data'][] = ['data' => '&nbsp;', 'style' => 'padding-bottom: 4px; min-width:4px; padding-top: 0; width: 4px; margin:0;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;', 'class' => 'template-column' ];
          }
          else {
            $content['#rows'][$currentRow++]['data'][] = $cellContent;
            $content['#rows'][$currentRow++]['data'][] = ['data' => '&nbsp;', 'style' => 'paddipadding-top: 0; ng: 0px; height:4px; font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;', 'colspan' => '3', 'class' => ['template-column', 'template-separator'] ];
            $currentCol = 0;
          }
        }
        $content['#rows'][++$currentRow]['no_striping'] = true;
        $content['#rows'][$currentRow]['data'][] = [
          'data' => '&nbsp;',
          'colspan' => '3',
          'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
        ];
        break;
      case 'newsletter_half_width_twitter':
        $content['#header'][0]['data'][0]['colspan'] = '2';

        global $base_url;
        $image_path = "{$base_url}/sites/all/modules/osha/osha_newsletter/images/twitter-gray.png";

        $content['#header'][0]['data'][0]['data'] .= '&nbsp;<img height="20" style="vertical-align:middle;height:20px!important;" src="' . $image_path . '"/>';
        $currentRow = $currentCol = 0;

        $content['#rows'][$currentRow]['no_striping'] = true;
        // $content['#rows'][$currentRow]['height'] = 0;
        $content['#rows'][$currentRow]['data'][] = [
          'data' => '&nbsp;',
          'colspan' => 2,
          'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
        ];

        $currentRow++;

        foreach ($variables['nodes'] as $node) {
          $cellContent = self::getCellContent($template, $node);
          $cellContent['width'] = '180';
          // $cellContent['height'] = '1%';
          if (empty($cellContent['style'])) {
            $cellContent['style'] = 'max-width:180px;';
          }
          else {
            $cellContent['style'] .= 'max-width:180px;';
          }
          // array_push($cellContent['class'], 'template-column');
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
        $content['#rows'][++$currentRow]['no_striping'] = true;
        $content['#rows'][$currentRow]['data'][] = [
          'data' => '&nbsp;',
          'colspan' => 2,
          'height' => 20,
          'style' => 'padding-top: 0; padding-bottom: 20px;font-size: 0px; line-height: 0px; mso-line-height-rule: exactly;',
        ];
        break;
      default:
        return theme($template, $variables);
    }
    if (!empty($content['#rows'])) {
      foreach ($content['#rows'] as $key => $row) {
        if (!empty($row)) {
          $content['#rows'][$key]['no_striping'] = true;
        }
      }
    }

    return theme('newsletter_base_table', array('content' => $content));
  }

  public static function render(EntityCollection $source) {
    $isOldNewsletter = false;
    $oldNewsletter = [
      'elements' => [],
      'blogs' => [],
      'news' => [],
      'events' => [],
    ];
    if (!empty($source->field_publication_date)) {
      $newsletterVersion2Date = variable_get('osha_newsletter_version_2_deployment_time', strtotime('1 March 2017'));
      $isOldNewsletter = $newsletterVersion2Date > strtotime($source->field_publication_date[LANGUAGE_NONE][0]['value']);
    }
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
          $section = $item->content;
          $section->campaign_id = $campaign_id;
          $section->old_newsletter = false;
          $content[$current_section] = [
            '#style' => !empty($item->style) ? $item->style : key($templatesList),
            'section' => $section,
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

          if ($isOldNewsletter) {
            $section->old_newsletter = true;
            $term = taxonomy_term_view($section, 'token');
            switch($current_section) {
              case '11': // News
                $oldNewsletter['news'][] = $term;
                break;
              case '14': // Blog
                $oldNewsletter['blogs'][] = $term;
                break;
              case '15': // Events
                $oldNewsletter['events'][] = $term;
                break;
              default:
                $oldNewsletter['elements'][] = $term;
            }
          }
          break;
        case 'node':
          if (empty($current_section) || $content[$current_section]['#style'] == 'newsletter_half_width_twitter') {
            // Found a node before all sections or within twitter section
            // @todo: maybe we should display a warning?
            continue;
          }
          $node = $item->content;
          $node->campaign_id = $campaign_id;
          $node->parent_section = $current_section;
          $node->old_newsletter = false;
          $content[$current_section]['nodes'][] = [
            '#style' => self::getChildStyle($content[$current_section]['#style']),
            'node' => $node,
          ];

          if ($isOldNewsletter) {
            $node->old_newsletter = true;
            $node = node_view($node, $item->style);
            $node['#campaign_id'] = $campaign_id;
            switch($current_section) {
              case '11': // News
                $oldNewsletter['news'][] = $node;
                break;
              case '14': // Blog
                $oldNewsletter['blogs'][] = $node;
                break;
              case '15': // Events
                $oldNewsletter['events'][] = $node;
                break;
              default:
                $oldNewsletter['elements'][] = $node;
            }
          }
          break;
      }
    }

    $languages = osha_language_list(TRUE);

    $renderedContent = '';
    if (!$isOldNewsletter) {
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

      if (!empty($half_column)) {
        $renderedContent .= self::renderTemplate($source, $half_column['#style'], $half_column);
        $half_column = null;
      }
    }
    else {
      $renderedContent = theme('newsletter_body', array(
        'items' => $oldNewsletter['elements'],
        'blogs' => $oldNewsletter['blogs'],
        'news' => $oldNewsletter['news'],
        'events' => $oldNewsletter['events'],
        'campaign_id' => $campaign_id,
      ));
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

    if ($isOldNewsletter) {
      $fullNewsletter['#attributes']['class'][] = 'old-newsletter';
    }

    $fullNewsletter = drupal_render($fullNewsletter);

    $stylesheet_path = drupal_get_path('module', 'osha_newsletter') . '/includes/css/newsletter.css';
    $fullNewsletter = self::cssToInlineStyles($fullNewsletter, $stylesheet_path);
    $fullNewsletter = self::appendFontInHead($fullNewsletter);

    return $fullNewsletter;
  }

  public static function getTwitterNodes(EntityCollection $entityCollection) {
    $configuration = !empty($entityCollection->field_newsletter_configuration[LANGUAGE_NONE][0]['value'])
      ? json_decode($entityCollection->field_newsletter_configuration[LANGUAGE_NONE][0]['value'], true)
      : null;
    $tweetsLimit = !empty($entityCollection->field_tweets_count[LANGUAGE_NONE][0]['value'])
      ? $entityCollection->field_tweets_count[LANGUAGE_NONE][0]['value']
      : 4;

    if (!empty($configuration['tweets'])) {
      return $configuration['tweets'];
    }

    $q = db_select('node', 'n');
    $q->innerJoin('field_data_field_tweet_creation_date', 'd', 'n.nid = d.entity_id');
    $q->fields('n', ['nid']);
    $q->condition('n.type', 'twitter_tweet_feed');
    $q->range(0, $tweetsLimit);
    $q->orderBy('d.field_tweet_creation_date_value', 'DESC');
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

    $meta = $domDocument->createElement('meta');
    $meta->setAttribute('name', 'viewport');
    $meta->setAttribute('content', 'width=device-width, initial-scale=1.0');

    $modulePath = drupal_get_path('module', 'osha_newsletter');

    $responsive_stylesheet_path =  $modulePath . '/includes/css/newsletter-responsive.css';
    $responsiveStylesheet =  file_get_contents($responsive_stylesheet_path);

    $responsiveStyle = $domDocument->createElement('style', $responsiveStylesheet);
    $responsiveStyle->setAttribute('type', 'text/css');

    global $osha_newsletter_send_mail;

    $print_stylesheet_path =  $modulePath . '/includes/css/newsletter-print.css';
    $printStylesheet =  file_get_contents($print_stylesheet_path);

    $printStyle = $domDocument->createElement('style', $printStylesheet);
    $printStyle->setAttribute('type', 'text/css');
    $printStyle->setAttribute('media', 'print');

    $outlookCss = file_get_contents($modulePath . '/includes/css/conditionals/newsletter-outlook.html');
    $outlookStyle = $domDocument->createDocumentFragment();
    $outlookStyle->appendXML($outlookCss);

    $yahooCss = file_get_contents($modulePath . '/includes/css/conditionals/newsletter-yahoo.html');
    $yahooStyle = $domDocument->createDocumentFragment();
    $yahooStyle->appendXML($yahooCss);

    $head = $domDocument->getElementsByTagName('head');
    if (empty($head->length)) {
      $head = $domDocument->createElement('head');
      $head->appendChild($meta);
      $head->appendChild($font);
      $head->appendChild($yahooStyle);
      $head->appendChild($outlookStyle);
      $head->appendChild($responsiveStyle);
      if (empty($osha_newsletter_send_mail)) {
        $head->appendChild($printStyle);
      }
      $body = $domDocument->getElementsByTagName('body')->item(0);
      $body->parentNode->insertBefore($head, $body);
    }
    else {
      $head = $head->item(0);
      $head->appendChild($meta);
      $head->appendChild($font);
      $head->appendChild($yahooStyle);
      $head->appendChild($outlookStyle);
      $head->appendChild($responsiveStyle);
      if (empty($osha_newsletter_send_mail)) {
        $head->appendChild($printStyle);
      }
    }

    return $domDocument->saveHTML();
  }
}