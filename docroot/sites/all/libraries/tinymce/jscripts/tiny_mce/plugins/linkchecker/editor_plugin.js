/**
 * editor_plugin.js
 */

(function() {
    tinymce.create('tinymce.plugins.Linkchecker', {
        id : null,

        init : function (ed, url) {
            var t = this;
            ed.onInit.add(function (ed) {
                t._update(ed);
            });
        },

        _update : function (ed) {
            var t = this;
            if (typeof(Drupal.settings.osha_linkchecker) != "undefined") {
                var tx = ed.getContent();
                for (var i = 0; i < Drupal.settings.osha_linkchecker.urls.length; i++) {
                    var url = Drupal.settings.osha_linkchecker.urls[i];
                    if (tx.indexOf('href="' + url) > 0) {
                        tx = tx.replace('href="' + url, 'data-linkchecker="" href="' + url);
                    }
                    ed.setContent(tx);
                }
            }
        },

        getInfo: function () {
            return {
                longname : 'Linkchecker',
                version : tinymce.majorVersion + "." + tinymce.minorVersion
            };
        }
    });

    tinymce.PluginManager.add('linkchecker', tinymce.plugins.Linkchecker);
})();
