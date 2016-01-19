<?php $class_first_block = 'active'; ?>
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