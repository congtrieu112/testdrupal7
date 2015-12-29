<?php
$calenders = isset($data['calenders']) ? $data['calenders'] : '';
$recent_document = isset($data['recent_document']) ? $data['recent_document'] : '';

if ($current_lang == 'en') :
  $recent_document_menus = unserialize(KANDB_GROUP_PUBLICATION_DOC_TYPE_TABS_EN);
else :
  $recent_document_menus = unserialize(KANDB_GROUP_PUBLICATION_DOC_TYPE_TABS_FR);
endif;

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
                      foreach ($calenders as $date => $content) :
                        $arr_date = explode('-', $date);
                        $year = '';
                        $day = '';
                        $month = '';
                        if (is_array($arr_date)) {
                          $year = isset($arr_date[0]) ? $arr_date[0] : '';
                          $month = isset($arr_date[1]) ? $arr_date[1] : '';
                          $day = isset($arr_date[2]) ? $arr_date[2] : '';
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
              <?php if ($recent_document_menus) : ?>
                <li class="btn-wrapper btn-wrapper--center">
                    <?php foreach ($recent_document_menus as $key => $value) : ?>
                      <?php
                      $document_type_name = $value['doc_type_name'];
                      $document_type_tid = kandb_group_get_term_from_name($document_type_name, VOCAL_DOCUMENT);
                      $numof_years = $value['numof_years'];
                      ?>
                      <a href="<?php print url('corporate/finance/publication/' . $document_type_tid . '/' . $numof_years . '/' . $current_lang); ?>" title="<?php print $key; ?>" class="btn-primary btn-rounded active">
                          <?php print $key; ?>
                      </a>
                    <?php endforeach; ?>
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
                                                <li>
                                                    <div class="communiquesDocs__list__title"><span><?php print $file['filename']; ?></span></div>
                                                    <div class="communiquesDocs__list__link"><a href="<?php print '/download-document-file/' . $file['fid']; ?>" title="<?php print $file['filename']; ?>"><span class="icon icon-download-pdf"></span></a></div>
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
<!--                    <input type="email" id="email-input" name="submitted[email]" placeholder="Votre adresse d’email" required><small class="error">Email valide requis.</small>
                    <button type="submit" class="button-submit js-btn-submit"><span>OK</span></button>-->
                </label>
            </div>
        </form>
    </div>
</section>
<!-- [email form] end-->
