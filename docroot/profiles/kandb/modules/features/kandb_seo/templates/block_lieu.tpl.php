<?php if(!empty($location)) : ?>
<section>
  <article>
    <div class="typeLogements wrapper">
      <div class="typeLogements__heading"></div>
      <div class="typeLogements__list bg-white" style="padding: 2px; margin: 2px">
        <ul>
          <?php foreach ($location as $text => $url) : ?>
          <li>
            <a href="/<?php print $url; ?>" class="<?php print ($url == $selected ? 'active' : ''); ?>" ><?php print $text; ?></a>
          </li>
          <?php endforeach; ?>
        </ul>
      </div>
    </div>
  </article>
</section>
<?php endif; ?>