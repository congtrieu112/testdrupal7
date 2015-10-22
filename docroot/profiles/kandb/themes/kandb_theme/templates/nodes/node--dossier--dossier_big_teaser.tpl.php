<?php
$style = $content['field_dossier_image'][0]['#image_style'];
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>

    <a href="https://www.youtube.com/watch?v=jO8k7fsdIIg" title="vidéo" data-reveal-id="videoConseilMain" data-interchange="[<?php print image_style_url($style, $content['field_dossier_image']['#items'][0]['uri']); ?>, (small)], [<?php print image_style_url($style, $content['field_dossier_image']['#items'][0]['uri']); ?>, (medium)]" class="homeDocs__main__link heading heading--white">
        <h3 class="heading__title">Pourquoi acheter dans le neuf&nbsp;?</h3>
        <div class="btn-icon"><span class="button__content"><span class="icon icon-play"></span>Lire la vidéo</span></div></a>
    <!-- [popin] start-->
    <div id="videoConseilMain" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal large">
        <div class="reveal-modal__wrapper">
            <div class="flex-video youtube">
                <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/jO8k7fsdIIg" frameborder="0" allowfullscreen allowtransparency="true"></iframe>
            </div><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
        </div>
    </div>
    <!-- [popin] start-->
    <div class="homeDocs__main__desc">
        <p class="color-jet"><?php print $node->title; ?></p>
        <div class="btn-wrapper"><a href="<?php print url('node/' . $node->nid); ?>" class="btn-secondary btn-rounded">Lire le dossier<span class="icon icon-arrow"></span></a></div>
    </div>
</div>