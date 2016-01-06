<!doctype html>
<html>

<!-- Auteur: ALTO Informatique, 33 avenue du Maine 75015 Paris - 2015 - Tous droits réservés -->

<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<meta name = "viewport" content="width=480, user-scalable=no" />
<meta name="apple-mobile-web-app-capable" content="yes" /> <!-- full-screen mode -->
<meta name="apple-mobile-web-app-status-bar-style" content="default" /> <!-- black-translucent pour afficher la calculette dessous -->
<meta name="format-detection" content="telephone=no" /> <!-- pas de numéro de téléphone à interpréter -->

<link rel="apple-touch-icon" href="<?php global $base_url; print  $base_url.'/'.drupal_get_path('module', 'kandb_simulator');?>/templates/library/CalcFin.png" />

<title>Calculette Financière</title>

<!-- Auteur: ALTO Informatique, 33 avenue du Maine 75015 Paris - 2015 - Tous droits réservés -->
<script type="text/javascript">
var ROOT_MODULE = "<?php global $base_url; print  $base_url.'/'.drupal_get_path('module', 'kandb_simulator');?>/templates";
</script>
<script type="text/javascript" language="JavaScript" src="<?php global $base_url; print  $base_url.'/'.drupal_get_path('module', 'kandb_simulator');?>/templates/js/CalcFinIni.js"></script>
<script type="text/javascript" language="JavaScript" src="<?php global $base_url; print  $base_url.'/'.drupal_get_path('module', 'kandb_simulator');?>/templates/js/CalcFinCmp.js"></script>

<!-- 
-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------
La calculette est chargée grâce à "LoadAltoCalcFin(param1, param2)" dans la fonction "onload" du tag "body", avec :
    param1 = Id du "div" dans lequel est chargé la calculette. Si param1 est null, la valeur par défaut est "IdAltoCalcFin".
    param2 = Objet contenant les paramètres de la calculette. Si param2 est null, la valeur par défaut est OCalcFinIni.
	
Deux objets présentant les paramètres d'initialisation sont déclarés par défaut dans le fichier CalcFinIni.js :
    OCalcFinIni et OCalcFinIni2 (pour initialiser une ou deux calculettes)
	
Exemple de code pour charger une calculette :	
    <body onload="LoadAltoCalcFin('IdAltoCalcFin', OCalcFinIni);">
    <div id="IdAltoCalcFin"></div>
	
Exemple de code pour charger deux calculettes sur la même page :	
    <body onload="LoadAltoCalcFin('IdAltoCalcFin', OCalcFinIni); LoadAltoCalcFin('IdAltoCalcFin2', OCalcFinIni2);">
    <div id="IdAltoCalcFin" style="position:relative; margin-left:30px; margin-top:50px"></div>
    <div id="IdAltoCalcFin2" style="position:relative; margin-left:30px; margin-top:100px"></div>
-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------
-->

</head>

<body onload="LoadAltoCalcFin('IdAltoCalcFin', OCalcFinIni)" style="margin:auto; padding:0;">

<div id="IdAltoCalcFin"></div>

</body>

</html>
