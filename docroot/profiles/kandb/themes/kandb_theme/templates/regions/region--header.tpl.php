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
global $base_url;
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
?>

<!-- [siteHeader] start-->
<div class="hide-for-medium-up pushy pushy-left"></div>
<div class="sticky contain-to-grid">
  <div class="fixed">
    <nav data-topbar="" role="banner" class="wrapper header">
      <button aria-label="" class="hide-for-medium-up menu-btn"><span><?php print t('Ouvrir le menu'); ?></span></button>
      <div class="header__title">
        <ul class="title-area">
          <li class="name"><a href="<?php print $base_url; ?>" title="K&amp;B homepage" class="title-area__link">
              <?php if ($is_front): ?>
                <h1><img src="<?php print $logo_svg; ?>" alt="Kaufman&amp;Board"></h1>
              <?php else: ?>
                <img src="<?php print $logo_svg; ?>" alt="Kaufman&amp;Board">
              <?php endif; ?>
            </a>
          </li>
          <li role="search" class="title-area__search notVisible">
            <button aria-label="Ouvrir la recherche" aria-haspopup="true" data-topbar-search="" class="icon icon-search"></button>
          </li>
        </ul>
        <aside aria-hidden="true" class="wrapper header__search js-topbarSearch">
          <form action="/<?php print URL_SEARCH_B2C; ?>" method="get" nov alidate="" class="smallSearch">
            <button type="submit" aria-label="Lancer la recherche" class="icon icon-search"></button>
            <div class="smallSearch__input">
              <input type="search" placeholder="Ville, département ou programme" required="" pattern="(.){2,}$" class="noScroll">
              <span class="topbarSearchError">Saisir au moins 2 charactères</span>
            </div>
            <button data-topbar-search="" role="button" class="smallSearch__close"><span>Fermer la recherche</span></button>
          </form>
        </aside>
      </div>
      <div aria-label="Menu principal" class="header__menu">
        <ul class="main-menu">
          <?php if ($main_menu) : ?>
            <?php foreach ($main_menu as $item) : ?>
              <li class="main-menu__item"><?php print l($item['title'], $item['href'], array('attributes' => array('title' => $item['title'], 'class' => array('textLink')))); ?></li>
            <?php endforeach; ?>
          <?php endif; ?>
          <li class="main-menu__item"><a href="/<?php print URL_PROJET; ?>" class="btn-primary btn-rounded btn-icon"><span class="button__content"><span class="icon icon-account"></span>Mon espace</span></a></li>
        </ul>
      </div>
    </nav>
  </div>
</div>
<div class="site-overlay"></div>
<!-- [siteHeader] end-->