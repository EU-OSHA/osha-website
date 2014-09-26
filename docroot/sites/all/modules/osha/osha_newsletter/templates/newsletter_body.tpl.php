<link href='http://fonts.googleapis.com/css?family=Oswald:400,300,700' rel='stylesheet' type='text/css'>
<table border="0" cellpadding="28" cellspacing="0" width="800">
  <tbody>
    <tr>
      <td width="100%" style="padding-top: 0px; padding-bottom: 0px;">
        <table border="0" cellpadding="20" cellspacing="0" width="100%">
          <tbody>
            <tr>
              <td width="396" style="padding-top: 0px;" class="left-column">
                <?php
                  $elements_no = sizeof($items);
                  foreach ($items as $idx => $item) {
                    if ($item['#entity_type'] == 'taxonomy_term' && ($idx+1 < $elements_no)) {
                      if ($items[$idx+1]['#entity_type'] == 'taxonomy_term') {
                        continue;
                      } else {
                        print(render($item));
                      }
                    } else {
                      print(render($item));
                    }
                  }
                ?>
              </td>

              <td width="308" style="vertical-align: top; padding-top: 0px; padding-right: 0px;" class="right-column">

                <?php
                  if (!empty($blogs) && sizeof($blogs) > 1) {
                    foreach ($blogs as $item) {
                      print(render($item));
                    }?>
                    <table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding-bottom: 15px;" class="pink-arrow">
                      <tbody>
                      <tr>
                        <td style="font-family: Oswald, Arial, sans-serif; font-size: 18px; color: #003399; text-align: right;">
                        <span>
                          <?php print l(t('View the blog'), 'https://osha.europa.eu/en/about/director_corner/blog', array('attributes' => array('style' => 'color: #144989; text-decoration: none;'), 'external' => TRUE)); ?>
                          <?php
                          $directory = drupal_get_path('module','osha_newsletter');
                          $site_url = variable_get('site_base_url', 'http://osha.localhost');
                          print l(theme('image', array(
                            'path' => $directory . '/images/pink-arrow.png',
                            'width' => 19,
                            'height' => 11,
                            'alt' => 'link arrow',
                            'attributes' => array('style' => 'border: 0px;')
                          )), $site_url, array(
                            'html' => TRUE,
                            'external' => TRUE
                          ));
                          ?>
                        </span>
                        </td>
                      </tr>
                      </tbody>
                    </table>
                  <?php
                  }
                ?>


                <?php
                  if (!empty($news) && sizeof($news) > 1) {
                    foreach ($news as $item) {
                      print(render($item));
                    }?>
                    <table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding-bottom: 15px;" class="pink-arrow">
                      <tbody>
                      <tr>
                        <td style="font-family: Oswald, Arial, sans-serif; font-size: 18px; color: #003399; text-align: right;">
                        <span>
                          <?php print l(t('More news'), 'https://osha.europa.eu/en/news', array('attributes' => array('style' => 'color: #144989; text-decoration: none;'), 'external' => TRUE)); ?>
                          <?php
                          $directory = drupal_get_path('module','osha_newsletter');
                          $site_url = variable_get('site_base_url', 'http://osha.localhost');
                          print l(theme('image', array(
                            'path' => $directory . '/images/pink-arrow.png',
                            'width' => 19,
                            'height' => 11,
                            'alt' => 'link arrow',
                          )), $site_url, array(
                            'html' => TRUE,
                            'external' => TRUE
                          ));
                          ?>
                        </span>
                        </td>
                      </tr>
                      </tbody>
                    </table>
                  <?php
                  }
                ?>


                <?php
                  if (!empty($events) && sizeof($events) > 1) {
                    foreach ($events as $item) {
                      print(render($item));
                    }?>
                    <table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding-bottom: 15px;" class="pink-arrow">
                      <tbody>
                      <tr>
                        <td style="font-family: Oswald, Arial, sans-serif; font-size: 18px; color: #003399; text-align: right;">
                        <span>
                          <?php print l(t('More events'), 'https://osha.europa.eu/en/news', array('attributes' => array('style' => 'color: #144989; text-decoration: none;'), 'external' => TRUE)); ?>
                          <?php
                          $directory = drupal_get_path('module','osha_newsletter');
                          $site_url = variable_get('site_base_url', 'http://osha.localhost');
                          print l(theme('image', array(
                            'path' => $directory . '/images/pink-arrow.png',
                            'width' => 19,
                            'height' => 11,
                            'alt' => 'link arrow',
                          )), $site_url, array(
                            'html' => TRUE,
                            'external' => TRUE
                          ));
                          ?>
                        </span>
                        </td>
                      </tr>
                      </tbody>
                    </table>
                  <?php
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