<div id="block_list_type" >
  <?php if(!empty($results)) : ?>
    <ul>
      <?php foreach ($results as $type => $pieces) : ?>
        <li>
          <span><?php print $type; ?></span>
          <ul>
            <?php foreach ($pieces as $piece) : ?>
              <li><a href="/<?php print current_path(); ?>/achat-<?php print $sanitized_strings[$type]; ?>-<?php print $sanitized_strings[$piece]; ?>" ><?php print $type; ?> <?php print $piece; ?></a></li>
            <?php endforeach; ?>
          </ul>
        </li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</div>