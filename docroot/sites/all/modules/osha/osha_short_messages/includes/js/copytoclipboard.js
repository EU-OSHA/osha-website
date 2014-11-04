jQuery(document).ready(function() {
    ZeroClipboard.config({
        moviePath: '/sites/all/libraries/zeroclipboard/ZeroClipboard.swf',
        forceEnhancedClipboard: true
    });

    var client = new ZeroClipboard( jQuery("#edit-short-messages-clipboard") );

    client.on( 'load', function(client) {

        client.on( 'datarequested', function(client) {
            var editorContent = jQuery('#edit-short-messages-content-value_ifr').contents().find("body").html();
            client.setText(editorContent);
        });

        // callback triggered on successful copying
        client.on( 'complete', function(client, args) {
            jQuery("<div>Copied HTML to clipboard</div>").dialog();
        });
    });

    // In case of error - such as Flash not being available
    client.on( 'wrongflash noflash', function() {
        ZeroClipboard.destroy();
    } );
});