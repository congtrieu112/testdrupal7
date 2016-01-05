<?php
print theme('group_durable_header');

global $base_url;
$title = $data['title'];
$resume = $data['resume'];
$content = $data['content'];
$path_image = $data['path_image'];
?>

<?php if($title || $resume || $content || $path_image) : ?>
<!-- [editorial Content Article] start-->
<article id="node-1" class="section-padding editorialContentArticle">
  <div class="wrapper">
    <?php if($title) : ?>
    <header class="heading heading--bordered heading--large">
      <h1 class="heading__title"><?php print $title; ?></h1>
    </header>
    <?php endif; ?>
    <?php if($resume) : ?>
    <p class="editorialContentArticle__content__hightlight">
      <?php print $resume; ?>
    </p>
    <?php endif; ?>
    <?php if($path_image || $content) : ?>
    <div class="row">
      <?php if($path_image) : ?>
      <figure class="editorialContentArticle__figure">
        <img src="<?php print $path_image; ?>" alt="<?php print $title; ?>"/>
      </figure>
      <?php endif; ?>
      <?php if($content && isset($content['value'])) : ?>
      <div class="editorialContentArticle__content">
        <?php print $content['value']; ?>
      </div>
      <?php endif; ?>
    </div>
    <?php endif; ?>
  </div>
</article>
<!-- [editorial Content Article] end-->
<?php endif; ?>