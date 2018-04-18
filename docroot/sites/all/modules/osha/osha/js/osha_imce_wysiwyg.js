
/**
 * Wysiwyg API integration helper function.
 */
function imceImageBrowserImage(field_name, url, type, win) {
  // TinyMCE.
  if (win !== 'undefined') {
    win.open(Drupal.settings.osha_imce.images_url + encodeURIComponent(field_name)+'&url='+encodeURIComponent(url), '', 'width=850,height=560,resizable=1');
  }
}

/**
 * Wysiwyg API integration helper function.
 */
function imceImageBrowserFile(field_name, url, type, win) {
    // TinyMCE.
    if (win !== 'undefined') {
        win.open(Drupal.settings.osha_imce.files_url + encodeURIComponent(field_name)+'&url='+encodeURIComponent(url), '', 'width=850,height=560,resizable=1');
    }
}
