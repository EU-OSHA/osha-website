The content of this file is based on the online documentation that can be found
at https://drupal.org/node/2171503
It is recommended to read it there, as it is more detailed.

NAME
====
Flickr Filter
Part of the Flickr module. Project page at https://drupal.org/project/flickr

OVERVIEW
========
Include single Flickr images, albums or slideshows (for sets, users or groups)
into the node body using only the Flickr ID and optionally a other parameters.

FILTER CONFIGURATION
====================
The Flickr filter should be added first to a text format at
admin/config/content/formats > configure
In the 'Filter processing order' it should be placed above filters that affect
image related HTML, for example AutoFloat
(https://drupal.org/project/autofloat).

Once you enabled the Flickr Filter submodule, you'll find a section FILTER
SETTINGS on the Flickr configuration page at admin/config/media/flickr to
provide the default values for the parameters size and heading. Both can be
overridden by specifying them in the filter tag, like [flickr-
group:id=91484156@N00, size=q, num=8, tags=flowers, heading=none].

Default size for single photos
------------------------------
A default Flickr size to use. This will be used when no size is specified, for
example [flickr-photo:id=3711935987]. TAKE CARE, n (320px) and c (800px) sizes
are missing on many "older" Flickr images! Defaults to m: 240 px on longest
side. Thanks to the default setting you can change the size of all images
without a specified size on the site in one go.

Wrap the album title in an HTML heading tag (only for the text filter)
----------------------------------------------------------------------
To style the album title. Use 'p' for no style, e.g. 'h3' for a heading or
'none' to not display an album title.

CREATE NEW FLICKR BLOCKS USING FLICKR FILTER
============================================
Using the predefined blocks from the Flickr Block submodule, once you "occupied"
one with a certain user, group or set ID, it can't be reused. With Flickr Filter
you just create a new block at admin/structure/block/add, using the right Text
format. With the parameters you define the desired settings.

If you use a photo size one step bigger than the block width, it will
automatically limit the image width to that of the block, without leaving
adjacent white space, filling it completely.

Use the block's visibility settings to specify what pages it should show on.
Don't use a block title, as this is added already. If you don't want that, use
the parameter heading=none.

The power of the Flickr Block submodule is that is can be context sensitive by
filtering Flickr photos on the node author's Flickr account and/or node terms to
be identical to tags used on Flickr. Something that can not be obtained
currently with Flickr Filter.

FILTER USAGE
=============
Single photo
============

Filter syntax
-------------
The filter format is:
[flickr-photo:id=7357144724, size=m]

It consists of:
- An opening square bracket ([).
- The term flickr followed by a dash (-).
The type: photo, photoset, user, group or favorites followed by a colon (:).
- A series of parameters separated by commas: id, size, class, style, num, tags,
  media, heading, sort, filter, count, mintitle and minmetadata
- A closing square bracket (]).

Photo ID
--------
Use the Flickr Advanced Search at https://www.flickr.com/search/advanced/ to
find a Flickr photo of your own choice. Click one you like. The last number of
the URL of the Flickr photo page is the ID, for example '9244503345' in
https://www.flickr.com/photos/98518260@N02/9244503345/.

Size
----
See https://drupal.org/node/2170535#sizes.

TAKE CARE, n (320px) and c (800px) sizes are missing on many "older" Flickr
images!

More info at https://www.flickr.com/services/api/misc.urls.html and
https://www.flickr.com/help/faq/search/?q=sizes

Float single photos
-------------------
If the AutoFloat module is active (https://drupal.org/project/autofloat) the
text already wraps around the image. If not, go back in 'Edit' mode and add:

, class=floatright

Put it at the end of the text filter tag above but inside the square brackets.
Don't forget the leading comma. This is prefered as it avoids inline styling and
is targeted with CSS that can be modified easily.

Also this will work:
[flickr-photo:id=9247388074, size=m, style=float:right;]

If the AutoFloat module is enabled (recommended), it should precede over the
existing 'floatleft' and 'floatright' classes found, but not over the inline
styles. Thus inline styling is the way to override AutoFloat behaviour. The
margins on the 'text side' of the image from autofloat.css get applied anyway,
so the text doesn't "lean" against the image.

To pass multiple classes or styles the syntax has to look like:
[flickr-photo:id=9247386562, class=foo bar, style=float:left; border:solid 2px;]
Thus without quotes, but with semicolons between styles.

Other parameters
----------------
Besides id, size, class and style there are
other parameters to use, like mintitle and minmetadata. You'll find parameter
examples, their use and default values at the bottom of the text filter help on
the 'Edit' page. Try to add some of them to find out how they work.

Album
=====
[flickr-photoset:id=72157634563269642]

You can create an album for a:

user
----
Most useful in combination with Flickr tags to filter on. User ID 'public' grabs
all users CC licensed photos.

photoset
--------
Currently the only way to have an arbitrary album to show as a slideshow.

gallery
-------
The only way to have an arbitrary album with photos from others. Currently no
slideshow support. Do not put own pictures in a gallery.

group
-----
Most convenient way to manage the images by multiple Flickr users, e.g. for a
sports club website.

user favorite photos
--------------------
A gallery is preferred as it give more flexibility. Left for legacy purpose.

All aforementioned parameters that also apply on single images can be used.
Obviously the 'id' is now a user, set, gallery or group ID. A number that
includes '@' is a user or group ID. A very long number (>16 characters) is a
photoset or gallery ID.

Examples:
- user: '98518260@N02' in https://www.flickr.com/photos/98518260@N02/9244503345
- photoset: '72157634563269642' in
  https://www.flickr.com/photos/98518260@N02/sets/72157634563269642
- gallery: '72157645025390895' in
  http://www.flickr.com/photos/martinpostma/galleries/72157645025390895

For users and groups you can also use the path alias if it exists:
- group: 'southseauk' in https://www.flickr.com/groups/southseauk

For albums you have the extra sizes 'x' and 'y' available that result in a Flash
or non-Flash slideshow over the full content width (responsive). Note that for
now a slideshow is only supported for photosets, groups and users and any other
parameters are ignored (NO sort or tags). To add some spacing above and below a
slideshow, modify your CSS or add some lines that contain a non breaking space:

&nbsp;
[flickr-photoset:id=72157634563269642,size=y]
&nbsp;


For all other sizes the following parameters can be used:

num : The number of photos to show.
tags : Flickr tags to filter on.
media : photos, videos or all.
heading : To suppress the album title.
sort : Date taken, posted, number of views, random or unsorted.
filter : Interesting or relevant. Only for user albums.
count : To suppress how many are available on Flickr.

Again, you'll find parameter examples, their use and default values at the
bottom of the text filter help on the 'Edit' page.
