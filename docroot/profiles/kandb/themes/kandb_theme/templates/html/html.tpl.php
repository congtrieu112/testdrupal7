<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
  global $base_url;
?><!DOCTYPE html >
<html lang="fr" class="no-js">

<head profile="<?php print $grddl_profile; ?>">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script>
    var MTUserId='c1114374-8ce1-41cb-a2d0-fbd1249e9b15';
    var MTFontIds = new Array();

    MTFontIds.push("1459684"); // Neue Helvetica® W04 35 Thin
    MTFontIds.push("1459692"); // Neue Helvetica® W04 55 Roman
    MTFontIds.push("1459700"); // Neue Helvetica® W04 75 Bold
    (function() {
      var mtTracking = document.createElement('script');
      mtTracking.type='text/javascript';
      mtTracking.async='true';
      mtTracking.src='<?php print $base_url; ?>/profiles/kandb/themes/kandb_theme/assets/fonts/mtiFontTrackingCode.js';

      (document.getElementsByTagName('head')[0]||document.getElementsByTagName('body')[0]).appendChild(mtTracking);
    })();
  </script>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div data-popincookies aria-hidden="true" class="popinCookies">
    <div class="wrapper">
      <div class="popinCookies__text">
        <p><?php print !empty(variable_get('kb_cookie_descriptions')) ? variable_get('kb_cookie_descriptions') : print t("En poursuivant votre navigation sur ce site, vous acceptez I'utilisation de Cookies pour vous proposer des publicités adaptées à vos centres d'intérêts, pour réaliser des statistiques de navigation, et pour faciliter le partage d'information sur les réseaux sociaux.  "); ?>
          <a href="<?php print !empty(variable_get('kb_cookie_link')) ? variable_get('kb_cookie_link') : '#'?>"><?php print !empty(variable_get('kb_cookie_title')) ? variable_get('kb_cookie_title') : print t("Pour en savoir plus et paramétrer les cookies."); ?></a>
        </p>
      </div>
      <div class="popinCookies__buttons">
        <span role="button" data-popincookies-accept class="popinCookies__buttons__agree btn-primary btn-rounded"><?php print t('Ok'); ?></span>
        <span type="button" data-popincookies-close class="popinCookies__buttons__close display-status display-status--suppr">
          <span class="show-for-sr"><?php print t('Fermer'); ?></span>
        </span>
      </div>
    </div>
  </div>  
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
