<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 *
 * If a preview is enabled, these keys will be available on the preview page:
 * - $form['preview_message']: The preview message renderable.
 * - $form['preview']: A renderable representing the entire submission preview.
 */
?>
<?php
  // Print out the progress bar at the top of the page
  print drupal_render($form['progressbar']);

  // Print out the preview message if on the preview page.
  if (isset($form['preview_message'])) {
    print '<div class="messages warning">';
    print drupal_render($form['preview_message']);
    print '</div>';
  }
  ?>
<?php if($form['#node']->webform['machine_name'] == 'prendre_rendez_vous') : ?>
<form method="post" action="partials/formRendezVous.html" class="webform-client-form">
  <fieldset class="row row--noGutter medium-uncollapse small-collapse">
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
      <?php print render($form['submitted']['rdv_nom']) ;?>
    </div>
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
      <?php print render($form['submitted']['rdv_prenom']) ;?>
    </div>
  </fieldset>
  <fieldset>
    <div class="webform-component webform-component-textfield">
      <?php print render($form['submitted']['rdv_adresse1']) ;?>
    </div>
    <div class="webform-component webform-component-textfield">
      <?php print render($form['submitted']['rdv_adresse2']) ;?>
    </div>
  </fieldset>
  <fieldset class="row row--noGutter medium-uncollapse small-collapse">
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
      <?php print render($form['submitted']['rdv_lieudit']) ;?>
    </div>
  </fieldset>
  <fieldset class="row row--noGutter medium-uncollapse small-collapse">
    <div class="webform-component webform-component-textfield small-12 medium-4 columns">
      <?php print render($form['submitted']['rdv_ville']) ;?>
    </div>
    <div class="webform-component webform-component-textfield small-12 medium-4 columns">
      <?php print render($form['submitted']['rdv_code_postal']) ;?>
    </div>
    <div class="webform-component webform-component-textfield small-12 medium-4 columns">
      <?php print render($form['submitted']['rdv_pays']) ;?>
    </div>
  </fieldset>
  <fieldset class="row row--noGutter medium-uncollapse small-collapse">
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
      <?php print render($form['submitted']['rdv_telephone']) ;?>
    </div>
    <div class="webform-component webform-component-textfield small-12 medium-6 columns">
      <?php print render($form['submitted']['rdv_email']) ;?>
    </div>
  </fieldset>
  <div class="webform-component webform-component-textarea">
      <?php print render($form['submitted']['rdv_message']) ;?>
  </div>
  <div class="webform-component">
      <?php $form['submitted']['rdv_newsletter']['#title'] = ''; print render($form['submitted']['rdv_newsletter']) ;?>
  </div>
  <div class="webform-component webform-component-select">
      <?php print render($form['submitted']['rdv_connu']) ;?>
  </div>
  <input type="hidden" name="from" value="B2C-ourAdvices"/>
  <div class="form-actions">
      <?php print render($form['actions']) ;?>
  </div>
</form>
<?php elseif ($form['#node']->webform['machine_name'] == '_tre_rappel_') : ?>
<form method="post" action="partials/formCallBack.html" class="webform-client-form">
  <fieldset class="row row--noGutter medium-uncollapse small-collapse">
    <?php print render($form['submitted']['row_1']['rappeler_nom']) ;?>
    <?php print render($form['submitted']['row_1']['rappeler_prenom']) ;?>
  </fieldset>
  <fieldset class="row row--noGutter medium-uncollapse small-collapse">
    <?php print render($form['submitted']['row_2']['rappeler_telephone']) ;?>
    <?php print render($form['submitted']['row_2']['rappeler_horaire']) ;?>
  </fieldset>
  <input type="hidden" name="from" value="B2C-ourAdvices"/>
  <div class="form-actions">
  <?php print render($form['actions']) ;?>
  </div>
</form>
<?php endif; ?>
<?php print drupal_render_children($form);?>

