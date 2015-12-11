<pre>
  <?php
    // Affichage de toutes les variables disponibles
    echo '<p>kandb_finance_presentation_word_president_titre = '.$kandb_finance_presentation_word_president_titre.'<br/>';
    echo 'kandb_finance_presentation_word_president_citation = '.$kandb_finance_presentation_word_president_citation.'<br/>';
    echo 'kandb_finance_presentation_word_president_identite = '.$kandb_finance_presentation_word_president_identite.'<br/>';
    echo 'kandb_finance_presentation_word_president_fonction_exercee = '.$kandb_finance_presentation_word_president_fonction_exercee.'<br/>';
    echo 'kandb_finance_presentation_word_president_link = '; var_dump($kandb_finance_presentation_word_president_link); echo '</p>';
    for ($i = 1; $i <= 20; ++$i) {
        echo '<p>kandb_finance_presentation_kpi_title_'.$i.' = '.${'kandb_finance_presentation_kpi_title_'.$i}.'<br/>';
        echo 'kandb_finance_presentation_kpi_sub_title_'.$i.' = '.${'kandb_finance_presentation_kpi_sub_title_'.$i}.'<br/>';
        echo 'kandb_finance_presentation_kpi_image_'.$i.' = ';
        var_dump(${'kandb_finance_presentation_kpi_image_'.$i});
        echo '</p>';
    }
    echo '<p>kandb_finance_presentation_carnet_market_data_title = '.$kandb_finance_presentation_carnet_market_data_title.'<br/>';
    echo 'kandb_finance_presentation_carnet_market_data_textarea = '.$kandb_finance_presentation_carnet_market_data_textarea.'<br/>';
    echo 'kandb_finance_presentation_carnet_title_1 = '.$kandb_finance_presentation_carnet_title_1.'<br/>';
    echo 'kandb_finance_presentation_carnet_sub_title_1 = '.$kandb_finance_presentation_carnet_sub_title_1.'<br/>';
    echo 'kandb_finance_presentation_carnet_market_sheet_title = '.$kandb_finance_presentation_carnet_market_sheet_title.'<br/>';
    echo 'kandb_finance_presentation_carnet_market_sheet_textarea = '; var_dump($kandb_finance_presentation_carnet_market_sheet_textarea); echo '</p>';
  ?>
  <table>
    <?php
      // Rendu d'un champ de type Textarea (tableau de clés et de valeurs délimités par le caractère "|" ; ex : marché|NYSE EURONEXT)
      foreach (explode("\n", $kandb_finance_presentation_carnet_market_data_textarea) as $lineString) {
          echo '<tr>';
          if (strpos($lineString, '|')) {
              $lineArr = (explode('|', $lineString));
              foreach ($lineArr as $value) {
                  echo '<td>'.$value.'</td>';
              }
          } else {
              echo '<td>'.$lineString.'</td>';
          }
          echo '</tr>';
      }
    ?>
  </table>
</pre>
