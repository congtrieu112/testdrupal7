<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php $_SESSION['avant_promotion_uncheck'] = 0; ?>
<ul data-app-filter-target="prochainement" class="flex-content ul-unstyled">
<?php foreach ($rows as $id => $row): ?>
  <?php print $row; ?>
<?php endforeach; ?>
</ul>