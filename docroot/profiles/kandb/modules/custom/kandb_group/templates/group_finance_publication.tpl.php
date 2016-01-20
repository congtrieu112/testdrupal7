<?php
define(MAX_LENGTH_FILENAME, 50);
$current_url = url(current_path(), array('absolute' => TRUE));
$current_path = explode('/', $current_url);
$current_path_alias = $current_path[count($current_path)- 3];
$calenders = isset($data['calenders']) ? $data['calenders'] : '';
$recent_document = isset($data['recent_document']) ? $data['recent_document'] : '';
;

print theme('finance_header_block');
?>

<?php if ($calenders) : ?>
  <!-- [content legroupeFinancePublications] start-->
  <section class="section-padding legroupeFinaceCalendar bg-lightGrey">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print t('Calendrier'); ?></h1>
          </header>
          <div class="legroupeFinaceCalendar__list">
              <ul>
                  <ul>
                      <?php
                      foreach ($calenders as $key => $value) :
                        $date = isset($value['date']) ? $value['date'] : '';
                        $content = isset($value['content']) ? $value['content'] : '';
                        $arr_date = explode('-', $date);
                        $year = '';
                        $day = '';
                        $month = '';
                        if (is_array($arr_date)) {
                          $year = isset($arr_date[0]) ? $arr_date[0] : '';
                          $month = isset($arr_date[1]) ? $arr_date[1] : '';
                          $day = isset($arr_date[2]) ? $arr_date[2] : '';
                          if ($day < 10) :
                            $day = str_replace('0', '', $day);
                          endif;
                        }
                        ?>
                        <li>
                            <div class="legroupeFinaceCalendar__item">
                                <div class="inner">
                                    <?php if ($day && $month && $year) : ?>
                                      <p class="date"><span class="day"><?php print $day; ?></span><span class="month"><?php print $month . '.' . $year ?></span></p>
                                    <?php endif; ?>
                                    <?php if ($content) : ?>
                                      <p class="description"><?php print $content; ?></p>
                                    <?php endif; ?>
                                </div>
                            </div>
                        </li>
                      <?php endforeach; ?>
                  </ul>
              </ul>
          </div>
          <p class="text-infor"><?php print t('Cet agenda peut être soumis à des modifications'); ?></p>
      </div>
  </section>
  <!-- [content legroupeFinancePublications] end-->
<?php endif; ?>

<?php if ($recent_document) : ?>
  <!-- [communiques Documents] start-->
  <section class="section-padding">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print t('Communiqués et documents récents'); ?></h1>
          </header>
      </div>
      <div class="wrapper--narrow downloadDocs">
          <ul data-app-accordion="communiquesDocs" class="accordion fullWidth">
              <?php  if ($data['tab_document']) : ?>
                <li class="btn-wrapper btn-wrapper--center">
                    <nav class="form-dropdown form-dropdown--responsive">
                        <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown="data-app-dropdown" data-app-dropdown-responsive="small-only" class="form-dropdown__trigger">
                            <?php
                               $i = 0;
                               foreach ($data['tab_document'] as $key => $value) :
                                    if ($current_path_alias == $value['tab_id'] || (count($current_path) <= 7 && $i == 0)) : ?>
                                        <span><?php print $value['tab_title']; ?></span>
                             <?php
                                    endif;
                                    $i++;
                                endforeach;
                              ?>
                            <span aria-hidden="true" class="icon icon-expand"></span>
                        </button>
                        <div id="dropdown-downloadDocs" aria-hidden="true" class="form-dropdown__content hidden">
                          <ul class="ul-unstyled undo-padding">
                            <?php
                               $i = 0;
                               foreach ($data['tab_document'] as $key => $value) :
                            ?>
                                <li class="bordered">
                                    <a href="<?php print $value['tab_url']; ?>" title="<?php print $value['tab_title']; ?>" class="<?php if ($current_path_alias == $value['tab_id'] || (count($current_path) <= 7 && $i == 0)) : print 'active'; endif; ?>">
                                        <span><?php print $value['tab_title']; ?></span>
                                    </a>
                                </li>
                            <?php $i++; endforeach; ?>
                          </ul>
                        </div>
                    </nav>

                </li>
              <?php endif; ?>
              <?php $i_active = 0; ?>
              <?php foreach ($recent_document as $year => $documents): ?>
                <?php if ($documents) : ?>
                  <li class="accordion__link">
                      <a data-app-accordion-link="#communiquesDocs-<?php print $year; ?>" role="button" class="<?php print $i_active == 0 ? 'active' : ''; ?> display-status"><span class="show-for-sr">fermer</span></a>
                      <div id="communiquesDocs-<?php print $year; ?>">
                          <div class="downloadDocs__heading">
                              <h3 class="downloadDocs__title"><?php print $year; ?></h3>
                          </div>
                          <div data-app-accordion-content="data-app-accordion-content" class="communiquesDocs">
                              <?php foreach ($documents as $key => $doc_nid): ?>
                                <?php if (is_numeric($doc_nid) AND $document = node_load($doc_nid)) : ?>
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
                                                    <?php if(strlen($filename) < MAX_LENGTH_FILENAME): ?>
                                                      <div class="communiquesDocs__list__title"><span><?php print !empty($filename)? $filename:''; ?></span></div>
                                                    <?php else: ?>
                                                      <div class="communiquesDocs__list__title"><span><?php print $filename ; ?></span></div>
                                                    <?php endif;?>
                                                    <div class="communiquesDocs__list__link"><a href="<?php print '/download-document-file/' . $file['fid']; ?>" title="<?php print !empty($filename)? $filename:''; ?>"><span class="icon icon-download-pdf"></span></a></div>
                                                </li>
                                              <?php endforeach; ?>
                                          </ul>
                                        <?php endif; ?>
                                    </div>
                                  <?php endif; ?>
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
  </section>
  <!-- [communiques Documents] end-->
<?php endif; ?>

<?php
$inscription_form = webform_features_machine_name_load('inscription');
$inscription_block_id = isset($inscription_form->nid) ? 'client-block-' . $inscription_form->nid : '';
$block = module_invoke('webform', 'block_view', $inscription_block_id);

?>
<!-- [email form] start-->
<section class="section-padding">
    <div class="wrapper">
        <form action="#" method="get" data-abide class="emailForm">
            <div class="emailForm__title">
                <p>Recevez toutes nos informations financières</p>
            </div>
            <div class="emailForm__input">
                <label for="email-input"><span class="visually-hidden">Votre adresse d’email</span>
                    <?php print render($block['content']); ?>
                </label>
            </div>
        </form>
    </div>
</section>
<!-- [email form] end-->
