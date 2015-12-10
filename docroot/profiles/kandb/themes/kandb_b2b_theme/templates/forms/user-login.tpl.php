<?php
/**
 * @file
 * Template of login block form.
 */
?>

<div class="heading heading--switchColor">
  <h3 class="heading__title">Déjà partenaire ?</h3>
</div>
<div class="homepageB2B__login--textfield">
  <label for="userName" class="visually-hidden">Votre identifiant <span class="form-required" title="This field is required.">*</span></label>
  <?php print drupal_render($form['name']); ?>
  <label for="password" class="visually-hidden">Votre mot de passe <span class="form-required" title="This field is required.">*</span></label>
  <?php print drupal_render($form['pass']); ?>
</div>
<div class="homepageB2B__login--inlineGroup">
  <div class="homepageB2B__login--checkbox">
    <?php print drupal_render($form['remember_me']); ?>
    <label for="rememberMe" class="label-checkbox">
      <span><?php print t('Se souvenir de moi'); ?></span>
    </label>
  </div>
  <a href="#" title="Mot de passe oublié?" class="textLink">
    <?php print t('Mot de passe oublié?'); ?>
  </a>
</div>
<?php print drupal_render($form['actions']); ?>
<?php
print drupal_render($form['form_build_id']);
print drupal_render($form['form_token']);
print drupal_render($form['form_id']);
?>
