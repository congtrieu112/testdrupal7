<?php

require_once('nusoap.php');

class TagCommander
{
    private static $instance = null;

    const WSDL_URL = 'http://manager.tagcommander.com/api/index.php?wsdl';

    private $nusoap = null;

    private function __construct()
    {
    }

    /**
     * Get an instance of TagCommander
     * @return null|TagCommander
     */
    static public function getInstance()
    {
        if (self::$instance == null) {
            self::$instance = new TagCommander();
        }

        return self::$instance;
    }

    /**
     * Get an instance of nusoap_client
     * @return nusoap_client
     */
    private function getNuSOAPInstance()
    {
        if ($this->nusoap == null) {
            $this->nusoap = new nusoap_client(self::WSDL_URL, true);
        }


        return $this->nusoap;
    }

    /**
     * Check if token is allready valid
     * @return bool
     */
    public function checkAccount()
    {
        $login = variable_get('tagcommander_account_login', '');
        $password = variable_get('tagcommander_account_password', '');
        try{
            $token = $this->getValidToken();
        }catch(Exception $e)
        {
            if( !empty($login) && !empty($password) )
            {
                throw new Exception('Login or Password are invalid');
                return false;
            }
            return false;
        }

        if (empty($login) || empty($password) ) {
            return false;
        }

        $params = array(
            'token' => $token
        );
        $valid = $this->getNuSOAPInstance()->call('Webservice.hello', $params, self::WSDL_URL);

        return $valid == 'Hello';
    }

    /**
     * Login and stock the valid token
     * @return bool|mixed|null
     * @throws Exception
     */
    public function getValidToken()
    {
        $login = variable_get('tagcommander_account_login', '');
        $password = variable_get('tagcommander_account_password', '');

        if (empty($login) || empty($password)) {
            return false;
        }

        $validity = variable_get('tagcommander_account_validity', 0);

        if ($validity < (time() + 3600)) {
            $params = array(
                'inputUsername' => $login,
                'inputPassword' => $password,
                'inputSite' => false,
                'encrypt' => 'md5'
            );

            //var_dump($params);
            $token = $this->getNuSOAPInstance()->call('Webservice.login', $params, self::WSDL_URL);

            if ($token === false) {
                throw new Exception('Error while connection. Please retry later');
                return false;
            }

            //ini_set('xdebug.var_display_max_depth', 999);
            //var_dump ($this->getNuSOAPInstance());
            if (is_array($token) && isset($token['faultcode']) && isset($token['faultstring'])) {
                throw new Exception('Message: ' . $token['faultstring'] . ' Please retry later');
                return false;
            }

            variable_set('tagcommander_account_token', $token);
            variable_set('tagcommander_account_validity', time());
        } else {
            $token = variable_get('tagcommander_account_token', '');
        }

        return $token;
    }

    /**
     * Call SiteSubservice.getSites service and return them
     * @return bool|mixed
     */
    public function getSites()
    {
        try{
            $token = $this->getValidToken();
        }catch(Exception $e)
        {
            return false;
        }
        $params = array('token' => $token);
        $sites = $this->getNuSOAPInstance()->call('SiteSubservice.getSites', $params, self::WSDL_URL);
        return $sites;
    }

    /**
     * Call ContainerSubservice.getExternalVars service and return them
     * @return bool|mixed
     */
    public function getExternalsVariables()
    {
        try{
            $token = $this->getValidToken();
        }catch(Exception $e)
        {
            return false;
        }
        $idSite = variable_get('tagcommander_website_id', 0);
        if ($idSite == 0) {
            return false;
        }

        $params = array('inputSiteid' => $idSite, 'token' => $token);
        $externals = $this->getNuSOAPInstance()->call('ContainerSubservice.getExternalVars', $params, self::WSDL_URL);
        return $externals;
    }

    /**
     * Call ContainerSubservice.getContainers service and return them
     * @return bool|mixed
     */
    function getContainers()
    {
        try{
            $token = $this->getValidToken();
        }catch(Exception $e)
        {
            return false;
        }
        $idSite = variable_get('tagcommander_website_id', 0);
        if ($idSite == 0) {
            return false;
        }
        $params = array('inputSiteid' => $idSite, 'token' => $token);
        $containers = $this->getNuSOAPInstance()->call('ContainerSubservice.getContainers', $params, self::WSDL_URL);
        return $containers;
    }
} 