function osha_tmgmt_tinymce_paste_postprocess(plugin, args) {
  jQuery(args.node).find('*').each(function(idx, item){
    jQuery(item).removeAttr('id');
  });
}
