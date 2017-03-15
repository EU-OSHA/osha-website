<!-- @TODO: remove once newsletter-responsive.css is included -->
<style>
  @media only screen and (max-width: 600px) {
    .template-container {
      /* max-width: 400px; */
    }
    .newsletter-container {
      max-width: 100% !important;
      width: 100% !important;
    }
    table[width],
    .template-image,
    .template-container,
    .template-column {
      max-width: 100% !important;
      width: 100% !important;
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    img {
      max-width: 100% !important;
    }
    .template-column {
      display: block !important;
    }

    .template-column td {
      /* padding-left: 0 !important;
      padding-right: 0 !important; */
    }
    .template-column img {
      width: auto !important;
      height: auto !important;
    }
    .template-image {
      text-align: center !important;
    }
    .template-column > .newsletter-item {
      background-color: transparent;
      color: #003399;
    }
    .newsletter-full-width-2-col-blocks-item > .newsletter-item > tbody > tr > td {
      padding: 5px 0px;
    }

    .newsletter-item {
      border-bottom: 1px dashed #dddddd;
    }

    .newsletter-section > tbody > .row:last-child > .item:last-child > .newsletter-item {
      border-bottom: none;
    }

    /* .newsletter-section .row:first-child > .item:last-child:not(:only-child) {
      padding-top: 3px !important;
    }
    .newsletter-section .row:last-child > .item:first-child:not(:only-child) {
      padding-bottom: 3px !important;
    } */
    td.social {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    /* .preheader .social {
      text-align: center !important;
    } */
    .newsletter-half-image-left-container {
      background-image: none!important;
    }
    .newsletter-half-image {
      padding-bottom: 0 !important;
    }
    .newsletter-half-image td {
      padding-right: 0 !important;
    }
    .newsletter-half-content {
      padding-top: 0 !important;
    }
  }
  @media only screen and (max-width: 500px) {
    .osha-logos {
      text-align: center !important;
    }
    .osha-logos,
    .osha-info {
      display: block !important;
      max-width: 100% !important;
      width: 100% !important;
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
  }
</style>
<!-- end @TODO -->
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

?>
<span class="preview-text" style="font-size: 0;">
  <?php
    $newsletter_ready_date = format_date(strtotime($newsletter_date), 'custom', 'F Y');
    print t("Occupational Safety and Health News &ndash; Europe &ndash; ");
    print $newsletter_ready_date;
  ?>
</span>
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="preheader template-container">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" width="100%" class="language-bar">
          <tbody>
            <tr>
              <td style="font-size: 12px; padding-left: 30px; padding-right: 30px; font-family: Arial,sans-serif;">
                <?php
                 if ($languages) {
                   $newsletter_languages = array();
                   foreach ($languages as $l) {
                     if ($l->language != "tr" && $l->language != "ru") {
                       $newsletter_languages[] = $l;
                     }
                   }
                   $last_lang = array_pop($newsletter_languages);
                   foreach ($newsletter_languages as $l):?>
                     <a href="<?php echo url('entity-collection/' . $newsletter_id, array('absolute' => TRUE, 'language' => $l, 'query' => $url_query));?>" style="text-decoration: none; color: #003399;"><?php print $l->native . ' | ';?></a>
                   <?php endforeach; ?>
                   <a href="<?php echo url('entity-collection/' . $newsletter_id, array('absolute' => TRUE, 'language' => $last_lang, 'query' => $url_query));?>" style="text-decoration: none; color: #003399;"><?php print $last_lang->native;?></a>
                 <?php
                 }
                ?>
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
                'linkedin' => array(
                  'path' => 'https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
                  'alt' => t('LinkedIn')
                ),
                'face' => array(
                  'path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
                  'alt' => t('Facebook')
                ),
                'blog' => array(
                  'path' => url('tools-and-publications/blog', array('alias' => TRUE, 'absolute' => TRUE, 'query' => $url_query)),
                  'alt' => t('blog')
                ),
                'youtube' => array(
                  'path' => 'https://www.youtube.com/user/EUOSHA',
                  'alt' => t('Youtube')
                )
              );

              $directory = drupal_get_path('module','osha_newsletter');
              foreach ($social as $name => $options):?>
                <td align="Right">
                <?php
                  print l(theme('image', array(
                    'path' => $directory . '/images/' . $name . '-blue.png',
                    'width' => 'auto',
                    'height' => 20,
                    'alt' => $options['alt'],
                    'attributes' => array('style' => 'border:0px;')
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

<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family: Oswald, Arial,sans-serif;" class="header template-container fallback-text">
  <tbody>
    <tr>
      <td class="osha-logos">
        <?php
          $directory = drupal_get_path('module','osha_newsletter');
          global $base_url;
          global $language;
          print l(theme('image', array(
          'path' => $directory . '/images/Osha-EU-logos.png',
          'width' => 256,
          'height' => 60,
          'alt' => 'Osha logo',
          'attributes' => array('style' => 'border: 0px; width: 256px; max-width: 256px;')
          )), $base_url.'/'.$language->language, array(
          'html' => TRUE,
          'external' => TRUE,
          'query' => $url_query
        ));
        ?>
      </td>
      <td class="osha-info">
        <div class="newsletter-number fallback-text" style="color: #003399; font-size: 20px; font-weight: 200; text-align: right;"><?php print $newsletter_title?></div>
        <div class="newsletter-month fallback-text" style="color: #DC2F82; font-size: 26px; text-align: right;"><?php print $newsletter_ready_date?></div>
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
              <td style="background-color: #003399; width: 100%; text-align: left; font-size: 24px; font-weight: 200; color: #ffffff; font-family: Oswald, Arial,sans-serif;" class="fallback-text"><?php print t("Occupational Safety and Health News &ndash; Europe");?></td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>