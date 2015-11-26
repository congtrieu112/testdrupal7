<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

global $base_url;

$header_image = '';
if(isset($content["field_block_header_image"]["#items"][0]['uri'])){
  $url = file_create_url($content["field_block_header_image"]["#items"][0]['uri']);
  $url = parse_url($url);
  $header_image = $base_url . $url['path'];
}
?>
<!-- [header Advice] start-->
<!-- images need to have 2 different formats:
- small: 640 x 400 (High compression)
- large: 1380 x 400
-->
<section data-interchange="[<?php print $header_image ?>, (small)], [<?php print $header_image ?>, (medium)]" 
         class="narrow-header <?php print $classes; ?>" <?php print $attributes; ?>>
    <div class="wrapper" <?php print $content_attributes; ?>>
        <div class="heading heading--bordered heading--white">
            <div class="heading__title"><?php print $title ?></div>
            <div class="heading__title heading__title--sub"><?php print (isset($content["field_block_header_stitre"]["#items"][0]["value"])) ? $content["field_block_header_stitre"]["#items"][0]["value"] : '' ?></div>
        </div>
    </div>
</section>
<!-- [header Advice] end-->