
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
?>

<table border="0" cellpadding="0" cellspacing="0" width="100%" class="template-container footer">
  <tbody>
    <tr>
      <td style="padding-top: 15px; padding-bottom: 15px; text-align: center; font-family: Arial,sans-serif; font-size: 12px; color: #333333;">
        <p><b><?php print t('Occupational Safety and Health News &ndash; Europe brought to you by EU-OSHA.');?></b></p>
        <p><?php global $base_url; print t('Visit us at: <a href="@base_url" style="@style">@base_url</a>',
                    array('@style' => 'color: #003399; border-bottom-style: solid; border-bottom-width: 1px; text-decoration: none;', '@base_url' => $base_url.'/'.$language->language)); ?>
          <?php print '&nbsp;'?>
          <?php print t('Contact us: <a href="mailto:@mail" style="@style">@mail</a>',
            array('@style' => 'color: #003399; border-bottom-style: solid; border-bottom-width: 1px; text-decoration: none;', '@mail' => 'information@osha.europa.eu')); ?>
        </p>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" class="template-container footer">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" width="100%">
          <tbody>
            <tr>
              <td class="social">
                <p>
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

                  foreach ($social as $name => $options) {
                    $directory = drupal_get_path('module','osha_newsletter');
                    print l(theme('image', array(
                      'path' => $directory . '/images/' . $name . '-blue.png',
                      'width' => 'auto',
                      'height' => 20,
                      'alt' => $options['alt'],
                      'attributes' => array('style' => 'border:0px;height:20px;max-width:20px;')
                    )), $options['path'], array(
                      'attributes' => array('style' => 'color:#144989;text-decoration:none;'),
                      'html' => TRUE,
                      'external' => TRUE
                    ));
					print ('&nbsp;&nbsp;&nbsp;&nbsp;');
                  }
                ?>
                </p>
              </td>
            </tr>
            <tr>
              <td style="padding-top: 10px; padding-bottom: 10px; color: #333333; font-family: Arial, sans-serif; font-size: 13px; ">
                <p>
                <?php print t('Subscribe to our <a href="@url" style="@style">Alert service</a> for <br/> customised content delivery',
                            array('@style' => 'color: #003399;text-decoration:none;', '@url' => url($base_url.'/'.$language->language.'/alertservice', array('query' => $url_query)))); ?>
                </p>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
    <tr>
      <td style="text-align: center;">
        <table border="0" cellpadding="0" cellspacing="0" width="100%">
          <tbody>
            <tr>
              <td style="text-align: center; font-family: Arial, sans-serif; color: #333333; font-size: 13px;">
                <p><?php print t('No longer wish to receive OSHmail? <a href="@url" style="@style">Unsubscribe here.</a>', array('@style' => 'color: #003399; text-decoration: none;', '@url' => url($base_url.'/'.$language->language.'/oshmail-newsletter', array('query' => $url_query)))); ?>
                </p>

              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
    <tr>
        <td style="text-align: center;">
            <table border="0" cellpadding="0" cellspacing="0" width="100%">
                <tbody>
                <tr>
                    <td style="text-align: center; font-family: Arial, sans-serif; color: #333333; font-size: 13px;">
                        <p>
                          <?php print strtr('<a href="@url" style="@style">' . t('Privacy notice') . '</a>',
                            array('@style' => 'color: #003399;text-decoration:none;', '@url' => url($base_url . '/' . $language->language . '/node/2433', array('query' => $url_query)))); ?>
                        </p>
                    </td>
                </tr>
                </tbody>
            </table>
        </td>
    </tr>

  </tbody>
</table>
<div class="gmailfix" style="white-space:nowrap; font:15px courier; line-height:0;">
  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
</div>