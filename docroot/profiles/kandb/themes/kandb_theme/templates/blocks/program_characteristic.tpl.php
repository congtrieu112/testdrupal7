<?php
if (!isset($programme_variables) || empty($programme_variables)) {
  return;
}
$slide0 = $slide1 = $slide2 = $slide3 = FALSE;
if((isset($programme_variables['slider_exterieur_image_small'])
    && isset($programme_variables['slider_exterieur_image_medium']))
    || $programme_variables['slider_exterieur_description'] != ''
    || $programme_variables['slider_exterieur_titre'] != '' ) {
  $slide0 = TRUE;
}
if((isset($programme_variables['slider_interieur_image_small'])
    && isset($programme_variables['slider_interieur_image_medium']))
    || $programme_variables['slider_interieur_description'] != ''
    || $programme_variables['slider_interieur_titre'] != '' ) {
  $slide1 = TRUE;
}
if((isset($programme_variables['slider_securite_image_small'])
    && isset($programme_variables['slider_securite_image_medium']))
    || $programme_variables['slider_securite_description'] != ''
    || $programme_variables['slider_securite_titre'] != '' ) {
  $slide2 = TRUE;
}
if((isset($programme_variables['slider_rt2012_image_small'])
    && isset($programme_variables['slider_rt2012_image_medium']))
    || $programme_variables['slider_rt2012_description'] != ''
    || $programme_variables['slider_rt2012_titre'] != '' ) {
  $slide3 = TRUE;
}
?>

<?php if($slide0 || $slide1 || $slide2 || $slide3) : ?>
<section class="section-padding bg-lightGrey">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h2 class="heading__title"><?php print isset($programme_variables['prestations_titre'])?$programme_variables['prestations_titre']:''; ?></h2>
      <div class="heading__title heading__title--sub"><?php print isset($programme_variables['prestations_sous_titre'])?$programme_variables['prestations_sous_titre']:'';?></div>
    </header>
  </div>
  <div class="programCharacteristics">
    <ul role="tablist" data-slick-nav="data-slick-nav" class="show-for-medium-up programCharacteristics__nav">
      <?php if($slide0) : ?>
      <li><a href="#slide0" data-slick-links="data-slick-links" role="tab" aria-controls="slide0" class="active" aria-selected="true"><?php print t('Extérieur'); ?></a></li>
      <?php endif; ?>
      <?php if($slide1) : ?>
      <li><a href="#slide1" data-slick-links="data-slick-links" role="tab" aria-controls="slide1" aria-selected="false"><?php print t('Intérieur'); ?></a></li>
      <?php endif; ?>
      <?php if($slide2) : ?>
      <li><a href="#slide2" data-slick-links="data-slick-links" role="tab" aria-controls="slide2" aria-selected="false"><?php print t('Sécurité'); ?></a></li>
      <?php endif; ?>
      <?php if($slide3) : ?>
      <li><a href="#slide3" data-slick-links="data-slick-links" role="tab" aria-controls="slide03" aria-selected="false"><?php print t('RT 2012'); ?></a></li>
      <?php endif; ?>
    </ul>
    <ul data-slick="data-slick" data-slick-responsive="medium" data-app-accordion="data-app-accordion" data-app-accordion-responsive="small-only" class="accordion fullwidth">
      <?php if($slide0) : ?>
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
          if(empty($small) && !empty($default_image)):
            $small = image_style_url("program_characteristic_small", $default_image);
          endif;

          if(empty($medium) && !empty($default_image)):
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
                    <h3 class="heading--tiny"><?php print isset($programme_variables['slider_exterieur_titre'])?$programme_variables['slider_exterieur_titre']:''; ?></h3>
                    <p><?php print isset($programme_variables['slider_exterieur_description'])?$programme_variables['slider_exterieur_description']:''; ?></p>
                  </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
              </li>
      <?php endif; ?>
      <?php if($slide1) : ?>
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
          if(empty($small) && !empty($default_image)):
            $small = image_style_url("program_characteristic_small", $default_image);
          endif;

          if(empty($medium) && !empty($default_image)):
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
                    <h3 class="heading--tiny"><?php print isset($programme_variables['slider_interieur_titre'])?$programme_variables['slider_interieur_titre']:''; ?></h3>
                    <p><?php print isset($programme_variables['slider_interieur_description'])?$programme_variables['slider_interieur_description']:''; ?></p>
                  </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
              </li>

      <?php endif; ?>
      <?php if($slide2) : ?>
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
          if(empty($small) && !empty($default_image)):
            $small = image_style_url("program_characteristic_small", $default_image);
          endif;

          if(empty($medium) && !empty($default_image)):
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
                    <h3 class="heading--tiny"><?php print isset($programme_variables['slider_securite_titre'])?$programme_variables['slider_securite_titre']:''; ?></h3>
                    <p><?php print isset($programme_variables['slider_securite_description'])?$programme_variables['slider_securite_description']:''; ?></p>
                  </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
              </li>
      <?php endif; ?>
      <?php if($slide3) : ?>
            <li id="slide3">
                <!-- mobile accordion trigger--><a href="#slide3" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link">RT 2012<span class="display-status"></span></a>
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
                          if(empty($small) && !empty($default_image)):
                            $small = image_style_url("program_characteristic_small", $default_image);
                          endif;

                          if(empty($medium) && !empty($default_image)):
                            $medium = image_style_url("program_characteristic_medium", $default_image);
                          endif;
                       ?>
                    <!-- [Responsive img] start-->
                    <img alt="<?php print $alt; ?>" data-interchange="[<?php print $small; ?>, (small)], [<?php print $medium; ?>, (medium)]"/>
                    <noscript>
                    <img src="<?php print $medium; ?>" alt="<?php print $alt; ?>"/>
                    </noscript>
                    <!-- [Responsive img] end-->
<!--                    <figure class="rt2012">
                      <div class="rt2012__img">
                         images are static and named:
                        - rt2012-A.png
                        - rt2012-B.png
                        - rt2012-C.png
                        - rt2012-D.png
                        - rt2012-E.png
                        - rt2012-F.png
                        - rt2012-G.png
                        <img src="assets/images/rt2012-A.png" alt="RT2012 Niveau A"/>
                      </div>
                      <figcaption class="rt2012__caption">
                         image is static<img src="assets/images/rt2012-logo.png" alt="Grenelle Environnement, règlementation thermique 2012"/>
                      </figcaption>
                    </figure>-->
                  </div>
                  <div class="programCharacteristicsItem__content">
                    <h3 class="heading--tiny"><?php print isset($programme_variables['slider_rt2012_titre'])?$programme_variables['slider_rt2012_titre']:'' ?></h3>
                    <p><?php print isset($programme_variables['slider_rt2012_description'])?print $programme_variables['slider_rt2012_description']: ''?></p>
                  </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
              </li>
      <?php endif; ?>
    </ul>
  </div>
</section>
<?php endif ; ?>