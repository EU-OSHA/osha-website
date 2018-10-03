/**
 * editor_plugin.js
 */

(function() {
    tinymce.create('tinymce.plugins.CharactersRemaining', {
        id : null,

        init : function(ed, url) {
            var t = this;
            t.char_id = ed.id + '-characters-remaining-max-length';
            t.word_id = ed.id + '-words-remaining-max-length';

            t.charLimit = ed.getElement().dataset.maxChars;
            t.wordLimit = ed.getElement().dataset.maxWords;

            if ((t.charLimit == 'undefined')) {
                t.charLimit = 0;
            }
            if ((t.wordLimit == 'undefined')) {
                t.wordLimit = 0;
            }

            ed.onPostRender.add(function(ed, cm) {
                var row;
                if ((t.charLimit) && (row = tinymce.DOM.get(ed.id + '_path_row'))) {
                    tinymce.DOM.add(row.parentNode, 'div', {'style': 'float: right'},
                        '<div class="danger hidden" id="' + t.char_id + '-limit">'
                        + ed.getLang('charactersremaining.maxlimitreached', 'Max limit reached!')
                        + '</div><div id="' + t.char_id + '-left">'
                        + ed.getLang('charactersremaining.charsleft', 'Chars left: ')
                        + '<span id="' + t.char_id + '">0</span></div>');
                }
                if ((t.wordLimit) && (row = tinymce.DOM.get(ed.id + '_path_row'))) {
                    tinymce.DOM.add(row.parentNode, 'div', {'style': 'float: right'},
                        '<div class="danger hidden" id="' + t.word_id + '-limit">'
                        + ed.getLang('wordactersremaining.maxlimitreached', 'Max limit reached!')
                        + '</div><div id="' + t.word_id + '-left">'
                        + ed.getLang('wordactersremaining.wordsleft', 'Words left: ')
                        + '<span id="' + t.word_id + '">0</span></div>');
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

                var char_left = t.charLimit - t._getCharCount(ed) - t._calcCharCount(content);// content.replace(/<.[^<>]*?>/g, '').replace(/&nbsp;|&#160;/gi, '').length;
                if (char_left <= 0) {
                    alert(ed.getLang('charactersremaining.maxlimitreached', 'Max chars limit reached!'));
                    tinymce.dom.Event.cancel(e);
                }

                var words = t._getWordCount(ed);
                var word_left = t.wordLimit - words - t._calcWordCount(content);

                if (word_left <= 0) {
                    alert(ed.getLang('wordactersremaining.maxlimitreached', 'Max words limit reached!'));
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
                tc = t._getWordCount(ed);
                if (tc > t.wordLimit) {
                    tinymce.dom.Event.cancel(e);
                }
                t._update(ed);
            });
        },

        _checkpaste : function(t, ed, e) {
            var char_left = t.charLimit - t._getCharCount(ed);
            if (char_left <= 0) {
                tinymce.dom.Event.cancel(e);
                tinymce.DOM.addClass(t.char_id + '-left', "hidden");
                tinymce.DOM.removeClass(t.char_id + '-limit', "hidden");
            }
            var word_left = t.wordLimit - t._getWordCount(ed);
            if (word_left <= 0) {
                tinymce.dom.Event.cancel(e);
                tinymce.DOM.addClass(t.word_id + '-left', "hidden");
                tinymce.DOM.removeClass(t.word_id + '-limit', "hidden");
            }
        },

        _update : function(ed) {
            var t = this;

            setTimeout(function() {
                if (!ed.destroyed) {

                    if (t.wordLimit) {
                        var word_left = t.wordLimit -  t._getWordCount(ed);
                        if (word_left <= 0) {
                            tinymce.DOM.addClass(t.word_id + '-left', "hidden");
                            tinymce.DOM.removeClass(t.word_id + '-limit', "hidden");
                        } else {

                            tinymce.DOM.setHTML(t.word_id, word_left.toString());
                            tinymce.DOM.removeClass(t.word_id + '-left', "hidden");
                            tinymce.DOM.addClass(t.word_id + '-limit', "hidden");
                        }
                    }
					if (t.charLimit) {
                        var tc = t._getCharCount(ed);
                        var char_left = t.charLimit -  tc;
                        if (char_left <= 0) {
                            tinymce.DOM.addClass(t.char_id + '-left', "hidden");
                            tinymce.DOM.removeClass(t.char_id + '-limit', "hidden");
                        } else {
                            tinymce.DOM.setHTML(t.char_id, char_left.toString());
                            tinymce.DOM.removeClass(t.char_id + '-left', "hidden");
                            tinymce.DOM.addClass(t.char_id + '-limit', "hidden");
                        }
					}
                    setTimeout(function() {}, 1000);
                }
            }, 1);
        },

        _calcWordCount: function(tx) {
            if (tx) {
                words = tx.split(" ")
                words = words.filter(function(item) {
                    return item.length > 0
                });
                return words.length;
            }
            return 0;
        },

        _getWordCount: function(ed) {

            var tx = ed.getContent({format: 'raw'});
            if (tx) {
                tx = tx.replace(/<br>/gi, ' ');
                tx = tx.replace(/<br \/>/gi, ' ');
                tx = tx.replace(/ &nbsp;/gi, ' ');
                tx = tx.replace(/<.[^<>]*?>/g, '').replace(/&#160;|&nbsp;/gi, '');
            }
            return this._calcWordCount(tx);
        },

        _calcCharCount: function(tx) {
            if (tx) {
                tx = tx.replace(/<.[^<>]*?>/g, '').replace(/&#160;|&nbsp;/gi, '');
            }
            return tx.length;
        },

        _getCharCount: function(ed) {
            var tx = ed.getContent({format: 'raw'});
            return this._calcCharCount(tx)
        },

        getInfo: function() {
            return {
                longname : 'Characters/Words Remaining',
                version : tinymce.majorVersion + "." + tinymce.minorVersion
            };
        }
    });

    tinymce.PluginManager.add('charactersremaining', tinymce.plugins.CharactersRemaining);
})();
