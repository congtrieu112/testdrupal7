<?php
/**
 * @file
 * Template of login block form.
 */
?>

<div class="heading heading--switchColor">
  <h3 class="heading__title"><?php print t('Déjà partenaire ?'); ?> </h3>
</div>
<div class="homepageB2B__login--textfield">
  <label for="userName" class="visually-hidden"><?php print t('Votre identifiant'); ?> <span class="form-required" title="<?php print t('This field is required.'); ?>">*</span></label>
  <?php print drupal_render($form['name']); ?>
  <label for="password" class="visually-hidden"><?php print t('Votre mot de passe'); ?> <span class="form-required" title="<?php print t('This field is required.'); ?>">*</span></label>
  <?php print drupal_render($form['pass']); ?>
</div>
<div class="homepageB2B__login--inlineGroup">
  <div class="homepageB2B__login--checkbox">
    <?php print drupal_render($form['remember_me']); ?>
    <label for="<?php print $form['remember_me']['#id']; ?>" class="label-checkbox">
      <span><?php print t('Se souvenir de moi'); ?></span>
    </label>
  </div>
  <a href="<?php print url('user/password') ?>" title="<?php print t('Mot de passe oublié?'); ?> " class="textLink">
    <?php print t('Mot de passe oublié?'); ?>
  </a>
</div>
<?php print drupal_render($form['actions']); ?>
<?php
print drupal_render($form['form_build_id']);
print drupal_render($form['form_token']);
print drupal_render($form['form_id']);
?>
