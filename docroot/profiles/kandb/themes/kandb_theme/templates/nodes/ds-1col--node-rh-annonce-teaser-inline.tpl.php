<?php
global $base_url;
$webform = webform_features_machine_name_load('candidature');
$webform_path = $base_url . '/' . drupal_get_path_alias('node/' . $webform->nid);
?>

<article id="postuler<?php print $id; ?>" class="accordion__link postuler__item <?php if (isset($id) && $id == 1) print 'opened'; ?>">
  <header class="latestJobs__item__heading"><span class="latestJobs__item__date"><?php if(isset($field_annonce_date_mise_en_ligne[0]['value'])) print date_format(date_create($field_annonce_date_mise_en_ligne[0]['value']), 'd/m/Y'); ?></span>
    <h2 class="latestJobs__item__title"><?php if(isset($field_annonce_fonction[0]['taxonomy_term']->name)) print $field_annonce_fonction[0]['taxonomy_term']->name; ?></h2><span class="latestJobs__item__address"><?php if(isset($field_annonce_ville[0]['taxonomy_term']->name)) print $field_annonce_ville[0]['taxonomy_term']->name; ?></span>
  </header>
  <div data-app-accordion-link="#postuler<?php print $id; ?>" role="button" class="display-status <?php if (isset($id) && $id == 1) print 'active'; ?>" <?php if (isset($id) && $id == 1) print 'aria-selected="true" aria-expanded="true"'; ?>><span class="show-for-sr">fermer</span></div>
  <div class="postuler__item__content">
    <div data-app-accordion-content="data-app-accordion-content" tab-index="-1" style="display: none;" class="">
      <p><?php if(isset($field_annonce_description[0]['value'])) print $field_annonce_description[0]['value']; ?></p>
      <p>
        <strong>Profil requis : </strong>
        <?php if(isset($field_annonce_profile[0]['value'])) print $field_annonce_profile[0]['value']; ?>
      </p>
    </div>
    <ul class="postuler__details">
      <li>
        <strong>Service : </strong>
        <?php if(isset($field_annonce_service[0]['value'])) print $field_annonce_service[0]['value']; ?>
      </li>
      <li>
        <strong>Type de contrat : </strong>
        <?php if(isset($field_annonce_type_contrat[0]['taxonomy_term']->name))print $field_annonce_type_contrat[0]['taxonomy_term']->name; ?>
      </li>
      <li>
        <strong>A pourvoir à partir de : </strong>
        <?php if(isset($field_annonce_date_debut[0]['value'])) print date_format(date_create($field_annonce_date_debut[0]['value']), 'd/m/Y'); ?>
      </li>
      <li>
        <strong>Expérience exigée : </strong>
        <?php if(isset($field_annonce_experience[0]['taxonomy_term']->name)) print $field_annonce_experience[0]['taxonomy_term']->name; ?>
      </li>
    </ul>
    <div data-app-accordion-content="data-app-accordion-content" class="btn-wrapper btn-wrapper--center" tab-index="-1" style="display: none;"><a href="<?php print $webform_path; ?>?annonce=<?php print $nid; ?>" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-primary btn-rounded"><?php print variable_get('rh_postuler_form_button', t('Postuler')); ?></a></div>
  </div>
</article>
