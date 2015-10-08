<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of newPHPClass
 *
 * @author dinh.han
 */
class KBAPI {
  public function getListNodeByBundle($type = 'node', $bundle = 'programme') {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', $type)
      ->entityCondition('bundle', $bundle)
      ->execute();

    if ($result) {
      return $result['node'];
    }

    return FALSE;
  }
}
