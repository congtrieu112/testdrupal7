<!-- [programHeader] start-->
<header class="programHeader headerB2B">
    <!-- mobile heading-->
    <div class="wrapper show-for-small-only">
        <h1 class="heading heading--bordered">
            <?php if ($program_loc_ville) : ?>
                <div class="heading__title">
                    <?php print $program_loc_ville; ?>
                    <?php
                    if ($programme_loc_arr_name) :
                        print $programme_loc_arr_name;
                    elseif ($program_loc_department) :
                        print $program_loc_department;
                    endif;
                    ?>
                </div>
            <?php endif; ?>
            <?php if ($title) : ?>
                <div class="heading__title heading__title--sub"><?php print $title; ?></div>
            <?php endif; ?>
        </h1>
        <?php print $address ; ?>
        <ul class="tags-list">
            <?php if ($nouveau) : ?>
                <li>
                    <div class="tag tag--important"><?php print t('Nouveauté'); ?></div>
                </li>
            <?php endif; ?>
            <?php
            if ($promotions) :
                foreach ($promotions as $promotion) :
                    $triger_promotion = 'promotion-' . $promotion->nid;
                    if (isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) && $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) :
                        ?>
                        <li>
                            <button class="tag tag--important" data-reveal-trigger="<?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $triger_promotion : ''; ?>" class="tag" tabindex="0"><?php print $promotion->title; ?></button>
                            <div data-reveal="<?php print $triger_promotion; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                    <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $promotion->title; ?></strong></p>
                                    <p><?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value'] : ''; ?></p>
                                </div>
                            </div>
                            <!-- [popin] end-->
                        </li>
                    <?php else : ?>
                        <li>
                            <div class="tag tag--important"><?php print $promotion->title; ?></div>
                        </li>
                    <?php endif; ?>
                <?php endforeach; ?>
            <?php endif; ?>
        </ul>
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
            <!-- [toolbox] start -->
            <div class="toolbox">
              <h1 class="heading heading--bordered heading--inline">
                <?php if ($loc_num || $loc_rue) : ?>
                  <div class="heading__title">
                    <?php print $loc_num; ?>
                    <?php print $loc_rue; ?>
                  </div>
                <?php endif; ?>
                <?php if ($title) : ?>
                  <div class="heading__title heading__title--sub"><?php print $title; ?></div>
                <?php endif; ?>
              </h1>
              <?php print $address; ?>
              <?php if ($nouveau) : ?>
                <div class="tag tag--important">Nouveauté<sup>1</sup></div>
              <?php endif; ?>
              <?php
                if ($promotions) :
                    foreach ($promotions as $promotion) :
                        $triger_promotion = 'promotion-' . $promotion->nid;
                        if (isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) && $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) :
                          ?>
                          <button class="tag tag--important" data-reveal-trigger="<?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $triger_promotion : ''; ?>" class="tag" tabindex="0"><?php print $promotion->title; ?></button>
                          <div data-reveal="<?php print $triger_promotion; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                              <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                  <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $promotion->title; ?></strong></p>
                                  <p><?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value'] : ''; ?></p>
                              </div>
                          </div>
                          <!-- [popin] end-->
                        <?php else : ?>
                          <div class="tag tag--important"><?php print $promotion->title; ?></div>
                        <?php endif; ?>
                    <?php endforeach; ?>
                <?php endif; ?>
              <div class="toolbox__content">
                <?php if ($flat_available && $de_a_pieces) :  ?>
                <h3 class="heading__title toolbox__heading">
                  <?php print $flat_available; ?>
                  <?php print $de_a_pieces; ?>
                </h3>
                <?php endif; ?>

                <?php if ($de_a_price_tva || $de_a_price) : ?>
                  <ul class="content-price">
                    <?php if ($de_a_price_tva && $affichage_double_grille && $tva) : ?>
                    <li class="content-price__item">
                      <span class="text"><?php print $de_a_price_tva; ?></span>
                      <span class="tags">
                        <div class="tva"><?php print $tva; ?></div>
                      </span>
                    </li>
                    <?php endif; ?>
                    <?php if ($de_a_price) : ?>
                    <li class="content-price__item">
                      <span class="text"><?php print $de_a_price; ?></span>
                      <span class="tags">
                        <div class="tva tva--high">TVA 20%</div>
                      </span>
                    </li>
                    <?php endif; ?>
                  </ul>
                <?php endif; ?>
                <?php if($livraison_date || $actabilite_date) : ?>
                <!-- [programDelivery] start-->
                <div class="programDelivery">
                  <?php if($livraison_date) : ?>
                  <div class="programDelivery__column">
                    <p><?php print t('Date de livraison prévisionnelle'); ?></p>
                    <p class="text-bold"><?php print date('d.m.Y', strtotime($livraison_date)); ?></p>
                  </div>
                  <?php endif; ?>
                  <?php if($actabilite_date) : ?>
                  <div class="programDelivery__column">
                    <p><?php print t('Date d’actabilité'); ?></p>
                    <p class="text-bold"><?php print date('d.m.Y', strtotime($actabilite_date)); ?></p>
                  </div>
                  <?php endif; ?>
                </div>
                <?php endif; ?>
                <!-- [programDelivery] end-->
                <a href="<?php if (isset($link_to_zip) && $link_to_zip) print $link_to_zip; ?>" class="programHeader__download btn-primary btn-rounded"><?php print t('Télécharger les documents'); ?></a>
                <!-- [show-for-medium-up] start-->
                <div class="show-for-medium-up">
                  <div class="sharing">
                    <ul class="sharing__items">
                      <li class="sharing__items__item"><a href="javascript:window.print()" title="<?php print t('Imprimer la page'); ?>" class="icon icon-print"></a></li>
                      <?php if ($email = variable_get('kb_partage_email')) : ?>
                      <li class="sharing__items__item">
                        <a href="mailto:<?php print $email;  ?>" title="<?php print t('partage par email'); ?>" class="icon icon-email"></a>
                      </li>
                      <?php endif; ?>
                    </ul>
                  </div>
                </div>
                <!-- [show-for-medium-up] end-->
              </div>
            </div>
            <!-- [toolbox] end -->
            <div class="programHeader__content__details">
              <ul class="characteristicList">
                <?php
                $vocabulary_name = 'caracteristiques_programme';
                $flag_etages = $flag_chauffage = TRUE;
                if ($caracteristiques):
                  foreach ($caracteristiques as $caracteristique):
                    if (isset($caracteristique['tid'])) :
                      $carac_term = taxonomy_term_load($caracteristique['tid']);
                      if ($carac_term) :
                        if ($carac_term->name == "Etages")
                          $flag_etages = FALSE;
                        if ($carac_term->name == "Chauffage"):
                          $flag_chauffage = FALSE;
                          if ($node->field_caracteristique_chauffage[LANGUAGE_NONE][0]['tid']):
                            $chauffage = taxonomy_term_load($node->field_caracteristique_chauffage[LANGUAGE_NONE][0]['tid']);
                          endif;
                        endif;
                        $picto_css_class = isset($carac_term->field_picto_css_class[LANGUAGE_NONE][0]['value']) ? $carac_term->field_picto_css_class[LANGUAGE_NONE][0]['value'] : '';
                        print '<li class="characteristicList__item"><span class="icon ' . $picto_css_class . '"></span>';
                        print '<span class="text">' . $carac_term->name . ' ' . (($carac_term->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip"  title="' . $carac_term->description . '"></span>' : '') . '</span>';
                        print '</li>';
                      endif;
                    endif;
                  endforeach;
                endif;
                $etages = field_get_items('node', $node, 'field_caracteristique_etages');
                if (isset($etages[0]['value']) && $etages[0]['value']) :
                  if (($icons = get_taxonomy_by_vocabulary_name('Etages', $vocabulary_name))):
                    if ($flag_etages):
                      if (($node->field_caracteristique_etages['und'][0]['value'] && $node->field_caracteristique_etages['und'][0]['value'] <= 1)):
                        $icons[0]->name = str_replace('s', '', $icons[0]->name);
                      endif;
                      $class_icon = isset($icons[0]->field_picto_css_class[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_picto_css_class[LANGUAGE_NONE][0]['value'] : '';
                      print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                      print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip"  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                      print '</li>';
                    endif;
                  endif;
                endif;
                $chauffage = field_get_items('node', $node, 'field_caracteristique_chauffage');
                if (isset($chauffage[0]['tid']) && $chauffage[0]['tid']) :
                  if ($icons = get_taxonomy_by_vocabulary_name('Chauffage', $vocabulary_name)):
                    if ($flag_chauffage):
                      $chauffage = taxonomy_term_load($chauffage[0]['tid']);
                      $class_icon = isset($icons[0]->field_picto_css_class[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_picto_css_class[LANGUAGE_NONE][0]['value'] : '';
                      print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                      print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip"  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                      print '</li>';
                    endif;
                  endif;
                endif;
                ?>
              </ul>

              <?php if ($en_quelques_mots) : ?>
                <p class="intro">
                  <em><?php print t('En quelques mots '); ?>&nbsp;</em><?php print $en_quelques_mots; ?>
                </p>
              <?php endif; ?>

              <?php if ($programme_mtn_legale) : ?>
                <p class="intro">
                  <em><?php print t('Mentions Legales '); ?>&nbsp;</em><?php print $programme_mtn_legale; ?>
                </p>
              <?php endif; ?>

              <ul class="toolsList show-for-medium-up">
                <?php if ($flag) : ?>
                  <li><a href="#logements-disponibles" data-scroll-to class="btn-white"><span class="icon icon-planing "></span><span class="text">Logements disponibles</span></a></li>
                <?php endif; ?>
                <li><a href="#quartier" data-scroll-to class="btn-white"><span class="icon icon-on-map"></span><span class="text">Quartier</span></a></li>
                <?php if ($status_slider) : ?>
                  <li><a href="#prestations" data-scroll-to class="btn-white"><span class="icon icon-prestation"></span><span class="text">Prestations</span></a></li>
                <?php endif; ?>
                <li><a href="#" data-cookie="<?php print $node->type; ?>" class="btn-white" data-cookie-add="<?php print $node->nid; ?>"><span class="icon icon-love"></span><span class="text"><?php print t('Ajouter à mes sélections'); ?></span></a></li>
                <?php if ($status_document) : ?>
                  <li><a href="#downloadDocument" data-scroll-to class="btn-white"><span class="icon icon-download"></span><span class="text"><?php print t('Documents téléchargeables'); ?></span></a></li>
                <?php endif; ?>
                <?php if ($habiteo_id) : ?>
                  <li><a href="#Vue3D" data-scroll-to class="btn-white"><span class="icon icon-cube"></span><span class="text"><?php print t('Vue 3D'); ?></span></a></li>
                <?php endif; ?>
              </ul>

              <?php if($programme_loc_region_kb) : ?>
                <?php
                  $query2 = new EntityFieldQuery();
                  $query2->entityCondition('entity_type', 'node')
                    ->entityCondition('bundle', 'conseiller_regional')
                    ->fieldCondition('field_conseiller_regional_reg_kb', 'target_id', $programme_loc_region_kb)
                    ->range(0, 2);
                  $conseillers = $query2->execute();
                  if($conseillers && isset($conseillers['node'])) :
                ?>
                    <!-- [programContactInformation] start-->
                    <div class="programContactInformation">
                      <h3 class="programContactInformation__heading"><?php print t('Pour toutes informations complémentaires'); ?></h3>
                      <div class="programContactInformation__content">
                <?php
                    foreach($conseillers['node'] as $conseiller) :
                      $conseiller_nid = isset($conseiller->nid) ? $conseiller->nid : '';
                      if($conseiller_nid) :
                        $n_conseiller = node_load($conseiller_nid);
                        if($n_conseiller) :
                          $conseiller_title = $n_conseiller->title;
                          $conseiller_tel1 = isset($n_conseiller->field_conseiller_regional_tele1[LANGUAGE_NONE][0]['value']) ? $n_conseiller->field_conseiller_regional_tele1[LANGUAGE_NONE][0]['value'] : '';
                          $conseiller_tel2 = isset($n_conseiller->field_conseiller_regional_tele2[LANGUAGE_NONE][0]['value']) ? $n_conseiller->field_conseiller_regional_tele2[LANGUAGE_NONE][0]['value'] : '';
                          $conseiller_email = isset($n_conseiller->field_conseiller_regional_email[LANGUAGE_NONE][0]['value']) ? $n_conseiller->field_conseiller_regional_email[LANGUAGE_NONE][0]['value'] : '';
                ?>
                  <div class="programContactInformation__item">
                    <?php if($conseiller_tel1) : ?>
                    <a href="mailto://<?php print $conseiller_email; ?>" class="programContactInformation__mail">
                      <span class="icon icon-email"></span>
                      <span class="text"><?php print $conseiller_title; ?></span>
                    </a>
                    <?php endif; ?>
                    <?php if($conseiller_tel1) : ?>
                      <a href="tel://<?php print str_replace(" ", "", $conseiller_tel1); ?>" class="programContactInformation__phone">
                      <span class="icon icon-phone-call"></span>
                      <span class="text"><?php print $conseiller_tel1; ?></span>
                    </a>
                    <?php endif; ?>
                    <?php if($conseiller_tel2) : ?>
                    <a href="tel://<?php print str_replace(" ", "", $conseiller_tel2); ?>" class="programContactInformation__phone">
                      <span class="text"><?php print $conseiller_tel2; ?></span>
                    </a>
                    <?php endif; ?>
                  </div>
                <?php
                        endif;
                      endif;
                    endforeach;
                      echo "</div>";
                    echo "</div>";
                    //<!-- [programContactInformation] end-->
                  endif;
                ?>


              <?php endif; ?>

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
            <h2 class="heading__title"><?php print isset($field_quartier_titre[0]['value']) ? $field_quartier_titre[0]['value'] : variable_get('kandb_program_default_title_map', t('Un quarter')); ?></h2>
            <p class="heading__title heading__title--sub"><?php print isset($field_quartier_sous_titre[LANGUAGE_NONE][0]['safe_value']) ? strip_tags($field_quartier_sous_titre[LANGUAGE_NONE][0]['safe_value']) : variable_get('kandb_program_default_subtitle_map', t("A l'image des famille")); ?></p>
        </header>
    </div>
    <div class="swapItem">
        <div class="swapItem__2 ">
            <div class="wrapper">

            </div>
        </div>

        <div class="swapItem__1">
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

                endif;
                ?>
            </div>
        </div>

        <div class="swapItem__3">
            <div class="wrapper">
                <div class="heading heading--small text-center">
                    <h3 class="heading__title"><?php print isset($field_quartier_video_titre[0]['value']) ? $field_quartier_video_titre[0]['value'] : ''; ?></h3>
                </div>
                <?php
                if ($video_id):
                    ?>
                    <div class="iframe iframe--video-de-quartier">
                        <iframe frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" width="100%" src="https://www.youtube.com/embed/<?php print $video_id; ?>" class="iframe__content" frameborder="0" allowfullscreen></iframe>
                    </div>
                    <?php
                endif;
                ?>
                <div class="content-centered">
                    <p><?php print isset($field_quartier_video_desc[0]['value']) ? $field_quartier_video_desc[0]['value'] : ''; ?></p>
                </div>
            </div>
        </div>
    </div>
</section>
<?php if ($status_slider): ?>
    <?php print render($program_characteristic['content']); ?>
<?php endif; ?>
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
            <h2 class="heading--tiny"><?php print variable_get('kandb_program_titre_les_plus_proches', t('Les programmes les plus proches')); ?></h2>
            <?php print $programme_carousel; ?>
            <?php
            if ($nodeid = variable_get('kandb_progamme_link_default_selected')) :
                $url = url('node/' . $nodeid);
            else :
                $url = '#';
            endif;
            ?>
            <div class="btn-wrapper btn-wrapper--center"><a href="<?php print $url; ?>" class="btn-rounded btn-primary"><?php print t('Voir toutes nos offres'); ?><span class="icon icon-arrow"></span></a>
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
