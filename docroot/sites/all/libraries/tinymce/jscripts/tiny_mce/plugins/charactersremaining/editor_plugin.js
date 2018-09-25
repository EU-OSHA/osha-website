/**
 * editor_plugin.js
 */

(function() {
    tinymce.create('tinymce.plugins.CharactersRemaining', {
        id : null,

        init : function(ed, url) {
            var t = this;
            t.id = ed.id + '-characters-remaining-max-length';
            t.charLimit = ed.getElement().dataset.maxLength;
            if ((t.charLimit == 'undefined')) {
                t.charLimit = 0;
            }

            ed.onPostRender.add(function(ed, cm) {
                var row;
                if ((t.charLimit) && (row = tinymce.DOM.get(ed.id + '_path_row'))) {
                    tinymce.DOM.add(row.parentNode, 'div', {'style': 'float: right'}, '<div class="danger hidden" id="' + t.id + '-limit">' + ed.getLang('charactersremaining.maxlimitreached', 'Max limit reached!') + '</div><div id="' + t.id + '-left">' + ed.getLang('charactersremaining.charsleft', 'Chars left: ') + '<span id="' + t.id + '">0</span></div>');
                }
            });

            ed.onInit.add(function(ed) {
                ed.selection.onSetContent.add(function() {
                    t._update(ed);
                });
                t._update(ed);
            });

            ed.onPaste.add(function(ed, e) {
                var content = ((e.originalEvent || e).clipboardData || window.clipboardData).getData('Text');
                var cl = t.charLimit - t._getCharCount(ed) - content.replace(/<.[^<>]*?>/g, '').replace(/&nbsp;|&#160;/gi, '').length;
                if (cl <= 0) {
                    alert(ed.getLang('charactersremaining.maxlimitreached', 'Max limit reached!'));
                    tinymce.dom.Event.cancel(e);
                }
            } );

            ed.onKeyPress.add(function(ed, e) {
                t._checkpaste(t, ed, e);
            } );

            ed.onKeyUp.add(function(ed, e) {
                tc = t._getCharCount(ed);
                if (tc > t.charLimit) {
                    tinymce.dom.Event.cancel(e);
                }
                t._update(ed);
            });
        },

        _checkpaste : function(t, ed, e) {
            var cl = t.charLimit - t._getCharCount(ed);
            if (cl <= 0) {
                tinymce.dom.Event.cancel(e);
                tinymce.DOM.addClass(t.id + '-left', "hidden");
                tinymce.DOM.removeClass(t.id + '-limit', "hidden");
            }
        },

        _update : function(ed) {
            var t = this;

            setTimeout(function() {
                if (!ed.destroyed) {

					if (t.charLimit) {
                        var tc = t._getCharCount(ed);
                        var cl = t.charLimit -  tc;
                        if (cl <= 0) {
                            tinymce.DOM.addClass(t.id + '-left', "hidden");
                            tinymce.DOM.removeClass(t.id + '-limit', "hidden");
                        } else {
                            tinymce.DOM.setHTML(t.id, cl.toString());
                            tinymce.DOM.removeClass(t.id + '-left', "hidden");
                            tinymce.DOM.addClass(t.id + '-limit', "hidden");
                        }
					}
                    setTimeout(function() {}, 1000);
                }
            }, 1);
        },

        _getCharCount: function(ed) {
            var tx = ed.getContent({format: 'raw'});
            if (tx) {
                tx = tx.replace(/<.[^<>]*?>/g, '').replace(/&#160;|&nbsp;/gi, '');
            }
            return tx.length;
        },

        getInfo: function() {
            return {
                longname : 'Characters Remaining',
                version : tinymce.majorVersion + "." + tinymce.minorVersion
            };
        }
    });

    tinymce.PluginManager.add('charactersremaining', tinymce.plugins.CharactersRemaining);
})();
