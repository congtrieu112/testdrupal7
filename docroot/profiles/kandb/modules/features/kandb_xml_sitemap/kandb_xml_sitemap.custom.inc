<?php

/**
 * @file
 * kandb_xml_sitemap.custom.inc
 */

/**
 * Implements hook_xmlsitemap_link_info_alter().
 */
function kandb_xml_sitemap_xmlsitemap_link_info_alter(&$link_info) {
  $link_info['node']['xmlsitemap']['rebuild callback'] = 'kandb_xml_sitemap_rebuild_batch_fetch';
}

function kandb_xml_sitemap_rebuild_batch_fetch($entity, &$context) {

  if (!isset($context['sandbox']['info'])) {
    $context['sandbox']['info'] = xmlsitemap_get_link_info($entity);
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['last_id'] = 0;
    $context['sandbox']['offset'] = 0;
  }
  $info = $context['sandbox']['info'];
  $types = xmlsitemap_get_link_type_enabled_bundles($entity);
  $types_list = array();
  $types_bien = '';
  if (!empty($types)) {
    foreach ($types as $item) {
      if ($item == 'bien') {
        $types_bien = $item;
      }
      else {
        $types_list[] = $item;
      }
    }
  }

  $query_list = new EntityFieldQuery();
  $query_list->entityCondition('entity_type', $entity);
  $query_list->addTag('xmlsitemap_link_bundle_access');
  $query_list->addTag('xmlsitemap_rebuild');
  $query_list->addMetaData('entity', $entity);
  $query_list->addMetaData('entity_info', $info);
  if ($types_list) {
    $query_list->entityCondition('bundle', $types_list, 'IN');
  }
  else {
    // If no enabled bundle types, skip everything else.
    return;
  }
  $query_list->entityOrderBy('entity_id');
  $result_list = $query_list->execute();
  $result1 = $result_list['node'];

  if (!empty($types_bien)) {
    $terms = taxonomy_get_term_by_name('Disponible / Libre');
    $terms = array_values($terms);
    $tid = $terms[0]->tid;
    $query_bien = new EntityFieldQuery();
    $query_bien->entityCondition('entity_type', $entity);
    $query_bien->addTag('xmlsitemap_link_bundle_access');
    $query_bien->addTag('xmlsitemap_rebuild');
    $query_bien->addMetaData('entity', $entity);
    $query_bien->addMetaData('entity_info', $info);
    $query_bien->fieldCondition('field_bien_statut', 'tid', $tid);
    $query_bien->entityCondition('bundle', $types_bien);
    $query_bien->entityOrderBy('entity_id');
    $result_bien = $query_bien->execute();
    $result2 = $result_bien['node'];
  }
  if (!empty($result2)) {
    $result = array_merge($result1, $result2);
  }
  else {
    $result = $result1;
  }
  if (!isset($context['sandbox']['max'])) {
    $context['sandbox']['max'] = count($result);
    if (!$context['sandbox']['max']) {
      // If there are no items to process, skip everything else.
      return;
    }
  }
  $list_ids = array();
  foreach ($result as $id) {
    $list_ids[] = $id->nid;
  }

  $limit = 20;
  if ($context['sandbox']['offset'] == 0) {
    $offset = 0;
  }
  else {
    $offset = $context['sandbox']['offset'];
  }
  $ids = array_slice($list_ids, $offset, $limit);

  $context['sandbox']['offset'] = $offset + $limit;

  $info['xmlsitemap']['process callback']($ids);
  $context['sandbox']['last_id'] = end($ids);
  $context['sandbox']['progress'] += count($ids);

  $context['message'] = t('Now processing %entity @last_id (@progress of @count).', array('%entity' => $entity, '@last_id' => $context['sandbox']['last_id'], '@progress' => $context['sandbox']['progress'], '@count' => $context['sandbox']['max']));

  if ($context['sandbox']['progress'] >= $context['sandbox']['max']) {
    $context['finished'] = 1;
  }
  else {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}
