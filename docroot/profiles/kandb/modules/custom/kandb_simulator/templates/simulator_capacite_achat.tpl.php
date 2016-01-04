<?php
print theme('simulator_header_block');
?>
<?php
$title = variable_get('title_simulator_calculer_section');
$subtitle = variable_get('subtitle_simulator_calculer_section');
?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <header class="heading heading--bordered">
    <h1 class="heading__title"><?php print !empty($title) ? $title : t('Calculer votre capacité d’achat'); ?></h1>
    <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
  </header>
</section>
<!-- [content Advice] end-->
