<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$terms = kandb_validate_get_ville_avant();
?>

<form class="filter">
    <label for="offersFilter" class="filter__label"><?php print t('Trier par'); ?></label>
    <select id="offersFilter" data-app-select data-app-filter="prochainement" name="offersFilter" class="filter__select">
        <option value="">-</option>
        <?php
        if ($terms):
          foreach ($terms as $key => $term) :
            ?>
            <option value="<?php print $key; ?>"><?php print $term; ?></option>
            <?php
          endforeach;
        endif;
        ?>
    </select>
</form>
<?php $_SESSION['avant_promotion_uncheck'] = 0; ?>
<ul data-app-filter-target="prochainement" class="flex-content ul-unstyled">
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
</ul>