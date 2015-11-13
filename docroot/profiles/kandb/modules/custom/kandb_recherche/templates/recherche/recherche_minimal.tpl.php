<?php
$errors = form_get_errors();
?>
<div class="searchFormular searchFormular-homepage">
    <form id="<?php print $form['#id']; ?>" data-abide="data-abide" class="searchFormular__form" novalidate="novalidate" accept-charset="UTF-8" method="<?php print $form['#method']; ?>" action="<?php print $form['#action']; ?>">
        <div class="input-withSubmit">
            <label class="input">
                <span class="visually-hidden"><?php print t('Ville, département ou programme'); ?></span>
                <?php print render($form['place']); ?>
                <small class="error"><?php print t('Veuillez saisir votre recherche'); ?></small>
            </label>
        </div>

        <?php print render($form['submit']); ?>
    </form>
</div>
