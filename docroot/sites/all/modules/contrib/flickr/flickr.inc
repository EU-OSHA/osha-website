<?php
/**
 * @file
 * The Flickr API functions.
 */

define('FLICKR_REST_ENDPOINT', 'https://api.flickr.com/services/rest/');
// Load flickr.api.inc from the flickr module.
module_load_include('inc', 'flickr', 'flickr.api');

/**
 * A list of possible photo sizes with description and label.
 *
 * @return array
 *   An array of photo sizes.
 */
function flickr_photo_sizes() {
  return array(
    's' => array(
      'label' => 'Square',
      'description' => t('s: 75 px square'),
    ),
    't' => array(
      'label' => 'Thumbnail',
      'description' => t('t: 100px on longest side'),
    ),
    'q' => array(
      'label' => 'Large Square',
      'description' => t('q: 150px square'),
    ),
    'm' => array(
      'label' => 'Small',
      'description' => t('m: 240px on longest side'),
    ),
    'n' => array(
      'label' => 'Small 320',
      'description' => t('n: 320px on longest side'),
    ),
    '-' => array(
      'label' => 'Medium',
      'description' => t('-: 500px on longest side'),
    ),
    'z' => array(
      'label' => 'Medium 640',
      'description' => t('z: 640px on longest side'),
    ),
    'c' => array(
      'label' => 'Medium 800',
      'description' => t('c: 800px on longest side'),
    ),
    'b' => array(
      'label' => 'Large',
      'description' => t('b: 1024px on longest side'),
    ),
    'h' => array(
      'label' => 'Large 1600',
      'description' => t('h: 1600px on longest side'),
    ),
    'k' => array(
      'label' => 'Large 2048',
      'description' => t('k: 2048px on longest side'),
    ),
    'o' => array(
      'label' => 'Original',
      'description' => t('o: Original image'),
    ),
    'x' => array(
      'label' => 'slideshow',
      'description' => t('x: Full featured responsive slideshow (for group, set and user IDs only)'),
    ),
    'y' => array(
      'label' => 'Simple slideshow',
      'description' => t('y: Basic responsive slideshow (for set and user IDs only)'),
    ),
  );
};

/**
 * Submit a request to Flickr.
 *
 * @param string $method
 *   String method name.
 * @param string $args
 *   Associative array of arguments names and values.
 * @param string $cacheable
 *   Boolean indicating if it's safe cache the results of this request.
 * @param string $return_errors
 *   Boolean indicating if the caller will handle displaying error messages.
 *
 * @return array
 *   an array with the the result of the request, or FALSE on error.
 */
function flickr_request($method, $args, $cacheable = TRUE, $return_errors = FALSE) {
  // Add in additional parameters then sort them for signing.
  $args['api_key'] = trim(variable_get('flickr_api_key', ''));
  $args['method'] = $method;
  $args['format'] = 'json';
  $args['nojsoncallback'] = 1;
  ksort($args);

  // Build an argument hash API signing (we'll also use it for the cache id).
  $arg_hash = '';
  foreach ($args as $k => $v) {
    $arg_hash .= $k . $v;
  }
  // If we've got a secret, sign the arguments.
  if ($secret = trim(variable_get('flickr_api_secret', ''))) {
    $args['api_sig'] = md5($secret . $arg_hash);
  }

  // Build the URL.
  foreach ($args as $k => $v) {
    $encoded_params[] = urlencode($k) . '=' . urlencode($v);
  }
  $url = FLICKR_REST_ENDPOINT . '?' . implode('&', $encoded_params);

  // If it's a cachable request, try to load a cached value.
  if ($cacheable) {
    if ($cache = cache_get("flickr_$arg_hash", 'cache')) {
      // Check that the value is still "fresh".
      if ($cache->expire > time()) {
        return json_decode($cache->data, TRUE);
      }
    }
  }
  // If a cached value wasn't suitable, attempt to connect and fetch a result.
  $cmethod = 'none';
  $result = new stdClass();
  $result->code = 0;
  if ((variable_get('flickr_curl2', 0) || !function_exists('stream_socket_client')) && function_exists('curl_version')) {
    $result = flickr_curl_http_request($url);
    $cmethod = 'cURL';
  }
  elseif (function_exists('stream_socket_client')) {
    $result = drupal_http_request($url);
    $cmethod = 'stream_socket_client';
  }
  if ($result->code != 200 && ($cmethod == 'stream_socket_client' || $cmethod == 'none') && function_exists('curl_version')) {
    // Try to use cURL when drupal_http_request returns a different code than
    // 200 (valid request, no errors). Most likely are 403 (forbidden) or 408
    // (Request Timeout).
    $result = flickr_curl_http_request($url);
    $cmethod = 'cURL';
    $message = t('Automatic fallback to the cURL connection method kicked in to handle the request. Result code from the failing request') . ': ' . $result->code;
    drupal_set_message($message, 'warning', FALSE);
    watchdog('flickr', $message, array(), WATCHDOG_WARNING);
    if ($return_errors && $result->code != 200) {
      // Debug info.
      if (variable_get('flickr_debug', 0) == 2 && function_exists('dpm')) {
        dpm("Value of error 'result' in 'function flickr_request()' with connection method " . "'" . $cmethod . "' in 'flickr.inc':");
        dpm($result);
      }
      return array(
        'stat' => 'error',
        // In Drupal <= 5.1, only HTTP errors are stored in $result->code
        // correctly, not TCP/IP errors. We can not count on this variable being
        // correct until this module requires Drupal 5.2 or above.
        'code' => $result->code,
        'message' => $result->error,
      );
    }
    // Even the cURL method returns an error.
    if ($result->code != 200) {
      // Debug info.
      if (variable_get('flickr_debug', 0) == 2 && function_exists('dpm')) {
        dpm("Value of 'result' with error in 'function flickr_request()' with connection method " . "'" . $cmethod . "' in 'flickr.inc':");
        dpm($result);
      }
      flickr_set_error(t("Could not connect to Flickr, Error: @error", array('@error' => $result->error)));
      return FALSE;
    }
  }
  if ($result->code == 0) {
    $message = t("There seems to be no connection method available on your server. Neither 'stream_socket_client' nor 'cURL'.");
    drupal_set_message($message, 'error', FALSE);
    watchdog('flickr', $message, array(), WATCHDOG_ERROR);

  }
  // Debug info.
  if (variable_get('flickr_debug', 0) == 2 && function_exists('dpm')) {
    dpm("Value of 'result' in 'function flickr_request()' with the " . "'" . $cmethod . "' connection method in 'flickr.inc':");
    dpm($result);
  }
  // Make sure it decodes.
  $response = json_decode($result->data, TRUE);
  if (!$response) {
    if ($return_errors) {
      return array(
        'stat' => t('error'),
        'code' => '-1',
        'message' => t('The response was corrupted. It could not be decoded.'),
      );
    }
    flickr_set_error(t("Flickr's response was corrupted and could not be decoded."));
    return FALSE;
  }

  // Check that the request was successful.
  if (flickr_response_has_error($response)) {
    if ($return_errors) {
      return $response;
    }
    flickr_set_error($response);
    return FALSE;
  }
  elseif (isset($args) && variable_get('flickr_debug', 0)) {
    $args['format'] = 'rest';
    unset($args['api_sig']);
    $attribs = urldecode(http_build_query($args, '', '&'));
    $attribs = str_replace('"', '', $attribs);
    $methodurl = l($method, 'https://www.flickr.com/services/api/' . $method . '.htm', array(
      'attributes' => array(
        'title' => t('Flickr Services: Flickr API') . ': ' . $method,
        'target' => '_blank',
      ),
    ));
    $explorerurl = l(t('API Explorer'), 'https://www.flickr.com/services/api/explore/' . $method, array(
      'attributes' => array(
        'title' => t('Flickr Api Explorer') . ' - ' . $method,
        'target' => '_blank',
      ),
    ));
    $requrl = l(t('following response'), FLICKR_REST_ENDPOINT . '?' . $attribs, array(
      'attributes' => array(
        'title' => t('Verify the passed arguments in the URL'),
        'target' => '_blank',
      ),
    ));
    $message = t("Debug info: Connection by %cmethod with method !methodurl gives the !requrl to check in the !explorerurl.", array(
      '%cmethod' => $cmethod,
      '!methodurl' => $methodurl,
      '!explorerurl' => $explorerurl,
      '!requrl' => $requrl,
    )) . '<br />' . t("Passed arguments: %attribs", array(
      '%attribs' => $attribs,
    ));
    drupal_set_message($message, 'warning');
    watchdog('flickr', $message, array(), WATCHDOG_WARNING);
  }

  // Save cacheable results for future use.
  if ($cacheable) {
    cache_set("flickr_$arg_hash", $result->data, 'cache', time() + variable_get('flickr_cache_duration', 3600));
  }

  return $response;
}

/**
 * This function will try to create an html image tag referencing the Flickr
 * photo with the desired size if that size is available for this photo.
 *
 * @param string $photo
 *   The photo variable.
 * @param string $size
 *   The desired image size.
 * @param string $attributes
 *   An optional array of HTML attributes to pass to the image.
 *
 * @return array
 *   a html image tag referencing the image of the desired
 *   size if it is available.
 */
function flickr_img($photo, $size = NULL, $attributes = NULL) {
  // Debug info.
  if (variable_get('flickr_debug', 0) == 2 && function_exists('dpm')) {
    dpm("Value of 'photo' passed to 'function flickr_img()' in 'flickr.inc':");
    dpm($photo);
  }
  $sizes = flickr_photo_sizes();
  if (!isset($size)) {
    $size = '-';
  }
  if (!isset($sizes[$size])) {
    return;
  }
  if (!isset($attributes) || !is_array($attributes)) {
    $attributes = array();
  }
  if (empty($attributes['class'])) {
    $attributes['class'] = NULL;
  }

  // Photoset's use primary instead of id to specify the image.
  if (isset($photo['primary'])) {
    $id = $photo['primary'];
    $attributes['class'] = explode(' ', trim($attributes['class'] . ' flickr-photoset-img'));
  }
  else {
    $id = $photo['id'];
    $attributes['class'] = explode(' ', trim($attributes['class'] . ' flickr-photo-img'));
  }

  $image_sizes = flickr_photos_getsizes($id);
  if ($image_sizes) {
    foreach ($image_sizes as $image_size) {
      if ($image_size['label'] == $sizes[$size]['label']) {
        break;
      }
    }
    if (isset($image_size)) {
      $img_url = $image_size['source'];
      // Fallback if no valid image is returned (might happen on some videos).
      if (!stripos($img_url, 'jpg')) {
        $img_url = flickr_photo_img($photo, $size);
      }
    }
  }
  else {
    $img_url = flickr_photo_img($photo, $size);
  }
  $info = !is_array($photo['title']) ? flickr_photos_getinfo($photo['id']) : '';
  if (isset($info['dates']) || isset($photo['dates'])) {
    $date_taken = is_array($info) && isset($info['dates']['taken']) ? $info['dates']['taken'] : $photo['dates']['taken'];
    $format_title = variable_get('flickr_date_format_image_title', 'medium');
    switch ($format_title) {
      case 'interval':
        $taken_short = format_interval(time() - strtotime($date_taken), 1) . ' ' . t('ago');
        break;

      case 'none':
        $taken_short = '';
        break;

      default:
        $taken_short = format_date(strtotime($date_taken), $format_title, '', NULL);
    }
  }
  $taken_short = empty($taken_short) ? '' : $taken_short . ' - ';
  $title = is_array($photo['title']) ? str_replace('"', "'", htmlspecialchars_decode(strip_tags($photo['description']['_content']))) : str_replace('"', "'", htmlspecialchars_decode(strip_tags($info['description']['_content'])));
  if (empty($title)) {
    $title = is_array($photo['title']) ? str_replace('"', "'", htmlspecialchars_decode(strip_tags($photo['title']['_content']))) : $photo['title'];
  }
  $title = $taken_short . $title;
  $overlay = variable_get('flickr_info_overlay', array(
    'title' => 'title',
    'metadata' => 'metadata',
    'description' => 'description',
    'license' => 0,
  ));
  $title = (gettype($overlay['description']) == 'integer') ? $photo['title'] : $title;
  if (module_exists('jcaption') && (variable_get('flickr_class') != NULL || variable_get('flickr_rel') != NULL)) {
    $title = '';
  }
  return theme('image', array(
    'path' => $img_url,
    'alt' => $title,
    'title' => $title,
    'attributes' => $attributes,
    'getsize' => FALSE,
  ));
}

/**
 * Returns the URL to $photo with size $size using the correct image farm
 * from the $photo variable.
 *
 * @param string $photo
 *   Photo to which the url should point.
 * @param string $size
 *   Size of the photo.
 * @param string $format
 *   Format of the photo.
 *
 * @return array
 *   URL for $photo with the correct size and format.
 */
function flickr_photo_img($photo, $size = NULL, $format = NULL) {
  // Early images don't have a farm setting so default to 1.
  $farm = isset($photo['farm']) ? $photo['farm'] : 1;
  $server = $photo['server'];
  // photoset's use primary instead of id to specify the image.
  $id = isset($photo['primary']) ? $photo['primary'] : $photo['id'];
  $secret = $photo['secret'];
  $suffix = $size ? "_$size." : '.';
  $suffix = $size == '-' ? '.' : $suffix;
  $extension = $size == 'o' ? $format : 'jpg';

  return "https://farm{$farm}.static.flickr.com/{$server}/{$id}_{$secret}" . $suffix . $extension;
}

/**
 * Returns the URL for the Flick photo page.
 *
 * @param string $owner
 *   Owner of the photo.
 * @param string $id
 *   ID of the photo to reference in the URL.
 *
 * @return array
 *   URL for the flickr photo page showing photo with $id of $owner.
 */
function flickr_photo_page_url($owner, $id = NULL) {
  $nsid = is_array($owner) ? $owner['nsid'] : $owner;
  if ($person = flickr_people_getinfo($nsid)) {
    return $person['photosurl']['_content'] . $id;
  }
  else {
    return "https://flickr.com/photos/$nsid/$id";
  }
}

/**
 * Returns the URL of a given photoset page.
 *
 * @param string $owner
 *   Owner of the photoset.
 * @param string $id
 *   ID of the photoset to which the url must lead.
 *
 * @return array
 *   URL for the photoset page of photoset $id of owner $owner.
 */
function flickr_photoset_page_url($owner, $id = NULL) {
  $nsid = is_array($owner) ? $owner['nsid'] : $owner;
  if ($person = flickr_people_getinfo($nsid)) {
    return $person['photosurl']['_content'] . 'sets/' . $id;
  }
  else {
    return "https://flickr.com/photos/$nsid/sets/$id";
  }
}

/**
 * Tries to match an 'identifier' onto a flickr nsid.
 *
 * This function will first see whether $identifier is already
 * a nsid (format check only, no api call).  If it is not and the
 * identifier has the format of an email, an api call will be made to
 * check whether there is an nsid for that email.  If this is not the
 * case, the $identifier is treated as a username and an api call is
 * made to find the nsid for that username.
 *
 * If none of these succeed, the result will be false
 *
 * @param string $identifier
 *   Identifier to find an NSID for.
 *
 * @return array
 *   Valid NSID or false if none can be found.
 */
function flickr_user_find_by_identifier($identifier) {
  if (flickr_is_nsid($identifier)) {
    // Identifier is an NSID.
    return $identifier;
  }
  if (valid_email_address($identifier) && ($user = flickr_people_findbyemail($identifier))) {
    return $user['nsid'];
  }
  if ($user = flickr_urls_lookupuser($identifier)) {
    return $user['id'];
  }
  if ($user = flickr_people_findbyusername($identifier)) {
    return $user['nsid'];
  }
  return FALSE;
}

/**
 * Flickr is NSID.
 */
function flickr_is_nsid($id) {
  return preg_match('/^\d+@N\d+$/', $id);
}

/**
 * Check if the response from the Flickr api call was an error.
 *
 * @param string $response
 *   Response to check.
 *
 * @return array
 *   True if the response is an error message.
 */
function flickr_response_has_error($response) {
  return !(isset($response['stat']) && $response['stat'] == 'ok');
}

/**
 * Display an error message to flickr admins and write an error to watchdog.
 *
 * @param string $message_or_response
 *   Message or error response to display.
 */
function flickr_set_error($message_or_response) {
  if (is_array($message_or_response)) {
    $message = t('Flickr error @error_id: %flickr_error', array(
      '@error_id' => $message_or_response['code'],
      '%flickr_error' => $message_or_response['message'],
    ));
    if ($message_or_response['code'] == 100) {
      $message .= '. ' . t('No valid Flickr API key has been set at !link.', array('!link' => l('admin/config/media/flickr', 'admin/config/media/flickr')));
    }
  }
  else {
    $message = $message_or_response;
  }

  if (user_access('administer flickr')) {
    drupal_set_message($message, 'error', FALSE);
  }
  watchdog('flickr', $message, array(), WATCHDOG_WARNING);
}

/**
 * Returns Flickr detialed data based on nsid.
 * An elaboration of flickr_people_getinfo.
 *
 * @param string $nsid
 *   A valid Flickr numerical user ID. Should be validated before arriving here.
 *
 * @return array $people
 *   HTML with a Flickr user's name that links to their Flickr profile.
 *   Real name if it exists, if not the username.
 */
function flickr_get_user_info($nsid) {
  $info = flickr_people_getinfo($nsid);
  $people = array();
  $people['name'] = !empty($info['realname']['_content']) ? l($info['realname']['_content'], $info['profileurl']['_content'], array(
    'attributes' => array(
      'title' => t('View user on Flickr.'),
      'target' => '_blank',
    ),
  )) : l($info['username']['_content'], $info['profileurl']['_content'], array(
    'attributes' => array(
      'title' => t('View user on Flickr.'),
      'target' => '_blank',
    ),
  ));
  $username = strip_tags($people['name']);
  $people['photostream'] = l(t("!user on Flickr", array('!user' => $username)), $info['photosurl']['_content'], array(
    'attributes' => array(
      'title' => t('View Flickr photostream.'),
      'target' => '_blank',
    ),
    'html' => TRUE,
  ));

  $people['photosurl'] = $info['photosurl']['_content'];
  $people['profileurl'] = $info['profileurl']['_content'];
  $people['count'] = $info['photos']['count']['_content'];
  return $people;
}

/**
 * Returns the type of ID. User, group or photoset.
 * If is has no @ it is a set, if flickr_groups_getinfo returns 'ok', it is a
 * group. This is not a validation function.
 *
 * @param string $id
 *   A valid Flickr ID. Should be validated before arriving here.
 *
 * @return string
 *   'user', 'group' or 'photoset'
 */
function flickr_get_id_type($id) {
  // If it contains a '@' it is likely a group or user ID.
  if (strpos($id, '@') !== FALSE) {
    $info = flickr_groups_getinfo($id);
    if ($info['stat'] == 'ok') {
      // If the function works, it is a group ID.
      return 'group';
    }
    elseif (flickr_user_find_by_identifier($id)) {
      // If it doesn't, it is likely a user ID.
      return 'user';
    }
  }
  elseif (is_numeric($id)) {
    return 'photoset';
  }
  if (flickr_user_find_by_identifier($id)) {
    return 'user';
  }
  $message = t('A valid Flickr ID could not be found');
  drupal_set_message($message, 'error');
  watchdog('flickr', $message, array(), WATCHDOG_WARNING);
  return FALSE;
}

/**
 * Render multiple photos as an album.
 */
function flickr_album($type = 'user', $id = '39873962@N08', $show_n = NULL, $size = NULL, $media = 'photos', $tags = '', $tags_user = '', $delta = 'true', $sort = 'unsorted', $heading = 'p', $min_title = NULL, $min_metadata = NULL, $vocab_isset = 0, $filter = NULL, $lat = NULL, $lon = NULL, $radius = NULL, $datefrom = NULL, $dateto = NULL, $extend = 1, $tag_mode = 'context', $class = NULL, $style = NULL, $page = 1) {
  // If no API key is set, break.
  if (!variable_get('flickr_api_key', NULL)) {
    return FALSE;
  }
  // Also Flickr converts tags to lowercase, removes spaces and the ampersand.
  $tags = strtolower(str_replace(array(' ', '&'), '', $tags));
  // drupal_is_front_page() is added because it also can have arg(0) == 'node'.
  $cache = cache_get('flickr_block_' . $delta . '_' . $id . '_' . $tags . '_' . $lat . '_' . $datefrom . '_' . $dateto . '_' . arg(0) . '_' . drupal_is_front_page() . '_' . $page);
  // If $delta is a number it is a block that could be cached.
  if ($cache && is_numeric($delta)) {
    $output = $cache->data;
  }

  // In any other case we generate an album, including a heading and counter.
  else {
    // As variables might change during processing, we set a fixed version of it
    // to use for the key to set the block cache after processing at the end.
    $idfix = $id;
    $datefromfix = $datefrom;
    $datetofix = $dateto;
    $tagsfix = $tags;
    $latfix = $lat;
    $pagefix = $page;
    // Turn GPS coordinates from degrees / minutes / seconds to decimal format.
    if (isset($lat)) {
      $dmslat = preg_match_all('/[\-(\.|,)0-9]+/', $lat, $matches);
      $deg = isset($matches[0][0]) ? $matches[0][0] : $lat;
      $min = isset($matches[0][1]) ? $matches[0][1] : 0;
      $sec = isset($matches[0][2]) ? $matches[0][2] : 0;
      $lat = $deg + ((($min * 60) + ($sec)) / 3600);
      $dmslon = preg_match_all('/[\-(\.|,)0-9]+/', $lon, $matches);
      $deg = isset($matches[0][0]) ? $matches[0][0] : $lon;
      $min = isset($matches[0][1]) ? $matches[0][1] : 0;
      $sec = isset($matches[0][2]) ? $matches[0][2] : 0;
      $lon = $deg + ((($min * 60) + ($sec)) / 3600);
    }
    if (!isset($dateto)) {
      $dateto = $datefrom;
    }
    $datestart = strtotime($datefrom);
    $dateend = strtotime($dateto);
    // Try again but turning DD/MM/YYYY to DD-MM-YYYY.
    // See http://www.hashbangcode.com/node/702 (first part only).
    if (!empty($datefrom) && ($datestart === FALSE || $dateend === FALSE || $datestart > $dateend)) {
      $datestart = strtotime(str_replace('/', '-', $datefrom));
      $dateend = strtotime(str_replace('/', '-', $dateto));
      $ambiguous = l(t('ambiguous'), 'http://php.net/manual/en/function.strtotime.php#100144', array(
        'attributes' => array(
          'title' => t('PHP: strtotime - Manual'),
          'target' => '_blank',
        ),
      ));
      $dateformat = l(t('accepted date format'), 'http://php.net/manual/en/datetime.formats.date.php/', array(
        'attributes' => array(
          'title' => t('PHP: Date Formats - Manual'),
          'target' => '_blank',
        ),
      ));
      drupal_set_message(t("You used the date format DD/MM/YYYY (starting with the day). As some dates are !ambiguous (e.g. is 04/05/2013 5 April or 4 May?) it is recommended to use dashes when you start with the day (DD-MM-YYYY), slashes when you start with the month (MM/DD/YYYY) or use any other !dateformat (e.g. 11 Jan 2015).", array(
          '!ambiguous' => $ambiguous,
          '!dateformat' => $dateformat,
        )), 'warning', FALSE);
    }
    if (!empty($datefrom) && ($datestart === FALSE || $dateend === FALSE)) {
      drupal_set_message(t("Invalid date provided."), 'error', FALSE);
    }
    $datefrom = empty($datefrom) ? '' : date("Y-m-d", $datestart);
    $dateto = empty($dateto) ? '' : date("Y-m-d", $dateend);
    $datefrom = isset($datefrom) ? $datefrom . ' 00:00:00' : '';
    $dateto = isset($dateto) ? $dateto . ' 23:59:59' : '';
    // Remove tags to exclude (preceded by a minus symbol) for album titles.
    $tagsfixnoexclude = preg_replace('/,(^|\s)*-(\w+)/', '', $tags);
    // Set the default tag mode appropriate.
    if ($tag_mode == 'context') {
      $tag_mode = empty($id) || $id == 'public' || $id == '39873962@N08' ? 'all' : 'any';
    }
    if ($extend && $tag_mode == 'all' && strpos($tags, ',') !== FALSE) {
      $tag_mode = 'any';
      drupal_set_message(t("The tag mode has been forced to 'any' (OR) for extended text matching (tags, titles and description). To use 'all' (AND) put 'extend=false' in Flickr's text filter code."), 'warning', FALSE);
    }
    $sizes = flickr_photo_sizes();
    $show_n = is_null($show_n) ? variable_get('flickr_photos_per_page', 6) : $show_n;
    $size = is_null($size) ? variable_get('flickr_default_size_album', 's') : $size;
    $min_title = is_null($min_title) ? variable_get('flickr_title_suppress_on_small', '100') : $min_title;
    $min_metadata = is_null($min_metadata) ? variable_get('flickr_metadata_suppress_on_small', '150') : $min_metadata;
    if ($show_n > 1 || is_numeric($delta)) {
      $output = '<div class="flickr-photoset">';
    }
    else {
      $output = '<span class="flickr-photoset-single">';
    }
    // The text to prepend to an album title.
    switch ($sort) {
      case 'added':
        $order = t('Latest added');
        break;

      case 'date-taken-desc':
        $order = t('Latest taken');
        break;

      case 'date-posted-desc':
        $order = t('Latest uploaded');
        break;

      case 'views':
        $order = t('Most viewed');
        break;

      case 'random':
        $order = t('Random');
        break;

      case 'unsorted':
        $order = '';
        break;

      // In case 'id'.
      default:
        $order = t('Latest');
        break;
    }
    if ($type == 'user' || $type == 'group') {
      switch ($filter) {
        case 'interestingness-desc':
          if (empty($order)) {
            $order = t('Most interesting') . ' ';
          }
          else {
            $order .= t(', most interesting') . ' ';
          }
          break;

        case 'relevance':
          if (empty($order)) {
            $order = t('Most relevant') . ' ';
          }
          else {
            $order .= t(', most relevant') . ' ';
          }
          break;

        default:
          $order .= ' ';
          break;
      }
    }
    else {
      $order .= ' ';
    }
    // Merge the user profile terms with the terms from the node.
    $tags_user_string = is_array($tags_user) ? implode(",", $tags_user) : $tags_user;
    $tags_combined = trim($tags . ',' . $tags_user_string, ',');
    // Get information about the album, including the owner if needed later on.
    switch ($type) {
      case "photoset":
        $info = flickr_photosets_getinfo($id);
        $people = flickr_get_user_info($info['owner']);
        if (!$info) {
          return;
        }
        $total = ($media == 'videos') ? $info['count_videos'] : $info['count_photos'] + $info['count_videos'];
        break;

      case "group":
        $info = flickr_groups_getinfo($id);
        if (!$info) {
          return;
        }
        $id = $info['group']['id'];
        $total = $info['group']['pool_count']['_content'];
        break;

      case "gallery":
        $info = is_numeric($delta) ? flickr_galleries_getinfo($id) : flickr_galleries_getinfo('6065-' . $id);
        if ($info['stat'] == 'ok') {
          $gallery_id = $info['gallery']['id'];
          $people = flickr_get_user_info($info['gallery']['owner']);
        }
        else {
          return;
        }
        $total = ($media == 'videos') ? $info['gallery']['count_videos'] : $info['gallery']['count_photos'] + $info['gallery']['count_videos'];
        break;

      default:
        $id = (empty($id) || $id == 'public') ? '39873962@N08' : $id;
        $people = flickr_get_user_info($id);
        if (!$people) {
          return;
        }
        $total = $people['count'];
        break;
    }

    // Set some variables for all album types.
    if ($show_n > 1) {
      $media_type = $media == 'videos' ? t('videos') : t('photos');
    }
    else {
      $media_type = $media == 'videos' ? t('video') : t('photo');
    }
    $people['photosurl'] = isset($people['photosurl']) ? $people['photosurl'] : 'https://www.flickr.com/groups/' . $idfix . '/';
    $people['photosurl'] = $id == '39873962@N08' ? 'https://www.flickr.com/search/?sort=relevance&text=' : $people['photosurl'];
    $photos = $order . l(t('Flickr'), $people['photosurl'], array(
      'attributes' => array(
        'title' => t("View the @type's Flickr photostream.", array('@type' => $type)),
        'target' => '_blank',
      ),
    )) . ' ' . $media_type;
    // The used tags with a space forced after the comma and the last
    // one replaced by 'or' or 'and'.
    $conjunction = $tag_mode == 'all' ? t('and') : t('or');
    $tags1 = preg_replace('/(.*),/', '$1 ' . $conjunction, str_replace(',', ', ', $tagsfixnoexclude));
    $flickr = flickr_album_link_construct(' ' . t('tagged') . ' <span class="flickr-tags">' . $tags1 . '</span></span>', $type, $id, $show_n, $media, $tags, $filter, $lat, $lon, $radius, $datefrom, $dateto, $extend, $tag_mode);

    $tagged = (empty($tags) || $size == 'x' || $size == 'y') ? '' : '<span class="flickr-tags-wrap">' . $flickr;
    // A single date.
    $format = empty($datefrom) ? 'none' : variable_get('flickr_date_format_album_title', 'short');
    switch ($format) {
      case 'interval':
        $formated_datefrom = format_interval(time() - strtotime(substr($datefrom, 0, 10)), 1);
        $formated_dateto = format_interval(time() - strtotime(substr($dateto, 0, 10)), 1);
        break;

      default:
        $formated_datefrom = format_date(strtotime(substr($datefrom, 0, 10)), $format, '', NULL);
        $formated_dateto = format_date(strtotime(substr($dateto, 0, 10)), $format, '', NULL);
    }
    if ((empty($datetofix) || $datetofix == $datefromfix || $formated_datefrom == $formated_dateto) && !empty($datefromfix)) {
      // Remove the time by capturing anything preceding one or more digits
      // followed by a colon. See http://rubular.com/r/7IJhj19P9K
      $match1 = preg_match('/^(.*?)[-|\s].\d*:/', $formated_datefrom, $match);
      // Only use the match if there is one (date with time).
      $date1 = isset($match[1]) ? $match[1] : $formated_datefrom;
      $taken = ($format == 'interval') ? ' ' . t('taken') . ' ' . $formated_datefrom . ' ' . t('ago') : ' ' . t('taken on') . ' ' . $date1;
    }
    // Multiple days.
    elseif (!empty($datefromfix)) {
      // Remove the times.
      $match1 = preg_match('/^(.*?)[-|\s].\d*:/', $formated_datefrom, $matchfrom);
      if (isset($matchfrom[1])) {
        preg_match('/^(.*?)[-|\s].\d*:/', $formated_dateto, $matchto);
        $date1 = $matchfrom[1];
        $date2 = $matchto[1];
      }
      else {
        $date1 = $formated_datefrom;
        $date2 = $formated_dateto;
      }
      switch ($format) {
        case 'interval':
          $taken = ' ' . t('taken') . ' ' . $formated_datefrom . ' ' . t('to') . ' ' . $formated_dateto . ' ' . t('ago');
          break;

        default:
          $taken = ' ' . t('taken from') . ' ' . $date1 . ' ' . t('to') . ' ' . $date2;
      }
    }
    else {
      $taken = '';
      $datefrom = '';
      $dateto = '';
    }
    $taken = $format == 'none' ? '' : $taken;

    // Generate an album heading depending on type.
    switch ($type) {
      case "photoset":
        $set = l($info['title']['_content'], $people['photosurl'] . 'sets/' . $id, array(
          'attributes' => array(
            'title' => t('View set on Flickr.'),
            'target' => '_blank',
          ),
        ));
        $map = variable_get('flickr_maps', 0) ? '(' . l(t('map'), $people['photosurl'] . 'sets/' . $id . '/map/', array(
          'attributes' => array(
            'title' => t('View set on Flickr map.'),
            'target' => '_blank',
          ),
        )) . ')' : '';
        $flickr = l(t('on Flickr'), $people['photosurl'] . 'sets/' . $id, array(
          'attributes' => array(
            'title' => t("@set by @name.", array(
              '@set' => strip_tags($set),
              '@name' => strip_tags($people['name']),
            )),
            'target' => '_blank',
          ),
        ));
        $output .= ($heading == 'none' || ($show_n == 1 && !is_numeric($delta))) ? '' : '<' . $heading . ' class="flickr-album-heading">' . t("!photos !tagsfrom the album !set by !username !map", array(
          '!photos' => $photos,
          '!tags' => $tagged . ' ',
          '!set' => $set,
          '!username' => $people['name'],
          '!map' => $map,
        )) . '</' . $heading . '>';
        if ($heading == 'h1') {
          $title_bar = t("@photos @tagsfrom the album @set by @username", array(
            '@photos' => strip_tags($photos),
            '@tags' => strip_tags($tagged) . ' ',
            '@set' => strip_tags($set),
            '@username' => strip_tags($people['name']),
          ));
          drupal_set_title($title_bar);
        }
        break;

      case "gallery":
        $set = l($info['gallery']['title']['_content'], $people['photosurl'] . 'galleries/' . preg_replace('/^[^,]*-\s*/', '', $id), array(
          'attributes' => array(
            'title' => t('View gallery on Flickr.'),
            'target' => '_blank',
          ),
        ));
        $flickr = l(t('on Flickr'), $people['photosurl'] . 'galleries/' . preg_replace('/^[^,]*-\s*/', '', $id), array(
          'attributes' => array(
            'title' => t("@set curated by @name.", array(
              '@set' => strip_tags($set),
              '@name' => strip_tags($people['name']),
            )),
            'target' => '_blank',
          ),
        ));
        $tagged = is_numeric($delta) ? '' : $tagged;
        $output .= ($heading == 'none' || ($show_n == 1 && !is_numeric($delta))) ? '' : '<' . $heading . ' class="flickr-album-heading">' . t("!photos !tagsfrom the gallery !set curated by !username", array(
          '!photos' => strip_tags($photos),
          '!tags' => strip_tags($tagged . ' '),
          '!set' => $set,
          '!username' => $people['name'],
        )) . '</' . $heading . '>';
        break;

      case "favorites":
        $flickr = l(t('on Flickr'), $people['photosurl'] . 'favorites/', array(
          'attributes' => array(
            'title' => t("View favorites of @name made by others.", array(
              '@name' => strip_tags($people['name']),
            )),
            'target' => '_blank',
          ),
        ));
        $favorites = l(t('favorites'), $people['photosurl'] . 'favorites/', array(
          'attributes' => array(
            'title' => t("View favorites of @name made by others.", array(
              '@name' => strip_tags($people['name']),
            )),
            'target' => '_blank',
          ),
        ));
        $tags1 = (!empty($tags)) ? '<span class="flickr-tags-wrap">' . t('tagged') . ' <span class="flickr-tags">' . $tags1 . '</span> </span>' : '';
        $output .= ($heading == 'none' || ($show_n == 1 && !is_numeric($delta))) ? '' : '<' . $heading . ' class="flickr-album-heading">' . t("!photos !tags from the !favorites of !username", array(
          '!photos' => strip_tags($photos),
          '!tags' => $tags1,
          '!favorites' => $favorites,
          '!username' => $people['name'],
        )) . '</' . $heading . '>';
        break;

      // User and group albums.
      default:
        if (!empty($tags) && strpos($tags, ',') == FALSE) {
          $map = variable_get('flickr_maps', 0) ? '(' . l(t('map'), $people['photosurl'] . 'tags/' . $tags . '/map/', array(
            'attributes' => array(
              'title' => t('View tagged photos on Flickr map.'),
              'target' => '_blank',
            ),
          )) . ')' : '';
        }
        else {
          $map = variable_get('flickr_maps', 0) ? '(' . l(t('map'), $people['photosurl'] . 'map/', array(
            'attributes' => array(
              'title' => t('View user photos on Flickr map.'),
              'target' => '_blank',
            ),
          )) . ')' : '';
        }
        if ($type == 'user') {
          $username = ($id == '39873962@N08' || empty($id)) ? '' : ' ' . t('by') . ' ' . $people['name'];
        }
        else {
          $username = ' ' . t('from the group') . ' ' . strip_tags($info['group']['name']['_content']);
        }
        $flickr = flickr_album_link_construct(t('on Flickr'), $type, $id, $show_n, $media, $tags, $filter, $lat, $lon, $radius, $datefrom, $dateto, $extend, $tag_mode);
        $map = ($id == '39873962@N08' || empty($id)) ? '' : $map;
        if (isset($lat)) {
          $place_id = flickr_places_findbylatlon($lat, $lon);
          $place_name = $place_id['places']['place'][0]['name'];
          $geophp = variable_get('flickr_geophp', array(
            'title' => 'title',
            'caption' => 0,
          ));
          if (gettype($geophp['title']) != 'integer') {
            $google = 'https://maps.googleapis.com/maps/api/geocode/json?latlng=' . $lat . ',' . $lon;
            if ((variable_get('flickr_curl2', 0) || !function_exists('stream_socket_client')) && function_exists('curl_version')) {
              $result = flickr_curl_http_request($google);
            }
            elseif (function_exists('stream_socket_client')) {
              $result = drupal_http_request($google);
            }
            $json = json_decode($result->data);
            if ($json->status == 'ZERO_RESULTS') {
              $location_name = $place_name;
            }
            else {
              $location_name = $json->results[0]->formatted_address;
              // Remove the postal code from the string.
              // Usually the last component of the returned address by Google.
              $location_components = $json->results[0]->address_components;
              $location_pc = end($location_components);
              if (strpos($location_pc->types[0], 'postal_code') !== FALSE) {
                $location_name = str_replace($location_pc->long_name, '', $location_name);
              }
              else {
                $location_name = $place_name;
              }
            }
          }
          else {
            $location_name = $place_name;
          }
          if ($id == '39873962@N08' || empty($id)) {
            $place_name = !is_array($place_name) ? l($location_name, 'https://www.flickr.com/map?&location=' . $place_name, array(
              'attributes' => array(
                'title' => t('View photos on Flickr map.'),
                'target' => '_blank',
                'class' => array('flickr-location'),
              ),
            )) : $place_name;
          }
          else {
            if ($type == 'user') {
              $place_name = !is_array($place_name) ? l($location_name, 'https://www.flickr.com/photos/' . $id . '/map?&location=' . $place_name, array(
                'attributes' => array(
                  'title' => t('View photos on Flickr map.'),
                  'target' => '_blank',
                  'class' => array('flickr-location'),
                ),
              )) : $place_name;
            }
            else {
              $place_name = !is_array($place_name) ? l($location_name, 'https://www.flickr.com/groups/' . $id . '/map?&location=' . $place_name, array(
                'attributes' => array(
                  'title' => t('View photos on Flickr map.'),
                  'target' => '_blank',
                  'class' => array('flickr-location'),
                ),
              )) : $place_name;
            }
          }
          if (is_array($place_name)) {
            drupal_set_message(t("Temporarily the album location could not be retrieved from Flickr and is therefore omitted in the album title."), 'warning', FALSE);
          }
        }
        $place = isset($lat) && !is_array($place_name) ? t('near') . ' ' . $place_name . ' ' : '';
        $pre_output = ($id == '39873962@N08' || empty($id)) ? strip_tags($photos) . ' '  . $tagged . ' ' . $place . $username . ' ' . $map . $taken : $photos . ' '  . $tagged . ' ' . $place . $username . ' ' . $map . $taken;
        $block_config = l(t('exclude the block'), 'admin/structure/block/manage/flickr/' . $delta . '/configure/', array(
          'attributes' => array(
            'title' => t('Block visibility settings'),
          ),
        ));
        $config = l(t('set empty blocks to remain hidden'), 'admin/config/media/flickr/', array(
          'attributes' => array(
            'title' => t('Go to Flickr configuration page'),
          ),
        ));
        if (($id == '39873962@N08' || empty($id)) && empty($tags) && !isset($lat)) {
          $pre_output .= '<div class="messages warning">' . t('Provide some tags or a location for public photos for the node on this page<br />- OR -<br />!block_config on this page<br />- OR -<br />!config.', array('!block_config' => $block_config, '!config' => $config)) . '</div>';
          $show_n = 0;
        }
        $output .= ($heading == 'none' || ($show_n == 1 && !is_numeric($delta))) ? '' : '<' . $heading . ' class="flickr-album-heading">' . $pre_output . '</' . $heading . '>';
        break;
    }

    // Generate the album itself, depending on size and type.
    switch ($size) {
      case "x":
        switch ($type) {
          case "favorites":
          case "gallery":
            $output .= '<div class="messages error">' . t("You cannot choose a slideshow for '@type'. Select another size.", array('@type' => $type)) . '</div>';
            drupal_set_message(t("You cannot choose a slideshow for '@type'. Select another size.", array('@type' => $type)), 'error', FALSE);
            break;

          default:
            // Info about set and owner is displayed in slideshow itself. If you
            // don't want a header, don't use concatenation (.=) but equals (=).
            $output .= theme('flickr_flickrcomslideshow', array(
              'id' => $id,
              'class' => $class,
              'style' => $style,
            ));
            drupal_set_message(t("Note that slideshows show in reverse chronological order (newest first) and ignore number, filter, tags, location and media settings."), 'warning', FALSE);
            break;
        }
        break;

      case "y":
        switch ($type) {
          case "favorites":
          case "gallery":
            $output .= '<div class="messages error">' . t("You cannot choose a slideshow for '@type'. Select another size.", array('@type' => $type)) . '</div>';
            drupal_set_message(t("You cannot choose a slideshow for '@type'. Select another size.", array('@type' => $type)), 'error', FALSE);
            break;

          case "group":
            $output .= '<div class="messages error">' . t('Choose the slideshow for group pool albums (size = x).') . '</div>';
            drupal_set_message(t('Choose the slideshow for group pool albums (size = x).'), 'error', FALSE);
            break;

          default:
            $output .= theme('flickr_flickrcomslideshow_simple', array(
              'id' => $id,
              'class' => $class,
              'style' => $style,
            ));
            drupal_set_message(t("Note that slideshows show in reverse chronological order (newest first) and ignore number, filter, tags, location and media settings."), 'warning', FALSE);
            break;
        }
        break;

      default:
        $output .= '<div class="flickr-album ' . $class . '" style="' . $style . '">';
        // Make API request quicker by limiting the number of photos to return.
        // For recent sorted photos this is 4 x the displayed number to provide
        // a sufficient distinction between recently uploaded and recently
        // taken.
        $per_page = ($sort == 'random' || $sort == 'views') ? variable_get('flickr_per_page', 100) : 4 * $show_n;
        // ...but if unsorted or user/date, limit it more (except size 'n')...
        $per_page = (($sort == 'unsorted' || ($type == 'user' && ($sort == 'date-taken-desc' || $sort == 'date-posted-desc') && empty($filter))) && $size != 'n') ? $show_n : $per_page;
        // When we have a photoset, gallery or favorites, use the maximum...
        $per_page = ($type == 'favorites' || $type == 'photoset' || $type == 'gallery') && (!empty($tags) || ($sort == 'date-taken-desc' || $sort == 'date-posted-desc')) ? $total : $per_page;
        // ...but when filtering on muiltiple tags in groups, use the maximum.
        $per_page = (strpos($tags, ',') !== FALSE && $type == 'group') || ($id == '39873962@N08' && $sort == 'date-taken-desc' && empty($filter)) ? $total : $per_page;
        // Fallback: Avoid that $page can be empty or 0.
        $per_page = isset($page) && $per_page > 0 ? $per_page : variable_get('flickr_per_page', 100);
        // If we could have a response of over [variable_get('flickr_per_page',
        // 100)] photos, we want a random sort to take a random page first, so
        // any photos could be taken (not only from the most recent batch).
        // The amount in the last page has to be sufficient to draw a random.
        $rest_ok = ($total % variable_get('flickr_per_page', 100)) > 3 * $show_n ? 1 : 0;
        $page = ($sort == 'random' && isset($total) && $total > variable_get('flickr_per_page', 100) && empty($tags)) ? mt_rand(1, floor($total / variable_get('flickr_per_page', 100)) + $rest_ok) : $page;
        // Debug info.
        if (variable_get('flickr_debug', 0) == 2 && function_exists('dpm')) {
          dpm("Arguments passed to 'function flickr_album()': " . '$type=' . $type . ' $delta=' . $delta . ' $id=' . $id . ' $sort=' . $sort . ' $filter=' . $filter . ' $page=' . $page . ' $per_page=' . $per_page . ' $tags=' . $tags . ' $vocab_isset=' . $vocab_isset . ' $total=' . $total . ' $lat=' . $lat . ' $lon=' . $lon . ' $radius=' . $radius . '$datefrom=' . $datefrom . ' $dateto=' . $dateto . ' $extend=' . $extend . ' $tag_mode=' . $tag_mode . ' $class=' . $class . ' $style=' . $style . ' $page=' . $page);
        }
        // Get a list of "all" the photos. This is cached.
        switch ($type) {
          case "photoset":
            $response = flickr_photosets_getphotos($id, array(
                'per_page' => $per_page,
                'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                'media' => $media,
            ), $page);
            if (!$response) {
              return;
            }
            $photos = $response['photoset']['photo'];
            break;

          case "gallery":
            $response = flickr_galleries_getphotos($gallery_id, $page, array(
                'per_page' => $per_page,
                'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                'media' => $media,
            ), $page);
            if (!$response) {
              return;
            }
            $photos = $response['photos']['photo'];
            break;

          case "favorites":
            $response = flickr_favorites_getpubliclist($id, 1, array(
              'per_page' => $per_page,
              'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
            ));
            if (!$response) {
              return;
            }
            $photos = $response['photo'];
            break;

          // User and group albums.
          default:
            $valid_sort = ($sort == 'date-taken-desc' || $sort == 'date-posted-desc') ? $sort : '';
            // Filter gets priority. Date sorting will be done anyway later.
            $valid_sort = ($filter == 'interestingness-desc' || $filter == 'relevance') ? $filter : $valid_sort;
            $textext = array();
            if ($type == 'group') {
              $group_id = $id;
              $id = '';
              $tags_combined = $tags;
              $texts[0] = $tagsfix;
              $license = '';
            }
            // On public photos we want to match all tags (AND).
            if ($type == 'user') {
              $group_id = '';
              if ($id == 'public' || $id == '39873962@N08' || empty($id)) {
                $texts[0] = $tagsfix;
                $id = '39873962@N08';
                $license = '1,2,3,4,5,6,7';
              }
              // On albums with a specified ID match any tags (OR).
              else {
                $texts = is_array($tagsfix) ? $tagsfix : explode(",", $tagsfix);
                $license = '';
              }
            }
            // With OR operator we remove exclusion strings.
            if ($tag_mode == 'any') {
              // Produce an array of all exlusion tags to use later on.
              preg_match_all('/(,-\w+)/', $tags_combined, $excludestrings);
              // Remove sub key.
              $excludestrings = $excludestrings[0];
              // We need the tags themselves, without comma and minus sign.
              $excludestrings = str_replace(',-', '', $excludestrings);
              $tags_combined = preg_replace('/(,-\w+)/', '', $tags_combined);
            }
            if (isset($lat)) {
              // Start with a circle of 14 meter.
              $radius = empty($radius) ? 0.014 : $radius;
              do {
                if (variable_get('flickr_restrict', 1) < 2) {
                  $response = flickr_photos_search($id, $page, array(
                    'group_id' => $group_id,
                    'tags' => $tags_combined,
                    'tag_mode' => $tag_mode,
                    'min_taken_date' => $datefrom,
                    'max_taken_date' => $dateto,
                    'sort' => $valid_sort,
                    'per_page' => $per_page,
                    'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                    'media' => $media,
                    'lat' => $lat,
                    'lon' => $lon,
                    'radius' => $radius,
                    'license' => $license,
                  ));
                  foreach ($texts as $tagsfiks) {
                    $textextension = flickr_photos_search($id, $page, array(
                      'group_id' => $group_id,
                      'text' => '"' . $tagsfiks . '"',
                      'tag_mode' => $tag_mode,
                      'min_taken_date' => $datefrom,
                      'max_taken_date' => $dateto,
                      'sort' => $valid_sort,
                      'per_page' => $per_page,
                      'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                      'media' => $media,
                      'lat' => $lat,
                      'lon' => $lon,
                      'radius' => $radius,
                      'license' => $license,
                    ));
                    $textext = array_merge($textext, $textextension['photo']);
                  }
                }
                // No results, to extend the search on license.
                if ((empty($response['photo']) || variable_get('flickr_restrict', 1) == 2) && variable_get('flickr_restrict', 1) != 0) {
                  $response = flickr_photos_search($id, $page, array(
                    'group_id' => $group_id,
                    'tags' => $tags_combined,
                    'tag_mode' => $tag_mode,
                    'min_taken_date' => $datefrom,
                    'max_taken_date' => $dateto,
                    'sort' => $valid_sort,
                    'per_page' => $per_page,
                    'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                    'media' => $media,
                    'lat' => $lat,
                    'lon' => $lon,
                    'radius' => $radius,
                    'license' => '',
                  ));
                  foreach ($texts as $tagsfiks) {
                    $textextension = flickr_photos_search($id, $page, array(
                      'group_id' => $group_id,
                      'text' => '"' . $tagsfiks . '"',
                      'tag_mode' => $tag_mode,
                      'min_taken_date' => $datefrom,
                      'max_taken_date' => $dateto,
                      'sort' => $valid_sort,
                      'per_page' => $per_page,
                      'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                      'media' => $media,
                      'lat' => $lat,
                      'lon' => $lon,
                      'radius' => $radius,
                      'license' => '',
                    ));
                    $textext = array_merge($textext, $textextension['photo']);
                  }
                }
                // Extend the search geo radius gradually to 32 km if there are
                // not enough results.
                $radius = $radius * 3;
              } while ((count($response['photo']) + count($textext)) < $show_n && $radius <= 32);
            }
            else {
              if (variable_get('flickr_restrict', 1) < 2) {
                $response = flickr_photos_search($id, $page, array(
                  'group_id' => $group_id,
                  'tags' => $tags_combined,
                  'tag_mode' => $tag_mode,
                  'min_taken_date' => $datefrom,
                  'max_taken_date' => $dateto,
                  'sort' => $valid_sort,
                  'per_page' => $per_page,
                  'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                  'media' => $media,
                  'license' => $license,
                ));
                foreach ($texts as $tagsfiks) {
                  $textextension = flickr_photos_search($id, $page, array(
                    'group_id' => $group_id,
                    'text' => '"' . $tagsfiks . '"',
                    'tag_mode' => $tag_mode,
                    'min_taken_date' => $datefrom,
                    'max_taken_date' => $dateto,
                    'sort' => $valid_sort,
                    'per_page' => $per_page,
                    'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                    'media' => $media,
                    'license' => $license,
                  ));
                  $textext = array_merge($textext, $textextension['photo']);
                }
              }
              if ((empty($response['photo']) || variable_get('flickr_restrict', 1) == 2) && variable_get('flickr_restrict', 1) != 0) {
                $response = flickr_photos_search($id, $page, array(
                  'group_id' => $group_id,
                  'tags' => $tags_combined,
                  'tag_mode' => $tag_mode,
                  'min_taken_date' => $datefrom,
                  'max_taken_date' => $dateto,
                  'sort' => $valid_sort,
                  'per_page' => $per_page,
                  'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                  'media' => $media,
                  'license' => '',
                ));
                foreach ($texts as $tagsfiks) {
                  $textextension = flickr_photos_search($id, $page, array(
                    'group_id' => $group_id,
                    'text' => '"' . $tagsfiks . '"',
                    'tag_mode' => $tag_mode,
                    'min_taken_date' => $datefrom,
                    'max_taken_date' => $dateto,
                    'sort' => $valid_sort,
                    'per_page' => $per_page,
                    'extras' => 'date_upload,date_taken,license,geo,tags,views,media',
                    'media' => $media,
                    'license' => '',
                  ));
                  $textext = array_merge($textext, $textextension['photo']);
                }
              }
            }
            if (!$response) {
              return;
            }
            $photos = $extend ? array_merge($response['photo'], $textext) : $response['photo'];
            // Remove duplicates on the key 'id'.
            $temp = array();
            $new = array();
            foreach ($photos as $value) {
              if (!in_array($value['id'], $temp)) {
                $temp[] = $value['id'];
                $new[] = $value;
              }
            }
            $photos = $new;
            // With OR operator we remove results that match exclusion strings.
            if ($tag_mode == 'any') {
              $photos = array_filter($photos, function($photo) use ($excludestrings) {
                return flickr_excludestrings($photo, $excludestrings);
              });
            }
        }
        switch ($sort) {
          case 'id':
            usort($photos, 'flickr_sortByID');
            break;

          case 'date-taken-desc':
            if ($type != 'user' || !empty($filter)) {
              usort($photos, 'flickr_sortByTaken');
            }
            break;

          case 'date-posted-desc':
            if ($type != 'user' || !empty($filter)) {
              usort($photos, 'flickr_sortByUpload');
            }
            break;

          // Only for group albums.
          case 'added':
            usort($photos, 'flickr_sortByAdded');
            break;

          case 'views':
            usort($photos, 'flickr_sortByPopularity');
            break;

          case 'random':
            shuffle($photos);
            break;

          // In any other case as ordered by the Flickr API response.
          default:
            break;
        }
        // Skip photos taken in the future (date set incorrectly on the camera).
        if ($sort == 'date-taken-desc') {
          $skipped = 0;
          foreach ($photos as $key => $photo) {
            $date = time() - strtotime($photo['datetaken']);
            if ($date < 0) {
              unset($photos[$key]);
              $skipped++;
            }
          }
          if ($skipped > 0) {
            drupal_set_message(t("Skipped !number photos because dated in the future (probably due to a wrong date on the used camera).", array('!number' => '<em>' . $skipped . '</em>')), 'warning');
          }
        }
        // We shouldn't try to return more than the total number of photos.
        $to = min($show_n, count($photos));
        $i = 0;
        $j = 0;
        $k = 0;
        // A (too complex) series of conditions to loop through to generate the
        // photos of an album. TODO: Implement simplification and better logic.
        // No Flickr tags specified and on a node page.
        if ($vocab_isset == -1 && empty($tags) && empty($lat) && (arg(0) == 'node' && is_numeric(arg(1)) && (arg(2) == '' || arg(2) == 'view'))) {
          $vocab_name = taxonomy_vocabulary_load($vocab_isset)->name;
          $output .= t("Post has no !vocab_name or location specified.", array('!vocab_name' => '<em>' . $vocab_name . '</em>'));
        }
        // No Flickr tags specified, not on a node page, thus show all.
        elseif ((empty($tags)  && empty($tags_user)) || ($type == 'gallery' && is_numeric($delta))) {
          foreach ($photos as $photo) {
            if ($i < $show_n && ($media == 'all' || $media == $photo['media'] . 's')) {
              // Insert owner into $photo because theme_flickr_photo needs it.
              $photo['owner'] = ($type == 'photoset') ? $info['owner'] : $photo['owner'];
              $photo['owner'] = ($type == 'gallery') ? $info['gallery']['owner'] : $photo['owner'];
              // Check if the requested size is available on Flickr.
              if (flickr_in_array_r($sizes[$size]['label'], flickr_photos_getsizes($photo['id']))) {
                $output .= theme('flickr_photo', array(
                  'photo' => $photo,
                  'size' => $size,
                  'min_title' => $min_title,
                  'min_metadata' => $min_metadata,
                ));
                $i++;
              }
              else {
                $output .= '';
                $k++;
              }
              $j++;
            }
          }
        }
        // Filter on Flickr tags specified in user account.
        elseif (empty($tags) && $type == 'user' && !empty($id) && $id != 'public') {
          foreach ($photos as $key => $photo) {
            $tags_user = !is_array($tags_user) ? explode(",", $tags_user) : $tags_user;
            foreach ($tags_user as $term) {
              if ($i >= $show_n && stripos($photo['tags'], $term) !== FALSE) {
                $j++;
              }
              elseif (stripos($photo['tags'], $term) !== FALSE && ($media == 'all' || $media == $photo['media'] . 's')) {
                // Check if the requested size is available on Flickr.
                if (flickr_in_array_r($sizes[$size]['label'], flickr_photos_getsizes($photo['id']))) {
                  $output .= theme('flickr_photo', array(
                    'photo' => $photo,
                    'size' => $size,
                    'min_title' => $min_title,
                    'min_metadata' => $min_metadata,
                  ));
                  $i++;
                }
                else {
                  $output .= '';
                  $k++;
                }
                // Avoid this image gets repeated by removing it from the
                // array.
                unset($photos[$key]);
                $j++;
              }
            }
          }
        }
        // Filter on Flickr tags as terms.
        elseif (empty($tags_user) || empty($id)) {
          $taxs = is_array($tags) ? $tags : explode(",", $tags);
          $texts = is_array($tagsfix) ? $tagsfix : explode(",", $tagsfix);
          $terms = array_merge($taxs, $texts);
          $done = 0;
          foreach ($photos as $key => $photo) {
            $phototags = (variable_get('flickr_extend', 1) || $extend) && $extend ? $photo['tags'] . ' ' . strtolower($photo['title']) : $photo['tags'];
            foreach ($terms as $term) {
              if (($i >= $show_n && (stripos($phototags, $term) !== FALSE || $type == 'user')) || ($photo['id'] == $done && (stripos($phototags, $term) !== FALSE || $type == 'user'))) {
                $j++;
              }
              elseif (($media == 'all' || $media == $photo['media'] . 's') && (stripos($phototags, $term) !== FALSE || $type == 'user')) {
                // Insert owner into $photo because theme_flickr_photo needs it.
                $photo['owner'] = $type == 'photoset' ? $info['owner'] : $photo['owner'];
                $photo['owner'] = $type == 'gallery' ? $info['gallery']['owner'] : $photo['owner'];
                // Check if the requested size is available on Flickr.
                if (flickr_in_array_r($sizes[$size]['label'], flickr_photos_getsizes($photo['id']))) {
                  $output .= theme('flickr_photo', array(
                    'photo' => $photo,
                    'size' => $size,
                    'min_title' => $min_title,
                    'min_metadata' => $min_metadata,
                  ));
                  $i++;
                }
                else {
                  $output .= '';
                  $k++;
                }
                // Avoid this image gets repeated by removing it from the
                // array AND "remembering" the processed photo ID if it is twice
                // in the array (public photos with multiple tags).
                unset($photos[$key]);
                $done = $photo['id'];
                $j++;
              }
            }
          }
        }
        // Filter on Flickr tags as terms AND Flickr tags specified in user
        // account.
        else {
          $terms = is_array($tags) ? $tags : explode(",", $tags);
          foreach ($photos as $key => $photo) {
            foreach ($tags_user as $tag) {
              foreach ($terms as $term) {
                if ($i >= $show_n && stripos($photo['tags'], $term) !== FALSE && stripos($photo['tags'], $tag) !== FALSE) {
                  $j++;
                }
                elseif (stripos($photo['tags'], $term) !== FALSE && stripos($photo['tags'], $tag) !== FALSE && ($media == 'all' || $media == $photo['media'] . 's')) {
                  // Insert owner into $photo because theme_flickr_photo needs
                  // it.
                  $photo['owner'] = ($type == 'photoset') ? $info['owner'] : $photo['owner'];
                  // TODO: In theory we don't get here if a gallery. Remove?
                  $photo['owner'] = ($type == 'gallery') ? $info['gallery']['owner'] : $photo['owner'];
                  // Check if the requested size is available on Flickr.
                  if (flickr_in_array_r($sizes[$size]['label'], flickr_photos_getsizes($photo['id']))) {
                    $output .= theme('flickr_photo', array(
                      'photo' => $photo,
                      'size' => $size,
                      'min_title' => $min_title,
                      'min_metadata' => $min_metadata,
                    ));
                    $i++;
                  }
                  else {
                    $output .= '';
                    $k++;
                  }
                  // Avoid this image gets repeated by removing it from the
                  // array.
                  unset($photos[$key]);
                  $j++;
                }
              }
            }
          }
        }
        if ($k > 0) {
          drupal_set_message(t("!number photos were skipped because the requested image size is not available on Flickr. They were uploaded when this size was not offered yet. To include them, use another size or re-upload your photos on Flickr.", array('!number' => '<em>' . $k . '</em>')), 'warning');
        }
        $output .= '</div>';

        if ($i == 0 && variable_get('flickr_block_hide_empty', 0)) {
          $output = '';
          if (is_numeric($delta) && module_exists('flickr_block')) {
            $refresh = $sort == 'random' ? variable_get('flickr_block_refresh_random', 23) : variable_get('flickr_block_refresh_others', 31);
            // drupal_is_front_page() is added because it also can have
            // arg(0) == 'node'.
            cache_set('flickr_block_' . $delta . '_' . $idfix . '_' . $tags . '_' . $lat . '_' . $datetofix . '_' . $datefromfix . '_' . arg(0) . '_' . drupal_is_front_page(), $output, 'cache', time() + $refresh * 60 * 60);
          }
          return $output;
        }

        // A counter if set to show.
        if (isset($response['total']) || isset($response['photos']['total'])) {
          $response['total'] = (!isset($response['total']) && isset($response['photos']['total'])) ? $response['photos']['total'] : $response['total'];
          $response['total'] = isset($textextension['total']) ? $response['total'] + $textextension['total'] : $response['total'];
        }
        $total = (isset($response['total'])) ? $response['total'] : $total;
        $total = ($type == 'favorites' && !empty($tags)) ? $j : $total;
        $total = (empty($tags) || isset($response['total'])) ? (int) $total : $j;
        $total = (isset($response['total']) && !empty($tags) && $j == $show_n * 4) ? $response['total'] : $total;
        $total = $total < $i ? $i : $total;
        $total = $i < $show_n ? $i : $total;
        $total = number_format($total, 0, '.', variable_get('flickr_thousands_sep', ','));
        if (!empty($radius)) {
          $radius = $radius / 3;
          $km = floor($radius);
          $mt = ltrim(str_replace(".", "", number_format($radius - $km, 3)), '0');
          $mt = empty ($mt) ? '' : $mt . ' ' . t('mt');
          $km = $radius >= 1 ? $km . ' ' . t('km') : '';
          $separator = empty($km) || empty($mt) ? '' : ' ' . t('and') . ' ';
          $range = ' ' . t('in a radius of') . ' ' . $km . $separator . $mt;
        }
        else {
          $range = '';
        }
        $count = t('@number out of @total !flickr@range', array(
          '@number' => $i,
          '@total' => $total,
          '!flickr' => $flickr,
          '@range' => $range,
        ));
        // Note the $delta value is 'abused' for counter override from filter.
        // If the total found > max query ($per_page), omit the counter if tags
        // are applied.
        $terms = isset($terms) ? $terms : 1;
        $output .= (((variable_get('flickr_counter', 1) && $delta != 'false') || $delta == 'true') && (isset($response['total']) || ($j < $per_page * count($terms) || empty($tags))) && ($show_n > 1 || is_numeric($delta))) ? '<div class="flickr-album-counter">' . $count . '</div>' : '';
    }
    if ($show_n > 1 || is_numeric($delta)) {
      $output .= '</div>';
    }
    else {
      $output .= '</span>';
    }
    if (is_numeric($delta) && module_exists('flickr_block')) {
      $refresh = $sort == 'random' ? variable_get('flickr_block_refresh_random', 23) : variable_get('flickr_block_refresh_others', 31);
      // drupal_is_front_page() is added because it also can have
      // arg(0) == 'node'.
      cache_set('flickr_block_' . $delta . '_' . $idfix . '_' . $tagsfix . '_' . $latfix . '_' . $datefromfix . '_' . $datetofix . '_' . arg(0) . '_' . drupal_is_front_page() . '_' . $pagefix, $output, 'cache', time() + $refresh * 60 * 60);
    }
  }
  return $output;
}

/**
 * Create a link to a Flickr search page with similar results as a user or group
 * album passing the same arguments.
 */
function flickr_album_link_construct($linktext, $type = 'user', $id = '39873962@N08', $show_n = NULL, $media = 'photos', $tags = '', $filter = NULL, $lat = NULL, $lon = NULL, $radius = NULL, $datefrom = NULL, $dateto = NULL, $extend = 1, $tag_mode = 'all') {
  if ($extend == 1) {
    $tagsinurl = $tag_mode == 'all' ? str_replace(',', '+AND+', $tags) : str_replace(',', '+OR+', str_replace(',-', '+AND+-', $tags));
    $tags2 = '&q=' . $tagsinurl;
  }
  else {
    $tags2 = '&tags=' . $tags;

  }
  if ($type == 'user') {
    $link_id = $id == '39873962@N08' ? 'user_id=' : 'user_id=' . $id;
  }
  else {
    $link_id = 'group_id=' . $id;
  }
  // Avoid empty gps attributes in the query that causes Flickr query hickups.
  $link_lat = empty($lat) ? '' : '&lat=' . $lat;
  $link_lon = empty($lon) ? '' : '&lon=' . $lon;
  $flickr = l($linktext, 'https://www.flickr.com/search/?' . $link_id . '&per_page=' . $show_n . '&tag_mode=' . $tag_mode . $tags2 . $link_lat . $link_lon . '&radius=' . $radius . '&min_taken_date=' . $datefrom . '&max_taken_date=' . $dateto . '&sort=' . $filter . '&media=' . $media, array(
    'attributes' => array(
      'title' => t('View the results on Flickr'),
      'target' => '_blank',
    ),
    'html' => TRUE,
  ));
  return $flickr;
}

/**
 * Callback function of array_filter().
 * Returns TRUE if a value is found in an array within a multidimensional array.
 * Note we use a closure to pass some variables.
 * See http://stackoverflow.com/a/2529784/523688.
 *
 * @param array $photo
 *   A single passed element of $photos.
 *
 * @param array $excludestrings
 *   The array to match, to return false if true.
 *
 * @return bool
 *   FALSE if a match found.
 */
function flickr_excludestrings($photo, $excludestrings) {
  foreach ($excludestrings as $excludestring) {
    if (stripos($photo['tags'], $excludestring) !== FALSE) {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Returns TRUE if a value is found in a multidimensional array.
 * See http://stackoverflow.com/a/4128377.
 *
 * @param string $needle
 *   The value to be matched.
 *
 * @param array $haystack
 *   The array to match.
 *
 * @param bool $strict
 *   If set to TRUE also check the types of the needle in the haystack.
 *
 * @return bool
 *   TRUE if match found.
 */
function flickr_in_array_r($needle, $haystack, $strict = FALSE) {
  foreach ($haystack as $item) {
    if (($strict ? $item === $needle : $item == $needle) || (is_array($item) && flickr_in_array_r($needle, $item, $strict))) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Puts an array in descending order on the used key.
 *
 * Call this function with e.g. 'usort($photos, 'flickr_sortByPopularity')'.
 * See http://stackoverflow.com/a/2699159.
 */
function flickr_sortByPopularity($a, $b) {
  return $b['views'] > $a['views'];
}

function flickr_sortByTaken($a, $b) {
  return strtotime($b['datetaken']) > strtotime($a['datetaken']);
}

function flickr_sortByUpload($a, $b) {
  return $b['dateupload'] > $a['dateupload'];
}

function flickr_sortByAdded($a, $b) {
  return $b['dateadded'] > $a['dateadded'];
}

function flickr_sortByID($a, $b) {
  return $b['id'] > $a['id'];
}

/**
 * Return the Flickr photo suffix that corresponds to the one that is one step
 * bigger than the one that is passed in the parameter.
 * Avoided are sizes that do not exist on all images ('n' and 'c').
 *
 * @param string $size
 *   The image size suffix to return the bigger one for.
 */
function flickr_one_size_bigger($size) {
  $in = array('h', 'b', 'c', 'z', '-', 'n', 'm', 'q', 't', 's');
  $out = array('k', 'h', 'b', 'b', 'z', 'z', '-', 'm', 'm', 'q');
  return str_replace($in, $out, $size);
}

/**
 * Performs an HTTP request over cURL.
 * Taken from http://cgit.drupalcode.org/chr/tree/chr.module.
 *
 * This is a flexible and powerful HTTP client implementation. Correctly
 * handles GET, POST, PUT or any other HTTP requests. Handles redirects.
 *
 * @param $url
 *   A string containing a fully qualified URI.
 * @param array $options
 *   (optional) An array that can have one or more of the following elements:
 *   - headers: An array containing request headers to send as name/value pairs.
 *   - method: A string containing the request method. Defaults to 'GET'.
 *   - data: A string containing the request body, formatted as
 *     'param=value&param=value&...'. Defaults to NULL.
 *   - max_redirects: An integer representing how many times a redirect
 *     may be followed. Defaults to 3.
 *   - timeout: A float representing the maximum number of seconds the function
 *     call may take. The default is 30 seconds. If a timeout occurs, the error
 *     code is set to the HTTP_REQUEST_TIMEOUT constant.
 *   - context: A context resource created with stream_context_create().
 *   - verify_ssl: A boolean, to decide whether (TRUE) or not (FALSE) verify the
 *     SSL certificate and host.
 *   - verbose: A boolean, to switch on (TRUE) and off (FALSE) the cURL verbose
 *     mode.
 *   - cookiefile: A string containing a local path to the cookie file.
 *   - http_proxy: An array that will override the system-wide HTTP proxy
 *     settings. Array's elements:
 *   - https_proxy: An array that will override the system-wide HTTPS proxy
 *     settings.
 *   - curl_opts: An array of generic cURL options.
 *
 * @return object
 *   An object that can have one or more of the following components:
 *   - request: A string containing the request body that was sent.
 *   - code: An integer containing the response status code, or the error code
 *     if an error occurred.
 *   - protocol: The response protocol (e.g. HTTP/1.1 or HTTP/1.0).
 *   - status_message: The status message from the response, if a response was
 *     received.
 *   - redirect_code: If redirected, an integer containing the initial response
 *     status code.
 *   - redirect_url: If redirected, a string containing the URL of the redirect
 *     target.
 *   - error: If an error occurred, the error message. Otherwise not set.
 *   - errno: If an error occurred, a cURL error number greater than 0.
 *     Otherwise set to 0.
 *   - headers: An array containing the response headers as name/value pairs.
 *     HTTP header names are case-insensitive (RFC 2616, section 4.2), so for
 *     easy access the array keys are returned in lower case.
 *   - data: A string containing the response body that was received.
 *   - curl_opts: An array of curl options used
 */
function flickr_curl_http_request($url, array $options = array()) {
  $result = new stdClass();

  // Parse the URL and make sure we can handle the schema.
  $uri = @parse_url($url);

  if ($uri == FALSE) {
    $result->error = 'unable to parse URL';
    $result->code = -1001;
    return $result;
  }

  if (!isset($uri['scheme'])) {
    $result->error = 'missing schema';
    $result->code = -1002;
    return $result;
  }

  timer_start(__FUNCTION__);

  // Merge the default options.
  $options += array(
    'headers' => array('User-Agent' => 'Drupal (+http://drupal.org/)'),
    'method' => 'GET',
    'data' => NULL,
    'max_redirects' => 3,
    'timeout' => 30.0,
    'context' => NULL,
    'verify_ssl' => FALSE,
    'verbose' => FALSE,
    'cookiefile' => NULL,
    'http_proxy' => variable_get('http_proxy'),
    'https_proxy' => variable_get('https_proxy'),
    'curl_opts' => array(),
  );

  // Initialize cURL object.
  $ch = curl_init($url);

  // Set the proxy settings.
  flickr_curl_set_proxy_settings($options, $ch, $uri);

  // If the database prefix is being used by SimpleTest to run the tests in a
  // copied database then set the user-agent header to the database prefix so
  // that any calls to other Drupal pages will run the SimpleTest prefixed
  // database.
  // The user-agent is used to ensure that multiple testing sessions running at
  // the same time won't interfere with each other as they would if the database
  // prefix were stored statically in a file or database variable.
  $test_info = &$GLOBALS['drupal_test_info'];
  if (!empty($test_info['test_run_id'])) {
    $options['headers']['User-Agent'] = drupal_generate_test_ua($test_info['test_run_id']);
  }
  elseif (empty($options['headers']['User-Agent'])) {
    $options['headers']['User-Agent'] = 'Drupal (+http://drupal.org/)';
  }

  // Set default configuration.
  flickr_curl_set_defaults($options, $ch);

  // Set cookie settings.
  flickr_curl_set_cookie_settings($options, $ch);

  // Set the port.
  $success = flickr_curl_set_port($options, $ch, $uri);

  if (FALSE === $success) {
    $result->error = 'invalid schema ' . $uri['scheme'];
    $result->code = -1003;
    return $result;
  }

  // Set request options.
  $success = flickr_curl_request_type_option($options, $ch);

  if (FALSE === $success) {
    $result->error = 'invalid method ' . $options['method'];
    $result->code = -1004;
    return $result;
  }

  // If the server URL has a user then attempt to use basic authentication.
  if (isset($uri['user'])) {
    $options['headers']['Authorization'] = 'Basic ' . base64_encode($uri['user'] . (isset($uri['pass']) ?
      ':' . $uri['pass'] : ''));
  }

  // Set headers.
  flickr_curl_set_headers($options, $ch);

  // Set any last minute options.
  flickr_curl_set_options($options, $ch);

  // Make request.
  $result->data = trim(curl_exec($ch));

  // Check for errors.
  $result->errno = curl_errno($ch);

  // Get response info.
  $info = curl_getinfo($ch);

  // If there's been an error, do not continue.
  if ($result->errno != 0) {
    // Request timed out.
    if (CURLE_OPERATION_TIMEOUTED == $result->errno) {
      $result->code = HTTP_REQUEST_TIMEOUT;
      $result->error = 'request timed out';
      return $result;
    }
    $result->error = curl_error($ch);
    $result->code = $result->errno;
    return $result;
  }

  // The last effective URL should correspond to the Redirect URL.
  $result->redirect_url = curl_getinfo($ch, CURLINFO_EFFECTIVE_URL);

  // Save the request sent into the result object.
  $result->request = curl_getinfo($ch, CURLINFO_HEADER_OUT);

  // Close the connection.
  curl_close($ch);

  // Parse response headers from the response body.
  // Be tolerant of malformed HTTP responses that separate header and body with
  // \n\n or \r\r instead of \r\n\r\n.
  list($response, $result->data) = preg_split("/\r\n\r\n|\n\n|\r\r/", $result->data, 2);

  // Sometimes when making an HTTP request via proxy using cURL, you end up with
  // a multiple set of headers:
  // from the web server being the actual target, from the proxy itself, etc.
  // The following 'if' statement is to check for such a situation and make sure
  // we get a proper split between
  // actual response body and actual response headers both coming from the web
  // server.
  while ('HTTP/' == substr($result->data, 0, 5)) {
    list($response, $result->data) = preg_split("/\r\n\r\n|\n\n|\r\r/", $result->data, 2);
  }

  $response = preg_split("/\r\n|\n|\r/", $response);

  // Parse the response status line.
  list($protocol, $code, $status_message) = explode(' ', trim(array_shift($response)), 3);
  $result->protocol = $protocol;
  $result->status_message = $status_message;

  $result->headers = array();

  // Parse the response headers.
  while ($line = trim(array_shift($response))) {
    list($name, $value) = explode(':', $line, 2);
    $name = strtolower($name);
    if (isset($result->headers[$name]) && $name == 'set-cookie') {
      // RFC 2109: the Set-Cookie response header comprises the token Set-
      // Cookie:, followed by a comma-separated list of one or more cookies.
      $result->headers[$name] .= ',' . trim($value);
    }
    else {
      $result->headers[$name] = trim($value);
    }
  }

  $responses = flickr_response_codes();

  // RFC 2616 states that all unknown HTTP codes must be treated the same as the
  // base code in their class.
  if (!isset($responses[$code])) {
    $code = floor($code / 100) * 100;
  }
  $result->code = $code;

  switch ($code) {
    case 200: // OK.
    case 304: // Not modified.
      break;

    case 301: // Moved permanently.
    case 302: // Moved temporarily.
    case 307: // Moved temporarily.
      $location = $result->headers['location'];
      $options['timeout'] -= timer_read(__FUNCTION__) / 1000;
      if ($options['timeout'] <= 0) {
        $result->code = HTTP_REQUEST_TIMEOUT;
        $result->error = 'request timed out';
      }
      elseif ($options['max_redirects']) {
        // Redirect to the new location.
        $options['max_redirects']--;
        $result = curl_http_request($location, $options);
        $result->redirect_code = $code;
      }
      if (!isset($result->redirect_url)) {
        $result->redirect_url = $location;
      }
      break;

    default:
      $result->error = $status_message;
  }

  // Lastly, include any cURL specific information.
  $result->curl_info = $info;

  return $result;
}
/**
 * Set cURL options.
 *
 * @param array $options [reference]
 *  Options array
 * @param object $ch [reference]
 *  cURL Object
 */
function flickr_curl_set_options(&$options, &$ch) {
  // Set any extra cURL options.
  foreach ($options['curl_opts'] as $opt => $value) {
    $set = curl_setopt($ch, $opt, $value);
    if (FALSE === $set) {
      watchdog('curl_http_request', 'Unable to set cURL option @opt : @value', array('@opt' => $opt, '@value' => $value), WATCHDOG_ERROR);
    }
  }
}

/**
 * Set default cURL settings.
 *
 * @param array $options [reference]
 *  Options array
 * @param object $ch [reference]
 *  cURL Object
 */
function flickr_curl_set_defaults(&$options, &$ch) {
  curl_setopt($ch, CURLOPT_HEADER, TRUE);
  curl_setopt($ch, CURLOPT_USERAGENT, $options['headers']['User-Agent']);
  curl_setopt($ch, CURLINFO_HEADER_OUT, TRUE);
  curl_setopt($ch, CURLOPT_TIMEOUT, $options['timeout']);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $options['timeout']);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, FALSE);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, $options['verify_ssl']);
  curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, $options['verify_ssl']);
  curl_setopt($ch, CURLOPT_MAXREDIRS, $options['max_redirects']);

  // Remove the user agent from the headers as it is already set.
  unset($options['headers']['User-Agent']);
}

/**
 * Set proxy settings.
 *
 * @param array $options [reference]
 *  Options array
 * @param object $ch [reference]
 *  cURL Object
 * @param array $uri [reference]
 *  URI array
 */
function flickr_curl_set_proxy_settings(&$options, &$ch, &$uri) {
  // Select the right proxy for the right protocol.
  $proxy = ('https' == $uri['scheme']) ? $options['https_proxy'] : $options['http_proxy'];

  // Nullify the proxy if the host to send the request to is part of the proxy's
  // exceptions.
  if ((!empty($proxy['exceptions'])) && (in_array($uri['host'], $proxy['exceptions']))) {
    $proxy = NULL;
  }

  if (!empty($proxy)) {
    curl_setopt($ch, CURLOPT_PROXY, $proxy['server']);
    curl_setopt($ch, CURLOPT_PROXYPORT, $proxy['port']);
    // For the time being let's just support HTTP proxies with basic
    // authentication.
    if (isset($proxy['username']) && isset($proxy['password'])) {
      curl_setopt($ch, CURLOPT_PROXYUSERPWD, implode(':', array($proxy['username'], $proxy['password'])));
      curl_setopt($ch, CURLOPT_PROXYTYPE, CURLPROXY_HTTP);
      curl_setopt($ch, CURLOPT_PROXYAUTH, CURLAUTH_BASIC);
    }
  }
}

/**
 * Set default headers in curl object.
 *
 * @param array $options [reference]
 *  Options array
 * @param object $ch [reference]
 *  cURL Object
 */
function flickr_curl_set_headers(&$options, &$ch) {
  if (is_array($options['headers']) and !empty($options['headers'])) {
    $headers = array();
    foreach ($options['headers'] as $key => $value) {
      $headers[] = trim($key) . ": " . trim($value);
    }
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
  }
}

/**
 * Convert the string name of the request type to a cURL opt value.
 *
 * @param array $options [reference]
 *  Options array
 * @param object $ch [reference]
 *  cURL Object
 *
 * @return bool
 *  Returns FALSE on error.
 */
function flickr_curl_request_type_option(&$options, &$ch) {
  $valid_method = FALSE;
  switch (drupal_strtoupper($options['method'])) {
    case 'DELETE':
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'DELETE');
      $valid_method = TRUE;
      break;

    case 'OPTIONS':
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'OPTIONS');
      $valid_method = TRUE;
      break;

    case 'TRACE':
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'TRACE');
      $valid_method = TRUE;
      break;

    case 'CONNECT':
      // @todo
      break;

    case 'PATCH':
      // @todo
      break;

    case 'POST':
      // Assign the data to the proper cURL option.
      curl_setopt($ch, CURLOPT_POSTFIELDS, $options['data']);
      if (isset($options['multipart']) && TRUE === $options['multipart']) {
        // Do nothing for now.
      }
      else {
        curl_setopt($ch, CURLOPT_POST, TRUE);
      }
      $valid_method = TRUE;
      break;

    case 'PUT':
      // Assign the data to the proper cURL option.
      curl_setopt($ch, CURLOPT_POSTFIELDS, $options['data']);
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'PUT');
      curl_setopt($ch, CURLOPT_HTTPHEADER, array('X-HTTP-Method-Override: PUT'));
      $valid_method = TRUE;
      break;

    case 'GET':
      curl_setopt($ch, CURLOPT_HTTPGET, TRUE);
      $valid_method = TRUE;
      break;

    case 'HEAD':
      curl_setopt($ch, CURLOPT_NOBODY, TRUE);
      $valid_method = TRUE;
      break;

    default:
      return $valid_method;
  }
}

/**
 * Set port options.
 *
 * @param array $options [reference]
 *  Options array
 * @param object $ch [reference]
 *  cURL Object
 * @param array $uri [reference]
 *  URI array
 *
 * @return bool
 *  Returns TRUE if they were set properly, FALSE otherwise.
 */
function flickr_curl_set_port(&$options, &$ch, &$uri) {
  $default_ports = array(
    'http' => 80,
    'feed' => 80,
    'https' => 443,
  );

  if (array_key_exists($uri['scheme'], $default_ports)) {
    if (!isset($uri['port'])) {
      $uri['port'] = $default_ports[$uri['scheme']];
    }
    // RFC 2616: "non-standard ports MUST, default ports MAY be included".
    // We don't add the standard port to prevent from breaking rewrite rules
    // checking the host that do not take into account the port number.
    $options['headers']['Host'] = $uri['host'] . ($uri['port'] != 80 ? ':' . $uri['port'] : '');

    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Set default cookie settings.
 *
 * @param array $options [reference]
 *  Options array
 * @param object $ch [reference]
 *  cURL Object
 */
function flickr_curl_set_cookie_settings(&$options, &$ch) {
  // Set cookie settings.
  if ($options['cookiefile']) {
    curl_setopt($ch, CURLOPT_COOKIEJAR, $options['cookiefile']);
    curl_setopt($ch, CURLOPT_COOKIEFILE, $options['cookiefile']);
  }
}

/**
 * List of response codes.
 *
 * @return array
 *  Returns an array of response codes.
 */
function flickr_response_codes() {
  return array(
    100 => 'Continue',
    101 => 'Switching Protocols',
    200 => 'OK',
    201 => 'Created',
    202 => 'Accepted',
    203 => 'Non-Authoritative Information',
    204 => 'No Content',
    205 => 'Reset Content',
    206 => 'Partial Content',
    300 => 'Multiple Choices',
    301 => 'Moved Permanently',
    302 => 'Found',
    303 => 'See Other',
    304 => 'Not Modified',
    305 => 'Use Proxy',
    307 => 'Temporary Redirect',
    400 => 'Bad Request',
    401 => 'Unauthorized',
    402 => 'Payment Required',
    403 => 'Forbidden',
    404 => 'Not Found',
    405 => 'Method Not Allowed',
    406 => 'Not Acceptable',
    407 => 'Proxy Authentication Required',
    408 => 'Request Time-out',
    409 => 'Conflict',
    410 => 'Gone',
    411 => 'Length Required',
    412 => 'Precondition Failed',
    413 => 'Request Entity Too Large',
    414 => 'Request-URI Too Large',
    415 => 'Unsupported Media Type',
    416 => 'Requested range not satisfiable',
    417 => 'Expectation Failed',
    500 => 'Internal Server Error',
    501 => 'Not Implemented',
    502 => 'Bad Gateway',
    503 => 'Service Unavailable',
    504 => 'Gateway Time-out',
    505 => 'HTTP Version not supported',
  );
}

/**
 * Parse parameters to the filter from a format like:
 * style="float:left;border:1px"
 * into an associative array with HTML attributes and their values.
 */
function flickr_split_style($string) {
  $attribs = array();
  // Put each setting on its own line.
  $string = str_replace(';', "\n", $string);
  // Break them up around colons.
  preg_match_all('/([a-zA-Z.]+):([-@\/0-9a-zA-Z .\%"\']+)/', $string, $parts, PREG_SET_ORDER);
  foreach ($parts as $part) {
    // Normalize to lowercase and remove extra spaces.
    $name = strtolower(trim($part[1]));
    $value = trim($part[2]);
    // Remove undesired but tolerated characters from the value.
    $value = str_replace(str_split('"\''), '', $value);
    $attribs[$name] = $value;
  }
  return array($attribs);
}
