The content of this file is based on the online documentation that can be found
at https://drupal.org/node/2170535
It is recommended to read it there, as it is more detailed.

NAME
====
Flickr
Project page at https://drupal.org/project/flickr

REQUIREMENTS
============
This module requires Drupal 7.X and a Flickr API key.

OVERVIEW
========
The Flickr module embeds images hosted on Flickr with a link to the
corresponding Flickr page.

- Flickr images can be displayed in blocks, within content or as fields.
- Open Flickr photos in Colorbox, Lightbox or alike.
- Show user/group photostreams and sets as responsive slideshows.
- Image caption with the Flickr title, date taken, where  and by who.
- Show the longer Flickr description on hover if it exists.

INSTALLATION AND CONFIGURATION
==============================
1.) Extract the download package in the '/sites/all/modules directory'.
2.) Enable the module in 'admin/modules'.
3.) Configure the API Key and settings at '/admin/config/media/flickr'.
4.) Allow permissions '/admin/people/permissions'.

SETTINGS
========
Settings are found at '/admin/config/media/flickr'. After changing many of the
settings below, it is often required to CLEAR THE SITE CACHE to have the changes
to take effect on existing content at '/admin/config/development/performance'.

API Key
-------
Get an API Key at https://www.flickr.com/services/apps/create/apply

API Shared Secret
-----------------
Default Flickr User ID
To use if in the block configuration no user is specified. Must be a valid
Flickr User ID, alias, username or email address. Emails or usernames (that might
change at any given time) are internally (in the variable) replaced with a
stable NSID (Flickr ID number). These are rendered in admin forms (settings or
block config) as Flickr usernames. 'Maria Emanuela' is human readable,
'43937662@N05' is not. Internal the module still uses the Flickr ID number as it
is more reliable.

Update interval
---------------
The refresh interval how often to check if cached Flickr API calls are up to
date. Defaults to 1 hour.

Limit API requests for random and popularity sort
-------------------------------------------------
Setting a lower number enhances performance but makes random results being less
spread between one another (not less random) and returns popular (most viewed on
Flickr) only for the n most recent. Minimum 20, maximum 500. If you use cache
warming you can set the maximum (see https://drupal.org/node/1576686).

Number of photos per photoset
-----------------------------
Defaults to 6.

Default size for photos in an album
-----------------------------------
A default Flickr size to use. This will be used when no size is specified, for
example [flickr-photoset:id=72157634563269642]. TAKE CARE, n (320px) and c
(800px) sizes are missing on many "older" Flickr images! Defaults to s: 75 px
square. Thanks to the default setting you can change the size of all images
without a specified size on the site in one go.

Use flickr.css
--------------
Uncheck to take care of the styling yourself in custom CSS.
Selected by default.

FLICKR INFO TO USE (field group)
--------------------------------
Minimum width to display a title caption
----------------------------------------
Small images have little space for a title caption. Replaces it with the text
"Flickr" that links to the photo page on Flickr to comply with their Guidelines.
Defaults to 100 px. Set it to 0 px to always include or 999 px to always
exclude.

The presence of a caption is solely reliant on the values of the configuration
fields:
- Minimum image width to display a title caption * (default: '100 px')
- Minimum image width to display date, location, photographer and optionally
  license info under the caption * (default: '150 px') (see point below)

The text 'Flickr' gets added as a caption that links to the correspondend Flickr
photo page if:
- clicking the image links to a bigger version of it, using lightbox/colorbox or
  not, AND
- the title caption that links to the Flickr photo page is suppressed (depending
on the size).

Setting a 'class' or 'rel' value in the 'overlay browser settings'
(colorbox/lightbox), even one that is not valid, always links the image to a
bigger version of it.

Minimum image width to display date, location, photographer and optionally
license info under the caption
--------------------------------------------------------------------------
Suppress extra info on small images. After saving the configuration clear the
cache.
Defaults to 150 px. Set it to 0 px to always include or 999 px to always
exclude.
Adds date, location and photographer info to the caption on images of a certain
width. The date is in the form of 'time ago'. The photographer's Real Name is
used, if not available the Username. In the caption it links to the user page on
Flickr. The license info is optional (see below).

License info in caption
-----------------------
Depending on 'Minimum image width' above. Checkbox (not selected by default).
Used is the nonintrusive icons font that can be found at
http://creativecommons.org/about/downloads. It links to the
corresponding Creative Commons human friendly info page. It is recommended to
download the cc-icons font, put it in the your theme folder or the Flickr module
folder and substitute the default used remote source that can be found in the
module's 'flickr.css' file. Just replace 'http://creative.../downloads/' with
the path to your theme folder or remove it completely if you have put it in the
Flickr module folder so that only the filename remains.

What horizontal inside spacing is applied on the caption? (padding/border)
--------------------------------------------------------------------------
See https://drupal.org/node/2174131#caption

Info to include when enlarging the image in Colorbox, Lightbox or alike
-----------------------------------------------------------------------
Usually this info is displayed under the enlarged image.
Checkboxes (multiple options can be selected).
- Title
- Date, location and photographer
- Description
- License info
All selected by default except for 'License info'. This info is concatenated
with '-' separators and added as the link 'title' attribute. HTML is stripped,
double quotes are removed (it goes into the title="[description]" attribute) and
special characters are decoded (&copy; turns into ©). If the title and
description are identical, only the title is used.

As a side note: The description is always included as the image 'title'
attribute (shows on hover). If the description is not available the title will
be used.

Extra links to Flickr maps
--------------------------
Include extra links to maps available for a user, group or set on Flickr.
Locations mentioned (if displayed) under individual images link to corresponding
Flickr user maps in any case, independent on the setting here.

Show a Flickr counter
--------------------
Shows how many photos are displayed out of the total number available for a
user, group, set or tags on Flickr. Can be overridden by the filter tag, eg.
[flickr-photoset:id=72157634563269642,count=false]

FILTER SETTINGS
---------------
Only if the submodule Flickr Filter is enabled.
See https://drupal.org/node/2171503#config.

BLOCK SETTINGS
--------------
Only if the submodule Flickr Block is enabled.
See https://drupal.org/node/2171249#config.

OVERLAY BROWSER SETTINGS (field group)
--------------------------------------
Colorbox, Lightbox (use the dev version) or alike. Leave these fields empty to
link directly to the Flickr photo page instead of opening the bigger version of
the image.  It also omits the caption in that case. This is only done to not
alter the behaviour on previous installs of the Flickr module.  The best way of
giving attribution is by using a full version of the caption (default settings +
license info).

To have captions, you must fill in the 'class' or 'rel' field. Even if you do
not intend to use an overlay browser, this is the condition to display a
caption. This way any sites upgrading the Flickr module do not experience a
change from the 'old' behaviour, suddenly having unexpected captions. If you
want captions but don't want to use an overlay browser, just enter for example
the name of your dog in one of the fields.

class
-----
Use 'colorbox' if you are using Colorbox. (https://drupal.org/project/colorbox)
With Lightbox you can leave it empty. (https://drupal.org/project/lightbox2)

rel
---
Use 'gallery-all' if you are using Colorbox. It can be anything you want,
really. As long there is something.
Use 'lightbox[gallery]' if you are using Lightbox2. The part inside the square
brackets can be anything you want but must be one word without spaces.

NOTE: With Lightbox if you select an 'Automatic image handling' for Flickr
images, you override the behaviour set here. If you don't want that, leave it
'Disabled'. (/admin/config/user-interface/lightbox2/automatic)

Image size to open
------------------
The image size to open in the overlay browser when clicking the image. Larger
sizes make navigating to next and previous pictures slower. TAKE CARE, n (320px)
and c (800px) sizes are missing on many "older" Flickr images!
Defaults to -: 500 px on longest side.

BLOCK SETTINGS (field group)
--------------------------------------
Only if the submodule Flickr Block is enabled.
See the README.txt there.

SIZES
=====
The size parameter can be one of the following:

Suffix: Label:  Size:
s Square  small square 75x75
t Thumbnail thumbnail, 100 on longest side
q Large Square  big square 150x150
m Small small, 240 on longest side
n Small 320 small, 320 on longest side
[none] Medium  medium, 500 on longest side
z Medium 640  medium 640, 640 on longest side
c Medium 800  medium 800,
b Large large, 1024 on longest side
o Original  original image, either a jpg, gif or png, depending on source format
x Flash Full featured responsive slideshow (for group, set and user IDs only)
y Non-Flash Basic responsive slideshow (for set and user IDs only)

Notes
-----
For square images ('s': 75px and 'q': 150px) no real width needs to be fetched,
giving it a performance advantage over other sizes. Recommended if you include
many images.

If the wrong size is applied, check if it exists on the Flickr photo page >
Actions > View all sizes.

The slideshow allows for videos to be played. Put the desired videos to show
together in a set.

RECOMMENDED
===========
If you use the Flickr Filter submodule, you might find the AutoFloat
module useful. See https://drupal.org/project/autofloat

Flickr module Style Guide. See https://drupal.org/node/2174131

TROUBLESHOOTING
===============
For more details, see https://www.drupal.org/node/2289785

Try clearing both your site (https://drupal.org/node/42055) and browser cache
(http://www.wikihow.com/Clear-Your-Browser's-Cache).
Use http://idgettr.com/ to find your Flickr user or group id.

BEFORE posting a support request related to configuration, check the necessary
settings in the demo at http://simplytest.me/project/demo_flickr/7.x-1.x
Complete the installation process there (just hit Save and continue on each
step). If at the end of the install process you get a white screen, just reload
the page.

Flickr error 100: Invalid API Key (Key has invalid format)
----------------------------------------------------------
Fill in some valid Flickr credentials at
admin/config/media/flickr.

Unexpected display problems occur
---------------------------------
It should be noted that the cascading stylesheets defined by modules are by
default loaded before theme CSS.See Drupal API:
http://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_add_css/7
Flickr module's style might be overwritten by the theme stylesheets. Copy and
paste the CSS code in the flickr.css file to the bottom of your theme's custom
CSS file or use this solution: http://k-it.ca/comment/14#comment-14

'Undefined index' error after upgrade from 7.x-1.0 to a later version
---------------------------------------------------------------------
Re-save your block settings. See https://drupal.org/node/2089575: Undefined
index error after upgrade.

Uninstalling Flickr Field - module is not selectable because Drupal says the
fields implemented by it are being used
----------------------------------------------------------------------------
First delete all Flickr fields in use on your content types at
admin/structure/types 'Manage fields'.
Then run cron at admin/reports/status/run-cron

MORE INFO
=========
The flickr module uses XML-RPC to connect to Flickr's API and retrieve photo
information. Flickr API Documentation: http://www.flickr.com/services/api

Other Flickr module specific info for developers can be found at
https://www.drupal.org/node/2289797
