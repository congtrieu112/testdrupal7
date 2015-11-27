<?php
$errors = form_get_errors();
?>
<div class="searchFormular searchFormular-homepage">
    <form id="<?php print $form['#id']; ?>" data-abide="data-abide" class="searchFormular__form" novalidate="novalidate" accept-charset="UTF-8" method="<?php print $form['#method']; ?>" action="<?php print $form['#action']; ?>">
        <div class="input-withSubmit">
            <label class="input">
                <span class="visually-hidden"><?php print t('Ville, département ou programme'); ?></span>
                <?php print render($form['place']); ?>
                <small class="error"><?php print t('Veuillez saisir votre recherche'); ?></small>
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
                            <?php print render($form['field_type']); ?>
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
                                    <input type="number" name="prix_min" placeholder="Min" step="1000" class="input__text small-padding text-center">
                                </label>
                            </li>
                            <li>
                                <label class="input">
                                    <div class="input__label visually-hidden"><?php print t('Max'); ?></div>
                                    <input type="number" name="prix_max" placeholder="Max" step="1000" class="input__text small-padding text-center">
                                </label>
                            </li>
                        </ul>
                    </div>
                </div>

                <?php print render($form['submit']); ?>
            </div>
        </div>
    </form>
</div>
