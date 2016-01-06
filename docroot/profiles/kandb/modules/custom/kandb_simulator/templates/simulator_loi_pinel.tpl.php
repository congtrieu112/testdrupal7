<?php
print theme('simulator_header_block');
?>
<?php
$title = variable_get('title_simulator_mon_section', '');
$subtitle = variable_get('subtitle_simulator_mon_section', '');
$adresse_ip = variable_get('adresse_ip_simulator_mon_section', '');
$param_dossier = variable_get('param_dossier_simulator_mon_section', '');
$param_id = variable_get('param_id_simulator_mon_section', '');
$iframe = '';
if($adresse_ip && $param_dossier && $param_id) {
  $iframe = '<IFRAME style="width:570px; height:700px; margin:0px; padding:0px;" allowtransparency="true" frameborder="0" scrolling="no" src="http://' . $adresse_ip . '/' . $param_dossier . '/scellier/simulrf1.asp?id=' . $param_id . '&MenageRgiHorsRF=40000&CSS_CadreHaut_TextColor=444400&CSS_Cadre_Entete_BackColor=355B95&CSS_Cadre_Body_BackColor=E0E2F9&CSS_Cadre_BorderColor=355B95&CSS_Result1_TextColor=000080&CSS_Result1_BackColor=8080FF&CSS_Result2_TextColor=000080&CSS_Result2_BackColor=8080FF"></IFRAME>';
}
?>
<?php if($title || $subtitle || $iframe) : ?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <header class="heading heading--bordered">
    <h1 class="heading__title"><?php print !empty($title) ? $title : t('Simuler mon investissement avec la loi Pinel'); ?></h1>
    <?php if($subtitle) : ?>
    <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
    <?php endif; ?>
  </header>
  <?php if ($iframe) : ?>
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