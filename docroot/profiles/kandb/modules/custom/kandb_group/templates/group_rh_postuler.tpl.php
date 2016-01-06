<?php
  print theme('group_rh_header');
  global $base_url;
  $webform = webform_features_machine_name_load('candidature');
  $webform_path = $base_url . '/' . drupal_get_path_alias('node/' . $webform->nid);
?>
<section class="section-padding">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title"><?php print variable_get('rh_postuler_title'); ?>&nbsp;</h1>
      <div class="heading__title heading__title--sub"><?php print variable_get('rh_postuler_sub_title'); ?></div>
    </header>
    <div class="bg-lightGrey blockText-centered">
      <article>
        <div class="blockText-centered__spaced">
          <h2 class="heading--tiny"><?php print variable_get('rh_postuler_title_paragraph'); ?></h2>
        </div>
        <div class="blockText-centered__spaced">
          <p><?php print variable_get('rh_postuler_text_paragraph'); ?></p>
        </div>
        <div class="btn-wrapper btn-wrapper--center"><a href="<?php print $webform_path; ?>" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-primary btn-rounded"><?php print variable_get('rh_postuler_button_paragraph'); ?></a></div>
      </article>
    </div>
    <?php print $view; ?>
  </div>
</section>