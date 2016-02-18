<?php
global $user;
?>
<div class="main-wrapper">

    <?php print render($page['header']); ?>

    <main id="container">
        <?php print theme('b2b_register_header'); ?>
        <section class="registerFormB2B wrapper section-padding">
            <div class="heading heading--bordered">
                <div class="heading__title"><?php print variable_get('kandb_b2b_register_form_title', t('Remplissez vos informations')); ?></div>
                <div class="heading__title heading__title--sub"><?php print variable_get('kandb_b2b_register_form_subtitle', t('Pour demander l\'ouverture d\'un compte')); ?></div>
            </div>
            <?php print $messages; ?>
            <?php
            if (!$user->uid) :
              $form_register = drupal_get_form('user_register_form');
              print drupal_render($form_register);
            endif;
            ?>
        </section>
        <hr>
    </main>

    <?php print render($page['footer']); ?>

    <!-- [popinLeadForm popin] start-->
    <div id="popinLeadForm" data-reveal="data-reveal" aria-hidden="true" role="dialog" data-drupal-form="data-drupal-form" class="reveal-modal full scroll"></div>
    <!-- [popinLeadForm popin] end-->
</div>