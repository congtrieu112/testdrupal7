<div class="main-wrapper">

    <?php print render($page['header']); ?>

    <main id="container">
        <?php print render($page['content']); ?>
    </main>

    <?php print render($page['footer']); ?>

    <!-- [popinLeadForm popin] start-->
    <div id="popinLeadForm" data-reveal="data-reveal" aria-hidden="true" role="dialog" data-drupal-form="data-drupal-form" class="reveal-modal full scroll"></div>
    <!-- [popinLeadForm popin] end-->
</div>