<?php
$image_path = kandb_theme_get_path('assets/images');
if (!isset($programme_variables) || empty($programme_variables)) {
  return;
}
$slide0 = $slide1 = $slide2 = $slide3 = FALSE;
if ((isset($programme_variables['slider_exterieur_image_small']) && isset($programme_variables['slider_exterieur_image_medium'])) || $programme_variables['slider_exterieur_description'] != '' || $programme_variables['slider_exterieur_titre'] != '') {
  $slide0 = TRUE;
}
if ((isset($programme_variables['slider_interieur_image_small']) && isset($programme_variables['slider_interieur_image_medium'])) || $programme_variables['slider_interieur_description'] != '' || $programme_variables['slider_interieur_titre'] != '') {
  $slide1 = TRUE;
}
if ((isset($programme_variables['slider_securite_image_small']) && isset($programme_variables['slider_securite_image_medium'])) || $programme_variables['slider_securite_description'] != '' || $programme_variables['slider_securite_titre'] != '') {
  $slide2 = TRUE;
}
if ((isset($programme_variables['slider_rt2012_image_small']) && isset($programme_variables['slider_rt2012_image_medium'])) || $programme_variables['slider_rt2012_description'] != '' || $programme_variables['slider_rt2012_titre'] != '') {
  $slide3 = TRUE;
}

// Echelle.
$echelle_value = '';
$echelle = isset($node->field_slider_rt2012_echelle[LANGUAGE_NONE][0]['value']) ? $node->field_slider_rt2012_echelle['und'][0]['value'] : '';
if ($echelle) {
  $my_field = field_info_field('field_slider_rt2012_echelle');
  $allowed_values = list_allowed_values($my_field);
  $echelle_value = $allowed_values[$echelle];
}
$rt2012_bbc = isset($node->field_slider_rt2012_bbc[LANGUAGE_NONE][0]['value']) ? $node->field_slider_rt2012_bbc['und'][0]['value'] : '';
if ($rt2012_bbc) {
  $logo = ($rt2012_bbc == '1') ? variable_get('image_default_slider_rt2012_logo') : variable_get('image_default_slider_bbc_logo');
  $tab_title = ($rt2012_bbc == '1') ? t('RT2012') : t('BBC');
}
$logo_image = isset($logo) ? file_load($logo) : '';
$logo_image_path = isset($logo_image->uri) ? file_create_url($logo_image->uri) : '';
?>

<?php if ($slide0 || $slide1 || $slide2 || $slide3) : ?>
  <section class="section-padding bg-lightGrey" id="prestations">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title">
                  <?php
                    if (isset($programme_variables['prestations_titre']) && $programme_variables['prestations_titre']) :
                        print $programme_variables['prestations_titre'];
                    else:
                        print variable_get('kandb_program_default_title_prestations', 'Les détails du programme');
                    endif;
                  ?>
              </h2>
              <div class="heading__title heading__title--sub">
                  <?php
                    if (isset($programme_variables['prestations_sous_titre']) && $programme_variables['prestations_sous_titre']) :
                        print $programme_variables['prestations_sous_titre'];
                    else :
                        print variable_get('kandb_program_default_subtitle_prestations', 'Un immeuble haut-de-gamme et sécurisé');
                    endif;
                  ?>
              </div>
          </header>
      </div>
      <div class="programCharacteristics">
          <ul role="tablist" data-slick-nav="data-slick-nav" class="show-for-medium-up programCharacteristics__nav">
              <?php if ($slide0 && $programme_variables['slider_exterieur_titre']) : ?>
                <li><a href="#slide0" data-slick-links="data-slick-links" role="tab" aria-controls="slide0" class="active" aria-selected="true" onclick="javascript:return tc_events_1(this,'CLICK',{'LABEL':'pages_programmes::exterieur','XTCLICK_EVENT':'C','XTCLICK_S2':'2','XTCLICK_TYPE':'N'});"><?php print t('Extérieur'); ?></a></li>
              <?php endif; ?>
              <?php if ($slide1 && $programme_variables['slider_interieur_titre']) : ?>
                <li><a href="#slide1" data-slick-links="data-slick-links" role="tab" aria-controls="slide1" aria-selected="false" onclick="javascript:return tc_events_1(this,'CLICK',{'LABEL':'pages_programmes::interieur','XTCLICK_EVENT':'C','XTCLICK_S2':'2','XTCLICK_TYPE':'N'});"><?php print t('Intérieur'); ?></a></li>
              <?php endif; ?>
              <?php if ($slide2 && $programme_variables['slider_securite_titre']) : ?>
                <li><a href="#slide2" data-slick-links="data-slick-links" role="tab" aria-controls="slide2" aria-selected="false" onclick="javascript:return tc_events_1(this,'CLICK',{'LABEL':'pages_programmes::services','XTCLICK_EVENT':'C','XTCLICK_S2':'2','XTCLICK_TYPE':'N'});"><?php print t('Sécurité'); ?></a></li>
              <?php endif; ?>
              <?php if ($slide3 && $programme_variables['slider_rt2012_titre']) : ?>
                <?php if ($echelle_value != 'Void' && $echelle_value && $tab_title): ?>
                  <li><a href="#slide3" data-slick-links="data-slick-links" role="tab" aria-controls="slide03" aria-selected="false" onclick="javascript:return tc_events_1(this,'CLICK',{'LABEL':'pages_programmes::rt_2012','XTCLICK_EVENT':'C','XTCLICK_S2':'2','XTCLICK_TYPE':'N'});"><?php print $tab_title; ?></a></li>
                <?php endif; ?>
              <?php endif; ?>
          </ul>
          <ul data-slick="data-slick" data-slick-responsive="medium" data-app-accordion="data-app-accordion" data-app-accordion-responsive="small-only" class="accordion fullwidth">
              <?php if ($slide0 && $programme_variables['slider_exterieur_titre']) : ?>
                <li id="slide0">

                    <!-- mobile accordion trigger-->
                    <a href="#slide0" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link active"><?php print t('Extérieur'); ?><span class="display-status"></span></a>
                    <!-- [programCharacteristicsItem] start-->
                    <!-- image need to have 2 formats:
                    - small: 560 x 230 (HEAVY compression!!!)
                    - medium: 1380 x 400
                    -->
                    <?php
                    $alt = isset($programme_variables['slider_exterieur_image_alt']) ? $programme_variables['slider_exterieur_image_alt'] : '';
                    $small = isset($programme_variables['slider_exterieur_image_small']) ? $programme_variables['slider_exterieur_image_small'] : '';
                    $medium = isset($programme_variables['slider_exterieur_image_medium']) ? $programme_variables['slider_exterieur_image_medium'] : '';

                    $default_image = variable_get('image_default_slider_exterieur_image');
                    if (empty($small) && !empty($default_image)):
                      $small = image_style_url("program_characteristic_small", $default_image);
                    endif;

                    if (empty($medium) && !empty($default_image)):
                      $medium = image_style_url("program_characteristic_medium", $default_image);
                    endif;
                    ?>
                    <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                        <div class="programCharacteristicsItem__img">
                            <!-- [Responsive img] start-->
                            <img alt="<?php print $alt; ?>" data-interchange="[<?php print $small; ?>, (small)], [<?php print $medium; ?>, (medium)]"/>
                            <noscript>
                            <img src="<?php print $small; ?>" alt="<?php print $alt; ?>"/></noscript>
                            <!-- [Responsive img] end-->
                        </div>
                        <div class="programCharacteristicsItem__content">
                            <h3 class="heading--tiny"><?php print isset($programme_variables['slider_exterieur_titre']) ? $programme_variables['slider_exterieur_titre'] : ''; ?></h3>
                            <p><?php print isset($programme_variables['slider_exterieur_description']) ? $programme_variables['slider_exterieur_description'] : ''; ?></p>
                        </div>
                    </article>
                    <!-- [programCharacteristicsItem] end-->
                </li>
              <?php endif; ?>
              <?php if ($slide1 && $programme_variables['slider_interieur_titre']) : ?>
                <li id="slide1">
                    <!-- mobile accordion trigger-->
                    <a href="#slide1" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link"><?php print t('Intérieur'); ?><span class="display-status"></span></a>
                    <!-- [programCharacteristicsItem] start-->
                    <!-- image need to have 2 formats:
                    - small: 560 x 230 (HEAVY compression!!!)
                    - medium: 1380 x 400
                    -->
                    <?php
                    $alt = isset($programme_variables['slider_interieur_image_alt']) ? $programme_variables['slider_interieur_image_alt'] : '';
                    $small = isset($programme_variables['slider_interieur_image_small']) ? $programme_variables['slider_interieur_image_small'] : '';
                    $medium = isset($programme_variables['slider_interieur_image_medium']) ? $programme_variables['slider_interieur_image_medium'] : '';

                    $default_image = variable_get('image_default_slider_interieur_image');
                    if (empty($small) && !empty($default_image)):
                      $small = image_style_url("program_characteristic_small", $default_image);
                    endif;

                    if (empty($medium) && !empty($default_image)):
                      $medium = image_style_url("program_characteristic_medium", $default_image);
                    endif;
                    ?>
                    <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                        <div class="programCharacteristicsItem__img">
                            <!-- [Responsive img] start-->
                            <img alt="<?php print $alt; ?>" data-interchange="[<?php print $small; ?>, (small)], [<?php print $medium; ?>, (medium)]"/>
                            <noscript>
                            <img src="<?php print $medium; ?>" alt="<?php print $alt; ?>"/></noscript>
                            <!-- [Responsive img] end-->
                        </div>
                        <div class="programCharacteristicsItem__content">
                            <h3 class="heading--tiny"><?php print isset($programme_variables['slider_interieur_titre']) ? $programme_variables['slider_interieur_titre'] : ''; ?></h3>
                            <p><?php print isset($programme_variables['slider_interieur_description']) ? $programme_variables['slider_interieur_description'] : ''; ?></p>
                        </div>
                    </article>
                    <!-- [programCharacteristicsItem] end-->
                </li>

              <?php endif; ?>
              <?php if ($slide2 && $programme_variables['slider_securite_titre']) : ?>
                <li id="slide2">
                    <!-- mobile accordion trigger-->
                    <a href="#slide2" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link"><?php print t('Sécurité'); ?><span class="display-status"></span></a>
                    <!-- [programCharacteristicsItem] start-->
                    <!-- image need to have 2 formats:
                    - small: 560 x 230 (HEAVY compression!!!)
                    - medium: 1380 x 400
                    -->
                    <?php
                    $alt = isset($programme_variables['slider_securite_image_alt']) ? $programme_variables['slider_securite_image_alt'] : '';
                    $small = isset($programme_variables['slider_securite_image_small']) ? $programme_variables['slider_securite_image_small'] : '';
                    $medium = isset($programme_variables['slider_securite_image_medium']) ? $programme_variables['slider_securite_image_medium'] : '';

                    $default_image = variable_get('image_default_slider_securite_image');
                    if (empty($small) && !empty($default_image)):
                      $small = image_style_url("program_characteristic_small", $default_image);
                    endif;

                    if (empty($medium) && !empty($default_image)):
                      $medium = image_style_url("program_characteristic_medium", $default_image);
                    endif;
                    ?>
                    <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                        <div class="programCharacteristicsItem__img">
                            <!-- [Responsive img] start-->
                            <img alt="<?php print $alt; ?>" data-interchange="[<?php print $small; ?>, (small)], [<?php print $medium; ?>, (medium)]"/>
                            <noscript>
                            <img src="<?php print $medium; ?>" alt="<?php print $alt; ?>"/></noscript>
                            <!-- [Responsive img] end-->
                        </div>
                        <div class="programCharacteristicsItem__content">
                            <h3 class="heading--tiny"><?php print isset($programme_variables['slider_securite_titre']) ? $programme_variables['slider_securite_titre'] : ''; ?></h3>
                            <p><?php print isset($programme_variables['slider_securite_description']) ? $programme_variables['slider_securite_description'] : ''; ?></p>
                        </div>
                    </article>
                    <!-- [programCharacteristicsItem] end-->
                </li>
              <?php endif; ?>
              <?php if ($slide3 && $programme_variables['slider_rt2012_titre']) : ?>
                <?php if ($echelle_value != 'Void' && $echelle_value && $tab_title): ?>
                  <li id="slide3">
                      <!-- mobile accordion trigger--><a href="#slide3" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link"><?php print $tab_title; ?><span class="display-status"></span></a>
                      <!-- [programCharacteristicsItem] start-->
                      <!-- image need to have 2 formats:
                      - small: 560 x 230 (HEAVY compression!!!)
                      - medium: 1380 x 400
                      -->
                      <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                          <div class="programCharacteristicsItem__img">
                              <?php
                              $alt = isset($programme_variables['slider_rt2012_image_alt']) ? $programme_variables['slider_rt2012_image_alt'] : '';
                              $small = isset($programme_variables['slider_rt2012_image_small']) ? $programme_variables['slider_rt2012_image_small'] : '';
                              $medium = isset($programme_variables['slider_rt2012_image_medium']) ? $programme_variables['slider_rt2012_image_medium'] : '';

                              $default_image = variable_get('image_default_slider_rt2012_image');
                              if (empty($small) && !empty($default_image)):
                                $small = image_style_url("program_characteristic_small", $default_image);
                              endif;

                              if (empty($medium) && !empty($default_image)):
                                $medium = image_style_url("program_characteristic_medium", $default_image);
                              endif;
                              ?>
                              <!-- [Responsive img] start-->
                              <img alt="<?php print $alt; ?>" data-interchange="[<?php print $small; ?>, (small)], [<?php print $medium; ?>, (medium)]"/>
                              <noscript>
                              <img src="<?php print $medium; ?>" alt="<?php print $alt; ?>"/>
                              </noscript>
                              <!-- [Responsive img] end-->
                              <figure class="rt2012">
                                  <div class="rt2012__img">
                                      <!-- images are static and named:
                                                              - rt2012-A.png
                                                              - rt2012-B.png
                                                              - rt2012-C.png
                                                              - rt2012-D.png
                                                              - rt2012-E.png
                                                              - rt2012-F.png
                                                              - rt2012-G.png-->
                                      <img src="<?php print $image_path . '/rt2012-' . $echelle_value . '.png' ?>" alt="<?php print t('RT2012 Niveau') . ' ' . $echelle_value; ?>"/>
                                  </div>
                                  <figcaption class="rt2012__caption">
                                      <img src="<?php print $logo_image_path; ?>" alt="<?php print t('Grenelle Environnement, règlementation thermique 2012'); ?>"/>
                                  </figcaption>
                              </figure>
                          </div>
                          <div class="programCharacteristicsItem__content">
                              <h3 class="heading--tiny"><?php print isset($programme_variables['slider_rt2012_titre']) ? $programme_variables['slider_rt2012_titre'] : ''  ?></h3>
                              <p><?php print isset($programme_variables['slider_rt2012_description']) ? $programme_variables['slider_rt2012_description'] : '' ?></p>
                          </div>
                      </article>
                      <!-- [programCharacteristicsItem] end-->
                  </li>
                <?php endif; ?>
              <?php endif; ?>
          </ul>
      </div>
  </section>
<?php endif; ?>
