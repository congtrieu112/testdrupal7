<fieldset class="row">
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
        <label for="registerName"><?php print t('Nom'); ?> <span class="form-required" title="This field is required.">*</span></label>
        <?php print drupal_render($form['group_profile']['field_user_nom']); ?>
    </div>
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
        <label for="registerFirstName"><?php print t('Prénom'); ?> <span class="form-required" title="This field is required.">*</span></label>
        <?php print drupal_render($form['group_profile']['field_prenom']); ?>
    </div>
</fieldset>
<fieldset class="row">
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
        <label for="registerSociete"><?php print t('Société'); ?> <span class="form-required" title="This field is required.">*</span></label>
        <?php print drupal_render($form['group_profile']['field_user_societe']); ?>
    </div>
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
        <label for="registerSociete"><?php print t('Email'); ?> <span class="form-required" title="This field is required.">*</span></label>
        <?php print drupal_render($form['account']['mail']); ?>
    </div>
</fieldset>
<fieldset class="row">
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
        <label for="registerAdresse"><?php print t('Adresse'); ?> <span class="form-required" title="This field is required.">*</span></label>
        <?php print drupal_render($form['group_profile']['field_user_adresse']); ?>
    </div>
    <div class="webform-component webform-component-textfield small-6 medium-3 columns">
        <label for="registerCPVille"><?php print t('Code postal / Ville'); ?></label>
        <?php print drupal_render($form['group_profile']['field_user_ville']); ?>
    </div>
    <div class="webform-component webform-component-textfield small-6 medium-3 columns">
        <label for="registerPays"><?php print t('Pays'); ?></label>
        <?php print drupal_render($form['group_profile']['field_user_pays']); ?>
    </div>
</fieldset>
<fieldset class="row">
    <div class="webform-component webform-component-textfield small-6 medium-3 columns">
        <label for="registerTelephoneFixe"><?php print t('Téléphone fixe'); ?></label>
        <?php print drupal_render($form['group_profile']['field_user_telephone']); ?>
    </div>
    <div class="webform-component webform-component-textfield small-6 medium-3 columns">
        <label for="registerPortable"><?php print t('Portable'); ?></label>
        <?php print drupal_render($form['group_profile']['field_user_portable']); ?>
    </div>
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
        <label for="registerAdresseMessagerie"><?php print t('Adresse de messagerie'); ?></label>
        <?php print drupal_render($form['group_profile']['field_user_email']); ?>
    </div>
</fieldset>
<fieldset class="row">
    <div class="webform-component webform-component-textarea small-12 columns">
        <label for="registerText"><?php print t('Votre message'); ?></label>
        <div class="form-textarea-wrapper resizable-textarea">
            <?php print drupal_render($form['group_profile']['field_user_message']); ?>
        </div>
    </div>
</fieldset>
<div class="form-actions">
    <?php print drupal_render($form['actions']); ?>
</div>

<?php print render($form['token']); ?>
<?php print render($form['form_build_id']); ?>
<?php print render($form['form_id']); ?>