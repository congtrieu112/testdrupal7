<?php
print theme('simulator_header_block');
?>
<?php
global $base_url;
$title = variable_get('title_simulator_calculer_section');
$subtitle = variable_get('subtitle_simulator_calculer_section');
$iframe_url = $base_url . '/nos-outils/simulateur-capacite-achat-fnfg';
?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <header class="heading heading--bordered">
    <h1 class="heading__title"><?php print !empty($title) ? $title : t('Calculer votre capacité d’achat'); ?></h1>
    <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
  </header>
  <iframe width="100%" height="890" src="<?php print $iframe_url; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="yes"></iframe>
</section>
<!-- [content Advice] end-->
