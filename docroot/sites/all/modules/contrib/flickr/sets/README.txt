The content of this file is based on the online documentation that can be found
at https://drupal.org/node/2226579

Sets are a convenient way to organize your images. Currently only 'sets' allow
for display as a slideshow with the Flickr module. To generate an album of
images, besides photosets, tags can be used, in combination with a specific user
(also from node author) or group. Tags have the advantage that they can be taken
from the taxonomy terms attached to a node, to create dynamic, context sensitive
albums.

To use Flickr Sets in user profiles, configure a Flickr identifier specified on
the user account at user/[uid]/edit. Of course some albums must be present on
the correspondent Flickr account. If you want other users to see those sets,
give them the permission "View Flickr photos on user profiles" at
admin/people/permissions#module-flickr. After that, browse to
www.yoursite.com/flickr/[uid]/sets.

A photo (or video) can make part of more than one set, without the need of
duplicating it. Just go to https://www.flickr.com/photos/organize, click 'Add to
album' and drag your images into it.

Once that's done you can display the set as a thumbnail gallery or a slideshow
in:
- the node body using Flickr Filter
- a block using Flickr Block
- a field using Flickr Field.

Disabling the Flickr Sets submodule: What happens?
==================================================
Only the first image of a set will be displayed in some blocks, in the photoset
filter tag and the Flickr photo field. Those will link to the set on Flickr when
clicking on them.

Flickr Blocks affected
----------------------
- User recent photosets
- Recent photosets by user
All the others are unaffected.

Flickr Filter tags affected
---------------------------
Only photoset tags like [flickr-photoset:id=72157634563269642,size=t]
are affected, but not for the sizes x and y (slideshow).

Flickr Field affected
---------------------
The Flickr Field 'photo' is only affected for the 'Item Type': 'Photoset'.
The Flickr Field 'photoset' always displays only the primary image (except for
slideshows), thus is unaffected.

Sets for photos from other Flickr users
=======================================
That is what a 'Gallery' is for. So, all the nice photos of other that you want
in an embedded album, you put them in a gallery on Flickr. You can put the
photos of different Flickr users in the same gallery, but don't put your own
photos inside.

If you always combine photos of the same users, including yourself, and you have
their consent, consider creating a group on Flickr, for example for the website
of the local hockey club. That way they can add photos themselves for which you
can then create e.g. blog posts on the site, "Our victorious match on Easter".
Flickr groups have many admin tools to manage and control them.
