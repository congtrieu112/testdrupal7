<?php
/**
 * @file
 * Default simple view template to display a rows in a grid.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
?>
<?php if ($rows): ?>
  <nav class="pageHeaderNav wrapper">
      <?php foreach ($rows as $row_number => $columns): ?>
        <ul class="pageHeaderNav__list">
            <?php foreach ($columns as $column_number => $item): ?>
              <?php
              $check_active = strpos($item, 'active');
              if ($check_active !== false)
                $class_active = 'active';
              else
                $class_active = '';
              ?>
              <li class="pageHeaderNav__list__item <?php print $class_active ?>"><?php print $item ?></li>
                <?php endforeach; ?>
        </ul>
      <?php endforeach; ?>
  </nav>
<?php endif; ?>