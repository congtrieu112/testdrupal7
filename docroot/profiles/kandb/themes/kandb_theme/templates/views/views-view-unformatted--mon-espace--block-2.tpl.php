<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" data-slick-responsive="small-only" class="slick-slider__item-1 articles">
  <!-- [squaredImageItem] start-->
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
  <!-- [squaredImageItem] end-->
</div>
