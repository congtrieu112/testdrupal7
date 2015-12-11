<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<ul class="mySelectionsProgrammes__actions">
  <li data-app-accordion-link="#programme<?php print $id; ?>" role="button" class="active display-status"><span class="show-for-sr">fermer</span></li>
  <li data-cookie="offres" data-cookie-remove="1" data-cookie-callback="removeSelection" role="button" class="display-status display-status--suppr"><span class="show-for-sr">Supprimer le programme de vos sélections</span></li>
</ul>
<article id="programme<?php print $id; ?>" class="mySelectionsProgramme">
  <div data-app-accordion-sample="data-app-accordion-sample">
    <div class="mySelectionsProgramme__small">
      <div class="media">
        <?php if(!empty($programme_selection_very_small)) : ?>
          <div class="media__img">
            <!-- 1 format needed:- 160 x 160 (HEAVY compression!!!) -->
            <img alt="Photo programme" src="<?php print $programme_selection_very_small; ?>">
          </div>
        <?php endif; ?>
        <div class="media__content">
          <?php // TODO : promotion && condition sur cette zone soit caractéristique soit nouveauté ?>
          <div class="heading heading--small"><span class="heading__title"><?php print $title; ?></span><span class="heading__title heading__title--sub"><?php print $field_programme_loc_ville[0]['taxonomy_term']->name; ?> / <?php print $field_programme_loc_department[0]['taxonomy_term']->field_numero_departement['und'][0]['value']; ?></span>
            <ul class="tags-list">
              <?php if(isset($field_nouveau['und'][0]) && $field_nouveau['und'][0]['value'] == 1) : ?>
                <li>
                  <div class="tag tag--important">Nouveauté</div>
                </li>
              <?php endif; ?>
              <li>
                <button data-reveal-trigger="selection-promotion-1" class="tag tag--important"><?php // TODO : print $field_caracteristiques[0]; ?> <sup>1</sup></button>
                <!-- [popin] start-->
                <div data-reveal="selection-promotion-1" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                  <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                    <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                  </div>
                </div>
                <!-- [popin] end-->
              </li>
            </ul>
          </div>
          <div class="text heading--small">
            <p class="heading__title">17 appartements de 1 à 3 pièces</p>
            <p class="hide-for-small-only heading__title">Parking disponible en addition</p>
          </div>
        </div>
      </div>
      <ul class="prices">
        <li><span class="text">À partir de <strong>54&nbsp;000€</strong></span><span class="tva">TVA 5,5%</span></li>
        <li><span class="text">À partir de <strong>1&nbsp;684&nbsp;000€</strong></span><span class="tva tva--high">TVA 20%</span></li>
      </ul>
    </div>
  </div>
  <div data-app-accordion-content="data-app-accordion-content">
    <div class="mySelectionsProgramme__large">
      <div class="squaredImageItem__img">
        <!-- images need to have 2 formats see data-exchange attribute:
        - small: 560 x 310 (heavy compression)
        - medium: 300 x 300
        -->
        <!-- [Responsive img] start-->
        <?php if(!empty($programme_selection_very_small)) : ?>
          <img alt="Photo du programme" data-interchange="[<?php print $programme_selection_small; ?>, (small)], [<?php print $programme_selection_medium; ?>, (medium)]">
          <noscript><img src="<?php print $programme_selection_medium; ?>" alt="Photo du programme"></noscript>
        <?php endif; ?>
        <!-- [Responsive img] end-->
        <div class="squaredImageItem__img__tags">
          <ul class="tags-list">
            <li>
              <button data-reveal-trigger="selection-promotion-1" class="tag tag--important">Nouveauté<sup>1</sup></button>
              <!-- [popin] start-->
              <div data-reveal="selection-promotion-1" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                  <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                  <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                  <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                </div>
              </div>
              <!-- [popin] end-->
            </li>
            <li>
              <div class="tag tag--important">plus que deux T3 disponibles</div>
            </li>
          </ul>
        </div>
      </div>
      <div class="squaredImageItem__infos">
        <div class="squaredImageItem__details">
          <div class="heading heading--bordered">
            <h3 class="heading__title">Emergence</h3>
            <p class="heading__title heading__title--sub">Paris / 75</p>
          </div>
          <div class="text heading--small">
            <p class="heading__title">17 appartements de 1 à 3 pièces</p>
            <p class="heading__title">Parking disponible en addition</p>
          </div>
          <ul class="prices">
            <li><span class="text">À partir de <strong>54&nbsp;000€</strong></span><span class="tva">TVA 5,5%</span></li>
            <li><span class="text">À partir de <strong>1&nbsp;684&nbsp;000€</strong></span><span class="tva tva--high">TVA 20%</span></li>
          </ul>
        </div>
        <ul class="squaredImageItem__actions">
          <li><a href="#" class="btn-rounded btn-secondary btn-big-mobile">Découvrir le programme</a></li>
          <li><a href="#" class="btn-rounded btn-primary btn-big-mobile">Télécharger la plaquette</a></li>
          <li>
            <button data-dropdown="sharing-0" aria-controls="sharing-0" aria-expanded="false" class="btn-primary btn-rounded hide-for-small-only">Partager<span class="icon icon-expand"></span></button>
            <div class="sharing f-dropdown" id="sharing-0" data-dropdown-content="data-dropdown-content" role="menu" aria-hidden="true" tabindex="-1">
              <ul class="sharing__items">
                <li class="sharing__items__item"><a href="#" title="partage par email" class="icon icon-email"></a></li>
                <li class="sharing__items__item"><a href="#" title="partage sur Facebook" class="icon icon-facebook"></a></li>
                <li class="sharing__items__item"><a href="#" title="partage sur Twitter" class="icon icon-twitter"></a></li>
                <li class="sharing__items__item"><a href="#" title="partage sur Whatsapp" class="icon icon-phone-call"></a></li>
              </ul>
            </div>
          </li>
        </ul>
      </div>
      <ul class="bg-lightGrey contact">
        <li class="contact__item">
          <!-- 1 format needed:- 60 x 60 (HEAVY compression!!!)
          --><img alt="Photo programme" src="test_assets/mySelectionContactUs.jpg" class="contact__item__img hide-for-small-only">
          <p class="text">Votre conseillère <strong>Amélie Martin</strong></p><a href="tel://0134544400" class="btn-phone">01 34 54 44 00</a>
        </li>
        <li class="contact__item"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-icon btn-white"><span class="button__content"><span class="icon icon-tel"></span>Etre rappelé</span></a></li>
        <li class="contact__item"><a href="partials/formRendezVous.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-icon btn-white"><span class="button__content"><span class="icon icon-email"></span>Prendre rendez-vous</span></a></li>
      </ul>
    </div>
  </div>
</article>