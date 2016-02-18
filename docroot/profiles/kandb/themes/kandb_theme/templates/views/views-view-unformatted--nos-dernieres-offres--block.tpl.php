<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<!-- [carousel] start-->
<div class="geoloc-wait" data-geoloc-target="<?php print $view->name; ?>" data-geoloc-target-args="module:views;display:<?php print $view->current_display; ?>;" >
  <?php if(!IS_AJAX): ?><div class="geoloc-wait__spinner" ></div><?php endif; ?>
  <div data-slick="{&quot;slidesToShow&quot;: 3, &quot;slidesToScroll&quot;: 3}" class="slick-slider__item-3">
      <?php $_SESSION['promotion'] = 0; ?>
      <?php foreach ($rows as $id => $row): ?>
        <?php print $row; ?>
      <?php endforeach; ?>
  </div>
</div>
<!-- [carousel] end-->
