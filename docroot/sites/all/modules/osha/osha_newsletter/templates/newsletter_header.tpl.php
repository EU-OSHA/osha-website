<?php

if (empty($campaign_id)) {
  if (!empty($variables['elements']['#campaign_id'])) {
    $campaign_id = $variables['elements']['#campaign_id'];
  }
  elseif (!empty($variables['campaign_id'])) {
    $campaign_id = $variables['campaign_id'];
  }
}

$url_query = array();
if (!empty($campaign_id)) {
  $url_query = array('pk_campaign' => $campaign_id);
}

global $language;
$directory = drupal_get_path('module','osha_newsletter');
?>

<span class="preview-text" style="color: transparent; display: none !important; height: 0; max-height: 0; max-width: 0; opacity: 0; overflow: hidden; mso-hide: all; visibility: hidden; width: 0;">
  <?php
    $newsletter_ready_date = format_date(strtotime($newsletter_date), 'custom', 'F Y');
    print t("Occupational Safety and Health News &ndash; Europe &ndash; ");
    print t($newsletter_ready_date);
  ?>
</span>
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="preheader template-container">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" width="100%" class="language-bar" style="max-width:100%;">
          <tbody>
            <tr>
              <td style="font-size: 12px; padding-left: 30px; padding-right: 30px; font-family: Arial,sans-serif;">
                <?php
                 if ($languages) {
                   $languages_text = [];
                   foreach ($languages as $l) {
                     if ($l->language != "tr" && $l->language != "ru") {
                       $languages_text[] = strtr('<a href="!link" style="text-decoration: none; color: !color; ">!text</a>',
                          [
                            '!link' => url('entity-collection/' . $newsletter_id, array('absolute' => TRUE, 'language' => $l, 'query' => $url_query)),
                            '!color' => ($l->language == $language->language) ? '#003399' : '#606060',
                            '!text' => $l->native
                          ]);
                    }
                  }
                 }
                ?>
                <?php foreach ($languages_text as $lidx =>  $lang_text) { ?>
                  <?php if ($lidx > 0): ?>
                    <span style="color: #606060;"> | </span>
                  <?php endif; ?>
                  <?php print $lang_text;?>
                <?php } ?>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
    <tr>
      <td class="social">
        <table border="0" cellpadding="20" cellspacing="0" width="auto" align="Right" style="width:auto!important;">
          <tbody><tr>
            <?php
              $social = array(
                'twitter' => array(
                  'path' => 'https://twitter.com/eu_osha',
                  'alt' => t('Twitter')
                ),
                'face' => array(
                  'path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
                  'alt' => t('Facebook')
                ),
                'linkedin' => array(
                  'path' => 'https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
                  'alt' => t('LinkedIn')
                ),
                'youtube' => array(
                  'path' => 'https://www.youtube.com/user/EUOSHA',
                  'alt' => t('Youtube')
                ),
                'flickr' => array(
                  'path' => 'https://www.flickr.com/photos/euosha/albums',
                  'alt' => t('Flickr')
                ),
                'blog' => array(
                  'path' => url('tools-and-publications/blog', array('alias' => TRUE, 'absolute' => TRUE, 'query' => $url_query)),
                  'alt' => t('Blog')
                ),
              );

              foreach ($social as $name => $options):?>
                <td align="Right">
                <?php
                  print l(theme('image', array(
                    'path' => $directory . '/images/' . $name . '-blue.png',
                    'width' => 'auto',
                    'height' => 20,
                    'alt' => $options['alt'],
                    'attributes' => array('style' => 'border:0px;height:20px;max-height:20px;max-width:20px;')
                  )), $options['path'], array(
                    'attributes' => array('style' => 'color:#144989;text-decoration:none;'),
                    'html' => TRUE,
                    'external' => TRUE
                  ));
                ?>
                </td>
              <?php endforeach; ?>
          </tr>
        </tbody>
        </table>
      </td>
    </tr>
    <!-- <tr>
      <td colspan="2" style="background-color:#003399; width:800px; height: 4px;" valign="top"></td>
    </tr> -->
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family: Oswald, Arial,sans-serif;" class="header template-container">
  <tbody>
    <tr>
      <td class="osha-logos">
        <?php
          global $base_url;
          print l(theme('image', array(
            'path' => $directory . '/images/EU-OSHA-en.png',
            'width' => 247,
            'height' => 84,
            'alt' => 'European Agency for Safety and Health at Work',
            'attributes' => array('style' => 'border: 0px; width: 247px; max-width: 247px; height: 87px; max-height: 87px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
          print theme('image', array(
            'path' => $directory . '/images/europeLogo.png',
            'width' => 63,
            'height' => 41,
            'alt' => 'EU',
            'attributes' => array('style' => 'border: 0px; margin-left: 20px; width: 63px; max-width: 63px; height: 41px; max-height: 41px;')
          ));
        ?>
      </td>
      <td class="osha-info">
        <div class="newsletter-number" style="color: #003399; font-size: 20px; font-weight: 200; text-align: right;"><?php print $newsletter_title; ?></div>
        <div class="newsletter-month" style="color: #DC2F82; font-size: 26px; text-align: right;"><?php print $newsletter_ready_date; ?></div>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" class="template-container">
  <tbody>
    <tr>
      <td style="padding-top: 0px; padding-bottom: 25px;">
        <table border="0" cellpadding="0" cellspacing="0" width="100%" class="header-title">
          <tbody>
            <tr>
              <td style="background-color: #003399; width: 70%; text-align: left; font-size: 24px; font-weight: 200; color: #ffffff; font-family: Oswald, Arial,sans-serif;">
                <?php print t("Occupational Safety and Health News &ndash; Europe");?>
              </td>
              <td style="background-color: #003399; width: 30%; text-align: right; font-size: 14px; font-weight: 200; color: #ffffff; font-family: Oswald, Arial,sans-serif;" class="hidden-print">
                <?php
                  $mailto_subject = 'OSH Newsletter: ' . $newsletter_title;
                  $newsletter_url = url('entity-collection/' . $newsletter_id, array('absolute' => TRUE, 'language' => $language));
                  $mailto_body = t('Check out this newsletter') . ': ' . $newsletter_url;
                ?>
                <a href="mailto:?subject=<?php print $mailto_subject; ?>&amp;body=<?php print $mailto_body; ?>"
                   title="Share by Email"
                   class="forward-newsletter-link"
                   style="color: #ffffff;">
                  <?php print t("Forward this newsletter");?>
                  &nbsp;
                  <?php print theme('image', array(
                      'path' => $directory . '/images/external_link_white.png',
                      'width' => 'auto',
                      'height' => '13px',
                      'attributes' => array('style' => 'border:0px;height:13px;max-height:13px;max-width:13px;')
                    ));
                  ?>
                </a>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>