<?php if(!empty($results)) : ?>
  <div class="noResults__category__list">
    <ul class="small-block-grid-2 medium-block-grid-3">
      <?php foreach ($results as $letter => $objects) : ?>
        <li id="list-<?php print strtolower($letter); ?>">
          <dl>
            <dt><?php print strtolower($letter); ?></dt>
            <dd>
              <?php foreach($objects as $object) : ?>
                <div class="heading heading--small">
                  <div class="heading__title"><?php print $object['name']; ?></div>
                </div>
                <ul>
                  <li><a href="/<?php print $location; ?>/programmes-immobiliers-neufs-<?php print $object['sanitize_name']; ?>" title="Programmes neufs à <?php print $object['name']; ?>">Programmes neufs <?php print $object['name']; ?></a></li>
                  <li><a href="/<?php print $location; ?>/logements-immobiliers-neufs-<?php print $object['sanitize_name']; ?><?php print (!empty($object['numero_departement']) ? '-' . $object['numero_departement'] : ''); ?>" title="Logements neufs à <?php print $object['name']; ?>">Logements neufs <?php print $object['name']; ?></a></li>
                </ul>
              <?php endforeach; ?>
            </dd>
          </dl>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>
