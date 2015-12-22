<?php
if (!isset($assembly_content) || empty($assembly_content)) {
  return;
}
$exist_download_function = function_exists('kandb_finance_archives_download_file');
$status_class = 'active';
?>
<section class="section-padding">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title"><?php print t('Assemblées Générales'); ?></h1>
    </header>
  </div>
  <div class="wrapper--narrow downloadDocs">
    <ul data-app-accordion="seeMore" class="accordion fullWidth">
      <?php foreach($assembly_content as $date_key => $assembly_per_date) : ?>
        <?php foreach($assembly_per_date as $type_key => $assembly_per_type) : ?>
        <li class="accordion__link"><a data-app-accordion-link="#assemblee-<?php print $date_key . $type_key; ?>" role="button" class="<?php print $status_class; ?> display-status"><span class="show-for-sr"><?php print t('fermer'); ?></span></a>
          <div id="assemblee-<?php print $date_key . $type_key; ?>">
            <div class="downloadDocs__heading">
              <h3 class="downloadDocs__title"><?php print $type_key; ?></h3><span class="downloadDocs__title--sub"><?php print $assembly_per_type['date']; ?></span>
            </div>
            <ul data-app-accordion-content="data-app-accordion-content" class="downloadDocs__list">
              <?php foreach($assembly_per_type['nodes'] as $node) : ?>
              <?php
                $file_path = '';
                if (isset($node->field_document_file[LANGUAGE_NONE][0]['fid'])) {
                  if ($exist_download_function) {
                    $file_path = base_path() . 'download-document-file/' . $node->field_document_file[LANGUAGE_NONE][0]['fid'];
                  }
                  else {
                    $file_path = file_create_url($node->field_document_file[LANGUAGE_NONE][0]['uri']);
                  }
                }
              ?>
              <li class="downloadDocs__item">
                <div class="downloadDocs__item__info">
                  <h4 class="downloadDocs__item__heading"><?php print $node->title; ?></h4>
                  <?php if($file_path != '') : ?>
                  <div class="downloadDocs__item__link"><a href="<?php print $file_path; ?>" title=<?php print t("Télécharger le PDF"); ?>><span class="icon icon-download-pdf"></span></a></div>
                  <?php endif; ?>
                </div>
              </li>
              <?php endforeach; $status_class = 'false'; ?>
            </ul>
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