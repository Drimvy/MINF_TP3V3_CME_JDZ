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
#include "bsp.h"

#define AFK_TIME 500 //Durée d'inactivité avant d'étaindre le rétro-éclairage

// Descripteur des sinaux
S_SwitchDescriptor DescrA;
S_SwitchDescriptor DescrB;
S_SwitchDescriptor DescrPB;


// Structure pour les traitement du Pec12
S_Pec12_Descriptor Pec12;
S_S9_Descriptor S9;


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
//     __________                       __________________
// A:            |_____________________|        
//     ____________________                      _________
// B:                      |____________________|
// Dans le sens anti-horaire CCW:
//     ___________________                       _________
// A:                     |_____________________|                    
//     __________                      ________________
// B:            |____________________|





void ScanPec12 (bool ValA, bool ValB, bool ValPB)
{   
    //Traitement ainti-rebond sur A, B et PB
    DoDebounce (&DescrA, ValA);
    DoDebounce (&DescrB, ValB);
    DoDebounce (&DescrPB, ValPB);
    

       //=================================//
      // Détection Incrément / Décrément //
     //=================================//
    //Detection flanc descendant sur B
    if((DescrB.bits.KeyPrevInputValue == 0) && (DescrB.bits.KeyValue == 1) && (DescrA.bits.KeyValue == 1)) 
    {
        Pec12.Inc = 1;
    }
    else if((DescrB.bits.KeyPrevInputValue == 0) && (DescrB.bits.KeyValue == 1) && (DescrA.bits.KeyValue == 1)) 
    {
        Pec12.Dec = 1;
    }
    else
    {
        Pec12.Inc = 0;
        Pec12.Dec = 0;
    }    
    
    /*//Détection flanc descendant sur B
    if(DebounceIsPressed(&DescrB))
    {
        // Quittance de l'événement
        DebounceClearPressed(&DescrB);
        
        if ( DebounceGetInput (&DescrA) == 0)
        {
           // Si A = 0 : situation CW = incrément
           Pec12.Inc = 1;
        } 
         else
        {
            Pec12.Dec = 1;
        }
    }*/
    
       //===========================//
      // Traitement du Push Button //
     //===========================//
    
    if(DescrPB.bits.KeyValue == 0)
    {
        Pec12.OK = 0;   
        Pec12.ESC = 0;
    }
    else if(DescrPB.bits.KeyValue == 1)
    {
        Pec12.PressDuration ++;
    }
    if ((Pec12.PressDuration >= 50) && (DescrPB.bits.KeyValue == 0))
    {
        Pec12.ESC = 1;
        Pec12.PressDuration = 0;
    }
    else if ((Pec12.PressDuration < 50)&&(Pec12.PressDuration > 0) && (DescrPB.bits.KeyValue == 0))
    {
        Pec12.OK = 1;
        Pec12.PressDuration = 0;
    }
    
    
    /*if(DebounceIsPressed(&DescrPB))
    {
        Pec12.PressDuration++; //Incrément de 1

        Pec12ClearInactivity();
    }
    else
    { 
        Pec12.PressDuration = 0; //Remise à 0
    }
    
    
    if(DebounceIsReleased(&DescrPB))
    {
        DebounceClearReleased(&DescrPB); // Quittance de l'événement
    }*/
    
    
    
            //====================//
            // Gestion inactivité //
            //====================//
    
    

    //Incrément ou reset du compteur AFK
    if((Pec12.Inc && Pec12.Dec && Pec12.OK && Pec12.ESC) == 0)
    {
        //Test durée d'inactivité > 5sec
        if(Pec12.InactivityDuration >= AFK_TIME)
        {
            //Pec12.InactivityDuration = 0;
            lcd_bl_off;
            Pec12.NoActivity = 1;
        }
        else
        {
            Pec12.InactivityDuration ++;
        }
    }
    
    else
    {
        if (Pec12.NoActivity == 1)
        {
           Pec12ClearInactivity();
           lcd_bl_on;  
        }
        Pec12.InactivityDuration = 0;
    }
    
              //====================//
             //  Gestion BoutonS9  //
            //====================//
    
    if(S_OK == 0)
    {
        S9.OK = 1;
    }
    else
    {
        S9.OK = 0;
    }
    
} //end of ScanPec12







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

bool S9_OK (void){
    S9_Flag = 1;
    return(S9_Flag);
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


