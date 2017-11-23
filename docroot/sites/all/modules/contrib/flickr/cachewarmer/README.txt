The content of this file is based on the online documentation that can be found
at https://www.drupal.org/node/2490126. It is recommended to read it there.

Rebuilds the page cache after cron runs for selected content types also known as
cache warming. It avoids long page loads for the first visitor after a cron run.
See https://www.drupal.org/node/1576686/. Feel free to use the method there
instead of this sub-module. Either way works but don't use them together.

The server virtually visits all nodes of selected content types to ensure the
cache of these pages is rebuild after a cron run to avoid long page loads for a
real visitor. It can be limited to selected content types at
admin/config/media/flickr. The connection method automatically falls back to
cURL if stream_socket_client fails or is not available. Note that it uses the
HEAD method where the server MUST NOT return a message-body in the response.
Drupal will rebuild the full page's cache anyway.

Set the 'Minimum cache lifetime' to 'none' at
admin/config/development/performance.

It is recommended to set the cron interval to something sensible. By default it
is set to 3 hours at admin/config/system/cron. For many cases 'once a day' or
even 'once a week' is more than enough. New or edited content will refresh
anyway after hitting the 'Save' button.
