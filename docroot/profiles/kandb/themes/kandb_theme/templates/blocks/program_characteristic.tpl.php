<?php
if (!isset($programme_variables) || empty($programme_variables)) {
  return;
}
?>
<section class="section-padding bg-lightGrey">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h2 class="heading__title"><?php if (isset($programme_variables['prestations_titre'])) { print $programme_variables['prestations_titre']; } ?></h2>
      <div class="heading__title heading__title--sub"><?php if (isset($programme_variables['prestations_sous_titre'])) { print $programme_variables['prestations_sous_titre']; } ?></div>
    </header>
  </div>
  <div class="programCharacteristics">
    <ul role="tablist" data-slick-nav="data-slick-nav" class="show-for-medium-up programCharacteristics__nav">
      <li><a href="#slide0" data-slick-links="data-slick-links" role="tab" aria-controls="slide0" class="active" aria-selected="true"><?php print t('Extérieur'); ?></a></li>
      <li><a href="#slide1" data-slick-links="data-slick-links" role="tab" aria-controls="slide1" aria-selected="false"><?php print t('Intérieur'); ?></a></li>
      <li><a href="#slide2" data-slick-links="data-slick-links" role="tab" aria-controls="slide2" aria-selected="false"><?php print t('Services'); ?></a></li>
      <li><a href="#slide3" data-slick-links="data-slick-links" role="tab" aria-controls="slide03" aria-selected="false"><?php print t('RT 2012'); ?></a></li>
    </ul>
    <ul data-slick="data-slick" data-slick-responsive="medium" data-app-accordion="data-app-accordion" data-app-accordion-responsive="small-only" class="accordion fullwidth">
    <li id="slide0">
      <a href="#slide0" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link active"><?php print t('Extérieur') ;?><span class="display-status"></span></a>
     <?php
       $alt = isset($programme_variables['slider_exterieur_image_alt']) ? $programme_variables['slider_exterieur_image_alt'] : 'Photo extérieure';
       $small = isset($programme_variables['slider_exterieur_image_small']) ? $programme_variables['slider_exterieur_image_small'] : '';
       $medium = isset($programme_variables['slider_exterieur_image_medium']) ? $programme_variables['slider_exterieur_image_medium'] : '';
     ?>
     <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
       <div class="programCharacteristicsItem__img">
         <img alt="<?php print $alt ;?>" data-interchange="[<?php print $small ;?>, (small)], [<?php print $medium ;?>, (medium)]">
         <noscript>&lt;img src="<?php print $medium ;?>" alt="<?php print $alt; ?>"/&gt;</noscript>
       </div>
       <div class="programCharacteristicsItem__content">
         <h3 class="heading--tiny"><?php if (isset($programme_variables['slider_exterieur_titre'])) { print $programme_variables['slider_exterieur_titre']; } ?></h3>
         <p><?php if (isset($programme_variables['slider_exterieur_description'])) { print $programme_variables['slider_exterieur_description']; } ?></p>
       </div>
     </article>
      </li>
      <li id="slide1">
        <a href="#slide1" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link"><?php print t('Intérieur') ;?><span class="display-status"></span></a>
     <?php
       $alt = isset($programme_variables['slider_interieur_image_alt']) ? $programme_variables['slider_interieur_image_alt'] : 'Photo extérieure';
       $small = isset($programme_variables['slider_interieur_image_small']) ? $programme_variables['slider_interieur_image_small'] : '';
       $medium = isset($programme_variables['slider_interieur_image_medium']) ? $programme_variables['slider_interieur_image_medium'] : '';
     ?>
     <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
       <div class="programCharacteristicsItem__img">
         <img alt="<?php print $alt ;?>" data-interchange="[<?php print $small ;?>, (small)], [<?php print $medium ;?>, (medium)]">
         <noscript>&lt;img src="<?php print $medium ;?>" alt="<?php print $alt; ?>"/&gt;</noscript>
       </div>
       <div class="programCharacteristicsItem__content">
         <h3 class="heading--tiny"><?php if (isset($programme_variables['slider_interieur_titre'])) { print $programme_variables['slider_interieur_titre']; } ?></h3>
         <p><?php if (isset($programme_variables['slider_interieur_description'])) { print $programme_variables['slider_interieur_description']; } ?></p>
       </div>
     </article>
      </li>
      <li id="slide2">
        <a href="#slide2" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link"><?php print t('Services') ;?><span class="display-status"></span></a>
     <?php
       $alt = isset($programme_variables['slider_securite_image_alt']) ? $programme_variables['slider_securite_image_alt'] : 'Photo extérieure';
       $small = isset($programme_variables['slider_securite_image_small']) ? $programme_variables['slider_securite_image_small'] : '';
       $medium = isset($programme_variables['slider_securite_image_medium']) ? $programme_variables['slider_securite_image_medium'] : '';
     ?>
     <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
       <div class="programCharacteristicsItem__img">
         <img alt="<?php print $alt ;?>" data-interchange="[<?php print $small ;?>, (small)], [<?php print $medium ;?>, (medium)]">
         <noscript>&lt;img src="<?php print $medium ;?>" alt="<?php print $alt; ?>"/&gt;</noscript>
       </div>
       <div class="programCharacteristicsItem__content">
         <h3 class="heading--tiny"><?php if (isset($programme_variables['slider_securite_titre'])) { print $programme_variables['slider_securite_titre']; } ?></h3>
         <p><?php if (isset($programme_variables['slider_securite_description'])) { print $programme_variables['slider_securite_description']; } ?></p>
       </div>
     </article>
      </li>
      <li id="slide3">
        <a href="#slide3" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link"><?php print t('RT 2012') ;?><span class="display-status"></span></a>
     <?php
       $alt = isset($programme_variables['slider_rt2012_image_alt']) ? $programme_variables['slider_rt2012_image_alt'] : 'Photo extérieure';
       $small = isset($programme_variables['slider_rt2012_image_small']) ? $programme_variables['slider_rt2012_image_small'] : '';
       $medium = isset($programme_variables['slider_rt2012_image_medium']) ? $programme_variables['slider_rt2012_image_medium'] : '';
     ?>
     <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
       <div class="programCharacteristicsItem__img">
         <img alt="<?php print $alt ;?>" data-interchange="[<?php print $small ;?>, (small)], [<?php print $medium ;?>, (medium)]">
         <noscript>&lt;img src="<?php print $medium ;?>" alt="<?php print $alt; ?>"/&gt;</noscript>
       </div>
       <div class="programCharacteristicsItem__content">
         <h3 class="heading--tiny"><?php if (isset($programme_variables['slider_rt2012_titre'])) { print $programme_variables['slider_rt2012_titre']; } ?></h3>
         <p><?php if (isset($programme_variables['slider_rt2012_description'])) { print $programme_variables['slider_rt2012_description']; } ?></p>
       </div>
     </article>
      </li>
    </ul>
  </div>
</section>