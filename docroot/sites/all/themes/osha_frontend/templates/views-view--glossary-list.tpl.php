<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>

 <div class="container fluid">
  <div class="<?php print $classes; ?>">
      <div class="view-content">
    <?php

    $voc = taxonomy_vocabulary_machine_name_load('glossary_type');
    $terms = taxonomy_get_tree($voc->vid);

      foreach ($terms as $glossary_type) {
        $w = entity_metadata_wrapper('taxonomy_term', $glossary_type->tid);
        $name = $w->label();
        $number = $glossary_type->tid;

        // Load the data of the glossary terms of each type.
        $glossary_list = views_get_view_result('glossary_list', 'page', $number);
        if (count($glossary_list) > 0) {
          ?>
          <div class="glossary_type">
            <div class="type-name" data-toggle="collapse" data-target="#demo<?php print $number;?>">
               <span class="display-down glyphicon glyphicon-triangle-bottom"></span>
              <?php print($name)?>
            </div>
            
            <div class="content-term collapssed  collapse" id="demo<?php print $number;?>">
              <dl>
              <?php
              foreach ($glossary_list as $term) {
                $term_title = $term->field_name_field[0]['rendered']['#markup'];
                $term_desc = $term->field_description_field[0]['rendered']['#markup'];
              ?>
                <dt class="term-title">
                 <?php print $term_title; ?>
                </dt>
                <dd class="term-description">
                  <?php print $term_desc; ?>
                </dd>
              <?php
              }
              ?>
            </dl>
            </div>
          </div>
          <?php
        }
      }
?>
    </div>
  </div>
</div>
