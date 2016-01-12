<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<!-- [carousel] start-->
<div data-slick="{&quot;slidesToShow&quot;: 4, &quot;slidesToScroll&quot;: 4}" class="slick-slider__item-4">
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
</div>
<!-- [carousel] end-->
