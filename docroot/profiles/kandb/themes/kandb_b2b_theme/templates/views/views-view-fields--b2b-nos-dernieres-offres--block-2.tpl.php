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
$style = isset($row->field_field_avant_premiere_image_princ[0]['rendered']['#image_style']) ? $row->field_field_avant_premiere_image_princ[0]['rendered']['#image_style'] : '';
$ville_name = isset($row->field_field_avant_premiere_ville[0]['rendered']['#markup']) ? $row->field_field_avant_premiere_ville[0]['rendered']['#markup'] : '';
$departement_tax = isset($row->field_field_avant_premiere_department[0]['raw']['taxonomy_term']) ? $row->field_field_avant_premiere_department[0]['raw']['taxonomy_term'] : '';
$departement_code = isset($departement_tax->field_numero_departement[LANGUAGE_NONE][0]['value']) ? $departement_tax->field_numero_departement[LANGUAGE_NONE][0]['value'] : '';
?>

<div class="slick-slider__item">
    <!-- [squaredImageItem] start-->
    <article data-selection-item="data-selection-item" class="squaredImageItem false">
        <div class="squaredImageItem__img">
            <a href="<?php print url('node/' . $row->nid); ?>" title="<?php print isset($row->node_title) ? $row->node_title : ''; ?>" title="<?php print isset($row->node_title) ? $row->node_title : ''; ?>">
                <img src="<?php print image_style_url($style, $row->field_field_avant_premiere_image_princ[0]['raw']['uri']); ?>" alt="<?php print image_style_url($style, $row->field_field_avant_premiere_image_princ[0]['raw']['alt']); ?>"/>
            </a>
            <?php if ($promotion = get_nids_promotions_by_avant($row->nid)): ?>
              <ul class="squaredImageItem__img__tags">
                  <?php
                  foreach ($promotion as $value) :
                    if (isset($value->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']) && $value->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']):
                      ?>
                      <li>
                          <button data-reveal-trigger="dernieres-<?php print $value->vid; ?>" class="tag tag--important">
                              <?php print $value->title; ?>
                          </button>
                          <!-- [popin] start-->
                          <div data-reveal="dernieres-<?php print $value->vid; ?>" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                              <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                  <p class="heading heading--bordered heading--small"><strong class="heading__title"><?php print $value->title; ?></strong></p>
                                  <p><?php print $value->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']; ?></p>
                              </div>
                          </div>
                          <!-- [popin] end-->
                      </li>
                    <?php else : ?>
                      <li>
                          <div class="tag tag--important"><?php print $value->title; ?></div>
                      </li>
                    <?php endif; ?>
                    <?php
                  endforeach;
                  ?>
              </ul>
            <?php endif; ?>
        </div>
        <div class="squaredImageItem__infos">
            <div class="squaredImageItem__details"><a href="<?php print url('node/' . $row->nid); ?>" title="<?php print $row->node_title; ?>" class="heading heading--small">
                    <h3 class="heading__title"><?php print $ville_name . ' / ' . $departement_code; ?></h3>
                    <p class="heading__title heading__title--sub"><?php print $row->node_title; ?></p></a>
            </div>
        </div>
    </article>
    <!-- [squaredImageItem] end-->
</div>
