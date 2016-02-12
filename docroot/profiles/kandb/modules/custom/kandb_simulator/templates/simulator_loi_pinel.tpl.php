<?php
print theme('simulator_header_block');
?>
<?php
$title = variable_get('title_simulator_mon_section', '');
$subtitle = variable_get('subtitle_simulator_mon_section', '');
$adresse_ip = variable_get('adresse_ip_simulator_mon_section', '');
$param_dossier = variable_get('param_dossier_simulator_mon_section', '');
$param_id = variable_get('param_id_simulator_mon_section', '');
$iframe_url = '';
if($adresse_ip && $param_dossier && $param_id) {
  $iframe_url = 'http://' . $adresse_ip . '/' . $param_dossier . '/scellier/simulrf1.asp?id=' . $param_id . '&amp;MenageRgiHorsRF=40000&amp;CSS_CadreHaut_TextColor=003d5d&amp;CSS_Cadre_Entete_BackColor=ff0000&amp;CSS_Cadre_Body_BackColor=f2f5f6&amp;CSS_Cadre_BorderColor=f2f5f6&amp;CSS_Result1_TextColor=003d5d&amp;CSS_Result1_BackColor=b2d8e9&amp;CSS_Result2_TextColor=003d5d&amp;CSS_Result2_BackColor=b2d8e9&amp;CSS_Cadre_Saisie_LigHeight=40&amp;CSS_Cadre_BorderWidth=1&amp;FlagCharte=2&amp;CSS_BtnCalcul_BackColor=199edd&amp;CSS_ResultTitle1_TextColor=003d5d&amp;CSS_Cadre_Body_TextColor=003d5d&amp;CSS_Cadre_Saisie_TextColor=199edd&amp;CSS_ResultTitle2_TextColor=003e5e&amp;CSS_Cadre_Entete_TextColor=003e5e&amp;CSS_Pie_TitleColor=003e5e&amp;CSS_Pie_LabelColor=003e5e&amp;CSS_Form_BackColor=transparent&amp;CSS_Pie_Bordercolor=ffffff&amp;CSS_Cadre_Result_BackColor=f2f5f6&amp;CSS_Cadre_Saisie_BackColor=ffffff&amp;CSS_Pie_TitleSize=14&amp;FlagDispoQuestions=1';
}
?>
<?php if($title || $subtitle || $iframe_url) : ?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <header class="heading heading--bordered">
    <h2 class="heading__title"><?php print !empty($title) ? $title : t('110.1 - calculer votre capacité d’achat (PINEL simulator)'); ?></h2>
    <?php if($subtitle) : ?>
    <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
    <?php endif; ?>
  </header>
  <?php if ($iframe_url) : ?>
  <div class="swapItem">
    <div class="swapItem__1">
      <div class="wrapper--medium-up">
          <iframe width="100%" height="1235" src="" data-src="<?php print $iframe_url; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="yes"></iframe>
      </div>
    </div>
  </div>
  <?php endif; ?>
</section>
<!-- [content Advice] end-->
<?php endif; ?>
