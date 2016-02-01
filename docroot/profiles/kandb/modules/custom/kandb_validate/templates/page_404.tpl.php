<?php
if (!$node) {
  return ;
}
$node_view = node_view($node);
$title_sub = render($node_view['field_hp_block_search_stitle']);
$bien_total = get_total_bien_by_status_site();
?>
<section data-interchange="[<?php print image_style_url('hp_search_block_mobile', $node_view['field_hp_block_search_img_mob']['#items'][0]['uri']); ?>, (small)], [<?php print image_style_url('hp_search_block', $node_view['field_hp_block_search_img_des']['#items'][0]['uri']); ?>, (medium)]" class="homepage__search">
    <div class="wrapper">
      <div class="heading heading--bordered heading--white">
        <div class="heading__title"><?php print render($node_view['field_hp_block_search_title']); ?></div>
        <div class="heading__title heading__title--sub"><?php print str_replace('#num# biens', '<strong>' . number_format($bien_total, NULL, ',', '&nbsp;') . ' biens</strong>', $title_sub); ?></div>
      </div>
      <?php print render($node_view['hp_block_search']); ?>
      <div class="heading--white">        
          <div class="heading__title heading__title--sub"><?php print t('ou consultez le'); ?> <a href="#" class="heading__title--sub--link"><?php print t('plan du site'); ?></a></div>
      </div>  
    </div>
</section>