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
      <h1 class="heading__title"><?php print t('Assemblées Générales'); ?></h1>
    </header>
  </div>
  <div class="wrapper--narrow downloadDocs">
    <ul data-app-accordion="communiquesDocs" class="accordion fullWidth">
      <?php foreach($assembly_content as $date_key => $assembly_per_date) : ?>
        <?php foreach($assembly_per_date as $type_key => $assembly_per_type) : ?>
          <li class="accordion__link"><a data-app-accordion-link="#communiquesDocs-<?php print $date_key . $type_key; ?>" role="button" class="<?php print $status_class; ?> display-status"><span class="show-for-sr"><?php print t('fermer'); ?></span></a>
            <div id="communiquesDocs-<?php print $date_key . $type_key; ?>">
              <div class="downloadDocs__heading">
                <h3 class="downloadDocs__title"><?php print $type_key; ?></h3><span class="downloadDocs__title--sub"><?php print $assembly_per_type['date']; ?></span>
              </div>
              <div data-app-accordion-content="data-app-accordion-content" class="communiquesDocs">
                  <?php foreach($assembly_per_type['nodes'] as $node) : ?>
                <div class="communiquesDocs__item bg-lightGrey">
                  <h4 class="communiquesDocs__title"><?php print $node->title; ?></h4>
                  <?php if(isset($node->field_document_file[LANGUAGE_NONE])) :?>
                  <ul class="communiquesDocs__list">
                    <?php foreach($node->field_document_file[LANGUAGE_NONE] as $file) :?>
                      <?php
                        $file_path = '';
                        if (isset($file['fid'])) {
                          if ($exist_download_function) {
                            $file_path = base_path() . 'download-document-file/' . $file['fid'];
                          }
                          else {
                            $file_path = file_create_url($file['uri']);
                          }
                        }
                      ?>
                    <li>
                      <div class="communiquesDocs__list__title"><span><?php print $file['filename']; ?></span></div>
                      <?php if($file_path != '') : ?>
                      <div class="communiquesDocs__list__link"><a href="<?php print $file_path; ?>" title="<?php print t("Télécharger le PDF"); ?>"><span class="icon icon-download-pdf"></span></a></div>
                      <?php endif; ?>
                    </li>
                    <?php endforeach; ?>
                  </ul>
                  <?php endif; ?>
                </div>
                <?php endforeach; $status_class = 'false'; ?>
              </div>
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