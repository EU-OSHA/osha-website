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
