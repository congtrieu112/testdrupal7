<?php
print theme('group_rh_header');
?>

<?php
  echo variable_get('rh_postuler_title'). "<br/>";
  echo variable_get('rh_postuler_sub_title'). "<br/>";
  echo variable_get('rh_postuler_title_paragraph'). "<br/>";
  echo variable_get('rh_postuler_text_paragraph'). "<br/>";
  echo variable_get('rh_postuler_button_paragraph'). "<br/>";
  echo variable_get('rh_last_offer_title'). "<br/>";
  echo variable_get('rh_postuler_form_button'). "<br/>";
?>
<?php print $view; ?>
