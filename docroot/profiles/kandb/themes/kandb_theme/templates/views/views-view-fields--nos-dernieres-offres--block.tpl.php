<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
$style = isset($row->field_field_image_principale[0]['rendered']['#image_style']) ? $row->field_field_image_principale[0]['rendered']['#image_style'] : '';
$ville_name = isset($row->field_field_programme_loc_ville[0]['rendered']['#title']) ? $row->field_field_programme_loc_ville[0]['rendered']['#title'] : '';
$departement_tax = isset($row->field_field_programme_loc_department[0]['rendered']['#options']['entity']) ? $row->field_field_programme_loc_department[0]['rendered']['#options']['entity'] : '';
$departement_code = isset($departement_tax->field_numero_departement [LANGUAGE_NONE][0]['value']) ? $departement_tax->field_numero_departement [LANGUAGE_NONE][0]['value'] : '';
$status_promotion = $row->field_promotion_programme_node_status;
$available = false;
// Check date rage available promotion.
if ($row->field_promotion_programme_node_title):
  $current_date = time();
  $start_date = strtotime($row->field_field_promotion_start[0]['raw']['value']);
  $end_date = strtotime($row->field_field_promotion_stop[0]['raw']['value']);
  if ($current_date > $start_date && $current_date < $end_date):
    $available = true;
  endif;
endif;
$promotion = array();
if (isset($view->promotion_duplicate) && count($view->promotion_duplicate)) {
  foreach ($view->promotion_duplicate as $key => $promotion_duplicate) {
    if ($key == $row->nid) {
      foreach ($promotion_duplicate as $promotion_items) {
        $promotion[] = $promotion_items['object'];
      }
    }
  }
}
?>
<div class="slick-slider__item">
    <article class="squaredImageItem false">
        <?php if (isset($row->field_field_image_principale[0]['raw']['uri'])) : ?>
        <div class="squaredImageItem__img">
            <a href="<?php print url('node/' . $row->nid); ?>" title="<?php print isset($row->node_title) ? $row->node_title : ''; ?>" class="squaredImageItem__img">
                <img src="<?php print image_style_url($style, $row->field_field_image_principale[0]['raw']['uri']); ?>" alt="<?php print $row->field_field_image_principale[0]['raw']['alt'] ?>"/>            
            </a>
        </div>
        <?php endif; ?>
        <ul class="squaredImageItem__img__tags">
            <?php if ($row->field_promotion_programme_node_title && $available && $status_promotion && $_SESSION['promotion'] < 3): ?>
              <li>
                  <button class="tag tag--important" data-reveal-trigger="dernieres-<?php print $row->field_promotion_programme_node_nid; ?>">
                      <?php print $row->field_promotion_programme_node_title; ?>
                  </button>

                  <!-- [popin] start-->
                  <div data-reveal="dernieres-<?php print $row->field_promotion_programme_node_nid; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                      <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                          <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $row->field_promotion_programme_node_title; ?></strong></p>
                          <p><?php print $row->field_field_promotion_mention_legale[0]['rendered']['#markup']; ?></p>
                      </div>
                  </div>
                  <!-- [popin] end-->

              </li>
              <?php
              if ($promotion) :
                foreach ($promotion as $value) :
                  ?>
                  <li>
                      <button data-reveal-trigger="dernieres-<?php print $value->field_promotion_programme_node_nid; ?>" class="tag tag--important">
                          <?php print $value->field_promotion_programme_node_title; ?>
                      </button>
                      <!-- [popin] start-->
                      <div data-reveal="dernieres-<?php print $value->field_promotion_programme_node_nid; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                          <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                              <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $value->field_promotion_programme_node_title; ?></strong></p>
                              <p><?php print $value->field_field_promotion_mention_legale[0]['rendered']['#markup']; ?></p>
                          </div>
                      </div>
                      <!-- [popin] end-->
                  </li>
                  <?php
                endforeach;
              endif;
              ?>  
              <?php
              $_SESSION['promotion'] += 1;
              ?>
            <?php endif; ?>
            <!--                <li>
                                <div class="tag">TVA 7%<sup>(2)</sup></div>
                            </li>
                            <li>
                                <div class="tag">Livraison immédiate<sup>(1)</sup></div>
                            </li>-->
        </ul>
        <div class="squaredImageItem__infos">
            <div class="squaredImageItem__details">
                <a href="<?php print url('node/' . $row->nid); ?>" title="<?php print t('Go to programme page'); ?>" class="heading heading--small">
                    <p class="heading__title">
                        <?php print $ville_name . ' / ' . $departement_code; ?>
                    </p>
                    <p class="heading__title heading__title--sub"><?php print $row->node_title; ?></p>
                </a>
            </div>
        </div>
    </article>
</div>
