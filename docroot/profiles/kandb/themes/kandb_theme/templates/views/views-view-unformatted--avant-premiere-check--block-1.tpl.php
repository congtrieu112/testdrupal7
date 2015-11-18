<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php $_SESSION['avant_promotion_uncheck'] = 0; ?>
<ul class="small-block-grid-1 medium-block-grid-3">
<?php foreach ($rows as $id => $row): ?>
  <?php print $row; ?>
<?php endforeach; ?>
</ul>