<?php

/**
 * @file
 * Default theme implementation to display a printer-friendly version page.
 *
 * This file is akin to Drupal's page.tpl.php template. The contents being
 * displayed are all included in the $content variable, while the rest of the
 * template focuses on positioning and theming the other page elements.
 *
 * All the variables available in the page.tpl.php template should also be
 * available in this template. In addition to those, the following variables
 * defined by the print module(s) are available:
 *
 * Arguments to the theme call:
 * - $node: The node object. For node content, this is a normal node object.
 *   For system-generated pages, this contains usually only the title, path
 *   and content elements.
 * - $format: The output format being used ('html' for the Web version, 'mail'
 *   for the send by email, 'pdf' for the PDF version, etc.).
 * - $expand_css: TRUE if the CSS used in the file should be provided as text
 *   instead of a list of @include directives.
 * - $message: The message included in the send by email version with the
 *   text provided by the sender of the email.
 *
 * Variables created in the preprocess stage:
 * - $print_logo: the image tag with the configured logo image.
 * - $content: the rendered HTML of the node content.
 * - $scripts: the HTML used to include the JavaScript files in the page head.
 * - $footer_scripts: the HTML  to include the JavaScript files in the page
 *   footer.
 * - $sourceurl_enabled: TRUE if the source URL infromation should be
 *   displayed.
 * - $url: absolute URL of the original source page.
 * - $source_url: absolute URL of the original source page, either as an alias
 *   or as a system path, as configured by the user.
 * - $cid: comment ID of the node being displayed.
 * - $print_title: the title of the page.
 * - $head: HTML contents of the head tag, provided by drupal_get_html_head().
 * - $robots_meta: meta tag with the configured robots directives.
 * - $css: the syle tags contaning the list of include directives or the full
 *   text of the files for inline CSS use.
 * - $sendtoprinter: depending on configuration, this is the script tag
 *   including the JavaScript to send the page to the printer and to close the
 *   window afterwards.
 *
 * print[--format][--node--content-type[--nodeid]].tpl.php
 *
 * The following suggestions can be used:
 * 1. print--format--node--content-type--nodeid.tpl.php
 * 2. print--format--node--content-type.tpl.php
 * 3. print--format.tpl.php
 * 4. print--node--content-type--nodeid.tpl.php
 * 5. print--node--content-type.tpl.php
 * 6. print.tpl.php
 *
 * Where format is the ouput format being used, content-type is the node's
 * content type and nodeid is the node's identifier (nid).
 *
 * @see print_preprocess_print()
 * @see theme_print_published
 * @see theme_print_breadcrumb
 * @see theme_print_footer
 * @see theme_print_sourceurl
 * @see theme_print_url_list
 * @see page.tpl.php
 * @ingroup print
 */
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>">
  <head>
    <?php print $head; ?>
    <base href='<?php print $url ?>' />
    <!--title><?php print $print_title; ?></title-->
    <?php print $scripts; ?>
    <?php if (isset($sendtoprinter)) print $sendtoprinter; ?>
    <?php print $robots_meta; ?>
    <?php if (theme_get_setting('toggle_favicon')): ?>
      <link rel='shortcut icon' href='<?php print theme_get_setting('favicon') ?>' type='image/x-icon' />
    <?php endif; ?>
    <?php print $css; ?>
  </head>
  <body>
    <table border="0" cellpadding="0" cellspacing="0">
      <tbody>
      <tr class="blue-line">
        <td style="background-color:#003399; width: 100%; height: 4px;"></td>
      </tr>
      </tbody>
    </table>

    <table border="0" cellpadding="18" cellspacing="0" style="font-family: Oswald, Arial,sans-serif;">
      <tbody>
      <tr>
        <td>
          <?php
          $directory = drupal_get_path('module','osha_newsletter');
          global $base_url;
          global $language;
          print l(theme('image', array(
            'path' => $directory . '/images/Osha-EU-logos.png',
            'width' => 256,
            'height' => 60,
            'alt' => 'Osha logo',
            'attributes' => array('style' => 'border: 0px;')
          )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE
          ));
          ?>
        </td>
        <td>&nbsp;</td>
      </tr>
      </tbody>
    </table>

    <table border="0" cellpadding="0" cellspacing="0">
      <tbody>
      <tr class="blue-line">
        <td style="background-color:#003399; width: 100%; height: 4px;"></td>
      </tr>
      </tbody>
    </table>

    <?php if (!empty($message)): ?>
      <div class="print-message"><?php print $message; ?></div><p />
    <?php endif; ?>
    <?php if ($print_logo): ?>
      <div class="print-logo"><?php print $print_logo; ?></div>
    <?php endif; ?>
    <div class="print-site_name"><?php print theme('print_published'); ?></div>

    <div class="print-breadcrumb"><?php print theme('print_breadcrumb', array('node' => $node)); ?></div>
    <hr class="print-hr" />
    <?php if (!isset($node->type)): ?>
      <h2 class="print-title"><?php print $print_title; ?></h2>
    <?php endif; ?>
    <div class="print-content"><?php print $content;?></div>
    <!--div class="print-footer"><?php print theme('print_footer'); ?></div-->
    <hr class="print-hr" />
    <?php if ($sourceurl_enabled): ?>
      <div class="print-source_url">
        <?php print theme('print_sourceurl', array('url' => $source_url, 'node' => $node, 'cid' => $cid)); ?>
      </div>
    <?php endif; ?>
    <div class="print-links"><?php print theme('print_url_list'); ?></div>
    <?php print $footer_scripts; ?>

    <table border="0" cellpadding="0" cellspacing="0">
      <tbody>
      <tr class="blue-line">
        <td style="background-color:#003399; width: 100%; height: 4px;"></td>
      </tr>
      </tbody>
    </table>

    <table border="0" cellpadding="10" cellspacing="0">
      <tbody>
      <tr>
        <td style="padding-top: 10px; padding-bottom: 10px; text-align: center; font-family: Arial,sans-serif; font-size: 8px; color: #333333;">
          <span><?php print t('Occupational Safety and Health News &ndash; Europe'); ?></span>
          <?php print t('Brought to you by EU-OSHA. Visit us at: <a href="@url" style="@style">http://osha.europa.eu</a>',
            array('@style' => 'color: #003399; border-bottom-color: #DC2F82; border-bottom-style: solid; border-bottom-width: 1px; text-decoration: none;', '@url' => 'https://osha.europa.eu/en')); ?>
        </td>
      </tr>
      </tbody>
    </table>

    <table border="0" cellpadding="0" cellspacing="0">
      <tbody>
      <tr>
        <td style="background-color: #B2B3B5;">
          <table border="0" cellpadding="10" cellspacing="0">
            <tbody>
            <tr>
              <td style="padding-top: 10px; padding-bottom: 10px; color: #FFFFFF; font-family: Arial, sans-serif; font-size: 8px; "><?php print t('Subscribe to our <a href="@url" style="@style">Alert service</a> for <br/> customised content delivery',
                  array('@style' => 'color: #FFFFFF;', '@url' => url('https://osha.europa.eu/en/alertservice'))); ?>
              </td>
              <td class="social" style="padding-top: 10px; padding-bottom: 10px; float: right;">
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
                  'facebook' => array(
                    'path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
                    'alt' => t('Facebook')
                  ),
                  'blog' => array(
                    'path' => url('tools-and-publications/blog', array('alias' => TRUE)),
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
                    'height' => 20,
                    'alt' => $options['alt'],
                    'attributes' => array('style' => 'border: 0px; padding-right: 24px; vertical-align: middle;')
                  )), $options['path'], array(
                    'attributes' => array('style' => 'color: #144989; text-decoration: none;'),
                    'html' => TRUE,
                    'external' => TRUE
                  ));
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

  </body>
</html>
