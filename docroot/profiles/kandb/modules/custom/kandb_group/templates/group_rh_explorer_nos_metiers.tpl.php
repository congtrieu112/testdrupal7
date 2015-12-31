<?php
/**
 * @file
 * Explore our business template.
 */
?>

<?php print theme('group_rh_header'); ?>
<?php
$module_title = variable_get('explore_our_businesses_module_title');
$button_label = variable_get('explore_our_businesses_button_label');
$button_link = variable_get('explore_our_businesses_button_link');
?>
<!-- [metier] start-->
<section class="section-padding metier bg-lightGrey">
    <div class="wrapper">
        <?php if ($module_title): ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $module_title; ?></h1>
          </header>  
        <?php endif; ?>
        <div class="metier__list">
            <?php for ($i = 0; $i <= KANDB_GROUP_OUR_BUSINESS_ITEMS_NUM; $i++) : ?>
              <?php
              $wording = variable_get('fieldset_expolore_our_businesses_wording' . $i);
              $description = variable_get('fieldset_expolore_our_businesses_description' . $i);
              $description = isset($description['value']) ? $description['value'] : '';
              ?>
              <?php if ($wording AND $description) : ?>
                <div class="metier__item">
                    <div class="metier__item__heading">
                        <h4 class="metier__item__title"><?php print $wording; ?></h4>
                    </div>
                    <div class="metier__item__content">
                        <?php print $description; ?>
                    </div>
                </div>
              <?php endif; ?>
            <?php endfor; ?>

        </div>
        <?php if ($button_label AND $button_link) : ?>
          <div class="btn-wrapper">
              <a href="<?php print url($button_link); ?>" class="btn-rounded btn-primary">
                  <?php print $button_label; ?>
                  <span class="icon icon-arrow"></span>
              </a>
          </div>
        <?php endif; ?>
    </div>
</section>
<!-- [metier] end-->
