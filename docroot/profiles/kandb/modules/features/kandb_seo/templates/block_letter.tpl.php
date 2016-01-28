<!-- [searchResults] start-->
<section class="wrapper">
  <div class="noResults">
    <div class="noResults__category">
      <dl class="noResults__category__filter">
        <dt>Aller à :</dt>
        <dd>
          <nav class="form-dropdown form-dropdown--responsive">
            <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown="data-app-dropdown" data-app-dropdown-responsive="small-only" class="form-dropdown__trigger">Les actualités<span aria-hidden="true" class="icon icon-expand"></span></button>
            <div id="dropdown-downloadDocs" aria-hidden="true" class="form-dropdown__content hidden">
              <?php if(!empty($location)) : ?>
              <ul>
                <?php foreach ($location as $text => $url) : ?>
                  <li>
                    <a href="#list-<?php print $text; ?>" title="<?php print $text; ?>" class="<?php print ($url == $selected ? 'active' : ''); ?>" ><?php print $text; ?></a>
                  </li>
                <?php endforeach; ?>
              </ul>
              <?php endif; ?>
            </div>
          </nav>
        </dd>
      </dl>

      <?php
        if(arg(0) == 'regions') :
      ?>
      <div class="noResults__category__list">
        <ul>
          <ul class="small-block-grid-2 medium-block-grid-3">
            <?php if($collections) : ?>
              <?php foreach ($collections as $letter => $collection) : ?>
              <li>
                <dl>
                  <dt><?php print $letter; ?></dt>
                  <dd>
                    <ul>
                      <?php foreach ($collection as $ville_name) : ?>
                      <li><a href="/recherche?place=<?php print ucwords(strtolower($ville_name)); ?>" title="<?php print ucwords(strtolower($ville_name)); ?>"><?php print ucwords(strtolower($ville_name)); ?></a></li>
                      <?php endforeach; ?>
                    </ul>
                  </dd>
                </dl>
              </li>
              <?php endforeach; ?>
            <?php endif; ?>
          </ul>
        </ul>
      </div>
      <?php
        endif;
      ?>
    </div>
  </div>
</section>
<!-- [searchResults] end-->