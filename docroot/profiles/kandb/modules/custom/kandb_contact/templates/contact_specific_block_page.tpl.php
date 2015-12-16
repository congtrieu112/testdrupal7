<?php
$photo_id = variable_get('kandb_contact_photo');
$nom_conseiller = '';
$array_info = array(
  'nom_conseiller' => '',
  'espace_vente_tel' => '',
  'espace_vente_tel2' => '',
  'espace_vente_adresse' => '',
  'espace_vente_horaire' => '',
  'buttons' => kandb_contact_buttons(),
);
$photo_id = isset($programme->field_photo_conseiller[LANGUAGE_NONE][0]['fid']) ? $programme->field_photo_conseiller[LANGUAGE_NONE][0]['fid'] : variable_get('kandb_contact_photo');
$array_info['nom_conseiller'] = isset($programme->field_nom_conseiller[LANGUAGE_NONE][0]['value']) ? $programme->field_nom_conseiller[LANGUAGE_NONE][0]['value'] : '';
$array_info['espace_vente_tel'] = isset($programme->field_espace_vente_tel[LANGUAGE_NONE][0]['value']) ? $programme->field_espace_vente_tel[LANGUAGE_NONE][0]['value'] : '';
$array_info['espace_vente_tel2'] = isset($programme->field_espace_vente_tel2[LANGUAGE_NONE][0]['value']) ? $programme->field_espace_vente_tel2[LANGUAGE_NONE][0]['value'] : '';
$array_info['espace_vente_adresse'] = isset($programme->field_espace_vente_adresse[LANGUAGE_NONE][0]['value']) ? $programme->field_espace_vente_adresse[LANGUAGE_NONE][0]['value'] : '';
$array_info['espace_vente_horaire'] = isset($programme->field_espace_vente_horaire[LANGUAGE_NONE][0]['value']) ? $programme->field_espace_vente_horaire[LANGUAGE_NONE][0]['value'] : '';
$photo = file_load($photo_id);
if ($wrapper = file_stream_wrapper_get_instance_by_uri($photo->uri)) :
  $array_info['photo_uri'] = $wrapper->getExternalUrl();
endif;
?>
<!-- [contactUs complete] start-->
<aside class="contactUs section-padding contactUs-complete" id="contact">
    <div style="background-image: url(<?php print $array_info['photo_uri']; ?>)" class="contactUs__img show-for-medium-up"></div>
    <div class="wrapper">
        <div class="contactUs__informations">
            <p class="contactUs__informations__heading"><?php print t('Votre conseillère'); ?></p>
            <div class="small-wrapper">
                <p class="contactUs__informations__text"><?php print $array_info['nom_conseiller']; ?></p>
                <div class="show-for-medium-up">
                    <?php if (isset($array_info['espace_vente_tel']) && $array_info['espace_vente_tel']): ?>
                      <a href="tel://<?php print str_replace(' ', '', $array_info['espace_vente_tel']); ?>" class="contactUs__informations__phone">
                          <span><?php print $array_info['espace_vente_tel'] ?></span>
                      </a>
                     <br><br>
                    <?php endif; ?>
                    <?php if (isset($array_info['espace_vente_tel2']) && $array_info['espace_vente_tel2']): ?>
                      <a href="tel://<?php print str_replace(' ', '', $array_info['espace_vente_tel2']); ?>" class="contactUs__informations__phone">
                          <span><?php print $array_info['espace_vente_tel2'] ?></span>
                      </a>
                    <?php endif; ?>
                </div>
                <div class="show-for-small-only">
                    <?php if (isset($array_info['espace_vente_tel']) && $array_info['espace_vente_tel']): ?>
                      <a href="tel://<?php print str_replace(' ', '', $array_info['espace_vente_tel']); ?>" class="contactUs__informations__phone btn-phone">
                          <span><?php print $array_info['espace_vente_tel'] ?></span>
                      </a>
                    <?php endif; ?>
                    <?php if (isset($array_info['espace_vente_tel2']) && $array_info['espace_vente_tel2']): ?>
                      <a href="tel://<?php print str_replace(' ', '', $array_info['espace_vente_tel2']); ?>" class="contactUs__informations__phone btn-phone">
                          <span><?php print $array_info['espace_vente_tel2'] ?></span>
                      </a>
                    <?php endif; ?>
                </div>

            </div>
            <?php print $array_info['buttons']; ?>
        </div>
        <div class="contactUs__description">
            <p class="contactUs__description__heading"><?php print t('Votre espace de vente'); ?></p>
            <div class="small-wrapper">
                <p class="contactUs__description__text"><?php print nl2br($array_info['espace_vente_adresse']); ?></p>
                <p class="contactUs__description__text"><?php print nl2br($array_info['espace_vente_horaire']); ?></p>
            </div>
<!--              <div class="contactUs__location"><a href="partials/formRendezVous.html" class="btn-icon btn-white btn-rounded"><span class="button__content"><span class="icon icon-marker"></span>Voir sur la carte</span></a></div>-->
        </div>
    </div>
</aside>
<!-- [contactUs complete] end-->