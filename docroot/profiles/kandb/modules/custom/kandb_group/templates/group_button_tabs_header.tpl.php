<?php
global $user;
if (in_array('Administrateur Général', $user->roles)):
  if(!empty($path)) :
  $url = 'admin/content/ketb/'.$path;
  $destination_path = !empty($destination)? $destination: $path;
  ?>
  <div class="tabs">
    <ul class="programCharacteristics__nav" style="margin:5px 0px; text-align:left;position:relative;">
      <li>
        <a href="<?php print url($url) . '?destination='.$destination_path ?>" class="test" style="margin:0px;">
          <?php print t('Edit'); ?>
        </a>
      </li>
    </ul>
  </div>
<?php
endif;
endif; ?>