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
$node = node_load($row->nid);
$region = isset ($node->field_habitat_region[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($node->field_habitat_region[LANGUAGE_NONE][0]['tid'])->name : "";
$postal_code = isset($node->field_habitat_code_postal[LANGUAGE_NONE][0]['value']) ? $node->field_habitat_code_postal[LANGUAGE_NONE][0]['value'] : "";
$title = $postal_code ." ". $region ;
$style = isset($row->field_field_habitat_image[0]['rendered']['#image_style']) ? $row->field_field_habitat_image[0]['rendered']['#image_style'] : '';
$ville_name = isset($row->field_field_habitat_ville[0]['rendered']['#title']) ? $row->field_field_habitat_ville[0]['rendered']['#title'] : '';
$departement_tax = isset($row->field_field_habitat_departement[0]['rendered']['#options']['entity']) ? $row->field_field_habitat_departement[0]['rendered']['#options']['entity'] : '';
$departement_code = isset($departement_tax->field_numero_departement [LANGUAGE_NONE][0]['value']) ? $departement_tax->field_numero_departement [LANGUAGE_NONE][0]['value'] : '';
?>
<div class="slick-slider__item">
    <!-- [squaredImageItem] start-->
    <article data-selection-item="data-selection-item" class="squaredImageItem false">
        <div class="squaredImageItem__img">
            <img src="<?php print image_style_url($style, $row->field_field_habitat_image[0]['raw']['uri']); ?>" alt="<?php print $row->field_field_habitat_image[0]['raw']['alt'] ?>"/>
        </div>
        <div class="squaredImageItem__infos">
            <div class="squaredImageItem__details">
                <h3 class="heading__title"><?php print $ville_name . ' / ' . $departement_code; ?></h3>
                <p class="heading__title heading__title--sub"><?php print $title ; ?></p>
            </div>
        </div>
    </article>
    <!-- [squaredImageItem] end-->
</div>
