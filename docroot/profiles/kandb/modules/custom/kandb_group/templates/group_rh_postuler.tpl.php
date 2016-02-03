<?php
$tabs = kandb_group_button_tabs_header($_GET['q']);
print $tabs;
print theme('group_rh_header');
global $base_url;
$webform = webform_features_machine_name_load('candidature');
$webform_path = $base_url . '/' . drupal_get_path_alias('node/' . $webform->nid);
$rh_postuler_text_paragraph = variable_get('rh_postuler_text_paragraph');

$rh_postuler_title = variable_get('rh_postuler_title');
$rh_postuler_sub_title = variable_get('rh_postuler_sub_title');
$rh_postuler_title_paragraph = variable_get('rh_postuler_title_paragraph');
$rh_postuler_button_paragraph = variable_get('rh_postuler_button_paragraph');
?>
<section class="section-padding">
    <div class="wrapper">
        <?php if(!empty($rh_postuler_title) || !empty($rh_postuler_sub_title)): ?>
        <header class="heading heading--bordered">
            <?php if(!empty($rh_postuler_title)): ?><h1 class="heading__title"><?php print $rh_postuler_title; ?>&nbsp;</h1><?php endif; ?>
            <?php if(!empty($rh_postuler_sub_title)): ?><div class="heading__title heading__title--sub"><?php print $rh_postuler_sub_title; ?></div><?php endif; ?>
        </header>
        <?php endif;?>
        <?php if(!empty($rh_postuler_title_paragraph) || (isset($rh_postuler_text_paragraph['value']) && !empty($rh_postuler_text_paragraph['value'])) || (!empty($webform_path) && !empty($rh_postuler_button_paragraph))): ?>
        <div class="bg-lightGrey blockText-centered">
            <article>
                <?php if(!empty($rh_postuler_title_paragraph)): ?>
                <div class="blockText-centered__spaced">
                    <h2 class="heading--tiny"><?php print $rh_postuler_title_paragraph; ?></h2>
                </div>
                <?php endif; ?>
                <?php if(isset($rh_postuler_text_paragraph['value']) && !empty($rh_postuler_text_paragraph['value'])): ?>
                <div class="blockText-centered__spaced">
                    <p><?php print $rh_postuler_text_paragraph['value']; ?></p>
                </div>
                <?php endif; ?>
                <?php if(!empty($webform_path) && !empty($rh_postuler_button_paragraph)): ?>
                <div class="btn-wrapper btn-wrapper--center"><a href="<?php print $webform_path; ?>" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-primary btn-rounded"><?php print variable_get('rh_postuler_button_paragraph'); ?></a></div>
                <?php endif; ?>
            </article>
        </div>
        <?php endif; ?>
        <?php print $view; ?>
    </div>
</section>