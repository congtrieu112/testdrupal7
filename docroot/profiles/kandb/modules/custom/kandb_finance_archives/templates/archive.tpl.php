<?php
if (!isset($content_archives) || empty($content_archives)) {
  return;
}

$class_first_block = 'active';

$title = '';
if(array_key_exists(arg(3), $content_archives['tab_header'])):
    $data = $content_archives['tab_header'][arg(3)];
    $title = $data['tab_title'];
else :
    $data = array_shift(array_values($content_archives['tab_header']));
    $title = $data['tab_title'];
endif;

print theme('finance_header_block');
?>
<section class="section-padding">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title"><?php print t('Documents à télécharger'); ?></h1>
    </header>
    <nav class="form-dropdown form-dropdown--responsive">
      <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown data-app-dropdown-responsive="small-only" class="form-dropdown__trigger"><?php print $title; ?><span aria-hidden="true" class="icon icon-expand"></span></button>
      <div id="dropdown-downloadDocs" aria-hidden="true" class="form-dropdown__content hidden">
        <ul class="ul-unstyled undo-padding">
          <?php foreach($content_archives['tab_header'] as $tab_content) : ?>
            <?php if ($tab_content['tab_url']) : ?>
              <li class="bordered"><a class="<?php print $tab_content['class']; ?>" href="<?php print $tab_content['tab_url']; ?>"><span><?php print $tab_content['tab_title'] ;?></span></a></li>
            <?php endif;?>
          <?php endforeach; ?>
        </ul>
      </div>
    </nav>
  </div>
  <?php 
  $args = array(
    'content_archives' => $content_archives,
    'pager' => theme('pager'),
  );
  if ($display_mode == 1) {
    print theme('archive_display_1', $args);
  }
  elseif ($display_mode == 2) {
    print theme('archive_display_2', $args);
  }
  else {
    print theme('archive_display_3', $args);
  }
  ?>
</section>