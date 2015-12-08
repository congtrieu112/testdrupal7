<!-- [programHeader] start-->
<header class="programHeader">
    <!-- mobile heading-->
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
                          <div class="heading__title">
                            <?php print $program_loc_ville; ?>
                               <?php
                                if ($programme_loc_arr_name) :
                                  print '(' .$programme_loc_arr_name. ')';
                                elseif ($program_loc_department) :
                                  print '(' . $program_loc_department. ')';
                                endif;
                            ?>
                          </div>
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
                        <button class="tag tag--important" data-reveal-trigger="<?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $triger_promotion : ''; ?>" class="tag" tabindex="0"><?php print $promotion->title; ?></button>
                        <!-- [popin] start-->
                        <div data-reveal="<?php print $triger_promotion; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                            <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $promotion->title; ?></strong></p>
                                <p><?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value'] : ''; ?></p>
                            </div>
                        </div>
                        <!-- [popin] end-->
                      <?php endforeach; ?>
                    <?php endif; ?>
                </div>

                <?php if ($trimstre && $annee && $flat_available && $de_a_pieces) : ?>
                  <p class="toolbox__intro">
                      <strong><?php print t('Livraison'); ?></strong>
                      <?php print t('à partir du'); ?>
                      <?php if ($trimstre) print $trimstre; ?>
                      <?php if ($annee) print $annee; ?>
                      <br/>
                      <?php if ($flat_available) print $flat_available; ?>
                      <?php if ($de_a_pieces) print ', ' . $de_a_pieces; ?>
                  </p>
                <?php endif; ?>


                <?php if ($de_a_price_tva || $de_a_price) : ?>
                  <ul class="content-price">
                      <?php if ($de_a_price_tva && $affichage_double_grille && $tva) : ?>
                        <li class="content-price__item">
                            <span class="text">
                                <?php if ($de_a_price_tva) print $de_a_price_tva; ?>
                            </span>
                            <span class="tags">
                                <?php if ($tva) : ?>
                                  <div class="tva"><?php print $tva; ?></div>
                                <?php endif; ?>
                                <?php /* TODO : <a href="#" class="tva--btn"><span class="icon icon-arrow"></span><?php print t('Suis-je éligible?'); ?></a>--> */ ?>
                            </span>
                        </li>
                      <?php endif; ?>
                      <?php if ($de_a_price) : ?>
                        <li class="content-price__item">
                            <span class="text">
                                <?php if ($de_a_price) print $de_a_price; ?>
                            </span>
                            <span class="tags">
                                <?php if($tva) : ?>
                                  <div class="tva tva--high">TVA 20%</div>
                                <?php endif; ?>
                            </span>
                        </li>
                      <?php endif; ?>
                  </ul>
                <?php endif; ?>

                <?php /* TODO :<!-- <p class="toolbox__intro">Parking extérieur à partir de 10.000€</p> --> */ ?>

                <!-- [contactUs mini] start-->
                <?php
                if (function_exists('kandb_contact_block_page')) {
                  print kandb_contact_block_page(TRUE);
                }
                ?>
                <!-- [contactUs mini] end-->

                <?php /* TODO : Sharing information */ ?>
                <!-- <a href="#" class="save save--small"><span class="icon icon-love"></span><span class="text">Ajouter à mes sélections</span></a>
                <div class="sharing">
                    <ul class="sharing__items">
                        <li class="sharing__items__item"><a href="javascript:window.print()" title="Imprimer la page" class="icon icon-print"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage par email" class="icon icon-email"></a></li>
                    </ul>
                </div>-->
            </div>
            <div class="programHeader__content__details">
                <ul class="characteristicList">
                    <?php
                    if ($caracteristiques):
                      foreach ($caracteristiques as $caracteristique):
                        if (isset($caracteristique['tid'])) :
                          $carac_term = taxonomy_term_load($caracteristique['tid']);
                          if ($carac_term) :
                            $picto_css_class = isset($carac_term->field_picto_css_class[LANGUAGE_NONE][0]['value']) ? $carac_term->field_picto_css_class[LANGUAGE_NONE][0]['value'] : '';
                            print '<li class="characteristicList__item"><span class="icon ' . $picto_css_class . '"></span><span class="text">' . $carac_term->name . '</span>';
                            if ($carac_term->description) :
                              print '<span data-tooltip="" aria-haspopup="true" class="has-tip" data-selector="tooltip-ihrbj73c0" aria-describedby="tooltip-ihrbj73c0" title="'. $carac_term->description.'">?</span>';
                            endif;
                            print '</li>';
                          endif;
                        endif;
                      endforeach;
                    endif;
                    $etages = field_get_items('node', $node, 'field_caracteristique_etages');
                    if (isset($etages[0]['value']) && $etages[0]['value']) :
                      if ($icons = array_values(taxonomy_get_term_by_name('Etages'))[0]) :
                        $class_icon = isset($icons->field_icon_name[LANGUAGE_NONE][0]) ? $icons->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                        print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span><span class="text">' . $icons->name . '</span>';
                        if ($icons->description):
                          print '<span data-tooltip="" aria-haspopup="true" class="has-tip" data-selector="tooltip-ihrbj73c0" aria-describedby="tooltip-ihrbj73c0" title="'. $icons->description.'">?</span>';
                        endif;
                        print '</li>';
                      endif;
                    endif;
                    $chauffage = field_get_items('node', $node, 'field_caracteristique_chauffage');
                    if (isset($chauffage[0]['value']) && $chauffage[0]['value']) :
                      if ($icons = array_values(taxonomy_get_term_by_name('Chauffage'))[0]) :
                        $class_icon = isset($icons->field_icon_name[LANGUAGE_NONE][0]) ? $icons->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                        print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span><span class="text">' . $icons->name . '</span>';
                        if ($icons->description):
                          print '<span data-tooltip="" aria-haspopup="true" class="has-tip" data-selector="tooltip-ihrbj73c0" aria-describedby="tooltip-ihrbj73c0" title="'. $icons->description.'">?</span>';
                        endif;
                        print '</li>';
                      endif;
                    endif;
                    ?>
                </ul>

                <?php if ($en_quelques_mots) : ?>
                  <p class="intro">
                      <?php print $en_quelques_mots; ?>
                  </p>
                <?php endif; ?>

                <?php if ($programme_mtn_legale) : ?>
                  <p class="intro">
                      <em><?php print t('Mentions Legales:'); ?>&nbsp;</em><?php print $programme_mtn_legale; ?>
                  </p>
                <?php endif; ?>

                <ul class="toolsList show-for-medium-up">
                    <?php if ($flag) : ?>
                      <li><a href="#logements-disponibles" class="btn-white"><span class="icon icon-planing "></span><span class="text">Logements disponibles</span></a></li>
                    <?php endif; ?>

                    <li><a href="#quartier" class="btn-white"><span class="icon icon-on-map"></span><span class="text">Quartier</span></a></li>

                    <?php if ($status_slider) : ?>
                      <li><a href="#prestations" class="btn-white"><span class="icon icon-prestation"></span><span class="text">Prestations</span></a></li>
                    <?php endif; ?>

                    <li><a href="#" data-cookie="<?php print $node->type; ?>" class="btn-white" data-cookie-add="<?php print $node->nid; ?>"><span class="icon icon-love"></span><span class="text"><?php print t('Ajouter à mes sélections'); ?></span></a></li>

                    <?php if ($status_document) : ?>
                      <li><a href="#downloadDocument" class="btn-white"><span class="icon icon-download"></span><span class="text"><?php print t('Documents téléchargeables'); ?></span></a></li>
                    <?php endif; ?>

                    <?php if ($habiteo_id) : ?>
                      <li><a href="#Vue3D" class="btn-white"><span class="icon icon-cube"></span><span class="text"><?php print t('Vue 3D'); ?></span></a></li>
                    <?php endif; ?>
                </ul>
            </div>
        </div>
    </div>
    <!-- [programHeader__content] end -->
</header>
<!-- [programHeader] end-->

<!-- [programParcel] start-->
<?php print render($logementBlock['content']); ?>
<!-- [programParcel] end-->

<!-- [3rd party: video-de-quartier] start-->
<section class="section-padding" id="quartier" >
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title"><?php print isset($field_quartier_titre[0]['value']) ? $field_quartier_titre[0]['value'] : ''; ?></h2>
            <p class="heading__title heading__title--sub"><?php print isset($field_quartier_titre[0]['value']) ? $field_quartier_titre[0]['value'] : ''; ?></p>
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
                  $settings = array(
                    'id' => 'mymap',
                    'latitude' => $lat, // center the map.
                    'longitude' => $lon, // on the marker.
                    'zoom' => 10,
                    'width' => '100%',
                    'height' => '490px',
                    'type' => 'Map',
                  );

                  $settings['markers'] = array(
                    array(
                      'latitude' => $lat,
                      'longitude' => $lon,
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

                  if ($video_id):
                    ?>
                    <div class="iframe iframe--video-de-quartier">
                        <iframe frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" width="100%" src="https://www.youtube.com/embed/<?php print $video_id; ?>" class="iframe__content" frameborder="0" allowfullscreen></iframe>
                    </div>
                    <?php
                  endif;
                endif;
                ?>
            </div>
        </div>

        <div class="swapItem__1">
            <div class="wrapper">
                <div class="heading heading--small text-center">
                    <h3 class="heading__title"><?php print isset($field_quartier_video_titre[0]['value']) ? $field_quartier_video_titre[0]['value'] : ''; ?></h3>
                </div>
            </div>
        </div>

        <div class="swapItem__3">
            <div class="wrapper">
                <div class="content-centered">
                    <p><?php print isset($field_quartier_video_desc[0]['value']) ? $field_quartier_video_desc[0]['value'] : ''; ?></p>
                </div>
            </div>
        </div>
    </div>
</section>

<?php print render($program_characteristic['content']); ?>

<!-- [3rd party: vue-generale] start-->
<?php if ($habiteo_id): ?>
  <section class="section-padding show-for-medium-up" id="Vue3D">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print t('Découvrez la modélisation 3D'); ?></h2>
          </header>
          <?php if ($habiteo_id): ?>
            <div class="iframe iframe--vue-generale">
                <iframe src="" data-src="<?php print $habiteo_vue_generale_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
            </div>
          <?php endif; ?>
      </div>
  </section>
<?php endif; ?>
<!-- [3rd party: vue-generale] start-->

<!-- [3rd party: vue-generale] start-->
<?php if ($habiteo_id): ?>
  <section class="section-padding show-for-medium-up" id="Vue3D" >
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print t('Découvrez la plan de masse 3D'); ?></h2>
          </header>
          <?php if ($habiteo_id): ?>
            <div class="iframe iframe--vue-generale">
                <iframe src="" data-src="<?php print $habiteo_plan_3d_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
            </div>
          <?php endif; ?>
          <div class="content-centered">
              <?php // TODO : // <p>Le quartier des Batignolles a conservé des allures de village avec ses petits commerces, ses galeries d'art et ses nombreux espaces verts qui en font l'un des plus charmants de Paris.</p>   ?>
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
          <div class="programDocumentDownload" id="downloadDocument">
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
                  <div class="btn-wrapper btn-wrapper--center show-for-small-only">
                      <button <?php print (isset($link_to_zip) AND ! empty($link_to_zip)) ? 'onclick="window.location.href=\'' . $link_to_zip . '\'"' : $nocontent; ?> class="btn-primary btn-rounded btn-download">
                          <?php print t('Tout télécharger (.zip)'); ?>
                      </button>
                  </div>
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

