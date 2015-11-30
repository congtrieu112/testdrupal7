<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
//get link file Plaquette commerciale
$file_plaquette_commerciale = '';
if (isset($content['field_plaquette_commerciale']['#object']->field_plaquette_commerciale['und'][0]['uri'])) {
  $file_plaquette_commerciale = $content['field_plaquette_commerciale']['#object']->field_plaquette_commerciale['und'][0]['uri'];
}
//get link file fiche reseignement
$file_fiche_renseignement = '';
if (isset($content['field_fiche_renseignement']['#object']->field_fiche_renseignement['und'][0]['uri'])) {
  $file_fiche_renseignement = $content['field_fiche_renseignement']['#object']->field_fiche_renseignement['und'][0]['uri'];
}
//get link file Kit fiscal
$file_kit_fiscal = '';
if (isset($content['field_kit_fiscal']['#object']->field_kit_fiscal['und'][0]['uri'])) {
  $file_kit_fiscal = $content['field_kit_fiscal']['#object']->field_kit_fiscal['und'][0]['uri'];
}//get link file Plan du bâtiment
$file_plan_batiment = '';
if (isset($content['field_plan_batiment']['#object']->field_plan_batiment['und'][0]['uri'])) {
  $file_plan_batiment = $content['field_plan_batiment']['#object']->field_plan_batiment['und'][0]['uri'];
}
//get link zip file
$addMore = '_';
$path_args = explode('/', current_path());
$node = node_load($path_args[1]);
$nid = $node->nid;
$title = $node->title;
$path = file_create_url('public://');
$real_path = drupal_realpath('public://');
$fileName = 'Programme' . $addMore . preg_replace('@[^a-z0-9-]+@', '-', strtolower($node->title)) . '.zip';
if (file_exists($real_path . '/Programme/archive/' . $nid . '/')) {
  $filePath = $real_path . '/Programme/archive/' . $nid . '/' . $fileName;
  $linkfile = $path . 'Programme/archive/' . $nid . '/' . $fileName;
  if ($filePath) {
    if (file_exists($filePath)) {
      $link_to_zip = $linkfile;
    }
  }
}
//check all bien status
$programme_id = $node->vid;
$flag = 0;
$custom_bien = 0;
$status = 1;
if ($tid = get_tid_by_id_field($status)) {
  $custom_bien = filter_bien_by_id_program($programme_id, $tid);
}
if ($custom_bien) {
  $flag = 1;
}

// Habitel widget
$habiteo_id = isset($node->field_programme_habiteo_id['und'][0]['value']) ? $node->field_programme_habiteo_id['und'][0]['value'] : '';
$habiteo_key = variable_get('habiteo_widget_security_key');
$habiteo_video_de_quartier_url = variable_get('habiteo_video-de-quartier_url');
$habiteo_vue_generale_url = variable_get('habiteo_vue-generale_url');
$lat = isset($node->field_programme_loc_lat[LANGUAGE_NONE][0]['value']) ? $node->field_programme_loc_lat[LANGUAGE_NONE][0]['value'] : '';
$lon = isset($node->field_programme_loc_long[LANGUAGE_NONE][0]['value']) ? $node->field_programme_loc_long[LANGUAGE_NONE][0]['value'] : '';
$video_id = isset($node->field_quartier_video[LANGUAGE_NONE][0]['video_id']) ? $node->field_quartier_video[LANGUAGE_NONE][0]['video_id'] : '';
$logementBlock = module_invoke('kandb_programme', 'block_view', 'logement_block');
$program_characteristic = module_invoke('kandb_programme', 'block_view', 'program_characteristic');

// Information for header programme page
$title = isset($node->title) ? $node->title : '';
$image_principale = isset($node->field_image_principale[LANGUAGE_NONE][0]['uri']) ? $node->field_image_principale[LANGUAGE_NONE][0]['uri'] : '';
$image_principale_small = '';
$image_principale_large = '';
$image_principale_medium = '';

if ($image_principale) {
  $image_principale_small = image_style_url('program_image_principale_small', $image_principale);
  $image_principale_medium = image_style_url('program_image_principale_medium', $image_principale);
  $image_principale_large = image_style_url('program_image_principale_large', $image_principale);
}

$nouveau = isset($node->field_nouveau[LANGUAGE_NONE][0]['value']) ? $node->field_nouveau[LANGUAGE_NONE][0]['value'] : 0;
$caracteristiques = isset($node->field_caracteristiques[LANGUAGE_NONE]) ? $node->field_caracteristiques[LANGUAGE_NONE] : '';
$program_loc_ville = isset($node->field_programme_loc_ville[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_programme_loc_ville[LANGUAGE_NONE][0]['taxonomy_term']->name : '';

$trimstre_id = isset($node->field_trimestre[LANGUAGE_NONE][0]['value']) ? $node->field_trimestre[LANGUAGE_NONE][0]['value'] : '';
$trimstre = '';
if ($trimstre_id) {
  if ($trimstre_id == 1) {
    $trimstre = t('1er trimestre');
  }
  $trimstre = $trimstre_id . t('ème trimestre');
}

$annee = isset($node->field_annee[LANGUAGE_NONE][0]['value']) ? $node->field_annee[LANGUAGE_NONE][0]['value'] : '';
$flat_available = isset($node->field_programme_flat_available[LANGUAGE_NONE][0]['value']) ? $node->field_programme_flat_available[LANGUAGE_NONE][0]['value'] . t(' appartements disponibles') : '';
$pieces_min = isset($node->field_programme_room_min[LANGUAGE_NONE][0]['value']) ? $node->field_programme_room_min[LANGUAGE_NONE][0]['value'] : '';
$pieces_max = isset($node->field_programme_room_max[LANGUAGE_NONE][0]['value']) ? $node->field_programme_room_max[LANGUAGE_NONE][0]['value'] : '';

$de_a_pieces = '';
if ($pieces_min && $pieces_max) {
  $de_a_pieces = t('de') . ' ' . $pieces_min . ' ' . t('à') . ' ' . $pieces_max . ' ' . t('pièces');
}
elseif (!$pieces_min && $pieces_max) {
  $de_a_pieces = $pieces_max . ' ' . t('pièces');
}
elseif ($pieces_min && !$pieces_max) {
  $de_a_pieces = $pieces_min . ' ' . t('pièces');
}

$price_tva_min = isset($node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value']) : '';
$price_tva_max = isset($node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value']) : '';

$de_a_price_tva = '';
if ($price_tva_min && $price_tva_max) {
  $de_a_price_tva = 'De' . ' ' . $price_tva_min . '€' . ' ' . 'à' . ' ' . $price_tva_max . '€';
}
elseif (!$price_tva_min && $price_tva_max) {
  $de_a_price_tva = 'De' . ' ' . $price_tva_max . '€' . ' ' . 'à' . ' ' . $price_tva_max . '€';
}
elseif ($price_tva_min && !$price_tva_max) {
  $de_a_price_tva = 'De' . ' ' . $price_tva_min . '€' . ' ' . 'à' . ' ' . $price_tva_min . '€';
}

$tva = isset($node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name : '';

$price_min = isset($node->field_programme_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_min[LANGUAGE_NONE][0]['value']) : '';
$price_max = isset($node->field_programme_price_max[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_max[LANGUAGE_NONE][0]['value']) : '';

$de_a_price = '';
if ($price_min && $price_max) {
  $de_a_price = 'De' . ' ' . $price_min . '€' . ' ' . 'à' . ' ' . $price_max . '€';
}
elseif (!$price_min && $price_max) {
  $de_a_price = 'De' . ' ' . $price_max . '€' . ' ' . 'à' . ' ' . $price_max . '€';
}
elseif ($price_min && !$price_max) {
  $de_a_price = 'De' . ' ' . $price_min . '€' . ' ' . 'à' . ' ' . $price_min . '€';
}

$en_quelques_mots = isset($node->field_en_quelques_mots[LANGUAGE_NONE][0]['value']) ? $node->field_en_quelques_mots[LANGUAGE_NONE][0]['value'] : '';

$arr_document = array(
  'field_plaquette_commerciale',
  'field_fiche_renseignement',
  'field_plan_batiment',
  'field_kit_fiscal',
  'field_contrat_reservation',
  'field_etat_des_risques',
  'field_lettre_de_banque',
  'field_prestations_programme',
  'field_mandat_gestion_locative',
  'field_plan_masse_sous_sol',
  'visuel_grande_taille',
  'field_bail_commercial',
  'bon_commande_mobilier',
  'autre_documents'
);

$status_document = FALSE;
foreach ($arr_document as $field_name) {
  $document = isset($node->$field_name) ? $node->$field_name : '';
  if (isset($document[LANGUAGE_NONE][0]['fid'])) {
    $status_document = TRUE;
    break;
  }
}

$arr_slider = array(
  'field_slider_exterieur_titre',
  'field_slider_exterieur_desc',
  'field_slider_exterieur_image',
  'field_slider_interieur_titre',
  'field_slider_interieur_desc',
  'field_slider_interieur_image',
  'field_slider_securite_titre',
  'field_slider_securite_desc',
  'field_slider_securite_image',
  'field_slider_rt2012_titre',
  'field_slider_rt2012_image',
  'field_slider_rt2012_desc',
);

$status_slider = FALSE;
foreach ($arr_slider as $field_name) {
  $slider = isset($node->$field_name) ? $node->$field_name : '';
  if (isset($slider[LANGUAGE_NONE][0]['value']) || isset($slider[LANGUAGE_NONE][0]['fid'])) {
    $status_slider = TRUE;
    break;
  }
}

// Get promotion by programme nid.
$promotions = get_nids_promotions_by_programme($nid);
?>

<!-- [programHeader] start-->
<header class="programHeader">
    <!-- mobile heading-->
    <div class="wrapper show-for-small-only">
        <h1 class="heading heading--bordered">
            <?php if ($program_loc_ville) : ?>
              <div class="heading__title"><?php print $program_loc_ville; ?></div>
            <?php endif; ?>
            <?php if ($title) : ?>
              <div class="heading__title heading__title--sub"><?php print $title; ?></div>
            <?php endif; ?>
        </h1>
        <div class="tag tag--important"><?php print t('Nouveauté'); ?><sup>1</sup></div>
    </div>

    <div class="programHeader__figure">
        <!-- images need to have 2 formats see data-exchange attribute:
        - small: 640 x 316 (heavy compression)
        - medium: 1024 x 506
        - large: 1380 x 670
        -->
        <!-- [Responsive img] start--><img alt="Photo du programme" data-interchange="[<?php print $image_principale_small; ?>, (small)], [<?php print $image_principale_medium; ?>, (medium)], [<?php print $image_principale_large; ?>, (large)]"/>
        <noscript><img src="<?php print $image_principale_medium; ?>" alt="Photo du programme"/></noscript>
        <!-- [Responsive img] end-->
    </div>
    <div class="wrapper">
        <!-- [programHeader__content] start -->
        <div class="programHeader__content">
            <div class="toolbox">
                <!-- tablet+desktop heading-->
                <div class="show-for-medium-up">
                    <h1 class="heading heading--bordered">
                        <?php if ($program_loc_ville) : ?>
                          <div class="heading__title"><?php print $program_loc_ville; ?></div>
                        <?php endif; ?>
                        <?php if ($title) : ?>
                          <div class="heading__title heading__title--sub"><?php print $title; ?></div>
                        <?php endif; ?>
                    </h1>
                    <?php if ($nouveau) : ?>
                      <div class="tag tag--important"><?php print t('Nouveauté'); ?><sup>1</sup></div>
                    <?php endif; ?>
                    <?php if ($promotions) : ?>
                      <?php
                      foreach ($promotions as $promotion) :
                        $triger_promotion = 'promotion-' . $promotion->nid;
                        ?>
                        <button class="tag tag--important" data-reveal-trigger="<?php print $triger_promotion; ?>" class="tag" tabindex="0"><?php print $promotion->title; ?></button>
                        <!-- [popin] start-->
                        <div data-reveal="<?php print $triger_promotion; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                            <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $promotion->title; ?></strong></p>
                                <p><?php print $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']; ?></p>
                            </div>
                        </div>
                        <!-- [popin] end-->
                      <?php endforeach; ?>
                    <?php endif; ?>
                </div>

                <?php if ($trimstre || $annee || $flat_available || $de_a_pieces) : ?>
                  <p class="toolbox__intro">
                      <strong><?php print t('Livraison'); ?></strong>
                      <?php print t('à partir du'); ?>
                      <?php
                      if ($trimstre) : print $trimstre;
                      endif;
                      ?>
                      <?php
                      if ($annee) : print $annee . "<br>";
                      endif;
                      ?>
                      <?php
                      if ($flat_available) : print $flat_available;
                      endif;
                      ?>
                      <?php
                      if ($de_a_pieces) : print ', ' . $de_a_pieces;
                      endif;
                      ?>
                  </p>
                <?php endif; ?>
            </div>
            <?php if ($trimstre || $annee || $flat_available || $de_a_pieces) : ?>
              <p class="toolbox__intro">
                  <strong><?php print t('Livraison'); ?></strong>
                  <?php print t('à partir du'); ?>
                  <?php
                  if ($trimstre) : print $trimstre;
                  endif;
                  ?>
                  <?php
                  if ($annee) : print $annee . "<br>";
                  endif;
                  ?>
                  <?php
                  if ($flat_available) : print $flat_available;
                  endif;
                  ?>
                  <?php
                  if ($de_a_pieces) : print ', ' . $de_a_pieces;
                  endif;
                  ?>
              </p>
            <?php endif; ?>

            <?php if ($de_a_price_tva || $de_a_price) : ?>
              <ul class="content-price">
                  <?php if ($de_a_price_tva) : ?>
                    <li class="content-price__item">
                        <span class="text">
                            <?php
                            if ($de_a_price_tva) : print $de_a_price_tva;
                            endif;
                            ?>
                        </span>
                        <span class="tags">
                            <?php if ($tva) : ?>
                              <div class="tva"><?php print $tva; ?></div>
                            <?php endif; ?>
                            <a href="#" class="tva--btn"><span class="icon icon-arrow"></span><?php print t('Suis-je éligible?'); ?></a>
                        </span>
                    </li>
                  <?php endif; ?>
                  <?php if ($de_a_price) : ?>
                    <li class="content-price__item">
                        <span class="text">
                            <?php
                            if ($de_a_price) : print $de_a_price;
                            endif;
                            ?>
                        </span>
                        <span class="tags">
                            <div class="tva tva--high">TVA 20%</div>
                        </span>
                    </li>
                  <?php endif; ?>
              </ul>
            <?php endif; ?>


            <!-- [contactUs mini] start-->
            <?php
            if (function_exists('kandb_contact_block_page')) {
              print kandb_contact_block_page(TRUE);
            }
            ?>
            <!-- [contactUs mini] end-->
            <a href="#" class="save save--small"><span class="icon icon-love"></span><span class="text">Ajouter à mes sélections</span></a>
            <div class="sharing">
                <ul class="sharing__items">
                    <li class="sharing__items__item"><a href="javascript:window.print()" title="Imprimer la page" class="icon icon-print"></a></li>
                    <li class="sharing__items__item"><a href="#" title="partage par email" class="icon icon-email"></a></li>
                </ul>
            </div>
        </div>

        <div class="programHeader__content__details">
            <?php if ($caracteristiques) : ?>
              <ul class="characteristicList">
                  <?php
                  foreach ($caracteristiques as $caracteristique) {
                    if (isset($caracteristique['tid'])) {
                      $carac_term = taxonomy_term_load($caracteristique['tid']);
                      if ($carac_term) {
                        $picto_css_class = isset($carac_term->field_picto_css_class[LANGUAGE_NONE][0]['value']) ? $carac_term->field_picto_css_class[LANGUAGE_NONE][0]['value'] : '';
                        print '<li class="characteristicList__item"><span class="icon ' . $picto_css_class . '"></span><span class="text">' . $carac_term->name . '</span></li>';
                      }
                    }
                  }
                  ?>
              </ul>
            <?php endif; ?>
            <?php if ($en_quelques_mots) : ?>
              <p class="intro">
                  <em><?php print t('En quelques mots'); ?>&nbsp;</em><?php print $en_quelques_mots; ?>
              </p>
            <?php endif; ?>

            <?php if (isset($node->field_programme_mtn_legale[LANGUAGE_NONE][0]["value"])) : ?>
              <p class="intro">
                  <em><?php print t('Mentions Legales'); ?>&nbsp;</em><?php print $node->field_programme_mtn_legale[LANGUAGE_NONE][0]["value"]; ?>
              </p>
            <?php endif; ?>  

            <ul class="toolsList show-for-medium-up">
                <li><a href="#" class="btn-white"><span class="icon icon-planing"></span><span class="text">Logements disponibles</span></a></li>
                <li><a href="#" class="btn-white"><span class="icon icon-on-map"></span><span class="text">Quartier</span></a></li>
                <?php if ($status_slider) : ?>
                  <li><a href="#" class="btn-white"><span class="icon icon-prestation"></span><span class="text">Prestations</span></a></li>
                  >>>>>>> Stashed changes
                <?php endif; ?>
                <?php if ($en_quelques_mots) : ?>
                  <p class="intro">
                      <em><?php print t('En quelques mots'); ?>&nbsp;</em><?php print $en_quelques_mots; ?>
                  </p>
                <?php endif; ?>

                <?php if (isset($node->field_programme_mtn_legale[LANGUAGE_NONE][0]["value"])) : ?>
                  <p class="intro">
                      <em><?php print t('Mentions Legales'); ?>&nbsp;</em><?php print $node->field_programme_mtn_legale[LANGUAGE_NONE][0]["value"]; ?>
                  </p>
                <?php endif; ?>

                <ul class="toolsList show-for-medium-up">
                    <?php if ($flag) { ?>  <li><a href="#" class="btn-white"><span class="icon icon-planing "></span><span class="text">Logements disponibles</span></a></li><?php } ?>
                    <li><a href="javascript:void(0)"  class="btn-white"><span class="icon icon-on-map"></span><span class="text">Quartier</span></a></li>
                    <?php if ($status_slider) : ?>
                      <li><a href="#" class="btn-white"><span class="icon icon-prestation"></span><span class="text">Prestations</span></a></li>
                    <?php endif; ?>
                    <li><a href="#" data-cookie="<?php print $node->type; ?>" class="btn-white" data-cookie-add="<?php print $node->nid; ?>"><span class="icon icon-love"></span><span class="text">Ajouter à mes sélections</span></a></li>
                    <?php if ($status_document) : ?>
                      <li><a href="#" class="btn-white"><span class="icon icon-download"></span><span class="text"><?php print t('Documents téléchargeables'); ?></span></a></li>
                    <?php endif; ?>
                    <?php if ($habiteo_id) : ?>
                      <li><a href="#" class="btn-white"><span class="icon icon-cube"></span><span class="text"><?php print t('Vue 3D'); ?></span></a></li>
                    <?php endif; ?>
                </ul>
        </div>
    </div>
    <!-- [programHeader__content] end -->
</div>
</header>
<!-- [programHeader] end-->

<!-- [programParcel] start-->
<?php print render($logementBlock['content']); ?>
<!-- [programParcel] end-->

<!-- [3rd party: video-de-quartier] start-->
<section class="section-padding">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title"><?php print t('Un arrondissement'); ?></h2>
            <p class="heading__title heading__title--sub"><?php print t('à l’image des familles'); ?></p>
        </header>
    </div>
    <div class="swapItem">
        <div class="swapItem__2 ">
            <div class="wrapper--medium-up">
                <?php if ($habiteo_id): ?>
                  <div class="iframe iframe--video-de-quartier">
                      <iframe src="" data-src="http://widgets.habiteo.com/plan-de-quartier?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
                  </div>
                  <?php
                elseif ($lon && $lat):
                  $latitude = $lat / 1000000;
                  $longitude = $lon / 1000000;

                  $settings = array(
                    'id' => 'mymap',
                    'latitude' => $latitude, // center the map.
                    'longitude' => $longitude, // on the marker.
                    'zoom' => 10,
                    'width' => '100%',
                    'height' => '490px',
                    'type' => 'Map',
                  );

                  $settings['markers'] = array(
                    array(
                      'latitude' => $latitude,
                      'longitude' => $longitude,
                      'markername' => 'Kandb',
                    ),
                  );

                  $element = array(
                    '#type' => 'gmap',
                    '#gmap_settings' => $settings,
                  );
                  print '<div class="show-for-medium-up">';
                  print drupal_render($element);
                  print '</div>';
                endif;
                ?>
            </div>

            <div class="swapItem__1">
                <div class="wrapper">
                    <div class="heading heading--small text-center">
                        <h3 class="heading__title">Batignolles, la renaissance d’un quartier</h3>
                    </div>
                </div>
            </div>

            <div class="wrapper--medium-up">
                <?php if ($habiteo_id): ?>
                  <div class="iframe iframe--video-de-quartier">
                      <iframe src="" data-src="<?php print $habiteo_video_de_quartier_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
                  </div>
                <?php elseif ($video_id): ?>
                  <div class="iframe iframe--video-de-quartier">
                      <iframe frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" width="100%" src="https://www.youtube.com/embed/<?php print $video_id; ?>" class="iframe__content" frameborder="0" allowfullscreen></iframe>
                  </div>
                <?php endif; ?>
            </div>
        </div>

        <div class="swapItem__3">
            <div class="wrapper">
                <div class="content-centered">
                    <P>Le quartier des Batignolles a conservé des allures de village avec ses petits commerces, ses galeries d'art et ses nombreux espaces verts qui en font l'un des plus charmants de Paris.</P>
                </div>
            </div>
        </div>
    </div>
</section>

<?php print render($program_characteristic['content']); ?>

<!-- [3rd party: vue-generale] start-->
<?php if ($habiteo_id): ?>
  <section class="section-padding show-for-medium-up">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print t('Découvrez la modélisation 3D'); ?></h2>
          </header>
          <?php if ($habiteo_id): ?>
            <div class="iframe iframe--vue-generale">
                <iframe src="" data-src="<?php print $habiteo_vue_generale_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
            </div>
          <?php endif; ?>
          <div class="content-centered">
              <P>Le quartier des Batignolles a conservé des allures de village avec ses petits commerces, ses galeries d'art et ses nombreux espaces verts qui en font l'un des plus charmants de Paris.</P>
          </div>
      </div>
  </section>
<?php endif; ?>
<!-- [3rd party: vue-generale] start-->

<!-- [3rd party: vue-generale] start-->
<?php if ($habiteo_id): ?>
  <section class="section-padding show-for-medium-up">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print t('Découvrez la plan de masse 3D'); ?></h2>
          </header>
          <?php if ($habiteo_id): ?>
            <div class="iframe iframe--vue-generale">
                <iframe src="" data-src="<?php print $habiteo_vue_generale_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
            </div>
          <?php endif; ?>
          <div class="content-centered">
              <P>Le quartier des Batignolles a conservé des allures de village avec ses petits commerces, ses galeries d'art et ses nombreux espaces verts qui en font l'un des plus charmants de Paris.</P>
          </div>
      </div>
  </section>
<?php endif; ?>
<!-- [3rd party: vue-generale] start-->
<!-- [programDocumentDownload] start-->

<?php
$list_document = array();

if (!empty($file_plaquette_commerciale)) {
  $list_document[] = array(
    'document' => $file_plaquette_commerciale,
    'title' => t('Plaquette commerciale'),
    'icon' => 'icon-flyer'
  );
}
if (!empty($file_fiche_renseignement)) {
  $list_document[] = array(
    'document' => $file_fiche_renseignement,
    'title' => t('Fiche Renseignement'),
    'icon' => 'icon-file'
  );
}

if (!empty($file_plan_batiment)) {
  $list_document[] = array(
    'document' => $file_plan_batiment,
    'title' => t('Plan du bâtiment'),
    'icon' => 'icon-planing '
  );
}
if (!empty($file_kit_fiscal)) {
  $list_document[] = array(
    'document' => $file_kit_fiscal,
    'title' => t('Kit fiscal'),
    'icon' => 'icon-calculator'
  );
}

if (!empty($list_document)):
  ?>
  <section class="section-padding">
      <div class="wrapper">
          <div class="programDocumentDownload">
              <?php
              $nocontent = 'data-reveal-id="downloadInformationForm"';
              ?>
              <div class="programDocumentDownload__heading">
                  <header class="heading">
                      <h2 class="heading__title">Documents <br>téléchargeables</h2>
                  </header>
                  <a  href="<?php if (isset($link_to_zip) && $link_to_zip) print $link_to_zip; ?>">
                      <button <?php if (!isset($link_to_zip) || !$link_to_zip) print $nocontent; ?> class="btn-primary btn-rounded hide-for-small-only">
                          Tout télécharger (.zip)</button></a>
              </div>
              <div class="programDocumentDownload__items">
                  <ul class="row">
                      <?php foreach ($list_document as $item): ?>
                        <li class="programDocumentDownload__items__item">
                            <a href="<?php print file_create_url($item["document"]) ?>" <?php if (!$item["document"]) print $nocontent; ?> >
                                <span class="icon <?php print $item["icon"] ?>"></span>
                                <div class="heading heading--small">
                                    <div class="heading__title"><?php print $item["title"] ?></div>
                                </div>
                            </a>
                        </li>
                      <?php endforeach; ?>
                  </ul>
              </div>
              <div class="btn-wrapper btn-wrapper--center show-for-small-only">
                  <a  href="<?php if (isset($link_to_zip) && $link_to_zip) print $link_to_zip; ?>"><button <?php if (!isset($link_to_zip) || !$link_to_zip) print $nocontent; ?> class="btn-primary btn-rounded btn-download">Tout télécharger (.zip)</button></a>
              </div>
              <!-- [popin] start-->
              <div id="downloadInformationForm" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                  <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                      <div class="programDocumentDownload__content">
                          <p>Content Update later</p>
                      </div>
                  </div>
              </div>
              <!-- [popin] end-->
          </div>
      </div>
  </section>
<?php endif; ?>
<!-- [programDocumentDownload] end-->
<?php
$region_id = isset($node->field_programme_loc_region[LANGUAGE_NONE][0]['tid']) ? $node->field_programme_loc_region[LANGUAGE_NONE][0]['tid'] : '';
$programme_carousel = '';
if ($region_id) {
  $programme_carousel = views_embed_view('nos_dernieres_offres', 'block_1', array($region_id));
}

if ($region_id && $programme_carousel):
  ?>
  <!-- [offers] start-->
  <section class="section-padding bg-lightGrey">
      <div class="wrapper">
          <h2 class="heading--tiny"><?php print t('Les programmes les plus proches'); ?></h2>
          <?php print $programme_carousel; ?>
          <div class="btn-wrapper btn-wrapper--center"><a href="#" class="btn-rounded btn-primary"><?php print t('Voir toutes nos offres'); ?><span class="icon icon-arrow"></span></a>
          </div>
      </div>
  </section>
  <!-- [offers] end-->
<?php endif; ?>
<!-- [contactUs complete] start-->
<!-- [contactUs complete] end-->

<?php
if (function_exists('kandb_contact_specific_block_page')) {
  print kandb_contact_specific_block_page($node);
}
?>