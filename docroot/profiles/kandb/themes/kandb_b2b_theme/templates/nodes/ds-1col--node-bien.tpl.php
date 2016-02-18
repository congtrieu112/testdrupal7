<?php
define("FACTEUR_TVA_5_5", 0.055);
define("FACTEUR_TVA_7", 0.07);

// Habitel widget
$habiteo_id = isset($node->field_bien_habiteo_id['und'][0]['value']) ? $node->field_bien_habiteo_id['und'][0]['value'] : '';
$habiteo_key = variable_get('habiteo_widget_security_key');
$habiteo_visite_virtuelle_url = variable_get('habiteo_visite-virtuelle_url');
$habiteo_plan_3d_url = variable_get('habiteo_plan-3d_url');
$label_parking_fee = variable_get('kandb_bien_default_label_parking_fee', 'Parking à partir de #num# €');

$bien_type = array();
if (isset($node->field_type[LANGUAGE_NONE][0]['tid'])) {
  $bien_type = taxonomy_term_load($node->field_type[LANGUAGE_NONE][0]['tid']);
}

$nb_pieces = array();
if ($bien_type) {
  $bien_id = isset($bien_type->field_id_type_bien[LANGUAGE_NONE][0]['value']) ? $bien_type->field_id_type_bien[LANGUAGE_NONE][0]['value'] : '';
  if ($bien_id) {
    switch ($bien_id) {
      case 'AP':
        if (isset($node->field_nb_pieces[LANGUAGE_NONE][0]['tid'])) {
          $nb_pieces = taxonomy_term_load($node->field_nb_pieces[LANGUAGE_NONE][0]['tid']);
        }
        break;
      case 'MA':
        if (isset($node->field_nb_chambres[LANGUAGE_NONE][0]['tid'])) {
          $nb_pieces = taxonomy_term_load($node->field_nb_chambres[LANGUAGE_NONE][0]['tid']);
        }
        break;
    }
  }
}

$bien_id = '';
if (isset($node->field_id_bien[LANGUAGE_NONE][0]['value'])) {
  $bien_ids = explode('-', $node->field_id_bien[LANGUAGE_NONE][0]['value']);
  $bien_id = $bien_ids[count($bien_ids) - 1];
}

$ville = '';
$arrondissement = '';
$programme = array();
$list_document = array();
$link_to_zip = '';
$region_kb_id = '';
$tva = 0; // 0: TVA 20%, 1: TVA 5.5%, 2: TVA 7%
$tva_name = '';
$affichage = FALSE;
$file_plaquette_commerciale = '';
if (isset($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
  $programme = node_load($node->field_programme[LANGUAGE_NONE][0]['target_id']);
  if (isset($programme->field_programme_loc_ville[LANGUAGE_NONE][0]['tid'])) {
    $city = taxonomy_term_load($programme->field_programme_loc_ville[LANGUAGE_NONE][0]['tid']);
    $ville = $city->name;
  }

  if (isset($programme->field_programme_loc_arr[LANGUAGE_NONE][0]['tid'])) {
    $district = taxonomy_term_load($programme->field_programme_loc_arr[LANGUAGE_NONE][0]['tid']);
    $arrondissement = $district->name;
  }

  if (isset($programme->field_plaquette_commerciale[LANGUAGE_NONE][0]['uri'])) {
    $plaquette_commerciale = file_create_url($programme->field_plaquette_commerciale[LANGUAGE_NONE][0]['uri']);
  }

  if (isset($programme->field_tva[LANGUAGE_NONE][0]['tid'])) {
    $tva_tid = $programme->field_tva[LANGUAGE_NONE][0]['tid'];
    $tva_term = taxonomy_term_load($tva_tid);
    if ($tva_term) {
      $tva_name = $tva_term->name;
      if (isset($tva_term->field_facteur[LANGUAGE_NONE][0]['value'])) {
        $facteur = $tva_term->field_facteur[LANGUAGE_NONE][0]['value'];
        switch ($facteur) {
          case FACTEUR_TVA_5_5:
            $tva = 1;
            break;
          case FACTEUR_TVA_7:
            $tva = 2;
            break;
          default:
            $tva = 0;
            break;
        }
      }
    }
  }

  if (isset($programme->field_affichage_double_grille[LANGUAGE_NONE][0]['value'])) {
    $flag = $programme->field_affichage_double_grille[LANGUAGE_NONE][0]['value'];
    if ($flag) {
      $affichage = TRUE;
    }
  }

  $programme_entity = isset($node->field_programme[LANGUAGE_NONE][0]['entity']) ? $node->field_programme[LANGUAGE_NONE][0]['entity'] : '';
  if($programme_entity) {
    $file_plaquette_commerciale = isset($programme_entity->field_plaquette_commerciale[LANGUAGE_NONE][0]['uri']) ? $programme_entity->field_plaquette_commerciale[LANGUAGE_NONE][0]['uri'] : '';
    $file_fiche_renseignement = isset($programme_entity->field_fiche_renseignement[LANGUAGE_NONE][0]['uri']) ? $programme_entity->field_fiche_renseignement[LANGUAGE_NONE][0]['uri'] : '';
    $file_plan_batiment = isset($programme_entity->field_plan_batiment[LANGUAGE_NONE][0]['uri']) ? $programme_entity->field_plan_batiment[LANGUAGE_NONE][0]['uri'] : '';
    $file_kit_fiscal = isset($programme_entity->field_kit_fiscal[LANGUAGE_NONE][0]['uri']) ? $programme_entity->field_kit_fiscal[LANGUAGE_NONE][0]['uri'] : '';

    $region_kb_id = isset($programme_entity->field_programme_loc_region_kb[LANGUAGE_NONE][0]['target_id']) ? $programme_entity->field_programme_loc_region_kb[LANGUAGE_NONE][0]['target_id'] : '';
    if ($file_plaquette_commerciale) {
      $list_document[] = array(
        'document' => $file_plaquette_commerciale,
        'title' => t('Plaquette commerciale'),
        'icon' => 'icon-flyer'
      );
    }
    if ($file_fiche_renseignement) {
      $list_document[] = array(
        'document' => $file_fiche_renseignement,
        'title' => t('Fiche Renseignement'),
        'icon' => 'icon-file'
      );
    }

    if ($file_plan_batiment) {
      $list_document[] = array(
        'document' => $file_plan_batiment,
        'title' => t('Plan du bâtiment'),
        'icon' => 'icon-planing '
      );
    }
    if ($file_kit_fiscal) {
      $list_document[] = array(
        'document' => $file_kit_fiscal,
        'title' => t('Kit fiscal'),
        'icon' => 'icon-calculator'
      );
    }

    //get link zip file
    $addMore = '_';
    $nid = $programme->nid;
    $path = file_create_url('public://');
    $real_path = drupal_realpath('public://');
    $fileName = 'Programme' . $addMore . preg_replace('@[^a-z0-9-]+@', '-', strtolower($programme->title)) . '.zip';
    if (file_exists($real_path . '/Programme/archive/' . $nid . '/')) {
      $filePath = $real_path . '/Programme/archive/' . $nid . '/' . $fileName;
      $linkfile = $path . 'Programme/archive/' . $nid . '/' . $fileName;
      if ($filePath) {
        if (file_exists($filePath)) {
          $link_to_zip = $linkfile;
        }
      }
    }
  }
}

$piece_id = '';
if (!empty($programme) && isset($node->field_nb_pieces[LANGUAGE_NONE][0]['tid'])) {
  $piece_id = $node->field_nb_pieces[LANGUAGE_NONE][0]['tid'];
}

$virtuelle_type = '';
$virtuelle = FALSE;
if (isset($bien_type->field_id_type_bien['und'][0]['value']) && $bien_type->field_id_type_bien['und'][0]['value'] == 'AP') {
  if ($programme->field_programme_habiteo_bon_plan['und'][0]['value'] == 0) {
    $virtuelle = TRUE;
  }
}
if (isset($nb_pieces->field_id_nombre_pieces['und'][0]['value'])) {
  $virtuelle_type = kandb_habiteo_get_type_room($nb_pieces->field_id_nombre_pieces['und'][0]['value']);
}

$heading_title = '';
$bien_type_name = (isset($bien_type->name) && $bien_type) ? $bien_type->name : '';
$nb_pieces_name = (isset($nb_pieces->name) && $nb_pieces) ? $nb_pieces->name : '';
$heading_title = $bien_type_name . ' ' . $nb_pieces_name;
if($nb_pieces_name == 'studio') {
  $heading_title = ucfirst($nb_pieces_name);
}
?>

<!-- [bienHeader] start-->
<header class="programHeader bienHeader headerB2B">
    <!-- mobile heading-->
    <div class="wrapper show-for-small-only">
        <h1 class="heading heading--bordered">
            <div class="heading__title">
                <?php print $heading_title; ?>
                <?php print (isset($node->field_superficie[LANGUAGE_NONE][0]['value'])) ? $node->field_superficie[LANGUAGE_NONE][0]['value'] . ' m<sup>2</sup>' : ''  ?>
                <?php print t('Lot') . ' ' . $bien_id ?>
            </div>
            <div class="heading__title heading__title--sub">
                <?php print $ville ?> <?php print $arrondissement ?> <?php print (!empty($programme)) ? $programme->title : ''; ?>
            </div>
        </h1>
        <ul class="tags-list">
            <?php
            $domain_id = 3;
            $status_bien = 1;
            if (isset($node->domains[$domain_id]) && $node->domains[$domain_id] == $domain_id && isset($node->field_bien_statut[LANGUAGE_NONE][0]['tid']) && $node->field_bien_statut[LANGUAGE_NONE][0]['tid'] == get_tid_by_id_field($status_bien)) :
              if ($promotions = get_nids_promotions_by_bien($node->nid)) :
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
            <?php endif; ?>
        </ul>

    </div>

    <?php
    $image_principale = '';
    // Check image bien.
    if (isset($node->field_image_principale[LANGUAGE_NONE][0]) &&
      $node->field_image_principale[LANGUAGE_NONE][0]) {
      $image_principale = $node->field_image_principale[LANGUAGE_NONE][0]['uri'];
    } else { // Not fould image bien.
      // Check image programme.
      if (isset($programme->field_image_principale[LANGUAGE_NONE][0]['uri']) &&
        $programme->field_image_principale[LANGUAGE_NONE][0]['uri']) {
        $image_principale = $programme->field_image_principale[LANGUAGE_NONE][0]['uri'];
      } else { // Not fould image programme
        // Get default per image on each pieces and gammes.
        if (isset($programme->field_programme_gamme[LANGUAGE_NONE][0]['value']) &&
          !empty($programme->field_programme_gamme[LANGUAGE_NONE][0]['value']) &&
          $piece_id
        ) {
          if ($file_id = variable_get('image_default_' . $piece_id . '_' . $programme->field_programme_gamme[LANGUAGE_NONE][0]['value'])) {
            $file_load = file_load($file_id);
            $image_principale = $file_load->uri;
          }
        }
      }
    }
    if ($image_principale):
      $image_small = image_style_url("bien_small__640_x_316", $image_principale);
      $image_medium = image_style_url("bien_medium__1024x506", $image_principale);
      $image_large = image_style_url("bien_large__1380_x_600", $image_principale);
      ?>
      <div class="programHeader__figure">
        <!-- [carousel] start-->
        <div data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" class="slick-slider__item-1">
          <article class="programHeaderFigureItem">
            <figure>
              <!-- images need to have 2 formats see data-exchange attribute:
              - small: 640 x 316 (heavy compression)
              - medium: 1024 x 506
              - large: 1380 x 670
              -->
              <!-- [Responsive img] start--><img alt="<?php print $node->title; ?>" data-interchange="[<?php print $image_small ?>, (small)], [<?php print $image_medium ?>, (medium)], [<?php print $image_large ?>, (large)]"/>
              <noscript><img src="<?php print $image_medium ?>" alt="<?php print $node->title; ?>"/></noscript>
              <!-- [Responsive img] end-->
            </figure>
          </article>
        </div>
        <!-- [carousel] end-->
      </div>
    <?php endif; ?>
    <div class="wrapper">
        <div data-equalizer data-equalizer-mq="medium-up" class="programHeader__content">
            <div data-equalizer-watch class="toolbox">
              <h1 class="heading heading--bordered">
                <div class="heading__title">
                  <?php print $heading_title; ?>
                  <?php
                  if(isset($title_maison)) {
                    print $title_maison;
                  }
                  ?>

                  <?php print (isset($node->field_superficie[LANGUAGE_NONE][0]['value'])) ? $node->field_superficie[LANGUAGE_NONE][0]['value'] . ' m<sup>2</sup>' : ''  ?>
                  <?php print t('Lot') . ' ' . $bien_id ?>
                </div>
                <div class="heading__title heading__title--sub">Paris 17 &Eacute;mergence
                  <?php print $ville ?> <?php print $arrondissement ?> <?php print (!empty($programme)) ? $programme->title : ''; ?>
                </div>
              </h1>
              <ul class="tags-list">
                <?php
                $domain_id = 3;
                $status_bien = 1;
                if (isset($node->domains[$domain_id]) && $node->domains[$domain_id] == $domain_id && isset($node->field_bien_statut[LANGUAGE_NONE][0]['tid']) && $node->field_bien_statut[LANGUAGE_NONE][0]['tid'] == get_tid_by_id_field($status_bien)) :
                  if ($promotions = get_nids_promotions_by_bien($node->nid)) :
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
                <?php endif; ?>
              </ul>
              <ul class="content-price bienPrice">
                <?php if ($tva) : ?>
                  <?php if ($affichage) : ?>
                    <li class="content-price__item">
                      <span class="text">
                        <?php print (isset($node->field_bien_low_tva_price[LANGUAGE_NONE][0])) ? numberFormatGlobalSpace($node->field_bien_low_tva_price[LANGUAGE_NONE][0]["value"]) : 0  ?> <?php print t('€'); ?>
                      </span>
                      <span class="tags">
                        <?php if ($tva_name) : ?>
                          <div class="tva"><?php print $tva_name; ?></div>
                        <?php endif; ?>
                        <a href="#" class="tva--btn">
                            <span class="icon icon-arrow"></span>
                            <?php print t('Suis-je éligible&nbsp;?') ?>
                        </a>
                      </span>
                    </li>
                    <li class="content-price__item">
                      <span class="text">
                        <?php print (isset($node->field_prix_tva_20[LANGUAGE_NONE][0])) ? numberFormatGlobalSpace($node->field_prix_tva_20[LANGUAGE_NONE][0]["value"]) : 0  ?> <?php print t('€'); ?>
                      </span>
                      <span class="tags">
                        <div class="tva tva--high"><?php print t('TVA 20%') ?></div>
                      </span>
                    </li>
                  <?php else: ?>
                    <li class="content-price__item">
                      <span class="text">
                        <?php print (isset($node->field_prix_tva_20[LANGUAGE_NONE][0])) ? numberFormatGlobalSpace($node->field_prix_tva_20[LANGUAGE_NONE][0]["value"]) : 0  ?> <?php print t('€'); ?>
                      </span>
                      <span class="tags">
                        <div class="tva tva--high"><?php print t('TVA 20%') ?></div>
                      </span>
                    </li>
                  <?php endif; ?>
                <?php else : ?>
                  <li class="content-price__item">
                    <span class="text">
                      <?php print (isset($node->field_prix_tva_20[LANGUAGE_NONE][0])) ? numberFormatGlobalSpace($node->field_prix_tva_20[LANGUAGE_NONE][0]["value"]) : 0  ?> <?php print t('€'); ?>
                    </span>
                  </li>
                <?php endif; ?>
              </ul>
              <ul class="toolsList">
                <li><a href="#" data-cookie="<?php print $node->type; ?>" class="btn-white" data-cookie-add="<?php print $node->nid; ?>"><span class="icon icon-love"></span><span class="text"><?php print t("Ajouter à mes sélections"); ?></span></a></li>
                <li><a href="#" data-reveal-id="poserPopin" class="btn-white"><span class="icon icon-flyer"></span><span class="text"><?php print t('Dénoncer un prospect'); ?></span></a></li>
              </ul>
              <div class="btn-wrapper btn-wrapper--center">
                <button data-reveal-id="poserPopin" class="btn-secondary btn-rounded btn-poser"><?php print t('Poser une option'); ?></button>
              </div>

              <?php
              if($region_kb_id) : ?>
              <?php
                $query2 = new EntityFieldQuery();
                $query2->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', 'conseiller_regional')
                  ->fieldCondition('field_conseiller_regional_reg_kb', 'target_id', $region_kb_id)
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
                    endforeach; ?>
                </div>
              </div>
              <!-- [programContactInformation] end-->
              <?php
                  endif;
              endif; ?>

              <div class="sharing hide-for-small-only">
                <ul class="sharing__items">
                  <li class="sharing__items__item"><a href="javascript:window.print()" title="Imprimer la page" class="icon icon-print"></a></li>
                  <li class="sharing__items__item"><a href="#" title="partage par email" class="icon icon-email"></a></li>
                  <li class="sharing__items__item"><a href="#" title="partage sur Facebook" class="icon icon-facebook"></a></li>
                  <li class="sharing__items__item"><a href="#" title="partage sur Twitter" class="icon icon-twitter"></a></li>
                </ul>
              </div>
            </div>
            <div data-equalizer-watch class="programHeader__content__details">
              <ul class="characteristicList">
                <?php
                $vocabulary_name = 'caracteristiques';
                if (isset($node->field_caracteristique[LANGUAGE_NONE][0])):
                  foreach ($node->field_caracteristique[LANGUAGE_NONE] as $item):
                    $caracteristique = taxonomy_term_load($item["tid"]);
                    $class_icon = isset($caracteristique->field_icon_name[LANGUAGE_NONE][0]) ? $caracteristique->field_icon_name[LANGUAGE_NONE][0]["value"] : '';
                    if(!in_array($caracteristique->name, array('Balcon', 'Terrasse', 'Parking', 'Box', 'Cave', 'Jardin Privatif'))) {
                      print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                      print '<span class="text">' . $caracteristique->name . ' ' . (($caracteristique->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip"  title="' . $caracteristique->description . '"></span>' : '') . '</span>';
                      print '</li>';
                    }
                  endforeach;
                endif;
                ?>
                <?php
                $jardin = field_get_items('node', $node, 'field_caracteristique_jardin');
                if (isset($jardin[0]['value']) && $jardin[0]['value']) :
                  if ($icons = get_taxonomy_by_vocabulary_name('Jardin Privatif', $vocabulary_name)):
                    $class_icon = isset($icons[0]->field_icon_name[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                    print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                    print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip "  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                    print '</li>';
                  endif;
                endif;
                $balcon = field_get_items('node', $node, 'field_caracteristique_balcon');
                if (isset($balcon[0]['value']) && $balcon[0]['value']):
                  if ($icons = get_taxonomy_by_vocabulary_name('Balcon', $vocabulary_name)):
                    $class_icon = isset($icons[0]->field_icon_name[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                    print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                    print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip "  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                    print '</li>';
                  endif;
                endif;
                $terrasse = field_get_items('node', $node, 'field_caracteristique_terrasse');
                if (isset($terrasse[0]['value']) && $terrasse[0]['value']):
                  if ($icons = get_taxonomy_by_vocabulary_name('Terrasse', $vocabulary_name)):
                    $class_icon = isset($icons[0]->field_icon_name[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                    print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                    print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip "  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                    print '</li>';
                  endif;
                endif;
                $parking = field_get_items('node', $node, 'field_caracteristique_parking');
                if (isset($parking[0]['value']) && $parking[0]['value']):
                  if ($icons = get_taxonomy_by_vocabulary_name('Parking', $vocabulary_name)):
                    $class_icon = isset($icons[0]->field_icon_name[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                    print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                    print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip "  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                    print '</li>';
                  endif;
                endif;
                $box = field_get_items('node', $node, 'field_caracteristique_box');
                if (isset($box[0]['value']) && $box[0]['value']) :
                  if ($icons = get_taxonomy_by_vocabulary_name('Box', $vocabulary_name)):
                    $class_icon = isset($icons[0]->field_icon_name[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                    print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                    print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip "  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                    print '</li>';
                  endif;
                endif;
                $cave = field_get_items('node', $node, 'field_caracteristique_cave');
                if (isset($cave[0]['value']) && $cave[0]['value']) :
                  if ($icons = get_taxonomy_by_vocabulary_name('Cave', $vocabulary_name)):
                    $class_icon = isset($icons[0]->field_icon_name[LANGUAGE_NONE][0]['value']) ? $icons[0]->field_icon_name[LANGUAGE_NONE][0]['value'] : '';
                    print '<li class="characteristicList__item"><span class="icon ' . $class_icon . '"></span>';
                    print '<span class="text">' . $icons[0]->name . ' ' . (($icons[0]->description) ? '<span data-tooltip aria-haspopup="true" class="infotip has-tip "  title="' . $icons[0]->description . '"></span>' : '') . '</span>';
                    print '</li>';
                  endif;
                endif;
                ?>
              </ul>

              <?php if($list_document) : ?>
              <!-- [programDocumentDownload] start-->
              <div class="programDocumentDownload">
                <?php $nocontent = 'data-reveal-id="downloadInformationForm"'; ?>
                <div class="programDocumentDownload__heading">
                  <header class="heading">
                    <h2 class="heading__title"><?php print t('Documents téléchargeables'); ?></h2>
                  </header>
                </div>
                <div class="programDocumentDownload__items">
                  <ul class="row">
                    <?php foreach ($list_document as $item): ?>
                    <li class="programDocumentDownload__items__item">
                      <a href="<?php print file_create_url($item["document"]) ?>" <?php if (!$item["document"]) print $nocontent; ?>>
                        <span class="icon <?php print $item["icon"] ?>"></span>
                        <div class="heading heading--small">
                          <div class="heading__title"><?php print $item["title"] ?></div>
                        </div>
                      </a>
                    </li>
                    <?php endforeach; ?>
                  </ul>
                </div>
                <div class="btn-wrapper">
                  <button <?php print (isset($link_to_zip) AND !empty($link_to_zip)) ? 'onclick="window.location.href=\'' . $link_to_zip . '\'"' : $nocontent; ?> class="btn-primary btn-rounded btn-download">
                    <?php print t('Tout télécharger (.zip)'); ?>
                  </button>
                </div>
                <!-- [popin] start-->
                <div id="downloadInformationForm" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                  <div class="reveal-modal__wrapper"><span aria-label="Fermer" role="button" class="close-reveal-modal icon icon-close"></span>
                    <div class="programDocumentDownload__content">
                      <p><?php print t('Content Update later'); ?></p>
                    </div>
                  </div>
                </div>
                <!-- [popin] end-->
              </div>
              <!-- [programDocumentDownload] end-->
              <?php endif; ?>
            </div>
        </div>
    </div>
    <!-- Popups-->
    <!-- [popin] start-->
    <div id="poserPopin" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
      <div class="reveal-modal__wrapper"><span aria-label="Fermer" role="button" class="close-reveal-modal icon icon-close"></span>
        <div class="programDocumentDownload__content">
          <p>Content Update later</p>
        </div>
      </div>
    </div>
    <!-- [popin] end-->
    <!-- [popin] start-->
    <div id="denoncerProspectPopin" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
      <div class="reveal-modal__wrapper"><span aria-label="Fermer" role="button" class="close-reveal-modal icon icon-close"></span>
        <div class="programDocumentDownload__content">
          <p>Content Update later</p>
        </div>
      </div>
    </div>
    <!-- [popin] end-->
</header>
<!-- [bienHeader] end-->





<!-- [3rd party: visite-virtuelle] start-->

<?php
if ($habiteo_id && $virtuelle):
  $bien_type = !empty($bien_type) ? $bien_type->name : '';
  $nb_pieces = !empty($nb_pieces) ? $nb_pieces->name : '';
  ?>
  <section class="section-padding">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print !empty($node->field_visite_titre['und'][0]['value']) ? $node->field_visite_titre['und'][0]['value'] : variable_get('kandb_bien_default_title_habiteo') . ' ' . $bien_type . ' ' . $nb_pieces  ?></h2>
          </header>
      </div>
      <div class="wrapper--medium-up">

          <div class="iframe iframe--visite-virtuelle">
              <iframe src="" data-src="<?php print $habiteo_visite_virtuelle_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>&amp;type=<?php print $virtuelle_type; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
          </div>
      </div>
      <div class="wrapper">
          <div class="content-centered">
              <p><?php print nl2br($node->field_visite_texte['und'][0]['value']); ?></p>
              <div class="btn-wrapper btn-wrapper--center"><a href="#" data-reveal-id="plan3d" class="btn-rounded btn-primary"><?php print $node->field_visite_plan_3d['und'][0]['value']; ?></a>
                  <!-- [popin] start-->
                  <div id="plan3d" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                      <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                          <div class="iframe iframe--plan-3d">
                              <iframe src="" data-src="<?php print $habiteo_plan_3d_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
                          </div>
                      </div>
                  </div>
                  <!-- [popin] end-->
              </div>
          </div>
      </div>
  </section>
<?php endif; ?>

<!-- [3rd party: visite-virtuelle] start-->

<!-- [More Available] start-->
<?php
global $_domain;
$gid = $_domain['domain_id'];

$list_bien_more = array();
if ($piece_id) {
  $nb_pieces = taxonomy_term_load($piece_id);
  $field_id_bien = isset($node->field_id_bien[LANGUAGE_NONE][0]['value']) ? $node->field_id_bien[LANGUAGE_NONE][0]['value'] : 0;
  // Get list bien exclude current bien with surface (sort asc)
  $list_bien_more = get_biens_follow_piece_program($programme->nid, $gid, $piece_id, $field_id_bien);
  // Get bien with price min
  $list_bien_more_price_min = get_biens_price_max_min_follow_piece_program($programme->nid, $gid, $piece_id, $field_id_bien, 'ASC');
  // Get bien with price max
  $list_bien_more_price_max = get_biens_price_max_min_follow_piece_program($programme->nid, $gid, $piece_id, $field_id_bien, 'DESC');

  // List bien more (First: Cheapest, Second: Expensive, Remain: Bien from the smallest to the larger Bien (surface)
  if(count($list_bien_more) > 2) {
    $bien_id_price_max = (!empty($list_bien_more_price_max)) ? key($list_bien_more_price_max) : '';
    $bien_id_price_min = (!empty($list_bien_more_price_min)) ? key($list_bien_more_price_min) : '';
    if($bien_id_price_max) {
      unset($list_bien_more[$bien_id_price_max]);
    }

    if($bien_id_price_min) {
      unset($list_bien_more[$bien_id_price_min]);
    }

    if($list_bien_more_price_min && $list_bien_more_price_max) {
      $list_bien_more = array_merge($list_bien_more_price_min, $list_bien_more_price_max, $list_bien_more);
    }
  } elseif(count($list_bien_more) == 2) {
    if($list_bien_more_price_min && $list_bien_more_price_max) {
      $list_bien_more = array_merge($list_bien_more_price_min, $list_bien_more_price_max);
    }
  }

  foreach ($list_bien_more as $item) {
    $bien_datas = node_load($item->nid);
    if (!in_array($gid, $bien_datas->domains)) {
      unset($list_bien_more[$item->nid]);
    }
  }
}

if (!empty($list_bien_more)):
  ?>
  <section class="section-padding">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print t('Les') . ' ' . $heading_title . ' ' . t('disponibles'); ?></h2>
              <p class="heading__title heading__title--sub"><?php print variable_get('kandb_bien_default_title_more') ?></p>
          </header>
      </div>
      <div class="wrapper--narrow">
          <div class="moreAvailable">
              <table class="responsive">
                  <tbody>
                      <?php
                      foreach ($list_bien_more as $item):

                        if ($item->nid == $node->nid) {
                          continue;
                        } else {
                          $bien_more = node_load($item->nid);
                          $bien_more_status = isset($bien_more->status) ? $bien_more->status : 0;
                          if (!in_array($gid, $bien_more->domains) || !$bien_more_status) {
                            continue;
                          }
                          $bien_id = explode('-', $bien_more->field_id_bien[LANGUAGE_NONE][0]["value"]);
                          $bien_id = $bien_id[count($bien_id) - 1];
                        }
                        ?>
                        <tr>
                            <td><?php print $bien_id ?></td>
                            <td>
                                <div class="list-item">
                                    <div class="item-promotion">
                                        <ul class="tags-list">
                                            <?php
                                            $promotions = get_nids_promotions_by_bien($bien_more->nid);
                                            if ($promotions):
                                              foreach ($promotions as $promotion):
                                                $triger_promotion = 'moreAvailable-promotion-' . $promotion->nid;
                                                ?>
                                                <li>
                                                    <button data-reveal-trigger="<?php print $triger_promotion; ?>" class="tag tag--important"><?php print $promotion->title; ?></button>
                                                    <!-- [popin] start-->
                                                    <div data-reveal="<?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $triger_promotion : ''; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                                        <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                                            <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $promotion->title; ?></strong></p>
                                                            <p><?php print isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) ? $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value'] : ''; ?></p>
                                                        </div>
                                                    </div>
                                                    <!-- [popin] end-->
                                                </li>
                                                <?php
                                              endforeach;
                                            endif;
                                            ?>
                                        </ul>
                                    </div>
                                    <div class="list-characteristics">
                                        <ul>
                                            <li class="item-ulities">
                                                <ul>
                                                    <?php
                                                    $arr_caracteris = array();
                                                    $arr_caracteris[] = isset($bien_more->field_caracteristique_balcon[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_balcon[LANGUAGE_NONE][0]['value'] > 0 ? 'Balcon' : '';
                                                    $arr_caracteris[] = isset($bien_more->field_caracteristique_box[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_box[LANGUAGE_NONE][0]['value'] >= 0 ? 'Box' : '';
                                                    $arr_caracteris[] = isset($bien_more->field_caracteristique_cave[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_cave[LANGUAGE_NONE][0]['value'] >= 0 ? 'Cave' : '';
                                                    $arr_caracteris[] = isset($bien_more->field_caracteristique_jardin[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_jardin[LANGUAGE_NONE][0]['value'] > 0 ? 'Jardin' : '';
                                                    $arr_caracteris[] = isset($bien_more->field_caracteristique_parking[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_parking[LANGUAGE_NONE][0]['value'] >= 0? 'Parking' : '';
                                                    $arr_caracteris[] = isset($bien_more->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value'] > 0 ? 'Terrasse' : '';

                                                    // Remove all value is emtpy in array
                                                    $arr_caracteris = array_filter($arr_caracteris);
                                                    $caracteristiques = isset($bien_more->field_caracteristique[LANGUAGE_NONE]) ? $bien_more->field_caracteristique[LANGUAGE_NONE] : '';
                                                    if ($caracteristiques && count($caracteristiques) > 0) {
                                                      foreach ($caracteristiques as $caracteristique) {
                                                        $term_caracteristique = taxonomy_term_load($caracteristique['tid']);
                                                        if ($term_caracteristique) {
                                                          if(isset($term_caracteristique->name) && !in_array($term_caracteristique->name, $arr_caracteris)) {
                                                            $arr_caracteris[] = $term_caracteristique->name;
                                                          }
                                                        }
                                                      }
                                                    }

                                                    $arr_caracteris[] = isset($bien_more->field_cave_description[LANGUAGE_NONE][0]['value']) ? $bien_more->field_cave_description[LANGUAGE_NONE][0]['value'] : '';
                                                    $arr_caracteris[] = isset($bien_more->field_parking_description[LANGUAGE_NONE][0]['value']) ? $bien_more->field_parking_description[LANGUAGE_NONE][0]['value'] : '';

                                                    ?>
                                                    <?php if (count($arr_caracteris) > 0) : ?>
                                                      <?php foreach ($arr_caracteris as $caracteris) : ?>
                                                        <?php if ($caracteris) : ?>
                                                          <li><?php print $caracteris; ?></li>
                                                        <?php endif; ?>
                                                      <?php endforeach; ?>
                                                    <?php endif; ?>
                                                </ul>
                                            </li>
                                            <li class="item-area"><?php print (isset($bien_more->field_superficie[LANGUAGE_NONE][0])) ? $bien_more->field_superficie[LANGUAGE_NONE][0]["value"] . ' m<sup>2</sup>' : ''  ?></li>
                                            <li class="item-exhibit">
                                                <?php
                                                if (isset($bien_more->field_etage[LANGUAGE_NONE][0])) {
                                                  $item_etage = taxonomy_term_load($bien_more->field_etage[LANGUAGE_NONE][0]['tid']);
                                                  print $item_etage->name;
                                                }
                                                ?>
                                            </li>
                                        </ul>
                                    </div>
                                </div>
                            </td>
                            <td>
                                <ul class="list-price">
                                    <?php if ($tva_name): ?>
                                      <?php if ($affichage): ?>
                                        <?php if (isset($bien_more->field_bien_low_tva_price[LANGUAGE_NONE][0]) && $bien_more->field_bien_low_tva_price[LANGUAGE_NONE][0]['value'] > 0) : ?>
                                          <li>
                                              <span class="text">
                                                  <?php print numberFormatGlobalSpace($bien_more->field_bien_low_tva_price[LANGUAGE_NONE][0]["value"]) ?><?php print ' ' . t('€'); ?></span>
                                              <span class="tva"><?php print $tva_name; ?></span>
                                          </li>
                                        <?php endif; ?>
                                      <?php endif; ?>
                                      <li>
                                          <span class="text">
                                              <?php print (isset($bien_more->field_prix_tva_20[LANGUAGE_NONE][0])) ? numberFormatGlobalSpace($bien_more->field_prix_tva_20[LANGUAGE_NONE][0]["value"]) : 0; ?><?php print ' ' . t('€'); ?></span>
                                          <span class="tva tva--high"><?php print t('TVA 20%'); ?></span>
                                      </li>
                                    <?php else: ?>
                                      <li>
                                          <span class="text">
                                              <?php print (isset($bien_more->field_prix_tva_20[LANGUAGE_NONE][0])) ? numberFormatGlobalSpace($bien_more->field_prix_tva_20[LANGUAGE_NONE][0]["value"]) : 0; ?><?php print ' ' . t('€'); ?></span>
                                      </li>
                                    <?php endif; ?>

                                </ul>
                                <a href="<?php print url('node/' . $bien_more->nid); ?>" title="<?php print t('voir la page') . ' ' . $bien_more->title; ?>" class="btn-primary btn-rounded"><?php print t('Voir'); ?></a>
                            </td>
                        </tr>
                      <?php endforeach; ?>

                  </tbody>
              </table>
          </div>
      </div>
  </section>
  <!-- [More Available] end-->

<?php endif; ?>


<!-- [More info] start-->
<section class="section-padding bg-lightGrey">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title"><?php print t('Plus d\'infos'); ?></h2>
            <p class="heading__title heading__title--sub"><?php print t('sur le programme'); ?></p>
        </header>
    </div>
    <div class="wrapper">
        <div data-equalizer data-equalizer-mq="medium-up" class="moreInfoProgram">
            <figure data-equalizer-watch class="moreInfoProgram__figure">


                <?php
                global $base_url;
                $url_principale = "";
                $url_principale = url('node/' . $programme->nid);
                $title_principale = isset($programme->title) ? $programme->title : '';
                $title_principale_ville = '';
                if (isset($programme->field_programme_loc_ville[LANGUAGE_NONE][0]['tid'])) {
                  $ville = taxonomy_term_load($programme->field_programme_loc_ville[LANGUAGE_NONE][0]['tid']);
                  $title_principale_ville = isset($ville->name) ? $ville->name : '';
                }
                $image_principale = isset($programme->field_image_principale[LANGUAGE_NONE][0]['uri']) ? $programme->field_image_principale[LANGUAGE_NONE][0]['uri'] : '';
                $image_principale_small = '';
                $image_principale_large = '';
                $image_principale_medium = '';
                if ($image_principale) {
                  $image_principale_small = image_style_url('bien_more_info_programe_small_560_x_214', $image_principale);
                  $image_principale_medium = image_style_url('bien_more_info_programe_medium_632_x_241', $image_principale);
                  $image_principale_large = image_style_url('bien_more_info_programe_large_780_x_298', $image_principale);
                }


                $pieces_min = isset($programme->field_programme_room_min[LANGUAGE_NONE][0]['value']) ? $programme->field_programme_room_min[LANGUAGE_NONE][0]['value'] : '';
                $pieces_max = isset($programme->field_programme_room_max[LANGUAGE_NONE][0]['value']) ? $programme->field_programme_room_max[LANGUAGE_NONE][0]['value'] : '';

                $de_a_pieces = '';
                if ($pieces_min && $pieces_max) {
                  $de_a_pieces = $pieces_min . ' ' . t('à') . ' ' . $pieces_max . ' ' . t('pièces');
                } elseif (!$pieces_min && $pieces_max) {
                  $de_a_pieces = $pieces_max . ' ' . t('pièces');
                } elseif ($pieces_min && !$pieces_max) {
                  $de_a_pieces = $pieces_min . ' ' . t('pièces');
                }


                $price_min = isset($programme->field_programme_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($programme->field_programme_price_min[LANGUAGE_NONE][0]['value']) : '';


                $de_a_price = "";
                if ($price_min) {
                  $de_a_price = t('à partir de ') . ' ' . $price_min . t('€');
                }
                ?>
                <!-- images need to have 2 formats see data-exchange attribute:
                - small: 560 x 214 (heavy compression)
                - medium: 632 x 241
                - large: 780 x 298
                -->
                <!-- [Responsive img] start--><img alt="Sur le programme" data-interchange="[<?php print ($image_principale_small); ?>, (small)], [<?php print ($image_principale_medium); ?>, (medium)], [<?php print ($image_principale_large); ?>, (large)]"/>
                <noscript><img src="<?php print ($image_principale_medium); ?>" alt="<?php print $title_principale; ?>"/></noscript>
                <!-- [Responsive img] end-->


            </figure>
            <div data-equalizer-watch class="moreInfoProgram__content">
                <div class="moreInfoProgram__content__inner">
                    <div class="heading heading--small">
                        <h3 class="heading__title"><?php print $title_principale_ville . " " . $title_principale; ?></h3>
                        <p class="heading__title heading__title--sub"><?php print $de_a_pieces; ?> <br><?php print $de_a_price; ?></p>
                    </div>
                    <p class="moreInfoProgram__description"><?php print str_replace('#num#', '10 000', $label_parking_fee); ?>e</p>
                    <div class="btn-wrapper"><a href="<?php print $url_principale; ?>" title="<?php print $title_principale; ?>" class="btn-primary btn-rounded btn-download"><?php print t('Découvrir'); ?><span class="icon icon-arrow"></span></a></div>

                </div>
            </div>
        </div>
    </div>
</section>
<!-- [More info] end-->
<?php
if (isset($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
  if (function_exists('kandb_contact_specific_block_page')) {
    $programme = node_load($node->field_programme[LANGUAGE_NONE][0]['target_id']);
    print kandb_contact_specific_block_page($programme);
  }
}
?>


