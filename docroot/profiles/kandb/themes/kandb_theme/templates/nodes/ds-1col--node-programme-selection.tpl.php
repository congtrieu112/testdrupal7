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
  <li data-app-accordion-link="#programme<?php print $id; ?>" role="button" class="<?php if($id == 1) print 'active'; ?> display-status"><span class="show-for-sr">fermer</span></li>
  <li data-cookie="programme" data-cookie-remove="<?php print $node->nid; ?>" data-cookie-callback="removeSelection" role="button" class="display-status display-status--suppr"><span class="show-for-sr">Supprimer le programme de vos sélections</span></li>
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
          <div class="heading heading--small"><span class="heading__title"><?php print $title; ?></span><span class="heading__title heading__title--sub"><?php print $field_programme_loc_ville[0]['taxonomy_term']->name; ?> / <?php print $field_programme_loc_department[0]['taxonomy_term']->field_numero_departement[LANGUAGE_NONE][0]['value']; ?></span>
            <?php if(!empty($promotions) || isset($field_nouveau[LANGUAGE_NONE][0])) : ?>
              <ul class="tags-list">
                <?php if(isset($field_nouveau[LANGUAGE_NONE][0]) && $field_nouveau[LANGUAGE_NONE][0]['value'] == 1) : ?>
                  <li>
                    <div class="tag tag--important">Nouveauté</div>
                  </li>
                <?php endif; ?>
                <?php if(!empty($promotions)) : ?>
                  <?php $current = 0; ?>
                  <?php foreach($promotions as $idp => $promotion): ?>
                    <li>
                      <button data-reveal-trigger="selection-promotion-1" class="tag tag--important"><?php print $promotion->title; ?> <sup><?php print $id; ?><?php print $current; ?></sup></button>
                      <!-- [popin] start-->
                      <div data-reveal="selection-promotion-1" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                        <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                          <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                          <p><?php print $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']; ?></p>
                        </div>
                      </div>
                      <!-- [popin] end-->
                    </li>
                    <?php $current ++; ?>
                  <?php endforeach; ?>
                <?php endif; ?>
              </ul>
            <?php endif; ?>
          </div>
          <div class="text heading--small">
            <p class="heading__title"><?php print $field_programme_flat_available[0]['value']; ?> logements de <?php print $field_programme_room_min[0]['value'] ?> <?php print ($field_programme_room_min[0]['value'] != $field_programme_room_max[0]['value'] ? 'à ' .$field_programme_room_max[0]['value'] . ' ' : ''); ?>pièces</p>
          </div>
        </div>
      </div>
      <ul class="prices">
        <?php if (isset($field_program_low_tva_price_min[0]['value'])) : ?>
          <li><span class="text">À partir de <strong><?php print number_format($field_program_low_tva_price_min[0]['value'], 0, ',', ' '); ?>€</strong></span><span class="tva"><?php print $field_tva[0]['taxonomy_term']->name; ?></span></li>
        <?php endif; ?>
        <li><span class="text">À partir de <strong><?php print number_format($field_programme_price_min[0]['value'], 0, ',', ' '); ?>€</strong></span><span class="tva tva--high">TVA 20%</span></li>
      </ul>
    </div>
  </div>
  <div data-app-accordion-content="data-app-accordion-content">
    <div class="mySelectionsProgramme__large ">
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
          <?php if(!empty($promotions) || isset($field_nouveau[LANGUAGE_NONE][0])) : ?>
            <ul class="tags-list">
              <?php if(isset($field_nouveau[LANGUAGE_NONE][0]) && $field_nouveau[LANGUAGE_NONE][0]['value'] == 1) : ?>
                <li>
                  <div class="tag tag--important"><?php print t('Nouveauté'); ?></div>
                </li>
              <?php endif; ?>
              <?php if(!empty($promotions)) : ?>
                <?php $current = 0; ?>
                <?php foreach($promotions as $idp => $promotion): ?>
                  <li>
                    <button data-reveal-trigger="selection-promotion-1" class="tag tag--important"><?php print $promotion->title; ?> <sup><?php print $id; ?><?php print $current; ?></sup></button>
                    <!-- [popin] start-->
                    <div data-reveal="selection-promotion-1" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                      <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                        <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                        <p><?php print $promotion->field_promotion_mention_legale[LANGUAGE_NONE][0]['value']; ?></p>
                      </div>
                    </div>
                    <!-- [popin] end-->
                  </li>
                  <?php $current ++; ?>
                <?php endforeach; ?>
              <?php endif; ?>
            </ul>
          <?php endif; ?>
        </div>
      </div>
      <div class="squaredImageItem__infos">
        <div class="squaredImageItem__details">
          <div class="heading heading--bordered">
            <h3 class="heading__title"><?php print $title; ?></h3>
            <p class="heading__title heading__title--sub"><?php print $ville_name; ?> <?php if(isset($ville_name) && isset($num_department)) print t('/ ')?> <?php print $num_department; ?></p>
          </div>
          <div class="text heading--small">
            <strong><?php print t('Livraison'); ?></strong>
            <?php print t('à partir du'); ?>
            <?php if ($trimstre) print $trimstre; ?>
            <?php if ($annee) print $annee; ?>
            <br/>
            <?php if ($flat_available) print $flat_available; ?>
            <?php if ($de_a_pieces) print ', ' . $de_a_pieces; ?>
          </div>
          <?php if ($de_a_price_tva || $de_a_price) : ?>
          <ul class="prices">              
              
              <?php if(empty($tva) && $affichage_double_grille == 0): ?>
              <li>
                  <span class="text">
                      <?php if ($de_a_price) print $de_a_price; ?>
                  </span>
              </li>
              <?php endif; ?>
              
              <?php if($tva && $affichage_double_grille == 0): ?>
              <li>
                  <span class="text">
                      <?php if ($de_a_price) print $de_a_price; ?>
                  </span>
              </li>
              <li>
                  <span class="tva tva--high">TVA 20%</span>                  
              </li>
              <?php endif; ?>
              
              <?php if($tva && $affichage_double_grille == 1): ?>
              <li>
                  <span class="text"><?php if ($de_a_price) print $de_a_price; ?></span>
                    <?php if ($tva) : ?>
                      <span class="tva tva--high">TVA 20%</span>
                    <?php endif; ?>
              </li>
              <li>
                  <span class="text">
                      <?php if ($de_a_price_tva) print $de_a_price_tva; ?>
                  </span>
                  <?php if ($tva) : ?>
                    <span class="tva"><?php print $tva; ?></span>
                  <?php endif; ?>
              </li>
              <?php endif; ?>
              
          </ul>
          <?php endif; ?>
        </div>          
        <ul class="squaredImageItem__actions">
          <li><?php print l('Découvrir le programme', 'node/' . $node->nid, array('attributes' => array('class' => array('btn-rounded', 'btn-secondary', 'btn-big-mobile')))); ?></li>
          <?php if(!empty($field_plaquette_commerciale)) : ?>
            <li><a href="<?php print file_create_url($field_plaquette_commerciale['und'][0]['uri']); ?>" class="btn-rounded btn-primary btn-big-mobile">Télécharger la plaquette</a></li>
          <?php endif; ?>
          <li>
            <button data-dropdown="sharing-<?php print $id; ?>" aria-controls="sharing-<?php print $id; ?>" aria-expanded="false" class="btn-primary btn-rounded hide-for-small-only"><span><?php print t('Partager'); ?><span class="icon icon-expand"></span></span></button>
            <div class="sharing f-dropdown" id="sharing-<?php print $id; ?>" data-dropdown-content="data-dropdown-content" role="menu" aria-hidden="true" tabindex="-1">
              <ul class="sharing__items">
                <li class="sharing__items__item"><a href="mailto:" title="partage par email" class="icon icon-email"></a></li>
              </ul>
            </div>
          </li>
        </ul>
      </div>
      <?php if(!empty($field_nom_conseiller)): ?>

        <ul class="bg-lightGrey contact">
          <li class="contact__item">
            <!-- 1 format needed:- 60 x 60 (HEAVY compression!!!)-->
            <img alt="<?php print t('Contact Programme'); ?> " src="<?php print $field_photo_conseiller[LANGUAGE_NONE][0]['contact_selection']; ?>" class="contact__item__img hide-for-small-only">
            <p class="text"><?php print t('Votre conseillère'); ?> <strong><?php print $field_nom_conseiller[LANGUAGE_NONE][0]['value']; ?></strong></p><a href="tel://<?php print $field_espace_vente_tel[LANGUAGE_NONE][0]['value']; ?>" class="btn-phone"><?php print $field_espace_vente_tel[LANGUAGE_NONE][0]['value']; ?></a>
          </li>

          <?php
            if (function_exists('kandb_contact_buttons')) {
              $url = kandb_contact_buttons(TRUE);
              $i = 0;
              foreach($url as $title_url => $link) {
                ?>
                  <li class="contact__item"><a href="<?php print $link; ?>" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-icon btn-white"><span class="button__content"><span class="icon icon-<?php print ($i ? 'email' : 'tel'); ?>"></span><?php print $title_url; ?></span></a></li>
                <?php
                $i++;
              }
            }
          ?>
        </ul>
      <?php endif; ?>
    </div>
  </div>
</article>
