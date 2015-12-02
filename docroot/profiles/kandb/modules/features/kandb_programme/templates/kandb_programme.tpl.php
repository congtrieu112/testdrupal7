<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
$title = isset($logement_block['title']) ? $logement_block['title'] : '';
?>
<?php
if ($logement_block && isset($logement_block['total_bien'])) :
  ?>
  <section class="section-padding bg-lightGrey">
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
            if ($count % 6 == 1) :
              print '<div class="unwrap">';
            endif;
            ?>
            <article data-reveal-id="programParcel<?php print $count; ?>"  class="programParcelItem">                
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img; ?>programParcel-small.jpg, (small)], [<?php print $path_img; ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img; ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading"><?php print $total; ?>&nbsp;<?php print t('appartements de'); ?>&nbsp;<?php print $type; ?>&nbsp;<?php print t('disponibles'); ?></h3>
                    <div class="programParcelItem__prices">
                        <?php
                        if (isset($logement_block['price_min_tva_un_20_bien'][$type]) && isset($logement_block['tva_bien'][$type])) :
                          ?>
                          <p><span><?php print t('À partir de '); ?><?php print number_format($logement_block['price_min_tva_un_20_bien'][$type], 0, '', ' ') . '€'; ?></span><span class="tva"><?php print 'TVA ' . $logement_block['tva_bien'][$type]*100 . '%'; ?></span></p>
                          <?php
                        endif;
                        ?>

                        <?php
                        if (isset($logement_block['price_min_tva20_bien'][$type])) :
                          ?>
                          <p><span><?php print t('À partir de '); ?><?php print number_format($logement_block['price_min_tva20_bien'][$type], 0, '', ' ') . '€'; ?></span><span class="tva tva--high">TVA 20%</span></p>
                          <?php
                        endif;
                        ?>

                    </div>
                </div>

                <!-- [popin] start-->
                <div id="programParcel<?php print $count; ?>" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                  <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                    <aside class="programParcelPopin">
                      <div class="heading heading--bordered">
                          <p class="heading__title"><?php print t('Appartements'); ?>&nbsp;<?php print $type; ?>&nbsp;<?php print t('disponibles'); ?></p>
                        <p class="heading__title heading__title--sub"><?php print t('dans ce programme'); ?></p>
                      </div>
                      <div class="moreAvailable">
                        <table class="responsive">
                          <tbody>

                            <?php foreach($logement_block['popin_program'][$type] as $node_bien_id) :
                              if($node_bien_id) :
                                $biens = node_load($node_bien_id);
                                if($biens) :
                                  $bien_id = isset($biens->field_id_bien[LANGUAGE_NONE][0]['value']) ? $biens->field_id_bien[LANGUAGE_NONE][0]['value'] : '';
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
                                  if($caracteristiques && count($caracteristiques) > 0) {
                                    foreach($caracteristiques as $caracteristique) {
                                      $term_caracteristique = taxonomy_term_load($caracteristique['tid']);
                                      if($term_caracteristique) {
                                        $arr_caracteris[] = $term_caracteristique->name;
                                      }
                                    }
                                  }

                                  $arr_caracteris[] = isset($biens->field_cave_description[LANGUAGE_NONE][0]['value']) ? $biens->field_cave_description[LANGUAGE_NONE][0]['value'] : '';
                                  $arr_caracteris[] = isset($biens->field_parking_description[LANGUAGE_NONE][0]['value']) ? $biens->field_parking_description[LANGUAGE_NONE][0]['value'] : '';

                                  $etage_tid = isset($biens->field_etage[LANGUAGE_NONE][0]['tid']) ? $biens->field_etage[LANGUAGE_NONE][0]['tid'] : '';
                                  $etage = '';
                                  if($etage_tid) {
                                    $term_etage = taxonomy_term_load($etage_tid);
                                    if($term_etage) {
                                      $etage = $term_etage->name;
                                    }
                                  }
                            ?>
                              <tr>
                                <td><?php if($bien_id) : print $bien_id; endif; ?></td>
                                <td>
                                  <div class="list-item">
                                    <div class="list-characteristics">
                                      <ul>
                                        <?php if(count($arr_caracteris) > 0) : ?>
                                        <li class="item-ulities">
                                            <ul>
                                              <?php foreach($arr_caracteris as $caracteris) : ?>
                                                <?php if($caracteris) : ?>
                                                  <li><?php print $caracteris; ?></li>
                                                <?php endif; ?>
                                              <?php endforeach; ?>
                                            </ul>
                                        </li>
                                        <?php endif; ?>
                                        <?php if($superficie) : ?><li class="item-area"><?php print str_replace ('.', ',', $superficie) . "m<sup>2</sup>"; ?></li><?php endif; ?>
                                        <?php if($etage) : ?><li class="item-exhibit"><?php print $etage; ?></li><?php endif; ?>
                                      </ul>
                                    </div>
                                  </div>
                                </td>
                                <td>
                                  <ul class="list-price">
                                      <?php if($price_tva_20) : ?>
                                        <li><span class="text"><?php print number_format($price_tva_20, 0, '', ' '); ?>&nbsp;€</span><span class="tva">TVA 5,5%</span></li>
                                      <?php endif; ?>

                                      <?php if($low_tva_price) : ?>
                                        <li><span class="text"><?php print number_format($low_tva_price, 0, '', ' '); ?>&nbsp;€</span><span class="tva tva--high">TVA 20%</span></li>
                                      <?php endif; ?>
                                  </ul><a href="#" title="<?php print t('Voir'); ?>" class="btn-primary btn-rounded"><?php print t('Voir'); ?></a>
                                </td>
                              </tr>
                            <?php
                                endif;
                              endif;
                            endforeach; ?>
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