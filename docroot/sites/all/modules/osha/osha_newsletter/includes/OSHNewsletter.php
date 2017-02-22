<?php

class OSHNewsletter {

  public static function render(EntityCollection $source) {
    $content = entity_collection_load_content($source->bundle, $source);

    $newsletter_title = $source->title;
    $newsletter_id = $source->eid;
    $newsletter_date = $source->field_created[LANGUAGE_NONE][0]['value'];
    if (!empty($source->field_publication_date)) {
      $newsletter_date = $source->field_publication_date[LANGUAGE_NONE][0]['value'];
    }
    $campaign_id = '';
    if (isset($source->field_campaign_id[LANGUAGE_NONE][0]['value'])) {
      $campaign_id = $source->field_campaign_id[LANGUAGE_NONE][0]['value'];
    };

    $items = $content->children;
    $elements = array();
    $last_section = NULL;
    $blogs = array();
    $news = array();
    $events = array();

    // @todo: replace hardcoded sections with taxonomy terms
    foreach ($items as $item) {
      if ($item->type == 'taxonomy_term') {
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
        'newsletter_title' => $newsletter_title,
        'newsletter_id' => $newsletter_id,
        'newsletter_date' => $newsletter_date,
        'campaign_id' => $campaign_id
      )),
      'body' =>  osha_newsletter_format_body($body), //add css styles to href in body
      'footer' => theme('newsletter_footer', array('campaign_id' => $campaign_id)),
    ];
  }
}