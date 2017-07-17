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

There are several blocks that show the Flickr photos of a corresponding node
author 'dynamically' and appear on posts written by the user and on their user
profile pages. To avoid that, change the block settings to exclude 'node/*'
pages or show them only on 'user/*' pages.

Of course you can do it also the other way around to show a block only on a node
page. You can fine-grain it even more by selecting only a certain content type
you want to show them on, for example blog posts.

- Node author favorites (what they like from others, but all together)
  optionally corresponding with a node's taxonomy term
- Node author gallery photos (arbitrary selection by author of other's photos)
  optionally with gallery title as term from node
- Node author photos optionally corresponding with a node's taxonomy term,
  location and/or date field
- Node author recent photosets

The node author has to have permission to specify a Flickr ID on their own
account (admin/people/permissions#module-flickr).

The block visibility setting for the 'Node author' blocks are not only
restricted by the sitebuilder in the block configuration but also by the module.
The block gets displayed when the first argument of the path is 'user' or 'node'
and a specific uid is available.

Furthermore several sitewide blocks are available. A user, photoset, gallery or
group needs to be specified in the block configuration.

- Favorites corresponding with a node's taxonomy term
- Group photos corresponding with a node's taxonomy term, location and/or date
  field
- Set photos corresponding with a node's taxonomy term
- User photos corresponding with a node's taxonomy term, location and/or date
  field
- User photos with specific tags
- User recent photosets

INSTALLATION / UPGRADING
========================
To have dynamic Flickr Blocks that use a node's:
- taxonomy terms to grab identical tagged photos from Flickr
- date fields to grab photos taken in the period of a node date
- location or geofields to grab photos taken near the location of a node

it is recommended to enable before installation or upgrade of the sub-module
Flickr Block:
- the core Taxonomy module. It will create a dedicated 'Flickr tags' vocabulary
  and a preconfigured term reference field. This is optional as any free tagging
  vocabulary can be used, but convenient as it saves some configuration.
- the Date Popup module (sub-module of Date). It will create a dedicated 'Flickr
  date taken' field on nodes.
- the Geofield module. It will create a dedicated 'Flickr location' field on
  nodes (latitude/longitude).

To avoid the above mentioned 'smart install':
- disable the mentioned modules before install of Flickr Block (first time
  enable or after uninstall)
OR
- enable first the Flickr main module and unselect the 'smart install' checkbox
  at admin/config/media/flickr under 'Block options', then install Flickr Block.


BLOCK CONFIGURATION
===================
Fields in the block settings that apply on all blocks.
======================================================
Block title
-----------
This is an extra block title that normally stays empty as a title is already
added that shows info about e.g. the photo order, the tags used to filter on,
the album title, location, date range and Flickr user. You can suppress this
title with CSS, e.g for the 'Flickr: User photos with specific tags' block
($delta=11):

#block-flickr-11 .flickr-album-heading {
  display: none;
}

Show n photos (field group 'Display')
-------------------------------------
The block will display this many photos.

Size of photos (field group 'Display')
--------------------------------------
Select the size of photos you'd like to display in the block.
NOTE:
For square images ('s': 75px and 'q': 150px) no real width needs to be fetched,
giving it a slight performance advantage over other sizes. Recommended if you
include many images.

Use size=x for a slideshow over the full region width (responsive). Size=y
for a basic version.

Minimum image width to display a title caption (field group 'Display')
----------------------------------------------------------------------
Small images have liitle space for a title caption. Replace it with the text
'Flickr' that links to the photo page on Flickr to comply with their Guidelines.
Set it to '0 px' to always include or '999 px' to always exclude. To give proper
attribution this should be included (space allowing).

Minimum image width to display date, location, photographer and optionally
license info under the caption (field group 'Display')
------------------------------------------------------
Suppress extra info on small images. Set it to '0 px' to always include or '999
px' to always exclude. To give proper attribution this should be included (space
allowing).

Media type (field group 'Filter / sort order')
----------------------------------------------
- all
- photos (default)
- videos

Note that for videos a still image representing the video is shown. If you use
Colorbox it can be played with the possibility to toggle to fullscreen. See
https://drupal.org/node/2226579#video.

All 'User' and 'Group' blocks.
==============================
Flickr User or Group ID
-----------------------
A valid Flickr User ID, alias, username or email address. If this is left blank,
the site's default user will be used if set. Emails or usernames (that might
change at any given time) are internally (in the variable) replaced with a
stable NSID (Flickr ID number). These are rendered in this field as Flickr
usernames. 'Maria Emanuela' is human readable, '43937662@N05' is not. Internal
the module still uses the Flickr ID number as it is more reliable.

For groups the ID (number) or alias can be used.

All 'corresponding with a node's taxonomy term' blocks.
=======================================================
Flickr tags as node taxonomy terms (choose a vocabulary to use) (field group
'Filter / sort order')
----------------------
Limit the Flickr images to those that have a Flickr tag identical to the terms
found for the node on the page the block is displayed on of a specific
vocabulary. Case insensitive, matches any tag, for photosets even partial.
Multiple tags for groups will only query the last 500 photos on Flickr (slowest
API request). For user blocks the Flickr account of the node author will be
queried. Flickr removes spaces from multi word tags (e.g. 'beach trip' becomes
'beachtrip'). Multi word tags in Drupal can be used as spaces are stripped to
make a Flickr request. For your content type, adjust the Help text of the used
taxonomy field accordingly (e.g. at
admin/structure/types/manage/article/fields/field_tags). The recommended widget
type is Autocomplete term widget (tagging) with an unlimited number of values.
If taxonomy was active at the moment of install, a vocabulary Flickr tags is
already configured right by default. You should find Flickr tags as a Term
reference field on your content type. It works out-of-the-box. If not on a node
page, all photos will be displayed. To avoid this set the visibility settings
below to Only the listed pages specified as node/*. Note that if you add this
term reference field to user profiles at admin/config/people/accounts/fields it
will filter additionally on it for user blocks. E.g. a user can set individually
that from their account only photos tagged 'website' should be used to embed,
independent from other used tags. Does apply only on user blocks, except for
favorites.

Checkbox: Extend to search for matching terms also in the Flickr photo title and
description besides Flickr tags. This limits the tag mode below to 'any' (OR).
(field group 'Filter / sort order')
-----------------------------------
Shows more results if true.

Radios: Tag mode (field group 'Filter / sort order')
----------------------------------------------------
- Any (OR)
- All (AND)
- All (AND) for public searches, any (OR) if a Flickr user ID is known.
Either 'any' for an OR operator between tags, 'all' for an AND operator or
depending on the context.

All 'corresponding with a node's location and/or date field' blocks.
====================================================================
Location or geofield (choose a field machine name to use)
(field group 'Filter / sort order')
-----------------------------------
Limit the Flickr images to those that have a geo location near to the geofield
found for the node on the page the block is displayed on. If not on a node page,
all photos will be displayed. To avoid this set the visibility settings below to
Only the listed pages specified as node/*.

Date field (choose a field machine name to use)
(field group 'Filter / sort order')
-----------------------------------
Limit the Flickr images to those that are taken on or between the dates attached
to the node on the page the block is displayed on. If not on a node page, all
photos will be displayed. To avoid this set the visibility settings below to
Only the listed pages specified as node/*.

Site wide block settings
========================
Generic block configuration settings can be found in an own section at
admin/config/media/flickr. Most options are only available if the sub-module
Flickr Block is enabled.

BLOCK SETTINGS (field group)
----------------------------

Smart install of Flickr Block
-----------------------------
A checkbox (default ON). Disabled after enabling Flickr Block.
On install of Flickr Block auto create Flickr taxonomy, date and geo fields on
all node types to grab Flickr photos related to the node on the same page as a
Flickr block based on tags, a date or a location. Enable Taxonomy (core), Date
(including date_popup) and Geofield before enabling Flickr Block for the first
time (or uninstall it first).

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

Number of photos per set
------------------------
How many photos display per set on blocks that display multiple photosets.

Node author blocks
==================
You find instructions targeted to editors that don't have block administer
permissions at https://drupal.org/node/2279003#block. They can make use of the
'Node author' blocks to show photos of their Flickr account that have Flickr
tags similar to taxonomy terms they attach to a node they write. This way they
are able to add matching Flickr photos with their posts without the hassle of
uploading them on the site. Remember to give site editors also the permission to
specify a Flickr identifier on their account.

A Flickr Block inside the node body
===================================
Use Block Inject to put a Flickr Block inside your node body.

Create new Flickr blocks
========================
You can create new Flickr blocks also through admin/structure/block/add, using
the Text format that contains the Flickr Filter. See
https://www.drupal.org/node/2171503#blocks.
