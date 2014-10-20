<table border="0" cellpadding="10" cellspacing="0" class="category-name" width="100%">
  <tbody>
    <tr>
      <td style="font-family: Oswald, Arial, sans-serif; font-weight: normal; font-size: 20px; padding-left: 0px; padding-right: 0px;">
        <?php
          $label = "";
          if (isset($name_field[$language])) {
            $label = $name_field[$language][0]['safe_value'];
            print($label);
            } else {
              $label = $name_field[0]['safe_value'];
              print($label);
          }
        ?>
        <?php
          if ($label == 'Blog') {
            $directory = drupal_get_path('module','osha_newsletter');
            $site_url = variable_get('site_base_url', 'http://osha.localhost');
            print(theme('image', array(
              'path' => $directory . '/images/blog-callout.png',
              'width' => 36,
              'height' => 30,
              'alt' => 'callout',
              'attributes' => array('style' => 'border: 0px;')
            )));
          }
        ?>
      </td>
    </tr>
    <tr>
      <td style="border-style: dotted; border-top-width: 2px; border-bottom-width: 0px; border-left-width: 0px; border-right-width: 0px; border-color: #CFDDEE; padding-top: 0px; padding-bottom: 0px; height: 0px;" class="dotted-line no-padding"></td>
    </tr>
    <tr>
      <td style="padding-top: 0px; padding-bottom: 10px;" class="space-beyond-dotted-line"></td>
    </tr>
  </tbody>
</table>