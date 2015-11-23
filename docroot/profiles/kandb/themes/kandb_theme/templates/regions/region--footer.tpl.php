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

<?php if ($content): ?>
  <div class="<?php print $classes; ?>">
    <?php print $content; ?>
  </div>
<?php endif; ?>
<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
global $base_url;
$link_custom = $base_url;
if(theme_get_setting('footer_link_custom')){
  $link_custom = theme_get_setting('footer_link_custom');  
}

?>
<footer class="siteFooter">
    <div class="wrapper">
        <div class="siteFooter__head"><a href="<?php print $base_url; ?>" title="retour à l'accueil" class="logo"><img src="<?php print $logo_svg;?>" alt="Kaufman&amp;Board"></a>
            <div class="prescripteurs"><a href="<?php print $link_custom; ?>" class="btn-white">Espace prescripteur<span class="icon icon-arrow"></span></a></div>
            <aside class="aside"><span class="sharing-label">suivez-nous sur</span>
                <?php
                $icon_setting = theme_get_setting('social_display');
                if ($icon_setting) {
                    $facebook = $youtube = $twiiter = "";
                    if (theme_get_setting('footer_link_face')) {
                        $facebook = theme_get_setting('footer_link_face');
                    }
                    if (theme_get_setting('footer_link_youtube')) {
                        $youtube = theme_get_setting('footer_link_youtube');
                    }
                    if (theme_get_setting('footer_link_twiiter')) {
                        $twiiter = theme_get_setting('footer_link_twiiter');
                    }
                    ?>
                    <div class="sharing">
                        <ul class="sharing__items">
                            <li class="sharing__items__item"><a href="<?php print $facebook; ?>" title="partage sur Facebook" class="icon icon-facebook"></a></li>
                            <li class="sharing__items__item"><a href="<?php print $twiiter; ?>#" title="partage sur Twitter" class="icon icon-twitter"></a></li>
                            <li class="sharing__items__item"><a href="<?php print $youtube; ?>" title="partage sur Youtube" class="icon icon-youtube"></a></li>
                        </ul>
                    </div>
                <?php } ?>
            </aside>
        </div>
        <nav class="siteFooter__nav">
            <?php
            $menu_one = $menu_two = $menu_three = "";
            if (!empty(menu_navigation_links('menu-footer-one')) && count(menu_navigation_links('menu-footer-one')) > 0) {
                $menu_one = menu_navigation_links('menu-footer-one');
                ?>
                <ul class="show-for-medium-up searchItems">
                <?php foreach ($menu_one as $item) { ?>
                        <li><a href="<?php print $item['href']; ?>" title="<?php print $item['title'] ?>" class="textLink"><?php print $item['title'] ?></a></li>
                    <?php } ?>

                </ul>
            <?php } ?>
            <?php
            if (!empty(menu_navigation_links('menu-footer-two')) && count(menu_navigation_links('menu-footer-two')) > 0) {
                $menu_two = menu_navigation_links('menu-footer-two');
                ?>
                <ul >
                    <?php foreach ($menu_tow as $item) { ?>
                        <li><a href="<?php print $item['href']; ?>" title="<?php print $item['title'] ?>" class="textLink"><?php print $item['title'] ?></a></li>
                    <?php } ?>

                </ul>
            <?php } ?>
            <?php
            if (!empty(menu_navigation_links('menu-footer-three')) && count(menu_navigation_links('menu-footer-three')) > 0) {
                $menu_three = menu_navigation_links('menu-footer-three');
                ?>
                <ul >
                    <?php foreach ($menu_three as $item) { ?>
                        <li><a href="<?php print $item['href']; ?>" title="<?php print $item['title'] ?>" class="textLink"><?php print $item['title'] ?></a></li>
                        <?php } ?>

                </ul>
            <?php } ?>
        </nav>
    </div>
</footer>
</div>







