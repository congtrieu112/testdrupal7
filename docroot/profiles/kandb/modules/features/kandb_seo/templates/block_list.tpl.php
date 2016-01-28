<section>
  <article>
    <div class="typeLogements wrapper">
      <div class="typeLogements__heading"></div>
      <?php if(!empty($results)) : ?>
        <?php foreach ($results as $letter => $objects) : ?>
        <div class="typeLogements__list bg-white" style="padding: 2px; margin: 2px">
            <dl>
                <dt id="list-<?php print strtolower($letter); ?>"><?php print strtoupper($letter); ?></dt>
              <?php foreach($objects as $object) : ?>
              <dt><?php print $object['name']; ?></dt>
              <dd>
                <ul>
                  <li><a href="/<?php print $location; ?>/programmes-immobiliers-neufs-<?php print $object['sanitize_name']; ?>" title="Programmes neufs à <?php print $object['name']; ?>">Programmes neufs <?php print $object['name']; ?></a></li>
                  <li><a href="/<?php print $location; ?>/logements-immobiliers-neufs-<?php print $object['sanitize_name']; ?><?php print (!empty($object['numero_departement']) ? '-' . $object['numero_departement'] : ''); ?>" title="Logements neufs à <?php print $object['name']; ?>">Logements neufs <?php print $object['name']; ?></a></li>
                </ul>
              </dd>
              <?php endforeach; ?>
            </dl>
          </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
  </article>
</section>