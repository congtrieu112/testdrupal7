<?php
$arg = arg();
$en_active = $fr_active = $current_path = '';

// Get current language.
if (in_array(end($arg), array('fr', 'en'))) :
  $current_lang = end($arg);
  array_pop($arg);
else:
  $current_lang = 'fr';
endif;

if ($current_lang == 'en') :
  $en_active = 'active';
else :
  $fr_active = 'active';
endif;

$current_path = implode('/', $arg);
$switch_url_en = url($current_path . '/en');
$switch_url_fr = url($current_path . '/fr');
$block_title = variable_get('finance_header_title_' . $current_lang);
$block_sub_title = variable_get('finance_header_sub_title_' . $current_lang);
$block_img_full_id = variable_get('finance_header_image_full_' . $current_lang);
$block_img_small_id = variable_get('finance_header_image_small_' . $current_lang);
$block_img_full_load = file_load($block_img_full_id);
$block_img_small_load = file_load($block_img_small_id);
$block_img_full_uri = (isset($block_img_full_load->uri)) ? file_create_url($block_img_full_load->uri) : '';
$block_img_small_uri = (isset($block_img_small_load->uri)) ? file_create_url($block_img_small_load->uri) : '';
?>
<?php if ($block_title && $block_img_full_load): ?>
  <div class="lang">
      <nav class="wrapper">
          <ul>
              <li class="fr <?php print $fr_active; ?>"><a href="<?php print $switch_url_fr; ?>" title="<?php print t('Version française de la page'); ?>">fr</a></li>
              <li class="en <?php print $en_active; ?>"><a href="<?php print $switch_url_en; ?>" title="<?php print t('English version of the page'); ?>">en</a></li>
          </ul>
      </nav>
  </div>
  <section data-interchange="[<?php print $block_img_small_uri; ?>, (small)], [<?php print $block_img_full_uri; ?>, (medium)]" class="narrow-header">
      <div class="wrapper">
          <div class="heading heading--bordered heading--white">
              <div class="heading__title"><?php print $block_title; ?></div>
              <div class="heading__title heading__title--sub"><?php print $block_sub_title; ?></div>
          </div>
      </div>
  </section>
  <!-- [header Advice] end-->
  <!-- [pageHeaderNav] start-->
  <nav class="pageHeaderNav wrapper">
      <ul class="pageHeaderNav__list">
          <?php
          $number_cta = 5;
          $current_path = current_path();
          $current_path = explode('/', $current_path);
          $current_path =$current_path[2];
          for ($i = 0; $i < $number_cta; $i++) :
            $url = $title = $class = '';
            $cta = array();
            $cta = variable_get('cta_menu_item_finance_' . $i . '_' . $current_lang);
            $default_menu_titles = $current_lang == 'en' ? unserialize(KANDB_GROUP_HEADER_MENU_DEFAULT_TITLES_EN) : unserialize(KANDB_GROUP_HEADER_MENU_DEFAULT_TITLES_FR);
            $default_menu_links = unserialize(KANDB_GROUP_HEADER_MENU_DEFAULT_LINKS);
            if (isset($cta['url']) && isset($cta['title']) && $cta['url'] && $cta['title']):
              $url = $cta['url'];
              $title = $cta['title'];
            else:
              $url = $current_lang == 'en' ? $default_menu_links[$i] . '/en' : $default_menu_links[$i];
              $title = $default_menu_titles[$i];
            endif;
            $url_alias = explode('/', $url);
            $url_alias = $url_alias[2];
            if ($current_path == $url_alias) :
              $class = 'active';
            endif;
            ?>
            <li class="pageHeaderNav__list__item <?php print $class; ?>">
                <a href="<?php print url($url); ?>"><?php print $title; ?></a>
            </li>
          <?php endfor; ?>
      </ul>
  </nav>
  <!-- [pageHeaderNav] end-->
  <div class="top-actions">
      <div class="wrapper">
          <a href="<?php print url('corporate'); ?>" class="btn-white"><?php print t('Retour'); ?><span class="icon icon-arrow left"></span></a>
      </div>
  </div>
  <div class="wrapper">
      <hr class="hr">
  </div>
  <?php
 endif;
