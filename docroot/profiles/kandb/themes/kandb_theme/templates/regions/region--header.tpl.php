<?php

/**
 * @file
 * Default theme implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top class.
 * - $region: The name of the region variable as defined in the theme's .info file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
// TODO : GET DYNAMIC MENU BY DOMAIN
?>
<!-- [siteHeader] start-->
<aside class="hide-for-large-up pushy pushy-left">
  <ul class="pushy__menu">
    <li class="pushy__menu__item"><a href="#">Nos offres</a></li>
    <li class="pushy__menu__item"><a href="#">Nos services</a></li>
    <li class="pushy__menu__item"><a href="#">Nos conseils</a></li>
    <li class="pushy__menu__item"><a href="#">Le groupe</a></li>
  </ul>
</aside>
<div class="sticky contain-to-grid">
  <header data-topbar role="banner" class="header">
    <button class="hide-for-large-up menu-btn"><span>Ouvrir le menu</span></button>
    <ul class="header__title title-area show-for-large-up">
      <li class="name"><a href="index.html" title="K&amp;B homepage" class="title-area__link"><img src="<?php print $logo_svg; ?>" alt="Kaufman&amp;Board"></a></li>
      <li role="search" class="has-form hidden">
        <form action="#" method="post" class="row collapse">
          <div class="large-4 small-3 columns">
            <button type="submit" class="button expand">Ok</button>
          </div>
          <div class="large-8 small-9 columns">
            <input type="text" placeholder="Ville, programme, bien...">
          </div>
        </form>
      </li>
    </ul>
    <nav aria-label="Menu principal" class="header__menu show-for-large-up right">
      <ul class="main-menu">
        <li class="main-menu__item"><a href="#">Nos offres</a></li>
        <li class="main-menu__item"><a href="#">Nos services</a></li>
        <li class="main-menu__item"><a href="#">Nos conseils</a></li>
        <li class="main-menu__item"><a href="#">Le groupe</a></li>
      </ul>
      <!-- [buttonDropdown] start-->
      <button data-dropdown="accountDropdown" aria-controls="accountDropdown" aria-expanded="false" class="btn-primary btn-rounded header__btn">Mon compte<span class="icon icon-expand"></span>
      </button>
      <ul id="accountDropdown" data-dropdown-content="data-dropdown-content" role="menu" aria-hidden="true" tabindex="-1" class="f-dropdown">
        <li><a href="#">Mon espace</a></li>
        <li><a href="#">Mes informations</a></li>
        <li><a href="#">Déconnexion</a></li>
      </ul>
      <!-- [buttonDropdown] start-->
    </nav>
  </header>
</div>
<div class="site-overlay"></div>
<!-- [siteHeader] end-->
