<?php

class OSHNewsletter {

  public static function alterContentForm(&$form, &$form_state) {
    // add submit button to send newsletter and send test newsletter
    if (isset($form['content'])) {
      foreach ($form['content'] as $k => &$v) {
        if (strpos($k, 'taxonomy_term:') !== FALSE) {
          hide($v['style']);
        }
        if (strpos($k, 'node:') === 0) {
          $v['style']['#options'] = array(
            'highlights_item' => 'Newsletter Highlights',
            'newsletter_item' => 'Newsletter Item',
          );
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

  public static function render(EntityCollection $source) {
    $content = [];
    $entityCollectionItems = entity_collection_load_content($source->bundle, $source);

    $campaign_id = '';
    if (!empty($source->field_campaign_id[LANGUAGE_NONE][0]['value'])) {
      $campaign_id = $source->field_campaign_id[LANGUAGE_NONE][0]['value'];
    };

    $items = $entityCollectionItems->children;
    $elements = array();
    $last_section = NULL;
    $blogs = array();
    $news = array();
    $events = array();

    // @todo: replace hardcoded sections with taxonomy terms
    foreach ($items as $item) {
      if ($item->type == 'taxonomy_term') {
        // Section
        $term = taxonomy_term_view($item->content, 'token');
        $last_section = $item->content->name_original;
        if ($last_section == 'Blog') {
          $blogs[] = $term;
        } else if ($last_section == 'News') {
          $news[] = $term;
        } else if ($last_section == 'Events') {
          $events[] = $term;
        } else {
          $elements[] = $term;
        }
      } else if ($item->type == 'node') {
        $style = $item->style;
        $node = node_view($item->content,$style);
        $node['#campaign_id'] = $campaign_id;

        if ($last_section == 'Blog') {
          $blogs[] = $node;
        } else if ($last_section == 'News') {
          $news[] = $node;
        } else if ($last_section == 'Events') {
          $events[] = $node;
        } else {
          $elements[] = $node;
        }
      }
    }

    $languages = osha_language_list(TRUE);

    $body = theme('newsletter_body', array(
      'items' => $elements,
      'blogs' => $blogs,
      'news' => $news,
      'events' => $events,
      'campaign_id' => $campaign_id
    ));

    return [
      'header' => theme('newsletter_header', array(
        'languages' => $languages,
        'newsletter_title' => $source->title,
        'newsletter_id' => $source->eid,
        'newsletter_date' =>
          !empty($source->field_publication_date)
          ? $source->field_publication_date[LANGUAGE_NONE][0]['value']
          : $source->field_created[LANGUAGE_NONE][0]['value'],
        'campaign_id' => $campaign_id
      )),
      'body' =>  osha_newsletter_format_body($body), //add css styles to href in body
      'footer' => theme('newsletter_footer', array('campaign_id' => $campaign_id)),
    ];
  }
}