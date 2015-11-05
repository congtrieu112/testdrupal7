<?php
$sub_title = '';
$uri_img = '';
if (isset($content['field_block_header_stitre']['#object']->field_block_header_stitre['und'][0]['value']))
  $sub_title = $content['field_block_header_stitre']['#object']->field_block_header_stitre['und'][0]['value'];
if (isset($content['field_block_header_image']['#object']->field_block_header_image['und'][0]['uri']))
  $uri_img = $content['field_block_header_image']['#object']->field_block_header_image['und'][0]['uri'];
?>
<section data-interchange="[<?php print file_create_url($uri_img) ?>, (small)], [<?php print file_create_url($uri_img) ?>, (medium)]" class="narrow-header">
    <div class="wrapper">
        <div class="heading heading--bordered heading--white">
            <div class="heading__title">Nos conseils</div>
            <div class="heading__title heading__title--sub"><?php print $sub_title ?></div>
        </div>
    </div>
</section>