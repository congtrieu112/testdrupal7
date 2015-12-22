<?php
$arg = arg();
$current_lang = 'fr';
$en_active = $fr_active = '';
if (isset($arg[2]) && $arg[2] == 'en') {
  $current_lang = 'en';
  $en_active = 'active';
} else {
  $fr_active = 'active';
}
$current_path = $arg['0'] . '/' . $arg['1'];
$block_title = variable_get('finance_header_title_' . $current_lang);
$block_sub_title = variable_get('finance_header_sub_title_' . $current_lang);
$block_img_full_id = variable_get('finance_header_image_full_' . $current_lang);
$block_img_small_id = variable_get('finance_header_image_small_' . $current_lang);
$block_img_full_load = file_load($block_img_full_id);
$block_img_small_load = file_load($block_img_small_id);
$block_img_full_uri = ($block_img_full_load->uri) ? file_create_url($block_img_full_load->uri) : '';
$block_img_small_uri = ($block_img_small_load->uri) ? file_create_url($block_img_small_load->uri) : '';
?>
<div class="lang">
    <nav class="wrapper">
        <ul>
            <li class="fr <?php print $fr_active; ?>"><a href="<?php print url($current_path . '/fr'); ?>" title="<?php print t('Version française de la page'); ?>">fr</a></li>
            <li class="en <?php print $en_active; ?>"><a href="<?php print url($current_path . '/en'); ?>" title="<?php print t('English version of the page'); ?>">en</a></li>
        </ul>
    </nav>
</div>
<section data-interchange="[<?php print $block_img_small_uri; ?>, (small)], [<?php print $block_img_full_uri; ?>, (medium)]" class="narrow-header">
    <div class="wrapper">
        <div class="heading heading--bordered heading--white">
            <div class="heading__title"><?php print $block_title; ?></div>
            <div class="heading__title heading__title--sub"><?php print $block_sub_title; ?></div>
        </div>
    </div>
</section>
<!-- [header Advice] end-->
<!-- [pageHeaderNav] start-->
<nav class="pageHeaderNav wrapper">
    <ul class="pageHeaderNav__list">
        <?php
        $number_cta = 5;
        for ($i = 0; $i < $number_cta; $i++) :
          $url = $title = '';
          $cta = array();
          $cta = variable_get('cta_menu_item_finance_' . $i . '_' . $current_lang);
          if (isset($cta['url']) && isset($cta['title']) && $cta['url'] && $cta['title']):
            $url = $cta['url'];
            $title = $cta['title'];
            ?>
            <li class="pageHeaderNav__list__item"><a href="<?php print $url; ?>"><?php print $title; ?></a></li>
          <?php endif; ?>
        <?php endfor; ?>
    </ul>
</nav>
<!-- [pageHeaderNav] end-->
<div class="top-actions">
    <div class="wrapper"><a href="#" class="btn-white"><?php print t('Retour'); ?><span class="icon icon-arrow left"></span></a>
    </div>
</div>
<div class="wrapper">
    <hr class="hr">
</div>