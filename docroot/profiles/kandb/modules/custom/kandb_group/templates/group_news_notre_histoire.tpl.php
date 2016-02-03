<?php
/**
 * @file
 * Your career template.
 */
?>
<?php
$tabs = kandb_group_button_tabs_header($_GET['q']);
print $tabs;
?>
<?php print theme('group_news_header'); ?>
<?php
$module_title = variable_get('news_history_module_title');
$sub_title = variable_get('news_history_module_sub_title');
?>
<!-- [content Advice] start-->
<section class="wrapper section-padding ourAdvices">
    <?php if ($module_title || $sub_title) : ?>
      <header class="heading heading--bordered">
          <h1 class="heading__title"><?php print $module_title; ?></h1>
          <p class="heading__title heading__title--sub"><?php print $sub_title; ?></p>
      </header>
    <?php endif; ?>
    <?php for ($i = 0; $i <= KANDB_GROUP_NEWS_ITEMS_NUM; $i++) : ?>
      <?php
      $title = variable_get('news_history_item_title_' . $i);
      $description = variable_get('news_history_item_description_' . $i);
      $description = isset($description['value']) ? $description['value'] : '';
      $image = variable_get('news_history_item_image_' . $i);
      $image = is_numeric($image) ? file_load($image) : '';
      $image = (isset($image->uri) AND $image->uri) ? image_style_url('dossier_medium_850x345', $image->uri) : '';
      ?>
      <?php if ($title || $description || $image) : ?>
        <!-- [Article Advice] start-->
        <article class="text-center">
            <?php if($image) : ?>
            <figure class="ourAdvices__figure">
                <!-- images need to have 2 formats in data-interchange attribute:
                - small:
                - medium: 850 x 345
                -->
                <!-- [Responsive img] start-->
                <img alt="<?php print $title; ?>" data-interchange="[<?php print $image; ?>, (small)], [<?php print $image; ?>, (medium)]"/>
                <noscript><img src="<?php print $image; ?>" alt="<?php print $title; ?>"/></noscript>
                <!-- [Responsive img] end-->
            </figure>
            <?php endif; ?>
            <?php if($title) : ?>
            <div class="heading--small ourAdvices__heading">
                <h2 class="heading__title"><?php print $title; ?></h2>
            </div>
            <?php endif; ?>
            <?php if($description) : ?>
            <div class="ourAdvices__text"><?php print $description; ?></div>
            <?php endif; ?>
        </article>
        <!-- [Article Advice] end-->
      <?php endif; ?>
    <?php endfor; ?>
</section>
<!-- [content Advice] end-->