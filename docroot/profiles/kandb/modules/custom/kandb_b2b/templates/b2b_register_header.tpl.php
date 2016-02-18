<?php
$fid = variable_get('kandb_b2b_register_page_background_header', '');
$image_medium = $image_small = '';
if ($fid) {
  $background = file_load($fid);
  if ($background->uri) {
    $image_medium = image_style_url('hp_search_block', $background->uri);
    $image_small = image_style_url('homepageb2b_backgound_small', $background->uri);
  }
}
?>
<!-- [header Advice] start-->
<!-- images need to have 2 different formats:
- small: 640 x 400 (High compression)
- large: 1380 x 400

-->
<section data-interchange="[<?php print $image_small; ?>, (small)], [<?php print $image_medium; ?>, (medium)]" class="narrow-header">
    <div class="wrapper">
        <div class="heading heading--bordered heading--white">
            <div class="heading__title"><?php print variable_get('kandb_b2b_register_page_title', t('Devenez un prescripteur privilégié')); ?></div>
            <div class="heading__title heading__title--sub"><?php print variable_get('kandb_b2b_register_page_subtitle', t('Kaufman et Broad')); ?></div>
        </div>
    </div>
</section>
<!-- [header Advice] end-->