<section data-equalizer data-equalizer-mq="medium-up" class="homepageB2B">
  <div data-interchange="[test_assets/homepageB2b-bg-small.jpg, (small)], [test_assets/homepageB2b-bg-large.jpg, (medium)]" class="homepageB2B__heading">
    <div data-equalizer-watch class="wrapper">
      <div class="heading heading--bordered heading--white">
        <div class="heading__title">Centre Tours / 37<br>Le Caducée</div>
        <div class="heading__title heading__title--sub">Rue Auguste Chevalier</div>
      </div>
      <div class="btn-wrapper btn-wrapper--center">
        <button data-reveal-id="B2bDetail" class="homepageB2B__popin__btn tag tag--important">Suuconmission de 3% et frais de notaires offerts<sup>&nbsp;(1)</sup></button>
      </div>
      <!-- [popin] start-->
      <div id="B2bDetail" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
        <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
          <div class="homepageB2B__popin__content">
            <p>Content Update later</p>
          </div>
        </div>
      </div>
      <!-- [popin] end-->
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