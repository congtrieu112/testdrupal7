<!-- [homeSearch] start-->
<!-- images need to have 2 different pictures see data-exchange attribute:
- small: 640 x 845
- large: 1380 x 590
-->
<?php drupal_set_title(''); ?>
<?php
  $title_sub = render($content['field_hp_block_search_stitle']);
  $bien_total = get_total_bien_by_status_site();
?>
<section data-interchange="[<?php print image_style_url('hp_search_block_mobile', $content['field_hp_block_search_img_mob']['#items'][0]['uri']); ?>, (small)], [<?php print image_style_url('hp_search_block', $content['field_hp_block_search_img_des']['#items'][0]['uri']); ?>, (medium)]" class="homepage__search">
    <div class="wrapper">
        <div class="heading heading--bordered heading--white">
            <div class="heading__title"><?php print render($content['field_hp_block_search_title']); ?></div>
            <div class="heading__title heading__title--sub"><?php print str_replace('#num#', $bien_total, $title_sub); ?></div>
        </div>
        <?php print render($content['hp_block_search']); ?>
    </div>
</section>
<!-- [homeSearch] end-->

<!-- [offers] start-->
<section class="wrapper section-padding">
    <header class="heading heading--bordered">
        <h2 class="heading__title"><?php print render($content['field_hp_block_offer_titre']); ?></h2>
        <p class="heading__title heading__title--sub"><?php print $content['field_hp_block_offer_stitre'][0]['#markup']; ?></p>
    </header>
    <?php print render($content['hp_block_offre']); ?>
<!--    <div class="btn-wrapper btn-wrapper--center"><a href="#" class="btn-rounded btn-primary">Voir toutes nos offres<span class="icon icon-arrow"></span></a>
    </div>-->
</section>
<!-- [offers] end-->

<!-- [homeDocs] start-->
<section class="homeDocs">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title"><?php print render($content['field_hp_block_conseil_titre']); ?></h2>
            <p class="heading__title heading__title--sub"><?php print $content['field_hp_block_conseil_stitre'][0]['#markup']; ?></p>
        </header>
        <div class="homeDocs__main">
            <!-- images need to have 2 formats in data-interchange attribute:
            - small: 560 x 365 (VERY high compression)
            - medium: 1180 x 380
            -->
            <?php print render($content['hp_block_conseil_big']); ?>
        </div>
        <div class="homeDocs__list">
            <div class="heading text-center">
                <h3 class="heading__title heading__title--sub"><?php print render($content['field_hp_block_conseil_titre2']); ?></h3>
            </div>
            <?php print render($content['hp_block_conseil_small']); ?>
        </div>
    </div>
</section>
<!-- [homeDocs] end-->