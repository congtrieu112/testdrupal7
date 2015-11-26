<?php
$ville = isset($node->field_avant_premiere_ville[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_avant_premiere_ville[LANGUAGE_NONE][0]['taxonomy_term']->name : '';
$arrondissement = isset($node->field_avant_premiere_arrondissem['und'][0]['value']) ? $node->field_avant_premiere_arrondissem['und'][0]['value'] : '';
// Information for header programme page
$title = isset($node->title) ? $node->title : '';
$image_principale = isset($node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['uri']) ? $node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['uri'] : '';
$image_principale_small = '';
$image_principale_large = '';
$image_principale_medium = '';
$image_principale_alt = isset($node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['alt']) ? $node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['alt'] : '';

if ($image_principale) {
  $image_principale_small = image_style_url('program_image_principale_small', $image_principale);
  $image_principale_medium = image_style_url('program_image_principale_medium', $image_principale);
  $image_principale_large = image_style_url('program_image_principale_large', $image_principale);
}

$en_quelques_mots = isset($node->field_avant_premiere_en_quelques[LANGUAGE_NONE][0]['value']) ? $node->field_avant_premiere_en_quelques[LANGUAGE_NONE][0]['value'] : '';
$description = isset($node->field_avant_premiere_description[LANGUAGE_NONE][0]['value']) ? $node->field_avant_premiere_description[LANGUAGE_NONE][0]['value'] : '';

$ouverture = isset($node->field_avant_premiere_grande_ouve['und'][0]['value']) ? $node->field_avant_premiere_grande_ouve['und'][0]['value'] : '';
?>
<!-- [programHeader] start-->
<header class="programHeader">
    <!-- mobile heading-->
    <div class="wrapper show-for-small-only">
        <h1 class="heading heading--bordered">
            <div class="heading__title"><?php print $ville . ' ' . $arrondissement; ?></div>
            <div class="heading__title heading__title--sub"><?php print $title; ?></div>
        </h1>
        <?php
        if ($ouverture):
          $date_range_string = '';
          if (module_exists('kandb_validate')) {
            $start_date = $node->field_avant_premiere_date_debut[LANGUAGE_NONE][0]['value'];
            $end_date = $node->field_avant_premiere_date_fin[LANGUAGE_NONE][0]['value'];
            $date_range = kandb_validate_get_dates_from_range($start_date, $end_date);
            $date_range_string = implode(' & ', $date_range) . ' ' . format_date(strtotime($start_date), 'custom', 'F');
          }
          ?>
          <div class="tag tag--important"><?php print t('Grande ouverture'); ?></div>
          <p class="toolbox__intro"><?php print $date_range_string; ?></p>
        <?php else: ?>
          <div class="tag tag--important"><?php print t('Avant-première'); ?></div>
        <?php endif; ?>
    </div>
    <div class="programHeader__figure">
        <!-- images need to have 2 formats see data-exchange attribute:
        - small: 640 x 316 (heavy compression)
        - medium: 1024 x 506
        - large: 1380 x 670
        -->
        <!-- [Responsive img] start--><img alt="<?php print $image_principale_alt; ?>" data-interchange="[<?php print $image_principale_small; ?>, (small)], [<?php print $image_principale_medium; ?>, (medium)], [<?php print $image_principale_large; ?>, (large)]"/>
        <noscript><img src="<?php print $image_principale_medium; ?>" alt="<?php print $image_principale_alt; ?>"/></noscript>
        <!-- [Responsive img] end-->
    </div>
    <div class="wrapper">
        <div class="programHeader__content">
            <div class="toolbox">
                <!-- tablet+desktop heading-->
                <div class="show-for-medium-up">
                    <h1 class="heading heading--bordered">
                        <div class="heading__title"><?php print $ville . ' ' . $arrondissement; ?></div>
                        <div class="heading__title heading__title--sub"><?php print $title; ?></div>
                    </h1>
                    <?php
                    if ($ouverture):
                      $date_range_string = '';
                      if (module_exists('kandb_validate')) {
                        $start_date = $node->field_avant_premiere_date_debut[LANGUAGE_NONE][0]['value'];
                        $end_date = $node->field_avant_premiere_date_fin[LANGUAGE_NONE][0]['value'];
                        $date_range = kandb_validate_get_dates_from_range($start_date, $end_date);
                        $date_range_string = implode(' & ', $date_range) . ' ' . format_date(strtotime($start_date), 'custom', 'F');
                      }
                      ?>
                      <div class="tag tag--important"><?php print t('Grande ouverture'); ?></div>
                      <p class="toolbox__intro"><?php print $date_range_string; ?></p>
                    <?php else: ?>
                      <div class="tag tag--important"><?php print t('Avant-première'); ?></div>
                    <?php endif; ?>
                </div>
            </div>
            <div class="programHeader__content__details">
                <?php if ($en_quelques_mots): ?>
                  <p class="intro"><em><?php print t('En quelques mots'); ?>&nbsp;</em> <?php print $en_quelques_mots; ?></p>
                <?php endif; ?>
            </div>
        </div>
        <?php if ($description): ?>
          <div>
              <p><?php print nl2br($description); ?><p>
          </div>
        <?php endif; ?>
    </div>
</header>
<!-- [programHeader] end-->