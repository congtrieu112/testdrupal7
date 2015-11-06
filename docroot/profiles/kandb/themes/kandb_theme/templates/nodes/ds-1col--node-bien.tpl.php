<?php
krumo($node);
// Habitel widget
$habiteo_id = isset($node->field_bien_habiteo_id['und'][0]['value']) ? $node->field_bien_habiteo_id['und'][0]['value'] : '';
$habiteo_key = variable_get('habiteo_widget_security_key');
$habiteo_visite_virtuelle_url = variable_get('habiteo_visite-virtuelle_url');
$habiteo_plan_3d_url = variable_get('habiteo_plan-3d_url');
?>
<!-- [3rd party: visite-virtuelle] start-->
<section class="section-padding">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title">Visite virtuelle</h2>
        </header>
    </div>
    <div class="wrapper--medium-up">
        <?php if ($habiteo_id): ?>
          <div class="iframe iframe--visite-virtuelle">
              <iframe src="" data-src="<?php print $habiteo_visite_virtuelle_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>&amp;type=T2" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
          </div>
        <?php endif; ?>
    </div>
    <div class="wrapper">
        <div class="content-centered">
            <P>Appartements avec parquet, double exposition, belle hauteur sous plafond, suite parentale, dressing, cuisine américaine ou traditionnelle avec buanderie, rangements multiples…</P>
            <div class="btn-wrapper btn-wrapper--center"><a href="#" data-reveal-id="plan3d" class="btn-rounded btn-primary">Voir le plan 3D</a>
                <!-- [popin] start-->
                <?php if ($habiteo_id): ?>
                  <div id="plan3d" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                      <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                          <div class="iframe iframe--plan-3d">
                              <iframe src="" data-src="<?php print $habiteo_plan_3d_url; ?>?id=<?php print $habiteo_id; ?>&amp;key=<?php print $habiteo_key; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
                          </div>
                      </div>
                  </div>
                <?php endif; ?>
                <!-- [popin] end-->
            </div>
        </div>
    </div>
</section>
<!-- [3rd party: visite-virtuelle] start-->
<!-- [popinLeadForm popin] start-->
<div id="popinLeadForm" data-reveal="data-reveal" aria-hidden="true" role="dialog" data-drupal-form="data-drupal-form" class="reveal-modal full scroll"></div>
<!-- [popinLeadForm popin] end-->