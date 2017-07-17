<?php
/**
 * @file
 * Flickr API functions.
 */

/**
 * Get information about a photo.
 *
 * @param string $photo_id
 *   ID of the photo to get info about.
 *
 * @return array
 *   Response from the flickr method flickr.photos.getInfo..
 *   (https://www.flickr.com/services/api/flickr.photos.getInfo.html)
 */
function flickr_photos_getinfo($photo_id) {
  $response = flickr_request(
    'flickr.photos.getInfo',
    array('photo_id' => $photo_id)
  );
  if ($response) {
    return $response['photo'];
  }
  return FALSE;
}

/**
 * Returns the available sizes for a photo.
 *
 * @param string $photo_id
 *   ID of the photo to get the available sizes of.
 *
 * @return array
 *   Response from the flickr method flickr.photos.getSizes..
 *   (https://www.flickr.com/services/api/flickr.photos.getSizes.html)
 */
function flickr_photos_getsizes($photo_id) {
  $response = flickr_request(
    'flickr.photos.getSizes',
    array('photo_id' => $photo_id)
  );
  if ($response) {
    return $response['sizes']['size'];
  }
  return FALSE;
}

/**
 * Return a list of photos matching some criteria.
 *
 * @param string $nsid
 *   NSID of the user whose photoset tags will be returned.
 * @param string $page
 *   Page of results to return.
 *
 * @return array
 *   Response from the flickr method flickr.photos.search.
 *   (https://www.flickr.com/services/api/flickr.photos.search.html)
 */
function flickr_photos_search($nsid, $page = 1, $other_args = array()) {
  // The user ID that gets returned from flickr_user_find_by_identifier('').
  $tags = isset($other_args['tags']) ? $other_args['tags'] : '';
  $nsid = $nsid == 'public' || $nsid == '39873962@N08' || empty($nsid) ? '' : $nsid;
  $other_args['group_id'] = isset($other_args['group_id']) ? $other_args['group_id'] : '';
  if ($nsid == '39873962@N08' || empty($nsid)) {
    $args = array(
      'user_id' => '',
      'group_id' => $other_args['group_id'],
      'tag_mode' => 'all',
      'license' => $other_args['license'],
      'page' => $page,
    );
  }
  else {
    $args = array(
      'user_id' => $nsid,
      'page' => $page,
    );
    // No license restrictions if a user ID is specified.
    $other_args['license'] = '';
  }
  // Set per_page to flickr module default if not specified in $other_args.
  if (!isset($other_args['per_page'])) {
    $args['per_page'] = variable_get('flickr_photos_per_page', 6);
  }

  $response = flickr_request('flickr.photos.search', array_merge($args, $other_args));
  if ($response) {
    return $response['photos'];
  }
  return FALSE;
}

/**
 * Returns a list of favorite public photos for the given user.
 *
 * @param string $nsid
 *   NSID of the user whose photoset tags will be returned.
 * @param string $page
 *   Page of results to return.
 *
 * @return array
 *   Response from the flickr method flickr.favorites.getPublicList.
 *   (https://www.flickr.com/services/api/flickr.favorites.getPublicList.html)
 */
function flickr_favorites_getpubliclist($nsid, $page = 1, $other_args = array()) {
  $args = array(
    'user_id' => $nsid,
    'page' => $page,
  );

  // Set per_page to flickr module default if not specified in $other_args.
  if (!isset($other_args['per_page'])) {
    $args['per_page'] = variable_get('flickr_photos_per_page', 6);
  }

  $response = flickr_request('flickr.favorites.getPublicList', array_merge($args, $other_args));
  if ($response) {
    return $response['photos'];
  }
  return FALSE;
}

/**
 * Gets information about a photoset.
 *
 * @param string $photoset_id
 *   ID of the photoset to get information about.
 *
 * @return array
 *   Response from the flickr method flickr.photosets.getInfo.
 *   (https://www.flickr.com/services/api/flickr.photosets.getInfo.html)
 */
function flickr_photosets_getinfo($photoset_id) {
  $response = flickr_request(
    'flickr.photosets.getInfo',
    array('photoset_id' => $photoset_id)
  );
  if ($response) {
    return $response['photoset'];
  }
  return FALSE;
}

/**
 * Returns the photosets belonging to the specified user.
 *
 * @param string $nsid
 *   NSID of the user whose photoset list you want.
 *
 * @return array
 *   Response from the flickr method flickr.photosets.getList.
 *   (https://www.flickr.com/services/api/flickr.photosets.getList.html)
 */
function flickr_photosets_getlist($nsid, $page = NULL) {
  $per_page = (!empty($page)) ? variable_get('flickr_sets_per_page', 8) : '';
  $response = flickr_request(
    'flickr.photosets.getList',
    array(
      'user_id' => $nsid,
      'page' => $page,
      'per_page' => $per_page,
    )
  );
  if ($response) {
    return $response['photosets']['photoset'];
  }
  return FALSE;
}

/**
 * Returns the galleries curated by the specified user.
 *
 * @param string $nsid
 *   NSID of the user whose photoset list you want.
 *
 * @return array
 *   Response from the flickr method flickr.galleries.getList.
 *   (https://www.flickr.com/services/api/flickr.galleries.getList.html)
 */
function flickr_galleries_getlist($nsid, $page = 1) {
  $response = flickr_request(
    'flickr.galleries.getList',
    array(
      'user_id' => $nsid,
      'page' => $page,
    )
  );
  if ($response) {
    return $response['galleries']['gallery'];
  }
  return FALSE;
}

/**
 * Get the list of photos in a set.
 *
 * @param string $photoset_id
 *   The Flickr photoset ID.
 *
 * @return array
 *   Response from the flickr method flickr.photosets.getPhotos.
 *   (https://www.flickr.com/services/api/flickr.photosets.getPhotos.html)
 */
function flickr_photosets_getphotos($photoset_id, $other_args = array(), $page = 1) {
  $args = array(
    'photoset_id' => $photoset_id,
    'page' => $page,
  );

  // Set per_page to flickr module default if not specified in $other_args.
  if (!isset($other_args['per_page'])) {
    $args['per_page'] = variable_get('flickr_photos_per_page', 6);
  }

  $response = flickr_request('flickr.photosets.getPhotos', array_merge($args, $other_args));

  if ($response) {
    return $response;
  }
  return FALSE;
}

/**
 * Get information about a user.
 *
 * @param string $nsid
 *   The Flickr user's NSID.
 *
 * @return array $response
 *   Array with person's info from flickr.people.getInfo.
 *   (https://www.flickr.com/services/api/flickr.people.getInfo.html)
 *   or FALSE on error.
 */
function flickr_people_getinfo($nsid) {
  $response = flickr_request(
    'flickr.people.getInfo',
    array('user_id' => $nsid)
  );
  if ($response) {
    return $response['person'];
  }
  return FALSE;
}

/**
 * Return a user's NSID, given their username.
 *
 * @param string $username
 *   Username to look for.
 *
 * @return array
 *   Response from the flickr method flickr.people.findByUsername.
 *   (https://www.flickr.com/services/api/flickr.people.findByUsername.html)
 */
function flickr_people_findbyusername($username) {
  $response = flickr_request(
    'flickr.people.findByUsername',
    array('username' => $username)
  );
  if ($response) {
    return $response['user'];
  }
  return FALSE;
}

/**
 * Return a user's NSID, given their alias.
 *
 * @param string $alias
 *   Username to look for.
 *
 * @return array
 *   Response from the flickr method flickr.people.findByUsername.
 *   (https://www.flickr.com/services/api/flickr.people.findByUsername.html)
 */
function flickr_urls_lookupuser($alias) {
  $response = flickr_request(
    'flickr.urls.lookupUser',
    array('url' => 'https://www.flickr.com/photos/' . $alias),
    $cacheable = FALSE,
    $return_errors = TRUE
  );
  if ($response) {
    if ($response['stat'] == 'ok') {
      return $response['user'];
    }
  }
  return FALSE;
}

/**
 * Return a user's NSID, given their email address.
 *
 * @param string $email
 *   Email to look for.
 *
 * @return array
 *   Response from the flickr method flickr.people.findByEmail.
 *   (https://www.flickr.com/services/api/flickr.people.findByEmail.html)
 */
function flickr_people_findbyemail($email) {
  $response = flickr_request(
    'flickr.people.findByEmail',
    array('find_email' => $email)
  );
  if ($response) {
    return $response['user'];
  }
  return FALSE;
}

/**
 * Get the popular tags for a given user.
 *
 * @param string $nsid
 *   NSID of the user whose tags will be returned.
 * @param string $count
 *   Number of tags to return.
 *
 * @return array
 *   Response from the flickr method flickr.tags.getListUserPopular.
 *   (https://www.flickr.com/services/api/flickr.tags.getListUserPopular.html)
 */
function flickr_tags_getlistuserpopular($nsid, $count = NULL) {
  $args = array('user_id' => $nsid);
  if ($count != NULL) {
    $args['count'] = $count;
  }
  $response = flickr_request('flickr.tags.getListUserPopular', $args);
  if ($response) {
    return $response['who']['tags']['tag'];
  }
  return FALSE;
}

/**
 * Get the tag list for a given user.
 *
 * @param string $nsid
 *   NSID of the user whose photoset tags will be returned.
 *
 * @return array $response
 *   Response from the flickr method flickr.tags.getListUser.
 *   (https://www.flickr.com/services/api/flickr.tags.getListUser.html)
 */
function flickr_tags_getlistuser($nsid) {
  $response = flickr_request(
    'flickr.tags.getListUser',
    array('user_id' => $nsid)
  );
  if ($response) {
    return $response['who']['tags']['tag'];
  }
  return FALSE;
}

/**
 * Returns info about a given group.
 *
 * @param string $id
 *   NSID of the group whose photos you want.
 *
 * @return array $response
 *   Response from the flickr method flickr.groups.getInfo.
 *   (https://www.flickr.com/services/api/flickr.groups.getInfo.html)
 */
function flickr_groups_getinfo($id, $other_args = array()) {
  if (flickr_is_nsid($id)) {
    $args = array('group_id' => $id);
  }
  else {
    $args = array('group_path_alias' => $id);
  }
  // $return_errors = TRUE avoids error messages when we abuse this function to
  // determine betweeen a group and user ID.
  $response = flickr_request('flickr.groups.getInfo', array_merge($args, $other_args), $cacheable = FALSE, $return_errors = TRUE);
  if ($response) {
    return $response;
  }
}

/**
 * Returns a list of photos for a given gallery.
 *
 * @param string $id
 *   ID of the gallery.
 *
 * @return array $response
 *   Response from the flickr method flickr.galleries.getPhotos.
 *   (https://www.flickr.com/services/api/flickr.galleries.getPhotos.html)
 */
function flickr_galleries_getphotos($id, $page = 1, $other_args = array()) {
  $args = array(
    'gallery_id' => $id,
    'page' => $page,
  );

  // Set per_page to flickr module default if not specified in $other_args.
  if (!isset($other_args['per_page'])) {
    $args['per_page'] = variable_get('flickr_photos_per_page', 6);
  }

  $response = flickr_request('flickr.galleries.getPhotos', array_merge($args, $other_args));
  if ($response) {
    return $response;
  }
  return FALSE;
}

/**
 * Returns info about a given gallery.
 *
 * @param string $id
 *   NSID of the gallery whose photos you want.
 *
 * @return array $response
 *   Response from the flickr method flickr.gallery.getInfo.
 *   (https://www.flickr.com/services/api/flickr.gallery.getInfo.html)
 */
function flickr_galleries_getinfo($id, $other_args = array()) {
  $args = array('gallery_id' => $id);

  // $return_errors = TRUE avoids error messages when we abuse this function to
  // determine betweeen a gallery and set ID.
  $response = flickr_request('flickr.galleries.getInfo', array_merge($args, $other_args), $cacheable = FALSE, $return_errors = TRUE);
  if ($response) {
    return $response;
  }
}

/**
 * Returns a list of public photos for the given user.
 *
 * @param string $nsid
 *   NSID of the user whose photos you want.
 *
 * @return array $response
 *   Response from the flickr method flickr.people.getPublicPhotos.
 *   (https://www.flickr.com/services/api/flickr.people.getPublicPhotos.html)
 */
function flickr_people_getpublicphotos($nsid, $page = 1, $other_args = array()) {
  $args = array(
    'user_id' => $nsid,
    'page' => $page,
  );

  // Set per_page to flickr module default if not specified in $other_args.
  if (!isset($other_args['per_page'])) {
    $args['per_page'] = variable_get('flickr_photos_per_page', 6);
  }

  $response = flickr_request('flickr.people.getPublicPhotos', array_merge($args, $other_args));
  if ($response) {
    return $response;
  }
  return FALSE;
}

/**
 * Returns a place ID for a latitude and longitude.
 *
 * @param string $lat
 *   Latitude from -90 to 90. Anything after 4 decimals will be truncated.
 * @param string $lon
 *   Longitude from -90 to 90. Anything after 4 decimals will be truncated.
 *
 * @return array $response
 *   Response from the flickr method flickr.places.findByLatLon.
 *   (https://www.flickr.com/services/api/flickr.places.findByLatLon.html)
 */
function flickr_places_findbylatlon($lat, $lon) {
  $args = array(
    'lat' => $lat,
    'lon' => $lon,
  );

  $response = flickr_request('flickr.places.findByLatLon', $args);
  if ($response) {
    return $response;
  }
  return FALSE;
}
