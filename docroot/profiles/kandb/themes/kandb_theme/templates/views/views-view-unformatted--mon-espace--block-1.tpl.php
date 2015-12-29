<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="wrapper--narrow">
    <ul data-app-accordion="data-app-accordion" data-seemore-list="programmes" class="accordion fullWidth mySelectionsProgrammes">
        <?php foreach ($rows as $id => $row): ?>
            <li data-selection-item="data-selection-item" class="accordion__link">
                <?php print $row; ?>
            </li>
        <?php endforeach; ?>
    </ul>
</div>

<?php if (count($rows) > 5) : ?>
    <!-- [seeMore] start-->
    <div data-seemore="programmes" data-seemore-nbr='5' class="voir-plus">
        <button class="btn-primary btn-rounded"> <?php print t('Voir plus'); ?><span class="icon icon-arrow down"></span></button>
    </div>
    <!-- [seeMore] end-->
<?php endif; ?>

