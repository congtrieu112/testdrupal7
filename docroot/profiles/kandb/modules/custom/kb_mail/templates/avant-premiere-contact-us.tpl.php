Bonjour 
Un visiteur du site <?php if(isset($mail_vars['kandb_base_url'])) {print $mail_vars['kandb_base_url']; } ?> s'est montré intéressé par une "avant première" et a souhaité laisser un message.
Ses coordonnées :
Nom : <?php if(isset($mail_vars['rdv_nom'])) {print $mail_vars['rdv_nom']; } ?>

Prénom : <?php if(isset($mail_vars['rdv_prenom'])) {print $mail_vars['rdv_prenom']; } ?>

Adresse : <?php if(isset($mail_vars['rdv_adresse1'])) {print $mail_vars['rdv_adresse1']; } ?>

<?php if(isset($mail_vars['rdv_adresse2'])) {print $mail_vars['rdv_adresse2']; } ?>
 

Ville : <?php if(isset($mail_vars['rdv_ville'])) {print $mail_vars['rdv_ville']; } ?> - <?php if(isset($mail_vars['rdv_lieudit'])) {print $mail_vars['rdv_lieudit']; } ?>

Code Postal : <?php if(isset($mail_vars['rdv_code_postal'])) {print $mail_vars['rdv_code_postal']; } ?>

Pays : 
E-mail : <?php if(isset($mail_vars['rdv_email'])) {print $mail_vars['rdv_email']; } ?>

Telephone : <?php if(isset($mail_vars['rdv_telephone'])) {print $mail_vars['rdv_telephone']; } ?>

Son message : <?php if(isset($mail_vars['rdv_message'])) {print $mail_vars['rdv_message']; } ?>

Origine Publicitaire : <?php if(isset($mail_vars['rdv_connu'])) {print $mail_vars['rdv_connu']; } ?>

L'avant première qui l'intéresse : 

<?php if(isset($mail_vars['avant_premiere_title'])) {print $mail_vars['avant_premiere_title']; } ?>

<?php if(isset($mail_vars['avant_premiere_ville'])) {print $mail_vars['avant_premiere_ville']; } ?><?php if(isset($mail_vars['avant_premiere_department'])) {print ' / ' . $mail_vars['avant_premiere_department']; } ?>

 

<?php if(isset($mail_vars['rdv_newsletter']) && $mail_vars['rdv_newsletter'] == TRUE) : ?>
Oui je souhaite recevoir les offres de KB
<?php endif;?>

Nous avons indiqué à cet internaute que vous le contacterez dans les meilleurs délais. Nous comptons sur vous. Cordialement, L'équipe internet Kaufman & Broad.
* Prix donné à titre indicatif