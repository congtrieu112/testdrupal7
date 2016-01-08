<?php print render($title_prefix); ?>
<?php if ($title): ?>
  <div class="heading heading--bordered heading--small">
    <div class="heading__title"><?php print $title; ?></div>
  </div>
<?php endif; ?>
<?php print render($title_suffix); ?>
<?php print render($page['content']); ?>