<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<ul data-app-accordion="data-app-accordion" data-seemore-list="programmes" class="accordion fullWidth mySelectionsProgrammes">
  <?php foreach ($rows as $id => $row): ?>
    <li data-selection-item="data-selection-item" class="accordion__link">
      <?php print $row; ?>
    </li>
  <?php endforeach; ?>
</ul>
