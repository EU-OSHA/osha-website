
ABOUT
--------------------------------------------------------------------------------

Simplenews Content Selection allows you to select already created content to
assemble in the body of a newsletter (provided by the Simplenews module)
content type.


INSTALLATION
--------------------------------------------------------------------------------

Enable the module, you'll need to have Simplenews too.


HOW DOES IT WORK
--------------------------------------------------------------------------------

This module provides an action "Create newsletter" in the content administration
form located at admin/content/node.

Check some content in this form, choose the "Create newsletter" action and you
will be provided a sorting form along with the option to create a Table of
Contents.

When validating, you will be redirected to a newsletter creation form with the
body field already filled in.


CONFIGURATION
--------------------------------------------------------------------------------

You can configure the module at admin/config/services/simplenews/settings/scs
you can change the default view mode (which is the one provided vy SCS) used
when generating the output of nodes selected on newsletter creation.

When multiple content types are flagged as newsletter content types, you can
select which content type to generate when using SCS. This is hidden by default
as the "Newsletter" content type is the only one by default.


OVERRIDING OUTPUT
--------------------------------------------------------------------------------

The output generated and placed in the body is built from the view mode set in
the module configuration.

You can override the Drupal way in your theme, for exmplae by specifying a
custom template for this view mode.

If you add this in the template.php file of your theme:

  function YOURTHEME_preprocess_node(&$vars){
    // Add template suggestions based on view modes
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['view_mode'];
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['view_mode'] . '__' . $vars['type'];
  }

You will be able to create a node--scs--article.tpl.php that will be taken into
account after flushing the theme registry and when creating a new newsletter.

You can also override the Table of Contents output by implemeting a function in
your template.php file: function YOURTHEME_scs_toc($variables) {}


VIEWS INTEGRATION
--------------------------------------------------------------------------------

The Simplenews Content Selection Views Integration is a submodule that provides
an action for Views Bulk Operations (VBO), it also provide a default view that
you can enable using Views UI.

If you want to create your own VBO view, add a field "Bulk operation: Content"
and select the action "Create newsletter". Note that the enqueue and skip
confirmation options will have no effect as you will be redirected to
newsletter creation form automatically after sorting.


CONTRIBUTORS
--------------------------------------------------------------------------------

SebCorbin http://drupal.org/user/412171 (current maintainer)

This module was sponsored by Makina Corpus (http://www.makina-corpus.com).
