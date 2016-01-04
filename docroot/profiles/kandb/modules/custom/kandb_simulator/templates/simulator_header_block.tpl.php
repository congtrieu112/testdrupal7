<?php
$arg = arg();
$current_path = implode('/', $arg);
if (isset($data['simulator_header'])):
  print render($data['simulator_header']);
endif;

$group_header = module_invoke('bean', 'block_view', 'simulator-header');
if (isset($group_header['content']) && $group_header['content']) {
  print render($group_header['content']);
}
?>
  <!-- [header Advice] end-->
  <!-- [pageHeaderNav] start-->
  <nav class="pageHeaderNav wrapper">
      <ul class="pageHeaderNav__list">
          <?php
          $number_si = 4;
          for ($i = 0; $i < $number_si; $i++) :
            $url = $title = $class = '';
            $si = array();
            $si = variable_get('si_simulator_block_header_' . $i);
            $default_menu_titles = unserialize(KANDB_SIMULATOR_HEADER_MENU_DEFAULT_TITLES);
            $default_menu_links = unserialize(KANDB_SIMULATOR_HEADER_MENU_DEFAULT_LINKS);
            if (isset($si['url']) && isset($si['title']) && $si['url'] && $si['title']):
            $url = $si['url'];
            $title = $si['title'];
          else:
            $url = $default_menu_links[$i];
            $title = $default_menu_titles[$i];
          endif;

          // Active menu.
          if (url($current_path) == url($url)):
            $class = 'active';
          endif;
            ?>
            <li class="pageHeaderNav__list__item <?php print $class; ?>">
                <a href="<?php print url($url); ?>"><?php print $title; ?></a>
            </li>
          <?php endfor; ?>
      </ul>
  </nav>
