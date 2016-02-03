<?php
$arg = arg();
$current_path = implode('/', $arg);
$group_header = module_invoke('bean', 'block_view', 'activities-header');
if (isset($group_header['content']) && $group_header['content']) {
  print render($group_header['content']);
}
?>
<!-- [pageHeaderNav] start-->
<nav class="pageHeaderNav wrapper">
    <ul class="pageHeaderNav__list">
        <?php
        $number_cta = 3;
        $default_menu_titles = unserialize(KANDB_GROUP_ACTIVITES_HEADER_MENU_DEFAULT_TITLES);
        $default_menu_links = unserialize(KANDB_GROUP_ACTIVITES_HEADER_MENU_DEFAULT_LINKS);
        for ($i = 0; $i < $number_cta; $i++) :
          $url = $title = $class = '';
          $cta = array();
          $cta = variable_get('cta_group_activites_block_header_' . $i);
          if (isset($cta['url']) && isset($cta['title']) && $cta['url'] && $cta['title']):
            $url = $cta['url'];
            $title = $cta['title'];
          else:
            $url = $default_menu_links[$i];
            $title = $default_menu_titles[$i];
          endif;

          // Active menu.
          if (url($current_path) == url($url)):
            $class = 'active';
          endif;
          
          // Checking the parent url is different to child url.
          // Example: /nos-parent-link, /nos-child-link.
          // Parent : corporate/activites/nos-agences.
          // Child: corporate/activites/nos-services
          if (preg_match('/nos/i', $_GET['q']) && preg_match('/nos/i', $url)) :
            $class = 'active';
          endif;
          
          // Check the child url has the pattern same parent url.
          // Example: /parent-link, /parent-link/123
          $pattern = str_replace('/', '\/', $url);          
          if (preg_match('/'. $pattern . '/i', $_GET['q'])) :            
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
    <div class="wrapper"><a href="<?php print url('corporate') ?>" class="btn-white"><?php print t('Retour'); ?><span class="icon icon-arrow left"></span></a>
    </div>
</div>
<div class="wrapper">
    <hr class="hr">
</div>