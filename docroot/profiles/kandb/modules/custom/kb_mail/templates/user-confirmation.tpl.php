Bonjour <?php if(isset($mail_vars['rdv_prenom'])) {print $mail_vars['rdv_prenom']; } ?> <?php if(isset($mail_vars['rdv_nom'])) {print $mail_vars['rdv_nom']; } ?>, 
Nous avons bien reçu votre message et vous remercions de votre intérêt. Votre demande de rendez-vous a été transmise au conseiller commercial en charge du programme :
<?php if(isset($mail_vars['programme_title'])) {print $mail_vars['programme_title']; } ?>

<?php if(isset($mail_vars['programme_loc_type'])) {print $mail_vars['programme_loc_type']; } ?> <?php if(isset($mail_vars['programme_loc_rue'])) {print $mail_vars['programme_loc_rue']; } ?>

<?php if(isset($mail_vars['bien_type'])) {print $mail_vars['bien_type']; } ?> <?php if(isset($mail_vars['bien_nb_pieces'])) {print $mail_vars['bien_nb_pieces']; } ?> <?php if(isset($mail_vars['bien_superficie'])) {print $mail_vars['bien_superficie']; } ?> <?php if(isset($mail_vars['bien_lot_id']) && $mail_vars['bien_lot_id'] != '') {print 'Lot ' . $mail_vars['bien_lot_id']; } ?>

Nous reviendrons vers vous dans les meilleurs délais.
Nous vous remercions de la confiance accordée à notre site et espérons vous revoir prochainement sur <?php if(isset($mail_vars['kandb_base_url'])) {print $mail_vars['kandb_base_url']; } ?> 
Cordialement,
L'équipe Kaufman & Broad
Rappel des coordonnées du conseiller commercial :
<?php if(isset($mail_vars['programme_nom_conseiller'])) {print $mail_vars['programme_nom_conseiller']; } ?>

<?php if(isset($mail_vars['programme_espace_vente_tel'])) {print $mail_vars['programme_espace_vente_tel']; } ?>

Bureau de vente :
<?php if(isset($mail_vars['programme_espace_vente_adresse'])) {print $mail_vars['programme_espace_vente_adresse']; } ?>

<?php if(isset($mail_vars['programme_espace_vente_ville'])) {print $mail_vars['programme_espace_vente_ville']; } ?>

Horaires d'ouverture : <?php if(isset($mail_vars['programme_espace_vente_horaire'])) {print $mail_vars['programme_espace_vente_horaire']; } ?>
Rappel de votre message : <?php if(isset($mail_vars['rdv_message'])) {print $mail_vars['rdv_message']; } ?>