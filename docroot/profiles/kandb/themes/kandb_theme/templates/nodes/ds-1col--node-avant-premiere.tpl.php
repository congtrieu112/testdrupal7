<?php
$ville = isset($node->field_avant_premiere_ville[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_avant_premiere_ville[LANGUAGE_NONE][0]['taxonomy_term']->name : '';
$arrondissement = isset($node->field_avant_premiere_arrondissem[LANGUAGE_NONE][0]['value']) ? $node->field_avant_premiere_arrondissem[LANGUAGE_NONE][0]['value'] : '';
// Information for header programme page
$title = isset($node->title) ? $node->title : '';
$image_principale = isset($node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['uri']) ? $node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['uri'] : '';
$image_principale_small = '';
$image_principale_large = '';
$image_principale_medium = '';
$image_principale_alt = isset($node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['alt']) ? $node->field_avant_premiere_image_princ[LANGUAGE_NONE][0]['alt'] : '';

if ($image_principale) {
  $image_principale_small = image_style_url('program_image_principale_small', $image_principale);
  $image_principale_medium = image_style_url('program_image_principale_medium', $image_principale);
  $image_principale_large = image_style_url('program_image_principale_large', $image_principale);
}

$en_quelques_mots = isset($node->field_avant_premiere_en_quelques[LANGUAGE_NONE][0]['value']) ? $node->field_avant_premiere_en_quelques[LANGUAGE_NONE][0]['value'] : '';
$description = isset($node->field_avant_premiere_description[LANGUAGE_NONE][0]['value']) ? $node->field_avant_premiere_description[LANGUAGE_NONE][0]['value'] : '';

$ouverture = isset($node->field_avant_premiere_grande_ouve[LANGUAGE_NONE][0]['value']) ? $node->field_avant_premiere_grande_ouve[LANGUAGE_NONE][0]['value'] : '';

$promotions = get_nids_promotions_by_avant($node->nid);
?>

<!-- [programHeader] start-->
<header class="programHeader">
    <!-- mobile heading-->
    <div class="wrapper show-for-small-only">
        <h1 class="heading heading--bordered">
            <div class="heading__title"><?php print $ville . ' ' . $arrondissement; ?></div>
            <div class="heading__title heading__title--sub"><?php print $title; ?></div>
        </h1>
        <?php
        if ($ouverture):
          $date_range_string = '';
          $start_date = $node->field_avant_premiere_date_debut[LANGUAGE_NONE][0]['value'];
          $end_date = $node->field_avant_premiere_date_fin[LANGUAGE_NONE][0]['value'];
          $date_range = kandb_validate_get_dates_from_range($start_date, $end_date);
          $date_range_string = implode(' & ', $date_range) . ' ' . format_date(strtotime($start_date), 'custom', 'F');
          ?>
          <div class="tag tag--important"><?php print t('Grande ouverture'); ?></div>
          <p class="toolbox__intro"><?php print $date_range_string; ?></p>
        <?php else: ?>
          <div class="tag tag--important"><?php print t('Avant-première'); ?></div>
        <?php endif; ?>
          <?php if ($promotions) : ?>
              <ul>
                  <?php
                  foreach ($promotions as $promotion) :
                      $triger_promotion = 'promotion-' . $promotion->nid;
                      if (isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) && $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']):
                            ?>
                            <li>
                                <button data-reveal-trigger="dernieres-<?php print $promotion->vid; ?>" class="tag tag--important">
                                    <?php print $promotion->title; ?>
                                </button>
                                <!-- [popin] start-->
                                <div data-reveal="dernieres-<?php print $value->vid; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                    <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                        <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $promotion->title; ?></strong></p>
                                        <p><?php print $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']; ?></p>
                                    </div>
                                </div>
                                <!-- [popin] end-->
                            </li>
                        <?php else : ?>
                            <li>
                                <div class="tag tag--important"><?php print $promotion->title; ?></div>
                            </li>
                        <?php endif; ?>
                      <!-- [popin] end-->
                  <?php endforeach; ?>
              </ul>
          <?php endif; ?>
    </div>
    <div class="programHeader__figure">
        <!-- images need to have 2 formats see data-exchange attribute:
        - small: 640 x 316 (heavy compression)
        - medium: 1024 x 506
        - large: 1380 x 670
        -->
        <!-- [Responsive img] start--><img alt="<?php print $image_principale_alt; ?>" data-interchange="[<?php print $image_principale_small; ?>, (small)], [<?php print $image_principale_medium; ?>, (medium)], [<?php print $image_principale_large; ?>, (large)]"/>
        <noscript><img src="<?php print $image_principale_medium; ?>" alt="<?php print $image_principale_alt; ?>"/></noscript>
        <!-- [Responsive img] end-->
    </div>
    <div class="wrapper">
        <div class="programHeader__content">
            <div class="toolbox">
                <!-- tablet+desktop heading-->
                <div class="show-for-medium-up">
                    <h1 class="heading heading--bordered">
                        <div class="heading__title"><?php print $ville . ' ' . $arrondissement; ?></div>
                        <div class="heading__title heading__title--sub"><?php print $title; ?></div>
                    </h1>
                    <ul class="tags-list">
                        <?php
                        if ($ouverture):
                            $date_range_string = '';
                            if (module_exists('kandb_validate')) {
                                $start_date = $node->field_avant_premiere_date_debut[LANGUAGE_NONE][0]['value'];
                                $end_date = $node->field_avant_premiere_date_fin[LANGUAGE_NONE][0]['value'];
                                $date_range = kandb_validate_get_dates_from_range($start_date, $end_date);
                                $date_range_string = implode(' & ', $date_range) . ' ' . format_date(strtotime($start_date), 'custom', 'F');
                            }
                            ?>
                            <li>
                                <div class="tag tag--important"><?php print t('Grande ouverture'); ?></div>
                                <p class=""><?php print $date_range_string; ?></p>
                            </li>
                        <?php else: ?>
                            <li>
                                <div class="tag tag--important"><?php print t('Avant-première'); ?></div>
                            </li>
                        <?php endif; ?>
                        <?php
                        if ($promotions) :
                            foreach ($promotions as $promotion) :
                                $triger_promotion = 'promotion-' . $promotion->nid;
                                if (isset($promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) && $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']):
                                    ?>
                                    <li>
                                        <button data-reveal-trigger="dernieres-<?php print $promotion->vid; ?>" class="tag tag--important">
                                            <?php print $promotion->title; ?>
                                        </button>
                                        <!-- [popin] start-->
                                        <div data-reveal="dernieres-<?php print $value->vid; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                            <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                                <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $promotion->title; ?></strong></p>
                                                <p><?php print $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']; ?></p>
                                            </div>
                                        </div>
                                        <!-- [popin] end-->
                                    </li>
                                <?php else : ?>
                                    <li>
                                        <div class="tag tag--important"><?php print $promotion->title; ?></div>
                                    </li>
                                <?php endif; ?>
                            <?php endforeach; ?>
                        <?php endif; ?>
                    </ul>
                </div>
            </div>
            <div class="programHeader__content__details">
                <?php if ($en_quelques_mots): ?>
                  <p class="intro"><em><?php print t('En quelques mots'); ?>&nbsp;</em> <?php print $en_quelques_mots; ?></p>
                <?php endif; ?>
            </div>
        </div>
        <?php if ($description): ?>
          <div>
              <p><?php print nl2br($description); ?><p>
          </div>
        <?php endif; ?>
        <div class="heading heading--bordered heading--small">
            <div class="heading__title">
                <?php print variable_get('avant_premiere_title', ''); ?>
            </div>
        </div>
        <p>
            <?php print variable_get('avant_premiere_textarea', ''); ?>
        </p>
        <?php
        $webform = webform_features_machine_name_load('avant_contactez_nous');
        if ($webform->nid) {
          $submission = array();
          $enabled = TRUE;
          $preview = FALSE;
          $node = node_load($webform->nid);
          $node_status = isset($node->status) ? $node->status : 0;
          if ($node_status) {
            print '<div>';
            $form_contact = drupal_get_form('webform_client_form_' . $webform->nid, $node, $submission, $enabled, $preview);
            print render($form_contact);
            print '</div>';
            $class_ajax = $form_contact['webform_ajax_wrapper_id']['#value'];
            drupal_add_css('div#' . $class_ajax . ' .messages.status{display:none;}', 'inline');
          }
        }
        ?>
        <p>
            <?php print variable_get('avant_premiere_textarea_bottom', ''); ?>
        </p>
    </div>
</header>
<!-- [programHeader] end-->