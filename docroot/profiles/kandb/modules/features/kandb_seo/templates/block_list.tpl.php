<div id="block_list" >
  <?php if(!empty($results)) : ?>
    <ul>
      <?php foreach ($results as $object) : ?>
        <li>
          <span><?php print $object['name']; ?></span>
          <a href="/<?php print $location; ?>/programmes-immobiliers-neufs-<?php print $object['sanitize_name']; ?>" >Programmes neufs à <?php print $object['name']; ?></a>
          <a href="/<?php print $location; ?>/logements-immobiliers-neufs-<?php print $object['sanitize_name']; ?>-<?php print $object['numero_departement']; ?>" >Logements neufs à <?php print $object['name']; ?></a>
        </li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</div>