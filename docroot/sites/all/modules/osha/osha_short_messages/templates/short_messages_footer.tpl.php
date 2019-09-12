<table border="0" cellpadding="28" cellspacing="0" width="800" class="blue-line">
  <tbody>
    <tr>
      <td style="padding-top: 0px; padding-bottom: 0px;">
        <table border="0" cellpadding="0" cellspacing="0" width="100%" class="blue-line">
          <tbody>
            <tr>
              <td style="background-color:#003399; width:800px; height: 4px;"></td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="28" cellspacing="0" width="800">
  <tbody>
    <tr>
      <td style="padding-top: 15px; padding-bottom: 15px; text-align: center; font-family: Arial,sans-serif; font-size: 12px; color: #333333;">
        <span><?php print t('Occupational Safety and Health News &ndash; Europe'); ?></span>
        <?php global $base_url; print lcfirst(t('Brought to you by EU-OSHA. Visit us at: <a href="@base_url" style="@style">@base_url</a>',
                    array('@style' => 'color: #003399; border-bottom-color: #DC2F82; border-bottom-style: solid; border-bottom-width: 1px; text-decoration: none;', '@base_url' => $base_url))); ?>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="800">
  <tbody>
    <tr>
      <td style="background-color: #B2B3B5; width:800px;">
        <table border="0" cellpadding="28" cellspacing="0" width="800">
          <tbody>
            <tr>
              <td style="padding-top: 10px; padding-bottom: 10px; color: #FFFFFF; font-family: Arial, sans-serif; font-size: 13px; ">
                <?php print t('Subscribe to our <a href="@url" style="@style">Alert service</a> for <br/> customised content delivery',
                            array('@style' => 'color: #FFFFFF;', '@url' => url('https://osha.europa.eu/en/alertservice'))); ?>
              </td>
              <td class="social" style="padding-top: 20px; padding-bottom: 10px; float: right;">
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
                      'path' => url('tools-and-resources/blog', array('alias' => TRUE, 'absolute' => TRUE)),
                      'alt' => t('blog')
                    ),
                    'youtube' => array(
                      'path' => 'https://www.youtube.com/user/EUOSHA',
                      'alt' => t('Youtube')
                    )
                  );

                  foreach ($social as $name => $options) {
                    $directory = drupal_get_path('module','osha_newsletter');
                    print l(theme('image', array(
                      'path' => $directory . '/images/' . $name . '.png',
                      'width' => 'auto',
                      'height' => 26,
                      'alt' => $options['alt'],
                      'attributes' => array('style' => 'border: 0px;')
                    )), $options['path'], array(
                      'attributes' => array('style' => 'color: #144989; text-decoration: none;'),
                      'html' => TRUE,
                      'external' => TRUE
                    ));
					print ('&nbsp;&nbsp;&nbsp;&nbsp;');
                  }
                ?>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>
