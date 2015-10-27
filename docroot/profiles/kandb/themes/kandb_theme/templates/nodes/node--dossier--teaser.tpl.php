<?php
$style = $content['field_dossier_image'][0]['#image_style'];
$video_id = isset($node->field_dossier_video[LANGUAGE_NONE][0]['video_id']) ? $node->field_dossier_video[LANGUAGE_NONE][0]['video_id'] : '';
?>
<!-- [fileItem] start-->
<article class="fileItem">
    <?php if ($video_id): ?>
        <a href="https://www.youtube.com/watch?v=<?php print $video_id; ?>" title="<?php print t('Lire la vidéo'); ?>"  data-reveal-id="videofileItem-<?php print $node->nid; ?>" class="fileItem__img">
        <?php else: ?>
            <a href="<?php print url('node/' . $node->nid); ?>" title="<?php print t('Lire la vidéo'); ?>"   class="fileItem__img">
            <?php endif; ?>

            <!-- images need to have 2 formats:
            - small: 560 x 365 (HEAVY compression!!!)
            - large: 560 x 365
            -->
            <!-- [Responsive img] start-->
            <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
                <?php print render($title_prefix); ?>
                <?php if ($video_id): ?>
                    <span class="icon icon-play"></span>
                <?php endif; ?>
                <img alt="<?php print $content['field_dossier_image']['#items'][0]['alt']; ?>" data-interchange="[<?php print image_style_url('dossier_small_teaser_mobile', $content['field_dossier_image']['#items'][0]['uri']); ?>, (small)], [<?php print image_style_url('dossier_small_teaser', $content['field_dossier_image']['#items'][0]['uri']); ?>, (large)]"/>
                <?php print render($title_suffix); ?>
            </div>

            <noscript><img src="<?php print image_style_url($style, $content['field_dossier_image']['#items'][0]['uri']); ?>" alt="<?php print $content['field_dossier_image']['#items'][0]['alt']; ?>"/></noscript>
            <!-- [Responsive img] end--></a>
        <!-- [popin] start-->
        <?php if ($video_id): ?>
            <div id="videofileItem-<?php print $node->nid; ?>" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal large">
                <div class="reveal-modal__wrapper">
                    <div class="flex-video youtube">
                        <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/<?php print $video_id; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true"></iframe>
                    </div><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                </div>
            </div>
        <?php endif; ?>
        <!-- [popin] start-->
        <div data-equalizer-watch="data-equalizer-watch" class="fileItem__infos">
            <h4 class="fileItem__infos__heading"><?php print $node->title; ?></h4>
            <div class="btn-wrapper text-center"><a href="<?php print url('node/' . $node->nid); ?>" class="btn-primary btn-rounded"><?php print t('Lire le dossier') ?><span class="icon icon-arrow"></span></a></div>
        </div>
</article>
<!-- [fileItem] end-->
