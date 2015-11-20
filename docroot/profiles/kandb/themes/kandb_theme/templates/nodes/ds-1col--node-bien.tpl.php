<?php
// Habitel widget
$habiteo_id = isset($node->field_bien_habiteo_id['und'][0]['value']) ? $node->field_bien_habiteo_id['und'][0]['value'] : '';
$habiteo_key = variable_get('habiteo_widget_security_key');
$habiteo_visite_virtuelle_url = variable_get('habiteo_visite-virtuelle_url');
$habiteo_plan_3d_url = variable_get('habiteo_plan-3d_url');


$bien_type = array();
if (isset($node->field_type[LANGUAGE_NONE][0]['tid'])) {
  $bien_type = taxonomy_term_load($node->field_type[LANGUAGE_NONE][0]['tid']);
}

$nb_pieces = array();
if (isset($node->field_nb_pieces[LANGUAGE_NONE][0]['tid'])) {
  $nb_pieces = taxonomy_term_load($node->field_nb_pieces[LANGUAGE_NONE][0]['tid']);
}

$bien_id = '';
if (isset($node->field_id_bien[LANGUAGE_NONE][0]['value'])) {
  $bien_ids = explode('-', $node->field_id_bien[LANGUAGE_NONE][0]['value']);
  $bien_id = $bien_ids[count($bien_ids) - 1];
}

$ville = '';
$arrondissement = '';
$programme = array();
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
}
?>


<!-- [bienHeader] start-->
<header class="programHeader bienHeader">
    <!-- mobile heading-->
    <div class="wrapper show-for-small-only">
        <h1 class="heading heading--bordered">
            <div class="heading__title">ALOO SAOIJO DSSDFoij</div>
            <div class="heading__title heading__title--sub">&Eacute;mergence</div>
        </h1>
    </div>


    <?php if (isset($node->field_image_principale[LANGUAGE_NONE][0])): ?>
      <div class="programHeader__figure">
          <!-- [carousel] start-->
          <div data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" class="slick-slider__item-1">
              <?php
              foreach ($node->field_image_principale[LANGUAGE_NONE] as $item):
                $image_small = image_style_url("bien_small__640_x_316", $item["uri"]);
                $image_medium = image_style_url("bien_medium__1024x506", $item["uri"]);
                $image_large = image_style_url("bien_large__1380_x_670", $item["uri"]);
                ?>
                <article class="programHeaderFigureItem">
                    <figure>
                        <!-- images need to have 2 formats see data-exchange attribute:
                        - small: 640 x 316 (heavy compression)
                        - medium: 1024 x 506
                        - large: 1380 x 670
                        -->
                        <!-- [Responsive img] start-->
                        <img alt="Photo Bien" data-interchange="[<?php print $image_small ?>, (small)], [<?php print $image_medium ?>, (medium)], [<?php print $image_large ?>, (large)]"/>
                        <noscript><img src="<?php print $image_medium ?>" alt="Photo Bien"/></noscript>
                        <!-- [Responsive img] end-->
                    </figure>
                </article>
              <?php endforeach; ?>
          </div>
          <!-- [carousel] end-->
      </div>
    <?php endif; ?>

    <div class="wrapper">
        <div data-equalizer data-equalizer-mq="medium-up" class="programHeader__content">
            <div data-equalizer-watch class="toolbox">
                <!-- tablet+desktop heading-->
                <div class="show-for-medium-up">
                    <h1 class="heading heading--bordered">
                        <div class="heading__title">
                            <?php print (!empty($bien_type)) ? $bien_type->name : ''  ?> 
                            <?php print (!empty($nb_pieces)) ? $nb_pieces->name : ''  ?> 
                            <?php print (isset($node->field_superficie[LANGUAGE_NONE][0]['value'])) ? $node->field_superficie[LANGUAGE_NONE][0]['value'] . ' m<sup>2</sup>' : ''  ?> 
                            Lot <?php print $bien_id ?>
                        </div>
                        <div class="heading__title heading__title--sub">
                            <?php print $ville ?> <?php print $arrondissement ?> <?php print (!empty($programme)) ? $programme->title : ''; ?>
                        </div>
                    </h1>
                </div>

                <p class="toolbox__intro"><?php print t('Quartier Batignolles PARIS 17ème') ?></p>

                <ul class="content-price bienPrice">
                    <li class="content-price__item">
                        <span class="text">
                            <?php print (isset($node->field_prix_tva_20[LANGUAGE_NONE][0])) ? numberFormatGlobal($node->field_prix_tva_20[LANGUAGE_NONE][0]["value"]) : 0  ?> <?php print t('€'); ?>
                        </span>
                        <span class="tags">
                            <div class="tva"><?php print t('TVA 5,5%'); ?></div>
                            <a href="#" class="tva--btn">
                                <span class="icon icon-arrow"></span>
                                <?php print t('Suis-je éligible&nbsp;?') ?>
                            </a>
                        </span>
                    </li>
                    <li class="content-price__item">
                        <span class="text">
                            <?php print (isset($node->field_bien_low_tva_price[LANGUAGE_NONE][0])) ? numberFormatGlobal($node->field_bien_low_tva_price[LANGUAGE_NONE][0]["value"]) : 0  ?> <?php print t('€'); ?>
                        </span>
                        <span class="tags">
                            <div class="tva tva--high"><?php print t('TVA 20%') ?></div>
                        </span>
                    </li>
                </ul>

                <p class="toolbox__intro toolbox__intro--border"><?php print t('Parking extérieur à partir de 10&nbsp;000€'); ?></p>

                <div class="sharing hide-for-small-only">
                    <ul class="sharing__items">
                        <li class="sharing__items__item"><a href="javascript:window.print()" title="Imprimer la page" class="icon icon-print"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage par email" class="icon icon-email"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage sur Facebook" class="icon icon-facebook"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage sur Twitter" class="icon icon-twitter"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage sur Whatsapp" class="icon icon-phone-call"></a></li>
                    </ul>
                </div>
            </div>
            
            <div data-equalizer-watch class="programHeader__content__details">
                <?php if (isset($node->field_caracteristique[LANGUAGE_NONE][0])): ?>
                  <ul class="characteristicList">
                      <?php
                      foreach ($node->field_caracteristique[LANGUAGE_NONE] as $item):
                        $caracteristique = taxonomy_term_load($item["tid"]);
                        ?>
                        <li class="characteristicList__item"><span class="icon <?php print (isset($caracteristique->field_icon_name[LANGUAGE_NONE][0])) ? $caracteristique->field_icon_name[LANGUAGE_NONE][0]["value"] : ''  ?>"></span><span class="text"><?php print $caracteristique->name ?></span></li>
                      <?php endforeach; ?>
                  </ul>
                <?php endif; ?>


                <ul class="toolsList">
                    <li><a href="#" data-cookie="<?php print $node->type; ?>" class="btn-white" data-cookie-add="<?php print $node->nid; ?>"><span class="icon icon-love"></span><span class="text"><?php print t("Ajouter à mes sélections"); ?></span></a></li>

                    <?php if (!empty($plaquette_commerciale)): ?>
                      <li><a href="<?php print $plaquette_commerciale; ?>" class="btn-white"><span class="icon icon-flyer"></span><span class="text"><?php print t("Télécharger la plaquette"); ?></span></a></li>
                    <?php endif; ?>

                    <?php if (isset($node->field_bien_plan[LANGUAGE_NONE][0]['uri'])) : ?>  
                      <li><a href="<?php print file_create_url($node->field_bien_plan[LANGUAGE_NONE][0]['uri']); ?>" class="btn-white"><span class="icon icon-flyer"></span><span class="text"><?php print t("Télécharger le plan"); ?></span></a></li>
                    <?php endif; ?>
                </ul>
                <!-- [contactUs mini] start-->
                <?php
                if (function_exists('kandb_contact_block_page')) {
                  print kandb_contact_block_page(TRUE);
                }
                ?>
                <!-- [contactUs mini] end-->
                <div class="sharing show-for-small-only">
                    <ul class="sharing__items">
                        <li class="sharing__items__item"><a href="javascript:window.print()" title="Imprimer la page" class="icon icon-print"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage par email" class="icon icon-email"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage sur Facebook" class="icon icon-facebook"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage sur Twitter" class="icon icon-twitter"></a></li>
                        <li class="sharing__items__item"><a href="#" title="partage sur Whatsapp" class="icon icon-phone-call"></a></li>
                    </ul>
                </div>
            </div>
        </div>
    </div>
</header>
<!-- [bienHeader] end-->


<!-- [3rd party: visite-virtuelle] start-->
<section class="section-padding">
    <?php if ($habiteo_id): ?>
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print $node->field_visite_titre['und'][0]['value']; ?></h2>
          </header>
      </div>
      <div class="wrapper--medium-up">

          <div class="iframe iframe--visite-virtuelle">
              <iframe src="" data-src="<?php print $habiteo_visite_virtuelle_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>&amp;type=T2" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
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
    <?php endif; ?>
</section>
<!-- [3rd party: visite-virtuelle] start-->
<!-- [popinLeadForm popin] start-->
<div id="popinLeadForm" data-reveal="data-reveal" aria-hidden="true" role="dialog" data-drupal-form="data-drupal-form" class="reveal-modal full scroll"></div>
<!-- [popinLeadForm popin] end-->



<!-- [More Available] start-->
<?php
$list_bien_more = array();
if (!empty($programme) && isset($node->field_nb_pieces[LANGUAGE_NONE][0]['tid'])) {
  $piece_id = $node->field_nb_pieces[LANGUAGE_NONE][0]['tid'];
  $nb_pieces = taxonomy_term_load($piece_id);
  $list_bien_more = get_biens_follow_piece_program($programme->nid, $piece_id);
}

if (!empty($list_bien_more)):
  ?>
  <section class="section-padding">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title">Appartements <?php echo $nb_pieces->name ?> disponibles</h2>
              <p class="heading__title heading__title--sub"><?php print t("sur le programme") ?></p>
          </header>
      </div>
      <div class="wrapper">
          <div class="moreAvailable">
              <table class="responsive">
                  <tbody>
                      <?php
                      foreach ($list_bien_more as $item):
                        if ($item->nid == $node->nid) {
                          continue;
                        }
                        else {
                          $bien_more = node_load($item->nid);
                          $bien_id = explode('-', $bien_more->field_id_bien[LANGUAGE_NONE][0]["value"]);
                          $bien_id = $bien_id[count($bien_id) - 1];
                        }
                        ?>

                        <tr>
                            <td><?php print $bien_id ?></td>
                            <td>
                                <ul class="list-item">
                                    <li class="item-promotion">
                                    </li>
                                    <li class="item-ulities">
                                        <?php
                                        if (isset($bien_more->field_caracteristique[LANGUAGE_NONE][0])) {
                                          $list_caracter = '';
                                          foreach ($bien_more->field_caracteristique[LANGUAGE_NONE] as $item_caracter_id) {
                                            $item_caracter = taxonomy_term_load($item_caracter_id['tid']);
                                            $list_caracter .= $item_caracter->name . ', ';
                                          }

                                          $list_caracter = substr($list_caracter, 0, -2);
                                          print $list_caracter;
                                        }
                                        ?>
                                    </li>
                                    <li class="item-area"><?php print (isset($bien_more->field_superficie[LANGUAGE_NONE][0])) ? $bien_more->field_superficie[LANGUAGE_NONE][0]["value"] . ' m2' : ''  ?></li>
                                    <li class="item-exhibit">
                                        <?php
                                        if (isset($bien_more->field_etage[LANGUAGE_NONE][0])) {
                                          $item_etage = taxonomy_term_load($bien_more->field_etage[LANGUAGE_NONE][0]['tid']);
                                          print $item_etage->name;
                                        }
                                        ?>
                                    </li>
                                </ul>
                            </td>
                            <td>
                                <ul class="list-price">
                                    <li><span class="text"><?php print (isset($bien_more->field_prix_tva_20[LANGUAGE_NONE][0])) ? numberFormatGlobal($bien_more->field_prix_tva_20[LANGUAGE_NONE][0]["value"]) : 0  ?><?php print t('€'); ?></span><span class="tva">TVA 5,5%</span></li>

    <?php if (isset($bien_more->field_bien_low_tva_price[LANGUAGE_NONE][0]) && $bien_more->field_bien_low_tva_price[LANGUAGE_NONE][0]['value'] > 0) { ?>
                                      <li><span class="text"><?php numberFormatGlobal($bien_more->field_bien_low_tva_price[LANGUAGE_NONE][0]["value"]) ?><?php print t('€'); ?></span><span class="tva tva--high">TVA 20%</span></li>
                        <?php } ?>
                                </ul>
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
            <h2 class="heading__title">Plus d'infos</h2>
            <p class="heading__title heading__title--sub">sur le programme</p>
        </header>
    </div>
    <div class="wrapper">
        <div data-equalizer data-equalizer-mq="medium-up" class="moreInfoProgram">
            <figure data-equalizer-watch class="moreInfoProgram__figure">


                <?php
                $id_programme = $nodeprogramme = "";
                if (!empty($node->field_programme[LANGUAGE_NONE][0]['entity']->vid)) {
                  $id_programme = $node->field_programme[LANGUAGE_NONE][0]['entity']->vid;
                  $param = array(
                    'type' => 'programme',
                    'status' => 1,
                  );
                  $nodeprogramme = node_load($param, $id_programme);
                }

                global $base_url;
                $url_principale = "";
                $url_principale = $base_url . "/" . drupal_lookup_path('alias', "node/" . $id_programme);
                $title_principale = isset($nodeprogramme->title) ? $nodeprogramme->title : '';
                $title_principale_ville = isset($nodeprogramme->field_espace_vente_ville[LANGUAGE_NONE][0]['value']) ? $nodeprogramme->field_espace_vente_ville[LANGUAGE_NONE][0]['value'] : '';
                $image_principale = isset($nodeprogramme->field_image_principale[LANGUAGE_NONE][0]['uri']) ? $nodeprogramme->field_image_principale[LANGUAGE_NONE][0]['uri'] : '';
                $image_principale_small = '';
                $image_principale_large = '';
                $image_principale_medium = '';
                if ($image_principale) {
                  $image_principale_small = image_style_url('program_image_principale_small', $image_principale);
                  $image_principale_medium = image_style_url('program_image_principale_medium', $image_principale);
                  $image_principale_large = image_style_url('program_image_principale_large', $image_principale);
                }


                $pieces_min = isset($nodeprogramme->field_programme_room_min[LANGUAGE_NONE][0]['value']) ? $nodeprogramme->field_programme_room_min[LANGUAGE_NONE][0]['value'] : '';
                $pieces_max = isset($nodeprogramme->field_programme_room_max[LANGUAGE_NONE][0]['value']) ? $nodeprogramme->field_programme_room_max[LANGUAGE_NONE][0]['value'] : '';

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


                $price_min = isset($nodeprogramme->field_programme_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobal($nodeprogramme->field_programme_price_min[LANGUAGE_NONE][0]['value']) : '';
                $price_max = isset($nodeprogramme->field_programme_price_max[LANGUAGE_NONE][0]['value']) ? numberFormatGlobal($nodeprogramme->field_programme_price_max[LANGUAGE_NONE][0]['value']) : '';

                $de_a_price = '';
                if ($price_min && $price_max) {
                  $de_a_price = 'De' . ' ' . numberFormatGlobal($price_min, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . numberFormatGlobal($price_max, 0, ",", " ") . '€';
                }
                elseif (!$price_min && $price_max) {
                  $de_a_price = 'De' . ' ' . numberFormatGlobal($price_max, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . numberFormatGlobal($price_max, 0, ",", " ") . '€';
                }
                elseif ($price_min && !$price_max) {
                  $de_a_price = 'De' . ' ' . numberFormatGlobal($price_min, 0, ",", " ") . '€' . ' ' . 'à' . ' ' . numberFormatGlobal($price_min, 0, ",", " ") . '€';
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
                    <p class="moreInfoProgram__description"><?php print t('Parking extérieur à partir de'); ?>&nbsp;10.000€</p>
                    <div class="btn-wrapper"><a href="<?php print $url_principale; ?>" title="<?php print $title_principale; ?>" class="btn-primary btn-rounded btn-download"><?php print $title_principale; ?><span class="icon icon-arrow"></span></a></div>

                </div>
            </div>
        </div>
    </div>
</section>
<!-- [More info] end-->