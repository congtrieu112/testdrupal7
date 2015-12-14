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
global $base_url;
$url = file_create_url($node->field_article_image[LANGUAGE_NONE][0]['uri']);
$url = parse_url($url);
$path_image = $base_url . $url['path'];
?>
<div class="top-actions">
        <div class="wrapper">
            <?php if($_SERVER['HTTP_REFERER']) : ?>
               <a href="<?php print $_SERVER['HTTP_REFERER']; ?>" class="btn-white"><?php print t('Retour'); ?><span class="icon icon-arrow left"></span></a>
            <?php endif; ?>
        <div class="top-actions__ctas">
              <label><?php print t('Ajouter aux favoris'); ?></label>
              <button data-cookie="articles" data-cookie-add="<?php print $node->nid; ?>" class="btn-icon--only"><span class="icon icon-love"></span></button>
              <label><?php print t('Partager');  ?></label><span class="icon icon-facebook"></span><span class="icon icon-twitter"></span>
        </div>
    </div>
</div>
<div class="wrapper">
    <hr class="hr">
</div>
<!-- [editorial Content Article] start-->
<article id="node-<?php print $node->nid; ?>" class="section-padding editorialContentArticle <?php print $classes; ?> <?php print $attributes; ?>">
    <div class="wrapper">
        <header class="heading heading--bordered heading--large">
            <h1 class="heading__title"><?php print $node->title ?></h1>
        </header>
        <p class="editorialContentArticle__content__hightlight">
            <?php print isset($node->field_article_resume[LANGUAGE_NONE][0]["value"]) ? $node->field_article_resume[LANGUAGE_NONE][0]["value"] : ''  ?>
        </p>
        <div class="row">
            <figure class="editorialContentArticle__figure">
                <img src="<?php print $path_image; ?>" alt="<?php print $node->title ?>"/>
            </figure>
            <div class="editorialContentArticle__content">
                <?php print (isset($node->field_article_content[LANGUAGE_NONE][0]["value"])) ? $node->field_article_content[LANGUAGE_NONE][0]["value"] : ''; ?>
            </div>
        </div>
    </div>
</article>
<!-- [editorial Content Article] end-->

<div class="wrapper">
    <hr class="hr">
</div>

<!-- [advice More Article] start-->
<?php
$list_articles = $node->field_article_article_ref[LANGUAGE_NONE];
if (isset($node->field_article_article_ref[LANGUAGE_NONE][0])) {
  ?>
  <section class="section-padding adviceMoreArticle">
      <div class="wrapper">
          <header class="heading text-center">
              <h3 class="heading__title heading__title--sub"><?php print t("A lire aussi"); ?></h3>
          </header>
          <div data-equalizer data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" data-slick-responsive="small-only" class="adviceMoreArticle__list">
              <?php
              foreach ($node->field_article_article_ref[LANGUAGE_NONE] as $item) {
                if (isset($item["entity"])) {
                  $article = $item["entity"];
                }
                else {
                  $article = node_load($item["target_id"]);
                }

                $image_small = '';
                if(isset($article->field_article_teaser_image[LANGUAGE_NONE][0]['uri'])){
                  $image_small = image_style_url("dossier_big_teaser_mobile", $article->field_article_teaser_image[LANGUAGE_NONE][0]['uri']);
                }
                ?>
                <div class="adviceMoreArticle__item">
                    <div class="adviceMoreArticle__item__img">

                      <!-- [Responsive img] start-->
                      <img alt="<?php print t('kaufman et broad, illustration de') . ' ' . $article->title; ?>" data-interchange="[<?php print $image_small ?>, (small)], [<?php print $image_small ?>, (large)]"/>
                      <noscript><img src="<?php print $image_small ?>" alt="<?php print t('kaufman et broad, illustration de') . ' ' . $article->title; ?>"/></noscript>
                      <!-- [Responsive img] end-->

                    </div>
                    <div data-equalizer-watch="data-equalizer-watch" class="adviceMoreArticle__item__infos">
                        <h4 class="adviceMoreArticle__item__infos__heading"><?php print $article->title; ?></h4>
                        <p><?php print isset($article->field_article_resume[LANGUAGE_NONE][0]["value"]) ? cut_character($article->field_article_resume[LANGUAGE_NONE][0]["value"]) : ''  ?></p>
                        <div class="btn-wrapper text-center">
                            <a href="<?php print url('node/' . $article->nid); ?>" class="btn-primary btn-rounded">
                                <?php print t("En savoir plus"); ?>
                            </a>
                        </div>
                    </div>
                </div>

              <?php } ?>
          </div>
      </div>
  </section>
<?php } ?>
<!-- [advice More Article] end-->

<!-- [contactUs generic] start-->
<?php
if (function_exists('kandb_contact_block_page')) {
  print kandb_contact_block_page();
}
?>
<!-- [contactUs generic] end-->