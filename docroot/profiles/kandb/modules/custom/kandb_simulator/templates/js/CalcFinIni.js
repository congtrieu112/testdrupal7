//;----------------------------------------------------------
//; (c) ALTO Informatique. Calculette Crédit Graphique - 2015
//;----------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//--- Objet OCalcFinIni contenant les paramètres d'initialisation d'une calculette -----------------
//--------------------------------------------------------------------------------------------------
var OCalcFinIni =
{
/*
;---------------------------------------------------
; IsPretToMensDuree : 0=Mensualité+Durée vers Prêt, 1=sens inversé
; IsFixeMontantPret : 0=La modification de la Mensualité ou de la Durée impacte le Prêt
;                     1=Le montant du prêt n'est pas modifié (toujours à 1 si IsPretToMensDuree == 1)
;
; CanSelectTF/TR/TS: 1=choix possible, 2=choix masqué
;
; DefaultTypeTaux   : type de taux par defaut
; 1=BaremeTauxFixe, 2=BaremeTauxRevisable, 9=TauxSaisiParUtilisateur
;
; DefaultTauxSaisi  : taux affiché par défaut si taux est saisi
; NbMoisMaxi        : durée maximale en mois (jusqu'à 600 mois)
; NbMoisMini        : durée minimale en mois (A partir de 12 mois)
; NbMoisDefaut      : durée par défaut en mois
; NbMoisMaxAvtMens  : la durée augmente en priorité jusqu'à ce nombre de mois (A partir de NbMoisDefaut)
; PasNbMois         : Nb mois entre chaque pas (la durée évolue de x mois en x mois)
; RevenuDefaut      : revenu par défaut
; PretMaxi          : montant maximum du prêt (0 = pas de limite)
; CodeNLS           : langue utilisée (0=français, 1033=anglais, 2070=portugais)
; Monnaie           : monnaie utilisée (euro=€, livre=£, dollar=$)
;---------------------------------------------------
*/
  General:
  {
    IsPretToMensDuree   :0
   ,IsFixeMontantPret   :0
   ,CanSelectTF         :0
   ,CanSelectTR         :0
   ,CanSelectTS         :0
   ,DefaultTypeTaux     :9
   ,DefaultTauxSaisi    :2.70
   ,NbMoisMini          :60
   ,NbMoisMaxi          :360
   ,NbMoisMaxAvtMens    :360
   ,NbMoisDefaut        :180
   ,PasNbMois           :12
   ,RevenuDefaut        :2500
   ,PretMaxi            :0
   ,CodeNLS             :0
   ,Monnaie             :"euro"
  }

/*
;---------------------------------------------------
; Design et présentation de la calculette :
; UrlTrameFondEcran     : image de fond d'écran du graphique
; IsHideBottomTextBox   : supprime les zones de texte en bas de la calculette (true|false)
; IsHideLabels          : supprime les labels de la calculette (true|false)
; IsHideHelp            : supprime l'aide de la calculette (true|false)
; IsFieldsWithoutBorder : champs de saisie sans bordures (true|false)
; BtnCalcul_UrlImageHaut: image haut du bouton calcul (ex:"library/BtnCalcul.png")
; BtnCalcul_UrlImageBas : image bas du bouton calcul (lorsqu'il est pressé)
; BtnAide_UrlImageHaut  : image haut du bouton d'aide
; BtnAide_UrlImageBas   : image bas du bouton d'aide (lorsqu'il est actif)
; TaillePoignees        : taille des poignées de redimensionnement (1=petit,2=moyen,3=grand,4=très grand)
;---------------------------------------------------
*/
 ,Design:
  {
    UrlTrameFondEcran       :null
   ,IsHideBottomTextBox     :false
   ,IsHideLabels            :false
   ,IsHideHelp              :false
   ,IsFieldsWithoutBorder   :false
   ,BtnCalcul_UrlImageHaut  :null
   ,BtnCalcul_UrlImageBas   :null
   ,BtnAide_UrlImageHaut    :null
   ,BtnAide_UrlImageBas     :null
   ,TaillePoignees          :2
  }

/*
;---------------------------------------------------
; couleurs utilisées dans la calculette :
; ColorBG               : couleur de fond (ex: ColorBG:"#CCCCFF")
; ColorGraphBG          : couleur de fond des graphiques
; ColorGraphContour     : couleur de contour des graphiques
; ColorAxeGraduation    : couleur des axes et graduations
; ColorBorder           : bordure de la calculette (ex : #C8C8FF ou none)
; ColorCadre            : couleur de fond des cadres entourants les zones de saisie
; ColorLabel            : couleur des labels
; ColorFieldText        : couleur du texte dans les champs de saisie
; ColorFieldBorder      : couleur de bordures des champs de saisie
; ColorDisabled         : couleur pour le grisage/verrouillage des champs de saisie
; ColorCadreBorder      : couleur de bordures des cadres entourants les zones de saisie
; ColorMensInf33PC      : mensualité inférieur à 33 %
; ColorMensSupp33PC     : mensualité suppérieur à 33 %
; ColorPret             : couleur du graphique de prêt
; Color33PC             : couleur de la barre des 33 % du revenu
; ColorContourPoignees  : couleur contours et poignées de redimensionnement
; ColorBulle            : couleur des bulles et tooltip
; ColorBtnCalculBG      : couleur de fond du bouton de calcul (si pas image)
; ColorBtnCalculText    : couleur de text du bouton calcul (si pas image)
;---------------------------------------------------
*/
 ,Couleur:
  {
    ColorBG             :"#EDF5FE"
   ,ColorGraphBG        :"#C8C8FF"
   ,ColorGraphContour   :"#888888"
   ,ColorAxeGraduation  :"#000000"
   ,ColorBorder         :"none"
   ,ColorCadre          :"#CEDFFF"
   ,ColorCadreBorder    :"#000000"
   ,ColorLabel          :"#000000"
   ,ColorFieldText      :"#000000"
   ,ColorFieldBorder    :"#8187CF"
   ,ColorDisabled       :"#CCCCCC"
   ,ColorMensInf33PC    :"#FFC62F"
   ,ColorMensSupp33PC   :"#FF0F0F"
   ,ColorPret           :"#5DAF20"
   ,Color33PC           :"#34B136"
   ,ColorContourPoignees:"#1600CF"
   ,ColorBulle          :"#FFF397"
   ,ColorBtnCalculBG    :"#5080FF"
   ,ColorBtnCalculText  :"#FFFFFF"
  }

/*
;---------------------------------------------------
; baremes de taux en fixe et revisable
; CanSelect: 1=choix autorisé, 0=choix masqué
; t#:NbMoisLimitTranche,TauxDeLaTranche  (t1 a t20 maxi)
; Sur la dernire tranche, NbMoisLimitTranche doit etre 0
;---------------------------------------------------
*/
 ,BaremeTauxFixe:
  {
    t1:[120,1.90]
   ,t2:[180,2.10]
   ,t3:[240,2.50]
   ,t4:[300,2.80]
   ,t5:[360,3.00]
   ,t6:[  0,3.20]
  }

 ,BaremeTauxRevisable:
  {
    t1:[ 60,1.00]
   ,t2:[120,2.10]
   ,t3:[180,2.60]
   ,t4:[240,3.00]
   ,t5:[300,3.30]
   ,t6:[360,3.50]
   ,t7:[  0,3.70]
  }
}













//--------------------------------------------------------------------------------------------------
//--- Objet OCalcFinIni2 contenant les paramètres d'initialisation pour une seconde calculette -----
//--------------------------------------------------------------------------------------------------
var OCalcFinIni2 =
{
/*
;---------------------------------------------------
; IsPretToMensDuree : 0=Mensualité+Durée vers Prêt, 1=sens inversé
; IsFixeMontantPret : 0=La modification de la Mensualité ou de la Durée impacte le Prêt
;                     1=Le montant du prêt n'est pas modifié (toujours à 1 si IsPretToMensDuree == 1)
;
; CanSelectTF/TR/TS: 1=choix possible, 2=choix masqué
;
; DefaultTypeTaux   : type de taux par defaut
; 1=BaremeTauxFixe, 2=BaremeTauxRevisable, 9=TauxSaisiParUtilisateur
;
; DefaultTauxSaisi  : taux affiché par défaut si taux est saisi
; NbMoisMaxi        : durée maximale en mois (jusqu'à 600 mois)
; NbMoisMini        : durée minimale en mois (A partir de 12 mois)
; NbMoisDefaut      : durée par défaut en mois
; NbMoisMaxAvtMens  : la durée augmente en priorité jusqu'à ce nombre de mois (A partir de NbMoisDefaut)
; PasNbMois         : Nb mois entre chaque pas (la durée évolue de x mois en x mois)
; RevenuDefaut      : revenu par défaut
; PretMaxi          : montant maximum du prêt (0 = pas de limite)
; CodeNLS           : langue utilisée (0=français, 1033=anglais, 2070=portugais)
; Monnaie           : monnaie utilisée (euro=€, livre=£, dollar=$)
;---------------------------------------------------
*/
  General:
  {
    IsPretToMensDuree   :1
   ,IsFixeMontantPret   :0
   ,CanSelectTF         :0
   ,CanSelectTR         :0
   ,CanSelectTS         :0
   ,DefaultTypeTaux     :9
   ,DefaultTauxSaisi    :2.70
   ,NbMoisMini          :60
   ,NbMoisMaxi          :360
   ,NbMoisMaxAvtMens    :360
   ,NbMoisDefaut        :180
   ,PasNbMois           :12
   ,RevenuDefaut        :2500
   ,PretMaxi            :0
   ,CodeNLS             :0
   ,Monnaie             :"euro"
  }

/*
;---------------------------------------------------
; Design et présentation de la calculette :
; UrlTrameFondEcran     : image de fond d'écran du graphique
; IsHideBottomTextBox   : supprime les zones de texte en bas de la calculette (true|false)
; IsHideLabels          : supprime les labels de la calculette (true|false)
; IsHideHelp            : supprime l'aide de la calculette (true|false)
; IsFieldsWithoutBorder : champs de saisie sans bordures (true|false)
; BtnCalcul_UrlImageHaut: image haut du bouton calcul (ex:"library/BtnCalcul.png")
; BtnCalcul_UrlImageBas : image bas du bouton calcul (lorsqu'il est pressé)
; BtnAide_UrlImageHaut  : image haut du bouton d'aide
; BtnAide_UrlImageBas   : image bas du bouton d'aide (lorsqu'il est actif)
; TaillePoignees        : taille des poignées de redimensionnement (1=petit,2=moyen,3=grand,4=très grand)
;---------------------------------------------------
*/
 ,Design:
  {
    UrlTrameFondEcran       :null
   ,IsHideBottomTextBox     :false
   ,IsHideLabels            :false
   ,IsHideHelp              :false
   ,IsFieldsWithoutBorder   :false
   ,BtnCalcul_UrlImageHaut  :null
   ,BtnCalcul_UrlImageBas   :null
   ,BtnAide_UrlImageHaut    :null
   ,BtnAide_UrlImageBas     :null
   ,TaillePoignees          :2
  }

/*
;---------------------------------------------------
; couleurs utilisées dans la calculette :
; ColorBG               : couleur de fond (ex: ColorBG:"#CCCCFF")
; ColorGraphBG          : couleur de fond des graphiques
; ColorGraphContour     : couleur de contour des graphiques
; ColorAxeGraduation    : couleur des axes et graduations
; ColorBorder           : bordure de la calculette (ex : #C8C8FF ou none)
; ColorCadre            : couleur de fond des cadres entourants les zones de saisie
; ColorLabel            : couleur des labels
; ColorFieldText        : couleur du texte dans les champs de saisie
; ColorFieldBorder      : couleur de bordures des champs de saisie
; ColorDisabled         : couleur pour le grisage/verrouillage des champs de saisie
; ColorMensInf33PC      : mensualité inférieur à 33 %
; ColorMensSupp33PC     : mensualité suppérieur à 33 %
; ColorPret             : couleur du graphique de prêt
; Color33PC             : couleur de la barre des 33 % du revenu
; ColorContourPoignees  : couleur contours et poignées de redimensionnement
; ColorBulle            : couleur des bulles et tooltip
; ColorBtnCalculBG      : couleur de fond du bouton de calcul (si pas image)
; ColorBtnCalculText    : couleur de text du bouton calcul (si pas image)
;---------------------------------------------------
*/
 ,Couleur:
  {
    ColorBG             :"#EDF5FE"
   ,ColorGraphBG        :"#C8C8FF"
   ,ColorGraphContour   :"#888888"
   ,ColorAxeGraduation  :"#000000"
   ,ColorBorder         :"none"
   ,ColorCadre          :"#CEDFFF"
   ,ColorLabel          :"#000000"
   ,ColorFieldText      :"#000000"
   ,ColorFieldBorder    :"#8187CF"
   ,ColorDisabled       :"#CCCCCC"
   ,ColorMensInf33PC    :"#FFC62F"
   ,ColorMensSupp33PC   :"#FF0F0F"
   ,ColorPret           :"#5DAF20"
   ,Color33PC           :"#34B136"
   ,ColorContourPoignees:"#1600CF"
   ,ColorBulle          :"#FFF397"
   ,ColorBtnCalculBG    :"#5080FF"
   ,ColorBtnCalculText  :"#FFFFFF"
  }

/*
;---------------------------------------------------
; baremes de taux en fixe et revisable
; CanSelect: 1=choix autorisé, 0=choix masqué
; t#:NbMoisLimitTranche,TauxDeLaTranche  (t1 a t20 maxi)
; Sur la dernire tranche, NbMoisLimitTranche doit etre 0
;---------------------------------------------------
*/
 ,BaremeTauxFixe:
  {
    t1:[120,1.90]
   ,t2:[180,2.10]
   ,t3:[240,2.50]
   ,t4:[300,2.80]
   ,t5:[360,3.00]
   ,t6:[  0,3.20]
  }

 ,BaremeTauxRevisable:
  {
    t1:[ 60,1.00]
   ,t2:[120,2.10]
   ,t3:[180,2.60]
   ,t4:[240,3.00]
   ,t5:[300,3.30]
   ,t6:[360,3.50]
   ,t7:[  0,3.70]
  }
}

