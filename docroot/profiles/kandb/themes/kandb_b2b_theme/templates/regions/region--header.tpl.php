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
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Patrimoine.svg';
$uid = isset($user->uid) ? $user->uid : 0;
$username = isset($user->name) ? $user->name : '';
?>

<!-- [siteHeader] start-->
<div class="hide-for-medium-up pushy pushy-left"></div>
<div class="sticky contain-to-grid">
  <div class="fixed">
    <nav data-topbar role="banner" class="wrapper header">
      <div class="header__title">
        <ul class="title-area">
          <li class="name"><a href="<?php print $base_url; ?>" title="K&amp;B homepage" class="title-area__link">
              <h1 class="main-title"><img src="<?php print $logo_svg; ?>" alt="Kaufman&amp;Broad"></h1></a></li>
        </ul>
      </div>

      <?php if (($main_menu || $user) && ($uid>0)) : ?>
      <div aria-label="Menu principal" class="header__menu">
        <ul class="main-menu">
          <?php foreach ($main_menu as $item) : ?>
            <li class="main-menu__item"><?php print l($item['title'], $item['href'], array('attributes' => array('title' => $item['title'], 'class' => array('textLink')))); ?></li>
          <?php endforeach; ?>
          <li class="main-menu__item"><a data-dropdown="loggedActions" aria-expanded="false" type="button" class="icons"><span class="icon icon-logged-user"></span><span><?php print $username; ?></span><span class="icon icon-logout"></span></a></li>
        </ul>
        <?php if($user) : ?>
        <ul id="loggedActions" data-dropdown-content role="menu" aria-hidden="true" tabindex="-1" class="logged-actions f-dropdown">
          <li><a href="/user/<?php print $uid; ?>"><?php print t('Mes informations'); ?></a></li>
          <li><a href="/user/logout"><?php print t('Me déconnecter'); ?></a></li>
        </ul>
        <?php endif; ?>
      </div>
      <?php endif; ?>
    </nav>
  </div>
</div>
<div class="site-overlay"></div>
<!-- [siteHeader] end-->