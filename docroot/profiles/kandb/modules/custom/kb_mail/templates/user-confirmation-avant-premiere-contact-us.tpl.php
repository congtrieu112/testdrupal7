Bonjour <?php if(isset($mail_vars['rdv_prenom'])) {print $mail_vars['rdv_prenom']; } ?> <?php if(isset($mail_vars['rdv_nom'])) {print $mail_vars['rdv_nom']; } ?>, 

Nous avons bien reçu votre message et vous remercions de votre intérêt. Votre demande de rendez-vous a été transmise au conseiller commercial en charge du programme :

<?php if(isset($mail_vars['avant_premiere_title'])) {print $mail_vars['avant_premiere_title']; } ?>

<?php if(isset($mail_vars['avant_premiere_ville'])) {print $mail_vars['avant_premiere_ville']; } ?><?php if(isset($mail_vars['avant_premiere_department'])) {print ' / ' . $mail_vars['avant_premiere_department']; } ?>

Nous reviendrons vers vous dans les meilleurs délais.
Nous vous remercions de la confiance accordée à notre site et espérons vous revoir prochainement sur <?php if(isset($mail_vars['kandb_base_url'])) {print $mail_vars['kandb_base_url']; } ?>
Cordialement,
L'équipe Kaufman & Broad

Rappel de votre message : <?php if(isset($mail_vars['rdv_message'])) {print $mail_vars['rdv_message']; } ?>