<?php
define('FEED_ID_IMPORT_BIEN', 'parcel_feed_import');


define('CONTENT_TYPE_BIEN', 'bien');
define('CONTENT_TYPE_PROGRAMME', 'programme');
define('CONTENT_TYPE_OPTION', 'options');

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
    
    /**
     * @todo set list node bien
     * @param type $list
     */
    public static function set_list_biens($list = -1) {
        if($list != -1){
            self::$_list_biens = $list;
        }elseif(empty(self::$_list_biens) && self::$_list_biens != -1){
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
    
    public static function get_bien_from_id_bien($id_bien){
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', CONTENT_TYPE_BIEN)
            ->fieldCondition('field_id_bien', 'value', $id_bien, '=');
            
        
        $results =  $query->execute();
        
        if(!empty($results)){
            return $results["node"];
        }
        
        return array();
    }

    /**
     * @todo to get taxonomy status du logement by name
     * @param type $term_name
     * @return type
     */
    public static function get_tax_status_du_logement_by_name($term_name) {
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'taxonomy_term')
            //->entityCondition('bundle', TAXONOMY_STATUS_LOGEMENT)
            ->propertyCondition('name', $term_name)
            ->range(0, 1);


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
    public static function calculate_bien_follow_programe($id_programe){
        if(empty($id_programe)){
            return NULL;
        }
        
        $status_disponible = Kandb_Business_Rules::get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', CONTENT_TYPE_BIEN)
            ->fieldCondition('field_bien_statut', 'tid', $status_disponible , '=')
            ->fieldCondition('field_programme', 'target_id', $id_programe, '=');
        
        $results = $query->execute();
        if(!empty($results)){
            return count($results["node"]);
        }
        return 0;
    }
    
    
    /**
     * @todo recalculate bien for program
     * @param type $id_programe
     * @return type
     */
    public static function recalculate_bien_to_programe($list_programe = array()){
        if(empty($list_programe)){
            $list_programe = self::get_list_program_contain_bien();
        }
        
        foreach($list_programe as $item){
            $total_bien = self::calculate_bien_follow_programe($item->nid);
        
            $node_programe = node_load($item->nid);
            $node_programe->field_programme_flat_available[LANGUAGE_NONE][0][value] = $total_bien;
            node_save($node_programe);
        }
    }
    
    /**
     * @todo to get list program contain bien
     * @return int
     */
    public static function get_list_program_contain_bien(){        
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', CONTENT_TYPE_PROGRAMME);
            //->fieldCondition('field_programme_flat_available', 'value', 0, '>');
        
        $results = $query->execute();
        
        if(!empty($results)){
            return $results["node"];
        }
        return array();
    }
    
    /**
     * @todo to Delete node option what it related to bien
     * @param type $id_bien
     * @return type
     */
    public static function delete_node_option_related_bien($id_bien){
        if(empty($id_bien) || !is_numeric($id_bien)){
            return;
        }
        
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', CONTENT_TYPE_OPTION)
            ->fieldCondition('field_option_bien', 'target_id', $id_bien, '=');
        
        $results = $query->execute();
        if(!empty($results)){
            foreach($results["node"] as $item ){
                node_delete($item->nid);
            }
        }
    }
   
}