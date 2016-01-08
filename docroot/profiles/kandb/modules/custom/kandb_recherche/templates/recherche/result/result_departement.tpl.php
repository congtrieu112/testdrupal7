<div class="noResults">
  <div class="noResults__heading">
    <h2>Nous n'avons pas trouvé de résultats correspondant à votre recherche.</h2>
    <p>Trouvez votre logement dans le département de votre choix:</p>
  </div>
  <div class="noResults__category">
    <dl class="noResults__category__filter">
      <dt>Aller à :</dt>
      <dd>
        <nav class="form-dropdown form-dropdown--responsive">
          <div id="dropdown-downloadDocs" aria-hi          <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown="data-app-dropdown" data-app-dropdown-responsive="small-only" class="form-dropdown__trigger">Les actualités<span aria-hidden="true" class="icon icon-expand"></span></button>
dden="true" class="form-dropdown__content hidden">
            <ul>
              <?php
                $ancien_first_letter = false;
                foreach($departement as $dpt) {
                  $first_letter = substr($dpt['name'], 0 ,1);
                  if($ancien_first_letter != $first_letter) {
                    echo '<li><a href="#list-' . $first_letter . '" title="a">' . $first_letter . '</a></li>';
                    $ancien_first_letter = $first_letter;
                  }
                }
              ?>
            </ul>
          </div>
        </nav>
      </dd>
    </dl>
    <div class="noResults__category__list">
      <ul>
        <ul class="small-block-grid-2 medium-block-grid-3">

          <?php
            $ancien_first_letter = false;
            foreach($departement as $dpt) {
              $first_letter = substr($dpt['name'], 0 ,1);
              if($ancien_first_letter != $first_letter) {
                if($ancien_first_letter) echo '</ul></dd></dl></li>';
                echo '<li><dl><dt id="list-' . $first_letter . '">' . $first_letter . '</dt><dd><ul>';
                $ancien_first_letter = $first_letter;
              }
              echo '<li><a href="' . $dpt['link'] . '" title="' . $dpt['name'] . '">' . $dpt['name'] . '</a></li>';
            }
             echo '</ul></dd></dl></li>';
          ?>

        </ul>
      </ul>
    </div>
  </div>
</div>