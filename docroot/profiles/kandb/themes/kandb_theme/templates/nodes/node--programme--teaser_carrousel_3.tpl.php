<?php
$style = $content['field_image_principale'][0]['#image_style'];
?>
<div class="slick-slider__item">
    <article class="squaredImageItem squaredImageItem--stacked false"><a href="<?php print url('node/' . $node->nid); ?>" title="<?php print $node->title; ?>" class="squaredImageItem__img">
            <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
                <?php print render($title_prefix); ?>
                <img src="<?php print image_style_url($style, $content['field_image_principale']['#items'][0]['uri']); ?>" alt="<?php print $content['field_image_principale']['#items'][0]['alt'] ?>"/>
                <?php print render($title_suffix); ?>
            </div>
            <div class="tag">Plus que deux T3 disponibles</div></a>
        <div class="squaredImageItem__infos">
            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                    <p class="heading__title">Appartement</p>
                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
            </div>
        </div>
    </article>
</div>