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
$header_image_small = '';
if (isset($content["field_block_b2b_header_image"]["#items"][0]['uri'])) {
  $header_image = image_style_url('hp_search_block', $content["field_block_b2b_header_image"]["#items"][0]['uri']);
}
if (isset($content["field_block_b2b_header_img_small"]["#items"][0]['uri'])) {
  $header_image_small = image_style_url('homepageb2b_backgound_small', $content["field_block_b2b_header_img_small"]["#items"][0]['uri']);
}
?>

<div data-interchange="[<?php print $header_image_small ?>, (small)], [<?php print $header_image ?>, (medium)]" class="homepageB2B__heading">
    <div class="wrapper">
        <div class="heading heading--bordered heading--white heading--small">
            <h1 class="heading__title"><?php print $title ?></h1>
            <div class="heading__title heading__title--sub"><?php print (isset($content['field_block_b2b_header_stitre']['#items'][0]['value'])) ? $content['field_block_b2b_header_stitre']['#items'][0]['value'] : ''  ?></div>
            <?php if (isset($content['field_block_b2b_header_cta'][0]['#markup'])): ?>
              <button data-reveal-id="videoIntro" class="btn-primary btn-rounded btn-icon"><span class="button__content"><span class="icon icon-play"></span><?php print $content['field_block_b2b_header_cta'][0]['#markup']; ?></span></button>
              <!-- [popin] start-->
              <div id="videoIntro" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                  <div class="reveal-modal__wrapper"><span aria-label="Fermer" role="button" class="close-reveal-modal icon icon-close"></span>
                      <div class="flex-video youtube">
                          <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/<?php print $content['field_block_b2b_header_video']['#items'][0]['video_id']; ?>" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true"></iframe>
                      </div>
                  </div>
              </div>
              <!-- [popin] end-->
            <?php endif; ?>
        </div>
    </div>
</div>