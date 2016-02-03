<?php
if (!$node) {
  return ;
}
$node_view = node_view($node);
?>
<?php if(empty(variable_get('kb_404_image'))):?>
<section data-interchange="[<?php print image_style_url('hp_search_block_mobile', $node_view['field_hp_block_search_img_mob']['#items'][0]['uri']); ?>, (small)], [<?php print image_style_url('hp_search_block', $node_view['field_hp_block_search_img_des']['#items'][0]['uri']); ?>, (medium)]" class="homepage__search">
    <?php else:
      $image_404 = file_load(variable_get('kb_404_image'));
    ?>
<section data-interchange="[<?php print image_style_url('hp_search_block_mobile', $image_404->uri); ?>, (small)], [<?php print image_style_url('hp_search_block', $image_404->uri); ?>, (medium)]" class="homepage__search">    
<?php endif; ?>
    <div class="wrapper">
      <div class="heading heading--bordered heading--white">
        <div class="heading__title"><?php print t('Oups !'); ?></div>
        <div class="heading__title heading__title--sub"><?php print !empty(variable_get('kb_404_title')) ? variable_get('kb_404_title') : ''; ?></div>
        <div class="heading__title"><?php print !empty(variable_get('kb_404_description')) ? variable_get('kb_404_description') : ''; ?></div>
      </div>
      <?php print render($node_view['hp_block_search']); ?>
      <div class="heading--white">        
        <div class="heading__title heading__title--sub"><?php print !empty(variable_get('kb_404_title_link')) ? variable_get('kb_404_title_link') : ''; ?> <a href="<?php print !empty(variable_get('kb_404_link')) ? variable_get('kb_404_link') : '#'; ?>" class="heading__title--sub--link"><?php print !empty(variable_get('kb_404_text_link')) ? variable_get('kb_404_text_link') : ''; ?></a></div>
      </div>  
    </div>
</section>