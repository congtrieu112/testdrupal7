<?php
$style = $content['field_dossier_image'][0]['#image_style'];
$video_id = isset($node->field_dossier_video[LANGUAGE_NONE][0]['video_id']) ? $node->field_dossier_video[LANGUAGE_NONE][0]['video_id'] : '';
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <?php if ($video_id): ?>
      <a href="https://www.youtube.com/watch?v=<?php print $video_id; ?>" title="<?php print $node->title; ?>" data-reveal-id="videoConseilMain" data-interchange="[<?php print image_style_url('dossier_big_teaser_mobile', $content['field_dossier_image']['#items'][0]['uri']); ?>, (small)], [<?php print image_style_url('dossier_big_teaser', $content['field_dossier_image']['#items'][0]['uri']); ?>, (medium)]" class="homeDocs__main__link heading heading--white">
          <h3 class="heading__title"><?php print $node->title; ?></h3>
          <div class="btn-icon">
              <span class="button__content" onclick="javascript:return tc_events_1(this,'CLICK',{'LABEL':'nos_conseils::player_video::video_acheter_neuf','XTCLICK_EVENT':'C','XTCLICK_S2':'1','XTCLICK_TYPE':'A'});">
                  <span class="icon icon-play"></span>
                  <?php print t('Lire la vidéo'); ?>
              </span>
          </div>
      </a>
    <?php else: ?>
      <a href="#" title="<?php print $node->title; ?>" data-reveal-id="" data-interchange="[<?php print image_style_url('dossier_big_teaser_mobile', $content['field_dossier_image']['#items'][0]['uri']); ?>, (small)], [<?php print image_style_url('dossier_big_teaser', $content['field_dossier_image']['#items'][0]['uri']); ?>, (medium)]" class="homeDocs__main__link heading heading--white">
          <h3 class="heading__title"><?php print $node->title; ?></h3>
      </a>
    <?php endif; ?>


    <!-- [popin] start-->
    <div id="videoConseilMain" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full">
        <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
            <div class="flex-video youtube">
                <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/<?php print $video_id; ?>" frameborder="0" allowfullscreen allowtransparency="true"></iframe>
            </div>
        </div>
    </div>
    <!-- [popin] end-->
    <div class="homeDocs__main__desc">
        <p class="color-jet"><?php print nl2br($node->field_dossier_introduction[LANGUAGE_NONE][0]['value']); ?></p>
        <div class="btn-wrapper">
            <a href="<?php print url('node/' . $node->nid); ?>" class="btn-secondary btn-rounded">
                <?php print t('Lire le dossier'); ?>
                <span class="icon icon-arrow"></span>
            </a>
        </div>
    </div>
</div>

