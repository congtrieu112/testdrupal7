Bonjour
Un visiteur du site "Kaufman & Broad" a souhaité être rappelé par un télé-acteur :
 
Ses coordonnées :
Langue : FR
Nom : <?php if(isset($mail_vars['rappeler_nom'])) {print $mail_vars['rappeler_nom']; } ?>

Prénom : <?php if(isset($mail_vars['rappeler_prenom'])) {print $mail_vars['rappeler_prenom']; } ?>

Téléphone : <?php if(isset($mail_vars['rappeler_telephone'])) {print $mail_vars['rappeler_telephone']; } ?>

Date et heure à laquelle il souhaite être contacté : <?php if(isset($mail_vars['rappeler_horaire'])) {print $mail_vars['rappeler_horaire']; } ?>
 
Le programme qui l'intéresse :

<?php if(isset($mail_vars['programme_title'])) {print $mail_vars['programme_title']; } ?>

<?php if(isset($mail_vars['programme_loc_ville'])) {print $mail_vars['programme_loc_ville']; } ?>  - <?php if(isset($mail_vars['programme_loc_department'])) {print $mail_vars['programme_loc_department']; } ?>

IDKP : <?php if(isset($mail_vars['programme_idkp'])) {print $mail_vars['programme_idkp']; } ?>

<?php if(isset($mail_vars['bien_type'])) {print $mail_vars['bien_type']; } ?> <?php if(isset($mail_vars['bien_nb_pieces'])) {print $mail_vars['bien_nb_pieces']; } ?> <?php if(isset($mail_vars['bien_superficie'])) {print $mail_vars['bien_superficie']; } ?> <?php if(isset($mail_vars['bien_lot_id']) && $mail_vars['bien_lot_id'] != '') {print 'Lot ' . $mail_vars['bien_lot_id']; } ?>
 
Cordialement,
L'équipe internet Kaufman & Broad.
