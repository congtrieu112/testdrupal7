<section class="section-padding presidentQuote">
  <div class="wrapper">
    <div class="presidentQuote__content">
      <div class="presidentQuote__img">
        <!-- images need to have square format:- 215 x 215 and have crop white circle -->
        <img alt="<?php echo htmlentities($kandb_finance_presentation_word_president_fonction_exercee); ?>" src="<?php echo $kandb_finance_presentation_word_president_image->uri; ?>" />
      </div>
      <div class="presidentQuote__quote">
        <blockquote>
          <p><?php echo $kandb_finance_presentation_word_president_citation; ?></p>
        </blockquote>
        <h3 class="presidentQuote__title"><?php echo $kandb_finance_presentation_word_president_identite; ?></h3>
        <span class="presidentQuote__sub"><?php echo $kandb_finance_presentation_word_president_fonction_exercee; ?></span>
        <div class="presidentQuote__cta">
          <a class="btn-primary btn-rounded" href="<?php echo $kandb_finance_presentation_word_president_link['url']; ?>" title="<?php echo htmlentities($kandb_finance_presentation_word_president_link['title']); ?>"><?php echo $kandb_finance_presentation_word_president_link['title']; ?></a>
        </div>
      </div>
    </div>
  </div>
</section>

<section class="section-padding graphicPresentation">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title">KPI</h1>
    </header>
    <?php
      $maxNbKPIFigure = (($countKPIFigure % 2) == 1)? $countKPIFigure-1 : $countKPIFigure;
    ?>
    <div class="graphicPresentation__list">
      <?php
        for ($i = 1; $i <= $maxNbKPIFigure; ++$i) {
          if (${'kandb_finance_presentation_kpi_title_'.$i} && ${'kandb_finance_presentation_kpi_sub_title_'.$i} && ${'kandb_finance_presentation_kpi_image_small_'.$i} && ${'kandb_finance_presentation_kpi_image_medium_'.$i}) {
            echo '<div class="graphicPresentation__item columns medium-6">';
            echo '<h4 class="graphicPresentation__item__heading">'.${'kandb_finance_presentation_kpi_title_'.$i}.'</h4>';
            echo '<p class="desc">'.${'kandb_finance_presentation_kpi_sub_title_'.$i}.'</p>';
            echo '<div class="graphicPresentation__item__img">';
            echo '<img data-interchange="['.${'kandb_finance_presentation_kpi_image_small_'.$i}->uri.', (small)], ['.${'kandb_finance_presentation_kpi_image_medium_'.$i}->uri.', (large)]" alt="test">';
            echo '<noscript><img alt="test" src="'.${'kandb_finance_presentation_kpi_image_medium_'.$i}->uri.'"></noscript>';
            echo '</div>'; // ending div.graphicPresentation__item__img
            echo '</div>'; // ending div.graphicPresentation__item.columns.medium-6
          }
        }
      ?>
    </div>
    <?php
      if ($maxNbKPIFigure != $countKPIFigure) {
        echo '<div class="graphicPresentation__list">';
        echo '<div class="graphicPresentation__item columns text-center">';
        echo '<h4 class="graphicPresentation__item__heading">'.${'kandb_finance_presentation_kpi_title_'.$maxNbKPIFigure}.'</h4>';
        echo '<p class="desc">'.${'kandb_finance_presentation_kpi_sub_title_'.$maxNbKPIFigure}.'</p>';
        echo '<div class="graphicPresentation__item__img">';
        echo '<img data-interchange="['.${'kandb_finance_presentation_kpi_image_small_'.$maxNbKPIFigure}->uri.', (small)], ['.${'kandb_finance_presentation_kpi_image_medium_'.$maxNbKPIFigure}->uri.', (large)]" alt="test">';
        echo '<noscript><img alt="test" src="'.${'kandb_finance_presentation_kpi_image_medium_'.$maxNbKPIFigure}->uri.'"></noscript>';
        echo '</div>'; // ending div.graphicPresentation__item__img
        echo '</div>'; // ending div.graphicPresentation__item.columns.text-center
        echo '</div>'; // ending div.graphicPresentation__list
      }
    ?>
  </div>
</section>

<section class="section-padding actionnaireCarnet bg-lightGrey">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title">Carnet de l'actionnaire</h1>
    </header>
    <div class="wrapper actionnaireCarnet__listInfor">
      <div class="inner">
        <div class="heading heading--small">
          <h1 class="heading__title"><?php echo $kandb_finance_presentation_carnet_market_data_title; ?></h1>
        </div>
        <dl class="actionnaireCarnet__listInfor__list">
          <?php
            // Rendu d'un champ de type Textarea (tableau de clés et de valeurs délimités par le caractère "|" ; ex : marché|NYSE EURONEXT)
            $dt_dd = array('dt', 'dd');
            foreach (explode("\n", $kandb_finance_presentation_carnet_market_data_textarea) as $lineString) {
              if (strpos($lineString, '|')) {
                $lineArr = (explode('|', $lineString));
                foreach ($lineArr as $key => $value) {
                  echo "<$dt_dd[$key]><p>".$value."</p></$dt_dd[$key]>";
                }
              } else {
                echo '<dt><p>'.$lineString.'</p></dt>';
              }
            }
          ?>
        </dl>
      </div>
    </div>
    <div class="wrapper actionnaireCarnet__listInfor">
      <div class="inner">
        <div class="heading heading--small">
          <h1 class="heading__title"><?php echo $kandb_finance_presentation_carnet_market_sheet_title; ?></h1>
        </div>
        <dl class="actionnaireCarnet__listInfor__list">
          <?php
            // Rendu d'un champ de type Textarea (tableau de clés et de valeurs délimités par le caractère "|" ; ex : marché|NYSE EURONEXT)
            $dt_dd = array('dt', 'dd');
            foreach (explode("\n", $kandb_finance_presentation_carnet_market_sheet_textarea) as $lineString) {
              if (strpos($lineString, '|')) {
                $lineArr = (explode('|', $lineString));
                foreach ($lineArr as $key => $value) {
                  echo "<$dt_dd[$key]><p>".$value."</p></$dt_dd[$key]>";
                }
              } else {
                echo '<dt><p>'.$lineString.'</p></dt>';
              }
            }
          ?>
        </dl>
      </div>
    </div>
  </div>
</section>