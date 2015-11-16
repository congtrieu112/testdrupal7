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
$current_id_programme = 0;
foreach ($rows as $id => $row) {
  $row_result = $view->style_plugin->rendered_fields[$id];
  if ($row_result['field_programme_nid'] != $current_id_programme) {
    $current_id_programme = $row_result['field_programme_nid'];
    $number_of_programme ++;
    $villes[] = $row_result['field_programme_field_programme_loc_ville'];
  }
}
$number_of_villes = count(array_unique($villes));
$current_id_programme = 0;
?>

<header class="heading results__list__heading">
  <h1 class="heading__title">Vos résultats</h1>
  <p class="heading__title heading__title--sub"><?php print $number_of_programme; ?> programmes / <?php print $number_of_villes; ?> villes</p>
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
        <li class="bordered"><a href="<?php print $link_search_programme; ?>" tabindex="0" aria-selected="true">Programmes</a></li>
        <li class="bordered"><a href="<?php print $link_search_bien; ?>" tabindex="0" aria-selected="false">Biens</a></li>
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
            <article data-gmaps-marker="{&quot;lat&quot;:<?php print $row_result['field_programme_field_programme_loc_lat']; ?>,&quot;lng&quot;:<?php print $row_result['field_programme_field_programme_loc_long']; ?>,&quot;infoWindow&quot;:{&quot;content&quot;:&quot;<?php print ucfirst(strtolower($row_result['field_programme_field_programme_loc_ville'])); ?> / <?php print $row_result['field_programme_field_programme_loc_department']; ?>, <?php print $row_result['field_programme_title']; ?>&quot;}}" class="searchResultsItem searchResultsItem--programmes">
            <div class="heading heading--small">
              <h3><span class="heading__title"><?php print ucfirst(strtolower($row_result['field_programme_field_programme_loc_ville'])); ?> / <?php print $row_result['field_programme_field_programme_loc_department']; ?></span><span class="heading__title heading__title--sub"><?php print $row_result['field_programme_title']; ?></span></h3>
              <div class="promotion">
                <?php foreach($row_result['promotions'] as $id => $promotion): ?>
                  <?php if ($id > 2) break; ?>
                  <div class="tag tag--important"><?php print $promotion->title; ?> <sup>(<?php print $id+1; ?>)</sup></div>
                <?php endforeach; ?>
              </div>
            </div>
            <div class="searchResultsItem__infos"><a href="<?php print $row_result['field_programme_url']; ?>" title="Aller à la page programme" class="searchResultsItem__infos__img">
                <!-- images need to have 2 formats:
                - small: 180 x 180 (HEAVY compression!!!)
                - medium: 180 x 180
                -->
                <!-- [Responsive img] start-->
                <img alt="TODO Photo programme undefined" data-interchange="[<?php print $row_result['search_small']; ?>, (small)], [<?php print $row_result['search_medium']; ?>, (medium)]" data-uuid="interchange-igw8ubhi9" src="<?php print $row_result['search_medium']; ?>">
                <noscript>&lt;img src="<?php print $row_result['search_medium']; ?>" alt="Photo programme undefined"/&gt;</noscript>
                <!-- [Responsive img] end--></a>
              <div class="searchResultsItem__infos__details">
                <p class="intro">Appartements disponibles de <?php print $row_result['field_programme_field_programme_room_min']; ?> à <?php print $row_result['field_programme_field_programme_room_max']; ?> pièces </p>
                <ul class="details">
                  <li>TODOOOOOOOO</li>
                  <?php // print str_replace('##', '</li><li>', $row_result['field_programme_caracteristique']); ?>
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