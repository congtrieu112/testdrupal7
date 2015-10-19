<?php
$errors = form_get_errors();
?>
<div class="searchFormular searchFormular-homepage">
    <form id="<?php print $form['#id']; ?>" data-abide="data-abide" class="searchFormular__form" novalidate="novalidate" accept-charset="UTF-8" method="<?php print $form['#method']; ?>" action="<?php print $form['#action']; ?>">
        <div class="input-withSubmit">
            <label class="input"><span class="visually-hidden"></span>
                <?php print render($form['place']); ?>
                <small class="error"><?php print $errors['place']; ?></small>
            </label>
        </div>

        <div class="searchFormular__filters false" aria-hidden="true" id="dropdown-search-filters">
            <div class="searchFormular__dropdowns">
                <div class="form-dropdown">
                    <button class="form-dropdown__trigger" data-app-dropdown="search" aria-controls="dropdown-type-choice" aria-expanded="false">
                        <?php print t('Type'); ?>
                        <span class="icon icon-expand" aria-hidden="true"></span>
                    </button>
                    <div class="form-dropdown__content hidden" aria-hidden="true" id="dropdown-type-choice">
                        <ul class="ul-unstyled undo-padding">
                            <?php print render($form['type']); ?>
                        </ul>
                    </div>
                </div>

                <div class="form-dropdown">
                    <button class="form-dropdown__trigger" data-app-dropdown="search" aria-controls="dropdown-price-choice" aria-expanded="false">
                        <?php print t('Prix'); ?>
                        <span class="icon icon-expand" aria-hidden="true"></span>
                    </button>
                    <div class="form-dropdown__content hidden" aria-hidden="true" id="dropdown-price-choice">
                        <ul class="ul-unstyled price-range">
                            <li>
                                <label class="input">
                                    <div class="input__label visually-hidden"><?php print t('Min'); ?></div>
                                    <?php print render($form['prix_min']); ?>
                                </label>
                            </li>
                            <li>
                                <label class="input">
                                    <div class="input__label visually-hidden"><?php print t('Max'); ?></div>
                                    <?php print render($form['prix_max']); ?>
                                </label>
                            </li>
                        </ul>
                    </div>
                </div>

                <?php print render($form['submit']); ?>
            </div>
        </div>
        <?php print drupal_render_children($form); ?>
    </form>
</div>
