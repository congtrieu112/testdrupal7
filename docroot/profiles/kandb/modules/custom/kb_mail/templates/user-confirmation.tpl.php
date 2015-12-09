<table border="0" cellpadding="0" cellspacing="0" width="600" align="center" bgcolor="#ffffff" style="width: 650px;">
    <tbody><tr>
            <td style="padding: 20px 40px;">
                <table border="0" cellpadding="0" cellspacing="0" width="100%">
                    <tbody><tr>
                            <td valign="middle"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail')); ?>/images/logo.png" alt="" width="173" height="13" style="border: none; display: block; width: 173px; height: 13px"></td>
                            <td valign="middle">
                                <table cellspacing="0" cellpadding="0" border="0" align="center" style="float:right">
                                    <tbody><tr>
                                            <td valign="top" style="padding: 0 10px"><a href="#" title="Nos offres" style="font-family: Helvetica, Arial, sans-serif; font-size: 11px; color: #199edd; text-decoration: none;">Nos offres</a>
                                            </td>
                                            <td valign="top" style="padding: 0 10px"><a href="#" title="Nos services" style="font-family: Helvetica, Arial, sans-serif; font-size: 11px; color: #869296; text-decoration: none;">Nos services</a>
                                            </td>
                                            <td valign="top" style="padding: 0 10px"><a href="#" title="Nos conseils" style="font-family: Helvetica, Arial, sans-serif; font-size: 11px; color: #869296; text-decoration: none;">Nos conseils</a>
                                            </td>
                                            <td valign="top" style="padding: 0 0 0 10px"><a href="#" title="Le groupe" style="font-family: Helvetica, Arial, sans-serif; font-size: 11px; color: #869296; text-decoration: none;">Le groupe</a>
                                            </td>
                                        </tr>
                                    </tbody>
                                </table>
                            </td>
                        </tr>
                    </tbody>
                </table>
            </td>
        </tr>
    </tbody>
</table>
<table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 650px; background-color: #fff;">
    <tbody>
        <tr>
            <td valign="middle"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail')); ?>/images/email-newsletter.jpg" alt="" width="650" height="216" style="border: none; display: block; width: 650px; height: 216px"></td>
        </tr>
    </tbody>
</table>
<table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 650px; padding: 0 38px;">
    <tbody>
        <tr>
            <td valign="top" style="padding: 0 38px;">
                <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%; background-color: #fff;">
                    <tbody>
                        <tr>
                            <td valign="top" style="padding: 0 20px;">
                                <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%;">
                                    <tbody>
                                        <tr>
                                            <td valign="top" style="padding: 0 13px;"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail')); ?>/images/title-border.jpg" alt="" width="100" height="15" style="border: none; display: block; width: 100px; height: 15px"></td>
                                        </tr>
                                        <tr>
                                            <td valign="top" style="padding: 0 13px;">
                                                <p style="margin: 0; font-family: Helvetica, Arial, sans-serif; font-size: 30px; color: #003e5e; line-height: 30px;">
                                                   <?php
                                                    if (isset($mail_vars['programme_loc_type'])) :
                                                      print $mail_vars['programme_loc_ville'] . ' ' . $mail_vars['programme_loc_department'];
                                                    endif;
                                                   ?>
                                                </p>
                                                <p style="margin: 0; font-family: Helvetica, Arial, sans-serif; font-size: 30px; color: #199edd; line-height: 30px;"><?php print $mail_vars['programme_title']; ?></p>
                                                <p style="margin: 0; padding-top: 18px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                                  Bonjour <?php print $mail_vars['rdv_prenom']; ?> <?php print $mail_vars['rdv_nom']; ?>,<br />
                                                  Nous avons bien reçu votre message et vous remercions de votre intérêt. Votre demande de rendez-vous a été transmise au conseiller commercial en charge du programme :<br />
                                                  <?php print $mail_vars['programme_title']; ?><br />
                                                  <?php print $mail_vars['programme_loc_type']; ?> <?php print $mail_vars['programme_loc_rue']; ?>
                                                </p>
                                                <?php if (isset($mail_vars['bien_lot_id']) &&  $mail_vars['bien_lot_id'] == 'A33') : ?>
                                                 <p style="margin: 0; padding-top: 18px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                                      <?php print $mail_vars['bien_type'];  ?> <?php print $mail_vars['bien_nb_pieces'];  ?> <?php print $mail_vars['bien_superficie'];  ?> Lot <?php print $mail_vars['bien_lot_id'];  ?>
                                                 </p>
                                                <?php endif ?>
                                                <p style="margin: 0; padding-top: 18px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                                    Nous reviendrons vers vous dans les meilleurs délais.
                                                </p>
                                                <p style="margin: 0; padding-top: 18px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                                    Nous vous remercions de la confiance accordée à notre site et espérons vous revoir prochainement sur <a href="http://www.ketb.com/" title="http://www.ketb.com/" style="font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; text-decoration: none;">http://www.ketb.com/</a>
                                                </p>
                                            </td>
                                        </tr>
                                    </tbody>
                                </table>
                            </td>
                        </tr>
                        <tr>
                            <td valign="top" style="padding: 0 30px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                <p style="margin: 0; padding-top: 20px;"> Cordialement,<br/>
                                  L'équipe Kaufman & Broad
                                </p>  
                                <p style="margin: 0; padding-top: 20px;">
                                  Rappel des coordonnées du conseiller commercial :<br />
                                  <?php print $mail_vars['programme_nom_conseiller']; ?><br />
                                  <?php print $mail_vars['programme_espace_vente_tel']; ?>
                                </p>
                                <p style="margin: 0; padding-top: 20px;">
                                  Bureau de vente :<br />
                                  <?php print $mail_vars['programme_espace_vente_adresse'];  ?><br />
                                  <?php print $mail_vars['programme_espace_vente_ville']; ?><br />
                                  Horaires d'ouverture : <?php print $mail_vars['programme_espace_vente_horaire']; ?>
                                </p>
                                <p style="margin: 0; padding-top: 20px;">
                                  Rappel de votre message : <?php print $mail_vars['rdv_message']; ?> 
                                </p>                                
                            </td>
                        </tr>
                        <tr>
                            <td valign="middle" style="padding: 15px 30px 25px 30px; border-top: 1px solid #a9bec8;">
                                <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%; font-family: Helvetica, Arial, sans-serif; font-size: 9px; color: #003e5e; line-height: 9px">
                                    <tbody>
                                        <tr>
                                            <td valign="middle" style="width: 167px;"><a href="#" title="http://www.ketb.com/" style="font-family: Helvetica, Arial, sans-serif; font-size: 9px; color: #003e5e; text-decoration: none;">http://www.ketb.com/</a>
                                            </td>
                                            <td valign="middle">
                                                <table cellspacing="0" cellpadding="0" border="0" align="center" style="float: left">
                                                    <tbody><tr>
                                                            <td valign="middle">
                                                                <p style="margin: 0 25px 0 0; font-size: 9px; line-height: 9px; text-transform: uppercase; color: #003e5e;">Suivez-nous sur</p>
                                                            </td>
                                                            <td valign="middle" style="padding-right: 10px"><a href="#"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail'));?>/images/icon-facebook.jpg" alt="" width="15" height="15" style="border: none; display: block; width: 15px; height: 15px"></a>
                                                            </td>
                                                            <td valign="middle" style="padding-right: 10px"><a href="#"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail'));?>/images/icon-twitter.jpg" alt="" width="15" height="15" style="border: none; display: block; width: 15px; height: 15px"></a>
                                                            </td>
                                                            <td valign="middle" style="padding-right: 10px"><a href="#"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail'));?>/images/icon-youtube.jpg" alt="" width="15" height="15" style="border: none; display: block; width: 15px; height: 15px"></a>
                                                            </td>
                                                        </tr>
                                                    </tbody>
                                                </table>
                                            </td>
                                        </tr>
                                    </tbody>
                                </table>
                            </td>
                        </tr>
                    </tbody>
                </table>
            </td>
        </tr>
    </tbody>
</table>
