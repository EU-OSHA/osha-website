The content of this file is based on the online documentation that can be found
at https://www.drupal.org/node/2174131. It is recommended to read it there.

Extra configuration options: Rounded corners, shadow, border, emphasize on
hover.

Configuration
=============
At 'admin/config/media/flickr' in the section 'STYLING (CSS RELATED)':

Use flickr.css
--------------
Checkbox.
Uncheck to take care of the styling yourself in custom CSS.
If you use Flickr Filter, you might find the AutoFloat module useful
(https://www.drupal.org/project/autofloat).

Image styles
------------
Checkboxes.
- Rounded corners
- Shadow
- Border

Apply the image style also on the caption?
------------------------------------------
Radio buttons.
- No
- Yes, separate from the image
- Yes, wrapped around the image and caption ("Polaroid" effect if applied with a
  border)

Disable the above styles on a caption with only the text 'Flickr' (simple link)
-------------------------------------------------------------------------------
Checkbox.

Emphasize the image on hover?
-----------------------------
Radio buttons.
- No
- Enlarge slightly (includes the caption)
- Enlarge (image only) (*)
- Zoom (*)
- Magnifier icon

(*): The 'Zoom' and 'Enlarge' styles use bigger images to maintain the
resolution. This has a slight performance impact and the size 'big square' (q)
is not square but 150px on the longest side to avoid distortion on older
browsers.


Suppress Flickr block titles
============================
You can suppress the block titles with CSS. For example for the block 'Flickr: User photos with specific tags' ($delta=11), it would look like:

#block-flickr-11 .flickr-album-heading {
  display: none;
}


Image & album HTML structure
============================
See https://www.drupal.org/node/2289797.
