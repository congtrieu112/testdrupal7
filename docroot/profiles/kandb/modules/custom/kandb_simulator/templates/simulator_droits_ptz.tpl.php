<?php
print theme('simulator_header_block');
?>
<?php
global $base_url;
$title = variable_get('title_simulator_vos_section', '');
$subtitle = variable_get('subtitle_simulator_vos_section', '');
$iframe = '<IFRAME style="width:1024px; height:2048px; margin:0px; padding:0px;" allowtransparency="true" frameborder="0" scrolling="no" src="' . $base_url . '/nos-outils/simulateur-droits-ptz/ajax"></IFRAME>';
?>
<?php if($title || $subtitle || $iframe) : ?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <header class="heading heading--bordered">
    <h1 class="heading__title"><?php print !empty($title) ? $title : t('Simuler vos droits au PTZ+'); ?></h1>
    <?php if($subtitle) : ?>
      <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
    <?php endif; ?>
  </header>
  <?php if($iframe) : ?>
  <div class="swapItem">
    <div class="swapItem__1">
    <div class="wrapper--medium-up">
      <div class="iframe iframe--video-de-quartier">
        <?php print $iframe; ?>
      </div>
    </div>
    </div>
  </div>
  <?php endif; ?>
</section>
<!-- [content Advice] end-->
<?php endif; ?>
