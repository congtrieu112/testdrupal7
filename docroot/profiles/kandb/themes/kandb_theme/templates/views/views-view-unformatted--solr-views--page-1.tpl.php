<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php
$number_of_programme = 0;
$villes = array();
$number_of_piece_by_programme = array();
$current_id_programme = 0;
$type_of_bien_by_programme = array();
$number_of_bien_by_programme = array();
$programme_promotions = array();
foreach ($rows as $id => $row) {
  $row_result = $view->style_plugin->rendered_fields[$id];
  // $programme_promotions[$row_result['field_programme_nid']] = array();
  foreach($row_result['promotions'] as $promotion) {
    $programme_promotions[$row_result['field_programme_nid']][$promotion->nid] = $promotion;
  }

  if ($row_result['field_programme_nid'] != $current_id_programme) {
    $number_of_bien_by_programme[$row_result['field_programme_nid']] = 1;
    $current_id_programme = $row_result['field_programme_nid'];
    $number_of_programme ++;
    if(!empty($row_result['field_programme_ville_text'])) $villes[] = $row_result['field_programme_ville_text'];
  }else{
    $number_of_bien_by_programme[$row_result['field_programme_nid']] ++;
  }

  if(!isset($number_of_piece_by_programme[$row_result['field_programme_nid']])) {
    $number_of_piece_by_programme[$row_result['field_programme_nid']] = array();
  }
  if(!in_array($row_result['field_nb_pieces'], $number_of_piece_by_programme[$row_result['field_programme_nid']])) {
    $number_of_piece_by_programme[$row_result['field_programme_nid']][] = $row_result['field_nb_pieces'];
  }
  if(!isset($type_of_bien_by_programme[$row_result['field_programme_nid']])){
    $type_of_bien_by_programme[$row_result['field_programme_nid']] = array();
  }
  if(!isset($type_of_bien_by_programme[$row_result['field_programme_nid']][$row_result['field_type']])){
    $type_of_bien_by_programme[$row_result['field_programme_nid']][$row_result['field_type']] = 1;
  }else{
    $type_of_bien_by_programme[$row_result['field_programme_nid']][$row_result['field_type']] ++;
  }
}
$number_of_villes = count(array_unique($villes));
$current_id_programme = 0;
$current_promotion_indice = 1;
?>

<header class="heading results__list__heading">
  <h1 class="heading__title">Vos résultats</h1>
  <p class="heading__title heading__title--sub"><?php print $number_of_programme; ?> programme<?php print ($number_of_programme > 1 ? 's' : ''); ?> / <?php print $number_of_villes; ?> ville<?php print ($number_of_villes > 1 ? 's' : ''); ?></p>
</header>
<!-- [searchResults: programmes] start-->
<div class="filter">
  <div class="filter__label">Afficher par</div>
  <div class="form-dropdown form-dropdown--floating filter__item">
    <h2>
      <button aria-expanded="false" aria-controls="resultType" data-app-dropdown="" class="form-dropdown__trigger"><span class="text">Programmes</span><span aria-hidden="true" class="icon icon-expand"></span></button>
    </h2>
    <div id="resultType" aria-hidden="true" class="form-dropdown__content form-dropdown__content--last hidden">
      <ul class="ul-unstyled undo-padding">
        <li class="bordered"><a href="<?php print $link_search_programme; ?>" tabindex="0" >Programmes</a></li>
        <li class="bordered"><a href="<?php print $link_search_bien; ?>" tabindex="0" >Biens</a></li>
      </ul>
    </div>
  </div>
</div>
<div class="results__items">
  <ul class="content">
    <?php foreach ($rows as $id => $row): ?>
      <?php $row_result = $view->style_plugin->rendered_fields[$id]; ?>
      <?php if ($row_result['field_programme_nid'] != $current_id_programme): ?>
        <li class="results__item">
          <!-- [searchResultsItem programmes] start-->
            <article data-gmaps-marker="{&quot;lat&quot;:<?php print $row_result['field_programme_field_programme_loc_lat']; ?>,&quot;lng&quot;:<?php print $row_result['field_programme_field_programme_loc_long']; ?>,&quot;infoWindow&quot;:{&quot;content&quot;:&quot;<?php print ucfirst(strtolower($row_result['field_programme_ville_text'])); ?> / <?php print $row_result['field_programme_departement_number']; ?>, <?php print $row_result['field_programme_title']; ?>&quot;}}" class="searchResultsItem searchResultsItem--programmes">
            <div class="heading heading--small">
              <h3><span class="heading__title"><?php print ucfirst(strtolower($row_result['field_programme_ville_text'])); ?> / <?php print $row_result['field_programme_departement_number']; ?></span><span class="heading__title heading__title--sub"><?php print $row_result['field_programme_title']; ?></span></h3>
              <?php if(!empty($programme_promotions[$row_result['field_programme_nid']])) : ?>
                <ul class="promotion">
                  <?php $count_promotion = 1; ?>
                  <?php foreach($programme_promotions[$row_result['field_programme_nid']] as $id => $promotion): ?>
                    <?php if ($count_promotion > 2) break; ?>
                    <!-- [popin] start-->
                    <li>
 	                  <button data-reveal-trigger="<?php print $current_id_programme . '_' . $id; ?>" class="tag tag--important"><?php print $promotion->title; ?><sup>(<?php print $current_promotion_indice; $current_promotion_indice++; ?>)</sup></button>
                      <!-- [popin] start-->
 	                  <div data-reveal="<?php print $current_id_programme . '_' . $id; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
 	                    <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
 	                      <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
 	                      <p><?php print $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']; ?></p>
 	                    </div>
 	                  </div>
 	                  <!-- [popin] end-->
 	                </li>
                    <?php $count_promotion ++; ?>
                  <?php endforeach; ?>
                </ul>
              <?php endif; ?>
            </div>
            <div class="searchResultsItem__infos"><a href="<?php print $row_result['field_programme_url']; ?>" title="Aller à la page programme" class="searchResultsItem__infos__img">
                <?php if(isset($row_result['field_programme_programme_image']) && !empty($row_result['field_programme_programme_image'])): ?>
                  <?php
                  $image = $row_result['field_programme_programme_image'];
                  $image_small = image_style_url("search_small", $image);
                  $image_medium = image_style_url("search_medium", $image);
                  ?>
                    <!-- images need to have 2 formats:
                    - small: 180 x 180 (HEAVY compression!!!)
                    - medium: 180 x 180
                    -->
                    <!-- [Responsive img] start-->
                    <img alt="Photo programme undefined" data-interchange="[<?php print (!empty($image_small) ? $image_small : ''); ?>, (small)], [<?php print (!empty($image_medium) ? $image_medium : ''); ?>, (medium)]" data-uuid="interchange-igw8ubhi9" src="<?php print (!empty($image_medium) ?$image_medium : ''); ?>">
                    <noscript><img src="<?php print (!empty($image_medium) ? $image_medium : ''); ?>" alt="Photo programme undefined"/></noscript>
                    <!-- [Responsive img] end-->
                <?php endif; ?></a>
              <div class="searchResultsItem__infos__details">
                <p class="intro"><?php print $number_of_bien_by_programme[$row_result['field_programme_nid']]; ?> <?php
                  $output = '';
                  if(!empty($type_of_bien_by_programme[$row_result['field_programme_nid']])) {
                    foreach ($type_of_bien_by_programme[$row_result['field_programme_nid']] as $type => $number) {
                      $output .= $type . (($number >1) ? 's' : '') . ' '; // Ugly
                      if($type == t('Appartement')) {
                        $count = count($number_of_piece_by_programme[$row_result['field_programme_nid']]);
                        if($count == 1){
                          $output .= 'de ' . $number_of_piece_by_programme[$row_result['field_programme_nid']][0] . ' ';
                        }elseif($count > 1){
                          $first = $number_of_piece_by_programme[$row_result['field_programme_nid']][0];
                          if(is_numeric(substr($first, 0, 1))){
                            $first = substr($first, 0, 1);
                          }
                          $last = $number_of_piece_by_programme[$row_result['field_programme_nid']][$count-1];
                          $output .= 'de '. $first . ' à ' . $last . ' ';
                        }
                      }
                      $output .= 'disponible' . (($number >1) ? 's' : '') . ', ';
                    }
                  }
                  $output = substr($output, 0, -2);
                  print $output;
                  ?></p>
                <ul class="details">
                  <li><?php print str_replace('##', '</li><li>', $row_result['field_programme_field_caracteristiques']); ?></li>
                </ul>
                <div class="large-column">
                  <ul class="prices">
                    <?php if($row_result['field_programme_field_program_low_tva_price_min'] != ''): ?>
                      <li><span class="text">à partir de <strong><?php print $row_result['field_programme_field_program_low_tva_price_min']; ?>&nbsp;€</strong></span><span class="tva"><?php print $row_result['field_programme_field_tva']; ?></span></li>
                    <?php endif; ?>
                    <li><span class="text">à partir de <strong><?php print $row_result['field_programme_field_programme_price_min']; ?>&nbsp;€</strong></span><span class="tva tva--high">TVA 20%</span></li>
                  </ul>
                  <div class="searchResultsItem__btn"><a href="<?php print $row_result['field_programme_url']; ?>" class="btn-rounded btn-primary">Découvrir<span class="icon icon-arrow"></span></a>
                  </div>
                </div>
              </div>
            </div>
          </article>
          <!-- [searchResultsItem programmes] end-->
        </li>
      <?php endif; ?>
      <?php $current_id_programme = $row_result['field_programme_nid']; ?>
    <?php endforeach; ?>
  </ul>
</div>
<!-- [searchResults: programmes] end-->


<script src="https://maps.googleapis.com/maps/api/js?sensor=true&amp;libraries=places&amp;key=<?php print variable_get('gmap_api_key'); ?>"></script>
