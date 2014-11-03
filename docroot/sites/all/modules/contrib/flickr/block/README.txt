The content of this file is based on the online documentation that can be found
at https://drupal.org/node/2171249
It is recommended to read it there, as it is more detailed.

NAME
====
Flickr Block
Part of the Flickr module. Project page at https://drupal.org/project/flickr

OVERVIEW
========
Flickr images or slideshows in blocks to show for example recent or random
images from a specific user, photoset, gallery or group.

- Configure the size, media type (photo/video) and number of images to show.
- With visibility by role or path.
- Blocks can be placed in any theme region.

There areseveral blocks that show the Flickr photos of a corresponding node
author 'dynamically' and appear on posts written by the user and on their user
profile pages. To avoid that, change the block settings to exclude 'node/*'
pages or show them only on 'user/*' pages.

Of course you can do it also the other way around to show a block only on a node
page. You can fine-grain it even more by selecting only a certain content type
you want to show them on, for example blog posts.

- Node author favorites (what they like from others, but all together)
  optionally tagged as term from node
- Node author gallery photos (arbitrary selection by author of other's photos)
  optionally with gallery title as term from node
- Node author photos optionally tagged as term from node
- Node author recent photosets

The node author has to have permission to specify a Flickr ID on their own
account (admin/people/permissions#module-flickr).

The block visibility setting for the 'Node author' blocks are not only
restricted by the sitebuilder in the block configuration but also by the module.
The block gets displayed when the first argument of the path is 'user' or 'node'
and a specific uid is available. This is however not visible for the web admin
and confusing. See #1122564: Sync the module defined visibility setting with the
block configuration.

Furthermore several sitewide blocks are available. A user, photoset, gallery or
group needs to be specified in the block configuration.

- Favorites optionally tagged as term from node
- Group photos optionally tagged as term from node
- Set photos optionally tagged as term from node
- User photos optionally tagged as term from node
- User photos with specific tags
- User recent photosets

BLOCK CONFIGURATION
===================
Fields in the block settings that apply on all blocks.

Show n photos
-------------
The block will display this many photos.

Size of photos
--------------
Select the size of photos you'd like to display in
the block. See https://drupal.org/node/2170535#sizes

NOTE:
For square images ('s': 75px and 'q': 150px) no real width
needs to be fetched, giving it a slight performance advantage over other sizes.
Recommended if you include many images.

Use size=x for a Flash slideshow over the full region width (responsive).
Size=y for a non-Flash version.

Media type
----------
- all
- photos (default)
- videos

Note that for videos only an image representing the video is shown, except for
slideshows (size x or y) that can 'play' a video. See
https://drupal.org/node/2226579#video.

All 'User' blocks.

Flickr User ID
--------------
A valid Flickr User ID, alias, username or email address. If this is left blank,
the site's default user will be used if set.
Emails or usernames (that might change at any given time) are internally (in the
variable) replaced with a stable NSID (Flickr ID number). These are rendered in
this field as Flickr usernames. 'Maria Emanuela' is human readable,
'43937662@N05' is not. Internal the module still uses the Flickr ID number as it
is more reliable.

Other fields are self-explaining.

SITEWIDE BLOCK SETTINGS
=======================
Generic block configuration settings can be found in an own section at
admin/config/media/flickr. Only if the submodule Flickr Block is enabled.

BLOCK SETTINGS (field group)
----------------------------

Hide empty blocks (no media found)
----------------------------------
A checkbox. Default OFF, mainly to make sure you can access the contextual
links. That little wheel you see when you hover over blocks to edit them in
place. It is recommended to hide empty blocks once you have set up the blocks
you need. Indispensable if you use blocks that dynamically show photos with
Flickr tags being similar to terms attached to a node.

Wrap the album title in an HTML heading tag (only for blocks)
-------------------------------------------------------------
Use 'p' for no style, e.g. 'h2' for a heading style or 'none' to not display an
album title. Use your browser inspector to see how other blocks are styled.

Refresh rates
-------------
It is recommended to set two different refresh values for random (default 23
hours) and other blocks (default 31 hours) to avoid they refresh all together.
Lower values impact performance negatively. Consider to use cache warming.

TIP
===
You find instructions targeted to editors that don't have block administer
permissions at https://drupal.org/node/2279003#block. They can still make use of
the 'Node author' blocks that use photos of their Flickr account that have
Flickr tags similar to taxonomy terms they attach to a node. This way they are
able to add matching Flickr photos with their posts without the hassle of
uploading them on the site. Remember to give site editors also the permission to
specify a Flickr identifier on their account.

Use Block Inject to put a Flickr Block inside your node body.
