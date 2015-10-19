<?php
$errors = form_get_errors();
?>
<section class="searchFormular searchFormular--results">
    <div class="wrapper">
        <form id="<?php print $form['#id'] ?>" data-abide="data-abide" class="searchFormular__form" novalidate="novalidate" accept-charset="UTF-8" method="<?php print $form['#method']; ?>" action="<?php print $form['#action']; ?>">
            <div class="input-withSubmit">
                <label class="input">
                    <span class="visually-hidden"><?php print t('Ville, département ou programme'); ?></span>
                    <?php print render($form['place']); ?>
                    <small class="error"><?php print $errors['place']; ?></small>
                </label>

                <button class="button-submit js-btn-submit" type="submit">
                    <span class="icon icon-search" aria-hidden="true"></span>
                    <span class="visually-hidden"><?php print t('Rechercher'); ?></span>
                </button>
            </div>

            <div class="searchFormular__filters hidden" aria-hidden="true" id="dropdown-search-filters">
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
                        <div class="form-dropdown__content hidden" aria-hidden="true" id="dropdown-price-choice" style="display: none;">
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
                    <div class="form-dropdown">
                        <button class="form-dropdown__trigger" data-app-dropdown="search" aria-controls="dropdown-rooms-choice" aria-expanded="false">
                            <?php print t('Pièces'); ?>
                            <span class="icon icon-expand" aria-hidden="true"></span>
                        </button>
                        <div class="form-dropdown__content hidden" aria-hidden="false" id="dropdown-rooms-choice">
                            <ul class="ul-unstyled with-columns undo-padding">
                                <?php print render($form['pieces']); ?>
                            </ul>
                        </div>
                    </div>
                    <div class="form-dropdown">
                        <button class="form-dropdown__trigger" data-app-dropdown="search" aria-controls="dropdown-surface-choice" aria-expanded="false">
                            <?php print t('Surface'); ?>
                            <span class="icon icon-expand" aria-hidden="true"></span>
                        </button>
                        <div class="form-dropdown__content hidden" aria-hidden="true" id="dropdown-surface-choice" style="display: none;">
                            <label class="input">
                                <div class="input__label visually-hidden"><?php print t('Min'); ?></div>
                                <?php print render($form['surface_min']); ?>
                            </label>
                        </div>
                    </div>
                    <div class="form-dropdown">
                        <button class="form-dropdown__trigger" data-app-dropdown="search" aria-controls="dropdown-services-choice" aria-expanded="false">
                            <?php print t('Services'); ?>
                            <span class="icon icon-expand" aria-hidden="true"></span>
                        </button>
                        <div class="form-dropdown__content hidden" aria-hidden="true" id="dropdown-services-choice">
                            <ul class="ul-unstyled undo-padding">
                                <?php print render($form['services']); ?>
                            </ul>
                        </div>
                    </div>
                </div>

                <div class="form-dropdown__bottom">
                    <?php print render($form['submit']); ?>
                </div>
            </div>

            <button class="searchFormular__more js-form-more" data-app-dropdown="remove" aria-controls="dropdown-search-filters" aria-expanded="false">
                <span class="icon icon-expand" aria-hidden="true"></span>
                <?php print t('Plus de critères'); ?>
            </button>

            <?php print drupal_render_children($form); ?>
        </form>
    </div>
</section>
