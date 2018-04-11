var FileDialog = {
	preInit : function() {
		var url;

		tinyMCEPopup.requireLangPack();

		if (url = tinyMCEPopup.getParam("external_image_list_url"))
			document.write('<script language="javascript" type="text/javascript" src="' + tinyMCEPopup.editor.documentBaseURI.toAbsolute(url) + '"></script>');
	},

	init : function() {
		var f = document.forms[0], ed = tinyMCEPopup.editor;

        document.getElementById('srcbrowsercontainer').innerHTML = getOshaBrowserHTML('imceImageBrowserFile','srcbrowser','href','image','theme_advanced_image');

		if (isVisible('srcbrowser'))
			document.getElementById('href').style.width = '180px';

		e = ed.selection.getNode();

		this.fillFileList('image_list', tinyMCEPopup.getParam('external_image_list', 'tinyMCEImageList'));

		if (e.nodeName == 'A') {
			f.href.value = ed.dom.getAttrib(e, 'href');
			f.alt.value = e.textContent;
			f.insert.value = ed.getLang('update');
			this.styleVal = ed.dom.getAttrib(e, 'style');
			selectByValue(f, 'image_list', f.href.value);
			selectByValue(f, 'align', this.getAttrib(e, 'align'));
			this.updateStyle();
		}
	},

	fillFileList : function(id, l) {
		var dom = tinyMCEPopup.dom, lst = dom.get(id), v, cl;

		l = typeof(l) === 'function' ? l() : window[l];

		if (l && l.length > 0) {
			lst.options[lst.options.length] = new Option('', '');

			tinymce.each(l, function(o) {
				lst.options[lst.options.length] = new Option(o[0], o[1]);
			});
		} else
			dom.remove(dom.getParent(id, 'tr'));
	},

	update : function() {
		var f = document.forms[0], nl = f.elements, ed = tinyMCEPopup.editor, args = {}, el;

		tinyMCEPopup.restoreSelection();

		if (f.href.value === '') {
			if (ed.selection.getNode().nodeName == 'A') {
				ed.dom.remove(ed.selection.getNode());
				ed.execCommand('mceRepaint');
			}

			tinyMCEPopup.close();
			return;
		}

        var content = f.alt.value;
		tinymce.extend(args, {
            href : f.href.value.replace(/ /g, '%20'),
		});

		el = ed.selection.getNode();

		if (el && el.nodeName == 'A') {
			ed.dom.setAttribs(el, args);
            el.textContent = content;
			tinyMCEPopup.editor.execCommand('mceRepaint');
			tinyMCEPopup.editor.focus();
		} else {
			tinymce.each(args, function(value, name) {
				if (value === "") {
					delete args[name];
				}
			});

			ed.execCommand('mceInsertContent', false, tinyMCEPopup.editor.dom.createHTML('a', args, content), {skip_undo : 1});
			ed.undoManager.add();
		}

		tinyMCEPopup.close();
	},

	updateStyle : function() {
		var dom = tinyMCEPopup.dom, st = {}, v, f = document.forms[0];

		if (tinyMCEPopup.editor.settings.inline_styles) {
			tinymce.each(tinyMCEPopup.dom.parseStyle(this.styleVal), function(value, key) {
				st[key] = value;
			});

			// Merge
			st = tinyMCEPopup.dom.parseStyle(dom.serializeStyle(st), 'a');
			this.styleVal = dom.serializeStyle(st, 'a');
		}
	},

	getAttrib : function(e, at) {
		var ed = tinyMCEPopup.editor, dom = ed.dom, v, v2;

        if (v = dom.getAttrib(e, at))
            return v;
		return '';
	},

	getImageData : function() {
	}
};

FileDialog.preInit();
tinyMCEPopup.onInit.add(FileDialog.init, FileDialog);
