<?php
/**
 * @file
 * Template file for search block of my selection
 *
 * Receive :
 * $recherches
 */
?>
<?php if (!empty($recherches)): ?>
<div>
  Recherche
  <?php foreach ($recherches as $url_recherche): ?>

  <?php endforeach; ?>
</div>
<?php endif; ?>
