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
?>

<?php print render($logementBlock['content']); ?>


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
                    <?php if ($file_plaquette_commerciale): ?>
                      <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_plaquette_commerciale) ?>" <?php if (!$file_plaquette_commerciale) print $nocontent; ?> ><span class="icon icon-flyer"></span>
                              <div class="heading heading--small">
                                  <div class="heading__title">Plaquette commerciale</div>
                              </div></a>
                      </li>
                    <?php endif; ?>
                    <?php if ($file_fiche_renseignement): ?>
                      <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_fiche_renseignement) ?>" <?php if (!$file_fiche_renseignement) print $nocontent; ?>><span class="icon icon-file"></span>
                              <div class="heading heading--small">
                                  <div class="heading__title">Kit juridique</div>
                              </div></a>
                      </li>
                    <?php endif; ?>
                    <?php if ($file_kit_fiscal): ?>
                      <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_kit_fiscal) ?>" <?php if (!$file_kit_fiscal) print $nocontent; ?>><span class="icon icon-calculator"></span>
                              <div class="heading heading--small">
                                  <div class="heading__title">Kit fiscal</div>
                              </div></a>
                      </li>
                    <?php endif; ?>
                    <?php if ($file_plan_batiment): ?>
                      <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_plan_batiment) ?>" <?php if (!$file_plan_batiment) print $nocontent; ?>><span class="icon icon-plan"></span>
                              <div class="heading heading--small">
                                  <div class="heading__title">Plan du bâtiment</div>
                              </div></a>
                      </li>
                    <?php endif; ?>
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