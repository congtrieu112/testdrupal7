<!-- [searchResults] start-->
<?php if(!empty($location)) : ?>
  <dl class="noResults__category__filter">
    <dt>Aller à :</dt>
    <dd>
      <nav class="form-dropdown form-dropdown--responsive">
        <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown="data-app-dropdown" data-app-dropdown-responsive="small-only" class="form-dropdown__trigger"><span class="text">Les actualités</span><span aria-hidden="true" class="icon icon-expand"></span></button>
        <div id="dropdown-downloadDocs" aria-hidden="true" class="form-dropdown__content hidden">
          <ul>
          <?php foreach ($location as $text => $url) : ?>
            <li><a href="#list-<?php print $text; ?>" title="<?php print $text; ?>" data-app-dropdown-close="data-app-dropdown-close"><?php print $text; ?></a></li>
          <?php endforeach; ?>
          </ul>
        </div>
      </nav>
    </dd>
  </dl>
<?php endif; ?>
<!-- [searchResults] end-->
