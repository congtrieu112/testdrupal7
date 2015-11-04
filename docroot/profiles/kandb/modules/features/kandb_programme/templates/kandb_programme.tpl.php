<?php

print $content['rs_price_max_min'];
foreach($content['rs_price_most'] as $key => $value) {
  if(isset($content['rs_price_most'][$key])) {
    print $content['rs_price_most'][$key];
  }
  if(isset($content['rs_price_least'][$key])) {
    print $content['rs_price_least'][$key];
  }
}