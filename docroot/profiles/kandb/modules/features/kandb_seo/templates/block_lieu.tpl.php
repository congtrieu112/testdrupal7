<div id="block_lieu" >
  <?php if(!empty($location)) : ?>
    <ul>
      <?php foreach ($location as $text => $url) : ?>
        <li>
          <a href="/<?php print $url; ?>" class="<?php print ($url == $selected ? 'active' : ''); ?>" ><?php print $text; ?></a>
        </li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</div>