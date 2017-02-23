<?php

class OSHNewsletter {

  public static function getTemplatesList() {
    return [
      'newsletter_full_width_details' => 'Full width: thumbnail + details',
      'newsletter_full_width_list' => 'Full width: title + short description',
      'newsletter_half_width_details' => '1/2 width: thumbnail + details',
      'newsletter_half_width_list' => '1/2 width: title + short description',
      'newsletter_half_image_left' => '1/2 width with background image on left side',
      'newsletter_full_width_2_col_blocks' => 'Full width: blocks on 2 columns',
      'newsletter_twitter' => 'Twitter (latest 4 tweets)',
    ];
  }

  public static function getChildStyle($parentTemaplate, $default = 'newsletter_item') {
    $styles = [
      'newsletter_full_width_details' => 'highlights_item',
      'newsletter_full_width_list' => 'newsletter_item',
      'newsletter_half_width_details' => 'highlights_item',
      'newsletter_half_width_list' => 'newsletter_item',
      'newsletter_half_image_left' => 'newsletter_item',
      'newsletter_full_width_2_col_blocks' => 'newsletter_item',
    ];
    if (empty($styles[$parentTemaplate])) {
      return $default;
    }
    return $styles[$parentTemaplate];
  }

  public static function alterContentForm(&$form, &$form_state) {
    // add submit button to send newsletter and send test newsletter
    if (isset($form['content'])) {
      foreach ($form['content'] as $k => &$v) {
        if (strpos($k, 'taxonomy_term:') !== FALSE) {
          $v['style']['#options'] = self::getTemplatesList();
        }
        elseif (strpos($k, 'node:') === 0) {
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

    // Attach js to add css class for taxonomy rows.
    // #attributes on $v doesn't work.
    if (isset($form_state['entity_collection']) && $form_state['entity_collection']->bundle == 'newsletter_content_collection') {
      $form['#attached']['js'][] = drupal_get_path('module', 'osha_newsletter') . '/includes/js/collection_form.js';
    }
  }

  public static function renderTemplate($template, $variables) {
    $content = [
      '#theme' => 'table',
      '#header' => [],
      '#rows' => [0 => []],
      '#attributes' => [
        'class' => [drupal_clean_css_identifier($template)],
      ],
      '#printed' => false,
      '#sticky' => false,
      '#children' => [],
    ];
    switch ($template) {
      case 'newsletter_multiple_columns':
        $columnWidth = round((100 / count($variables)), 2);
        foreach ($variables as $column) {
          $content['#rows'][0]['data'][] = [
            'data' => self::renderTemplate($column['#style'], $column),
            'width' => "$columnWidth%",
          ];
        }
        break;
      case 'newsletter_full_width_list':
      case 'newsletter_half_width_details':
      case 'newsletter_half_width_list':
      case 'newsletter_full_width_details':
        if (empty($variables['section']) || empty($variables['nodes'])) {
          return '';
        }
        $cssClass = drupal_clean_css_identifier('section-' . strtolower($variables['section']->name));
        $content['#header'] = [$variables['section']->name];
        $content['#attributes']['class'][] = 'newsletter-section';
        $content['#attributes']['class'][] = $cssClass;
        foreach ($variables['nodes'] as $node) {
          $nodeContent = node_view($node['node'], $node['#style']);
          $content['#rows'][] = [
            'data' => [drupal_render($nodeContent)],
            'class' => [drupal_clean_css_identifier("{$template}-item")],
            'no_striping' => true,
          ];
        }
        break;
      case 'newsletter_half_image_left':
        // @todo
        break;
      case 'newsletter_full_width_2_col_blocks':
        // @todo
        break;
      case 'newsletter_twitter':
        // @todo
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
          $renderedContent .= self::renderTemplate($section['#style'], $half_column);
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

    $fullNewsletter = $header . $renderedContent . $footer;

    $stylesheet_path = drupal_get_path('module', 'osha_newsletter') . '/includes/css/newsletter.css';
    self::cssToInlineStyles($fullNewsletter, $stylesheet_path);

    return $fullNewsletter;
  }

  public static function applyCss(&$item, $styles) {
    if (is_array($item)) {
      foreach ($item as &$subItem) {
        self::applyCss($subItem, $styles);
      }
      return;
    }
    $cssToInlineStyles = new \TijsVerkoyen\CssToInlineStyles\CssToInlineStyles();
    $item = $cssToInlineStyles->convert($item, $styles);
  }

  public static function cssToInlineStyles(&$item, $stylesheet_path) {
    if (($library = libraries_load('CssToInlineStyles')) && !empty($library['loaded'])) {
      $styles = file_get_contents($stylesheet_path);
      self::applyCss($item, $styles);
    }
  }
}