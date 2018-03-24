/**
 * @file
 * Plugin for inserting links with osha_file.
 */
(function ($) {
    tinymce.create('tinymce.plugins.osha_file', {
        init : function(ed, url) {
            // Register commands
            ed.addCommand('mceosha_file', function() {

                if (ed.dom.getAttrib(ed.selection.getNode(), 'class', '').indexOf('mceItem') != -1)
                    return;

                if (ed.callbackLookup) {
                    ed.callbackLookup.file_browser_callback='';
                }
                ed.settings['file_browser_callback']='imceImageBrowserFile';

                ed.windowManager.open({
                    file : url + '/file.htm',
                    width : 620 + parseInt(ed.getLang('advimage.delta_width', 0)),
                    height : 280 + parseInt(ed.getLang('advimage.delta_height', 0)),
                    inline : 1
                }, {
                    plugin_url : url
                });

            });

            // Register buttons
            ed.addButton('osha_file', {
                title : Drupal.t('File'),
                cmd : 'mceosha_file',
                image : url + '/images/icon_file.png'
            });

            // We need the real contextmenu in order to make this work.
            if (ed && ed.plugins.contextmenu) {
                // Contextmenu gets called - this is what we do.
                ed.plugins.contextmenu.onContextMenu.add(function(th, m, e, col) {
                    // Only if selected node is an link do this.
                    if (e.nodeName == 'A' || !col) {
                        // Remove all options from standard contextmenu.
                        m.removeAll();
                        th._menu.add({
                            title : Drupal.t('File'),
                            cmd : 'mceosha_file',
                            icon : 'osha_file'
                        });
                        //m.addSeparator();
                    }
                });
            }
        },

        getInfo : function() {
            return {
                longname : 'osha_file',
                version : tinymce.majorVersion + "." + tinymce.minorVersion
            };
        }
    });
    // Register plugin
    tinymce.PluginManager.add('osha_file', tinymce.plugins.osha_file);
})(jQuery);