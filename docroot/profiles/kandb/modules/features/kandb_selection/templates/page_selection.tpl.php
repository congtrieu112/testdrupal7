<?php
/**
 * @file
 * Selection Page which will load ajax
 */

?>
<section data-interchange="[<?php print $backgrounds['small']; ?>, (small)], [<?php print $backgrounds['medium']; ?>, (medium)]" class="narrow-header" >
  <div class="wrapper">
    <div class="heading heading--bordered heading--white">
      <div class="heading__title"><?php print $title; ?></div>
      <div class="heading__title heading__title--sub"><?php print $sub_title; ?></div>
    </div>
  </div>
</section>
<div data-app-ajax="cookies" data-app-ajax-url="<?php print $ajax_url; ?>">
</div>
<?php print $contact; ?>
