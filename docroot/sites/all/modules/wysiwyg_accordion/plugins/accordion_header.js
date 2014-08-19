(function ($) {
	Drupal.wysiwyg.plugins.accordion_header = {
	  invoke: function(data,settings,instanceId) {
			Drupal.wysiwyg.instances[instanceId].insert('<h3>' + data.content + '</h3>');
		},
	}
}(jQuery));