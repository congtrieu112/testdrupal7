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
    <iframe width="100%" height="760" src="<?php print $iframe_url; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="yes"></iframe>
  <?php endif; ?>
</section>
<!-- [content Advice] end-->
<?php endif; ?>
