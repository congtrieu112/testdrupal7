<?php
print theme('simulator_header_block');
?>
<?php
global $base_url;
$title = variable_get('title_simulator_vos_section', '');
$subtitle = variable_get('subtitle_simulator_vos_section', '');
$iframe_url =  $base_url . '/nos-outils/simulateur-droits-ptz/ajax';
?>
<?php if($title || $subtitle || $iframe_url) : ?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <header class="heading heading--bordered">
    <h1 class="heading__title"><?php print !empty($title) ? $title : t('Simuler vos droits au PTZ+'); ?></h1>
    <?php if($subtitle) : ?>
      <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
    <?php endif; ?>
  </header>
  <?php if($iframe_url) : ?>
  <div class="swapItem">
    <div class="swapItem__1">
    <div class="wrapper--medium-up">
      <div class="iframe iframe--scrollMobile" style="min-height: 1430px">
          <iframe src="" data-src="<?php print $iframe_url; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
        </div>
    </div>
    </div>
  </div>
  <?php endif; ?>
</section>
<!-- [content Advice] end-->
<?php endif; ?>
