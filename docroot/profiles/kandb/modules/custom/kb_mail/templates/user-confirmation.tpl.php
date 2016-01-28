<table border="0" cellpadding="0" cellspacing="0" width="600" align="center" bgcolor="#ffffff" style="width: 650px;">
    <tbody><tr>
            <td style="padding: 20px 40px;">
                <table border="0" cellpadding="0" cellspacing="0" width="100%">
                    <tbody><tr>
                            <td valign="middle"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail'));?>/images/logo.png" alt="" width="173" height="13" style="border: none; display: block; width: 173px; height: 13px"></td>
                            <td valign="middle">
                                <table cellspacing="0" cellpadding="0" border="0" align="center" style="float:right">
                                    <tbody>
                                        <tr>
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
                    </tbody></table>
            </td>
        </tr>
    </tbody>
</table>
<table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 650px; background-color: #fff;">
    <tbody>
        <tr>
            <td valign="middle"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail'));?>/images/email-newsletter.jpg" alt="" width="650" height="216" style="border: none; display: block; width: 650px; height: 216px"></td>
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
                            <p style="margin: 0; padding-top: 55px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 12px;">Bonjour <?php print $mail_vars['rdv_prenom']; ?> <?php print $mail_vars['rdv_nom']; ?>,</p>
                            <p style="margin: 0; padding-top: 18px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">Nous avons bien reçu votre message et vous remercions de votre intérêt. Votre demande de rendez-vous a été transmise au conseiller commercial en charge du programme :</p>
                          </td>
                        </tr>
                        <tr>
                          <td valign="top" style="padding-top: 27px;">
                            <table cellspacing="0" cellpadding="0" border="0" bgcolor="#f2f5f6" align="center" style="width: 100%; background-color: #f2f5f6;">
                              <tbody>
                                <tr>
                                  <td valign="top" style="padding: 30px;">
                                    <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%; border-bottom: 1px solid #a9bec8;">
                                      <tbody>
                                        
                                        <tr>
                                          <td valign="top" style="width: 50%; margin: 0; padding: 0 0 25px 10px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                            <p style="margin: 0;"><span style="text-transform: uppercase;"> <?php print $mail_vars['programme_title']; ?></span>
                                            </p>
                                            <p style="margin: 0;"><?php print $mail_vars['programme_loc_type']; ?> <?php print $mail_vars['programme_loc_rue']; ?></p>
                                            
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
                <tr>
                    <td valign="top" style="padding: 0 30px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                        <p style="margin: 0; padding-top: 20px;">Nous reviendrons vers vous dans les meilleurs délais.</p>
                        <p style="margin: 0; padding-top: 20px;">NNous vous remercions de la confiance accordée à notre site et espérons vous revoir prochainement sur <a href="<?php print isset($mail_vars['kandb_base_url']) ? $mail_vars['kandb_base_url'] : ''; ?>" title="<?php print isset($mail_vars['kandb_base_url']) ? $mail_vars['kandb_base_url'] : ''; ?>" style="font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; text-decoration: none;"><?php print isset($mail_vars['kandb_base_url']) ? $mail_vars['kandb_base_url'] : ''; ?></a></p>
                        <p style="margin: 0; padding-top: 20px;">
                            Cordialement,<br>
                            L'équipe Kaufman &amp; Broad
                        </p>
                        <p style="margin: 0; padding: 15px 0 20px; font-size: 12px;">Rappel des coordonnées du conseiller commercial :</p>
                    </td>
                </tr>
                <tr>
                    <td valign="top" style="padding: 0 20px;">
                        <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%;">
                            <tbody>
                                <tr>
                                    <td valign="top" style="padding-bottom: 20px;">
                                        <table cellspacing="0" cellpadding="0" border="0" bgcolor="#f2f5f6" align="center" style="width: 100%;">
                                            <tbody>
                                                <tr>
                                                    <td valign="top" style="padding: 30px;">
                                                        <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%;">
                                                            <tbody>
                                                                <tr>
                                                                    <td valign="top" style="width: 50%; margin: 0; padding: 0 0 25px 10px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                                                        <p style="margin: 0;"><span style="text-transform: uppercase;"><?php print $mail_vars['programme_nom_conseiller']; ?></span>
                                                                        </p>
                                                                        <p style="margin: 0;"><?php print $mail_vars['programme_espace_vente_tel']; ?></p>
                                                                        <p style="margin: 0;">Bureau de vente :</p>
                                                                        <p style="margin: 0;"><?php print $mail_vars['programme_espace_vente_adresse']; ?></p><p style="margin: 0;"><span style="text-transform: uppercase;"><?php print $mail_vars['programme_espace_vente_ville']; ?></span></p>
                                                                        <p style="margin: 0;">Horaires d'ouverture :</p><p style="margin: 0;"><?php print $mail_vars['programme_espace_vente_horaire']; ?></p>
                                                                        <p style="margin: 0;">Rappel de votre message :</p><p style="margin: 0;"> <?php print $mail_vars['rdv_message']; ?></p>
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
                <tr>
                  <td valign="middle" style="padding: 15px 30px 25px 30px; border-top: 1px solid #a9bec8;">
                    <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%; font-family: Helvetica, Arial, sans-serif; font-size: 9px; color: #003e5e; line-height: 9px">
                      <tbody>
                        <tr>
                          <td valign="middle" style="width: 167px;"><a href="#" title="<?php print isset($mail_vars['kandb_base_url']) ? $mail_vars['kandb_base_url'] : ''; ?>" style="font-family: Helvetica, Arial, sans-serif; font-size: 9px; color: #003e5e; text-decoration: none;"><?php print isset($mail_vars['kandb_base_url']) ? $mail_vars['kandb_base_url'] : ''; ?></a>
                          </td>
                          <td valign="middle">
                              <table cellspacing="0" cellpadding="0" border="0" align="center" style="float: left">
                                  <tbody><tr>
                                          <td valign="middle">
                                              <p style="margin: 0 25px 0 0; font-size: 9px; line-height: 9px; text-transform: uppercase; color: #003e5e;">Suivez-nous sur</p>
                                          </td>
                                          <td valign="middle" style="padding-right: 10px"><a href="#" title="undefined"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail')); ?>/images/icon-facebook.jpg" alt="" width="15" height="15" style="border: none; display: block; width: 15px; height: 15px"></a>
                                          </td>
                                          <td valign="middle" style="padding-right: 10px"><a href="#" title="undefined"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail')); ?>/images/icon-twitter.jpg" alt="" width="15" height="15" style="border: none; display: block; width: 15px; height: 15px"></a>
                                          </td>
                                          <td valign="middle" style="padding-right: 10px"><a href="#" title="undefined"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail')); ?>/images/icon-youtube.jpg" alt="" width="15" height="15" style="border: none; display: block; width: 15px; height: 15px"></a>
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