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
module_load_include('module', 'kandb_admin_content', 'kandb_admin_content');
$style = $row->field_field_avant_premiere_image_princ[0]['rendered']['#image_style'];
$ville_name = isset($row->field_field_avant_premiere_ville[0]['rendered']['#title']) ? $row->field_field_avant_premiere_ville[0]['rendered']['#title'] : '';
$departement_tax = isset($row->field_field_avant_premiere_department[0]['rendered']['#options']['entity']) ? $row->field_field_avant_premiere_department[0]['rendered']['#options']['entity'] : '';
$departement_code = isset($departement_tax->field_numero_departement [LANGUAGE_NONE][0]['value']) ? $departement_tax->field_numero_departement [LANGUAGE_NONE][0]['value'] : '';
$status_promotion = $row->field_promotion_avant_premiere_node_status;
$available = false;
// Check date rage available promotion.
if ($row->field_promotion_avant_premiere_node_title):
  $current_date = time();
  $start_date = strtotime($row->field_field_promotion_start[0]['raw']['value']);
  $end_date = strtotime($row->field_field_promotion_stop[0]['raw']['value']);
  if ($current_date > $start_date && $current_date < $end_date):
    $available = true;
  endif;
endif;
$node = node_load($row->nid);
$date_range_string = '';
if (module_exists('kandb_validate')) {
  $start_date = $node->field_avant_premiere_date_debut[LANGUAGE_NONE][0]['value'];
  $end_date = $node->field_avant_premiere_date_fin[LANGUAGE_NONE][0]['value'];
  $date_range = kandb_validate_get_dates_from_range($start_date, $end_date);
  $month_start = date('M' ,strtotime($start_date));
  $date_range_string = implode(' & ', $date_range) . ' ' . translatorMonth('fr',$month_start);
}

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
    <!-- [squaredImageItem] start-->
    <article class="squaredImageItem false">
        <aside>
            <p class="squaredImageItem__date"><?php print $date_range_string; ?></p>
        </aside>
        <div class="squaredImageItem__img"><a href="<?php print url('node/' . $row->nid); ?>" title="<?php print $row->node_title; ?>"><img src="<?php print image_style_url($style, $row->field_field_avant_premiere_image_princ[0]['raw']['uri']); ?>" alt="<?php print $row->field_field_avant_premiere_image_princ[0]['raw']['alt']; ?>"/></a>
            <ul class="squaredImageItem__img__tags">

                <?php if ($row->field_promotion_avant_premiere_node_title && $available && $status_promotion && $_SESSION['avant_promotion'] < 3): ?>
                  <li>
                      <?php if($row->field_field_promotion_mention_legale[0]['rendered']['#markup']) : ?>
                      <button data-reveal-trigger="avant_premiere_<?php print $row->field_promotion_avant_premiere_node_nid; ?>" class="tag tag--important"><?php print $row->field_promotion_avant_premiere_node_title; ?></button>

                        <!-- [popin] start-->
                        <div data-reveal="avant_premiere_<?php print $row->field_promotion_avant_premiere_node_nid; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                            <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $row->field_promotion_avant_premiere_node_title; ?></strong></p>
                                <p><?php print $row->field_field_promotion_mention_legale[0]['rendered']['#markup']; ?></p>
                            </div>
                        </div>
                        <!-- [popin] end-->
                        <?php else :  ?>
                        <div class="tag tag--important"><?php print $row->field_promotion_avant_premiere_node_title; ?></div>
                      <?php endif; ?>
                  </li>

                  <?php
                  if ($promotion) :
                    foreach ($promotion as $value) :
                      if (isset($value->field_field_promotion_mention_legale[0]['rendered']['#markup']) && $value->field_field_promotion_mention_legale[0]['rendered']['#markup']) :
                      ?>
                      <li>
                          <button data-reveal-trigger="avant_premiere_<?php print $value->field_promotion_avant_premiere_node_nid; ?>" class="tag tag--important"><?php print $value->field_promotion_avant_premiere_node_title; ?></button>
                          <!-- [popin] start-->
                          <div data-reveal="avant_premiere_<?php print $value->field_promotion_avant_premiere_node_nid; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                              <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                  <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $value->field_promotion_avant_premiere_node_title; ?></strong></p>
                                  <p><?php print $value->field_field_promotion_mention_legale[0]['rendered']['#markup']; ?></p>
                              </div>
                          </div>
                          <!-- [popin] end-->
                      </li>
                      <?php else : ?>
                            <li>
                                <div class="tag tag--important"><?php print $value->field_promotion_avant_premiere_node_title; ?></div>
                            </li>
                      <?php endif; ?>
                      <?php
                    endforeach;
                  endif;
                  ?>
                  <?php
                  $_SESSION['avant_promotion'] += 1;
                  ?>
                <?php endif; ?>
            </ul>
        </div>
        <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
            <div class="squaredImageItem__details">
                <div class="heading-favorite">
                    <a href="<?php print url('node/' . $row->nid); ?>" title="<?php print $row->node_title; ?>" class="heading heading--small">
                        <h3 class="heading__title"><?php print $ville_name . ' / ' . $departement_code; ?></h3>
                        <p class="heading__title heading__title--sub"><?php print $row->node_title; ?></p>
                    </a>
                    <a href="" title="<?php print t('Add item to favorites'); ?>" data-cookie="offres" data-cookie-add="<?php print $row->nid; ?>" class="btn-icon--only">
                        <span class="icon icon-love"></span>
                    </a>
                </div>
            </div>
        </div>
    </article>
    <!-- [squaredImageItem] end-->
</div>


