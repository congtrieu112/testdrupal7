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

  public
    function getTaxonomyTermDataByFieldName($fieldName, $value, $type = 'value', $entityType = 'taxonomy_term') {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $entityType)
      ->fieldCondition($fieldName, $type, $value);
    $result = $query->execute();

    return $result;
  }

  public
    function deleteTableIndex($tableIndex, $field, $id, $tid) {
    $status = db_delete($tableIndex)
      ->condition($field, $id)
      ->condition('tid', $tid)
      ->execute();
    return $status;
  }

  public
    function insertTableIndex($tableIndex, $field, $id, $tid) {
    $status = db_insert($tableIndex)
      ->fields(array(
        $field => $id,
        'tid' => $tid,
      ))
      ->execute();

    return $status;
  }

  /**
   * Get produts item by lang code.
   */
  public
    function checkExistsProgramme($idkp, $type = 'node', $bundle = 'programme') {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', $type)
      ->entityCondition('bundle', $bundle)
      ->fieldCondition('field_idkp', 'value', $idkp, '=')
      ->execute();

    if ($result) {
      return $result['node'];
    }

    return FALSE;
  }

  public
    function getListProgramme($type = 'node', $bundle = 'programme') {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', $type)
      ->entityCondition('bundle', $bundle)
      ->execute();

    if ($result) {
      return $result['node'];
    }

    return FALSE;
  }

  public
    function insertNodeProgramme($params, $type = 'programme') {
    $node = new stdClass();
    $node->title = $params['name'];
    $node->type = $type;
    node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
    $node->uid = 1;
    $node->status = 1; //(1 or 0): published or not
    $node->promote = 1; //(1 or 0): promoted to front page
    $node->comment = 2; // 0 = comments disabled, 1 = read only, 2 = read/write
    $node->field_structure[LANGUAGE_NONE][0]['value'] = $params['structure'];
    $node->field_idkp[LANGUAGE_NONE][0]['value'] = $params['idkp'];
    $node = node_submit($node); // Prepare node for saving
    node_save($node);
  }

  public
    function updateNodeProgramme($nid, $value) {
    $node = node_load($nid);
    $field_language = field_language('node', $node, 'field_structure');
    $node->field_structure[$field_language][0]['value'] = $value;
    node_save($node);
  }

}
