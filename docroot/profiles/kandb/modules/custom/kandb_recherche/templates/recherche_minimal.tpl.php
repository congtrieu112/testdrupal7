<?php
$errors = form_get_errors();
?>
<div class="searchFormular searchFormular-homepage">
    <form id="<?php print $form['#id']; ?>" data-abide="data-abide" class="searchFormular__form" novalidate="novalidate" accept-charset="UTF-8" method="<?php print $form['#method']; ?>" action="<?php print $form['#action']; ?>">
        <div class="input-withSubmit">
            <label class="input"><span class="visually-hidden"></span>
                <?php print render($form['place']); ?>
                <small class="error"><?php print $errors['place']; ?></small>
            </label>
        </div>

        <?php print render($form['submit']); ?>
        <?php print drupal_render_children($form); ?>
    </form>
</div>
