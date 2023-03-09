// GesPec12.c  Canevas pour r�alisation  
// C. HUBER    09/02/2015

// Fonctions pour la gestion du Pec12
//
//
// Principe : Il est n�cessaire d'appeler cycliquement la fonction ScanPec12
//            avec un cycle de 1 ms
//
//  Pour la gestion du Pec12, il y a 9 fonctions � disposition :
//       Pec12IsPlus       true indique un nouveau incr�ment
//       Pec12IsMinus      true indique un nouveau d�cr�ment
//       Pec12IsOK         true indique action OK
//       Pec12IsESC        true indique action ESC
//       Pec12NoActivity   true indique abscence d'activit� sur PEC12
//  Fonctions pour quittance des indications
//       Pec12ClearPlus    annule indication d'incr�ment
//       Pec12ClearMinus   annule indication de d�cr�ment
//       Pec12ClearOK      annule indication action OK
//       Pec12ClearESC     annule indication action ESC
//
//
//---------------------------------------------------------------------------


// d�finitions des types qui seront utilis�s dans cette application

#include "GesPec12.h"
#include "Mc32Debounce.h"
#include "Mc32DriverLcd.h"
#include <stdint.h>

#define AFK_TIME 5000 //Dur�e d'inactivit� avant d'�taindre le r�tro-�clairage

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
// Apr�s l'appel le descripteur est mis � jour

// Comportement du PEC12
// =====================

// Attention 1 cran g�n�re une pulse compl�te (les 4 combinaisons)
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

<<<<<<< HEAD
void ScanPec12 (bool ValA, bool ValB, bool ValPB)
{   
    //Traitement ainti-rebond sur A, B et PB
    DoDebounce (&DescrA, ValA);
    DoDebounce (&DescrB, ValB);
    DoDebounce (&DescrPB, ValPB);
    
    
            //=================================//
            // D�tection Incr�ment / D�cr�ment //
            //=================================//
    
    //D�tection flanc descendant sur B
    if(DebounceIsPressed(&DescrB)){
        // Quittance de l'�v�nement
        DebounceClearPressed(&DescrB);

        if ( DebounceGetInput (&DescrA) == 0)
        {
           // Si A = 0 : situation CW = incr�ment
           Pec12.Inc = 1;
           Pec12ClearInactivity();
        } 
         else
        {
            Pec12.Dec = 1;
            Pec12ClearInactivity();
        }
    }
    
    
    
            //===========================//
            // Traitement du Push Button //
            //===========================//
    
    if(DebounceIsPressed(&DescrPB)){

        Pec12.PressDuration++; //Incr�ment de 1
        Pec12ClearInactivity();
=======
/*void ScanPec12 (bool ValA, bool ValB, bool ValPB)
{
     //d�claration des variables;
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
   DescrB.bits.KeyPrevInputValue
   // D�tection incr�ment / d�cr�ment
   Compt_AFK ++ ;
   // Traitement du PushButton
   //si lors de la valeur de valAB est diff�rant que la pr�cedente
   if (ValAB != OLD_ValAB)
    //    if ((DescrA.bits.KeyPressed == 0) && (DescrA.bits.KeyPrevInputValue == 1) && (DescrB.bits.KeyPressed == 1) ||
    //            (DescrA.bits.KeyPressed == 1) && (DescrA.bits.KeyPrevInputValue == 0) && (DescrB.bits.KeyPressed == 0))
   {
        switch (ValAB)
        {
            //lorsque les deux signaux sont � 0
            case 0x00: 
				//ne rien faire;
			break;
            
            //lorsque le B est a 1
            case 0x01:
				//sens anti horaire;
                if (OLD_ValAB==0x00)
                {
                    Pec12.Inc = Pec12IsPlus ;
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
                    Pec12.Dec = Pec12IsMinus ();
                    Compt_AFK = 0;//Pec12ClearInactivity 
                }
                else
                {
                    //ne rien faire;
                }
            break;
            
            //lorsque les deux signaux sont � 1
            case 0x11:
                    //ne rien faire;
            break;

            default:
                    //erreur;
                break; 
		}  
>>>>>>> b2aaeca84b70b3c66fda3078a17189699756e079
    }
    else
    { 
        Pec12.PressDuration = 0; //Remise � 0
    }
    
    
    if(DebounceIsReleased(&DescrPB))
    {
        DebounceClearReleased(&DescrPB); // Quittance de l'�v�nement
        
        Pec12ClearInactivity();   
    }
    
    
    
            //====================//
            // Gestion inactivit� //
            //====================//
    
    if(Pec12.InactivityDuration >= AFK_TIME)
    {
        lcd_bl_off(); //Eclairage LCD �teint
    }
    else
    {
        Pec12.InactivityDuration += 1;
    }
    
    
    
    /*
    if((Pec12.Inc || Pec12.Dec || Pec12.OK || Pec12.ESC) == 0)
    {
        Pec12.NoActivity = 1;
        Pec12.InactivityDuration++;
        
        if(Pec12.InactivityDuration >= 5000)
        {
            lcd_bl_off(); //Eclairage LCD �teint
            Pec12.InactivityDuration = 0;
        }
    }
    else
    {
        lcd_bl_on();
        Pec12ClearInactivity(); 
    }*/

} //end of ScanPec12







//       Pec12IsPlus       true indique un nouveau incr�ment
bool Pec12IsPlus    (void) {
    Pec12.Inc = 1;
   return (Pec12.Inc);
}

//       Pec12IsMinus      true indique un nouveau d�cr�ment
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

//       Pec12NoActivity   true indique abscence d'activit� sur PEC12
bool Pec12NoActivity    (void) {
    Pec12.NoActivity  = 1;
   return (Pec12.NoActivity);
}

//  Fonctions pour quittance des indications
//       Pec12ClearPlus    annule indication d'incr�ment
void Pec12ClearPlus   (void) {
   Pec12.Inc = 0;
}

//       Pec12ClearMinus   annule indication de d�cr�ment
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


