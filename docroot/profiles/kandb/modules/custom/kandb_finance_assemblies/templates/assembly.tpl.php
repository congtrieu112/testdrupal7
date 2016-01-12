<?php
if (!isset($assembly_content) || empty($assembly_content)) {
  return;
}
$exist_download_function = function_exists('kandb_finance_archives_download_file');
$status_class = 'active';
print theme('finance_header_block');
?>
<section class="section-padding">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title"><?php print $page_title; ?></h1>
    </header>
  </div>
  <div class="wrapper--narrow downloadDocs">
    <ul data-app-accordion="seeMore" class="accordion fullWidth">
      <?php foreach($assembly_content as $date_key => $assembly_per_date) : ?>
        <?php foreach($assembly_per_date as $type_key => $assembly_per_type) : ?>
        <li class="accordion__link"><a data-app-accordion-link="#assemblee-<?php print $date_key . $type_key; ?>" role="button" class="<?php print $status_class; ?> display-status"><span class="show-for-sr"><?php print t('fermer'); ?></span></a>
          <div id="assemblee-<?php print $date_key . $type_key; ?>">
            <?php foreach($assembly_per_type['nodes'] as $node) : ?>
            <?php
              $year = date('Y', strtotime($node->field_document_date[LANGUAGE_NONE][0]['value']));
            ?>
            <div class="downloadDocs__heading">
              <h3 class="downloadDocs__title"><?php print $node->title ; ?></h3><span class="downloadDocs__title--sub"><?php print $year; ?></span>
            </div>
            <ul data-app-accordion-content="data-app-accordion-content" class="downloadDocs__list">
                  <?php if($node->field_document_file[LANGUAGE_NONE]) :?>
                    <?php foreach ($node->field_document_file[LANGUAGE_NONE] as $file): ?>
                      <?php
                        $file_path = '';
                        $file_name = '';
                        if ($exist_download_function) {
                          $file_path = base_path() . 'download-document-file/' . $file['fid'];
                        }
                        else {
                          $file_path = file_create_url($file['uri']);
                        }
                        if ($file['description'] != '') {
                          $file_name = $file['description'];
                        }
                        else {
                          $file_name = preg_replace("/['.pdf', '_']/", ' ', $file['filename']);
                        }
                      ?>
                      <?php if($file_path != '') : ?>
                        <li class="downloadDocs__item">
                          <div class="downloadDocs__item__info">
                            <h4 class="downloadDocs__item__heading"><?php print $file_name; ?></h4>
                              <div class="downloadDocs__item__link"><a href="<?php print $file_path; ?>" title="<?php print $file_name; ?>"><span class="icon icon-download-pdf"></span></a></div>
                          </div>
                        </li>
                      <?php endif; ?>
                    <?php endforeach; ?>
                  <?php endif; ?>
            </ul>
            <?php endforeach; $status_class = 'false'; ?>
          </div>
        </li>
        <?php endforeach ; ?>
      <?php endforeach ; ?>
      <?php if(isset($pager)) : ?>
        <?php print $pager; ?>
      <?php endif; ?>
    </ul>
  </div>
</section>