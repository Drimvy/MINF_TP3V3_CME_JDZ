// GesPec12.c  Canevas pour réalisation  
// C. HUBER    09/02/2015

// Fonctions pour la gestion du Pec12
//
//
// Principe : Il est nécessaire d'appeler cycliquement la fonction ScanPec12
//            avec un cycle de 1 ms
//
//  Pour la gestion du Pec12, il y a 9 fonctions à disposition :
//       Pec12IsPlus       true indique un nouveau incrément
//       Pec12IsMinus      true indique un nouveau décrément
//       Pec12IsOK         true indique action OK
//       Pec12IsESC        true indique action ESC
//       Pec12NoActivity   true indique abscence d'activité sur PEC12
//  Fonctions pour quittance des indications
//       Pec12ClearPlus    annule indication d'incrément
//       Pec12ClearMinus   annule indication de décrément
//       Pec12ClearOK      annule indication action OK
//       Pec12ClearESC     annule indication action ESC
//
//
//---------------------------------------------------------------------------


// définitions des types qui seront utilisés dans cette application

#include "GesPec12.h"
#include "Mc32Debounce.h"
#include "Mc32DriverLcd.h"
#include <stdint.h>

// Descripteur des sinaux
S_SwitchDescriptor DescrA;
S_SwitchDescriptor DescrB;
S_SwitchDescriptor DescrPB;

// Structure pour les traitement du Pec12
S_Pec12_Descriptor Pec12;


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Principe utilisation des fonctions
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//
// ScanPec12 (bool ValA, bool ValB, bool ValPB)
//              Routine effectuant la gestion du Pec12
//              recoit la valeur des signaux et du boutons
//
// s'appuie sur le descripteur global.
// Après l'appel le descripteur est mis à jour

// Comportement du PEC12
// =====================

// Attention 1 cran génère une pulse complète (les 4 combinaisons)
// D'ou traitement uniquement au flanc descendand de B

// Dans le sens horaire CW:
//     __________                      ________________
// B:            |____________________|
//     ___________________                       _________
// A:                     |_____________________|                    

// Dans le sens anti-horaire CCW:
//     ____________________                      _________
// B:                      |____________________|
//     __________                       __________________
// A:            |_____________________|        

/*void ScanPec12 (bool ValA, bool ValB, bool ValPB)
{
     //déclaration des variables;
	//Val encodeur;
	uint8_t ValAB;
	uint8_t OLD_ValAB = 0;
	//Val bouton;
	uint8_t OLD_ValPB;
	//position encodeur;
	
	//Compteur ok esc;
	static uint8_t Compt_BT;
	//compteur AFK;
	static uint8_t Compt_AFK;
   // Traitement antirebond sur A, B et PB
   DoDebounce (&DescrA, ValA);
   DoDebounce (&DescrB, ValB);
   DoDebounce (&DescrPB, ValPB);
   
   //entrer la valeur de A sur byte MSB de ValAB
   ValAB  = DescrA.bits.KeyReleased;
   ValAB = ValAB << 4;
   //entrer la valeur de B sur byte LSB de ValAB
   ValAB = ValAB | DescrB.bits.KeyReleased;
   // Détection incrément / décrément
   Compt_AFK ++ ;
   // Traitement du PushButton
   //si lors de la valeur de valAB est différant que la précedente
   if (ValAB != OLD_ValAB)
   {
        switch (ValAB)
        {
            //lorsque les deux signaux sont à 0
            case 0x00: 
				//ne rien faire;
			break;
            
            //lorsque le B est a 1
            case 0x01:
				//sens anti horaire;
                if (OLD_ValAB==0x00)
                {
                    Pec12.Inc = Pec12.Inc ++ ;
                    Compt_AFK = 0;//Pec12ClearInactivity 
                }
                else
                {
                    //ne rien faire;
                }
            break;
            
            //lorsque le A est a 1
            case 0x10:
                    //sens horaire;
                if (OLD_ValAB==0x00)
                {
<<<<<<< HEAD
                    Pec12.Inc = Pec12.Inc ++ ;
=======
                    Pec12.Dec = Pec12IsMinus ();
>>>>>>> c3d542c1bcf1366d822d56c3708f938bb63ed1ad
                    Compt_AFK = 0;//Pec12ClearInactivity 
                }
                else
                {
                    //ne rien faire;
                }
            break;
            
            //lorsque les deux signaux sont à 1
            case 0x11:
                    //ne rien faire;
            break;

            default:
                    //erreur;
                break; 
		}  
    }
    else
	{
		//ne rien faire;
	}
   // Gestion inactivité
	if (ValPB == 1)
	{
		Compt_BT++;
		Compt_AFK = 0;//Pec12ClearInactivity 
	}
	else
	{
		//ne rien faire;
	}
	if ((OLD_ValPB == 1) && (ValPB == 0))
	{
		if ((Compt_BT < 500))
		{
			Pec12.OK = Pec12IsOK(); 
			Compt_BT = 0;
		}
		else
		{
<<<<<<< HEAD
			Pec12.ESC = Pec12IsESC();
=======
			Pec12.ESC = Pec12IsESC;
>>>>>>> c3d542c1bcf1366d822d56c3708f938bb63ed1ad
			Compt_BT = 0;
		}
	}
    else
	{
		//ne rien faire;
	}
	if (Compt_AFK >= 5000)
	{
		lcd_bl_off();
	}
	else
	{
		//ne rien faire;
	}
	OLD_ValPB = ValPB;
	OLD_ValAB = ValAB;
   
 } // ScanPec12*/


/*void Pec12Init (void)
{
   // Initialisation des descripteurs de touches Pec12
   DebounceInit(&DescrA);
   DebounceInit(&DescrB);
   DebounceInit(&DescrPB);
   
   // Init de la structure PEc12
    Pec12.Inc = 0;             // événement incrément  
    Pec12.Dec = 0;             // événement décrément 
    Pec12.OK = 0;              // événement action OK
    Pec12.ESC = 0;             // événement action ESC
    Pec12.NoActivity = 0;      // Indication d'activité
    Pec12.PressDuration = 0;   // Pour durée pression du P.B.
    Pec12.InactivityDuration = 0; // Durée inactivité
  
 } // Pec12Init */





//       Pec12IsPlus       true indique un nouveau incrément
bool Pec12IsPlus    (void) {
    Pec12.Inc = 1;
   return (Pec12.Inc);
}

//       Pec12IsMinus      true indique un nouveau décrément
bool Pec12IsMinus    (void) {
    Pec12.Dec  = 1;
   return (Pec12.Dec);
}

//       Pec12IsOK         true indique action OK
bool Pec12IsOK    (void) {
    Pec12.OK  = 1;
   return (Pec12.OK);
}

//       Pec12IsESC        true indique action ESC
bool Pec12IsESC    (void) {
    Pec12.ESC = 1;
   return (Pec12.ESC);
}

//       Pec12NoActivity   true indique abscence d'activité sur PEC12
bool Pec12NoActivity    (void) {
    Pec12.NoActivity  = 1;
   return (Pec12.NoActivity);
}

//  Fonctions pour quittance des indications
//       Pec12ClearPlus    annule indication d'incrément
void Pec12ClearPlus   (void) {
   Pec12.Inc = 0;
}

//       Pec12ClearMinus   annule indication de décrément
void Pec12ClearMinus   (void) {
   Pec12.Dec = 0;
}

//       Pec12ClearOK      annule indication action OK
void Pec12ClearOK   (void) {
   Pec12.OK = 0;
}

//       Pec12ClearESC     annule indication action ESC
void Pec12ClearESC   (void) {
   Pec12.ESC = 0;
}

void Pec12ClearInactivity   (void) {
  Pec12.NoActivity = 0;
  Pec12.InactivityDuration = 0;
}


