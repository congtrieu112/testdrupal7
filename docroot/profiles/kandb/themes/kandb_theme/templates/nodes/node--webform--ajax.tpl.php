<?php
$webform_title = $node->title;
if ($node->webform['machine_name'] == '_tre_rappel_') {
  foreach ($node->webform['machine_name']['components'] as $components) {
    if ($components['machine_name'] == '_tre_rappel___popin_title') {
      $webform_title = $components['value'];
    }
  }
}
?>
<div class="heading heading--bordered heading--small">
  <div class="heading__title"><?php print $webform_title; ?></div>
</div>
<?php print render($content); ?>