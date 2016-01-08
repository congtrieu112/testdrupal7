<?php
$actualites_header = module_invoke('bean', 'block_view', 'actualités-header');
if (isset($actualites_header['content']) && $actualites_header['content']) {
  print render($actualites_header['content']);
}

$class_first_block = 'active';
?>

<section class="wrapper section-padding ourAdvices">
    <header class="heading heading--bordered">
        <h1 class="heading__title"><?php print variable_get('title_news'); ?></h1>
        <p class="heading__title heading__title--sub"><?php print variable_get('sub_title_news'); ?></p>
    </header>

    <?php
      $image = variable_get('image_group_new');
      $image = is_numeric($image) ? file_load($image) : '';
      $image = (isset($image->uri) AND $image->uri) ? image_style_url('dossier_big_teaser', $image->uri) : '';
    ?>
    <article class="text-center">
        <figure class="ourAdvices__figure">            
            <img alt="<?php print $title; ?>" data-interchange="[<?php print $image; ?>, (small)], [<?php print $image; ?>, (medium)]"/>
            <noscript><img src="<?php print $image; ?>" alt="<?php print $title; ?>"/></noscript>            
            <!-- [Responsive img] end-->
        </figure>
        <div class="heading--small ourAdvices__heading">
            <?php             
                $descriptions_news = variable_get('description_news');
                print $descriptions_news['value'];
            ?>
        </div>        
    </article>
</section>
<section class="section-padding">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title"><?php print t('Communiqué de presse'); ?></h1>
    </header>
    <nav class="form-dropdown form-dropdown--responsive">
      <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown data-app-dropdown-responsive="small-only" class="form-dropdown__trigger"><?php print t('Les actualités'); ?><span aria-hidden="true" class="icon icon-expand"></span></button>
      <div id="dropdown-downloadDocs" aria-hidden="true" class="form-dropdown__content hidden">
        <ul class="ul-unstyled undo-padding">
          <?php foreach($content_archives['tab_header'] as $tab_content) : ?>
          <li class="bordered"><a class="<?php print $tab_content['class']; ?>" href="<?php print $tab_content['tab_url']; ?>"><span><?php print $tab_content['tab_title'] ;?></span></a></li>
          <?php endforeach; ?>
        </ul>
      </div>
    </nav>
  </div>
  <div class="wrapper--narrow downloadDocs">
    <ul data-app-accordion="seeMore" class="accordion fullWidth">
      <?php foreach($content_archives['tab_content'] as $year =>  $nodes) :?>
      <li class="accordion__link"><a data-app-accordion-link="#financeDocs-<?php print $year; ?>" role="button" class="<?php print $class_first_block; ?> display-status"><span class="show-for-sr"><?php print t('fermer'); ?></span></a>
        <div id="financeDocs-<?php print $year; ?>">
          <div class="downloadDocs__heading">
            <h3 class="downloadDocs__title"><?php print $year; ?></h3>
          </div>
          <ul data-app-accordion-content="data-app-accordion-content" class="downloadDocs__list">
            <?php foreach ($nodes as $node) : ?>
            <li class="downloadDocs__item">
              <div class="downloadDocs__item__date">
                <?php
                  $document_date = '';
                  if (isset($node->field_document_date[LANGUAGE_NONE][0]['value'])) {
                    $document_date = date('d.m.Y', strtotime($node->field_document_date[LANGUAGE_NONE][0]['value']));
                  }
                ?>
                <spn><?php print $document_date ; ?></spn>
              </div>
              <div class="downloadDocs__item__info">
                <h4 class="downloadDocs__item__heading"><?php print $node->title; ?></h4>
                <?php if(isset($node->field_document_file[LANGUAGE_NONE])) : ?>
                  <?php foreach($node->field_document_file[LANGUAGE_NONE] as $file) :?>
                    <?php
                    $document_file = '';
                    $document_file = base_path() . 'download-document-file/' . $file['fid'];
                    ?>
                    <?php if ($document_file != '') : ?>
                    <div class="downloadDocs__item__link"><a href="<?php print $document_file; ?>" title="<?php print $file['filename']; ?>"><span class="icon icon-download-pdf"></span></a></div>
                    <?php endif; ?>
                  <?php endforeach; ?>
                <?php endif; ?>
              </div>
            </li>
            <?php endforeach; $class_first_block = 'false'; ?>
          </ul>
        </div>
      </li>
      <?php endforeach; ?>
      <?php if(isset($pager)) : ?>
        <?php print $pager; ?>
      <?php endif; ?>
    </ul>
  </div>
</section>