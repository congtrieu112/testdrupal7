<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<!-- [carousel] start-->
<div data-slick="{&quot;slidesToShow&quot;: 3, &quot;slidesToScroll&quot;: 3}" data-equalizer="squaredImageItem" class="slick-slider__item-3">
    <?php $_SESSION['avant_promotion'] = 0; ?>
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
</div>
<!-- [carousel] end-->
