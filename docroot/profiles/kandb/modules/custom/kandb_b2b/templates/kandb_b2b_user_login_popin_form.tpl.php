<?php
/**
 * @file
 * Template of login block form.
 */
?>
<fieldset>
    <?php print drupal_render($form['name']); ?>
    <?php print drupal_render($form['pass']); ?>
</fieldset>
<div class="links">
    <div class="login--save-password">
        <?php print drupal_render($form['remember_me']); ?>
        <label for="saveCredentials" class="label-checkbox"><span><?php print t('Se souvenir de moi'); ?></span></label>
    </div>
    <a href="<?php print url('user/password') ?>" title="<?php print t('Mot de passe oublié?'); ?> " class="login--password-link">
        <?php print t('Mot de passe oublié?'); ?>
    </a>
</div>
<?php print drupal_render($form['actions']); ?>
<?php
print drupal_render($form['form_build_id']);
print drupal_render($form['form_token']);
print drupal_render($form['form_id']);
