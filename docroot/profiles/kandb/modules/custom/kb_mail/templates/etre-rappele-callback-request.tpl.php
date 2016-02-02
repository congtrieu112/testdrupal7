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
                                            <td valign="top" style="padding: 0 13px;"><img src="<?php print file_create_url(drupal_get_path('module', 'kb_mail'));?>/images/title-border.jpg" alt="" width="100" height="15" style="border: none; display: block; width: 100px; height: 15px"></td>
                                        </tr>
                                        <tr>
                                            <td valign="top" style="padding: 0 13px;">
                                                <p style="margin: 0; font-family: Helvetica, Arial, sans-serif; font-size: 30px; color: #003e5e; line-height: 30px;">
                                                    <?php
                                                      if (isset($mail_vars['programme_loc_type']) && !$mail_vars['bien_lot_id'] ) :
                                                        print $mail_vars['programme_loc_ville'] . ' ' . $mail_vars['programme_loc_department']. "<br />";
                                                      endif;
                                                   ?>
                                                </p>
                                                <p style="margin: 0; font-family: Helvetica, Arial, sans-serif; font-size: 30px; color: #199edd; line-height: 30px;"><?php print $mail_vars['programme_title']; ?></p>
                                                <p style="margin: 0; padding-top: 55px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 12px;">Bonjour,</p>
                                                <p style="margin: 0; padding-top: 18px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">Un visiteur du site "Kaufman & Broad" a souhaité être rappelé par un télé-acteur:
                                                </p>
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
                                                                            <td valign="top" style="padding: 0 10px;">
                                                                                <p style="margin: 0; padding-bottom: 20px; font-family: Helvetica, Arial, sans-serif; font-size: 20px; color: #199edd; line-height: 20px;">Ses coordonnées</p>
                                                                            </td>
                                                                        </tr>
                                                                        <tr>
                                                                            <td valign="top" style="width: 50%; margin: 0; padding: 0 0 25px 10px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">

                                                                               <p style="margin: 0;">Langue&nbsp;: <span style="text-transform: uppercase;"><?php print t('FR'); ?></span></p>
                                                                                <p style="margin: 0;">Nom&nbsp;: <span style="text-transform: uppercase;"><?php if (isset($mail_vars['rappeler_nom'])) : print $mail_vars['rappeler_nom']; endif; ?></span>
                                                                                </p>
                                                                                <p style="margin: 0;">Prénom&nbsp;: <span style="text-transform: uppercase;"><?php if (isset($mail_vars['rappeler_prenom'])) : print $mail_vars['rappeler_prenom']; endif; ?></span>
                                                                                </p>
                                                                                <p style="margin: 0;">Téléphone&nbsp;: <span style="text-transform: uppercase;"><?php if (isset($mail_vars['rappeler_telephone'])) : print $mail_vars['rappeler_telephone']; endif; ?></span>
                                                                                </p>

                                                                                <?php if ($mail_vars['rappeler_horaire'] ) : ?>
                                                                                  <p style="margin: 0;">Date et heure à laquelle il souhaite être contacté&nbsp;: <br />
                                                                                    <?php print $mail_vars['rappeler_horaire']; ?><br />
                                                                                  </p>
                                                                                <?php endif; ?>
                                                                            </td>

                                                                        </tr>
                                                                    </tbody>
                                                                </table>
                                                                <table cellspacing="0" cellpadding="0" border="0" align="center" style="width: 100%;">
                                                                    <tbody>
                                                                        <tr>
                                                                            <td valign="top" style="padding: 0 10px;">
                                                                                <p style="margin: 0; padding: 20px 0; font-family: Helvetica, Arial, sans-serif; font-size: 20px; color: #199edd; line-height: 20px;">
                                                                                  <?php if (!empty($mail_vars['tre_rappel_title'])): ?>
                                                                                    La page d’origine
                                                                                  <?php else: ?>
                                                                                    Le programme qui l'intéress :
                                                                                  <?php endif; ?>

                                                                                </p>
                                                                            </td>
                                                                        </tr>
                                                                        <tr>
                                                                            <td valign="top" style="margin: 0; padding: 0 10px; font-family: Helvetica, Arial, sans-serif; font-size: 12px; color: #003e5e; line-height: 25px;">
                                                                              <?php if (!empty($mail_vars['tre_rappel_title'])): ?>
                                                                                <p style="margin: 0;"><?php print $mail_vars['tre_rappel_title']; ?></p>
                                                                              <?php else: ?>
                                                                                <p style="margin: 0;">

                                                                                  <?php print isset($mail_vars['programme_title']) ? $mail_vars['programme_title'] : ""; ?><br>
                                                                                  <?php if ($mail_vars['programme_loc_ville'] && $mail_vars['programme_loc_department']) : ?>
                                                                                    <?php print $mail_vars['programme_loc_ville']; ?> -  <?php print $mail_vars['programme_loc_department']; ?>
                                                                                  <?php endif; ?>
                                                                                </p>

                                                                                <p style="margin: 0;">IDKP&nbsp;: <span style="text-transform: uppercase;"><?php if (isset($mail_vars['programme_idkp'])) : print $mail_vars['programme_idkp'];
                                                                                endif; ?></span>
                                                                                </p>

                                                                                  <?php if ($mail_vars['bien_lot_id']) : ?>
                                                                                  <p style="margin: 0;">

                                                                                  <?php print $mail_vars['bien_type']; ?> <?php print $mail_vars['bien_nb_pieces'] ?> <?php print $mail_vars['bien_superficie']; ?> Lot <?php print $mail_vars['bien_lot_id']; ?>
                                                                                  </p>
                                                                                <?php endif; ?>
                                                                              <?php endif; ?>


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
                                <p style="margin: 0; padding-top: 20px;">
                                    Cordialement. <p></p>
                                    &nbsp;L'équipe internet Kaufman &amp; Board
                                </p>
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
