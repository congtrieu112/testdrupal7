<?php
if (isset($data['group_header'])):
  print render($data['group_header']);
endif;

$calenders = isset($data['calenders']) ? $data['calenders'] : '';
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
                <p class="date"><span class="day"><?php print $day; ?></span><span class="month"><?php print $month . '.' . $year?></span></p>
                <p class="description"><?php print $content; ?></p>
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

<!-- [assembleeGenerale] start-->
<section class="section-padding">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title">Assemblées Générales</h1>
    </header>
  </div>
  <div class="wrapper--narrow downloadDocs">
    <ul data-app-accordion="seeMore" class="accordion fullWidth">
      <li class="accordion__link"><a data-app-accordion-link="#assemblee-0" role="button" class="active display-status"><span class="show-for-sr">fermer</span></a>
        <div id="assemblee-0">
          <div class="downloadDocs__heading">
            <h3 class="downloadDocs__title">GM</h3><span class="downloadDocs__title--sub">28 May 2015</span>
          </div>
          <ul data-app-accordion-content="data-app-accordion-content" class="downloadDocs__list">
            <li class="downloadDocs__item">
              <div class="downloadDocs__item__info">
                <h4 class="downloadDocs__item__heading">VOTING RESULTS OF AGM 28 MAY 2015</h4>
                <div class="downloadDocs__item__link"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              </div>
            </li>
            <li class="downloadDocs__item">
              <div class="downloadDocs__item__info">
                <h4 class="downloadDocs__item__heading">VOTING RESULTS OF AGM 28 MAY 2015</h4>
                <div class="downloadDocs__item__link"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              </div>
            </li>
            <li class="downloadDocs__item">
              <div class="downloadDocs__item__info">
                <h4 class="downloadDocs__item__heading">VOTING RESULTS OF AGM 28 MAY 2015</h4>
                <div class="downloadDocs__item__link"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              </div>
            </li>
          </ul>
        </div>
      </li>
      <li class="accordion__link"><a data-app-accordion-link="#assemblee-1" role="button" class="false display-status"><span class="show-for-sr">fermer</span></a>
        <div id="assemblee-1">
          <div class="downloadDocs__heading">
            <h3 class="downloadDocs__title">GM</h3><span class="downloadDocs__title--sub">28 May 2015</span>
          </div>
          <ul data-app-accordion-content="data-app-accordion-content" class="downloadDocs__list">
            <li class="downloadDocs__item">
              <div class="downloadDocs__item__info">
                <h4 class="downloadDocs__item__heading">VOTING RESULTS OF AGM 28 MAY 2015</h4>
                <div class="downloadDocs__item__link"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              </div>
            </li>
            <li class="downloadDocs__item">
              <div class="downloadDocs__item__info">
                <h4 class="downloadDocs__item__heading">VOTING RESULTS OF AGM 28 MAY 2015</h4>
                <div class="downloadDocs__item__link"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              </div>
            </li>
            <li class="downloadDocs__item">
              <div class="downloadDocs__item__info">
                <h4 class="downloadDocs__item__heading">VOTING RESULTS OF AGM 28 MAY 2015</h4>
                <div class="downloadDocs__item__link"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" title="Télécharger le PDF"><span class="icon icon-download-pdf"></span></a></div>
              </div>
            </li>
          </ul>
        </div>
      </li>
    </ul>
  </div>
</section>
<!-- [assembleeGenerale] end-->