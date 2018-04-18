/**
 * @file
 * Plugin for inserting links with osha_image.
 */
(function ($) {
    tinymce.create('tinymce.plugins.osha_image', {
        init : function(ed, url) {
            // Register commands
            ed.addCommand('mceosha_image', function() {

                if (ed.dom.getAttrib(ed.selection.getNode(), 'class', '').indexOf('mceItem') != -1)
                    return;

                if (ed.callbackLookup) {
                    ed.callbackLookup.file_browser_callback='';
                }
                ed.settings['file_browser_callback']='imceImageBrowserImage';

                ed.windowManager.open({
                    file : url + '/image.htm',
                    width : 620 + parseInt(ed.getLang('advimage.delta_width', 0)),
                    height : 380 + parseInt(ed.getLang('advimage.delta_height', 0)),
                    inline : 1
                }, {
                    plugin_url : url
                });

            });

            // Register buttons
            ed.addButton('osha_image', {
                title : Drupal.t('Image'),
                cmd : 'mceosha_image'

            });

            // We need the real contextmenu in order to make this work.
            if (ed && ed.plugins.contextmenu) {
                // Contextmenu gets called - this is what we do.
                ed.plugins.contextmenu.onContextMenu.add(function(th, m, e, col) {
                    // Only if selected node is an link do this.
                    if (e.nodeName == 'IMG' || !col) {
                        // Remove all options from standard contextmenu.
                        m.removeAll();
                        th._menu.add({
                            title : Drupal.t('Image'),
                            cmd : 'mceosha_image',
                            icon : 'osha_image'
                        });
                        //m.addSeparator();
                    }
                });
            }
        },

        getInfo : function() {
            return {
                longname : 'osha_image',
                version : tinymce.majorVersion + "." + tinymce.minorVersion
            };
        }
    });
    // Register plugin
    tinymce.PluginManager.add('osha_image', tinymce.plugins.osha_image);
})(jQuery);