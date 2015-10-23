<?php
$style = $content['field_image_principale'][0]['#image_style'];
// Get ville name form Tax.
$ville_id = isset($node->field_programme_loc_ville[LANGUAGE_NONE][0]['tid']) ? $node->field_programme_loc_ville[LANGUAGE_NONE][0]['tid'] : '';
$tax_ville = taxonomy_term_load($ville_id);
$ville_name = isset($tax_ville->name) ? $tax_ville->name : '';

// Get ville name form Tax.
$departement_id = isset($node->field_espace_vente_dpt[LANGUAGE_NONE][0]['tid']) ? $node->field_espace_vente_dpt[LANGUAGE_NONE][0]['tid'] : '';
$departement = taxonomy_term_load($departement_id);
$departement_code = isset($departement->field_numero_departement[LANGUAGE_NONE][0]['value']) ? $departement->field_numero_departement[LANGUAGE_NONE][0]['value'] : '';
?>
<div class="slick-slider__item">
    <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
        <?php print render($title_prefix); ?>
        <?php print render($title_suffix); ?>

        <article class="squaredImageItem squaredImageItem--stacked false">
            <a href="<?php print url('node/' . $node->nid); ?>" title="<?php print $node->title; ?>" class="squaredImageItem__img">
                <img src="<?php print image_style_url($style, $content['field_image_principale']['#items'][0]['uri']); ?>" alt="<?php print $content['field_image_principale']['#items'][0]['alt'] ?>"/>
                <div class="tag">Plus que deux T3 disponibles</div>
            </a>
            <div class="squaredImageItem__infos">
                <div class="squaredImageItem__details">
                    <a href="#" title="Go to programme page" class="heading heading--small">
                        <p class="heading__title">
                            <?php print $ville_name . ' / ' . $departement_code; ?>
                        </p>
                        <p class="heading__title heading__title--sub"><?php print $node->title; ?></p>
                    </a>
                </div>

            </div>
        </article>
    </div>
</div>