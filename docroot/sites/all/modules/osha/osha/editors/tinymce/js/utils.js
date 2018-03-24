function openOshaBrowser(cb, img_id, target_form_element, type, option) {
    tinyMCEPopup.editor.settings['file_browser_callback'] = cb;
    var img = document.getElementById(img_id);

    if (img.className != "mceButtonDisabled") {

        tinyMCEPopup.restoreSelection();
        tinyMCEPopup.editor.execCallback("file_browser_callback",target_form_element, document.getElementById(target_form_element).value, type, window)
    }
}

function getOshaBrowserHTML(cb, id, target_form_element, type, prefix) {
    var option = prefix + "_" + type + "_browser_callback_"+cb, cb, html;
    if (!cb)
        return "";
    html = "";
    html += '<a id="' + id + '_link" href="javascript:openOshaBrowser(\''+cb+'\',\'' + id + '\',\'' + target_form_element + '\', \'' + type + '\',\'' + option + '\');" onmousedown="return false;" class="browse">';
    html += '<span id="' + id + '" title="' + tinyMCEPopup.getLang('browse') + '">&nbsp;</span></a>';

    return html;
}
