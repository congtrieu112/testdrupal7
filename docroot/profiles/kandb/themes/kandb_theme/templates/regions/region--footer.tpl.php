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
global $base_url;
?>

<footer class="siteFooter">
    <div class="wrapper">
        <div class="siteFooter__head"><a href="<?php print $base_url; ?>" title="retour à l'accueil" class="logo"><img src="<?php print $logo_svg; ?>" alt="Kaufman&amp;Board"></a>
            <div class="prescripteurs"><?php if ($link_prescripteur) : ?><a href="<?php print $link_prescripteur; ?>" class="btn-white">Espace prescripteur<span class="icon icon-arrow"></span></a><?php endif; ?></div>
            <?php if ($icon_setting) : ?>
                <aside class="aside"><span class="sharing-label">suivez-nous sur</span>
                     <div class="sharing">
                        <ul class="sharing__items">
                            <?php if ($facebook) : ?><li class="sharing__items__item"><a href="<?php print $facebook; ?>" title="partage sur Facebook" class="icon icon-facebook"></a></li><?php endif; ?>
                            <?php if ($twitter) : ?><li class="sharing__items__item"><a href="<?php print $twitter; ?>#" title="partage sur Twitter" class="icon icon-twitter"></a></li><?php endif; ?>
                            <?php if ($youtube) : ?><li class="sharing__items__item"><a href="<?php print $youtube; ?>" title="partage sur Youtube" class="icon icon-youtube"></a></li><?php endif; ?>
                        </ul>
                    </div>
                </aside>
            <?php endif; ?>
        </div>
        <nav class="siteFooter__nav">
            <?php $i = 0; ?>
            <?php if ($menu_footer && count($menu_footer) > 0) :?>
                <?php foreach ($menu_footer as $item) : ?>
                    <?php if ($i % 3 == 0) : ?>
                        <ul <?php print (!$i ? 'class="show-for-medium-up searchItems"' : '') ?>>
                    <?php endif; ?>
                    <li><a href="<?php print $item['href']; ?>" title="<?php print $item['title'] ?>" class="textLink"><?php print $item['title'] ?></a></li>
                    <?php if ($i % 3 == 2 ) : ?>
                        </ul>
                    <?php endif; ?>
                    <?php $i++; ?>
                    <?php if($i >= 9) break; ?>
                <?php endforeach; ?>
            <?php endif; ?>
        </nav>
    </div>
</footer>







