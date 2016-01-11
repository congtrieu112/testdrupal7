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

function kandb_xml_sitemap_xmlsitemap_link_info() {
  return array(
    'kandb' => array(
      'label' => t('Kandb custom links'),
      'xmlsitemap' => array(
        'rebuild callback' => 'kandb_xml_sitemap_xmlsitemap_index_links',
        ),
      )
    );
}

function kandb_xml_sitemap_xmlsitemap_index_links($limit) {
  $link = array(
    'type' => 'kandb',
    'id' => 0,
    'loc' => '',
    'priority' => '0.5',
    'changefreq' => '86400',
    'language' => LANGUAGE_NONE
  );
  $current_paths = array_merge(kandb_xml_sitemap_get_current_links(), array('villes', 'departements', 'regions'));
  $del_paths = array();
  $add_paths = array();
  $db_query = db_select('xmlsitemap', 'x');
  $db_query->fields('x', array('loc', 'id'));
  $db_query->condition('x.type', 'kandb');
  $result = $db_query->execute()->fetchAll();
  if(empty($result)) {
    $add_paths = $current_paths;
  }
  else{
    $indexed_paths = array();
    $latest_id = 0;
    foreach ($result as $item) {
      $indexed_paths []= $item->loc;
      $latest_id = $latest_id > $item->id ? $latest_id : $item->id;
    }
    $del_paths = array_diff($indexed_paths, $current_paths);
    $add_paths = array_diff($current_paths, $indexed_paths);
  }
  if(!empty($del_paths)){
    $db_query = db_delete('xmlsitemap');
    $db_query->condition('xmlsitemap.type', 'kandb');
    $db_query->condition('xmlsitemap.loc', $del_paths, 'IN');
    $db_query->execute();
  }
  if (!empty($add_paths)) {
    $add_paths = array_unique($add_paths);
    foreach($add_paths as $path) {
      $link['loc'] = $path;
      $link['id'] = $latest_id++;
      xmlsitemap_link_save($link);
    }
  }
}

function kandb_xml_sitemap_get_current_links() {
  $vars = array();
  $urls = array(
    'villes',
    'departements',
    'regions',
  );
  foreach($urls as $url) {
    $current_url_meta = kandb_seo_metatags_and_callbacks($url);
    if(isset($current_url_meta['callbacks'])) {
      foreach ($current_url_meta['callbacks'] as $callback => $args) {
        if ($callback == 'kandb_seo_block_lieu') {
          continue;
        }
        elseif ($callback == 'kandb_seo_block_letters' || $callback == 'kandb_seo_block_list') {
          $callback = str_replace("kandb_seo_block","kandb_xml_sitemap_current_links", $callback);
        }
        $var = call_user_func_array($callback, $args);
        $vars = array_merge($vars, $var);
      }
    }
  }
  return $vars;
}

function kandb_xml_sitemap_current_links_letters($location) {
  global $conf;
  $vars = array();
  $results_letter = kandb_seo_get_list_of_cities_by_programme_in($location, array('only_first_letter' => TRUE));
  while($object_letter = $results_letter->fetchAssoc()){
    $min_letter = strtolower($object_letter['first_letter']);
    $vars []= $location . '/' . $min_letter;
  }
  return $vars;
}

function kandb_xml_sitemap_current_links_list($location) {
  global $conf;
  $vars = array();
  $results_list = kandb_seo_get_list_of_cities_by_programme_in($location, array('first_letter' => FALSE));
  module_load_include('inc', 'pathauto');
  $pathauto_ignore_words = $conf['pathauto_ignore_words'];
  $conf['pathauto_ignore_words'] = '';
  while($object_list = $results_list->fetchAssoc()){
    $sanitize_name = pathauto_cleanstring($object_list['name']);
    $vars []= $location . '/programmes-immobiliers-neufs-' . $sanitize_name;
    $vars []= $location . '/logements-immobiliers-neufs-' . $sanitize_name;
  }
  $conf['pathauto_ignore_words'] = $pathauto_ignore_words;
  return $vars;
}
