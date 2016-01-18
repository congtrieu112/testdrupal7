<?php
define(MAX_LENGTH_FILENAME, 50);
?>
<div class="wrapper--narrow downloadDocs">
  <ul data-app-accordion="communiquesDocs" class="accordion fullWidth">
      <?php $i_active = 0; ?>
      <?php foreach($content_archives['tab_content'] as $year =>  $documents) :?>
        <?php if ($documents) : ?>
          <li class="accordion__link">
              <a data-app-accordion-link="#communiquesDocs-<?php print $year; ?>" role="button" class="<?php print $i_active == 0 ? 'active' : ''; ?> display-status"><span class="show-for-sr">fermer</span></a>
              <div id="communiquesDocs-<?php print $year; ?>">
                  <div class="downloadDocs__heading">
                      <h3 class="downloadDocs__title"><?php print $year; ?></h3>
                  </div>
                  <div data-app-accordion-content="data-app-accordion-content" class="communiquesDocs">
                      <?php foreach ($documents as $key => $document): ?>
                        <?php if ($document): ?>
                          <?php
                          $title = $document->title;
                          $field_document_file = field_get_items('node', $document, 'field_document_file');
                          ?>
                          <div class="communiquesDocs__item bg-lightGrey">
                              <h4 class="communiquesDocs__title"><?php print $title; ?></h4>
                              <?php if ($field_document_file) : ?>
                                <ul class="communiquesDocs__list">
                                    <?php foreach ($field_document_file as $file) : ?>
                                      <?php
                                        $filename = '';
                                        if ($file['description'] != '') {
                                          $filename = $file['description'];
                                        }
                                        else {
                                          $filename = preg_replace("/['.pdf', '_']/", ' ', $file['filename']);
                                        }
                                      ?>
                                      <li>
                                          <div class="communiquesDocs__list__title"><span><?php print !empty($filename)? $filename:''; ?></span></div>
                                          <div class="communiquesDocs__list__link"><a href="<?php print '/download-document-file/' . $file['fid']; ?>" title="<?php print !empty($filename)? $filename:''; ?>"><span class="icon icon-download-pdf"></span></a></div>
                                      </li>
                                    <?php endforeach; ?>
                                </ul>
                              <?php endif; ?>
                          </div>
                        <?php endif; ?>
                      <?php endforeach; ?>
                  </div>
              </div>
          </li>
          <?php $i_active++; ?>
        <?php endif; ?>
      <?php endforeach; ?>
  </ul>
</div>