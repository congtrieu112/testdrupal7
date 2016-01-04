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
        <li class = "pageHeaderNav__list__item ">
            <a href = "#">Habitat</a>
        </li>
        <li class = "pageHeaderNav__list__item ">
            <a href = "#">Tertiary</a>
        </li>
        <li class = "pageHeaderNav__list__item ">
            <a href = "#">Our agencies</a>
        </li>
    </ul>
</nav>
<!-- [pageHeaderNav] end-->
<div class="top-actions">
    <div class="wrapper"><a href="#" class="btn-white"><?php print t('Retour'); ?><span class="icon icon-arrow left"></span></a>
    </div>
</div>
<div class="wrapper">
    <hr class="hr">
</div>