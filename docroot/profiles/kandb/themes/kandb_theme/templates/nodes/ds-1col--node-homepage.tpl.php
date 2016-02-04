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
            <div class="heading__title heading__title--sub"><?php print str_replace('#num# biens', '<strong>' . number_format($bien_total, NULL, ',', '&nbsp;') . ' biens</strong>', $title_sub); ?></div>
        </div>
        <?php print render($content['hp_block_search']); ?>
    </div>
</section>
<!-- [homeSearch] end-->

<!-- [offers] start-->
<section class="wrapper section-padding">
    <header class="heading heading--bordered">
        <h2 class="heading__title">
            <?php
            if (isset($content['field_hp_block_offer_titre'])) :
              print render($content['field_hp_block_offer_titre']);
            else :
              print variable_get('kandb_bloc_default_offre_title_homepage', '');
            endif;
            ?>
        </h2>
        <?php
        if (isset($content['field_hp_block_offer_stitre'][0]['#markup'])) :
        ?>
          <p class="heading__title heading__title--sub">
          <?php
            print $content['field_hp_block_offer_stitre'][0]['#markup'];
          ?>
          </p>
        <?php
        elseif(!empty(variable_get('kandb_bloc_default_offre_subtitle_homepage', ''))) :
        ?>
          <p class="heading__title heading__title--sub">
          <?php
          print variable_get('kandb_bloc_default_offre_subtitle_homepage', '');
          ?>
          </p>
        <?php
        endif;
        ?>
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
<?php
$number_pdf = count($node->field_hp_block_document['und']);
?>
<!-- [references] start-->
<section class="wrapper section-padding">
    <header class="heading heading--bordered">
        <?php
        if ($number_pdf > 1):
          $addMore = '_';
          $nid = $node->nid;
          $path = file_create_url('public://');
          $real_path = drupal_realpath('public://');
          $fileName = 'Habitat' . $addMore . preg_replace('@[^a-z0-9-]+@', '-', strtolower($node->title)) . '.zip';
          if (file_exists($real_path . '/Habitat/archive/' . $nid . '/')) :
            $filePath = $real_path . '/Habitat/archive/' . $nid . '/' . $fileName;
            $linkfile = $path . 'Habitat/archive/' . $nid . '/' . $fileName;
            if ($filePath) :
              if (file_exists($filePath)) :
                ?>
                <div class="heading__document"><a href="<?php print $linkfile; ?>" title="<?php print t('Télécharger le pdf'); ?>" class="btn-white"><?php print t('Télécharger le pdf'); ?><span class="icon icon-download left"></span></a></div>
                <?php
              endif;
            endif;
          endif;
          ?>
        <?php elseif ($number_pdf > 0):
          ?>
          <div class="heading__document"><a href="<?php print url('download-document-file/' . $node->field_hp_block_document['und'][0]['fid']) ?>" title="<?php print t('Télécharger le pdf'); ?>" class="btn-white"><?php print t('Télécharger le pdf'); ?><span class="icon icon-download left"></span></a></div>
        <?php endif; ?>
        <h2 class="heading__title"><?php print render($content['field_hp_block_ref_titre']); ?></h2>
        <p class="heading__title heading__title--sub"><?php print render($content['field_hp_block_ref_stitre'][0]['#markup']); ?></p>
    </header>
    <?php print render($content['habitat_carousel']); ?>
    <?php if ($content['field_hp_block_cta_habitat']['#items'][0]['url'] && $content['field_hp_block_cta_habitat']['#items'][0]['title']): ?>
      <div class="btn-wrapper btn-wrapper--center">
          <a href="<?php print isset($content['field_hp_block_cta_habitat']['#items'][0]['url']) ? url($content['field_hp_block_cta_habitat']['#items'][0]['url']) : ''; ?>" class="btn-rounded btn-primary"><?php print isset($content['field_hp_block_cta_habitat']['#items'][0]['title']) ? $content['field_hp_block_cta_habitat']['#items'][0]['title'] : ''; ?>
              <span class="icon icon-arrow"></span>
          </a>
      </div>
    <?php endif; ?>
</section>
<!-- [references] end-->