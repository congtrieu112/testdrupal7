<?php
$count = 0;
if ($region_contents && isset($region_contents['node'])) :
  foreach ($region_contents['node'] as $region) :
    $region_nid = isset($region->nid) ? $region->nid : '';
    if ($region_nid) :
      $n_region = node_load($region_nid);
      if ($n_region):
        $region_kb_id = $n_region->field_region_kb_id[LANGUAGE_NONE][0]['value'];
        $html = '';
        for ($i = 1; $i <= 5; $i++) :
          if ($arg == 'nos-services') :
            $field_addr = 'field_kb_service' . $i . '_address';
            $field_email = 'field_kb_service' . $i . '_email';
            $field_telephone = 'field_kb_service' . $i . '_telephone';
          elseif ($arg == 'nos-showroom') :
            $field_addr = 'field_kb_showroom' . $i . '_address';
            $field_email = 'field_kb_showroom' . $i . '_email';
            $field_telephone = 'field_kb_showroom' . $i . '_telephone';
          else :
            $field_addr = 'field_kb_agence' . $i . '_address';
            $field_email = 'field_kb_agence' . $i . '_email';
            $field_telephone = 'field_kb_agence' . $i . '_telephone';
          endif;
          $arr_field_addr = isset($n_region->$field_addr) ? $n_region->$field_addr : array();
          $arr_field_email = isset($n_region->$field_email) ? $n_region->$field_email : array();
          $arr_field_telephone = isset($n_region->$field_telephone) ? $n_region->$field_telephone : array();
          $addr = isset($arr_field_addr[LANGUAGE_NONE][0]['value']) ? $arr_field_addr[LANGUAGE_NONE][0]['value'] : '';
          $email = isset($arr_field_email[LANGUAGE_NONE][0]['value']) ? $arr_field_email[LANGUAGE_NONE][0]['value'] : '';
          $telephone = isset($arr_field_telephone[LANGUAGE_NONE][0]['value']) ? $arr_field_telephone[LANGUAGE_NONE][0]['value'] : '';
          if ($addr && ($email || $telephone)) :
            $html .= '<li>';
            $html .= '<div class="counselors__infor">';
            $html .= '<a href="javascript:void(0)" class="mail"><span>' . $addr . '</span><span class="icon icon-marker"></span></a>';
            $html .= '</div>';
            if ($email):
              $html .= '<div class="counselors__infor">';
              $html .= '<a href="mailto:' . $email . '" class="mail"><span>' . $email . '</span><span class="icon icon-email"></span></a>';
              $html .= '</div>';
            endif;
            if ($telephone) :
              $html .= '<div class="counselors__infor">';
              $html .= '<a href="tel:' . $telephone . '" class="phone"><span>' . $telephone . '</span><span class="icon icon-tel"></span></a>';
              $html .= '</div>';
            endif;
            $html .= '</li>';
          endif;
        endfor;
        if ($html): ?>
          <li id="<?php print $region_kb_id; ?>">
            <a href="#<?php print $region_kb_id; ?>" data-app-accordion-link data-contact-map-section='<?php print $region_kb_id; ?>' class="accordion__link <?php print ($count == 0) ? 'active' : ''; ?>">
              <?php print ($n_region->title) ? $n_region->title : ''; ?>
              <span class="display-status"></span>
            </a>
            <article data-app-accordion-content class="heading--small">
              <ul class="counselors">
                <?php print $html; ?>
              </ul>
            </article>
          </li>
          <?php
          $count++;
        endif;
      endif;
    endif;
  endforeach;
endif;