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
<?php if ($rows): ?>
  <!-- [mySelections: programmes] start-->
  <section class="bg-lightGrey section-padding">
    <div class="wrapper">
      <h2 class="heading heading--bordered">
        <div class="heading__title">Mes sélections</div>
      </h2>
    </div>
    <div class="wrapper--narrow">
      <?php print $rows; ?>
    </div>
    <?php if(count($rows) > 5) : ?>
    <!-- [seeMore] start-->
    <div data-seemore="programmes" data-seemore-nbr='5' class="voir-plus">
      <button class="btn-primary btn-rounded">Voir plus<span class="icon icon-arrow down"></span></button>
    </div>
    <!-- [seeMore] end-->
    <?php endif; ?>
  </section>
  <!-- [mySelections: programmes] end-->
<?php endif; ?>