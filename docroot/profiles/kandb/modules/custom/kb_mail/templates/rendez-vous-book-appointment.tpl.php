Bonjour 
Un visiteur du site <?php if(isset($mail_vars['kandb_base_url'])) {print $mail_vars['kandb_base_url']; } ?> s'est montré intéréssé par un logement et souhaite que vous le contactiez pour prendre rendez-vous.
Ses coordonnées :
Nom : <?php if(isset($mail_vars['rdv_nom'])) {print $mail_vars['rdv_nom']; } ?>

Prénom : <?php if(isset($mail_vars['rdv_prenom'])) {print $mail_vars['rdv_prenom']; } ?>

Adresse : <?php if(isset($mail_vars['rdv_adresse1'])) {print $mail_vars['rdv_adresse1']; } ?>

<?php if(isset($mail_vars['rdv_adresse2'])) {print $mail_vars['rdv_adresse2']; } ?>

Ville : <?php if(isset($mail_vars['rdv_ville'])) {print $mail_vars['rdv_ville']; } ?> - <?php if(isset($mail_vars['rdv_lieudit'])) {print $mail_vars['rdv_lieudit']; } ?>

Code Postal : <?php if(isset($mail_vars['rdv_code_postal'])) {print $mail_vars['rdv_code_postal']; } ?>

Pays : <?php if(isset($mail_vars['rdv_pays'])) {print $mail_vars['rdv_pays']; } ?>

E-mail : <?php if(isset($mail_vars['rdv_email'])) {print $mail_vars['rdv_email']; } ?>

Telephone : <?php if(isset($mail_vars['rdv_telephone'])) {print $mail_vars['rdv_telephone']; } ?>

Son message : <?php if(isset($mail_vars['rdv_message'])) {print $mail_vars['rdv_message']; } ?>

Origine Publicitaire : <?php if(isset($mail_vars['rdv_connu'])) {print $mail_vars['rdv_connu']; } ?>


Le programme qui l'intéresse : 
<?php if(isset($mail_vars['programme_title'])) {print $mail_vars['programme_title']; } ?>

<?php if(isset($mail_vars['programme_loc_type'])) {print $mail_vars['programme_loc_type']; } ?> <?php if(isset($mail_vars['programme_loc_rue'])) {print $mail_vars['programme_loc_rue']; } ?>

<?php if((isset($mail_vars['bien_type']) AND $mail_vars['bien_type']) OR
  (isset($mail_vars['bien_nb_pieces']) AND $mail_vars['bien_nb_pieces']) OR 
  (isset($mail_vars['bien_superficie']) AND $mail_vars['bien_superficie']) OR 
  (isset($mail_vars['bien_lot_id']) AND $mail_vars['bien_lot_id'])) : ?>
Le bien qui l'intéresse :  
<?php endif; ?> 
<?php if(isset($mail_vars['bien_type']) AND $mail_vars['bien_type']) {print $mail_vars['bien_type']; } ?> 
<?php if(isset($mail_vars['bien_nb_pieces']) AND $mail_vars['bien_nb_pieces']) {print $mail_vars['bien_nb_pieces']; } ?> 
<?php if(isset($mail_vars['bien_superficie']) AND $mail_vars['bien_superficie']) {print $mail_vars['bien_superficie']; } ?> 
<?php if(isset($mail_vars['bien_lot_id']) && $mail_vars['bien_lot_id'] != '') {print 'Lot ' . $mail_vars['bien_lot_id']; } ?>

<?php if(isset($mail_vars['rdv_newsletter']) && $mail_vars['rdv_newsletter'] == TRUE) : ?>
Oui je souhaite recevoir les offres de KB
<?php endif;?>


Nous avons indiqué à cet internaute que vous le contacterez dans les meilleurs délais. Nous comptons sur vous. Cordialement, L'équipe internet Kaufman & Broad.
* Prix donné à titre indicatif
