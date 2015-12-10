<?php
/**
 * @file
 * Template of B2B Homepage.
 */
?>
<section data-equalizer data-equalizer-mq="medium-up" class="homepageB2B">
  <div data-interchange="[<?php print $bg_image_small; ?>, (small)], [<?php print $bg_image_large; ?>, (medium)]" class="homepageB2B__heading">
    <div data-equalizer-watch class="wrapper">
      <div class="heading heading--bordered heading--white">
        <div class="heading__title">
          <?php print $program_ville; ?><?php print ($program_ville AND $program_department) ? ' / ' : ''; ?><?php print $program_department; ?><br>
          <?php print $program_title; ?>
        </div>
        <div class="heading__title heading__title--sub">Rue Auguste Chevalier</div>
      </div>
      <?php if ($program_promotions) : ?>
        <?php foreach ($program_promotions as $key => $item) : ?>
          <div class="btn-wrapper btn-wrapper--center">
            <button data-reveal-id="B2bDetail" class="homepageB2B__popin__btn tag tag--important">
              <?php print $item['title']; ?><sup>&nbsp;(<?php print $key + 1; ?>)</sup>
            </button>
          </div>
          <?php if ($item['mention_legale']) : ?>
            <!-- [popin] start-->
            <div id="B2bDetail" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
              <div class="reveal-modal__wrapper">
                <a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                <div class="homepageB2B__popin__content">
                  <p><?php print $item['mention_legale']; ?></p>
                </div>
              </div>
            </div>
            <!-- [popin] end-->
          <?php endif; ?>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
  </div>
  <!-- [homepageB2B__login] start-->
  <div class="homepageB2B__login">
    <div class="wrapper">
      <div data-equalizer-watch class="homepageB2B__login--inner">
        <?php
        if ($login_form) :
          print drupal_render($login_form);
        endif;
        ?>
        <div class="homepageB2B__login__content">
          <div class="heading heading--switchColor">
            <h3 class="heading__title"><?php print t('Pas encore inscrit ?'); ?></h3>
          </div>
          <p><?php print t('Devenez un partenaire de Kaufman & Broad et accédez à plus de 1000 logements correspondants'); ?></p>
          <a href="#" title="Inscrivez - vous" class="btn-primary btn-rounded"><?php print t('Inscrivez - vous'); ?></a>
        </div>
      </div>
    </div>
  </div>
  <!-- [homepageB2B__login] end-->
</section>