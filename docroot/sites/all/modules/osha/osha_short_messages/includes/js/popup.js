jQuery(document).ready(function() {
    //create dialog window to access the iframe
    displayDialog();
    jQuery( "#preview_message" ).dialog('close');
});

/**
 * Populate dialog window with the editor content
 * The HTML is inserted in an iframe to not use the site css styles
 */
function displayDialog(){

    var editorContent = jQuery('#edit-short-messages-content-value_ifr').contents().find("body").html();

    var $frm = jQuery("#preview_content");
    var $doc = $frm[0].contentWindow ? $frm[0].contentWindow.document : $frm[0].contentDocument;
    var $body = jQuery($doc.body);
    $body.html(''); // clear iFrame contents <- I'm using this...
    $body.append(editorContent); // use this to write something into the iFrame

    //display dialog
    jQuery( "#preview_message" ).dialog({
        width: '850px'
    });

    //set iframe height
    setIframeHeight(jQuery("#preview_content").get(0));
}

/**
 * Adjust height to match content
 * @param iframe
 */
function setIframeHeight(iframe) {
    if (iframe) {
        var iframeWin = iframe.contentWindow || iframe.contentDocument.parentWindow;
        if (iframeWin.document.body) {
            iframe.height = iframeWin.document.documentElement.scrollHeight || iframeWin.document.body.scrollHeight;
        }
    }
};