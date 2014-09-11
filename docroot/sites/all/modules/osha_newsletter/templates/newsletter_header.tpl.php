<table border="0" cellpadding="0" cellspacing="0" width="800" class="top-blue-line">
  <tbody>
    <tr>
      <td colspan="2" style="background-color:#003399; width:800px; height: 4px;" valign="top"></td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="28" cellspacing="0" width="800" style="font-family: Oswald, Arial,sans-serif;">
  <tbody>
    <tr>
      <td>
        <?php
          $directory = drupal_get_path('module','osha_newsletter');
          $site_url = variable_get('site_base_url', 'http://osha.localhost');
          print l(theme('image', array(
          'path' => $directory . '/images/Osha-EU-logos.png',
          'width' => 256,
          'height' => 60,
          'alt' => 'Osha logo',
          )), $site_url, array(
          'html' => TRUE,
          'external' => TRUE
        ));
        ?>
      </td>
      <td>
        <div class="newsletter-month" style="color: #DC2F82; font-size: 26px; text-align: right;">July 2014</div>
        <div class="newsletter-number" style="color: #003399; font-size: 24px; font-weight: 300; text-align: right;">OSHMail newsletter 145</div>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="28" cellspacing="0" width="800">
  <tbody>
    <tr>
      <td style="padding-top: 0px; padding-bottom: 0px;">
        <table border="0" cellpadding="0" cellspacing="0" width="100%">
          <tbody>
            <tr>
              <td style="background-color:#003399; width: 100%; height: 4px;"></td>
            </tr>
            <tr>
              <td style="background-color: #A6B8DB; width: 100%; height: 36px; text-align: center; font-size: 24px; font-weight: 300; color: #003399; font-family: Oswald, Arial,sans-serif;">Occupational Safety and Health News - Europe</td>
            </tr>
            <tr>
              <td>
                <table border="0" cellpadding="15" cellspacing="0" width="100%">
                  <tbody>
                    <tr>
                      <td style="font-size: 12px; padding-left: 30px; padding-right: 30px; font-family: Arial,sans-serif;">
                        <?php
                         if ($languages) {
                            $last_lang = array_pop($languages);
                            foreach ($languages as $langcode => $language):?>
                            <a href="#" style="text-decoration: none; color: #003399;"><?php print $language->name . ' | ';?></a><?php  endforeach; ?> <a href="#" style="text-decoration: none; color: #003399;"><?php print $last_lang->name;?></a>
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
              <td style="background-color:#003399; width: 100%; height: 4px;"></td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>