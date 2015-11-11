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
$nouveau = isset($node->field_nouveau[LANGUAGE_NONE][0]['value']) ? $node->field_nouveau[LANGUAGE_NONE][0]['value'] : 0;
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
} elseif (!$pieces_min && $pieces_max) {
  $de_a_pieces = $pieces_max . ' ' . t('pièces');
} elseif ($pieces_min && !$pieces_max) {
  $de_a_pieces = $pieces_min . ' ' . t('pièces');
}

$price_tva_min = isset($node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value']) ? $node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value'] : '';
$price_tva_max = isset($node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value']) ? $node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value'] : '';

$de_a_price_tva = '';
if ($price_tva_min && $price_tva_max) {
  $de_a_price_tva = 'De' . ' ' . number_format($price_tva_min, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . number_format($price_tva_max, 0, ",", " ") . '€';
} elseif (!$price_tva_min && $price_tva_max) {
  $de_a_price_tva = 'De' . ' ' . number_format($price_tva_max, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . number_format($price_tva_max, 0, ",", " ") . '€';
} elseif ($price_tva_min && !$price_tva_max) {
  $de_a_price_tva = 'De' . ' ' . number_format($price_tva_min, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . number_format($price_tva_min, 0, ",", " ") . '€';
}

$tva = isset($node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name : '';

$price_min = isset($node->field_programme_price_min[LANGUAGE_NONE][0]['value']) ? $node->field_programme_price_min[LANGUAGE_NONE][0]['value'] : '';
$price_max = isset($node->field_programme_price_max[LANGUAGE_NONE][0]['value']) ? $node->field_programme_price_max[LANGUAGE_NONE][0]['value'] : '';

$de_a_price = '';
if ($price_min && $price_max) {
  $de_a_price = 'De' . ' ' . number_format($price_min, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . number_format($price_max, 0, ",", " ") . '€';
} elseif (!$price_min && $price_max) {
  $de_a_price = 'De' . ' ' . number_format($price_max, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . number_format($price_max, 0, ",", " ") . '€';
} elseif ($price_min && !$price_max) {
  $de_a_price = 'De' . ' ' . number_format($price_min, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . number_format($price_min, 0, ",", " ") . '€';
}

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
foreach($arr_document as $field_name) {
  $document = $node->$field_name;
  if(isset($document[LANGUAGE_NONE][0]['value'])) {
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
foreach($arr_slider as $field_name) {
  $slider = $node->$field_name;
  if(isset($slider[LANGUAGE_NONE][0]['value']) || $slider[LANGUAGE_NONE][0]['fid']) {
    $status_slider = TRUE;
    break;
  }
}

//krumo($node);
?>


<!-- [programHeader] start-->
<header class="programHeader">
    <!-- mobile heading-->
    <div class="wrapper show-for-small-only">
        <h1 class="heading heading--bordered">
            <div class="heading__title">Paris 17</div>
            <div class="heading__title heading__title--sub">&Eacute;mergence</div>
        </h1>
        <div class="tag tag--important">Nouveauté<sup>1</sup></div>
    </div>
    <div class="programHeader__figure">
        <!-- images need to have 2 formats see data-exchange attribute:
        - small: 640 x 316 (heavy compression)
        - medium: 1024 x 506
        - large: 1380 x 670
        -->
        <!-- [Responsive img] start--><img alt="Photo du programme" data-interchange="[test_assets/programHeader-small.jpg, (small)], [test_assets/programHeader-medium.jpg, (medium)], [<?php print $path_img; ?>programHeader-large.jpg, (large)]"/>
        <noscript><img src="<?php print $path_img; ?>programHeader-medium.jpg" alt="Photo du programme"/></noscript>
        <!-- [Responsive img] end-->
    </div>
    <div class="wrapper programHeader__content">
        <div class="toolbox">
            <!-- tablet+desktop heading-->
            <div class="show-for-medium-up">
                <h1 class="heading heading--bordered">
                    <?php if ($program_loc_ville) : ?>
                      <div class="heading__title"><?php print $program_loc_ville; ?> 17</div>
                    <?php endif; ?>
                    <?php if ($title) : ?>
                      <div class="heading__title heading__title--sub"><?php print $title; ?></div>
                    <?php endif; ?>
                </h1>
                <?php if ($nouveau) : ?>
                  <div class="tag tag--important"><?php print t('Nouveauté'); ?><sup>1</sup></div>
                <?php endif; ?>

            </div>
            <p class="toolbox__intro"><strong><?php print t('Livraison'); ?></strong> à partir du <?php if ($trimstre) : print $trimstre;
                endif; ?> <?php if ($annee) : print $annee;
                endif; ?> <br><?php if ($flat_available) : print $flat_available;
                endif; ?> <?php if ($de_a_pieces) : print ', ' . $de_a_pieces;
                endif; ?></p>
            <ul class="content-price">
                <li class="content-price__item"><span class="text"><?php if ($de_a_price_tva) : print $de_a_price_tva;
                endif; ?></span><span class="tags">
                        <?php if($tva) : ?>
                          <div class="tva"><?php print $tva; ?></div>
                        <?php endif; ?>
                        <a href="#" class="tva--btn"><span class="icon icon-arrow"></span><?php print t('Suis-je éligible?'); ?></a></span></li>
                <li class="content-price__item"><span class="text"><?php if($de_a_price) : print $de_a_price; endif;?></span><span class="tags">
                        <div class="tva tva--high">TVA 20%</div></span></li>
            </ul>
            <p class="toolbox__intro">Parking extérieur à partir de 10.000€</p>
            <!-- [contactUs mini] start-->
            <aside class="contactUs-mini"><a href="tel://0800544000" class="phone-green"><span>N°&nbsp;vert&nbsp;</span>0 800 544 000</a>
                <div class="contactUs__cta"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-primary btn-rounded">Rappelez moi</a><a href="partials/formRendezVous.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-secondary btn-rounded">Prendre rendez-vous</a></div>
            </aside>
            <!-- [contactUs mini] end--><a href="#" class="save save--small"><span class="icon icon-love"></span><span class="text">Ajouter à mes sélections</span></a>
            <div class="sharing">
                <ul class="sharing__items">
                    <li class="sharing__items__item"><a href="javascript:window.print()" title="Imprimer la page" class="icon icon-print"></a></li>
                    <li class="sharing__items__item"><a href="#" title="partage par email" class="icon icon-email"></a></li>
                    <li class="sharing__items__item"><a href="#" title="partage sur Facebook" class="icon icon-facebook"></a></li>
                    <li class="sharing__items__item"><a href="#" title="partage sur Twitter" class="icon icon-twitter"></a></li>
                    <li class="sharing__items__item"><a href="#" title="partage sur Whatsapp" class="icon icon-phone-call"></a></li>
                </ul>
            </div>
        </div>
        <div class="programHeader__content__details">
            <ul class="characteristicList">
                <li class="characteristicList__item"><span class="icon icon-sun"></span><span class="text">Sud - Sud Est</span></li>
                <li class="characteristicList__item"><span class="icon icon-building"></span><span class="text">4<sup>ème</sup> étage</span></li>
                <li class="characteristicList__item"><span class="icon icon-balcony"></span><span class="text">Balcony</span></li>
                <li class="characteristicList__item"><span class="icon icon-car"></span><span class="text">Parking</span></li>
            </ul>
            <p class="intro"><em>En quelques mots</em> Un quartier vivant à deux pas de Paris <strong>Un cadre idéal pour les familles</strong> Des volumes spacieux <strong>Proche des transports en commun</strong></p>
            <ul class="toolsList show-for-medium-up">
                <li><a href="#" class="btn-white"><span class="icon icon-plan"></span><span class="text">Logements disponibles</span></a></li>
                <li><a href="#" class="btn-white"><span class="icon icon-on-map"></span><span class="text">Quartier</span></a></li>
                <?php if($status_slider) : ?>
                  <li><a href="#" class="btn-white"><span class="icon icon-prestation"></span><span class="text">Prestations</span></a></li>
                <?php endif; ?>
                <li><a href="#" class="btn-white"><span class="icon icon-love"></span><span class="text">Ajouter à mes sélections</span></a></li>
                <?php if($status_document) : ?>
                  <li><a href="#" class="btn-white"><span class="icon icon-download"></span><span class="text"><?php print t('Documents téléchargeables'); ?></span></a></li>
                <?php endif; ?>
                <?php if($habiteo_id) : ?>
                  <li><a href="#" class="btn-white"><span class="icon icon-cube"></span><span class="text"><?php print t('Vue 3D'); ?></span></a></li>
                <?php endif; ?>
            </ul>
        </div>
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
        <div class="swapItem__2">
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
                    'type' => 'Satellite',
                  );

                  $settings['markers'] = array(
                    array(
                      'latitude' => $latitude,
                      'longitude' => $longitude,
                    ),
                  );

                  $element = array(
                    '#type' => 'gmap',
                    '#gmap_settings' => $settings,
                  );
                  print drupal_render($element);

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
    'title' => t('Plaquette commerciale')
  );
}
if (!empty($file_fiche_renseignement)) {
  $list_document[] = array(
    'document' => $file_fiche_renseignement,
    'title' => t('Kit juridique')
  );
}
if (!empty($file_plan_batiment)) {
  $list_document[] = array(
    'document' => $file_plan_batiment,
    'title' => t('Kit fiscal')
  );
}
if (!empty($file_plan_batiment)) {
  $list_document[] = array(
    'document' => $file_plan_batiment,
    'title' => t('Plan du bâtiment')
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
                            <a href="<?php print file_create_url($item["document"]) ?>" <?php if (!$item["document"]) print $nocontent; ?> ><span class="icon icon-flyer"></span>
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

<!-- [offers] start-->
<section class="section-padding bg-lightGrey">
    <div class="wrapper">
        <h2 class="heading--tiny">Les programmes les plus proches</h2>
        <!-- [carousel] start-->
        <div data-slick="{&quot;slidesToShow&quot;: 3, &quot;slidesToScroll&quot;: 3}" class="slick-slider__item-3">
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/>
                        <ul class="squaredImageItem__img__tags">
                            <li>
                                <div class="tag tag--important">Plus que deux T3 disponibles</div>
                            </li>
                            <li>
                                <div class="tag">TVA 7%<sup>(2)</sup></div>
                            </li>
                            <li>
                                <div class="tag">Livraison immédiate<sup>(1)</sup></div>
                            </li>
                        </ul></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
        </div>
        <!-- [carousel] end-->

        <div class="btn-wrapper btn-wrapper--center"><a href="#" class="btn-rounded btn-primary">Voir toutes nos offres<span class="icon icon-arrow"></span></a>
        </div>
    </div>
</section>
<!-- [offers] end-->
<!-- [contactUs complete] start-->
<!-- [contactUs complete] end-->