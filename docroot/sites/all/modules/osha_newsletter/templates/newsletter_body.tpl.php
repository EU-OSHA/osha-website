<?php
  $categories = array();
  $blogs = array();
  $highlights = array();
  $news = array();

  foreach($items as $item) {
    // do something ...
  }
?>
<table>
  <tbody>
  <tr>
    <td width="590" valign="top">
      <?php
      foreach ($items as $item) {
        print(render($item));
      }
      ?>
    </td>
    <td width="200" valign="top"  style="padding-left: 24px; padding-top: 36px;">
      <div style="font: 12px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif;">
        <h2 style="color: #191919; font-size: 18px; font-weight: normal; margin: 12px 0 13px; padding: 0;">
          <?php print t('Blog'); ?>
        </h2>
      </div>
      <div style="background-color: #f2f4f6; font: 12px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif; margin-bottom: 20px;">
        <h2 style="color: #191919; font-size: 11px; font-weight: normal; margin-bottom: 13px; padding: 6px 15px; text-align: right;">
          <?php print l(t('View the blog'), 'https://osha.europa.eu/en/about/director_corner/blog', array('attributes' => array('style' => 'color: #144989; text-decoration: none;'), 'external' => TRUE)); ?> &raquo;
        </h2>
      </div>
      <div style="font: 12px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif;">
        <h2 style="color: #191919; font-size: 18px; font-weight: normal; margin: 12px 0 13px; padding: 0;">
          <?php print t('News'); ?>
        </h2>
      </div>
      <div style="background-color: #f2f4f6; font: 12px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif; margin-bottom: 20px;">
        <h2 style="color: #191919; font-size: 11px; font-weight: normal; margin-bottom: 13px; padding: 6px 15px; text-align: right;">
          <?php print l(t('More news'), 'https://osha.europa.eu/en/news', array('attributes' => array('style' => 'color: #144989; text-decoration: none;'), 'external' => TRUE)); ?> &raquo;
        </h2>
      </div>
      <div style="font: 12px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif;">
        <h2 style="color: #191919; font-size: 18px; font-weight: normal; margin: 12px 0 13px; padding: 0;">
          <?php print t('Events'); ?>
        </h2>
      </div>
      <div style="background-color: #dce8f4; font: 12px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif; margin-bottom: 20px;">
        <h2 style="color: #191919; font-size: 11px; font-weight: normal; margin-bottom: 13px; padding: 6px 15px; text-align: right;">
          <?php print l(t('More events'), 'https://osha.europa.eu/en/news', array('attributes' => array('style' => 'color: #144989; text-decoration: none;'), 'external' => TRUE)); ?> &raquo;
        </h2>
      </div>
    </td>
  </tr>
  </tbody>
</table>
