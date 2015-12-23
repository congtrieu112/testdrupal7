<?php
$calenders = isset($data['calenders']) ? $data['calenders'] : '';
print theme('finance_header_block');
?>

<?php if($calenders) : ?>
<!-- [content legroupeFinancePublications] start-->
<section class="section-padding legroupeFinaceCalendar bg-lightGrey">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title"><?php print t('Calendrier'); ?></h1>
    </header>
    <div class="legroupeFinaceCalendar__list">
      <ul>
        <ul>
          <?php foreach($calenders as $date => $content) :
            $arr_date = explode('-', $date);
            $year = ''; $day = ''; $month = '';
            if(is_array($arr_date)) {
              $year = isset($arr_date[0]) ? $arr_date[0] : '';
              $month = isset($arr_date[1]) ? $arr_date[1] : '';
              $day = isset($arr_date[2]) ? $arr_date[2] : '';
            }
          ?>
          <li>
            <div class="legroupeFinaceCalendar__item">
              <div class="inner">
                <?php if($day && $month && $year) : ?>
                <p class="date"><span class="day"><?php print $day; ?></span><span class="month"><?php print $month . '.' . $year?></span></p>
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

<?php
  $doc_comuniques = isset($data['documents_communique']) ? $data['documents_communique'] : '';
  $doc_explode_comuniques = isset($data['documents_explode_communique']) ? $data['documents_explode_communique'] : '';
  if($doc_comuniques || $doc_explode_comuniques) :
?>
 <!-- [recent Documents] start-->
<section class="section-padding">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title"><?php print t('Communiqués et documents récents'); ?></h1>
    </header>
  </div>
  <div class="wrapper--narrow downloadDocs">
    <ul class="accordion fullWidth">
      <li class="accordion__link">
        <div class="downloadDocs__heading">
          <h3 class="downloadDocs__title"><?php print t('Communiqués'); ?></h3>
        </div>
        <ul class="downloadDocs__list">
          <?php foreach($doc_comuniques as $doc_comunique) :
            $doc_date = isset($doc_comunique->field_document_date[LANGUAGE_NONE][0]['value']) ? $doc_comunique->field_document_date[LANGUAGE_NONE][0]['value'] : '';
            $doc_title = isset($doc_comunique->title) ? $doc_comunique->title : '';
            $doc_uri = isset($doc_comunique->field_document_file[LANGUAGE_NONE][0]['uri']) ? $doc_comunique->field_document_file[LANGUAGE_NONE][0]['uri'] : '';
          ?>
          <li class="downloadDocs__item">
            <?php if($doc_date) : ?>
            <div class="downloadDocs__item__date">
              <spn><?php print date("d.m.Y", strtotime($doc_date)); ?></spn>
            </div>
            <?php endif; ?>
            <div class="downloadDocs__item__info">
              <?php if($doc_title) : ?>
              <h4 class="downloadDocs__item__heading"><?php print $doc_title; ?></h4>
              <?php endif; ?>
              <?php if($doc_uri) : ?>
              <div class="downloadDocs__item__link"><a href="#" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              <?php endif; ?>
            </div>
          </li>
          <?php endforeach; ?>
          <li class="btn-wrapper btn-wrapper--center"><a href="#" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF" class="btn-primary btn-rounded">Voir tout<span class="icon icon-arrow"></span></a></li>
        </ul>
      </li>

      <li class="accordion__link">
        <div class="downloadDocs__heading">
          <h3 class="downloadDocs__title"><?php print t('Communiqués'); ?></h3>
        </div>
        <ul class="downloadDocs__list">
          <?php foreach($doc_explode_comuniques as $doc_explode_comunique) :
            $ex_doc_date = isset($doc_explode_comunique->field_document_date[LANGUAGE_NONE][0]['value']) ? $doc_explode_comunique->field_document_date[LANGUAGE_NONE][0]['value'] : '';
            $ex_doc_title = isset($doc_explode_comunique->title) ? $doc_explode_comunique->title : '';
            $ex_doc_uri = isset($doc_explode_comunique->field_document_file[LANGUAGE_NONE][0]['uri']) ? $doc_explode_comunique->field_document_file[LANGUAGE_NONE][0]['uri'] : '';
          ?>
          <li class="downloadDocs__item">
            <?php if($ex_doc_date) : ?>
            <div class="downloadDocs__item__date">
              <spn><?php print date("d.m.Y", strtotime($ex_doc_date)); ?></spn>
            </div>
            <?php endif; ?>
            <div class="downloadDocs__item__info">
              <?php if($ex_doc_title) : ?>
              <h4 class="downloadDocs__item__heading"><?php print $ex_doc_title; ?></h4>
              <?php endif; ?>
              <?php if($ex_doc_uri) : ?>
              <div class="downloadDocs__item__link"><a href="#" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              <?php endif; ?>
            </div>
          </li>
          <?php endforeach; ?>
          <li class="btn-wrapper btn-wrapper--center"><a href="#" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF" class="btn-primary btn-rounded">Voir tout<span class="icon icon-arrow"></span></a></li>
        </ul>
      </li>

    </ul>
  </div>
</section>
<!-- [recent Documents] end-->

<?php endif; ?>