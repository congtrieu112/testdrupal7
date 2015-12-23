<?php
print theme('finance_header_block');
?>
<!-- [Finance Gouvernance] start-->
<section class="section-padding financeGouvernance">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h1 class="heading__title"><?php print t('Gouvernance d\'entreprise'); ?></h1>
        </header>
    </div>
    <div class="wrapper">
        <!-- [linksBlock: dropdown] start-->
        <nav class="filter filter--left">
            <div class="filter__label show-for-medium-up"><?php print t('Afficher par'); ?>:</div>
            <div class="form-dropdown form-dropdown--floating filter__item">
                <div>
                    <button aria-expanded="false" aria-controls="governance" data-app-dropdown="data-app-dropdown" type="button" class="form-dropdown__trigger"><span class="text">Conseil d'Administration</span><span aria-hidden="true" class="icon icon-expand"></span></button>
                </div>
                <div id="governance" aria-hidden="true" class="form-dropdown__content form-dropdown__content--last hidden">
                    <?php if ($voca): ?>
                      <ul class="ul-unstyled undo-padding">
                          <?php
                          foreach ($voca as $value):
                            $selected = 'false';
                            $term_load = taxonomy_term_load($value->tid);
                            $name = $term_load->name;
                            if ($lang == 'en' && isset($term_load->field_comite_title_en[LANGUAGE_NONE][0]['value'])) {
                              $name = $term_load->name;
                            }
                            if ($value->tid == $term_id) {
                              $selected = 'true';
                            }
                            $path = url('corporate/finance/gouvernance/' . $value->tid . '/' . $lang);
                            ?>
                            <li class="bordered"><a href="<?php print $path; ?>" tabindex="0" aria-selected="<?php print $selected; ?>"><?php print $name; ?></a></li>
                          <?php endforeach; ?>
                      </ul>
                    <?php endif; ?>
                </div>
            </div>
        </nav>
        <!-- [linksBlock: dropdown] end-->
        <div class="financeGouvernance__list">
            <?php if ($data): ?>
              <?php foreach ($data as $item): ?>
                <?php if (isset($tax->field_comite_display_description[LANGUAGE_NONE][0]['value']) && $tax->field_comite_display_description[LANGUAGE_NONE][0]['value']): ?>
                  <article class="financeGouvernance__item">
                      <div class="financeGouvernance__img">
                          <!-- images need to have square format:- 215 x 215
                          --><img src="<?php print image_style_url('finance_presentation_speech_215_x_215', $item->field_gouvernance_photo[LANGUAGE_NONE][0]['uri']); ?>" alt="<?php print $item->title ?>"/>
                      </div>
                      <div class="financeGouvernance__content">
                          <h3 class="financeGouvernance__title"><?php print $item->title ?></h3>
                          <span class="financeGouvernance__sub">
                              <?php print $item->field_gouvernance_function[LANGUAGE_NONE][0]['value']; ?>
                          </span>
                          <div data-showmoretext="data-showmoretext" class="financeGouvernance__content__info">
                              <p data-showmoretext-content="data-showmoretext-content" class="more-info">
                                  <?php print nl2br($item->field_gouvernance_presentation[LANGUAGE_NONE][0]['value']); ?>
                              </p>
                              <div aria-hidden="true" class="financeGouvernance__cta"><a href="#" data-showmoretext-trigger="Lire moins" class="hidden">Lire plus<span class="icon icon-arrow down"></span></a></div>
                          </div>
                      </div>
                  </article>
                <?php else: ?>
                  <article class="financeGouvernance__item">
                      <div class="financeGouvernance__img">
                          <!-- images need to have square format:- 215 x 215
                          --><img src="<?php print image_style_url('finance_presentation_speech_215_x_215', $item->field_gouvernance_photo[LANGUAGE_NONE][0]['uri']); ?>" alt="<?php print $item->title ?>"/>
                      </div>
                      <div class="financeGouvernance__content">
                          <h3 class="financeGouvernance__title"><?php print $item->title ?></h3>
                          <span class="financeGouvernance__sub">
                              <?php print $item->field_gouvernance_function[LANGUAGE_NONE][0]['value']; ?>
                          </span>
                      </div>
                  </article>
                <?php endif; ?>
              <?php endforeach; ?>
            <?php endif; ?>
        </div>
    </div>
</section>
<!-- [Finance Gouvernance] end-->