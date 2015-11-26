<?php
$webform_title = $node->title;
if ($node->webform['machine_name'] == '_tre_rappel_') {
  $webform_title = t('Rappelez moi');
}
?>
<div class="heading heading--bordered heading--small">
  <div class="heading__title"><?php print $webform_title; ?></div>
</div>
<?php print render($content); ?>