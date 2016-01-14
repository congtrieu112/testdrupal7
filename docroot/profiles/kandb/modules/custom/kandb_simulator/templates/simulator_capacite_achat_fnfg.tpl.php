<!DOCTYPE html>
<html>
<!--
Programmes et formulaires contenus dans cette page sont la
propriété d'ALTO Informatique, 33 Av. du Maine, 75755 Paris cedex 15
Tous droits réservés.
-->

<head>
<title>Frais de notaire et frais de garantie</title>
<style>
.tab1 { border: solid #355B95 1px; }
.put1{ font-family: Arial; font-size: 10pt; border-width: 1px; border-style: solid; border-color: #7F9DB9; }
.td0 { font-family: Arial; font-size: 11pt; color: #FFFFFF; background-color: #355B95; font-weight: bold; }
.td1 { font-family: Arial; font-size: 10pt; color: #000044; background-color: #E0E2F9; }
.td1r{ font-family: Arial; font-size: 11pt; color: #C00000; font-weight: bold; }
.td3 { font-family: Arial; font-size: 10pt; color: #000044; background-color: #FFFFFF; }
.tdg { background-color: #E0E2F9; }
.titre1 { font-family: Arial; font-size: 11pt; font-weight: bold; color: #000080; }
#divreal a.Note1 { font-family: Arial; font-size: 8pt; font-style: italic; color: #909090; text-decoration:none; }
#divreal a.Note1:visited { font-family: Arial; font-size: 8pt; font-style: italic; color: #909090; text-decoration:none; }
#divreal a.Note1:hover { font-family: Arial; font-size: 8pt; font-style: italic; color: #909090; text-decoration:underline; background-color:#FFFFFF; }
</style>
</head>


<script language="JavaScript"><!--

var _tn=0;
var _ttn=0;

function GetNum(champ, fmt, flag)
{ _ttn=TestNum(champ,fmt, flag); return(_tn);
}

function TestNum(champ, fmt, flag)
{
var ret=0;
var s=""+champ;
var i1,i2,c;

_tn=0;
i1=0;
i2=s.length;
//for(; i1<i2; i1++) { c=s.charAt(i1); if(c!=' ' && c!='\t') { break; } }
//for(; i2>i1; i2--) { c=s.charAt(i2-1); if(c!=' ' && c!='\t') { break; } }

if(i1<i2)
  {
    var MaxEntier,MaxDeci,NegOK=0,NbEntier=0,NbDeci=0,iVirg=0,i,s2="";

    if(fmt<0)
        { NegOK=1;
          fmt=-fmt;
        }
    MaxEntier=fmt/10;
    MaxDeci  =fmt%10;

    for(i=i1; i<i2; i++)
        { c=s.charAt(i);
          if(c==' ' && flag!=null && (flag & 0x0001))
              { continue;
              }
          if(c>='0' && c<='9')
              { if(iVirg) { NbDeci++; if(NbDeci>MaxDeci) { ret=-3; break; } }
                else { NbEntier++; if(NbEntier>MaxEntier) { ret=-2; break; } }
              }
          else
          if(c=='.' || c==',')
              { if(iVirg) { ret=-1; break; }
                iVirg=i+1;
                c='.';
              }
          else
          if(c=='-')
              { if(!NegOK || i>i1) { ret=-4; break; }
              }
          else{ ret=-1;
                break;
              }
          s2+=c;
        }
    if(!ret)
        { _tn=(iVirg) ? parseFloat(s2) : parseInt(s2,10);
          ret=1;
        }
  }
return(ret);
}



function FormateVal(val, NbDeci, flag)
{
var s="";

if(val!=null && !isNaN(val))
    {
      var l,i,tmp,signe;

      var separe=" ";
      if(flag!=null)
          { if(flag & 0x0001) separe="&nbsp;"; else
            if(flag & 0x0002) separe="."; else
            if(flag & 0x0004) separe="";
          }

      if(NbDeci==2) { val=val*100.0; } else
      if(NbDeci>0) { for(i=0; i<NbDeci; i++) { val=val*10; } }
      else{ NbDeci=0; }

      val=Math.round(val);

      if(val<0) { val=-val; signe=1; } else{ signe=0; }
      s=val.toString();

      l=s.length;
      for(i=NbDeci+1-l; i>0; i--) s="0"+s;

      tmp=l-NbDeci;
      if(tmp>3 && separe.length>0)
          { for(i=0; i<5; i++)
                { if (tmp<4) break;
                  tmp-=3;
                  s=s.substring(0, tmp)+separe+s.substring(tmp, l);
                  l+=separe.length;
                }
          }
      if(NbDeci>0)
          { l=s.length;
            s=s.substring(0, l-NbDeci)+","+s.substring(l-NbDeci, l);
          }
      if(signe) s="-"+s;
    }

return(s);
}

//-->
</script>



<script language="JavaScript"><!--

var g_IsChange1=0;

function ffff_OC(sName)
{

g_IsChange1=1;

var f=document.ffff;

if(sName==null || sName=="TypeAchat")
    {
      var TypeAchat=parseInt(f.TypeAchat.options[f.TypeAchat.selectedIndex].value);

      var c=f.terrain;
      if(TypeAchat==1)  // 1=terrain+construct
          {
            c.disabled=false;
            c.style.backgroundColor="#FFFFFF";
          }
      else{ c.value="";
            c.disabled=true;
            c.style.backgroundColor="#CCCCCC";
          }

      var c=f.logement;
      if(TypeAchat>=1 && TypeAchat!=5)  // sauf travaux seuls
          {
            c.disabled=false;
            c.style.backgroundColor="#FFFFFF";
          }
      else{ c.value="";
            c.disabled=true;
            c.style.backgroundColor="#CCCCCC";
          }

      var c=f.travaux;
      if(TypeAchat==4 || TypeAchat==5)  // ancien et/ou travaux
          {
            c.disabled=false;
            c.style.backgroundColor="#FFFFFF";
          }
      else{ c.value="";
            c.disabled=true;
            c.style.backgroundColor="#CCCCCC";
          }

      var c=f.NbLogement;
      if(TypeAchat==2 || TypeAchat==3) // NEUF
          {
            c.disabled=false;
            c.style.backgroundColor="#FFFFFF";
            if(c.selectedIndex<0)
                 { c.selectedIndex=0;
                 }
          }
      else{ c.value="";
            c.disabled=true;
            c.style.backgroundColor="#CCCCCC";
          }

      var c=f.PretPth;
      if(TypeAchat>0)
          {
            c.disabled=false;
            c.style.backgroundColor="#FFFFFF";
          }
      else{ c.value="";
            c.disabled=true;
            c.style.backgroundColor="#CCCCCC";
          }
    }

fn_BodyOnLoad(1); // recalcul immédiat
}



function BeforeSubmit(f,IsAlert)
{
var ers="";

var TypeAchat=parseInt(f.TypeAchat.options[f.TypeAchat.selectedIndex].value);
var terrain  =GetNum(f.terrain.value ,80); var t_terrain =_ttn;
var logement =GetNum(f.logement.value,80); var t_logement=_ttn;
var travaux  =GetNum(f.travaux.value ,80); var t_travaux =_ttn;
var PretPth  =GetNum(f.PretPth.value ,80); var t_PretPth =_ttn;

if(TypeAchat<1 || TypeAchat>5)
    { ers="Précisez le type d'acquisition !";
    }
else
if(t_terrain <0) { ers="Prix du terrain : saisie invalide" ; } else
if(t_logement<0) { ers="Prix du logement : saisie invalide"; } else
if(t_travaux <0) { ers="Prix des travaux : saisie invalide"; } else
if(t_PretPth <0) { ers="Montant du prêt : saisie invalide" ; }
else
if(TypeAchat==1 && (terrain==0 && logement==0))
    { ers="Précisez le prix du terrain et/ou du logement !";
    }
else
if((TypeAchat==2 || TypeAchat==3) && logement<=0)
    { ers="Précisez le prix du logement !";
    }
else
if(TypeAchat==4 && (logement==0 && travaux==0))
    { ers="Précisez le prix du logement et/ou des travaux !";
    }
else
if(!g_IsChange1)
    { ///ers="Résultats déjà calculés !";
    }
if(ers!="" && IsAlert)
    { self.alert(ers);
    }

return((ers!="") ? false : true);
}


function OnBtnSubmit(f)
{
if(BeforeSubmit(f,1)==true)
    { ///f.submit();
      fn_BodyOnLoad(1);
    }
}


function MainGetForm()
{
var fd=new Object();

var f=document.ffff;

fd.TypeAchat  =parseInt(f.TypeAchat.options[f.TypeAchat.selectedIndex].value);
fd.terrain    =GetNum(f.terrain.value , 80);
fd.logement   =GetNum(f.logement.value, 80);
fd.travaux    =GetNum(f.travaux.value , 80);
fd.PretPth    =GetNum(f.PretPth.value , 80);
fd.IsNegocie  =(f.IsNegocie.checked) ? 1:0;

fd.NumDept    =parseInt(f.NumDept.options[f.NumDept.selectedIndex].value); // modif 06/03/2014
fd.IsDOM      =(fd.NumDept==97 || (fd.NumDept>=971 && fd.NumDept<=976)) ? 1:0; // modif 06/03/2014

fd.NbLogement=1;
if(f.NbLogement.selectedIndex>=0)
    { fd.NbLogement=parseInt(f.NbLogement.options[f.NbLogement.selectedIndex].value);
    }

return(fd);
}



function MainGetBareme()
{
var brm=
{ ModeCalculHypo: 2,
  TauxTva:        20.0, // depuis 1/1/2014
  TauxTvaDOM:      8.5,
  ProportMini:    78.00,
  EmolFixeAncien: 570.00,
  EmolFixeNeufT:  370.00,
  EmolFixePret:   180.00,
  EmolFixePpd:    130.00,
  DeboursAchat:   780.00,
  DeboursPret:    40.00,
  EnregFixe125:   125.00,
  EnregFixe25:    25.00,

  NegociePlafond: 45735.00,
  NegocieTaux1:   5,
  NegocieTaux2:   2.5,

  SalaireMini1:   15.00,
  SalaireMini2:   8.00,
  SalaireTaux1:   0.10,
  SalaireTaux2:   0.05,

  TauxTD:         4.50, // depuis 1/1/2014
  TauxTC:         1.20,
  TauxPF:         0.70,
  TauxFA_TD:      2.37,
  TauxFA_PF:      2.14,

  s1:[ { plafond:  6500.00, taux: 4.000 },
       { plafond: 17000.00, taux: 1.650 },
       { plafond: 60000.00, taux: 1.100 },
       { plafond:     0.00, taux: 0.825 }
     ],
  s2:[ { plafond:  6500.00, taux: 2.000 },
       { plafond: 17000.00, taux: 1.100 },
       { plafond: 30000.00, taux: 1.750 },
       { plafond:     0.00, taux: 0.550 }
     ],

  TblDept: // pour deriver TauxTD specifique sur departement. au 1/1/2015
  [
    { NumDept:21, TauxTD:4.45 }, // code d'or
    { NumDept:36, TauxTD:3.80 }, // indre
    { NumDept:38, TauxTD:3.80 }, // isere
    { NumDept:53, TauxTD:3.80 }, // mayenne
    { NumDept:56, TauxTD:3.80 }, // morbihan
/// { NumDept:75, TauxTD:3.80 }, // paris // 4,5% depuis 1/1/2016
    { NumDept:972,TauxTD:3.80 }, // martinique
    { NumDept:976,TauxTD:3.80 }  // mayotte
  ]
};

return(brm);
}


function NotaireCalculFrais(brm, assiette, type, IsNegociation, NbHabitation, IsDOM, NumDept)
{
var   CoeffSerie;  // appliqué à s1,s2 : 1/3, 2/3 ...
var   tempd;
var   FraisNotaire=0;

if(type!=1 && type!=2 && type!=3 && type!=4)
    { return(FraisNotaire);
    }

if(assiette<=0)
    { return(FraisNotaire);
    }

if(type==2 || type==3) // NEUF
    {
           if(NbHabitation<=10) CoeffSerie=1.0;
      else if(NbHabitation<25 ) CoeffSerie=4.0/5.0;
      else if(NbHabitation<100) CoeffSerie=2.0/3.0;
      else if(NbHabitation<250) CoeffSerie=1.0/2.0;
      else if(NbHabitation<500) CoeffSerie=2.0/5.0;
      else                      CoeffSerie=1.0/3.0;
    }
else{ CoeffSerie=1.0;
    }

var emolument=NotaireEmolFromSerie(brm, assiette, 1, CoeffSerie);

emolument+=(type==1 || type==2 || type==3)
          ? brm.EmolFixeNeufT
          : brm.EmolFixeAncien;

// en DOM (Guadeloupe, Guyane, Martinique) : emolument major‚s +25%, mayotte= +40%

if(NumDept==97 || (NumDept>=971 && NumDept<=976))
    { IsDOM=1; // force IsDOM
    }
else
if(NumDept>0)
    { IsDOM=0; // force IsDOM
    }

if(IsDOM && NumDept!=974) // La Reunion = pas de majoration
    {
     // 1.40 si mayotte
     // 1.25 si martinique,guadeloupe,guyanne ou NR
      emolument*=((NumDept==976) ? 1.40 : 1.25);
    }

if(IsNegociation)
    {
      if(assiette<=brm.NegociePlafond)
          { tempd=assiette*(brm.NegocieTaux1/100);
          }
      else{ tempd=brm.NegociePlafond;
            tempd=(tempd*(brm.NegocieTaux1/100))
                 +((assiette-tempd)*(brm.NegocieTaux2/100));
          }
      emolument+=tempd;
    }

var debours=brm.DeboursAchat;

tempd=assiette*(brm.SalaireTaux1/100);
if(tempd<brm.SalaireMini1) tempd=brm.SalaireMini1;
debours+=tempd;

var tva1=emolument*(((IsDOM) ? brm.TauxTvaDOM : brm.TauxTva)/100);
var enreg=0;

if(type==1 || type==4) // TERRAIN ou ANCIEN
    {
      var TauxTD=brm.TauxTD;

      // modif 06/03/2014
      if(NumDept && NumDept>=1)
          {
            var i;
            for(i=0; i<brm.TblDept.length; i++)
                {
                  if(brm.TblDept[i].NumDept==NumDept)
                      { TauxTD=brm.TblDept[i].TauxTD;
                        break;
                      }
                }
          }

      TauxTD*=(1+(brm.TauxFA_TD/100));
      enreg=assiette*((TauxTD+brm.TauxTC)/100);
    }
else
if(type==2 || type==3)
    {
      var TauxPF=brm.TauxPF*(1+(brm.TauxFA_PF/100));
      enreg=assiette*(TauxPF/100);
    }

tempd=emolument+debours+enreg+tva1;

FraisNotaire=Math.floor(tempd/10)*10; // arrondi a 10 Euro

return(FraisNotaire);
}



function NotaireCalculHypo(brm, Pth, PcPel, PasPtz, PpdMax, IsDOM, NumDept)
{
var tempd;
var FraisNotaire=0;
var TotalPret=Pth+PcPel+PasPtz;

if(TotalPret<=0)
    { return(FraisNotaire);
    }

if(PpdMax<=0) PpdMax=0;

var emolument;

emolument=NotaireEmolFromSerie(brm, TotalPret, 1, 1.0/3.0);

emolument+=(PcPel>0 || PasPtz>0 || Pth>PpdMax)
          ? brm.EmolFixePret
          : brm.EmolFixePpd;

// en DOM (Guadeloupe, Guyane, Martinique) : emolument major‚s +25%, mayotte= +40%

if(NumDept==97 || (NumDept>=971 && NumDept<=976))
    { IsDOM=1; // force IsDOM
    }
else
if(NumDept>0)
    { IsDOM=0; // force IsDOM
    }

if(IsDOM && NumDept!=974) // La Reunion = pas de majoration
    {
     // 1.40 si mayotte
     // 1.25 si martinique,guadeloupe,guyanne ou NR
      emolument*=((NumDept==976) ? 1.40 : 1.25);
    }

var enreg=0;

if(Pth>PpdMax)
    {
      var TauxPF=brm.TauxPF*(1+(brm.TauxFA_PF/100)); // modif 22/06/2011
      enreg=(((Pth-PpdMax)*1.20)*(TauxPF/100)); // modif 22/06/2011
    }

if(PcPel>0 || PasPtz>0 || Pth>PpdMax)
    { enreg+=brm.EnregFixe125;
    }

var debours=brm.DeboursPret;

tempd=TotalPret;
if(tempd>0)
    { tempd*=1.20*(brm.SalaireTaux2/100);
      if(tempd<brm.SalaireMini2) tempd=brm.SalaireMini2;
      debours+=tempd;
    }

var tva1=emolument*(((IsDOM) ? brm.TauxTvaDOM : brm.TauxTva)/100);

tempd=emolument+debours+enreg+tva1;

FraisNotaire=Math.floor(tempd/5)*5; // arrondi a 5 euro

return(FraisNotaire);
}


function NotaireEmolFromSerie(brm, assiette, NumSerie, coeff)
{
var emolument=0;


if(assiette>0)
    {
      var serie=(NumSerie==2) ? brm.s2 : brm.s1;

      for(var num=0; ; num++)
          {
            var plafond=serie[num].plafond;
            var tempd=(plafond!=0 && assiette>plafond) ? plafond : assiette;

            if(num>0) tempd-=serie[num-1].plafond;
            emolument+=tempd*(serie[num].taux/100);
            if(plafond==0 || assiette<=plafond) break;
          }

      emolument*=coeff;

      if(emolument<brm.ProportMini)
          { emolument=brm.ProportMini;
          }
    }

return(emolument);
}



function GetResultFnfg(fdata)
{
var brm=MainGetBareme();
var r=new Object();

r.FnTotal  =0;
r.FgTotal  =0;

r.S_FnTotal="";
r.S_FgTotal="";

if(fdata.TypeAchat>0)
    {
      var CoutAchat=(fdata.TypeAchat==1) ? fdata.terrain : fdata.logement;

      if(CoutAchat>0)
          {
            r.FnTotal=NotaireCalculFrais(brm,
                                         CoutAchat,
                                         fdata.TypeAchat,
                                         fdata.IsNegocie,
                                         fdata.NbLogement,
                                         fdata.IsDOM,
                                         fdata.NumDept); // modif 06/03/2014

            r.S_FnTotal=FormateVal(r.FnTotal, 0)+"&nbsp;&euro;";
          }

      if(fdata.PretPth>0)
          {
            var PpdMax=0;

            if(fdata.TypeAchat==1)
                { PpdMax=fdata.terrain;
                }
            else
            if(fdata.TypeAchat==3 || // neuf cle en main
               fdata.TypeAchat==4)   // ancien
                { PpdMax=fdata.logement;
                }

            r.FgTotal=NotaireCalculHypo(brm,
                                                    fdata.PretPth,
                                                                                0,
                                                                                0,
                                                                                PpdMax,
                                                                                fdata.IsDOM,
                                                                                fdata.NumDept); // modif 06/03/2014

            r.S_FgTotal=FormateVal(r.FgTotal, 0)+"&nbsp;&euro;";
          }
    }

return(r);
}


function fn_BodyOnLoad(IsLoaded)
{
g_IsChange1=0;

if(IsLoaded!=1)
    { ffff_OC(null);
      g_IsChange1=0;
    }

var f=document.ffff;
var fdata=MainGetForm();
var result=GetResultFnfg(fdata);

document.getElementById("result_FnTotal"     ).innerHTML=result.S_FnTotal   ;
document.getElementById("result_FgTotal"     ).innerHTML=result.S_FgTotal   ;
}

//-->
</script>

<body bgcolor="#FFFFFF" onload="fn_BodyOnLoad(0)">

<form name="ffff" onsubmit="return BeforeSubmit(ffff,1)" method="POST">
  <table align="center" border="0" cellspacing="8" cellpadding="0">
    <tr>
      <td align="center" colspan="2"><font class="titre1">Calculez vos frais
      de notaire et d&#146;hypothèque</font></td>
    </tr>
    <tr>
      <td class="tdg" valign="top">
      <table class="tab1" border="0" cellspacing="1" cellpadding="4" width="100%">
        <tr>
          <td class="td0" align="center">Votre projet immobilier</td>
        </tr>
        <tr>
          <td valign="top"><table border="0" cellspacing="0" cellpadding="2" width="100%">
            <tr>
              <td class="td1" nowrap colspan="2">
              <div style="float:left;">Projet :</div>
              <select name="TypeAchat" size="1" onchange="ffff_OC('TypeAchat')" style="float:right;">
                <option value="0">(précisez votre projet)</option>
                <option value="1">Achat de terrain + construction</option>
                <option value="2">Achat d&#146;un logement neuf en VEFA</option>
                <option value="3">Achat d&#146;un logement neuf clé en main</option>
                <option value="4">Achat d&#146;un logement ancien</option>
                <option value="5">Réalisation de travaux seuls</option>
              </select>
              </td>
            </tr>
            <tr>
              <td class="td1" nowrap colspan="2">
              <div style="float:left;">Département :</div>
                            <select name="NumDept" size="1" onchange="ffff_OC('NumDept')" style="float:right;">
<option value="0">(précisez le département)</option>
<option value="1">01-Ain</option>
<option value="2">02-Aisne</option>
<option value="3">03-Allier</option>
<option value="4">04-Alpes de Hte Provence</option>
<option value="5">05-Hautes-Alpes</option>
<option value="6">06-Alpes-Maritimes</option>
<option value="7">07-Ardèche</option>
<option value="8">08-Ardennes</option>
<option value="9">09-Ariège</option>
<option value="10">10-Aube</option>
<option value="11">11-Aude</option>
<option value="12">12-Aveyron</option>
<option value="13">13-Bouches-du-Rhône</option>
<option value="14">14-Calvados</option>
<option value="15">15-Cantal</option>
<option value="16">16-Charente</option>
<option value="17">17-Charente-Maritime</option>
<option value="18">18-Cher</option>
<option value="19">19-Corrèze</option>
<option value="20">20-Corse</option>
<option value="21">21-Côte-d'Or</option>
<option value="22">22-Côtes-d'Armor</option>
<option value="23">23-Creuse</option>
<option value="24">24-Dordogne</option>
<option value="25">25-Doubs</option>
<option value="26">26-Drôme</option>
<option value="27">27-Eure</option>
<option value="28">28-Eure-et-Loire</option>
<option value="29">29-Finistère</option>
<option value="30">30-Gard</option>
<option value="31">31-Haute-Garonne</option>
<option value="32">32-Gers</option>
<option value="33">33-Gironde</option>
<option value="34">34-Hérault</option>
<option value="35">35-Ille-et-Vilaine</option>
<option value="36">36-Indre</option>
<option value="37">37-Indre-et-Loire</option>
<option value="38">38-Isère</option>
<option value="39">39-Jura</option>
<option value="40">40-Landes</option>
<option value="41">41-Loir-et-Cher</option>
<option value="42">42-Loire</option>
<option value="43">43-Haute-Loire</option>
<option value="44">44-Loire-Atlantique</option>
<option value="45">45-Loiret</option>
<option value="46">46-Lot</option>
<option value="47">47-Lot-et-Garonne</option>
<option value="48">48-Lozère</option>
<option value="49">49-Maine-et-Loire</option>
<option value="50">50-Manche</option>
<option value="51">51-Marne</option>
<option value="52">52-Haute-Marne</option>
<option value="53">53-Mayenne</option>
<option value="54">54-Meurthe-et-Moselle</option>
<option value="55">55-Meuse</option>
<option value="56">56-Morbihan</option>
<option value="57">57-Moselle</option>
<option value="58">58-Nièvre</option>
<option value="59">59-Nord</option>
<option value="60">60-Oise</option>
<option value="61">61-Orne</option>
<option value="62">62-Pas-de-Calais</option>
<option value="63">63-Puy-de-Dôme</option>
<option value="64">64-Pyrénées-Atlantiques</option>
<option value="65">65-Hautes-Pyrénées</option>
<option value="66">66-Pyrénées-Orientales</option>
<option value="67">67-Bas-Rhin</option>
<option value="68">68-Haut-Rhin</option>
<option value="69">69-Rhône</option>
<option value="70">70-Haute-Saône</option>
<option value="71">71-Saône-et-Loire</option>
<option value="72">72-Sarthe</option>
<option value="73">73-Savoie</option>
<option value="74">74-Haute-Savoie</option>
<option value="75">75-Paris</option>
<option value="76">76-Seine-Maritime</option>
<option value="77">77-Seine-et-Marne</option>
<option value="78">78-Yvelines</option>
<option value="79">79-Deux-Sèvres</option>
<option value="80">80-Somme</option>
<option value="81">81-Tarn</option>
<option value="82">82-Tarn-et-Garonne</option>
<option value="83">83-Var</option>
<option value="84">84-Vaucluse</option>
<option value="85">85-Vendée</option>
<option value="86">86-Vienne</option>
<option value="87">87-Haute-Vienne</option>
<option value="88">88-Vosges</option>
<option value="89">89-Yonne</option>
<option value="90">90-Territoire-de-Belfort</option>
<option value="91">91-Essonne</option>
<option value="92">92-Hauts-de-Seine</option>
<option value="93">93-Seine-Saint-Denis</option>
<option value="94">94-Val-de-Marne</option>
<option value="95">95-Val-d'Oise</option>
<option value="971">971-Guadeloupe</option>
<option value="972">972-Martinique</option>
<option value="973">973-Guyanne</option>
<option value="974">974-La-Réunion</option>
<option value="976">976-Mayotte</option>
              </select>
              </td>
            </tr>
            <tr>
              <td class="td1" nowrap>Prix du terrain :</td>
              <td class="td1" nowrap><input class="put1" name="terrain" size="7" maxlength="8" onchange="ffff_OC('terrain')">&nbsp;&euro;</td>
            </tr>
            <tr>
              <td class="td1" nowrap>Prix du logement ou construction :</td>
              <td class="td1" nowrap><input class="put1" name="logement" size="7" maxlength="8" onchange="ffff_OC('logement')">&nbsp;&euro;</td>
            </tr>
            <tr>
              <td class="td1" nowrap>Coût des travaux additionnels :</td>
              <td class="td1" nowrap><input class="put1" name="travaux" size="7" maxlength="8" onchange="ffff_OC('travaux')">&nbsp;&euro;</td>
            </tr>
            <tr>
              <td class="td1" nowrap>Montant du prêt sollicité :</td>
              <td class="td1" nowrap><input class="put1" name="PretPth" size="7" maxlength="8" onchange="ffff_OC('PretPth')">&nbsp;&euro;</td>
            </tr>
            <tr>
              <td class="td1" nowrap colspan="2">
              <div style="float:left;">Taille de l&#146;ensemble immo.:</div>
              <select name="NbLogement" size="1" onchange="ffff_OC('NbLogement')" style="float:right;">
                <option value="1">1 à 10 logements</option>
                <option value="11">11 à 24 logements</option>
                <option value="25">25 à 99 logements</option>
                <option value="100">100 et plus</option>
              </select>
              </td>
            </tr>
            <tr>
              <td class="td1" nowrap colspan="2">
              <label for="IsNegocie">
              <input type="checkbox" name="IsNegocie" id="IsNegocie" value="1" onclick="ffff_OC('IsNegocie')">
              Bien négocié auprès du notaire</label>
            </tr>
          </table>
          </td>
        </tr>
      </table>
      </td>
    </tr>
    <tr>
      <td valign="center" align="center">
      <input name="BtnSubmit" type="button"
      value="Calculer !" onclick="OnBtnSubmit(ffff)"></td>
    </tr>
    <tr>
      <td valign="top">
      <table class="tab1" border="0" cellspacing="1" cellpadding="4" height="100" width="100%">
        <tr>
          <td class="td3" nowrap valign="top" align="center" width="50%">
          Montant estimé<br>des frais de notaire<br>sur l&#146;acquisition :<br>&nbsp;
          <br><font class="td1r"><div id="result_FnTotal"></div></font></td>
          <td class="td3" nowrap valign="top" align="center" width="50%">
          Montant estimé<br>des frais d&#146;hypothèque<br>sur le prêt :<br>&nbsp;
          <br><font class="td1r"><div id="result_FgTotal"></div></font></td>
        </tr>
      </table>
    <div id="divreal" align="right">
      <a class="Note1" href="http://www.alto-informatique.com" target="_blank">
        Réalisation alto-informatique.com
      </a>
    </div>
      </td>
    </tr>
  </table>
</form>
</body>
</html>
