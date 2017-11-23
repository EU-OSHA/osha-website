The content of this file is based on the online documentation that can be found
at https://drupal.org/node/2171299
It is recommended to read it there, as it is more detailed and illustrated.

NAME
====
Flickr Field
Part of the Flickr module. Project page at https://drupal.org/project/flickr

OVERVIEW
========
Add Flickr images or sets to content as fields:
- can be added to entities, usually nodes
- have several formatting options to use various sizes, including slideshows
- can be queried with the Views module.

There are two kind of module provided Flickr fields. Only the first type is used
for single Flickr photos. Both type of fields can be used for Flickr Photo Sets
but each in a different way.

Flickr Photo
------------
Store Flickr Photo or Photoset IDs and display the photos in nodes and Views.
Despite the name this field is used both for individual photos (using
'Item Type': 'Photo') as for complete sets of photos (using 'Item Type':
'Photoset'). The submodule Flickr Sets should be enabled to use sets in this
field.

Flickr Photo Set
----------------
Field for storing a reference to a Flickr photo set. It displays only the
primary representing image of a set or a slideshow of multiple images. To
display multiple photos from a photoset, use the Flickr Photo field type or use
the slideshow format.

Most interesting feature of this field is the slideshow. Both a full featured and
basic version exist. Both are responsive and adapt to the available space.

Full screen mode is supported, showing the largest available image that fits the
screen on a black background (the way that most professional photographers
prefer to showcase their work).

FIELD CONFIGURATION
===================
- Go to '/admin/structure/types'
- Click 'manage fields'
- Add new field > Flickr Photo or Flickr Photo Set (submodule Flickr Sets
  should be enabled to use sets in this field)
- Save field settings
- Configure as desired
- Save settings
Then:
- Go to '/admin/structure/types'
- Click 'manage display'
- Select the formatter for a Flickr field (a size)
- Save

NOTE:
For square images ('s': 75px and 'q': 150px) no real width needs to be fetched,
giving it a performance advantage over other sizes. Recommended if you include
many images.

FEEDS INTEGRATION
=================
If you have the feeds module enabled, you can export Flickr field data.
- Go to 'Mapping' (under 'Processor') for your particular feed.
- See and use the 3 new 'Target' options (named as your chosen field name with
  the targeted column (id, nsid and type) in brackets.

The options are as follows:
- id: This is the Flickr photo or set ID.
- nsid: This is the Flickr user ID.
- type: This is the type of Flickr field. Current options are 'photo_id' (for an
  individual photo) and 'id' (for a set).

Find an example csv file and feeds importer at:
https://www.drupal.org/node/2339189#comment-9160963
