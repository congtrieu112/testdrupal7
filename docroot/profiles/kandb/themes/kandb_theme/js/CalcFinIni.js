//;----------------------------------------------------------
//; (c) ALTO Informatique. Calculette Cr�dit Graphique - 2015
//;----------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//--- Objet OCalcFinIni contenant les param�tres d'initialisation d'une calculette -----------------
//--------------------------------------------------------------------------------------------------

var OCalcFinIni =
{
/*
;---------------------------------------------------
; IsPretToMensDuree : 0=Mensualit�+Dur�e vers Pr�t, 1=sens invers�
; IsFixeMontantPret : 0=La modification de la Mensualit� ou de la Dur�e impacte le Pr�t
;                     1=Le montant du pr�t n'est pas modifi� (toujours � 1 si IsPretToMensDuree == 1)
;
; CanSelectTF/TR/TS: 1=choix possible, 2=choix masqu�
;
; DefaultTypeTaux   : type de taux par defaut
; 1=BaremeTauxFixe, 2=BaremeTauxRevisable, 9=TauxSaisiParUtilisateur
;
; DefaultTauxSaisi  : taux affich� par d�faut si taux est saisi
; NbMoisMaxi        : dur�e maximale en mois (jusqu'� 600 mois)
; NbMoisMini        : dur�e minimale en mois (A partir de 12 mois)
; NbMoisDefaut      : dur�e par d�faut en mois
; NbMoisMaxAvtMens  : la dur�e augmente en priorit� jusqu'� ce nombre de mois (A partir de NbMoisDefaut)
; PasNbMois         : Nb mois entre chaque pas (la dur�e �volue de x mois en x mois)
; RevenuDefaut      : revenu par d�faut
; PretMaxi          : montant maximum du pr�t (0 = pas de limite)
; CodeNLS           : langue utilis�e (0=fran�ais, 1033=anglais, 2070=portugais)
; Monnaie           : monnaie utilis�e (euro=�, livre=�, dollar=$)
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
; Design et pr�sentation de la calculette :
; UrlTrameFondEcran     : image de fond d'�cran du graphique
; IsHideBottomTextBox   : supprime les zones de texte en bas de la calculette (true|false)
; IsHideLabels          : supprime les labels de la calculette (true|false)
; IsHideHelp            : supprime l'aide de la calculette (true|false)
; IsFieldsWithoutBorder : champs de saisie sans bordures (true|false)
; BtnCalcul_UrlImageHaut: image haut du bouton calcul (ex:"library/BtnCalcul.png")
; BtnCalcul_UrlImageBas : image bas du bouton calcul (lorsqu'il est press�)
; BtnAide_UrlImageHaut  : image haut du bouton d'aide
; BtnAide_UrlImageBas   : image bas du bouton d'aide (lorsqu'il est actif)
; TaillePoignees        : taille des poign�es de redimensionnement (1=petit,2=moyen,3=grand,4=tr�s grand)
;---------------------------------------------------
*/
 ,Design:
  {
    UrlTrameFondEcran       :null
   ,IsHideBottomTextBox     :false
   ,IsHideLabels            :false
   ,IsHideHelp              :false
   ,IsFieldsWithoutBorder   :false
   ,BtnCalcul_UrlImageHaut  :'/profiles/kandb/themes/kandb_theme/js/calcul.png'
   ,BtnCalcul_UrlImageBas   :'/profiles/kandb/themes/kandb_theme/js/calcul-hover.png'
   ,BtnAide_UrlImageHaut    :null
   ,BtnAide_UrlImageBas     :null
   ,TaillePoignees          :2
  }

/*
;---------------------------------------------------
; couleurs utilis�es dans la calculette :
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
; ColorMensInf33PC      : mensualit� inf�rieur � 33 %
; ColorMensSupp33PC     : mensualit� supp�rieur � 33 %
; ColorPret             : couleur du graphique de pr�t
; Color33PC             : couleur de la barre des 33 % du revenu
; ColorContourPoignees  : couleur contours et poign�es de redimensionnement
; ColorBulle            : couleur des bulles et tooltip
; ColorBtnCalculBG      : couleur de fond du bouton de calcul (si pas image)
; ColorBtnCalculText    : couleur de text du bouton calcul (si pas image)
;---------------------------------------------------
*/
 ,Couleur:
  {
    ColorBG             :"#f2f5f6"
   ,ColorGraphBG        :"#dcebf2"
   ,ColorGraphContour   :"#dcebf2"
   ,ColorAxeGraduation  :"#003d5d"
   ,ColorBorder         :"none"
   ,ColorCadre          :"#f2f5f6"
   ,ColorCadreBorder    :"#f2f5f6"
   ,ColorLabel          :"#003d5d"
   ,ColorFieldText      :"#199edd"
   ,ColorFieldBorder    :"#ffffff"
   ,ColorDisabled       :"#CCCCCC"
   ,ColorMensInf33PC    :"#b2d8e9"
   ,ColorMensSupp33PC   :"#ff3265"
   ,ColorPret           :"#aab3b7"
   ,Color33PC           :"#34B136"
   ,ColorContourPoignees:"#003e5e"
   ,ColorBulle          :"#FFFFFF"
   ,ColorBtnCalculBG    :"#199edd"
   ,ColorBtnCalculText  :"#FFFFFF"
  }

/*
;---------------------------------------------------
; baremes de taux en fixe et revisable
; CanSelect: 1=choix autoris�, 0=choix masqu�
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
//--- Objet OCalcFinIni2 contenant les param�tres d'initialisation pour une seconde calculette -----
//--------------------------------------------------------------------------------------------------
var OCalcFinIni2 =
{
/*
;---------------------------------------------------
; IsPretToMensDuree : 0=Mensualit�+Dur�e vers Pr�t, 1=sens invers�
; IsFixeMontantPret : 0=La modification de la Mensualit� ou de la Dur�e impacte le Pr�t
;                     1=Le montant du pr�t n'est pas modifi� (toujours � 1 si IsPretToMensDuree == 1)
;
; CanSelectTF/TR/TS: 1=choix possible, 2=choix masqu�
;
; DefaultTypeTaux   : type de taux par defaut
; 1=BaremeTauxFixe, 2=BaremeTauxRevisable, 9=TauxSaisiParUtilisateur
;
; DefaultTauxSaisi  : taux affich� par d�faut si taux est saisi
; NbMoisMaxi        : dur�e maximale en mois (jusqu'� 600 mois)
; NbMoisMini        : dur�e minimale en mois (A partir de 12 mois)
; NbMoisDefaut      : dur�e par d�faut en mois
; NbMoisMaxAvtMens  : la dur�e augmente en priorit� jusqu'� ce nombre de mois (A partir de NbMoisDefaut)
; PasNbMois         : Nb mois entre chaque pas (la dur�e �volue de x mois en x mois)
; RevenuDefaut      : revenu par d�faut
; PretMaxi          : montant maximum du pr�t (0 = pas de limite)
; CodeNLS           : langue utilis�e (0=fran�ais, 1033=anglais, 2070=portugais)
; Monnaie           : monnaie utilis�e (euro=�, livre=�, dollar=$)
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
; Design et pr�sentation de la calculette :
; UrlTrameFondEcran     : image de fond d'�cran du graphique
; IsHideBottomTextBox   : supprime les zones de texte en bas de la calculette (true|false)
; IsHideLabels          : supprime les labels de la calculette (true|false)
; IsHideHelp            : supprime l'aide de la calculette (true|false)
; IsFieldsWithoutBorder : champs de saisie sans bordures (true|false)
; BtnCalcul_UrlImageHaut: image haut du bouton calcul (ex:"library/BtnCalcul.png")
; BtnCalcul_UrlImageBas : image bas du bouton calcul (lorsqu'il est press�)
; BtnAide_UrlImageHaut  : image haut du bouton d'aide
; BtnAide_UrlImageBas   : image bas du bouton d'aide (lorsqu'il est actif)
; TaillePoignees        : taille des poign�es de redimensionnement (1=petit,2=moyen,3=grand,4=tr�s grand)
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
; couleurs utilis�es dans la calculette :
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
; ColorMensInf33PC      : mensualit� inf�rieur � 33 %
; ColorMensSupp33PC     : mensualit� supp�rieur � 33 %
; ColorPret             : couleur du graphique de pr�t
; Color33PC             : couleur de la barre des 33 % du revenu
; ColorContourPoignees  : couleur contours et poign�es de redimensionnement
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
; CanSelect: 1=choix autoris�, 0=choix masqu�
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

