jQuery(document).ready(function() {
    ZeroClipboard.config({
        moviePath: '/sites/all/libraries/zeroclipboard/ZeroClipboard.swf',
        forceEnhancedClipboard: true
    });

    var client = new ZeroClipboard( jQuery("#edit-short-messages-clipboard") );

    client.on( 'load', function(client) {
        // Initial load
        applyCSS(client);
        // Copy request
        client.on( 'datarequested', function(client) {
            applyCSS(client);
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

/**
 * Apply CSS to editor content
 */
function applyCSS(client){
    var iframeContent = jQuery('#edit-short-messages-content-value_ifr').contents();

    //convert relative to absolute url
    iframeContent.find('a').each(function(){
        jQuery(this).attr('href', jQuery(this).attr('data-mce-href'));
    });

    //add css styles
    iframeContent.find('.views-field-field-press-contact-job-title').find('div').css({'font-size': '0.9em', 'font-weight': 'bold', 'margin-bottom':'5px'});
    iframeContent.find('.views-field-title').find('a').css({'color': '#003399', 'font-size': '0.9em', 'text-decoration': 'none'});
    iframeContent.find('.views-field-field-press-contact-phone').find('div').css({'font-size': '0.9em'});
    iframeContent.find('.views-field-field-press-contact-email').find('a').css({'color': '#003399', 'font-size': '0.9em', 'text-decoration': 'none', 'font-weight': 'bold'});
    iframeContent.find('.view-footer').css({'margin-top':'4px'});
    iframeContent.find('.view-footer').find('a').css({'color': '#003399', 'text-decoration': 'none', 'font-weight': 'bold', 'margin-left':'4px'});
    iframeContent.find('.node').css({'font-size': '14px'});
    iframeContent.find('.node').find('a').css({'color': '#039', 'text-decoration': 'none', 'border-bottom': '1px solid #DC2F82'});
    iframeContent.find('div').css({'margin-top': '0.5em', 'margin-bottom': '0.5em'});
    iframeContent.find('.node').find('h2').find('a').css({'color': '#039', 'text-decoration': 'none', 'font-weight': 'bold', 'font-size': '1.1em', 'line-height': '1.1em', 'border':0});
    iframeContent.find('.field-name-field-pr-notes-to-editor').find('.field-label').css({'font-weight': 'bold', 'margin-top': '1.5em'});
    iframeContent.find('p').css({'line-height': '1.5em', 'margin': '0em'});
    iframeContent.find('.node-note-to-editor h2, .node-infographic h2').css({'margin': '0px', 'display':'none'});
    iframeContent.find('.field-name-field-pr-notes-to-editor span').css({'float': 'left', 'margin-top': '2px', 'padding-right': '0.3em'});
    iframeContent.find('.node-infographic h1').css({'font-size': '14px', 'line-height': '1.5em'});
    //get iframe body
    var editorContent = iframeContent.find("body").html();
    client.setText(editorContent);
}