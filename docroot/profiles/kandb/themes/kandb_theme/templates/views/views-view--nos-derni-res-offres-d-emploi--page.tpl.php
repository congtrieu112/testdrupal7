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
<section>
  <header class="heading heading--bordered">
    <h2 class="heading__title">Nos dernières offres d’emploi&nbsp;</h2>
  </header>
  <?php if (false): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>
  <?php if($rows): ?>
    <ul data-app-accordion="postuler" class="accordion fullWidth postuler">
      <?php print $rows; ?>
    </ul>
  <?php else: ?>
    <div>Pas d'annonces actuellement</div>
  <?php endif; ?>
</section>
<?php print $pager; ?>

