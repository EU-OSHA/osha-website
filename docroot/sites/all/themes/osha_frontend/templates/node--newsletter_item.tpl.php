<?php
/**
 * @file
 * EU-OSHA's theme implementation to display a newsletter item in Newsletter item view mode.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<?php if($node->title != NULL) {?>
  <table id="node-<?php print $node->nid; ?>" border="0" cellpadding="0" cellspacing="0" width="100%" height="100%" class="newsletter-item" style="height:100%!important;">
    <tbody>
    <?php
    if (isset($node->field_publication_date[LANGUAGE_NONE][0]['value']) && $node->type != 'newsletter_article') {
      $date = strtotime($node->field_publication_date[LANGUAGE_NONE][0]['value']);
      ?>
      <tr>
        <td colspan="2" style="font-family: Arial, sans-serif; font-size: 14px;">
          <span class="item-date"><?php print format_date($date, 'custom', 'd/m/Y');?></span>
        </td>
      </tr>
      <?php
    } if ($node->type == 'events') {
      $date = (isset($field_start_date) && !empty($field_start_date)) ? strtotime($field_start_date[0]['value']) : '';
      $country_location = (isset($field_country_code) && !empty($field_country_code)) ? $field_country_code[0]['value'] : '';
      $city_location = (isset($field_city) && !empty($field_city)) ? $field_city[0]['safe_value'] : '';
      ?>
      <tr>
        <td colspan="2" style="font-family: Arial, sans-serif; font-size: 14px; padding-left: 14px;">
          <span class="item-date"><?php if (trim($country_location) != '' && trim($city_location) != '') { echo $country_location . ' ' . $city_location . ', ';} if (trim($date) != '') { print format_date($date, 'custom', 'd/m/Y');}?></span>
        </td>
      </tr>
      <?php
    }
    ?>
    <tr style="height: 100%;">
      <?php
        if ($node->type !== 'twitter_tweet_feed') {
      ?>
        <td align="left" width="10" style="padding-right: 0px; vertical-align: top; padding-top: 5px;">
          <?php
          $directory = drupal_get_path('module','osha_newsletter');
          global $base_url; // TODO: should link to node

  //        dpm($node->arrow_color);die;
          $arrow_img = !empty($node->arrow_color) ? "link-arrow-{$node->arrow_color}.png" : "link-arrow.png";

          print l(theme('image', array(
            'path' => $directory . '/images/' . $arrow_img,
            'width' => 7,
            'height' => 11,
            'alt' => 'link arrow',
            'attributes' => array('style' => 'border: 0px;height:11px!important;width:7px!important;')
          )), $base_url, array(
            'html' => TRUE,
            'external' => TRUE
          ));
          ?>
        </td>
      <?php } ?>
      <td align="right" style="text-align: left; padding-top: 5px; padding-bottom: 10px;">
        <?php
        if (isset($variables['elements']['#campaign_id'])) {
          $url_query = array('pk_campaign' => $variables['elements']['#campaign_id']);
        } else {
          $url_query = array();
        }
        switch ($node->type) {
          case 'publication':
            print l($node->title, url('node/' . $node->nid . '/view', array('absolute' => TRUE)), array(
              'attributes' => array('style' => 'text-decoration: none; font-family:Arial, sans-serif; font-size: 12px; font-weight: bold;'),
              'query' => $url_query,
              'external' => TRUE
            ));
            break;
          case 'twitter_tweet_feed':
            if (!empty($node->field_tweet_author[LANGUAGE_NONE][0]['value'])
              && !empty($node->field_tweet_contents[LANGUAGE_NONE][0]['value'])) {
              printf("<p>@%s</p><p>%s</p>",
                $node->field_tweet_author[LANGUAGE_NONE][0]['value'],
                $node->field_tweet_contents[LANGUAGE_NONE][0]['value']);

            }
            else {
              goto defaultLabel;
            }
            break;
          case 'newsletter_article':
            if (empty($node->body)) {
              print $node->title;
            }
            else {
              goto defaultLabel;
            }
            break;
          default:
            defaultLabel:
            print l($node->title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
              'attributes' => array('style' => 'text-decoration: none; font-family:Arial, sans-serif; font-size: 12px; font-weight: bold;'),
              'query' => $url_query,
              'external' => TRUE
            ));
            break;
        }
        ?>
      </td>
    </tr>
    <!-- <tr>
      <td colspan="2" style="border-bottom:1px dashed #CFDDEE;padding-top:0px;"></td>
    </tr> -->
    <!-- <tr>
      <td colspan="2" style="padding-bottom: 10px;" class="space-beyond-dotted-line"></td>
    </tr> -->
    </tbody>
  </table>
<?php } ?>
