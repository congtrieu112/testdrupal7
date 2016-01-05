<?php
global $base_url;
$webform = webform_features_machine_name_load('candidature');
$webform_path = $base_url . '/' . drupal_get_path_alias('node/' . $webform->nid);
/*
$field_annonce_date_mise_en_ligne[0]['value'];
$field_annonce_ville_[0]['value']; // Remove
*/

?>
<a href="<?php print $webform_path; ?>?annonce=<?php print $nid; ?>" class="btn-primary btn-rounded" data-reveal-ajax="true" data-reveal-id="popinLeadForm" ><?php print variable_get('rh_postuler_form_button', t('Postuler')); ?></a>
