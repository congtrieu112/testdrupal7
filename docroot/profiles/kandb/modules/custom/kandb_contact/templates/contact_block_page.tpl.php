<!-- [contactUs generic] start-->
<aside class="contactUs section-padding contactUs-generic">
  <div style="background-image: url('<?php print $content['kandb_contact_photo']->uri; ?>')" class="contactUs__img show-for-medium-up"></div>
  <div class="wrapper">
    <div class="contactUs__informations">
      <div class="small-wrapper">
        <p class="contactUs__informations__heading"><?php print  $content['kandb_contact_title']; ?></p>
        <p class="contactUs__informations__text"><?php print  $content['kandb_contact_sub_title']; ?></p>
        <div class="contactUs__informations__cta"><a href="tel://<?php print  $content['kandb_contact_numero_vert']; ?>" class="btn-phone-green"><span><?php print $content['kandb_contact_numero_text']; ?></span> <?php print $content['kandb_contact_numero_vert']; ?></a><a href="<?php print $content['kandb_contact_faq_link']; ?>" class="btn-white"><?php print $content['kandb_contact_faq_text']; ?><span class="icon icon-arrow"></span></a></div>
      </div>
    </div>
    <?php echo $content['buttons']; ?>
  </div>
</aside>
<!-- [contactUs generic] end-->