<?php
print theme('simulator_header_block');
?>
<?php
$title = variable_get('title_simulator_mon_section');
$subtitle = variable_get('subtitle_simulator_mon_section');
?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <header class="heading heading--bordered">
    <h1 class="heading__title"><?php print !empty($title) ? $title : t('Simuler mon investissement avec la loi Pinel'); ?></h1>
    <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
  </header>
</section>
<!-- [content Advice] end-->
