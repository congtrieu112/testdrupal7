<?php
$title = isset($logement_block['title']) ? $logement_block['title'] : '';

$tva_name = isset($node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name : '';
$affichage = isset($node->field_affichage_double_grille[LANGUAGE_NONE][0]['value']) ? $node->field_affichage_double_grille[LANGUAGE_NONE][0]['value'] : '';
ksort($logement_block['total_bien']);
    if ($logement_block && isset($logement_block['total_bien'])) :
  ?>
  <section class="section-padding bg-lightGrey" id="logements-disponibles">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print t('Découvrir les logements'); ?></h2>
          </header>
      </div>
      <!-- [carousel] start-->
      <div data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" class="slick-slider__item-1 programParcel">
          <?php
          $count = 1;
          foreach ($logement_block['total_bien'] as $type => $total) :
            $arr_type = explode("-", $type);
            $type_de_bien = ''; $nb_pieces_tid = '';
            if(is_array($arr_type)) :
                 $type_de_bien = isset($arr_type[1]) ? $arr_type[1] : '';
                if ($type_de_bien) :
                   if( strtolower($type_de_bien) == 'maison' || strtolower($type_de_bien) == 'appartement') :
                       if($total > 1) :
                          $type_de_bien = $type_de_bien . 's';
                       endif;
                   endif;
                 $nb_pieces_tid = isset($arr_type[2]) ? $arr_type[2] : '';
                endif;
            endif;
            if ($total > 1) :
                $label = t('disponibles');
            else :
                $label = t('disponible');
            endif;
            $nb_pieces = '';
            if($nb_pieces_tid) {
              $nb_pieces_node = taxonomy_term_load($nb_pieces_tid);
              if($nb_pieces_node) {
                $nb_pieces = $nb_pieces_node->name;
              }
            }
            if ($count % 6 == 1) :
              print '<div class="unwrap">';
            endif;
            ?>
            <article data-reveal-id="programParcel<?php print $count; ?>"  class="programParcelItem">
                <?php if (isset($logement_block['programme_bien_images'][$type]) && $logement_block['programme_bien_images'][$type]) : ?>
                  <figure>
                      <!-- [Responsive img] start-->
                      <img alt="<?php print $type; ?>" data-interchange="[<?php print $logement_block['programme_bien_images'][$type]; ?>, (small)], [<?php print $logement_block['programme_bien_images'][$type]; ?>, (large)]"/>
                      <noscript><img src="<?php print $logement_block['programme_bien_images'][$type]; ?>" alt="test"/></noscript>
                      <!-- [Responsive img] end-->
                  </figure>
                <?php endif; ?>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading"><?php print $total; ?>&nbsp;<?php print $type_de_bien; ?><?php if($nb_pieces) : print t(' de ') . $nb_pieces; endif;?><?php print ' ' . $label; ?></h3>
                    <div class="programParcelItem__prices">
                        <?php if (isset($logement_block['price_min_tva_un_20_bien'][$type]) && isset($logement_block['tva_bien'][$type]) && $affichage) : ?>
                          <p>
                              <span>
                                  <?php print t('À partir de '); ?>
                                  <?php print number_format($logement_block['price_min_tva_un_20_bien'][$type], 0, '', ' ') . ' €'; ?>
                              </span>
                              <span class="tva"><?php print 'TVA ' . $logement_block['tva_bien'][$type] * 100 . '%'; ?></span>
                          </p>
                        <?php endif; ?>

                        <?php if (isset($logement_block['price_min_tva20_bien'][$type])) : ?>
                          <p>
                              <span>
                                  <?php print t('À partir de '); ?>
                                  <?php print number_format($logement_block['price_min_tva20_bien'][$type], 0, '', ' ') . ' €'; ?>
                              </span>
                              <?php if ($tva_name): ?>
                                <span class="tva tva--high"><?php print t('TVA 20%') ?></span>
                              <?php endif; ?>
                          </p>
                        <?php endif; ?>

                    </div>
                </div>

                <!-- [popin] start-->
                <div id="programParcel<?php print $count; ?>" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                    <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                        <aside class="programParcelPopin">
                            <div class="heading heading--bordered">
                                <p class="heading__title"><?php print $type_de_bien; ?>&nbsp;<?php print $nb_pieces;?><?php print t(' disponibles');?></p>
                                <p class="heading__title heading__title--sub"><?php print t('dans ce programme'); ?></p>
                            </div>
                            <div class="moreAvailable">
                                <table class="responsive">
                                    <tbody>
                                        <?php
                                        foreach ($logement_block['popin_program'][$type] as $node_bien_id => $node_bien_price) :
                                          if ($node_bien_id) :
                                            $query = new EntityFieldQuery();
                                            $query->entityCondition('entity_type', 'node')
                                              ->entityCondition('bundle', 'bien')
                                              ->fieldCondition('field_id_bien', 'value', $node_bien_id)
                                              ->range(0, 1);

                                            $result = $query->execute();
                                            $result = array_keys($result['node']);
                                            $biens = node_load($result[0]);
                                            if ($biens) :
                                              $bien_id = isset($biens->field_id_bien[LANGUAGE_NONE][0]['value']) ? $biens->field_id_bien[LANGUAGE_NONE][0]['value'] : '';
                                              if ($bien_id) :
                                                $bien_id = explode('-', $bien_id);
                                                $bien_id = $bien_id[count($bien_id) - 1];
                                              endif;
                                              $superficie = isset($biens->field_superficie[LANGUAGE_NONE][0]['value']) ? $biens->field_superficie[LANGUAGE_NONE][0]['value'] : 0;
                                              $price_tva_20 = isset($biens->field_prix_tva_20[LANGUAGE_NONE][0]['value']) ? round($biens->field_prix_tva_20[LANGUAGE_NONE][0]['value'], 0) : 0;
                                              $low_tva_price = isset($biens->field_bien_low_tva_price[LANGUAGE_NONE][0]['value']) ? round($biens->field_bien_low_tva_price[LANGUAGE_NONE][0]['value'], 0) : 0;

                                              $arr_caracteris = array();
                                              $arr_caracteris[] = isset($biens->field_caracteristique_balcon[LANGUAGE_NONE][0]['value']) ? 'Balcon' : '';
                                              $arr_caracteris[] = isset($biens->field_caracteristique_box[LANGUAGE_NONE][0]['value']) ? 'Box' : '';
                                              $arr_caracteris[] = isset($biens->field_caracteristique_cave[LANGUAGE_NONE][0]['value']) ? 'Cave' : '';
                                              $arr_caracteris[] = isset($biens->field_caracteristique_jardin[LANGUAGE_NONE][0]['value']) ? 'Jardin' : '';
                                              $arr_caracteris[] = isset($biens->field_caracteristique_parking[LANGUAGE_NONE][0]['value']) ? 'Parking' : '';
                                              $arr_caracteris[] = isset($biens->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value']) ? 'Terrasse' : '';

                                              $caracteristiques = isset($biens->field_caracteristique[LANGUAGE_NONE]) ? $biens->field_caracteristique[LANGUAGE_NONE] : '';
                                              if ($caracteristiques && count($caracteristiques) > 0) {
                                                foreach ($caracteristiques as $caracteristique) {
                                                  $term_caracteristique = taxonomy_term_load($caracteristique['tid']);
                                                  if ($term_caracteristique) {
                                                    $arr_caracteris[] = $term_caracteristique->name;
                                                  }
                                                }
                                              }

//                                              $arr_caracteris[] = isset($biens->field_cave_description[LANGUAGE_NONE][0]['value']) ? $biens->field_cave_description[LANGUAGE_NONE][0]['value'] : '';
//                                              $arr_caracteris[] = isset($biens->field_parking_description[LANGUAGE_NONE][0]['value']) ? $biens->field_parking_description[LANGUAGE_NONE][0]['value'] : '';

                                              if (!empty($biens->field_cave_description[LANGUAGE_NONE][0]['value'])) {
                                                $name_description_cave = field_info_instance('node', 'field_cave_description', 'bien');
                                                $arr_caracteris[] = $name_description_cave['label'];
                                              }
                                              $etage_tid = isset($biens->field_etage[LANGUAGE_NONE][0]['tid']) ? $biens->field_etage[LANGUAGE_NONE][0]['tid'] : '';
                                              $etage = '';
                                              if ($etage_tid) {
                                                $term_etage = taxonomy_term_load($etage_tid);
                                                if ($term_etage) {
                                                  $etage = $term_etage->name;
                                                }
                                              }

                                              ?>
                                              <tr>
                                                  <td><?php

                                                      if ($bien_id) : print $bien_id;
                                                      endif;
                                                      ?></td>
                                                  <td>
                                                      <div class="list-item">
                                                          <div class="list-characteristics">
                                                              <ul>
                                                                  <?php if ($superficie) : ?>
                                                                <li class="item-area">
                                                                  <?php print str_replace('.', ',', $superficie) . "m<sup>2</sup>"; ?></li><?php endif; ?>
                                                                  <?php if (count($arr_caracteris) > 0) : ?>
                                                                    <li class="item-ulities">
                                                                        <ul>
                                                                            <?php foreach ($arr_caracteris as $caracteris) : ?>
                                                                              <?php if ($caracteris) : ?>
                                                                                <li><?php print $caracteris; ?></li>
                                                                              <?php endif; ?>
                                                                            <?php endforeach; ?>
                                                                        </ul>
                                                                    </li>
                                                                  <?php endif; ?>
                                                                  <?php if ($etage) : ?><li class="item-exhibit"><?php print $etage; ?></li><?php endif; ?>
                                                              </ul>
                                                          </div>
                                                      </div>
                                                  </td>
                                                  <td>
                                                      <ul class="list-price">
                                                          <?php if ($tva_name): ?>
                                                            <?php if ($affichage): ?>
                                                              <?php if ($low_tva_price) : ?>
                                                                <li>
                                                                    <span class="text"><?php print number_format($low_tva_price, 0, '', ' '); ?>&nbsp;€</span>
                                                                    <span class="tva"><?php print $tva_name; ?></span>
                                                                </li>
                                                              <?php endif; ?>
                                                            <?php endif; ?>

                                                            <?php if ($price_tva_20) : ?>
                                                              <li>
                                                                  <span class="text"><?php print number_format($price_tva_20, 0, '', ' '); ?>&nbsp;€</span>
                                                                  <span class="tva tva--high"><?php print t('TVA 20%'); ?></span>
                                                              </li>
                                                            <?php endif; ?>
                                                          <?php else: ?>
                                                            <?php if ($price_tva_20) : ?>
                                                              <li>
                                                                  <span class="text"><?php print number_format($price_tva_20, 0, '', ' '); ?>&nbsp;€</span>
                                                              </li>
                                                            <?php endif; ?>
                                                          <?php endif; ?>

                                                      </ul><a href="<?php print url('node/' . $biens->nid); ?>" title="<?php print t('Voir'); ?>" class="btn-primary btn-rounded"><?php print t('Voir'); ?></a>
                                                  </td>
                                              </tr>
                                              <?php
                                            endif;
                                          endif;
                                        endforeach;
                                        ?>
                                    </tbody>
                                </table>
                            </div>
                        </aside>
                    </div>
                </div>
                <!-- [popin] end-->

            </article>

            <?php
            if ($count % 6 == 0) :
              print '</div>';
            endif;
            $count++;
          endforeach;
          ?>
      </div>
      <!-- [carousel] end-->
  </section>
<?php endif; ?>