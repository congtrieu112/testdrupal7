<?php

define('FEED_ID_IMPORT_BIEN', 'parcel_feed_import');


define('CONTENT_TYPE_BIEN', 'bien');
define('CONTENT_TYPE_PROGRAMME', 'programme');
define('CONTENT_TYPE_OPTION', 'options');

define('TAXONOMY_NB_PIECES', 'nb_pieces');
define('TAXONOMY_STATUS_LOGEMENT', 'status_logement');
define('TAXONOMY_STATUS_LOGEMENT_INDISPONIBLE', 'Indisponible');
define('TAXONOMY_STATUS_LOGEMENT_DISPONIBLE', 'Disponible / Libre');
define('TAXONOMY_STATUS_LOGEMENT_RESERVE', 'Réservé');
define('TAXONOMY_STATUS_LOGEMENT_VENDU', 'Vendu');
define('TAXONOMY_STATUS_LOGEMENT_L', 'L');
define('TAXONOMY_STATUS_LOGEMENT_R', 'R');

define('FEED_COLUMN_ID', 0);
define('FEED_COLUMN_STATUS', 27);

class Kandb_Business_Rules {

  public static $_list_biens = array();
  public static $_list_id_program = array();
  public static $_is_feed_import = FALSE;
  public static $_list_progame = array();
  public static $_list_progam_to_save = array();
  public static $_is_node_updating = false;

  public static function set_is_feed_import($status = TRUE) {
    self::$_is_feed_import = $status;
  }

  public static function get_is_feed_import() {
    return self::$_is_feed_import;
  }

  public static function set_is_node_updating($status = TRUE) {
    self::$_is_node_updating = $status;
  }

  public static function get_is_node_updating() {
    return self::$_is_node_updating;
  }

  /**
   * @todo set list node bien
   * @param type $list
   */
  public static function set_list_biens($list = -1) {
    if ($list != -1) {
      self::$_list_biens = $list;
    }
    elseif (empty(self::$_list_biens) && self::$_list_biens != -1) {
      self::$_list_biens = self::get_node_by_type(CONTENT_TYPE_BIEN);
    }
  }

  public static function get_list_biens() {
    return self::$_list_biens;
  }

  /**
   * @todo to get list node by content type
   * @param type $type
   * @return type
   */
  public static function get_node_by_type($type) {

    $query = db_select('node', 'n');
    $query->condition('type', $type, '=');

    $query->fields('n', array('nid'));
    $nids = $query->execute()->fetchCol();

    if (!empty($nids)) {
      return $nids;
    }

    return -1;
  }

  public static function get_bien_from_id_bien($id_bien) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_BIEN)
        ->fieldCondition('field_id_bien', 'value', $id_bien, '=');


    $results = $query->execute();

    if (!empty($results)) {
      return $results["node"];
    }

    return array();
  }

  /**
   * @todo to get taxonomy status du logement by name
   * @param type $term_name
   * @return type
   */
  public static function get_tax_status_du_logement_by_name($term_name, $search_by_name = TRUE) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term');
    //->entityCondition('bundle', TAXONOMY_STATUS_LOGEMENT)

    if (!$search_by_name) {
      $query->fieldCondition('field_id_file', 'value', $term_name, '=');
    }
    else {
      $query->propertyCondition('name', $term_name);
    }

    $query->range(0, 1);


    $results = $query->execute();

    if (!empty($results)) {
      return array_shift($results["taxonomy_term"])->tid;
    }

    return $results;
  }

  /**
   * @todo calculate bien follow program
   * @param type $id_programe
   * @return int
   */
  public static function calculate_bien_follow_programe($id_programe) {
    if (empty($id_programe)) {
      return NULL;
    }

    $status_disponible = Kandb_Business_Rules::get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_BIEN)
        ->fieldCondition('field_bien_statut', 'tid', $status_disponible, '=')
        ->fieldCondition('field_programme', 'target_id', $id_programe, '=');

    $count_bien = intval($query->count()->execute());
    if ($count_bien > 0) {
      return $count_bien;
    }
    return 0;
  }

  /**
   * @todo recalculate bien for program
   * @param type $id_programe
   * @return type
   */
  public static function recalculate_bien_to_programe($list_programe = array()) {
    if (empty($list_programe)) {
      $list_programe = self::get_list_program_contain_bien();
    }

    foreach ($list_programe as $item) {
      $total_bien = self::calculate_bien_follow_programe($item->nid);

      if (isset(self::$_list_progam_to_save [$item->nid])) {
        $node_programe = self::$_list_progam_to_save [$item->nid];
      }
      else {
        $node_programe = node_load($item->nid);
      }

      $node_programe->field_programme_flat_available[LANGUAGE_NONE][0]["value"] = $total_bien;

      self::$_list_progam_to_save [$item->nid] = $node_programe;
      //node_save($node_programe);
    }
  }

  /**
   * @todo to get list program contain bien
   * @return int
   */
  public static function get_list_program_contain_bien() {
    if (!empty(self::$_list_progame)) {
      return self::$_list_progame;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_PROGRAMME);
    //->fieldCondition('field_programme_flat_available', 'value', 0, '>');

    $results = $query->execute();

    if (!empty($results)) {
      self::$_list_progame = $results["node"];
      return self::$_list_progame;
    }
    return array();
  }

  /**
   * @todo to Delete node option what it related to bien
   * @param type $id_bien
   * @return type
   */
  public static function delete_node_option_related_bien($id_bien) {
    if (empty($id_bien) || !is_numeric($id_bien)) {
      return;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_OPTION)
        ->fieldCondition('field_option_bien', 'target_id', $id_bien, '=');

    $results = $query->execute();
    if (!empty($results)) {
      foreach ($results["node"] as $item) {
        node_delete($item->nid);
      }
    }
  }

  /**
   * @todo To get min or max price bien contain programe
   * @param type $id_programe
   * @param type $is_min
   * @return int
   */
  public static function get_programe_min_max_price($id_programe, $is_min = TRUE) {
    if (empty($id_programe)) {
      return 0;
    }

    $sort = "ASC";
    if (!$is_min) {
      $sort = "DESC";
    }

    $status_disponible = Kandb_Business_Rules::get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_BIEN)
        ->fieldCondition('field_bien_statut', 'tid', $status_disponible, '=')
        ->fieldCondition('field_programme', 'target_id', $id_programe, '=')
        ->fieldOrderBy('field_prix_tva_20', 'value', $sort)
        ->range(0, 1)
    ;

    $results = $query->execute();

    if (!empty($results)) {
      $first_item = array_shift($results["node"]);
      $bien = node_load($first_item->nid);
      return $bien->field_prix_tva_20[LANGUAGE_NONE][0]["value"];
    }

    return 0;
  }

  /**
   * @todo To calculate min price and max price for programe
   * RULE COUNTING 106
   */
  public static function calculate_programe_price($list_programe = array()) {
    if (empty($list_programe)) {
      $list_programe = self::get_list_program_contain_bien();
    }

    foreach ($list_programe as $item) {
      $min_price = self::get_programe_min_max_price($item->nid);
      $max_price = self::get_programe_min_max_price($item->nid, FALSE);

      if (isset(self::$_list_progam_to_save [$item->nid])) {
        $node_programe = self::$_list_progam_to_save [$item->nid];
      }
      else {
        $node_programe = node_load($item->nid);
      }

      $node_programe->field_programme_price_min[LANGUAGE_NONE][0]["value"] = $min_price;
      $node_programe->field_programme_price_max[LANGUAGE_NONE][0]["value"] = $max_price;

      self::$_list_progam_to_save [$item->nid] = $node_programe;
      //node_save($node_programe);
    }
  }

  /**
   * @todo
   * @param type $id_programe
   * @param type $is_room_min
   * @return int
   */
  public static function get_room_min_max_follow_programe($id_programe, $is_room_min = TRUE) {
    $sort = "ASC";
    if (!$is_room_min) {
      $sort = "DESC";
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', TAXONOMY_NB_PIECES)
        ->fieldOrderBy('field_id_nombre_pieces', 'value', $sort)
    ;


    $list_pieces = $query->execute();
    if (!empty($list_pieces)) {
      foreach ($list_pieces["taxonomy_term"] as $nb_piece) {
        // count bien follow programe and piece
        $count_bien = self::get_list_bien_by_program_piece($id_programe, $nb_piece->tid, TRUE);
        if ($count_bien > 0) {  // Have item mean this is min|max piece what I need to find.
          $tax_piece = taxonomy_term_load($nb_piece->tid);

          return $tax_piece->field_id_nombre_pieces[LANGUAGE_NONE][0]["value"];
        }
      }
    }


    return 0;
  }

  /**
   * @todo To find Room min or max of bien follow progame
   * RULE COUNTING 107
   * @return type
   */
  public static function find_room_bien_follow_programe($list_programe = array()) {
    if (empty($list_programe)) {
      $list_programe = self::get_list_program_contain_bien();
    }

    foreach ($list_programe as $item) {
      $room_min = self::get_room_min_max_follow_programe($item->nid);
      $room_max = self::get_room_min_max_follow_programe($item->nid, FALSE);

      if (isset(self::$_list_progam_to_save [$item->nid])) {
        $node_programe = self::$_list_progam_to_save [$item->nid];
      }
      else {
        $node_programe = node_load($item->nid);
      }

      $node_programe->field_programme_room_min[LANGUAGE_NONE][0]["value"] = $room_min;
      $node_programe->field_programme_room_max[LANGUAGE_NONE][0]["value"] = $room_max;

      self::$_list_progam_to_save [$item->nid] = $node_programe;
      //node_save($node_programe);
    }
  }

  /**
   * @todo To calculate total bien follow programe
   * RULE COUNTING 101.
   */
  public static function get_total_bien_follow_programe() {
    $status_disponible = Kandb_Business_Rules::get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
    $list_programe = self::get_list_program_contain_bien();

    foreach ($list_programe as $item) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', CONTENT_TYPE_BIEN)
          ->fieldCondition('field_bien_statut', 'tid', $status_disponible, '=')
          ->fieldCondition('field_programme', 'target_id', $item->nid, '=')
      ;

      $total_bien = intval($query->count()->execute());
      if ($total_bien > 0) {
        if (isset(self::$_list_progam_to_save [$item->nid])) {
          $node_programe = self::$_list_progam_to_save [$item->nid];
        }
        else {
          $node_programe = node_load($item->nid);
        }

        $node_programe->field_programme_flat_available[LANGUAGE_NONE][0]["value"] = $total_bien;

        self::$_list_progam_to_save [$item->nid] = $node_programe;
        //node_save($node_programe);
      }
    }
  }

  public static function node_save_list_program() {
    if (!empty(self::$_list_progam_to_save)) {
      foreach (self::$_list_progam_to_save as $node) {
        node_save($node);
      }
    }
  }

  /**
   * @todo to get list bien by id_programe && id_tax_piece
   * @param type $id_programe
   * @param type $id_piece
   * @param type $is_count
   * @return type
   */
  public static function get_list_bien_by_program_piece($id_programe, $id_piece = 0, $is_count = 0) {
    if (empty($id_programe)) {
      if ($is_count) {
        return $is_count;
      }
      else {
        return array();
      }
    }

    $status_disponible = Kandb_Business_Rules::get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_BIEN)
        ->fieldCondition('field_bien_statut', 'tid', $status_disponible, '=')
        ->fieldCondition('field_programme', 'target_id', $id_programe, '=')        
    ;
    
    if(!empty($id_piece)){      
      $query->fieldCondition('field_nb_pieces', 'tid', $id_piece, '=');
    }

    if ($is_count) {
      // count bien follow programe and piece
      return intval($query->count()->execute());
    }
    else {
      $results = $query->execute();
      if (!empty($results)) {
        return $results["node"];
      }
    }

    return array();
  }
  
  /**
   * @todo To get cheapest or expensive bien follow programe
   * @param type $id_programe
   * @param type $is_min
   * @return type
   */
  public static function get_cheapest_expensive_bien($id_programe, $id_piece = 0, $is_min = TRUE){
    $sort = "ASC";
    if(!$is_min){
      $sort = 'DESC';
    }
    
    $status_disponible = Kandb_Business_Rules::get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_BIEN)
        ->fieldCondition('field_bien_statut', 'tid', $status_disponible, '=')
        ->fieldCondition('field_programme', 'target_id', $id_programe, '=')
        ->fieldOrderBy('field_prix_tva_20', 'value', $sort)
        ->range(0, 1)
    ;
    
    if(!empty($id_piece)){
      $query->fieldCondition('field_nb_pieces', 'tid', $id_piece, '=');
    }
    
    $bien = $query->execute();
    if (!empty($bien)) {
      return array_shift($bien["node"]);
    }
    
    return array();
  }
  
  /**
   * @todo to get list between cheapest expensive (surface) bien  follow program
   * @param type $id_programe
   * @param type $id_piece
   * @param type $limit
   * @return type
   */
  public static function get_between_cheapest_expensive_biens($id_programe, $id_piece = 0, $limit = 1, $exclude_bien = array()){
    $status_disponible = Kandb_Business_Rules::get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', CONTENT_TYPE_BIEN)
        ->fieldCondition('field_bien_statut', 'tid', $status_disponible, '=')
        ->fieldCondition('field_programme', 'target_id', $id_programe, '=')
        ->fieldOrderBy('field_superficie', 'value', 'ASC')
        ->range(0, $limit)
    ;
    
    if(!empty($exclude_bien)){
      $exclude_ids = array();
      foreach($exclude_bien as $item){
        $exclude_ids[] = $item->nid;
      }      
      //$query->propertyCondition('nid', $exclude_ids, 'NOT IN');
      $query->entityCondition('entity_id', $exclude_ids, 'NOT IN');
    }
    
    if(!empty($id_piece)){
      $query->fieldCondition('field_nb_pieces', 'tid', $id_piece, '=');
    }
    
    $bien = $query->execute();
    
    if (!empty($bien)) {      
      return $bien["node"];
    }
    
    return array();
  }
}
