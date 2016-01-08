<!-- [searchFormular main] start-->
<?php echo render($block_form); ?>
<!-- [searchFormular main] end-->
<!-- [searchResults] start-->
<section class="wrapper">
  <?php if($isThereAResult): ?>
    <div class="results">
      <figure class="results__map show-for-medium-up">
        <div data-gmaps="addMarkers" class="gmaps js-app-gmaps"></div>
      </figure>
      <div class="results__list">
        <?php echo $result; ?>
      </div>
    </div>
  <?php else: ?>
    <?php print $result; ?>
  <?php endif; ?>
</section>
<!-- [searchResults] end-->