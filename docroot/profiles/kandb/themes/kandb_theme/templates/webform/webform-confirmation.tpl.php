<?php
/**
 * @file
 * Customize confirmation screen after successful submission.
 *
 * This file may be renamed "webform-confirmation-[nid].tpl.php" to target a
 * specific webform e-mail on your site. Or you can leave it
 * "webform-confirmation.tpl.php" to affect all webform confirmations on your
 * site.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $progressbar: The progress bar 100% filled (if configured). This may not
 *   print out anything if a progress bar is not enabled for this node.
 * - $confirmation_message: The confirmation message input by the webform
 *   author.
 * - $sid: The unique submission ID of this submission.
 * - $url: The URL of the form (or for in-block confirmations, the same page).
 */
$page_name = '';
$webfrom_machine = $node->webform['machine_name'];
switch ($webfrom_machine) {
  case '_tre_rappel_':
    $page_name = TC_PAGE_NAME_RAPPELEZ;
    break;

  case 'prendre_rendez_vous':
    $page_name = TC_PAGE_NAME_PRENDRE;
    break;

  default:
    break;
}
?>
<?php if ($page_name): ?>
  <script>
    jQuery(document).ready(function () {
        console.log('<?php print $page_name; ?>'); // For debug page_name.
        tc_events_1(this, 'PAGE', {'page_level': '', 'page_name': '<?php print $page_name ?>'});
    });
  </script>
<?php endif; ?>

<?php print $progressbar; ?>

<div class="webform-confirmation">
    <?php if ($confirmation_message): ?>
      <?php print $confirmation_message; ?>
    <?php else: ?>
      <p><?php print t('Thank you, your submission has been received.'); ?></p>
    <?php endif; ?>
</div>