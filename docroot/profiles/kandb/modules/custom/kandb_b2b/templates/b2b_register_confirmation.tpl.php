<?php
$default_description = variable_get('kandb_b2b_register_confirmation_description');
?>
<?php print theme('b2b_register_header'); ?>
<section class="registerConfirmationB2B">
    <div class="blockText-centered">
        <article class="heading--small">
            <h2 class="heading__title"><?php print variable_get('kandb_b2b_register_confirmation_title', t('Votre inscription a bien été prise en compte.')); ?></h2>
            <p class="heading__title--sub"><?php print isset($default_description['value']) ? $default_description['value'] : t('Merci de votre intérêt. Un conseiller va prendre contact avec vous très rapidement.')  ?></p>
        </article>
    </div>
</section>